#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// Ǯ�� ���� DP ������ ���� ���� ������ ����.
// �տ������� �������� ����� ���� �����ߴµ�, ����� ���� dp�� �׻� ��ȭ�� ���� ������ �Ѵٴ� ������ �ٽ� ��� ����
// ��������� ������ �κп����� ��Ģ�� ��� �����Ǵ����� ã�ƾ� �ϴµ� �տ������� ��츸 �����ϴ� ���� ��ȭ���� ��ã�ڴ�.
// dp�� �����...
// �������� ���� ���ô� ��쿡�� ��Ģ�� ã�⸸ �ϸ� ���� ������ �� ����.

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