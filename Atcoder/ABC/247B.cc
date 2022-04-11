#include "bits/stdc++.h"
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  unordered_map<string, int> mp;
  for (int i = 1; i <= n; ++i) {
    string s, t;
    cin >> s;
    cin >> t;
    mp[s]++, mp[t]++;
  }
  int cnt = 0;
  for (auto &x : mp) {
    if (x.second >= 2) cnt++;
  }
  if (cnt >= 2)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
  return 0;
}