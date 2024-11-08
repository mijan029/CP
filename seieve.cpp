#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 1000005
#define inf 1e18
#define mod 1000000007

int leastPrime[sz];
void seieve(int upto){
    for(int i=2; i*i<=upto; i++){
        for(int j = i*i; j<=upto; j+=i){ 
            if(!leastPrime[j]) leastPrime[j]=i;
        }
    }
    for(int i=2; i<=upto; i++){
        if(!leastPrime[i]) leastPrime[i]=i;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int upto = 1000000, mx=0, num;
    int a[upto+1] = {0};
    for(int i=1; i<=upto; i++){
        for(int j=i; j<=upto; j+=i){
            a[j]++;
            if(a[j]>mx){
                num = j;
                mx = a[j];
            }
        }
    }

    cout<<mx<<' '<<num<<endl;

    

    return 0;
}
