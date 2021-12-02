#include "bits/stdc++.h"
using namespace std;
const int maxn = 1e5+10;
int main()
{
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    int n;
    struct Node{
        int x,y,g,k;
    };
    Node p[maxn];
    cin>>n;
    for(int i=1;i<=n;i++) cin>>p[i].x>>p[i].y>>p[i].g>>p[i].k;
    int a,b;
    cin>>a>>b;
    for(int i=n;i>=1;i--){
        if(p[i].x<=a&&a<=p[i].x+p[i].g&&p[i].y<=b&&b<=p[i].y+p[i].k){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}