#include "bits/stdc++.h"
using namespace std;
const int maxn = 1e4 + 100;
int a[maxn], b[maxn];
int T;
bool cmp(int x, int y) { return x > y; }
int main() {
  // freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    vector<int> v;
    int n, A, B;
    cin >> A >> B >> n;

    for (int i = 1; i <= A; ++i) {
      int x;
      cin >> a[i];
      v.push_back(a[i]);
    }
    for (int i = 1; i <= B; ++i) {
      cin >> b[i];
    }
    sort(b + 1, b + 1 + B, cmp);
    if (A + min(n / 2, B) < n) {
      cout << "-1" << endl;
      continue;
    }
    for (int i = 1; i <= min(n / 2, B); ++i) v.push_back(b[i]);
    sort(v.begin(), v.end(), cmp);
    int sum = 0;
    for (int i = 0; i < n; ++i) sum += v[i];
    cout << sum << endl;
    v.clear();
    v.shrink_to_fit();
  }
  return 0;
}
