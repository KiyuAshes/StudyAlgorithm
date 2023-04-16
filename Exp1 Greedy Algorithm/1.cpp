/*
 * @Author: KiyuAshes
 * @Date: 2023-04-16 18:21:27
 * @LastEditTime: 2023-04-16 19:11:01
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
  int i = 0, step, min = INT_MAX, total = INT_MAX;
  stamp stp[100050];

  scanf("%ld%ld", &n, &m);

  for (i = 0; i < n; i++) {
    scanf("%d", &stp[i].num);
    if (stp[i].num < total)
      total = stp[i].num;
  }

  for (i = 0; i < n; i++) {
    scanf("%d", &stp[i].max);
  }

  sort(stp, stp + n, [](stamp x, stamp y) -> bool { return x.num < y.num; });

  i = 0;
  while (m > 0) {
    if (stp[i].num > total) {

      step = stp[i].num - total;

      if (step >= min || step >= m / i) {
        total += min < (m / i) ? min : (m / i);
        break;
      }

      total += step;

      i = 0;
      min = INT_MAX;
      continue;
    }

    if (stp[i].num < total) {
      step = total - stp[i].num;

      stp[i].max -= step;
      stp[i].num += step;

      m -= step;
    }

    if (stp[i].max < min)
      min = stp[i].max;

    i++;
  }

  printf("%d ", total);

  return 0;
}