#include <iostream>
#include <vector>
#include <random>

using namespace std;

const int MAXN = 100005;

long long key_val[MAXN];
long long tag[MAXN];
unsigned int prio[MAXN];
int left_child[MAXN], right_child[MAXN];
int sz[MAXN];
int head[MAXN], tail[MAXN], next_id[MAXN];
long long ans[MAXN];

mt19937 rng(1337);

void apply_tag(int u, long long v) {
    if (!u) return;
    key_val[u] += v;
    tag[u] += v;
}

void push(int u) {
    if (!u || tag[u] == 0) return;
    apply_tag(left_child[u], tag[u]);
    apply_tag(right_child[u], tag[u]);
    tag[u] = 0;
}

void pull(int u) {
    if (!u) return;
    sz[u] = 1 + sz[left_child[u]] + sz[right_child[u]];
    }

void split(int u, long long k, int &L, int &R) {
    if (!u) {
        L = R = 0;
        return;
    }
    push(u);
    if (key_val[u] < k) {
        L = u;
        split(right_child[u], k, right_child[u], R);
        pull(L);
    } else {
        R = u;
        split(left_child[u], k, L, left_child[u]);
        pull(R);
    }
}

int merge(int L, int R) {
    if (!L || !R) return L ? L : R;
    if (prio[L] > prio[R]) {
        push(L);
        right_child[L] = merge(right_child[L], R);
        pull(L);
        return L;
    } else {
        push(R);
        left_child[R] = merge(L, left_child[R]);
        pull(R);
        return R;
    }
}

void split3(int u, long long k, int &L, int &M, int &R) {
    split(u, k, L, R);
    split(R, k + 1, M, R);
}

// Insert node u into Treap root
void insert_node(int &root, int u) {
    if (!root) {
        root = u;
        return;
    }
    push(root);
    if (key_val[u] == key_val[root]) {
        // Same balance reached! Merge ID lists in O(1)
        next_id[tail[root]] = head[u];
        tail[root] = tail[u];
        return;
    }
    if (prio[u] > prio[root]) {
        int L = 0, M = 0, R = 0;
        split3(root, key_val[u], L, M, R);
        if (M) {
            next_id[tail[M]] = head[u];
            tail[M] = tail[u];
            root = merge(merge(L, M), R);
            return;
        }
        left_child[u] = L;
        right_child[u] = R;
        pull(u);
        root = u;
        return;
    }
    if (key_val[u] < key_val[root]) {
        insert_node(left_child[root], u);
    } else {
        insert_node(right_child[root], u);
    }
    pull(root);
}

// Smaller-to-larger merging of two overlapping Treaps
void insert_all(int &dest, int u) {
    if (!u) return;
    push(u);
    int l = left_child[u];
    int r = right_child[u];
    left_child[u] = right_child[u] = 0;
    sz[u] = 1;
    tag[u] = 0;
    insert_node(dest, u);
    insert_all(dest, l);
    insert_all(dest, r);
}

// DFS to extract final balances for all starting days
void dfs(int u) {
    if (!u) return;
    push(u);
    int id = head[u];
    while (id != 0) {
        ans[id] = key_val[u];
        id = next_id[id];
    }
    dfs(left_child[u]);
    dfs(right_child[u]);
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    int root = 0;
    for (int i = 1; i <= n; ++i) {
        long long A;
        cin >> A;

        if (root) {
            int T1 = 0, R = 0, T2 = 0, R2 = 0, T3 = 0, T4 = 0;
            split(root, A, T1, R);
            split(R, 2 * A, T2, R2);
            split(R2, 3 * A, T3, T4);

            apply_tag(T1, A);
            apply_tag(T2, -A);
            apply_tag(T3, -A);
            apply_tag(T4, -A);

            int T_mid = 0;
            if (sz[T1] < sz[T3]) {
                insert_all(T3, T1);
                T_mid = T3;
            } else {
                insert_all(T1, T3);
                T_mid = T1;
            }

            root = merge(merge(T2, T_mid), T4);
        }

        // Initialize node for day i
        key_val[i] = A;
        prio[i] = rng();
        sz[i] = 1;
        head[i] = tail[i] = i;
        left_child[i] = right_child[i] = 0;
        tag[i] = 0;
        next_id[i] = 0;

        insert_node(root, i);
    }

    dfs(root);

    for (int k = 1; k <= n; ++k) {
        cout << ans[n - k + 1] << (k == n ? "" : " ");
    }
    cout << "\n";

    return 0;
}