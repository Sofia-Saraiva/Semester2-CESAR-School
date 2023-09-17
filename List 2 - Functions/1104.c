#include <stdio.h>

int delDuplicates(int arr[], int n);

int main(void) {

  while (1) {
    int a, b;
    
    scanf("%d %d", &a, &b);
    if (a == 0 && b == 0) {
      break;
    }

    int varA[a], varB[b];
    
    for (int i = 0; i < a; i++) {
      scanf("%d", &varA[i]);
    }
    
    for (int i = 0; i < b; i++) {
      scanf("%d", &varB[i]);
    }

    a = delDuplicates(varA, a);
    b = delDuplicates(varB, b);
    int iguais = 0, menor, max;
    for (int i = 0; i < a; i++) {
      for (int j = 0; j < b; j++) {
        if (varA[i] == varB[j]) {
          iguais++;
        }
      }
    }
    
    a = a - iguais;
    b = b - iguais;

    if (a < b) {
      printf("%d\n", a);
    }
    else {
      printf("%d\n", b);
    }
  }
  return 0;
}

int delDuplicates(int arr[], int n) {
  if (n <= 1) {
    return n;
  }
  
  int temp[n];
  int j = 0;
  for (int i = 0; i < n - 1; i++) {
		if (arr[i] != arr[i + 1]) {
			temp[j++] = arr[i];
    }
  }

  temp[j++] = arr[n - 1];
	for (int i = 0; i < j; i++)
		arr[i] = temp[i];

	return j;
}