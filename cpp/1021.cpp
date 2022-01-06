#include <algorithm>
#include <iostream>
#include <list>
#include <stdio.h>
using namespace std;

int main() {
    int n = 0;
    int m = 0;
    int k = 0;
    int tmp1 = 0;
    int tmp2 = 0;
    int cnt = 0;
    list<int> circular;
    list<int>::iterator iter;
    list<int>::iterator calc2;
    list<int>::iterator calc3;

    scanf("%d %d", &n, &m);

    int arr[50] = {0};

    for (int i = 0; i < m; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 1; i <= n; i++) {
        circular.push_back(i);
    }
    //포인터 위치 설정
    iter = circular.begin();

    for (int i = 0; i < m; i++) {
        calc2 = iter;
        while (*calc2 != arr[i]) {
            if (calc2 == circular.end()) {
                calc2 = circular.begin();
            }
            calc2++;
            tmp1++;
        }

        calc3 = iter;
        while (*calc3 != arr[i]) {
            if (calc3 == circular.begin()) {
                calc3 = circular.end();
            }
            calc3--;
            tmp2++;
        }
        cnt += min(tmp1, tmp2);
        tmp1 = 0;
        tmp2 = 0;
        iter = circular.erase(calc3);
    }

    printf("%d", cnt);
}