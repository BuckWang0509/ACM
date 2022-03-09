#include "bits/stdc++.h"
using namespace std;
int Cal(int &x,int &y,char ch){
    switch(ch){
        case 'U':
            y++;
            break;
        case 'D':
            y--;
            break;
        case 'R':
            x++;
            break;
        default:
            x--;
    }
    return (x*x)+(y*y);
}
int main(){
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        int n; cin>>n;
        string s; cin>>s;
        int sum = 0;
        int x=0,y=0;
        for(int i=0;i<n;++i){
            sum = max(sum,Cal(x,y,s[i]));
        }
        printf("%.6f\n",sqrt(sum));
    }
    return 0;
}