#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// 어려운 문제엿다..
int dfs(int cur, int sts);

int cities[16][16] = {0};
// dp 배열의 의미 - 현재 i번째 도시, j는 방문한 도시를 알려줌. (i 포함)
// 이때, dp의 의미는 남아있는 도시들을 모두 순회하고 0으로 돌아갔을때의 최솟값을 의미
// 0번 도시에서 ~ i번 도시까지의 최솟값이 아님!
// 즉 모든 도시를 순회하고 갔을 때, 전체 합의 최솟값은 dp[0][1] 에 담긴다.
int dp[16][1 << 16] = {0}; // 1 << 16 = 10000000000000000 (2^16)
int N;

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &cities[i][j]);
        }
    }

    // dp 배열 초기화
    // 값을 -1로 하면 시간통과
    // 값을 1000000000 로 하면 시간초과...
    // 55%에서 걸리는걸로 보아 testcase에서 뭔가 걸리는게 있는것 같음...
    fill(&dp[0][0], &dp[0][0] + 1048576, -1);

    printf("%d\n", dfs(0, 1));

    return 0;
}

int dfs(int cur, int sts) {
    // 모든 도시를 방문한 상태 - 출발 도시로 돌아가줘야함.
    if ((sts & ((1 << N) - 1)) == ((1 << N) - 1)) {
        if (cities[cur][0] != 0) {
            return cities[cur][0];
        } else {
            // 온전한 순회를 할수 없는 상태
            return 1000000000;
        }
    }

    // 초기에 배열에 저장해놓은 값이 아니라면 이미 계산해놓은 최솟값이므로 그대로 리턴
    // 지나온 경로가 다를수도 있는데 왜 되는가?
    // 경로가 다르더라도 방문한 도시들의 목록은 같기 때문에, 차후에 방문할 도시의 목록도 같고,
    // 현재 위치한 cur도 같기 때문이다.
    if (dp[cur][sts] != -1) {
        return dp[cur][sts];
    }
    dp[cur][sts] = 1000000000;

    for (int i = 0; i < N; i++) {
        // 이미 방문한 도시인 경우
        if ((sts & (1 << i)) == (1 << i)) {
            continue;
        }
        // 방문한 도시는 아니지만 현재 도시에서 가는 길이 없는 경우
        // cities[cur][cur]의 경우도 걸러짐.
        if (cities[cur][i] == 0) {
            continue;
        }

        dp[cur][sts] = min(dp[cur][sts], cities[cur][i] + dfs(i, sts | (1 << i)));
    }

    return dp[cur][sts];
}