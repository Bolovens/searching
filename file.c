#include <stdio.h>
#include <string.h>

typedef struct Dictionary {
    char abbr[55];
    char word[55];
} Dict;

Dict list[101];

int main(int argc, char *argv) {
    FILE *ptr = fopen("testdata.in", "r");

    int length;
    fscanf(ptr, "%d\n", &length);

    for (int i = 0; i < length; i++) {
        fscanf(ptr, "%[^#]#%[^\n]\n", list[i].abbr, list[i].word);
    }

    int tc;
    fscanf(ptr, "%d\n", &tc);

    for (int i = 1; i <= tc; i++) {
        char string[105];
        fscanf(ptr, "%[^\n]\n", string);

        char *token;
        token = strtok(string, " ");

        printf("Case #%d:\n", i);
        while (token != NULL) {
            int check = 0;

            for (int j = 0; j < length; j++) {
                if (!strcmp(token, list[j].abbr)) {
                    printf("%s", list[j].word);
                    check = 1;
                    break;
                }
            }

            if (!check) {
                printf("%s", token);
            }

            token = strtok(NULL, " ");

            if (token != NULL) {
                printf("%c", ' ');
            } 
        }

        printf("\n");
    }
    
    fclose(ptr);

    return 0;
}