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
typedef long long int Number;
Number dp[50][2];
Number contar(int n, int last = 0) {
  if (n == 0) return 1LL;
  if (dp[n][last] != -1) return dp[n][last];
  Number ans = contar(n - 1, 0);//pongo un cero no importa cual era antes
  if (last != 1)
    ans += contar(n - 1, 1);
  return dp[n][last] = ans;
}
string solve(int n, Number k) {
  if (k > contar(n))
    return "-1";
  string ans = "";
  for (int i = 1; i <= n; i++) {
    int tam = n - i;
    //0 XXXX.XXX cnt1  1 - cnt1
    //1 XXXX.XXX cnt2  (cnt1 + 1) - 
    if (contar(tam) < k) {
      ans.pb('1');
      k -= contar(tam);
    } else {
      ans.pb('0');
    }
  }
  return ans;
}
int main() {
  memset(dp, -1, sizeof(dp));
  int n;
  Number k;
  scanf("%d %lld", &n, &k);
  printf("%s\n", solve(n, k).c_str());
  return 0;
}
