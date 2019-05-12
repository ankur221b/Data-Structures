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
#define mod 100000

vector< list< pair<int,string> > > v(100000);



void add(int num, string name)
{
    int id = num%mod;
    for(auto it=v[id].begin();it!=v[id].end();it++)
    {
        if(it->ff == num)
        {
            it->ss = name;
            return;
        }
    }
    v[id].push_back({num,name});
}

string find(int num)
{
    int id = num%mod;

    for(auto it=v[id].begin();it!=v[id].end();it++)
    {
        if(it->ff == num)return it->ss;
    }

    return "not found";
}

void del(int num)
{
    int id = num%mod;

    for(auto it=v[id].begin();it!=v[id].end();it++)
    {
        if(it->ff == num)
        {
            it = v[id].erase(it);
            return;
        }
    }
    
}

int main()
{
    fast_io;
    int n,num;
    string q,name;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>q;
        if(q=="add")
        {
            cin>>num>>name;
            add(num,name);
        }
        if(q=="find")
        {
            cin>>num;
            cout<<find(num)<<'\n';
        }
        if(q=="del")
        {
            cin>>num;
            del(num);
        }
    }

}