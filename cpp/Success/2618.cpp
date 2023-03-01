#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

// 플레급 문제 오랜만에 풀었는데 진짜 어렵고 상상도 못한 풀이 방식이었다.
// 처음에는 점화식으로 어찌어찌 답을 구했는데 해당 방식으로 했을 때, 경찰차 순서를 찍는 방법을 도저히 모르겠어서
// 답을 보고 재귀 방식으로 선회
// 답을 보고 좀 당황했던게 답을 구하는 과정에서 경찰차 순서를 어떻게 찍을지 고민이었는데, 아예 dp 배열 순회를
// 다시 해버릴 줄은 몰랐다...
// 아무튼 풀고 나서도 어지러운 문제, 매우매우 어려운 문제인것 같다. 내 한계는 실버가 아닐까?
// 풀이 방식의 기본 골자는 각 경찰차에서 다음 지점까지의 거리를 계산해서 비교하는데, 이 비교가 재귀를 통해 마지막 사건쯤에서부터 시작된다는 것.
// 앞에서부터 비교하려고 했을땐 어찌어찌 점화식까진 만들었는데 진짜 골아파 죽는줄 알았다.
// 암튼 존나 골때리는문제 엿음 ㅇ;

// 처음에 답을 보고 든 생각
// dp[i][j]에서 배열에 들어가는 값은 1번 경찰차가 i번째, 2번 경찰차가 j번째 사건까지 해결했을 때까지의 거리
// 답에서의 dp
// dp[i][j]에서 배열에 들어가는 값은 1번 경찰차가 i번째, 2번 경찰차가 j번째 사건까지 해결했을 때, 남은 모든 사건을 해결할 수 있는 최소 거리

// 두 번째
int getMin(int a, int b);
int getDistance(int x1, int y1, int x2, int y2);
int getTotalDistance(int pos1, int pos2, int next_crime);
void printPolice(int pos1, int pos2, int next_crime);

struct crime {
    int x, y;
};

vector<crime> cVec;
int dpArr[1001][1001];
int N, C;

int main() {
    int tmpx, tmpy;

    scanf("%d %d", &N, &C);

    for (int i = 0; i < C + 1; i++) {
        for (int j = 0; j < C + 1; j++) {
            dpArr[i][j] = -1;
        }
    }

    for (int i = 0; i < C; i++) {
        scanf("%d %d", &tmpx, &tmpy);
        cVec.push_back({tmpx, tmpy});
    }

    printf("%d\n", getTotalDistance(0, 0, 1));

    printPolice(0, 0, 1);

    return 0;
}

int getMin(int a, int b) {
    if (a >= b) {
        return b;
    } else {
        return a;
    }
}

int getDistance(int x1, int y1, int x2, int y2) { return abs(x1 - x2) + abs(y1 - y2); }

int getTotalDistance(int pos1, int pos2, int next_crime) {
    int tx = cVec[next_crime - 1].x, ty = cVec[next_crime - 1].y;

    if (next_crime > C) {
        dpArr[pos1][pos2] = 0;
        return dpArr[pos1][pos2];
    }
    if (dpArr[pos1][pos2] != -1) {
        return dpArr[pos1][pos2];
    }

    int dis1 = pos1 == 0 ? getDistance(1, 1, tx, ty) : getDistance(cVec[pos1 - 1].x, cVec[pos1 - 1].y, tx, ty);
    int dis2 = pos2 == 0 ? getDistance(N, N, tx, ty) : getDistance(cVec[pos2 - 1].x, cVec[pos2 - 1].y, tx, ty);

    dpArr[pos1][pos2] = getMin(dis1 + getTotalDistance(next_crime, pos2, next_crime + 1), dis2 + getTotalDistance(pos1, next_crime, next_crime + 1));

    return dpArr[pos1][pos2];
}

void printPolice(int pos1, int pos2, int next_crime) {
    int tx = cVec[next_crime - 1].x, ty = cVec[next_crime - 1].y;

    if (next_crime > C)
        return;

    int dis1 = pos1 == 0 ? getDistance(1, 1, tx, ty) : getDistance(cVec[pos1 - 1].x, cVec[pos1 - 1].y, tx, ty);
    int dis2 = pos2 == 0 ? getDistance(N, N, tx, ty) : getDistance(cVec[pos2 - 1].x, cVec[pos2 - 1].y, tx, ty);

    if (dis1 + dpArr[next_crime][pos2] <= dis2 + dpArr[pos1][next_crime]) {
        printf("%d\n", 1);
        printPolice(next_crime, pos2, next_crime + 1);
    } else {
        printf("%d\n", 2);
        printPolice(pos1, next_crime, next_crime + 1);
    }

    return;
}

/*
// 첫 번째
int getMin(int a, int b);

int cArr[1001][2];
int dpArr[1001][1001];

int main() {
    int m = 100000, N = 0, C = 0;

    scanf("%d %d", &N, &C);

    for (int i = 1; i < C + 1; i++) {
        scanf("%d %d", &cArr[i][0], &cArr[i][1]);
    }

    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            dpArr[i][j] = -1;
        }
    }

    dpArr[1][0] = abs(cArr[1][0] - 1) + abs(cArr[1][1] - 1);
    dpArr[0][1] = abs(cArr[1][0] - N) + abs(cArr[1][1] - N);

    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            if (i > j) {
                if (abs(i - j) != 1) {
                    dpArr[i][j] = dpArr[i - 1][j] + abs(cArr[i][0] - cArr[i - 1][0]) + abs(cArr[i][1] - cArr[i - 1][1]);
                } else {
                    for (int k = 0; k < j; k++) {
                        if (k == 0) {
                            dpArr[i][j] = dpArr[k][j] + abs(cArr[i][0] - 1) + abs(cArr[i][1] - 1);
                        } else {
                            dpArr[i][j] = getMin(dpArr[i][j], dpArr[k][j] + abs(cArr[i][0] - cArr[k][0]) + abs(cArr[i][1] - cArr[k][1]));
                        }
                    }
                }
            } else if (i < j) {
                if (abs(i - j) != 1) {
                    dpArr[i][j] = dpArr[i][j - 1] + abs(cArr[j][0] - cArr[j - 1][0]) + abs(cArr[j][1] - cArr[j - 1][1]);
                } else {
                    for (int k = 0; k < i; k++) {
                        if (k == 0) {
                            dpArr[i][j] = dpArr[i][k] + abs(cArr[j][0] - N) + abs(cArr[j][1] - N);
                        } else {
                            dpArr[i][j] = getMin(dpArr[i][j], dpArr[i][k] + abs(cArr[j][0] - cArr[k][0]) + abs(cArr[j][1] - cArr[k][1]));
                        }
                    }
                }
            } else {
                continue;
            }
            if (i == C || j == C) {
                m = getMin(m, dpArr[i][j]);
            }
        }
    }

    for (int i = 0; i < C + 1; i++) {
        for (int j = 0; j < C + 1; j++) {
            printf("%d ", dpArr[i][j]);
        }
        printf("\n");
    }

    printf("%d", m);

    return 0;
}

int getMin(int a, int b) {
    if (a >= b) {
        return b;
    } else {
        return a;
    }
}*/