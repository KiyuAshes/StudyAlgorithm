/*
 * @Author: KiyuAshes
 * @Date: 2023-05-28 09:42:09
 * @LastEditTime: 2023-05-28 13:45:04
 * @Description: USC OJ 1392 探险家们的回程之路
 * @E-mail: kiyuashes@stu.usc.edu.cn
 * Copyright (c) 2023 by KiyuAshes, All Rights Reserved. 
 */
#include <cstdio>
#include <climits>

int ans;
int k, c, n;
int boat[30];
int person[18];

bool dfs(int x, int y) {
    if (y >= ans)
        return false;

    if (x == n) {
        return true;
    }

    for (int i = 0; i < y; i++) {
        if (boat[i] + person[x] <= c) {
            boat[i] += person[x];
            if (dfs(x + 1, y)) {
                ans = y;
            }
            boat[i] -= person[x];
        }
    }

    if (boat[y]) {
        boat[y + 1] = person[x];
        if (dfs(x + 1, y + 2)) {
            ans = y + 1;
        }
        boat[y + 1] = 0;
    }
    else {
        boat[y] = person[x];
        if (dfs(x + 1, y + 1)) {
            ans = y + 1;
        }
        boat[y] = 0;
    }

    return false;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        //输入数据
        scanf("%d%d%d", &k, &c, &n);

        for (int i = 0; i < n; i++) {
            scanf("%d", &person[i]);
        }

        //初始化数据
        for (int i = 0; i < k; i++) {
            boat[i] = 0;
        }

        ans = INT_MAX;

        dfs(0, 1);

        if (ans <= k) {
            printf("Let's go\n");
        }
        else {
            printf("find another way\n");
        }
    }
    return 0;
}
