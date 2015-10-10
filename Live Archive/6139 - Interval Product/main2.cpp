#include <bits/stdc++.h>

using namespace std;

#ifdef ACMTUYO
struct RTC{~RTC(){cerr << "Time: " << clock() * 1.0 / CLOCKS_PER_SEC <<" seconds\n";}} runtimecount;
#define DBG(X) cerr << #X << " = " << X << '\n';
#else
struct RTC{};
#define DBG(X)
#endif

#define fast_io() ios_base::sync_with_stdio(false)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)
typedef long long int number;
struct T {
  int neg, zero;
  T() {
    neg = zero = 0;
  }
  T(int x) {
    neg = zero = 0;
    if (x < 0) neg++;
    if (x == 0) zero++;
  }
  T operator + (const T&other) {
    T ans = *this;
    ans.neg += other.neg;
    ans.zero += other.zero;
    return ans;
  }
};
const int maxn = 100010;
struct segment_tree {
  T v[maxn + maxn];
  int n;
  segment_tree(int _n = 0): n(_n) {}
  void read() {
    for (int i = n; i < n + n; i++) {
      int x;
      scanf("%d", &x);
      v[i] = T(x);
    }
  }
  void upd(int i) {
    v[i] = v[i << 1] + v[i << 1 | 1];
  }
  void build() {
    for (int i = n - 1; i; i--)
      upd(i);
  }
  void update(int p, int val) {
    v[p += n] = val;
    for (p >>= 1; p; p >>= 1)
      upd(p);
  }
  char query(int l, int r) {
    T ans;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) ans = ans + v[l++];
      if (r & 1) ans = ans + v[--r];
      if (ans.zero) break;
    }
    if (ans.zero) return '0';
    return (ans.neg & 1)?'-':'+';
  }
} tree;

int main() {
  int m;
  while (scanf("%d %d", &(tree.n), &m) == 2) {
    tree.read();
    tree.build();
    while (m--) {
      char op[5];
      int a, b;
      scanf("%s %d %d", op, &a, &b);
      if (op[0] == 'C')
        tree.update(a - 1, b);
      else
        printf("%c", tree.query(a - 1, b));
    }
    printf("\n");
  }
  return 0;
}

