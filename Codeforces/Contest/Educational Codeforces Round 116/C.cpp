#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int maxn=10+1;
int T,n,k;
LL a[maxn];
LL quick_mul(LL a,LL b){
    LL res = 1;
    while(b){
        if(b&1) res*=a;
        a*=a;
        b>>=1;
    }
    return res;
}
int main()
{
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--){
        cin>>n>>k;
        k++;
        for(int i=0;i<n;i++){
            LL x;
            cin>>x;
            a[i] = quick_mul(10LL,x);
        }
        LL ans = 0;
        for(int i=0;i<n;i++){
            int cnt = k;
            if(i!=n-1) cnt=min(cnt,(int)(a[i+1]/a[i]-1));
            ans+=1LL*(LL)cnt*a[i];
            k-=cnt;
        }
        cout<<ans<<endl;
    }
    return 0;
}