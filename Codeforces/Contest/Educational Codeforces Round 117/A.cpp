#include "bits/stdc++.h"
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    int T;
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--){
        int x,y; cin>>x>>y;
        if((abs(x)+abs(y))%2){
            cout<<"-1"<<" "<<"-1"<<endl;
        }else{
            int flag = 0;
            for(int i=-50;i<=50;i++){
                if(flag) break;
                for(int j=-50;j<=50;j++){
                    int ac = abs(i)+abs(j);
                    int bc = abs(i-x)+abs(j-y);
                    int ab = abs(x)+abs(y);
                    if(flag) break;
                    if(ac==bc&&2*ac==ab&&2*bc==ab){
                        cout<<i<<" "<<j<<endl;
                        flag = 1;
                        break;
                    }
                }
            }
            if(!flag) cout<<"-1"<<" "<<"-1"<<endl;
        }
    }
    return 0;
}