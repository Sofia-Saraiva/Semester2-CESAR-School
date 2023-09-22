#include <stdio.h>

int main(void) {
  int n;

  scanf("%d", &n);
  getchar();

  for (int i = 0; i < n; i++) {
    int qnt[26] = {0}, max = 0;
    
    for (char c = getchar(); c != '\n'; c = getchar()) {
      if (c >= 'A' && c <= 'Z') {
        c += 32;
      }

      if (c >= 'a' && c <= 'z') {
        int index = c - 'a';
        qnt[index]++;
        if (qnt[index] > max) {
          max = qnt[index];
        }
      }
    }

    for (int j = 0; j < 26; j++) {
      if (max == qnt[j]) {
        printf("%c", j + 'a');
      }
    }
    printf("\n");
  }
  return 0;
}
