#include <stdio.h>
#include <stdlib.h>

typedef struct Data {
    long long int id;
    char name[21];
} Student;

Student students[101];

int main(int argc, char *argv[]) {
    FILE *ptr = fopen("testdata.in", "r");

    int length;
    fscanf(ptr, "%d", &length);

    for (int i = 0; i < length; i++) {
        fscanf(ptr, "%lld %s", &students[i].id, students[i].name);
    }

    int find;
    fscanf(ptr, "%d", &find);

    for (int i = 1; i <= find; i++) {
        long long int target;
        fscanf(ptr, "%lld", &target);

        int id = -1;
        for (int j = 0; j < length; j++) {
            if (students[j].id == target) {
                id = j;
                break;
            }
        }
        printf("Case #%d: %s\n", i, (id != -1) ? students[id].name : "N/A");
    }

    fclose(ptr);

    return 0;
}