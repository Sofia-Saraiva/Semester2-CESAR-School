#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produto {
  char nome[50];
  float valor;
};

struct comprar {
  char nome[50];
  int unidade;
};

int main(void) {
  int n, m, p;
  
  scanf("%d", &n);
  for (int i  = 0; i < n; i++) {
    float total = 0;
    scanf("%d", &m);
    
    struct produto *arr;
    arr = (struct produto*)malloc(m * sizeof(struct produto));
    
    for (int j = 0; j < m; j++) {
      scanf("%s %f", arr[j].nome, &arr[j].valor);
    }
  
    scanf("%d", &p);
    struct comprar *arr2;
    arr2 = (struct comprar*)malloc(p * sizeof(struct comprar));
    for (int k = 0; k < p; k++) {
      scanf("%s %d", arr2[k].nome, &arr2[k].unidade);
    }

    for (int j = 0; j < m; j++) {
      for (int k = 0; k < p; k++) {
        if (strcmp(arr[j].nome, arr2[k].nome) == 0) {
          total += (arr[j].valor * arr2[k].unidade);
        }
      }
    }

    printf("R$ %.2f\n", total);
    free(arr);
    free(arr2);
  }
  
  return 0;
}