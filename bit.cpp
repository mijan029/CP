#include<bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define endl '\n'
#define ll long long
#define sz 500005
#define inf 2e18
#define mod 998244353
#define pi acos(-1.0)


int bit[sz];
int query(int idx){	// returns sumation of vals from 1 to idx
       int sum=0;
       while(idx>0){
             sum+=bit[idx];
             idx -= idx & (-idx);
       }
       return sum;
}
void update(int idx, int x, int n)// add val to index idx, total bit size n
{
       while(idx<=n)
       {
             bit[idx]+=x;
             idx += idx & (-idx);
       }
}

void solve(){
	//can be used memset to free upto a fixed arr position
	//memset(pointer of the arr, 0/-1, size in byte)
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1, tt=0;
    cin>>t;
    while(t--){
    	solve();
    }
    return 0;
}