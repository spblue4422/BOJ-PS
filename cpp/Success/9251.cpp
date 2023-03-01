#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

// LCS 문제 어디서 많이 들어봄.
// 공략 안봤으면 절대 못풀었을 것 같은 문제
// 사실 점화식이 왜 저건지도 정확히는 모르겠음.
// 같은 문자 일때, dp[i][j] = dp[i-1][j-1] + 1;
// 다른 문자 일때, dp[i][j] = getMax(dp[i-1][j], dp[i][j-1]);
// 내가 직접 표를 그려보고 문자열을 비교해보면서도 뭔가 왜 이런 표가 나오고,
// 왜 이런 점화식이 되는지 잘 모르겠는... 그냥 모르면 외우고 풀어야 하지 않을까?
// 오랜만에 string 쓰려니까 scanf가 안 되서 당황..
// 아무튼 어려운 문제다!

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