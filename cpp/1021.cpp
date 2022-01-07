#include <algorithm>
#include <iostream>
#include <list>
#include <stdio.h>
using namespace std;

int main() {
    int n, m, cnt = 0;
    list<int> circular;
    list<int>::iterator iter;

    scanf("%d %d", &n, &m);

    int arr[50] = {0};

    for (int i = 0; i < m; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 1; i <= n; i++) {
        circular.push_back(i);
    }

    iter = circular.begin();

    for (int i = 0; i < m; i++) {
        int tmp = 0;
        while (*iter != arr[i]) {
            iter++;
            tmp++;
            if (iter == circular.end()) {
                iter = circular.begin();
            }
        }

        cnt += min(tmp, n - tmp);
        n--;
        iter = circular.erase(iter);
        if (iter == circular.end()) {
            iter = circular.begin();
        }
    }

    printf("%d", cnt);
}