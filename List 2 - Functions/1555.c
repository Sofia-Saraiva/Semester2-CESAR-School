#include <stdio.h>

int power(int base, int exponente);
int rafael(int x, int y);
int beto(int x, int y);
int carlos(int x, int y);

int main(void) 
{
  int n;
  scanf("%d", &n);

  for (int cont = 0; cont < n; cont++)
  {
    int x, y;
    scanf("%d %d", &x, &y);

    int r = rafael(x,y);
    int b = beto(x,y);
    int c = carlos(x,y);
  
    if (r > b && r > c) 
    {
      printf("Rafael ganhou\n");
    }
    else if (b > r && b > c)
    {
      printf("Beto ganhou\n");
    }
    else
    {
      printf("Carlos ganhou\n");
    }
  }

  return 0;
}


int power(int base, int exponente)
{
  int result = 1;
  for (int i = 0; i < exponente; i++)
  {
      result *= base;
  }
  
  return result;
}

int rafael(int x, int y) {
  int t = power(3 * x, 2) + power(y, 2);
  return t;
}

int beto(int x, int y) {
  int t = 2 * power(x, 2) + power(5, 2) * power(y, 2);
  return t;
}

int carlos(int x, int y) {
  int t = -100 * x + power(y, 3);
  return t;
}