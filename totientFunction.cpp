#include<bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define ll long long int
#define pii pair<int,int>
#define sz 1000005
#define inf 1000000001
#define mod 998244353
#define Mod 1000000007
#define pi acos(-1.0)

int phi[sz];
void totient(int upto){
    int check[upto+1]={0};
    for(int i=1; i<=upto; i++)
        phi[i]=i;`

    for(int i=2; i<=upto; i++){
        if(!check[i]){
            for(int j = i; j<=upto; j+=i){ 
                phi[j]=(phi[j]/i)*(i-1);
                check[j]=1;
            }
        }
    }

}


void solve(){
    
    int n;
    cin>>n;
    cout<<phi[n]<<endl;

}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1, tt=0;

    totient(1000000);


    cin>>t;
    while(t--){
        tt++;
        //cout<<"Case "<<tt<<": ";
        solve();
    }
    return 0;
}