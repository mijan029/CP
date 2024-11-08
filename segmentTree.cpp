#include<bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define ll long long int
#define pii pair<int,int>
#define sz 200005
#define inf 2e9
#define mod 998244353
#define Mod 1000000007
#define pi acos(-1.0)

int segt[26][4*sz], a[26][sz], b[26][sz];
int build(int n, int l, int r, int id){
    if(l==r){
        segt[id][n]=a[id][l];
        return segt[id][n];
    }
    int m = (l+r)/2;
    segt[id][n]=min(build(2*n,l,m,id),build(2*n+1,m+1,r,id));
    return segt[id][n];
}

int query(int n, int l, int r, int li, int ri, int id){
    if(li>r || ri<l) return inf;
    if(li<=l && r<=ri) return segt[id][n];
    int m = (l+r)/2;
    return min(query(2*n,l,m,li,ri,id),query(2*n+1,m+1,r,li,ri,id));
}

int dummy = -inf;
int segt[4*sz], val[4*sz], a[sz], lazy[4*sz];

int build(int n, int l, int r){
    if(l==r){
        segt[n]=l;
        val[n]=a[l];
        return segt[n];
    }
    int m = (l+r)/2;
    int a1 = build(2*n,l,m);
    int a2 = build(2*n+1,m+1,r);
    segt[n] = max(a1,a2);
    return segt[n];
}

void push(int n){
    lazy[2*n]+=lazy[n];
    segt[2*n]+=lazy[n];
    lazy[2*n+1]+=lazy[n];
    segt[2*n+1]+=lazy[n];
    lazy[n]=0;
}
void update(int n, int l, int r, int li, int ri, int val){
    if(r<li || l>ri) return;
    if(l>=li && r<=ri) {
        lazy[n]+=val;
        segt[n]+=val;
        return;

    }
    int m = (l+r)/2;
    push(n);
    update(2*n, l, m, li, ri, val);
    update(2*n+1, m+1, r, li, ri, val);
    segt[n]=max(segt[2*n],segt[2*n+1]);
    return;
}

pair<int,int> query(int n, int l, int r, int index){
    if(l==r) return {val[n],l};
    int m = (l+r)/2;
    pair<int,int> val;
    push(n);
    if(segt[2*n]>=index) val = query(2*n,l,m,index);
    else val = query(2*n+1,m+1,r,index);
    return val;
}


void solve(){

    int n, q;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    build(1,1,n);
    q=n;
    while(q--){
        int x;
        cin>>x;
        pair<int,int> val = query(1,1,n,x);
        cout<<val.first<<endl;

        x = val.second;
        update(1,1,n,x,x,-val.first);
        update(1,1,n,x,n,-1);

    }
    

}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1, tt=0;

    // cin>>t;
    while(t--){
        tt++;
        //cout<<"Case "<<tt<<": ";
        solve();
    }
    return 0;
}