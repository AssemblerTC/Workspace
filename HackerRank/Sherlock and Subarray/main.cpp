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
const int maxn = 100010;
int v[maxn + maxn];
struct segment_tree {
  int n;
  segment_tree(int _n = 0): n(_n) {}
  void init() {
    memset(v, -1, sizeof(v));    
  }
  void update(int p, int val) {
    v[p += n] = val;
    for (p >>= 1; p; p >>= 1)
      v[p] = max(v[p << 1], v[p << 1 | 1]);
  }
  int query(int l, int r) {
    int ans = -1;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) ans = max(ans, v[l++]);
      if (r & 1) ans = max(ans, v[--r]);
    }
    return ans;
  }
} tree;
int n, LIM;
int vec[maxn];
void contar(int *cnt) {
  tree = segment_tree(LIM);
  tree.init();
  forn (i, n) {
    int pos = tree.query(vec[i], LIM);
    cnt[i] = i - pos;
    tree.update(vec[i], i);
  }
}
// 0 1 2 3
// 1 0 0 1
int cnt_izq[maxn];
int cnt_der[maxn];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    LIM = 0;
    forn (i, n) {
      scanf("%d", vec + i);
      LIM = max(LIM, vec[i]);
    }
    LIM++;
    contar(cnt_izq);
    reverse(vec, vec + n);
    contar(cnt_der);
    reverse(cnt_der, cnt_der + n);
    number ans = 0;
    forn (i, n)
      ans += number(cnt_izq[i]) * number(cnt_der[i]);
    printf("%lld\n", ans);
  }
  return 0;
}

