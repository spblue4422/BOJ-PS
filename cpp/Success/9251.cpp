#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

// LCS ���� ��� ���� ��.
// ���� �Ⱥ����� ���� ��Ǯ���� �� ���� ����
// ��� ��ȭ���� �� �������� ��Ȯ���� �𸣰���.
// ���� ���� �϶�, dp[i][j] = dp[i-1][j-1] + 1;
// �ٸ� ���� �϶�, dp[i][j] = getMax(dp[i-1][j], dp[i][j-1]);
// ���� ���� ǥ�� �׷����� ���ڿ��� ���غ��鼭�� ���� �� �̷� ǥ�� ������,
// �� �̷� ��ȭ���� �Ǵ��� �� �𸣰ڴ�... �׳� �𸣸� �ܿ�� Ǯ��� ���� ������?
// �������� string �����ϱ� scanf�� �� �Ǽ� ��Ȳ..
// �ƹ�ư ����� ������!

int getMax(int a, int b);

int board[1001][1001] = {0};

int main() {
    string str1, str2;

    cin >> str1;
    cin >> str2;

    for (int i = 0; i < str1.length() + 1; i++) {
        for (int j = 0; j < str2.length() + 1; j++) {
            if (i == 0 || j == 0) {
                board[i][j] = 0;
            } else {
                if (str1[i - 1] == str2[j - 1]) {
                    board[i][j] = board[i - 1][j - 1] + 1;
                } else {
                    board[i][j] = getMax(board[i - 1][j], board[i][j - 1]);
                }
            }
            // printf("%d ", board[i][j]);
        }
        // printf("\n");
    }

    printf("%d", board[str1.length()][str2.length()]);

    return 0;
}

int getMax(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}