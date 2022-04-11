#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
struct Node {
  LL Val, Start, End;
};
int main() {
  //freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false);
  LL pos = 0LL, point = 0LL;
  deque<Node> que;
  int T;
  cin >> T;
  while (T--) {
    int op;
    LL x, c;
    cin >> op;
    if (op == 1)
      cin >> x >> c;
    else
      cin >> c;
    if (op == 1) {
      que.push_back(Node{x, pos + 1, pos + c});
      pos += c ;
    } else {
      LL sum = 0;
      while (!que.empty()) {
        auto u = que.front();
        if (point + c < u.Start) break;
        if (point + c >= u.End) {
          sum += u.Val * (u.End - u.Start + 1);
          que.pop_front();
        } else {
          que.pop_front();
          que.push_front(Node{u.Val, min(point + c + 1,u.End), u.End});
          sum += u.Val * (point + c - u.Start + 1);
        }
      }
      point += c ;
      cout << sum << endl;
    }
  }
  return 0;
}