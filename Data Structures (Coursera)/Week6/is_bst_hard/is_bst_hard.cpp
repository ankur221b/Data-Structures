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

struct node
{
    ll val;
    int left,right;
};

vector <node> v; 
vector <int> vec;


bool chk(node x)
{
    bool X=1,Y=1;

    if(x.left==-1 && x.right==-1)return 1;

    if(x.left!=-1 && v[x.left].val >= x.val)return 0;
    if(x.right!=-1 && v[x.right].val < x.val)return 0;

    if(x.left!=-1) X = chk(v[x.left]);
    if(x.right!=-1) Y = chk(v[x.right]);

    if( !X || !Y )
    {
        return 0;
    }

    return 1;

    
}

void inorder(node x)
{
    if(x.left!=-1)inorder(v[x.left]);
    vec.push_back(x.val);
    if(x.right!=-1)inorder(v[x.right]);
    return;
}

int main()
{
    fast_io;
    int n;
    cin>>n;
    if(n==0 || n==1)
    {
        cout<<"CORRECT";
        return 0;
    }
    node x;
    for(int i=0;i<n;i++)
    {
        cin >> x.val >> x.left >> x.right;
        v.push_back(x);
    }
    
    inorder(v[0]);

    if(!is_sorted(all(vec)))
    {
        cout<<"INCORRECT";
        return 0;
    }

    if(chk(v[0]))cout<<"CORRECT";
    else cout<<"INCORRECT";    
    

}