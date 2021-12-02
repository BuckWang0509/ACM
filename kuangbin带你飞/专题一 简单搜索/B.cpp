#include "cstdio"
#include "cstring"
#include "iostream"
#include "queue"
using namespace std;
const int maxn = 35;
const int INF = 0x3f3f3f3f;
int h, n, m;
int vis[maxn][maxn][maxn];
char s[maxn][maxn][maxn];
int dx[] = {1, -1, 0, 0, 0, 0}, dy[] = {0, 0, 1, -1, 0, 0},
    dz[] = {0, 0, 0, 0, 1, -1};
struct Node {
  int x, y, z, step;
};
int main() {
  // freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false);
  while (cin >> h >> n >> m) {
    if (!h && !n && !m) break;
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i <= 30; ++i) {
      for (int j = 0; j <= 30; ++j) {
        for (int k = 0; k <= 30; ++k) s[i][j][k] = '#';
      }
    }
    queue<Node> que;
    for (int i = 1; i <= h; ++i) {
      for (int j = 1; j <= n; ++j) {
        for (int k = 1; k <= m; ++k) {
          cin >> s[i][j][k];
          if (s[i][j][k] == 'S') {
            que.push({i, j, k, 0});
          }
        }
      }
    }
    int mx = INF;
    while (!que.empty()) {
      Node u = que.front();
      vis[u.x][u.y][u.z] = 1;
      que.pop();
      if (s[u.x][u.y][u.z] == 'E') {
        mx = min(u.step, mx);
        break;
      }
      for (int i = 0; i < 6; i++) {
        int nx = u.x + dx[i], ny = u.y + dy[i], nz = u.z + dz[i];
        if (nx < 0 || nx > h || ny < 0 || ny > n || nz < 0 || nz > m ||
            vis[nx][ny][nz] || s[nx][ny][nz] == '#')
          continue;
        que.push({nx, ny, nz, u.step + 1});
        vis[nx][ny][nz] = 1;
      }
    }
    if (mx == INF)
      cout << "Trapped!" << endl;
    else
      cout << "Escaped in " << mx << " minute(s)." << endl;
  }
  return 0;
}
