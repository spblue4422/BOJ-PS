#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int cnt = 0, n = 0;
void tracking(int board[15][15], int k);
int checkQueen(int board[15][15], int k, int l);

int main() {
    int board[15][15] = {0};

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        board[0][i] = 1;
        tracking(board, 1);
        board[0][i] = 0;
    }

    printf("%d", cnt);

    return 0;
}

void tracking(int board[15][15], int k) {
    //성공한 케이스
    if (k == n) {
        cnt++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (checkQueen(board, k, i) == -1) {
            continue;
        }
        board[k][i] = 1;
        tracking(board, k + 1);
        //보드 다시 0으로
        board[k][i] = 0;
    }
}

int checkQueen(int board[15][15], int k, int l) { // board[k][l]
    for (int i = 0; i < k; i++) {
        int tmp = k - i;
        if (board[i][l] == 1) {
            //세로줄에 겹치는 친구가 있을 때
            return -1;
        } else if ((l - tmp >= 0 && board[i][l - tmp] == 1) ||
                   (l + tmp < n && board[i][l + tmp] == 1)) {
            //대각선 경로상에 겹치는 친구가 있을 때
            return -1;
        }
    }
    return 0;
}