#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

// �����ߴ� �ͺ��� �ǰ� ���� �ɸ� ����.
// ó������ ������ �޾Ƽ� ���Ʈ������ �����غ��� ������ ������ �ʹ� ���������ٴ°� �˰� ����
// ��Ʈ��ŷ���� ��ȸ �� ó������ A��� ��� ���� ��, �� ��쿡 ���� B,C,~ ��⸦ �����Ϸ��� ������
// ����� ���� ���� ��� ���� ��ü�� ��ƴ�.
// �׷��� �ѹ��� �����ϴ� ���� �ƴ� �� ��� ������� �������� ���� ��/��/�и� �����ϴ� ��Ʈ��ŷ ������� �ذ�
// ������� �̷��� �׳� ��� Ǫ�°���;

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

// ó������ A�� ��� ���, B�� ��� ����� �� ť�� ä���������µ� �̰� �Ұ���
// ������ �� ��� ���� ���� ���� ä���־�� ��.
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