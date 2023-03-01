#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

// ó���� �ߴ� ����
// dp�迭�� ���� ��, ���� 2���� �迭�� ���� � ���ڿ��� ���ƴ��� �ٷιٷ� �ִ� ����
// �ڵ尡 �� ���������� ������ ���������� ������ ��.
// But �޸� �ʰ� ���� �߻�
// �� ���� ���� ���� �ſ� �������� �����...
// ���带 �ϼ��ϰ� ���� ���ڿ��� �������� Ž���ϴ� ���
// ������ ���� ���ڿ� ����� ��ͷ� ®��, ���� ������ �̿�

int getMax(int a, int b);

int board[1001][1001] = {0};

int main() {
    int M = 0;
    stack<int> prtStk;
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
        }
    }
    M = board[str1.length()][str2.length()];
    printf("%d\n", M);

    for (int i = str1.length(), j = str2.length(), k = M; k > 0; i--, j--, k--) {
        while (board[i][j] == board[i][j - 1] || board[i][j] == board[i - 1][j]) {
            if (board[i - 1][j] >= board[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
        prtStk.push(str1[i - 1]);
    }

    for (int i = 0; i < M; i++) {
        printf("%c", prtStk.top());
        prtStk.pop();
    }

    return 0;
}

int getMax(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

// vector<int> vArr[1001][1001];

// int main() {
//     string str1, str2;

//     cin >> str1;
//     cin >> str2;

//     for (int i = 0; i < str1.length() + 1; i++) {
//         for (int j = 0; j < str2.length() + 1; j++) {
//             if (i == 0 || j == 0) {
//                 vArr[i][j].push_back(0);
//             } else {
//                 if (str1[i - 1] == str2[j - 1]) {
//                     int tmp = vArr[i - 1][j - 1].front();
//                     vArr[i][j].push_back(tmp + 1);

//                     for (int k = 0; k < tmp; k++) {
//                         vArr[i][j].push_back(vArr[i - 1][j - 1][k + 1]);
//                     }

//                     vArr[i][j].push_back(str1[i - 1]);
//                 } else {
//                     int tmp1 = vArr[i - 1][j].front();
//                     int tmp2 = vArr[i][j - 1].front();

//                     if (tmp1 >= tmp2) {
//                         vArr[i][j].push_back(tmp1);

//                         for (int k = 0; k < tmp1; k++) {
//                             vArr[i][j].push_back(vArr[i - 1][j][k + 1]);
//                         }
//                     } else {
//                         vArr[i][j].push_back(tmp2);

//                         for (int k = 0; k < tmp2; k++) {
//                             vArr[i][j].push_back(vArr[i][j - 1][k + 1]);
//                         }
//                     }
//                 }
//             }
//         }
//     }

//     for (int i = 0; i < vArr[str1.length()][str1.length()].size(); i++) {
//         if (i == 0) {
//             printf("%d\n", vArr[str1.length()][str1.length()][i]);
//         } else {
//             printf("%c", vArr[str1.length()][str1.length()][i]);
//         }
//     }
//     printf("\n");

//     return 0;
// }