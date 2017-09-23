#include <stdio.h>
#include <string.h>
#define size 10000
int main()
{
    int t,n;
    char str[size];
    scanf("%d",&t);
    while(t--)
    {
        int count=0,j,k=0;
        scanf("%d",&n);
        scanf("%s",str);
        for(int i=0;str[i]!='\0';)
        {
            if(str[i]>='0' && str[i]<='9')
            {
                for(j=i+1;;j++)
                {
                    if(str[j]>='0' && str[j]<='9')
                        continue;
                    else
                    {
                        i=j+1;
                        count++;
                        break;
                    }
                }
            }
            else
                i++;
        }
        printf("%d\n",count);
    }
    return 0;
}