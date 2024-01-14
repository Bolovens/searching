#include <stdio.h>

void divide(int array[], int left, int right);
void merge(int array[], int left, int mid, int right);

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
        if ((i < leftLength) && ((j >= rightLength) || (leftTemp[i] < rightTemp[j]))) {
            array[k] = leftTemp[i];
            i++;
        } else {
            array[k] = rightTemp[j];
            j++;
        }
    }
}

int search(int array[], int target, int left, int right) {
    if (left > right) return -1;

    int mid = left + (right - left) / 2;

    if (array[mid] == target) return mid;
    else if (array[mid] > target) return search(array, target, left, mid - 1);
    else if (array[mid] < target) return search(array, target, mid + 1, right);
}

int main(int argc, char *argv[]) {
    int tc;
    scanf("%d", &tc);
    getchar();

    for (int i = 1; i <= tc; i++) {
        int length;
        scanf("%d", &length);
        getchar();

        int array[length];
        for (int j = 0; j < length; j++) {
            scanf("%d", &array[j]);
            getchar();
        }

        int mmr;
        scanf("%d", &mmr);
        getchar();

        divide(array, 0, length - 1);

        int index = search(array, mmr, 0, length - 1);

        if (index == length - 1) {
            printf("CASE #%d: %d %d\n", i, array[index - 1], array[index]);
        } else if (index >= 0) {
            printf("CASE #%d: %d %d\n", i, array[index], array[index + 1]);
        } else if (index == -1) {
            printf("CASE #%d: %d %d\n", i, index, index);
        }
    }
    
    return 0;
}