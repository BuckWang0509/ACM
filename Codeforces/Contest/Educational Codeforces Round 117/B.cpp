#include "bits/stdc++.h"
using namespace std;
const int maxn=100+100;
int main()
{
    //freopen("in.txt","r",stdin);
    int T;
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--){
        int n,a,b;cin>>n>>a>>b;
        int f[n+1]; memset(f,0,sizeof(f));
        int vis[n+1]; memset(vis,0,sizeof(vis));
        f[n/2] = a,vis[a]=1;
        f[n/2+1] = b, vis[b]=1;
        int pos=n;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                while(f[pos]) pos--;
                f[pos] = i,vis[i]=1;
            }
        }
        int flag = 0;
        for(int i=1;i<=n/2;i++) if(f[i]<a) flag=1;
        for(int i=n/2+1;i<=n;i++) if(f[i]>b) flag=1;
        if(flag) cout<<"-1"<<endl;
        else{
            for(int i=1;i<=n;i++) cout<<f[i]<<" ";
            cout<<endl;
        }
    }
    return 0;
}