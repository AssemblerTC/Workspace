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
pair<int,int> p[500 * 500 + 2];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    forn (i, n) forn (j, n) {
      int x;
      scanf("%d", &x);
      p[x] = {i, j};
    }
    int ans = 0;
    for (int upto = n * n, i = 2; i <= upto; i++)
      ans += abs(p[i].first - p[i - 1].first) + abs(p[i].second - p[i - 1].second);
    printf("%d\n", ans);
  }
  return 0;
}
