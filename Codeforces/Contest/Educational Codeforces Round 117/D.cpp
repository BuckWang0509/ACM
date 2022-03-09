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
        LL a,b,x; cin>>a>>b>>x;
        if(a>b) swap(a,b);
        int flag = 0;
        while(a){
            if(b%a==x%a&&x<=b) {
                flag = 1; break;
            }
            b%=a; swap(a,b);
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}