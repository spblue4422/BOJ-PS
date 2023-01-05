#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

int beforeSwapCheck(int x, int y);
int afterSwapCheck(int x, int y, int flag);
int getMax(int a, int b, int c, int d);

char arr[50][50];
int N;

int main() {
    int M = 0, tmp1, tmp2, tmp3;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%s", arr[i]);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tmp1 = beforeSwapCheck(i, j);
            tmp2 = afterSwapCheck(i, j, 1);
            tmp3 = afterSwapCheck(i, j, 0);
            M = getMax(M, tmp1, tmp2, tmp3);
        }
    }

    printf("%d", M);

    return 0;
}

int beforeSwapCheck(int x, int y) {
    int cnt = 1, M = 0;
    for (int i = x; i < N - 1; i++) {
        if (arr[i][y] == arr[i + 1][y]) {
            cnt++;
        } else {
            break;
        }
    }
    M = max(cnt, M);
    cnt = 1;
    for (int j = y; j < N - 1; j++) {
        if (arr[x][j] == arr[x][j + 1]) {
            cnt++;
        } else {
            break;
        }
    }
    M = max(cnt, M);

    return M;
}

int afterSwapCheck(int x, int y, int flag) {
    int cnt = 1, M = 0;

    if (flag) { //가로로 바꾼 경우
        // 1번 사탕 기준 열
        for (int i = x; i > 0; i--) {
            if (arr[x][y] == arr[i - 1][y + 1]) {
                cnt++;
            } else {
                break;
            }
        }
        for (int i = x; i < N - 1; i++) {
            if (arr[x][y] == arr[i + 1][y + 1]) {
                cnt++;
            } else {
                break;
            }
        }
        M = max(cnt, M);
        cnt = 1;
        // 2번 사탕 기준 열
        for (int i = x; i > 0; i--) {
            if (arr[x][y + 1] == arr[i - 1][y]) {
                cnt++;
            } else {
                break;
            }
        }
        for (int i = x; i < N - 1; i++) {
            if (arr[x][y + 1] == arr[i + 1][y]) {
                cnt++;
            } else {
                break;
            }
        }
        M = max(cnt, M);
        cnt = 1;
        //마지막 가로 확인
        for (int j = y; j > 0; j--) {
            if (arr[x][y + 1] == arr[x][j - 1]) {
                cnt++;
            } else {
                break;
            }
        }
        M = max(cnt, M);
        cnt = 1;
        for (int j = y; j < N - 2; j++) {
            if (arr[x][y] == arr[x][j + 2]) {
                cnt++;
            } else {
                break;
            }
        }
        M = max(cnt, M);
    } else { //세로로 바꾼 경우
        // 1번 사탕 기준 행
        for (int j = y; j > 0; j--) {
            if (arr[x][y] == arr[x + 1][j - 1]) {
                cnt++;
            } else {
                break;
            }
        }
        for (int j = y; j < N - 1; j++) {
            if (arr[x][y] == arr[x + 1][j + 1]) {
                cnt++;
            } else {
                break;
            }
        }
        M = max(cnt, M);
        cnt = 1;
        // 2번 사탕 기준 행
        for (int j = y; j > 0; j--) {
            if (arr[x + 1][y] == arr[x][j - 1]) {
                cnt++;
            } else {
                break;
            }
        }
        for (int j = y; j < N - 1; j++) {
            if (arr[x + 1][y] == arr[x][j + 1]) {
                cnt++;
            } else {
                break;
            }
        }
        M = max(cnt, M);
        cnt = 1;
        //마지막 세로 확인
        for (int i = x; i > 0; i--) {
            if (arr[x + 1][y] == arr[i - 1][y]) {
                cnt++;
            } else {
                break;
            }
        }
        M = max(cnt, M);
        cnt = 1;
        for (int i = x; i < N - 2; i++) {
            if (arr[x][y] == arr[i + 2][y]) {
                cnt++;
            } else {
                break;
            }
        }
        M = max(cnt, M);
    }
    return M;
}

int getMax(int a, int b, int c, int d) {
    int M;
    M = max(a, b);
    M = max(M, c);
    M = max(M, d);
    return M;
}