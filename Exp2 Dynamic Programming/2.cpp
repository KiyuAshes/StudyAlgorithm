/*
 * @Author: KiyuAshes
 * @Date: 2023-05-06 06:24:07
 * @LastEditTime: 2023-05-06 15:17:59
 * @Description: USC OJ 1391 正确的排队
 * @E-mail: kiyuashes@stu.usc.edu.cn
 * Copyright (c) 2023 by KiyuAshes, All Rights Reserved.
 */

#include <bitset>
#include <cstdio>

#define MAX_N 10000000 + 100

using namespace std;

int main() {
    int n, x;
    bitset<MAX_N> q;
    q.reset();

    // The item before the first item of queue is the end of last group
    q[0] = true;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);

        // the x-1 one ahead exist and is the end of last group
        // the x one ahead is guide and the ticket num is right
        // q[i] is the end of this group
        if (i - x - 1 >= 0 && q[i - x - 1])
            q[i] = true;

        // the first one ahead exist and is the end of last group
        // q[i] is guide and the ticket num is right
        // the x one behind is the end of this group
        if (i + x <= n && q[i - 1])
            q[i + x] = true;
    }

    if (q[n]) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }

    return 0;
}
