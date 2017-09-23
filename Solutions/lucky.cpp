#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int max_num = 1458;
const int max_sum = 162;
const int max_length = 19;

LL dp[max_length + 1][max_sum + 1][max_num + 1];
int digits[max_length + 1];
bool composite[max_num + 1];
int len;

void get_primes(){

    composite[0] = composite[1] = true;

    for(long long i = 2; i * i <= max_num; i++){
        if(!composite[i]){
            for(long long j = i * i; j <= max_num; j+= i){
                composite[j] = true;
            }
        }
    }
}

LL rec(int pos, int s1, int s2, int chk)
{
    if(pos == -1)
        return !composite[s1] && !composite[s2];


    if(!chk && dp[pos][s1][s2] != -1)
        return dp[pos][s1][s2];

    LL ans = 0;
    int end = chk ? digits[pos] : 9;

    for(int d = 0 ; d <= end; d++) {
        ans += rec(pos - 1 , s1 + d , s2 + d * d, chk && d == end);
    }

    if(!chk)
        dp[pos][s1][s2] = ans;

    return ans;
}

LL get_ans(LL num) {

    if(num == 0)
        return 0;

    len = 0;

    while(num){

        digits[len++] = num % 10;
        num /= 10;
    }

    LL ans = rec(len - 1, 0, 0, 1);
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);

    int t;

    get_primes();
    memset(dp,-1,sizeof(dp));
    cin >> t;

    while(t--) {

        LL a, b;
        cin >> a >> b;
        cout << get_ans(b) - get_ans(a - 1)  << endl;
    }

    return 0;
}