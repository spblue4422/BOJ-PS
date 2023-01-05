#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int app[101][2] = {0};
int dp[101][10000] = {0};

int main() {
    int N, M, size, cost, minCost = 100000;

    scanf("%d %d", &N, &M);

    // app 메모리 크기
    for (int i = 1; i <= N; i++) {
        scanf("%d", &app[i][0]);
    }
    // app 비활성화시 비용
    for (int i = 1; i <= N; i++) {
        scanf("%d", &app[i][1]);
    }

    // 배낭문제와 미묘하게 다름.
    // M을 열으로 dp배열을 만들지 못하는 이유: 최댓값이 천만이기 때문에 배열을 만들 경우 메모리 초과 발생
    // i개의 app을 종료했을 때, 발생하는 비용(j)으로 얻을 수 있는 메모리의 최댓값을 dp에 저장.
    for (int i = 1; i <= N; i++) {
        size = app[i][0];
        cost = app[i][1];
        // 배낭문제와의 차이점++ cost가 0일 수 있음
        for (int j = 0; j <= N * 100; j++) {
            if (cost > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j - cost] + size, dp[i - 1][j]);
            }
            // dp 배열을 만들면서 메모리 최댓값이 기준을 넘으면 j를 최솟값 비교.
            if (dp[i][j] >= M) {
                minCost = min(minCost, j);
            }
        }
    }

    printf("%d\n", minCost);

    return 0;
}