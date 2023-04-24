/*
 * @Author: KiyuAshes
 * @Date: 2023-04-16 18:21:27
 * @LastEditTime: 2023-04-24 01:03:36
 * @Description: USC OJ 1388 集邮票
 * @E-mail: kiyuashes@stu.usc.edu.cn
 * Copyright (c) 2023 by KiyuAshes, All Rights Reserved. 
 */

#include <algorithm>
#include <climits>
#include <cstdio>

using namespace std;

typedef struct stamp {
  int num = 0, max = 0;
} stamp;

int main() {
  long n, m;
  int i = 0, l = INT_MAX, r = INT_MAX, total = 0, mid, used;
  stamp stp[100050];

  scanf("%ld%ld", &n, &m);

  for (i = 0; i < n; i++) {
    scanf("%d", &stp[i].num);
    if (stp[i].num < l)
      l = stp[i].num;
  }

  for (i = 0; i < n; i++) {
    scanf("%d", &stp[i].max);
    if (stp[i].num + stp[i].max < r)
      r = stp[i].num + stp[i].max;
  }

  while (l <= r) {
    mid = (l + r) / 2;
    used = 0;

    for (i = 0; i < n; i++) {

      if (stp[i].num > mid)
        continue;

      if (stp[i].max < mid - stp[i].num)
        break;

      used += mid - stp[i].num;


    }

    if (i == n && used <= m) {
      total = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  printf("%d", total);
  return 0;
}