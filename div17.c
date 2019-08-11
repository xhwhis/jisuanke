#include <stdio.h>
#include <inttypes.h>

int main() {
    int n;
    int digit;
    scanf ("%d", &n);
    while (n > 0) {
        n /= 10;
        digit = n % 10;
        n -= digit * 5;
    }
    if (n % 17 == 0) printf ("YES");
    else printf ("NO");
    return 0;
}
