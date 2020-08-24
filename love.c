#include <stdio.h>
#include <string.h>

const int MAX_LENGTH = 256;

char* get_letter(void) {
    static char letter[1000000];
    letter[999999] = ' ';
    char *p = letter;
    int size = MAX_LENGTH;
    while (feof(stdin) == 0) {
        if (size == 0) {
            break;
        }
        fgets(p, size + 1, stdin);
        while (*p != '\0') {
            p++;
            size--;
        }
    }
    return letter;
}

int main() {
    char *str = get_letter();
    char str_tmp[strlen(str) + 1];
    strcpy(str_tmp, str);
    char delim[10] = {' ', '\n', '\t', '\r', '\"', '\'', ',', '.'};
    char *token = strtok(str_tmp, delim);
    // 在此处添加你的代码
    int cnt = 0;
    while (token != NULL) {
        puts(token);
        if (strcmp(token, "love") == 0) {
            cnt++;
        }
        token = strtok(NULL, delim);
    }
    printf ("%d\n", cnt);
    puts(str);
    return 0;
}

#undef MAX_LENGTH
