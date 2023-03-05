#include<iostream>
#include<algorithm>
using namespace std;
const int N=1010;

int v[N],w[N];
int f[N][N];

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>v[i]>>w[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
               // f[i][j]=max(f[i][j],f[i-1][j-k*v[i]]+k*w[i]);
               f[i][j] = f[i-1][j];
            if(j-v[i]>=0)       f[i][j]=max(f[i-1][j],f[i][j-v[i]]+w[i]);
            
        }
    }
    cout<<f[n][m];
    return 0;
    
}
