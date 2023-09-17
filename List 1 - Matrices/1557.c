#include <stdio.h>
#include <math.h>

int main() {
    int n, space, max, t=0;

  while (1) {
    scanf("%d", &n);
    
    if (n == 0) {
      break;
    }
    
    int matrix[n][n];
  
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0) {
                matrix[i][j] = pow(2,j);  
            } else if (j == 0) {
                matrix[i][j] = pow(2,i); 
            } else {
                matrix[i][j] = 2 * matrix[i-1][j]; 
            }
        }
    }

    max = pow(2, ((n - 1) * 2));
    space = 0;
    while (max > 0) {
      max = max / 10;
      space++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          printf("%*d", space, matrix[i][j]); 
          if (j < n - 1) {
              printf(" "); 
          }
        }
        printf("\n");
    }
    printf("\n");
  }

  return 0;
}
