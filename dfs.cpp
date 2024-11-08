#include<bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define ll long long int
#define pii pair<int,int>
#define sz 400005
#define inf 1000000001
#define mod 998244353
#define Mod 1000000007
#define pi acos(-1.0)

vector<int>tree[sz];
ll  vs[sz];

ll dfs(int n){
    vs[n]=1;

    for(auto u:tree[n]){
        if(!vs[u]){
            dfs(u);
        }
    }

}


void init(int n){
	for(int i=1; i<=n; i++){
        tree[i].clear();
        vs[i]=0;
    }
}


void solve(){
	
    int n, k, col;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }

    for(int i=1; i<n; i++){
        int u, v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    

}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1, tt=0;


    cin>>t;
    while(t--){
    	tt++;
    	//cout<<"Case "<<tt<<": ";
    	solve();
    }
    return 0;
}