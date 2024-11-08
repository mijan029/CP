#include<bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define ll long long
#define pii pair<int,int>
#define sz 100005
#define inf 1e9
#define mod 998244353
#define Mod 1000000007
#define pi acos(-1.0)

void solve(){
    while(1){
        double area;
        cin>>area;
        if(area<0) return;

        double lo=0, hi = sqrt(area/2);
        double ans=0;
        while(hi-lo>1e-10){
            double m1 = lo + (hi-lo)/3;
            double m2 = hi - (hi-lo)/3;
            double h1 = sqrt(((area - m1*m1)/(2*m1)*(area - m1*m1)/(2*m1))-(m1*m1/4));
            double h2 = sqrt(((area - m2*m2)/(2*m2)*(area - m2*m2)/(2*m2))-(m2*m2/4));
            double vol1 = (m1*m1*h1/(3));
            double vol2 = (m2*m2*h2/(3));
            if(vol1<vol2){
                ans = vol2;
                lo=m1;
            }else{
                ans=vol1;
                hi=m2;
            }
        }
        cout<<fixed<<setprecision(4)<<ans<<endl;

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