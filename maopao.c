#include <stdio.h>
#define max_n 1000

int num[max_n + 5];

int main() {
    int n;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &num[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (num[j] > num[j + 1]) {
                int temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        i && printf (" ");
        printf ("%d", num[i]);
    } 
    return 0;
}
