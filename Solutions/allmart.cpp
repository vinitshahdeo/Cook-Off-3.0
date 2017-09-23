#include<bits/stdc++.h>
using namespace std;
pair<long long,int> pre[200000];
long long a[25],N;
#define INF 2000000000000000000LL
long long trunc_mul(long long a, long long b)
{
    return a <= INF / b ? a * b : INF;
}
void compute()
{
    int limit = 1<<N;
    limit--;
    for(int i = 1;i <= limit;i++)
    {
        long long lcm = 1;
        pre[i].second = __builtin_popcount(i);
        int k = 1;
        for(int j = N-1;j>=0;j--)
        {
            if(k&i)
            {
                lcm = trunc_mul(lcm/__gcd(lcm,a[j]), a[j]); 

            }
            k = k<<1;
        }
        pre[i].first = lcm;
    }
    return ;
}
int main()
{
    cin >> N;
    for(int i = 0;i < N;i++)
    {
        cin >> a[i];
    }
    compute();
    int limit = 1<<N;
    limit--;
    int Q;
    cin >> Q;
    while(Q--){
        long long L,R;
        cin >> L >> R;
        long long ans = 0;
        L--;
        for(int i = 1;i <= limit;i++)
        {
            if(pre[i].second%2 == 1)ans+=((long long)(R/pre[i].first)-(long long)(L/pre[i].first));
            else ans-=((long long)(R/pre[i].first)-(long long)(L/pre[i].first));
        }
        cout << ans << endl;
    }

    return 0;
}