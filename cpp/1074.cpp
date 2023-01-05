#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
    int n, r, c, dv, cnt = 0;

    scanf("%d %d %d", &n, &r, &c);

    dv = n;
    r += 1;
    c += 1;

    while (dv >= 1) {
        int quadrant = 0, fr = 0, fc = 0;
        if (r > pow(2, dv - 1)) {
            fr = 1;
            r -= pow(2, dv - 1);
        }
        if (c > pow(2, dv - 1)) {
            fc = 1;
            c -= pow(2, dv - 1);
        }

        if (!fr && !fc) {
            quadrant = 0;
        } else if (!fr && fc) {
            quadrant = 1;
        } else if (fr && !fc) {
            quadrant = 2;
        } else {
            quadrant = 3;
        }
        cnt += pow(2, 2 * (dv - 1)) * quadrant;

        dv--;
    }

    printf("%d\n", cnt);

    return 0;
}