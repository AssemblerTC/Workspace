#include <bits/stdc++.h>

using namespace std;

#ifdef ACMTUYO
struct RTC{~RTC(){cerr << "Time: " << clock() * 1.0 / CLOCKS_PER_SEC <<" seconds\n";}} runtimecount;
#define DBG(X) cerr << #X << " = " << X << '\n';
#else
struct RTC{};
#define DBG(X)
#endif
#define forn(i, n) for (int i = 0; i < (n); i++)
typedef long long int number;
const int maxn = 50010;
struct T {
  int preffix, suffix, sum, sol;
  bool is_null;
  T() : is_null(true) {}
  T(int val) : preffix(val), suffix(val), sum(val), sol(val), is_null(false) {}
  T operator + (const T& other) const {    
    T ans;
    if (is_null) return other;
    if (other.is_null) return *this;
    ans.preffix = max(preffix, sum + other.preffix);
    ans.suffix = max(suffix + other.sum, other.suffix);
    ans.sum = sum + other.sum;
    ans.sol = max(max(sol, other.sol), suffix + other.preffix);
    ans.is_null = false;
    return ans;
  }
};

struct segment_tree {
  T v[maxn + maxn];
  int n;
  segment_tree(int _n = 0): n(_n) {}
  void read() {
    for (int i = n; i < n + n; i++) {
      int x;
      scanf("%d", &x);
      v[i] = x;
    }
  }
  void upd(int i) {v[i] = v[i << 1 ] + v[i << 1 | 1];}
  void build() {
    for (int i = n-1; i; i--)
      upd(i);
  }
  void update(int p, int val) {
    v[p += n] = val;
    for (p >>= 1; p; p >>= 1) 
      upd(p);
  }
  int query(int l, int r) {// [l, r)
    T l_ans, r_ans;//setear a NEUTRO
    for (l += n, r+= n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) l_ans = l_ans + v[l++];
      if (r & 1) r_ans = v[--r] + r_ans;
    }
    return (l_ans + r_ans).sol;
  }
} tree;

int main() {
  int n, m;
  scanf("%d", &n);
  tree = segment_tree(n);
  tree.read();
  tree.build();
  scanf("%d", &m);
  while (m--) {
    int op, a, b;
    scanf("%d %d %d", &op, &a, &b);
    if (op)
      printf("%d\n", tree.query(a - 1, b));
    else
      tree.update(a - 1, b);
  }
  return 0;
}
