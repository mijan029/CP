#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 200005
#define inf 1e18
#define mod 998244353


ll bigmod(ll a, ll b, ll c){
    if(b==0) return 1;
    if(b%2){
        ll ans = bigmod(a,b/2,c);
        return ((ans*ans)%c)*a%c;
    }else{
        ll ans = bigmod(a,b/2,c);
        return ans*ans%c;
    }
}



int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t=1;
    //cin>>t;
    while(t--){
        
    }
    return 0;
}


