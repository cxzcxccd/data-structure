#include<iostream>
#include<algorithm>
using namespace std;
int a[100010];
void qs(int a[],int l,int r)
{
    if(l>=r) return;
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
 qs(a,l,j);qs(a,j+1,r);
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    qs(a,0,n-1);
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    return 0;
}
