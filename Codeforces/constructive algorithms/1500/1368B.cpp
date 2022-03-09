/*
    在乘积相等时，和最小的情况是几个数尽量接近，两个数之间差值最多为1.枚举t和t+1的个数即可
*/
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
bool check(LL x, LL k) {
  LL sum = 1;
  for (int i = 1; i <= 10; ++i) {
    sum *= x;
  }
  if (sum >= k) return true;
  return false;
}
LL vis[15];
int main() {
  // freopen("in.txt","r",stdin);
  ios::sync_with_stdio(false);
  LL k;
  cin >> k;
  for (int i = 0; i < 10; ++i) vis[i] = 1;
  LL tmp = 1LL;
  for (LL i = 1; i <= 40LL; ++i) {
    if (check(i, k)) {
      tmp = i;
      break;
    }
  }
  tmp--;
  for (int i = 0; i <= 10; ++i) {
    LL sum = 1;
    for (int j = 1; j <= i; ++j) sum *= tmp;
    for (int j = i + 1; j <= 10; ++j) sum *= (tmp + 1LL);
    if (sum >= k) {
      for (int j = 0; j < i; ++j) vis[j] = tmp;
      for (int j = i; j < 10; ++j) vis[j] = tmp + 1LL;
    }
  }
  string res = "";
  string ss = "codeforces";
  for (int i = 0; i < ss.length(); ++i) {
    for (LL j = 0LL; j < vis[i]; ++j) res += ss[i];
  }
  cout << res << endl;
}