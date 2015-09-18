#include <cstdio>
using namespace std;
char line[20];
int now = 0;
inline int getInt() {
  int n = -1;
  while (true)
    if (line[now]) {
      if (line[now] < '0' || line[now] > '9') {
        now++;
        continue;
      }
      n = 0;
      while (line[now] >= '0' && line[now] <= '9') {
        n = n * 10 + line[now] - '0';
        now++;
      }
      return n;
    }
    else {
      if(!gets(line)) return EOF;
      now = 0;
    }
  return n;
}
int n;
int x[101], y[101], w[101];
double sqr(double A) {return A * A;}
double costo(double X, double Y) {
  double ans = 0;
  for (int i = 0; i < n; i++) {
    ans += w[i] * (sqr(-X + x[i]) + sqr(-Y + y[i]));
  }
  return ans;
}
int main() {
  while ((n = getInt()) != EOF) {
    int ax = 0, bx = 0, ay = 0, by = 0;
    for (int i = 0; i < n; i++) {
      x[i] = getInt();
      y[i] = getInt();
      w[i] = getInt();
      ax += w[i] * x[i];
      bx += w[i];
      ay += w[i] * y[i];
      by += w[i];
    }
    printf("%.3lf\n", costo(double(ax) / bx, double(ay) / by));
  }
  return 0;
}
