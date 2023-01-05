#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void shark(int idx, int idy, int sum);
void fishSwap();

struct status {
    int num;
    int direction;
};

struct way {
    int x;
    int y;
};

int Max = 0;
status board[4][4];
way darr[8] = {{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};

int main() {
    int n = 0, d = 0;
    //입력
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d %d", &n, &d);
            board[i][j] = {n, d};
        }
    }

    shark(0, 0, 0);

    printf("%d", Max);
    return 0;
}

void shark(int idx, int idy, int sum) {
    int i = idx, j = idy, dir = board[idx][idy].direction - 1, tmp = board[idx][idy].num;
    status backup[4][4];

    way w = darr[dir];
    //물고기 포식 후 증가.
    sum += tmp;
    copy(&board[0][0], &board[0][0] + 16, &backup[0][0]);

    //상어가 있는 공간
    board[idx][idy].num = 100;
    board[idx][idy].direction = 0;
    fishSwap();

    //방향에 먹을 수 있는 물고기가 없는 경우 shark 더이상 실행 x
    while (i + w.x >= 0 && i + w.x <= 3 && j + w.y >= 0 && j + w.y <= 3) {
        i += w.x;
        j += w.y;
        // printf("%d %d\n", i, j);
        if (board[i][j].num != 0 && board[i][j].direction != 0) {
            //상어가 이동하기 때문에, 빈공간으로 만들어둬야함.
            board[idx][idy].num = 0;
            shark(i, j, sum);
        }
    }
    // 복원 - 백업된 보드를 가져와야 하는게 맞는듯 ㅇㅇ;
    copy(&backup[0][0], &backup[0][0] + 16, &board[0][0]);

    Max = max(Max, sum);

    return;
}

void fishSwap() {
    int chk = 1, dir, flg = 0;
    way w;
    status tmp;

    while (chk < 17) {
        flg = 0;
        for (int i = 0; i < 4; i++) {
            if (flg)
                break;
            for (int j = 0; j < 4; j++) {
                if (board[i][j].num == chk) {
                    dir = board[i][j].direction - 1;
                    w = darr[dir];
                    //물고기 이동방향 정하기(범위 밖이거나, 상어가 있거나)
                    while (i + w.x < 0 || i + w.x > 3 || j + w.y < 0 || j + w.y > 3 || board[i + w.x][j + w.y].num == 100) {
                        dir = (dir + 1) % 8;
                        w = darr[dir];
                    }
                    board[i][j].direction = dir + 1;

                    //자리교체
                    tmp = board[i + w.x][j + w.y];
                    board[i + w.x][j + w.y] = board[i][j];
                    board[i][j] = tmp;

                    flg = 1;
                    break;
                }
            }
        }
        chk++;
    }
    return;
}