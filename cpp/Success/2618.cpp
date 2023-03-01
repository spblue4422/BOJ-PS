#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

// �÷��� ���� �������� Ǯ���µ� ��¥ ��ư� ��� ���� Ǯ�� ����̾���.
// ó������ ��ȭ������ ������� ���� ���ߴµ� �ش� ������� ���� ��, ������ ������ ��� ����� ������ �𸣰ھ
// ���� ���� ��� ������� ��ȸ
// ���� ���� �� ��Ȳ�ߴ��� ���� ���ϴ� �������� ������ ������ ��� ������ ����̾��µ�, �ƿ� dp �迭 ��ȸ��
// �ٽ� �ع��� ���� ������...
// �ƹ�ư Ǯ�� ������ �������� ����, �ſ�ſ� ����� �����ΰ� ����. �� �Ѱ�� �ǹ��� �ƴұ�?
// Ǯ�� ����� �⺻ ���ڴ� �� ���������� ���� ���������� �Ÿ��� ����ؼ� ���ϴµ�, �� �񱳰� ��͸� ���� ������ ����뿡������ ���۵ȴٴ� ��.
// �տ������� ���Ϸ��� ������ ������� ��ȭ�ı��� ������µ� ��¥ ����� �״��� �˾Ҵ�.
// ��ư ���� �񶧸��¹��� ���� ��;

// ó���� ���� ���� �� ����
// dp[i][j]���� �迭�� ���� ���� 1�� �������� i��°, 2�� �������� j��° ��Ǳ��� �ذ����� �������� �Ÿ�
// �信���� dp
// dp[i][j]���� �迭�� ���� ���� 1�� �������� i��°, 2�� �������� j��° ��Ǳ��� �ذ����� ��, ���� ��� ����� �ذ��� �� �ִ� �ּ� �Ÿ�

// �� ��°
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
// ù ��°
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