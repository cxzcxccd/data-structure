#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int rp(int x)
{
    int res=1;
    while(x--)    res*=10;
    return res;
}
int getnum(vector<int>A,int l,int r)
{
    int res=0;
    for(int i=l;i>=r;i--)
    {
        res=res*10+A[i];
    }
    return res;
}

int count(int n,int x)//返回从1到n中x出现的次数和
{
    if(!n) return 0;
    int res=0;
    vector<int>A;
    while(n!=0)
    {
        A.push_back(n%10);
        n/=10;
    }
    n=A.size();
    for(int i=n-1-!x;i>=0;i--)
    {
        if(i<n-1)
        {
            int l=n-1,r=i+1;
            res+=getnum(A,l,r)*rp(i);
            if(!x) res-=rp(i);
        }
         if(A[i]>x)  res+=rp(i);
         if(A[i]==x) res+=getnum(A,i-1,0)+1;    
         
    }
    return res;
}




int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b),a||b)
    {
        if(a>b) swap(a,b);
        for(int i=0;i<10;i++) 
        cout<<count(b,i)-count(a-1,i)<<" ";
        printf("\n");   
    }
    return 0;
}
