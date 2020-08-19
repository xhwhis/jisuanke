#include <stdio.h>
#include <string.h>

int main() {
    char path[105], ans[105];
    scanf ("%s", path);    
    int i = 0, flag = 0;
    while (path[i]) {
        if (path[i] == '.') {
            int cnt = 1;
            while (path[++i] == '.') cnt++;
            if (cnt == 2) {
                ans[flag++] = '.';
                ans[flag++] = '.';
            }
        } else if (path[i] == '\\' || path[i] == '/') {
            while (path[i] == '\\' || path[i] == '/') i++;
            ans[flag++] = '/';
        } else {
            ans[flag++] = path[i++];
        }
    }
    printf ("%s", ans);
    return 0;
}
