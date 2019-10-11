#include <iostream>
#define max_n 20
using namespace std;

char a[max_n + 5][max_n + 5];
int w, h, cnt = 0;

void dfs(int x, int y) {
    if (x < 0 || x >= h || y < 0 || y >= w || a[x][y] == '#') return ;
    cnt++;
    a[x][y] = '#';
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x + 1, y);
    dfs(x, y - 1);
    return ;
}

int main() {
    cin >> w >>h;
    int x, y;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
            if (a[i][j] == '@') x = i, y = j;
        }
    }
    dfs(x, y);
    cout << cnt;
    return 0;
}
