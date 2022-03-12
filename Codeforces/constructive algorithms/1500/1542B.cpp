#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
int main() {
  // freopen("in.txt","r",stdin);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    LL n, a, b;
    cin >> n >> a >> b;
    if (a == 1LL) {
      if ((n - 1LL) % b)
        cout << "No" << endl;
      else
        cout << "Yes" << endl;
    } else {
      int flag = 0;
      LL ans = 1;
      while (ans <= n) {
        if ((n - ans) % b == 0) {
          flag = 1;
          break;
        }
        ans *= a;
      }
      if (flag)
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }
  }
  return 0;
}