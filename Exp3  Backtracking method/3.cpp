/*
 * @Author: KiyuAshes
 * @Date: 2023-05-06 13:29:51
 * @LastEditTime: 2023-05-08 16:04:01
 * @Description: USC OJ 1389 筛选排列
 * @E-mail: kiyuashes@stu.usc.edu.cn
 * Copyright (c) 2023 by KiyuAshes, All Rights Reserved.
 */
#include <vector>
#include <cstdio>

using namespace std;

int main() {
    int n, q, i, j;
    bool used[10];
    int x[10];
    vector<int> lim[10];

    // Input
    scanf("%d%d", &n, &q);
    for (i = 0; i < q; i++) {
        int loc, num;
        scanf("%d%d", &loc, &num);
        lim[loc].push_back(num);
    }

    // Init array
    for (i = 0; i < 10; i++) {
        x[i] = n + 1;
        used[i] = false;
    }

    i = 1;

    while (i >= 1) {
        if (x[i] > 1) {
            x[i]--;

            for (j = 0; j < lim[i].size(); j++) {
                if (lim[i][j] == x[i])
                    break;
            }

            if (!used[x[i]] && j + 1 > lim[i].size()) {
                if (i == n) {
                    for (j = 1; j <= n; j++) {
                        printf("%d ", x[j]);
                    }
                    printf("\n");
                }
                else {
                    used[x[i]] = true;
                    i++;
                }
            }
        }
        else {
            x[i] = n + 1;
            i--;
            used[x[i]] = false;
        }
    }
    return 0;
}
