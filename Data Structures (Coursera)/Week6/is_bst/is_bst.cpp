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
    int val,left,right;
};

vector <node> v; 
vector <int> vec;
void inorder(node x)
{
    if(x.left!=-1)inorder(v[x.left]);
    vec.push_back(x.val);
    if(x.right!=-1)inorder(v[x.right]);
    return;
}

void preorder(node x)
{
    cout<<x.val<<" ";
    if(x.left!=-1)preorder(v[x.left]);
    if(x.right!=-1)preorder(v[x.right]);

}

void postorder(node x)
{
    if(x.left!=-1)postorder(v[x.left]);
    if(x.right!=-1)postorder(v[x.right]);
    cout<<x.val<<" ";
}

int main()
{
    int n;
    cin>>n;
    if(n==0)
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
    if(is_sorted(all(vec)))cout<<"CORRECT";
    else cout<<"INCORRECT";

}