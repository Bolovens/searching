#include <stdio.h>

int main(int argc, char *argv[]) {
    int tc;
    scanf("%d", &tc);
    getchar();

    for (int i = 1; i <= tc; i++) {
        int length, minimum, count = 0;
        scanf("%d %d", &length, &minimum);
        getchar();

        int array[length];
        for (int j = 0; j < length; j++) {
            scanf("%d", &array[j]);
            getchar();

            if (array[j] >= minimum) {
                count++;
            }
        }

        printf("Case #%d: %d\n", i, count);
    }
    
    return 0;
}