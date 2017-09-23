#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
  
using namespace std;
   
#define pb push_back
#define mp make_pair
#define F first
#define S second

const int N = 100500;

int n;
int a[N];
bool used[N];
pair<int, int> b[N], c[N];

void goB(int v) {
    if (used[v]) return;
    used[v] = true;
    goB(b[v].S);
}


void goC(int v) {
    if (used[v]) return;
    used[v] = true;
    goC(c[v].S);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        b[i] = c[i] = mp(a[i], i);
    }
    sort(b + 1, b + 1 + n);
    sort(c + 1, c + 1 + n);
    reverse(c + 1, c + 1 + n);
    for (int i = 1; i <= n; i++) {
        used[i] = false;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            ++ans;
            goB(i);
        }
    }
    int result = ans;
    for (int i = 1; i <= n; i++) {
        used[i] = false;
    }
    ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            ++ans;
            goC(i);
        }
    }
    int answer = min(n - result, n - ans);
    printf("%d\n", answer);
    return 0;
}