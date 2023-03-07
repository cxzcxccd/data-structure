#include<iostream>
#include<algorithm>
using namespace std;

const int N=100100;

int a[N],b[N],f[N],s[N],c[N];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        s[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&c[i]);
        b[i]=s[c[i]];
    }
    int len =0;
    f[0]=-2e9;
    for(int i=1;i<=n;i++)
    {
        int l=0,r=len;
        while(l<r)
        {
            int mid=l+r+1>>1;
            if(f[mid]<b[i])  l=mid;
            else r=mid-1;
        }
        len=max(len,r+1);
        f[r+1]=b[i];
    }
    
    cout<<len;
    
    
    return 0;
}
//洛谷1439
