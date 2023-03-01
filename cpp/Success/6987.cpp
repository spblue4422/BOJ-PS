#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

// 생각했던 것보다 되게 오래 걸린 문제.
// 처음에는 조건을 달아서 브루트포스로 검증해볼까 했지만 조건이 너무 복잡해진다는걸 알고 포기
// 백트래킹으로 선회 후 처음에는 A경기 모두 세팅 후, 각 경우에 따라 B,C,~ 경기를 세팅하려고 했지만
// 경우의 수가 많아 모두 세팅 자체가 어렵다.
// 그래서 한번에 세팅하는 것이 아닌 한 경기 결과마다 배정받은 팀의 승/무/패를 차감하는 백트래킹 방식으로 해결
// 사람들은 이런걸 그냥 어떻게 푸는거지;

void fill(int trackArr[6][3], int gCnt);

vector<pair<int, int>> game;
int board[4][18] = {0};
int result[4] = {0};
int flag = 0;

int main() {
    int trackArr[6][3] = {0};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 18; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            game.push_back({i, j});
        }
    }

    for (int i = 0; i < 4; i++) {
        flag = 0;
        for (int j = 0; j < 18; j++) {
            trackArr[j / 3][j % 3] = board[i][j];
        }
        fill(trackArr, 0);

        result[i] = flag;
    }

    for (int i = 0; i < 4; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}

void fill(int trackArr[6][3], int gCnt) {
    if (gCnt == 15) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                if (trackArr[i][j] != 0) {
                    return;
                }
            }
        }

        flag = 1;
        return;
    }

    int t = game[gCnt].first;
    int et = game[gCnt].second;

    if (!flag) {
        if (trackArr[t][0] != 0 && trackArr[et][2] != 0) {
            trackArr[t][0]--;
            trackArr[et][2]--;
            fill(trackArr, gCnt + 1);
            trackArr[t][0]++;
            trackArr[et][2]++;
        }

        if (trackArr[t][1] != 0 && trackArr[et][1] != 0) {
            trackArr[t][1]--;
            trackArr[et][1]--;
            fill(trackArr, gCnt + 1);
            trackArr[t][1]++;
            trackArr[et][1]++;
        }

        if (trackArr[t][2] != 0 && trackArr[et][0] != 0) {
            trackArr[t][2]--;
            trackArr[et][0]--;
            fill(trackArr, gCnt + 1);
            trackArr[t][2]++;
            trackArr[et][0]++;
        }
    }

    return;
}

// 처음에는 A의 경기 결과, B의 경기 결과를 한 큐에 채워넣을랬는데 이게 불가능
// 각각의 한 경기 씩을 따로 보고 채워넣어야 함.
/*
int fill(int arr[6][6], int cnt, int num) {
    if(cnt == 6) {
        return 1;
    }

    int win = board[num][cnt*3];
    int draw = board[num][cnt*3 + 1];
    int lose = board[num][cnt*3 + 2];

    for(int j = 0; j < cnt; j++) {
        if(arr[cnt][j] == 1) {
            win--;
        } else if(arr[cnt][j] == 0) {
            draw--;
        } eles {
            lose--;
        }
    }


    return fill(arr, cnt + 1);
}*/