#include <stdio.h>

void call(int array[], int length);
void divide(int array[], int left, int right);
void merge(int array[], int left, int mid, int right);

void call(int array[], int length) {
    divide(array, 0, length - 1);
}

void divide(int array[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        divide(array, left, mid);
        divide(array, mid + 1, right);

        merge(array, left, mid, right);
    }
}

void merge(int array[], int left, int mid, int right) {
    int leftLength = mid - left + 1;
    int rightLength = right - mid;

    int leftTemp[leftLength];
    int rightTemp[rightLength];

    int i, j, k;
    for (i = 0; i < leftLength; i++) {
        leftTemp[i] = array[i + left];
    }

    for (i = 0; i < rightLength; i++) {
        rightTemp[i] = array[i + mid + 1];
    }

    for (i = 0, j = 0, k = left; k <= right; k++) {
        if ((i < leftLength) &&  (j >= rightLength || leftTemp[i] < rightTemp[j])) {
            array[k] = leftTemp[i];
            i++;
        } else {
            array[k] = rightTemp[j];
            j++;
        }
    }
}

int main(int argc, char *argv[]) {
    int length, test;
    scanf("%d %d", &length, &test);

    int array[length];
    int result[1000] = {0};
    for (int i = 0; i < length; i++) {
        scanf("%d", &array[i]);
        getchar();
        result[array[i]]++;

    }

    call(array, length);

    int check[test];
    for (int i = 0; i < test; i++) {
        scanf("%d", &check[i]);
        getchar();
        result[check[i]] = 0;
    }

    int max = -1;
    for (int i = array[0]; i <= array[length - 1]; i++) {
        if (result[i] > 0) {
            if (max < i) {
                max = i;
            }
        }
    }

    printf("Maximum number is %d\n", max);
    
    return 0;
}