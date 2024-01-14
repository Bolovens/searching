#include <stdio.h>

int main(int argc, char *argv[]) {
    int length;
    scanf("%d", &length);
    getchar();

    int array[length];
    int check[2] = {0};
    for (int i = 0; i < length; i++) {
        scanf("%d", &array[i]);
        check[array[i]]++;
    }

    if (!check[1]) {
        printf("easy\n");
    } else {
        printf("not easy\n");
    }

    return 0;
}