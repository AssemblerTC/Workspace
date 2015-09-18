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
vector<int> divi[2001];
const int mod = 1000000007;
int dp[2001][2001];
int solve(int n, int last) {
  if (n == 0) return 1;
  if (dp[n][last] != -1) return dp[n][last];
  int ans = 0;
  for (int d: divi[last]) {
    ans += solve(n - 1, d);
    if (ans >= mod) ans -= mod;
  }
  return dp[n][last] = ans;
}
int n, k;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++)
      if (i % j == 0)
        divi[i].pb(j);
  memset(dp, -1, sizeof(dp));
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += solve(k - 1, i);
    if (ans >= mod) ans -= mod;
  }
  cout << ans << endl;
  return 0;
}
