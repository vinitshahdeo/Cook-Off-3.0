#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		int len=str.length();
		bool flag=0;
		for(int i=0,j=len-1;i<j;i++,j--)
			if(str[i]!=str[j])
			{
				flag=1;break;
			}
		if(flag)printf("NO\n");
		else
		{
			printf("YES ");
			if(len&1)printf("ODD\n");
			else printf("EVEN\n");
		}
	}
	return 0;
}