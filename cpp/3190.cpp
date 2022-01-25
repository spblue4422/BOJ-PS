#include <iostream>
#include <list>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int board[102][102] = {0}; // 전체 판
int sec[102] = {0};        //방향 전환 시간 배열
char dir[102] = {0};       // 좌회전,우회전 배열

void changeDir(char *, char); //방향전환함수

int main() {
    int N, k, l = 0, s = 0, tmp = 0;
    int m, n, flg = 1;
    char g = 'R';
    // list에 집어넣을 좌표 배열
    int *arr = new int[2]{1, 1};

    list<int *> snake;
    list<int *>::iterator iter;

    scanf("%d %d", &N, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &m, &n);
        board[m][n] = 2; //사과 위치
    }
    scanf("%d", &l);
    for (int i = 0; i < l; i++) {
        scanf("%d %c", &sec[i], &dir[i]);
    }

    //보드 초기화 - 벽(-1)세워주기
    for (int i = 0; i < N + 2; i++) {
        for (int j = 0; j < N + 2; j++) {
            if (i == 0 || i == N + 1 || j == 0 || j == N + 1)
                board[i][j] = -1;
        }
    }

    m = 1;
    n = 1;
    board[m][n] = 1; //시작위치
    snake.push_back(arr);
    iter = snake.begin();

    while (flg) {
        // 배열에 담긴 시간초가 되면 방향전환
        if (sec[tmp] == s) {
            changeDir(&g, dir[tmp]);
            tmp++;
        }
        if (g == 'U') // UP
            m--;
        else if (g == 'R') // RIGHT
            n++;
        else if (g == 'D') // DOWN
            m++;
        else // LEFT
            n--;

        // list에 넣을 좌표(m,n) 배열
        int *arr = new int[2]{m, n};
        snake.push_front(arr);
        iter = snake.begin();

        // 머리가 있는 좌표(m, n)의 값이 0이라면(빈공간)
        if (board[m][n] == 0) {
            board[m][n] = 1;
            board[snake.back()[0]][snake.back()[1]] =
                0; // 꼬리가 있던 좌표 1에서 0으로
            snake.pop_back();
        } else if (board[m][n] == 2) { //사과(2)가 있다면
            board[m][n] = 1;           //꼬리는 그대로
        } else {     //벽(-1)에 부딪혔거나 몸통(1)에 부딪혔다면
            flg = 0; // 0이되면 while문이 끝남.
        }
        s++;
    }
    printf("%d", s);
    return 0;
}

void changeDir(char *ptr, char turn) {
    switch (*ptr) {
    case 'U':
        if (turn == 'D')
            *ptr = 'R';
        else
            *ptr = 'L';
        break;
    case 'R':
        if (turn == 'D')
            *ptr = 'D';
        else
            *ptr = 'U';
        break;
    case 'D':
        if (turn == 'D')
            *ptr = 'L';
        else
            *ptr = 'R';
        break;
    case 'L':
        if (turn == 'D')
            *ptr = 'U';
        else
            *ptr = 'D';
        break;
    default:
        break;
    }
}