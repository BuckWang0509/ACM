#include "cstdio"
#include "cstring"
#include "iostream"
using namespace std;
const int maxn = 10;
char s[maxn][maxn];
int vis[maxn];
int n, k, cnt;
void dfs(int cur, int count) {
  if (count == k) {
    cnt++;
    return;
  }
  if (cur == n + 1) return;
  for (int i = 1; i <= n; ++i) {
    if (!vis[i] && s[cur][i] == '#') {
      vis[i] = 1, s[cur][i] = '.';
      dfs(cur + 1, count + 1);
      vis[i] = 0, s[cur][i] = '#';
    }
  }
  dfs(cur + 1, count);
}
int main() {
  // freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false);
  while (cin >> n >> k) {
    if (n == -1 && k == -1) break;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j) cin >> s[i][j];
    memset(vis, 0, sizeof(vis));
    cnt = 0;
    dfs(1, 0);
    cout << cnt << endl;
  }
  return 0;
}