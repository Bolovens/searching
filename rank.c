#include <stdio.h>
#include <string.h>

typedef struct Report {
    char name[15];
    int score;
} Report;

Report list[1001];

void divide(Report list[], int left, int right);
void merge(Report list[], int left, int mid, int right);

void divide(Report list[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        divide(list, left, mid);
        divide(list, mid + 1, right);

        merge(list, left, mid, right);
    }
}

void merge(Report list[], int left, int mid, int right) {
    int leftLength = mid - left + 1;
    int rightLength = right - mid;

    Report leftTemp[leftLength];
    Report rightTemp[rightLength];

    int i, j, k;
    for (i = 0; i < leftLength; i++) {
        leftTemp[i] = list[i + left];
    }

    for (i = 0; i < rightLength; i++) {
        rightTemp[i] = list[i + mid + 1];
    }

    for (i = 0, j = 0, k = left; k <= right; k++) {
        if ((i < leftLength) && (j >= rightLength || leftTemp[i].score > rightTemp[j].score || ((leftTemp[i].score == rightTemp[j].score) && strcmp(leftTemp[i].name, rightTemp[j].name) < 0))) {
            list[k] = leftTemp[i];
            i++;
        } else {
            list[k] = rightTemp[j];
            j++;
        }
    }
}


int main(int argc, char *argv[]) {
    int tc;
    scanf("%d", &tc);
    getchar();

    for (int i = 1; i <= tc; i++) {
        int length;
        scanf("%d", &length);
        getchar();

        for (int j = 0; j < length; j++) {
            scanf("%[^#]#%d", list[j].name, &list[j].score);
            getchar();
        }

        divide(list, 0, length - 1);

        char name[15];
        scanf("%s", name);
        getchar();

        for (int j = 0; j < length; j++) {
            if (!strcmp(name, list[j].name)) {
                printf("Case #%d: %d\n", i, j + 1);
                break;
            }
        }
    } 

    return 0;
}