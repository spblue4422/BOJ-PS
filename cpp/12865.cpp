#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;

int wv[105][2] = {0};
int dp[105][100010] = {0};

int main() {
    int n = 0;
    int k = 0;
    int tmp = 0;
    int val = 0;
    scanf("%d %d", &n, &k);

    for (int i = 1; i < n + 1; i++) {
        scanf("%d %d", &wv[i][0], &wv[i][1]);
    }

    // dp 배열 만들기, dp[n][k]는 n개의 물건으로 최대 무게 k를 맞출때, 최대 가치
    for (int i = 1; i < n + 1; i++) {
        tmp = wv[i][0];
        val = wv[i][1];
        for (int j = 1; j < k + 1; j++) {
            if (tmp > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - tmp] + val);
            }
        }
    }
    printf("%d", dp[n][k]);

    return 0;
}