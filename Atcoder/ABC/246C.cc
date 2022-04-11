#include "bits/stdc++.h"
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n; cin>>n;
    string s ="1";
    for(int i=2;i<=n;++i){
        s = s+" "+to_string(i)+" "+s;
    }
    cout<<s<<endl;
    return 0;
}