#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
int s;
cin >> s;
double ans = -1E9;
double mxeven = -1E9, mxodd = -1E9;
for (double i = 2; i < s; i += 2) {
    mxeven = max(mxeven, cos( (i - 2) / 2 ));
    ans = max(ans, 
        2. * sin(i/2) * mxeven + sin(s - i));
}
for (double i = 3; i < s; i += 2) {
    mxodd = max(mxodd, cos( (i - 2) / 2 ));
    ans = max(ans, 
        2. * sin(i/2) * mxodd + sin(s - i));
}
cout << fixed << setprecision(9) << ans << endl;
return 0;
}