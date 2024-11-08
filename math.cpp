#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 1000005
#define inf 1e18
#define mod 1000000007

int leastPrime[sz];
void sieve(int upto){
	for(int i=2; i*i<=upto; i++){
        for(int j = i*i; j<=upto; j+=i){ 
            if(!leastPrime[j]) leastPrime[j]=i;
        }
    }
    for(int i=2; i<=upto; i++){
        if(!leastPrime[i]) leastPrime[i]=i;
        //if(i<=100) cout<<i<<' '<<leastPrime[i]<<endl;
    }
}

ll bigmod(ll a, ll b, ll c){
	if(!b) return 1;
	ll ans = bigmod(a,b/2,c);
	if(b%2) return (ans*ans%c)*a%c;
	else return ans*ans%c;
}

ll fact[sz], invfact[sz], inv[sz];

void generate_fact(int upto){
	fact[0]=1;
	for(int i=1; i<=upto; i++)
		fact[i] = fact[i-1]*i%mod;
}

void generate_invfact(int upto){
	inv[1]=1;
	for(int i=2; i<=upto; i++)
		inv[i] = (mod-mod/i)*inv[mod%i]%mod;

	invfact[0]=1;
	for(int i=1; i<=upto; i++)
		invfact[i] = invfact[i-1]*inv[i]%mod;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    generate_invfact(n);
    for(int i=1; i<=n; i++){
    	ll r = bigmod(i,mod-2,mod);

    	cout<<inv[i]<<' '<<r<<' '<<inv[i]-r<<endl;
    }

    return 0;
}