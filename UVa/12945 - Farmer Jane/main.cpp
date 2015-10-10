#include <bits/stdc++.h>
using namespace std;
int n;
double x[101], y[101], w[101];
double sqr(double A) {return A * A;}
double costo(double X, double Y) {
  double ans = 0;
  for (int i = 0; i < n; i++) {
    ans += w[i] * (sqr(-X + x[i]) + sqr(-Y + y[i]));
  }
  return ans;
}
int main() {
  while (cin >> n) {
    double ax = 0, bx = 0, ay = 0, by = 0;
    for (int i = 0; i < n; i++) {
      cin >> x[i] >> y[i] >> w[i];
    }
    for (int i = 0; i < n; i++) {
      ax += w[i] * x[i];
      bx += w[i];
      ay += w[i] * y[i];
      by += w[i];
    }
    double ans = costo(ax / bx, ay / by);
    cout << setiosflags(ios::fixed) << setprecision(3) << ans << endl;
  }

  return 0;
}
