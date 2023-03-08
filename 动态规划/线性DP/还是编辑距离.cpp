#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
char a[1010][20];
char b[20];
int  f[110][110];


int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i]+1;
    int sb=m;
    while(sb--)
    {
        int k;
        cin>>b+1>>k;
         int res=0;
        int len2=strlen(b+1);
       for(int m=1;m<=n;m++)
       {
           int len1=strlen(a[m]+1);
           for(int w=1;w<=len1;w++) f[w][0]=w;
           for(int w=1;w<=len2;w++)  f[0][w]=w;
           
           for(int i=1;i<=len1;i++)
           {
               for(int j=1;j<=len2;j++)
               {
                   f[i][j]=min(f[i-1][j]+1,f[i][j-1]+1);
                   if(a[m][i]==b[j]) f[i][j]=min(f[i][j],f[i-1][j-1]);
                   else f[i][j]=min(f[i][j],f[i-1][j-1]+1);
               }
           }
           if(f[len1][len2]<=k) res++;
           
       }
         cout<<res<<endl;
    }
    
}
