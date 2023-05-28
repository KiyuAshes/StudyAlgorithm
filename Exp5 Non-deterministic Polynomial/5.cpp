#include <cstdio>

int ans;
int k, c, n;
int boat[30];
int person[18];

bool dfs(int x, int y) {
    if (x == n) {
        return true;
    }

    for (int i = 0; i < y; i++) {
        if (boat[i] + person[x] <= c) {
            boat[i] += person[x];
            if (dfs(x + 1, y)) {
                return true;
            }
            boat[i] -= person[x];
        }
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

        for (ans = 1; ans <= k; ans++) {
            if (dfs(0, ans)) {
                break;
            }
        }

        if (ans <= k) {
            printf("Let's go\n");
        }
        else {
            printf("find another way\n");
        }
    }
    return 0;
}
