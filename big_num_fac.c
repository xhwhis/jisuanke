1#include <stdio.h>
#define max_n 100000

int f[max_n + 5] = {1, 1};

int main() {
    int n;
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= f[0]; j++) {
            f[j] *= i;
        }
        for (int k = 1; k <= f[0]; k++) {
            if (f[k] < 10) continue;
            f[k + 1] += f[k] / 10;
            f[k] %= 10;
            f[0] += (k == f[0]);
        }
    }
    for (int i = f[0]; i > 0; i--) {
        printf ("%d", f[i]);
    }
    return 0;
}
