#include<iostream>
#include<algorithm>
using namespace std;
const int N=1010;
int f[N];
int a[N];
int g[N];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)  scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
         f[i]=1;
       //  g[i]=0;
         for(int j=1;j<=i-1;j++)
         {
             if(a[j]<a[i])
                // f[i]=max(f[i],f[j]+1);
                {
                    if(f[i]<f[j]+1) 
                    {
                        f[i]=f[j]+1;
                        g[i]=j;
                    }
                }
         }
    }
    int res1=0;
    int res2=0;
    for(int i=1;i<=n;i++) 
    {
        if(res1<f[i]) 
        {
            res1=f[i];
            res2=i;
        }
    }
    for(int i=0;i<res1;i++)
    {
       cout<<a[res2]<<" ";
        res2=g[res2];
    }
    
    cout<<res1;
    
    return 0;
}
