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
int lcp[maxn];
int p[maxlg][maxn];
char s[maxn];
int n = 0;
int suffix_array() {
  forn (i, n)
    p[0][i] = s[i];
  assert(n <= maxn);
  int paso = 1, ancho, cnt_b;
  for (paso = 1, ancho = 1; ; paso++, ancho *= 2) {
    forn (i, n)
      L[i] = {p[paso - 1][i], i + ancho < n?p[paso - 1][i + ancho]:-1, i};
    sort(L, L + n);
    cnt_b = 0;//cnt_buckets
    forn (i, n)
      p[paso][L[i].pos] = (i > 0 && L[i] == L[i - 1])?p[paso][L[i - 1].pos]:cnt_b++;
    if (cnt_b == n) break;
  }
  assert(cnt_b == n);
  assert(paso < maxn);
  return paso;
}

void kasai(int paso) {
  memset(lcp, 0, sizeof(lcp));
  int k = 0;
  for (int i = 0; i < n; i++, k?k--:0) {
    if (p[paso][i] == n - 1) {k = 0; continue;}
    int j = L[p[paso][i] + 1].pos;
    while (i + k < n && j + k < n && s[i+k]==s[j+k]) k++;
    lcp[p[paso][i]] = k;
  }
}

int main() {
  int t;
  scanf("%d", &t);
  forn (_, t) {
    scanf("%s", s);
    n = strlen(s);
    long long ans = (n * (n + 1LL) / 2LL);
    s[n++] = '$';
    kasai(suffix_array());
    forn (i, n)
      ans -= lcp[i];
    printf("%lld\n", ans);
  }
  return 0;
}
