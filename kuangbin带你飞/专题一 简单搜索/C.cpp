#include "cstdio"
#include "cstring"
#include "iostream"
#include "queue"
using namespace std;
const int maxn = 2e5 + 10;
int vis[maxn];
int n, k;
int operation(int num, int id) {
  switch (id) {
    case 0:
      return num - 1;
    case 1:
      return num + 1;
    case 2:
      return num * 2;
    default:
      return 0;
  }
}
struct Node {
  int num, step;
};
int main() {
  // freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false);
  while (cin >> n >> k) {
    queue<Node> que;
    que.push(Node{n, 0});
    memset(vis, 0, sizeof(vis));
    while (!que.empty()) {
      Node t = que.front();
      que.pop();
      if (t.num == k) {
        cout << t.step << endl;
        break;
      }
      for (int i = 0; i < 3; i++) {
        int temp = operation(t.num, i);
        if (temp >= maxn || temp < 0 || vis[temp]) continue;
        que.push(Node{temp, t.step + 1});
        vis[temp] = 1;
      }
    }
  }
  return 0;
}