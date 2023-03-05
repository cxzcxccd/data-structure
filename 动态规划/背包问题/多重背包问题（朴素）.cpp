#include<iostream>
#include<algorithm>
using namespace std;

const int N=110;

int v[N],w[N],s[N];
int f[N][N];


int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)    scanf("%d%d%d",&v[i],&w[i],&s[i]);
    
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            f[i][j]=f[i-1][j];
            for(int k=0;k*v[i]<=j&&k<=s[i];k++)
            {
                f[i][j]=max(f[i][j],f[i-1][j-k*v[i]]+k*w[i]);
            }
        }
    }
    cout<<f[n][m];
    return 0;
}
