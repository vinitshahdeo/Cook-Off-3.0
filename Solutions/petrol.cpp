#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

lli oil[100000 + 10];
lli dis[100000 + 10];
int n;

int main(void) {
  int i, j, k, kase = 0;
  cin >> n;

  for (i = 0; i < n; i++)
    cin >> oil[i] >> dis[i];

  int st, en;
  en = 0, st = 0;
  lli sum = 0, d;

  while (st + 1 != en) {
    d = oil[st] - dis[st];
    if (sum + d >= 0)
      st++, sum += d;
    else
      sum = 0, st++, en = st;
    if (st >= n)
      st -= n;
  }
  printf("%d\n", en);

  return 0;
}