#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
int main()
{
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        LL k,x; cin>>k>>x;
        LL res = (1LL+k)*k/2;
        LL ans = 0;
        if(res>=x){
            LL l=1,r=k,v=1LL;
            while(l<=r){
                LL mid=(l+r)/2;
                LL tmp = (1LL+mid)*mid/2;
                if(tmp>=x){
                    r=mid-1;
                    v=mid;
                }else l=mid+1;
            }
            cout<<v<<endl;
        }else{
            ans+=k;
            x-=res;
            //cout<<"----->"<<x<<endl;
            LL l=1,r=k-1,v=1LL;
            while(l<=r){
                LL mid = (l+r)/2;
                LL tmp = (k-1+mid)*(k-mid)/2;
                //cout<<"**"<<mid<<endl;
                if(tmp>=x){
                    l=mid+1;
                    v=mid;
                }else r = mid-1;
            }
            cout<<ans+(k-v)<<endl;
        }
    }
    return 0;
}