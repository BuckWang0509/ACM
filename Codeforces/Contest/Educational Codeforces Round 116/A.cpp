#include "bits/stdc++.h"
using namespace std;
const int maxn=1000+1;
string s[maxn];
int main()
{
    //freopen("in.txt","r",stdin);
    int n;
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        int len=s[i].length();
        if(s[i][0]==s[i][len-1]) cout<<s[i]<<endl;
        else{
            s[i][len-1]=s[i][0];
            cout<<s[i]<<endl;
        }
    }
    return 0;
}