//
// Created by buckwang on 22-6-11.
//
#include "bits/stdc++.h"
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    int T;cin>>T;
    while(T--){
        int n; cin>>n;
        string s; cin>>s;
        int count = 0;
        int index = s.length()/2;
        for(int i = index-1;i>=0;--i){
            if(s[i]==s[index]) count+=2;
            else break;
        }
        if(s.length()%2) ++count;
        cout<<count<<endl;
    }
    return 0;
}