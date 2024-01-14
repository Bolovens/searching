#include <stdio.h>

void divide(long long int array[], int left, int right);
void merge(long long int array[], int left, int mid, int right);

void divide(long long int array[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        divide(array, left, mid);
        divide(array, mid + 1, right);

        merge(array, left, mid, right);
    }
}

void merge(long long int array[], int left, int mid, int right) {
    int leftLength = mid - left + 1;
    int rightLength = right - mid;

    long long int leftTemp[leftLength];
    long long int rightTemp[rightLength];

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

int main(int argc, char *argv[]) {
    int length;
    scanf("%d", &length);
    getchar();

    long long int array[length];
    for (int i = 0; i < length; i++) {
        scanf("%lld", &array[i]);
        getchar();
    }

    long long int power;
    scanf("%lld", &power);

    divide(array, 0, length - 1);

    int count = 0;
    for (int i = 0; i < length; i++) {
        if (power >= array[i]) {
            count++;
            power -= array[i];
        } else {
            break;
        }
    }

    printf("%d\n", count);

    return 0;
}