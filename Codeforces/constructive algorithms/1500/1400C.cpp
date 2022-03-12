#include "bits/stdc++.h"
using namespace std;
int T,x;
int main()
{
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        cin>>x;
        int len = s.length();
        string w(len,'1');
        for(int i=0;i<len;++i){
            if(s[i]=='0'){
                if(i>=x) w[i-x]='0';
                if(i+x<len) w[i+x]='0';
            }
        }
        bool flag = 0;
        for(int i=0;i<len;++i){
            bool state = (i>=x)&&w[i-x]=='1';
            state = state ||((i+x<len)&&(w[i+x]=='1'));
            if(s[i]!=state+'0'){
                flag = 1; break;
            }
        }
        if(!flag) cout<<w<<endl;
        else cout<<"-1"<<endl;
    }
    return 0;
}