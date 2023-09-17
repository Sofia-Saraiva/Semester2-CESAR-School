#include <stdio.h>

int tempo(int h1, int m1, int h2, int m2);

int main(void) {
  int h1, m1, h2, m2;

  while (1) {
    scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
    if (h1 == 0 && h2 == 0 && m1 == 0 && m2 == 0) {
      break;
    }
    int total = tempo(h1,m1,h2,m2);
    printf("%d\n", total);
  }
  return 0;
}

int tempo(int h1, int m1, int h2, int m2) {
  int t1 = (h1 * 60) + m1;
  int t2 = (h2 * 60) + m2;

  int minutos = t2 - t1;
  if (minutos < 0) {
    minutos = minutos + 1440;
  }

  return minutos;
}