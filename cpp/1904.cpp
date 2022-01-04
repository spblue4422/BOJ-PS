#include <algorithm>
#include <iostream>
#include <stdio.h>

long long arr[2000000];

int main() {
    int n;
    scanf("%d", &n);

    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;

    if (n > 2) {
        for (int i = 1; i < n - 1; i++) {
            arr[i + 2] = (arr[i] % 15746) + (arr[i + 1] % 15746);
        }
    }

    printf("%lld", arr[n] % 15746);

    return 0;
}

// N의 범위가 1000000까지이기 때문에 자료형을 long long으로 잡아도 범위를
// 벗어난다. 그래서 배열에는 15746으로 나눈 나머지를 계속해서 넣어줘야한다.