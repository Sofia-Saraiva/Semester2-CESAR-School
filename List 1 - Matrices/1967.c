#include <stdio.h>

int main(void) {
  int g, a, m, c, i , j, k, l;

  scanf("%d %d %d %d", &g, &a, &m, &c);
  int ga[g][a], am[a][m], mc[m][c], result1[g][m], resultfinal[g][c];
  
  printf("\n");
  for (i = 0; i < g; i++) {
    for (j = 0; j < a; j++) {
        scanf("%d", &ga[i][j]);
    }
  }
  printf("\n");

  for (i = 0; i < a; i++) {
    for (j = 0; j < m; j++) {
        scanf("%d", &am[i][j]);
    }
  }
  printf("\n");
  
  for (i = 0; i < m; i++) {
    for (j = 0; j < c; j++) {
        scanf("%d", &mc[i][j]);
    }
  }

  
  for (i = 0; i < g; i++) {
    for (j = 0; j < m; j++) {
      result1[i][j] = 0;
      for (k = 0; k < a; k++) {
        result1[i][j] += ga[i][k] * am[k][j];
      }
    }
  }

  for (i = 0; i < g; i++) {
    for (j = 0; j < c; j++) {
      resultfinal[i][j] = 0;
      for (k = 0; k < m; k++) {
        resultfinal[i][j] += result1[i][k] * mc[k][j];
      }
    }
  }

  for (i = 0; i < g; i++) {
    for (j = 0; j < c; j++) {
      printf("%*d", 3, resultfinal[i][j]); 
      if (j < c - 1) {
          printf(" "); 
      }
    }
    printf("\n"); 
  }

  return 0;
}