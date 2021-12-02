#include "bits/stdc++.h"
using namespace std;
const int maxn=100+10;
int n,a[maxn];
int main()
{
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n+1;++i) cin>>a[i];
    string res="";
    for(int i=1;i<=n;i++){
        if(a[i]!=0){
            if(abs(a[i])==1){
                if(a[i]<0) res+='-';
                else res+='+';
            }else{
                if(a[i]>0) res+='+';
                res+=to_string(a[i]);
            }
            if(n-i+1==1) res+="x";
            else res+="x^"+to_string(n-i+1);
        }
    }
    if(a[n+1]!=0){
        if(a[n+1]>0) res+="+";
        res+=to_string(a[n+1]);
    }
    if(a[1]>0) cout<<res.substr(1)<<endl;
    else cout<<res<<endl;
    return 0;
}