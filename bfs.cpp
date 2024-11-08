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

vector<int> bfs(int node, int n){

    vector<int> dist(n+1), vs(n+1);

    queue<int>q;
    q.push(node);
    vs[node]=1;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v:graph[u]){
            if(!vs[v]){
                dist[v] = dist[u] + 1;
                q.push(v);
                vs[v]=1;
            }
        }
    }

    return dist;

}


void solve(){
    
    int n, a, b;
    cin>>n>>a>>b;
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