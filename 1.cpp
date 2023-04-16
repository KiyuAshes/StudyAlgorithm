/*
 * @Author: KiyuAshes
 * @Date: 2023-04-16 18:21:27
 * @LastEditTime: 2023-04-16 18:32:30
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
  int n, m, total = INT_MAX, p = 0;
  stamp stp[100050];

  scanf("%d%d", &n, &m);

  for (int i = 0; i < n; i++) {
    scanf("%d", &stp[i].num);
    if (stp[i].num < total)
      total = stp[i].num;
  }

  for (int i = 0; i < n; i++) {
    scanf("%d", &stp[i].max);
  }

  sort(stp, stp + n, [](stamp x, stamp y) -> bool { return x.num < y.num; });


  while (m > 0) {
    if (stp[p].num > total) {
      total++;
      p = 0;
      continue;
    }

    if (stp[p].max == 0)
      break;

    stp[p].max--;
    stp[p].num++;

    p++;
    m--;
  }


  printf("%d ", total);

  return 0;
}