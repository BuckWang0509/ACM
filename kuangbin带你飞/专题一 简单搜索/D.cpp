#include "cstdio"
#include "cstring"
#include "iostream"
using namespace std;
const int maxn = 20;
int m, n, s[maxn][maxn], f[maxn][maxn], vis[maxn][maxn], dp[maxn][maxn];
int cnt;
int dx[] = {1, -1, 0, 0, 0}, dy[] = {0, 0, 0, 1, -1};
void Rev(int x, int y) {
  for (int i = 0; i < 5; ++i) {
    int nx = x + dx[i], ny = y + dy[i];
    f[nx][ny] ^= 1;
  }
  cnt++;
  vis[x][y]++;
}
int main() {
  // freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin >> m >> n;
  for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= n; ++j) cin >> s[i][j];
  int mi = 0x3f3f3f3f;
  for (int loop = 0; loop < (1 << n); ++loop) {
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j) f[i][j] = s[i][j];
    int ans = loop;
    cnt = 0;
    for (int j = 1; j <= n; ++j) {
      if (ans & 1) Rev(1, j);
      ans >>= 1;
    }
    for (int i = 2; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (f[i - 1][j]) Rev(i, j);
      }
    }
    int j = 1;
    for (; j <= n; ++j) {
      if (f[m][j]) break;
    }
    if (j == n + 1 && cnt < mi) {
      mi = cnt;
      for (int i = 1; i <= m; ++i)
        for (int k = 1; k <= n; ++k) dp[i][k] = vis[i][k];
    }
  }
  if (mi == 0x3f3f3f3f)
    cout << "IMPOSSIBLE" << endl;
  else {
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j < n; ++j) cout << dp[i][j] << " ";
      cout << dp[i][n] << endl;
    }
  }
  return 0;
}