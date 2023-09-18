#include <stdio.h>

int main(void) {
  int max, x, index;

  max = 0;
  for (int i = 0; i < 10; i++) {
    scanf("%d", &x);
    if (x > max) {
      max = x;
      index = i + 1;
    }
  }

  printf("%d\n", max);
  printf("%d\n", index);
  
  return 0;
}