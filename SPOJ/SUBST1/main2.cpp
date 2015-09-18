#include <bits/stdc++.h>

using namespace std;

struct RTC{~RTC(){cerr << "Time: " << clock() * 1.0 / CLOCKS_PER_SEC <<" seconds\n";}} runtimecount;
#define DBG(X) cerr << #X << " = " << X << '\n';
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)
const int maxn = 50010;
const int maxlg = 17;
struct Suffix {
  int a, b, pos;
  bool operator <(const Suffix&o) const {
    if (a == o.a) return b < o.b;
    return a < o.a;
  }
  bool operator ==(const Suffix&o) const {
    return a == o.a && b == o.b;
  }
} L[maxn];
int p[maxlg][maxn];
char s[maxn];
int n = 0;
int suffix_array() {
  n = 0;
  for (n = 0; s[n]; n++)
    p[0][n] = s[n];
  int paso = 1, ancho, cnt_b;
  for ( paso = 1, ancho = 1; ancho <= n; paso++, ancho *= 2) {
    forn (i, n)
      L[i] = {p[paso - 1][i], i + ancho < n?p[paso - 1][i + ancho]:-1, i};
    sort(L, L + n);
    cnt_b = 0;//cnt_buckets
    forn (i, n)
      p[paso][L[i].pos] = (i > 0 && L[i] == L[i - 1])?p[paso][L[i - 1].pos]:cnt_b++;
    //if (cnt_b == n) break;
  }
  //DBG(cnt_b);
  assert(cnt_b == n);
  assert(paso < maxn);
  return paso;
}
long long solve(int paso) {
  //EN EL ULTIMO PASO TODOS ESTABAN EN DISTINTOS BUCKETS => paso - 1
  long long ans = 0, anstmp, tmp;
  forn (i, n - 1) {
    anstmp = 0;
    int x = L[i].pos, y = L[i + 1].pos;
    for (int k = paso - 1; k >= 0 && x < n && y < n; k--)
      if (p[k][x] == p[k][y]) {
        tmp = 1LL << (long long)(k);
        x += tmp;
        y += tmp;
        anstmp += tmp;
      }
    long long lcp = anstmp;
    ans += anstmp;
  }
  return ans;
}
int main() {
  int t;
  scanf("%d", &t);
  forn (_, t) {
    scanf("%s", s);
    long long ans = -solve(suffix_array());
    ans += (n * (n + 1) / 2LL);
    printf("%lld\n", ans);
  }
  return 0;
}
