#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 200005
#define inf 1e9
#define mod 998244353

vector<pair<int, int>> adj[sz];
vector<int>d,p,ans,vs,vis;
vector<int>vec[sz];
int a[sz], mx=0, node=0;

void dijkstra(int s, int n) {
    d[s] = a[s];
    priority_queue<pair<int, int>> q;
    q.push({a[s], s});
    while (!q.empty()) {
        int v = q.top().second;
        vis[v]=1;
        int d_v = q.top().first;
        q.pop(); vs[v]=1;
        if (d_v != d[v])
            continue;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second; //cout<<to<<' '<<len<<' '<<v<<endl;
            if(!vs[to]){
                if (d[v] + len + a[to] > d[to]) {
                    d[to] = d[v] + len + a[to];
                    p[to] = v;
                    q.push({d[to], to});
                }
            }
            
        }
    }
}


int dfs(int n)
{
    vis[n]=1;
    vector<pair<int,int>> val;
    for(auto u:vec[n]){
        int k = dfs(u);
        val.push_back({d[k]-d[n],k});
    }
    if(val.size()==0){
        if(a[n]>mx){
            mx = a[n]; node = n;
        }
        return n;
            
    }else if(val.size()==1){
        if(val[0].first+a[n]>mx){
            mx = val[0].first+a[n];
            node = val[0].second;
            
        }
        return val[0].second;
    }else{
        sort(val.begin(),val.end(),greater<pair<int,int>>());
        if(val[0].first+val[1].first+a[n]>mx){
            node = val[0].second;
            mx = val[0].first+val[1].first+a[n];
        }
        return val[0].second;
    }
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t=1;
    //cin>>t;
    while(t--){
            int n, m, k=0;
            cin>>n>>m; 
            for(int i=1; i<=n; i++)
                cin>>a[i];
            for(int i=1; i<=m; i++){
                int u,v,w;
                cin>>u>>v>>w;
                adj[u].push_back({v,w});
                adj[v].push_back({u,w});
            }

     


    }
    return 0;
}


