#include <stdio.h>
#define max_n 1000

int num[max_n + 5];

int main() {
    int n;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &num[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (num[min] > num[j]) min = j;
        }
        if (min - i) {
            int temp = num[min];
            num[min] = num[i];
            num[i] = temp;
        }
    }
    for (int i = 0; i < n; i++) {
        i && printf (" ");
        printf ("%d", num[i]);
    }
    return 0;
}
