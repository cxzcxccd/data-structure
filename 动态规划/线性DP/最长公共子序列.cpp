#include<iostream>
#include<algorithm>
using namespace std;

char a[1010],b[1010];
int f[1010][1010];

//f[i,j]数组表示的是属于a序列前i个元素也属于b序列前j个元素的最长公共子序列的最大值.
/*f[i,j-1]数组表示的属于a序列前i个元素也属于b序列前j个元素的最长公共子序列的最大值，虽然他不等价于不选b[j],选a[i]这种决策,但是他
  包含了这种情况，f[i-1,j]也是同理，而这两种情况肯定也大于等于不选a[i]也不选b[j]这种情况*/
int main()
{
    int n,m;
    cin>>n>>m;
    cin>>a+1>>b+1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            f[i][j]=max(f[i-1][j],f[i][j-1]);
            if(a[i]==b[j]) f[i][j]=max(f[i][j],f[i-1][j-1]+1);
        }
    }
    
    cout<<f[n][m];
    return 0;
}
