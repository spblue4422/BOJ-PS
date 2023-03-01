#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// 풀고 보니 DP 문제의 정석 중의 정석인 문제.
// 앞에서부터 포도주의 경우의 수를 생각했는데, 결과를 보니 dp는 항상 점화식 부터 세워야 한다는 생각이 다시 드는 문제
// 결과적으로 마지막 부분에서의 규칙이 어떻게 형성되는지를 찾아야 하는데 앞에서부터 경우만 생각하다 보니 점화식을 못찾겠다.
// dp는 어려워...
// 마지막의 잔을 마시는 경우에서 규칙을 찾기만 하면 쉬운 문제인 것 같음.

int getMax(int a, int b, int c);

int main() {
    int n = 0, M = 0;
    int arr[10001] = {0};
    int dpArr[10001] = {0};

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    dpArr[1] = arr[1];
    dpArr[2] = arr[1] + arr[2];

    for (int i = 3; i <= n; i++) {
        dpArr[i] = getMax(dpArr[i - 1], dpArr[i - 3] + arr[i - 1] + arr[i], dpArr[i - 2] + arr[i]);
    }
    printf("%d", dpArr[n]);

    return 0;
}

int getMax(int a, int b, int c) {
    int tmp = 0;
    if (a > b) {
        tmp = a;
    } else {
        tmp = b;
    }

    if (tmp < c) {
        tmp = c;
    }

    return tmp;
}