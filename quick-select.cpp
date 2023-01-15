#include<iostream>
#include<algorithm>
using namespace std;
int a[100010];
int qs(int a[],int l,int r,int k)
{
    if(l>=r) return a[l];
    int i=l-1;int j=r+1;
    int x=(a[l]+a[r])/2;
    while(i<j)
    {
        do
        {
            i++;
        }while(a[i]<x);
        do
        {
            j--;
        }
        while(a[j]>x);
        if(i<j) swap(a[i],a[j]);
    }
    int sl=j-l+1;
    if(k<=sl) qs(a,l,j,k);
    else      qs(a,j+1,r,k-sl);//这一步做差是精髓。
}
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    cout<<qs(a,0,n-1,k);
    return 0;
}
