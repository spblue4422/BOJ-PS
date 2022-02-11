#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

long long arr[100000];

//정렬 후 양쪽에서 하나씩 줄여가면 쉽게 풀림.
int main() {
    int N = 0, ptr1, ptr2, min = 0, max = 0;
    long long sum = 0, tmp = 2000000001;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%lld", &arr[i]);
    }
    sort(arr, arr + N);
    ptr1 = 0;
    ptr2 = N - 1;
    while (ptr1 != ptr2) {
        sum = arr[ptr1] + arr[ptr2];
        if (sum == 0) {
            min = ptr1;
            max = ptr2;
            break;
        } else {
            if (abs(sum) < tmp) {
                tmp = abs(sum);
                min = ptr1;
                max = ptr2;
            }
            if (sum > 0) {
                ptr2--;
            } else if (sum < 0) {
                ptr1++;
            }
        }
    }

    printf("%lld %lld", arr[min], arr[max]);

    return 0;
}