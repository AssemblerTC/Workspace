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
const int maxn = 300010;
pair<Number, int> v[maxn];
Number ans[maxn];
int n;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  forn (i, n) {
    Number x;
    cin >> x;
    v[i] = {x, i};
  }
  sort(v, v + n);
  Number target = 0;
  forn (i, n) {
    if (v[i].first > target)
      target = v[i].first;
    ans[v[i].second] = target;
    target++;
  }
  forn (i, n) {
    if (i) cout << " ";
    cout << ans[i];
  }
  cout << '\n';
  return 0;
}
