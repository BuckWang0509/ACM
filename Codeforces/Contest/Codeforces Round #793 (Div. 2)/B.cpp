#include "bits/stdc++.h"
using namespace std;
int main() {
  // freopen("in.txt","r",stdin);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n; cin >> n;
    int ans = (1 << 30) - 1;
    for (int i = 0; i < n; ++i) {
    int x;
      cin >> x;
      if(x!=i) ans &= x;
    }
    cout << ans << endl;
  }
  return 0;
}