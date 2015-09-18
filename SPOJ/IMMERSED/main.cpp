#include <bits/stdc++.h>

using namespace std;
double P, C;
int main() {
  long long p, c;
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%lld %lld", &p, &c);
    P = p;
    C = c;
    double izq = 0, der = 14;
    for (int it = 0; it < 30; it++) {
      double mid = (izq + der) / double(2);
      double val = mid * pow(mid, c * mid);
      if (val < P)
        izq = mid;
      else
        der = mid;
    }
    printf("%.6lf\n", izq);
  }
  return 0;
}
