#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct aluno {
  char a[20];
  char s;
  int c;
};


void swap(struct aluno *a, struct aluno *b) {
  struct aluno temp = *a;
  *a = *b;
  *b = temp;
}


void sort(struct aluno arr[], int n) {

  for (int i = 0; i < n - 1; i++) {
    int swapped = 0;
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j].c > arr[j + 1].c) {
        swap(&arr[j], &arr[j + 1]);
        swapped = 1;
      }
      else if (arr[j].c == arr[j + 1].c) {
        if (arr[j].s > arr[j + 1].s) {
          swap(&arr[j], &arr[j + 1]);
          swapped = 1;
        }
        else if (arr[j].s == arr[j + 1].s) {
          if (strcmp(arr[j].a, arr[j + 1].a) > 0) {
            swap(&arr[j], &arr[j + 1]);
            swapped = 1;
          }
        }
      }
    }
    if (swapped == 0) {
      break;
    }
  }
}


int main(void) {
  int q;
  
  
  while (scanf("%d", &q) != EOF) {
    struct aluno *arr;
    arr = (struct aluno*)malloc(q * sizeof(struct aluno));
    
    for (int i = 0; i < q; i++) {
      scanf("%s %c %d", arr[i].a, &arr[i].s, &arr[i].c);
    }

    sort(arr, q);
    for (int i = 0; i < q; i++) {
      printf("%s\n", arr[i].a);
    }
  }
  
  return 0;
}
