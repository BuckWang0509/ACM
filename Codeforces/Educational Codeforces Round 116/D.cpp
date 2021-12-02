#include "bits/stdc++.h"
using namespace std;
const int maxn=0x3f3f3f3f;
int T;
int main()
{
    ios::sync_with_stdio(false);
    //freopen("in.txt","r",stdin);
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        int a[n+1][m+1];
        for(int i=1;i<=n;i++)
         for(int j=1;j<=m;j++)
            cin>>a[i][j];
        int Lmax[n+1][m+1],Lmin[n+1][m+1],Rmax[n+1][m+1],Rmin[n+1][m+1];
        for(int i=1;i<=n;i++) Lmax[i][1] = a[i][1], Lmin[i][1] = a[i][1];
        for(int i=1;i<=n;i++) Rmax[i][m] = a[i][m], Rmin[i][m] = a[i][m];
        for(int i=1;i<=n;i++){
            for(int j=2;j<=m;j++){
                Lmax[i][j] = max(Lmax[i][j-1],a[i][j]);
                Lmin[i][j] = min(Lmin[i][j-1],a[i][j]);
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=m-1;j>=1;j--){
                Rmax[i][j] = max(Rmax[i][j+1],a[i][j]);
                Rmin[i][j] = min(Rmin[i][j+1],a[i][j]);
            }
        }
        int flag = 0;
        for(int j=1;j<m;j++){
            vector<pair<int,int>>vec;
            for(int i=1;i<=n;i++) vec.push_back(make_pair(Lmin[i][j],i));
            sort(vec.begin(),vec.end(),[](const pair<int,int>& a,const pair<int,int>& b){
                if(a.first==b.first) return a.second < b.second;
                return a.first<b.first;
            });
            int num[n+1];
            for(int i=1;i<=n;i++) num[i] = vec[i-1].second;
            int lmaxv[n+2],lminv[n+2],rmaxv[n+2],rminv[n+2];
            for(int i=0;i<=n+1;i++) lmaxv[i]=rmaxv[i]=0,lminv[i]=rminv[i]=maxn;
            for(int i=1;i<=n;i++){
                lmaxv[i] = max(lmaxv[i-1],Lmax[num[i]][j]);
                rminv[i] = min(rminv[i-1],Rmin[num[i]][j+1]);
            }
            for(int i=n;i>=1;i--){
                lminv[i] = min(lminv[i+1],Lmin[num[i]][j]);
                rmaxv[i] = max(rmaxv[i+1],Rmax[num[i]][j+1]);
            }
            for(int i=1;i<n;i++){
                if(lmaxv[i] < lminv[i+1] && rminv[i] > rmaxv[i+1]){
                    cout<<"YES"<<endl;;
                    char s[n+1]; s[n]=0;
                    for(int k=1;k<=n;k++)
                        s[num[k]-1] = (k<=i ? 'B' : 'R');
                    cout<<s<<" "<<j<<endl;
                    flag=1; break;
                }
            }
            if(flag) break;
        }
        if(!flag) cout<<"NO"<<endl;
    }
    return 0;
}