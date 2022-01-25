#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    int a, b, c, d, e, f;
    int x = 0, y = 0;

    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

    x = (c * e - b * f) / (a * e - b * d);
    y = (c * d - a * f) / (b * d - a * e);

    printf("%d %d", x, y);

    return 0;
}