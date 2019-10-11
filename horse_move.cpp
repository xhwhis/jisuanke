#include <iostream>
#define max_n 20
using namespace std;

int a[max_n + 5][max_n + 5] = {0};
int n, m, cnt = 0;

void dfs(int x, int y) {
    if (x < 0 || x >= m || y < 0 || y >= n || a[x][y]) return ;
    cnt++;
    a[x][y] = 1;
    dfs(x - 2, y - 1);
    dfs(x - 1, y - 2);
    dfs(x + 1, y + 2);
    dfs(x + 2, y + 1);
    dfs(x - 2, y + 1);
    dfs(x - 1, y + 2);
    dfs(x + 1, y - 2);
    dfs(x + 2, y - 1);
    return ;
}

int main() {
    cin >> n >> m;
    dfs(0, 0);
    cout << cnt;
    return 0;
}
