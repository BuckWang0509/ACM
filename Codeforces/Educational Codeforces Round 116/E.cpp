#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int maxn=500+10;
const LL mod = 998244353;
int n,k;
LL c[maxn][maxn],dp[maxn][maxn];
LL quickmod(LL a,int b){
    LL res=1;
    while(b){
        if(b&1) res=res*a%mod;
        a = a * a %mod;
        b>>=1;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>k;
    c[0][0]=1;
    for(int i=1;i<=505;++i){
        c[i][0]=1;
        for(int j=1;j<=i;j++) c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
    }
    for(int i=1;i<=k;i++) dp[1][i]=i,dp[2][i]=i*(i-1)%mod;
    for(int i=3;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(j<i){
                dp[i][j]=0;
                continue;
            }
            for(int l=0;l<i;l++){
                dp[i][j]+=(((dp[i-l][j-i+1]*quickmod((LL)(i-1),l))%mod)*c[i][l])%mod;
                dp[i][j]%=mod;
            }
        }
    }
    cout<<(quickmod((LL)k,n)-dp[n][k]+mod)%mod<<endl;
    return 0;
}