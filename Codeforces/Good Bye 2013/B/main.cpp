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
int v[302];
int main() {
  int n;
  scanf("%d", &n);
  forn (i, n)
    scanf("%d", v + i);
  for (int i = 0; i < n - 1; i++) {
    if (v[i] == 0) printf("R");
    while (v[i] > 0) {
      printf("PR");
      v[i]--;
      if (v[i] > 0)
        printf("L");
    }
  }
  while (v[n - 1] > 0) {
    printf("LR");
    if (v[n - 1]) {
      printf("P");
      v[n - 1]--;
    }
  }
  printf("\n");
  return 0;
}
