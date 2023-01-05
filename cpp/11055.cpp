#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

long long dp[1001] = {0};

int main() {
    int n = 0;
    long long M = 0, tmp = 0;
    int arr[1001];

    // 입력
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        dp[i] = arr[i];
    }

    // dp배열 만들기
    for (int i = 1; i <= n; i++) {
        tmp = 0;
        // 앞부분 확인해서 더 작은 수면 뽑아두고 그중 최댓값을 dp배열에 집어넣는다.
        // dp배열 자체가 앞쪽의 증가 수열 값이기 때문에 그냥 더하면 됨.
        for (int j = i - 1; j > 0; j--) {
            if (arr[j] < arr[i]) {
                tmp = max(tmp, dp[j]);
            }
        }
        dp[i] += tmp;
        M = max(M, dp[i]);
    }

    printf("%lld", M);

    return 0;
}