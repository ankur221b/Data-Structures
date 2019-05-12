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


int main()
{
  ll n;
  cin>>n;

  ll v[n+1];
  vector<pll> swaps;

  for(int i=1;i<=n;i++)
  {
    cin>>v[i];
  }

  int j=n;
  while(j>1)
  {
    int i=j,c=0;

    while(1)
    {

      if(v[i/2]>v[i])
      {
        swap(v[i/2],v[i]);
        swaps.push_back({i/2-1,i-1});
        c++;
      }
      i=i/2;

      if(i<=1)break;

    }
    if(c==0)j--;
  }

  cout<<swaps.size()<<"\n";
  for(int i=0;i<swaps.size();i++)
  {
    cout<<swaps[i].ff<<" "<<swaps[i].ss<<"\n";
  }

}