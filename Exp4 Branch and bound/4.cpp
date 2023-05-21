/*
 * @Author: KiyuAshes
 * @Date: 2023-05-20 12:24:12
 * @LastEditTime: 2023-05-21 11:11:02
 * @Description: USC OJ 1390 怎么绘世
 * @E-mail: kiyuashes@stu.usc.edu.cn
 * Copyright (c) 2023 by KiyuAshes, All Rights Reserved.
 */
 
#include <cstdio>
#include <queue>

struct P
{
    int x, y, d, t;
};

int dir[8][2] = {{0, 1},  {1, 1},   {1, 0},  {1, -1},
                 {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

int main() {
    bool ff;
    int x, y;
    int s[30];
    int ans = 0;
    int n, m, t;  // n for y,m for x;
    std::queue<P> Q;
    int nx, ny, d;
    int f[505][505] = {0};

    scanf("%d%d%d", &m, &n, &t);

    for (int i = 0; i < t; i++) {
        scanf("%d", &s[i]);
    }

    scanf("%d%d", &x, &y);

    Q.push({x, y, 0, 0});

    for (int i = 0; i < t; i++) {
        while (!Q.empty()) {
            P tmp = Q.front();
            if (tmp.t != i) {
                break;
            }
            Q.pop();

            x = tmp.x;
            y = tmp.y;
            d = tmp.d;

            ff = true;

            for (int j = 0; j < s[i]; j++) {
                nx = x + dir[d][0] * j;
                ny = y + dir[d][1] * j;

                if (nx <= 0 || nx > m || ny <= 0 || ny > n) {
                    ff = false;
                    break;
                }
                else if (f[nx][ny] == 0) {
                    f[nx][ny] = 1;
                    ans++;
                }
            }

            if (ff) {
                x = nx + dir[(d + 1) % 8][0];
                y = ny + dir[(d + 1) % 8][1];

                if (x > 0 && x <= m && y > 0 && y <= n) {
                    Q.push({x, y, (d + 1) % 8, tmp.t + 1});
                }

                x = nx + dir[(d + 7) % 8][0];
                y = ny + dir[(d + 7) % 8][1];

                if (x > 0 && x <= m && y > 0 && y <= n) {
                    Q.push({x, y, (d + 7) % 8, tmp.t + 1});
                }
            }
        }

        printf("%d ", ans);
    }

    return 0;
}