#include <stdio.h>
#include <math.h>

struct point {
  int x, y;
};

int main(void) {
  int c, n;
  
  scanf("%d", &c);
  for (int i = 0; i < c; i++) {
    scanf("%d", &n);
    struct point arr[n + 1];
    for (int j = 0; j < n + 1; j++) {
      scanf("%d %d", &arr[j].x, &arr[j].y);
    }
    
    int index = 0;
    int min = 10000000;
    for (int j = 1; j <= n; j++) {
      int d = sqrt((arr[j].x - arr[0].x) * (arr[j].x - arr[0].x) + (arr[j].y - arr[0].y) * (arr[j].y - arr[0].y));
      if (d < min) {
        min = d;
        index = j;
      }
    }

    printf("%d\n", index);
  }
  return 0;
}