#include <algorithm>
#include <iostream>
#include <list>
#include <stdio.h>
using namespace std;

int main() {
    list<int> yosephus;
    list<int>::iterator iter;

    int n = 0;
    int k = 0;

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        yosephus.push_back(i + 1);
    }

    iter = yosephus.begin();
    printf("<");
    while (n > 1) {
        for (int i = 0; i < k - 1; i++) {
            iter++;
            if (iter == yosephus.end()) {
                iter = yosephus.begin();
            }
        }
        printf("%d, ", *iter);
        iter = yosephus.erase(iter);
        n--;
        if (iter == yosephus.end()) {
            iter = yosephus.begin();
        }
    }
    printf("%d>", *iter);
}