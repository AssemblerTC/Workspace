#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define sz(x) ((int)(x).size())
#define forn(i, n) for (int i = 0; i < (n); i++)
typedef long long int number;
const int maxn = 5010;
int n;
vector<int> g[maxn];
int parent[maxn];
vector<vector<int> > level, new_level;

void next_level() {
  new_level.clear();
  forn (i, sz(level)) {
    const vector<int> &group = level[i];
    vector<int> new_group;
    forn (j, sz(group)) {
      int u = group[j];
      forn (k, sz(g[u])) {
        int v = g[u][k];
        if (v != parent[u]) {
          new_group.pb(v);
          parent[v] = u;
        }
      }
    }
    if (sz(new_group) > 0)//this is important
      new_level.pb(new_group); 
  }
  swap(level, new_level);
}

vector<number> size_group;
number dp[maxn][3];
number solve(int pos, int rem) {
  if (rem == 0) return 1LL;
  if (pos == sz(size_group))
    return number(rem == 0);
  if (dp[pos][rem] != -1LL) return dp[pos][rem];
  number ans = solve(pos + 1, rem);
  ans += size_group[pos] * solve(pos + 1, rem - 1);
  return dp[pos][rem] = ans;
}

int main() {
  scanf("%d", &n);
  forn (i, n - 1) {
    int u, v;
    scanf("%d %d", &u, &v);
    g[u].pb(v);
    g[v].pb(u);
  }
  number ans = 0;
  for (int center = 1; center <= n; center++) {
    memset(parent, -1, sizeof(parent));
    level.clear();
    forn (i, sz(g[center])) {//first level after root
      int v = g[center][i];
      level.pb(vector<int>(1, v));
      parent[v] = center;
    }
    while (sz(level) >= 3) {//can't take 3 node if there are < 3 groups
      size_group.clear();//colect the sizes of groups
      forn (i, sz(level)) {
        assert(sz(level[i]) > 0);//this should be > 0 
        size_group.pb(sz(level[i]));
      }
      memset(dp, -1, sizeof(dp));
      ans += solve(0, 3);
      next_level();
    }
  }
  printf("%lld\n", ans);
  return 0;
}
