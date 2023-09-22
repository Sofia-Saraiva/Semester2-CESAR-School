#include <stdio.h>

int main(void) {
  char str[21];
  int n, k, boolean; 

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    boolean = 0;
    scanf("%d", &k);
    char c = '\0';
    for (int j = 0; j < k; j++) {
      scanf("%s", str);
      char current = str[0];

      if (c != current && c != '\0') {
        boolean = 1;
      }

      c = current;
    }

    if (boolean == 1) {
      printf("ingles\n");
    }
    else {
      printf("%s\n", str);
    }
  }
  return 0;
}