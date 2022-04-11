#include "bits/stdc++.h"
using namespace std;
int main() {
  // freopen("in.txt","r",stdin);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    stack<int> p1, p2;
    vector<int> res(n);
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '0') {
        if (p2.empty()) {
          ++count;
          p1.push(count);
          res[i] = count;
        } else {
          int tmp = p2.top();
          res[i] = tmp;
          p2.pop();
          p1.push(tmp);
        }
      } else {
        if (p1.empty()) {
          ++count;
          p2.push(count);
          res[i] = count;
        } else {
          int tmp = p1.top();
          res[i] = tmp;
          p1.pop();
          p2.push(tmp);
        }
      }
    }
    cout << p1.size() + p2.size() << endl;
    for (auto &x : res) cout << x << " ";
    cout << endl;
  }
  return 0;
}