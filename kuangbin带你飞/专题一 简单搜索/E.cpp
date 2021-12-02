#include "cstdio"
#include "iostream"
#include "queue"
using namespace std;
typedef long long LL;
int main() {
  // freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false);
  LL n;
  while (cin >> n && n) {
    queue<LL> que;
    que.push(1LL);
    while (!que.empty()) {
      LL t = que.front();
      que.pop();
      if (t % n == 0) {
        cout << t << endl;
        break;
      }
      que.push(t * 10LL);
      que.push(t * 10LL + 1LL);
    }
  }
  return 0;
}