#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
int main()
{
    //freopen("in.txt","r",stdin);
    int T;
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--){
        LL n,k;
        cin>>n>>k;
        LL ans=0,cur=1;
        while(cur<k){
            cur<<=1;
            ans++;
        }
        if(cur<n) ans+=(n-cur+k-1)/k;
        cout<<ans<<endl;
    }
    return 0;
}