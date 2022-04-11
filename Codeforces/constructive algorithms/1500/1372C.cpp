#include "bits/stdc++.h"
using namespace std;
const int maxn = 2e5 + 100;
int T, n, a[maxn];
int main() {
  // freopen("in.txt","r",stdin);
  ios::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int flag_equal = 0;
    for (int i = 1; i <= n; ++i) {
      if (a[i] != i) {
        flag_equal = 1;
        break;
      }
    }
    if (!flag_equal) {
      cout << "0" << endl;
      continue;
    }
    int left = 1, right = n;
    for (int i = 1; i <= n; ++i) {
      if (a[i] != i) {
        left = i;
        break;
      }
    }
    for (int i = n; i >= 1; --i) {
      if (a[i] != i) {
        right = i;
        break;
      }
    }
    int flag_diff = 0;
    for (int i = left; i <= right; ++i) {
      if (a[i] == i) {
        flag_diff = 1;
        break;
      }
    }
    if (!flag_diff)
      cout << "1" << endl;
    else
      cout << "2" << endl;
  }
  return 0;
}