#include<iostream>
#include<algorithm>

using namespace std;

const int N=25000;
const int M=2010;
int f[M];
int v[N],w[N];


int main()
{
    int n,m,cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int a,b,s;
        cin>>a>>b>>s;
        int k=1;
        while(k<=s)
        {
            cnt++;
            v[cnt]=a*k;
            w[cnt]=b*k;
            s-=k;
            k*=2;
        }
        if(s>=0)
        {
            cnt++;
            v[cnt]=a*s;
            w[cnt]=b*s;
        }
    }
 /*   for(int i=1;i<=cnt;i++)
    {
        for(int j=0;j<=m;j++)
        {
            f[i][j]=f[i-1][j];
            if(j-v[i]>=0) f[i][j]=max(f[i][j],f[i-1][j-v[i]]+w[i]);
        }
    }*/
     for(int i=1;i<=cnt;i++)
    {
        for(int j=m;j>=v[i];j--)
        {
            
             f[j]=max(f[j],f[j-v[i]]+w[i]);
        }
    }
    cout<<f[m];
    
    return 0;
}
