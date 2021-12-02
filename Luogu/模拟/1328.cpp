#include "bits/stdc++.h"
using namespace std;
const int maxn=200+10;
int main()
{
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    int n,na,nb;
    cin>>n>>na>>nb;
    vector<int>ta(na+1),tb(nb+1);
    for(int i=0;i<na;i++){
        cin>>ta[i];
    }
    for(int i=0;i<nb;i++){
        cin>>tb[i];
    }
    vector<int>ra,rb;
    for(int i=0;i<n/na;i++)
        for(int j=0;j<na;j++) ra.push_back(ta[j]);
    for(int i=0;i<n%na;i++) ra.push_back(ta[i]);
    for(int i=0;i<n/nb;i++)
        for(int j=0;j<nb;j++) rb.push_back(tb[j]);
    for(int i=0;i<n%nb;i++) rb.push_back(tb[i]);
    auto compare = [&](int x,int y){
        int ans = 0;
        switch(x){
            case 0:
                if(y==1||y==4) ans = -1;
                else if(y==2||y==3) ans = 1;
                break;
            case 1:
                if(y==0||y==3) ans = 1;
                else if(y==2||y==4) ans = -1;
                break;
            case 2:
                if(y==4||y==1) ans = 1;
                else if(y==0||y==3) ans = -1;
                break;
            case 3:
                if(y==2||y==4) ans =1;
                else if(y==1||y==0) ans =-1;
                break;
            case 4:
                if(y==0||y==1) ans =1;
                else if(y==2||y==3) ans =-1;
                break; 
        }
        return ans;
    };
    int sa = 0, sb= 0;
    for(int i=0;i<n;i++){
        int tmp = compare(ra[i],rb[i]);
        if(tmp==0) continue;
        else if(tmp>0) sa++;
        else sb++;
    }
    cout<<sa<<" "<<sb<<endl;
    return 0;
}