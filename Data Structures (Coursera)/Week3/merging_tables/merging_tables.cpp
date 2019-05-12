#include<bits/stdc++.h> 
using namespace std;

#define ll long long
#define fast_io ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MAX 100001
#define MOD 1000000007

int root(int *parent,int a)
{
    while(parent[a]!=a)
    {
      a = parent[parent[a]];       
    }
    return a;
}

int merge(int *parent,int *size,int a,int b)
{
    int A = root(parent,a);
    int B = root(parent,b);
    if(A==B)return 0;

    if(size[A]>size[B])
    {
      parent[B]=A;
      size[A]+=size[B];
      size[B]=0;
      return size[A];
    }
    else
    {
      parent[A]=B;
      size[B]+=size[A];
      size[A]=0;
      return size[B];
    }
}

int main()
{
  fast_io;

  int n,m,a,b,x,ma=-1;
  cin>>n>>m;
  int parent[n],size[n];  

  for(int i=0;i<n;i++)
  {
    cin>>size[i];
    parent[i]=i;
    ma=max(ma,size[i]);
  }

  for(int k=0;k<m;k++)
  {
    cin>>a>>b;
    x = merge(parent,size,a-1,b-1);
    ma=max(ma, x);
    cout<<ma<<"\n";

  }

}