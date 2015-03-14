#include <stdio.h>
#include <stdlib.h>

typedef struct {
  float real, img;
} complexo;

complexo soma(complexo a, complexo b);
complexo le_complexo();
void escreve_complexo(complexo a);

int
main()
{
  complexo x, y, z;

  x = le_complexo();
  y = le_complexo();

  z = soma(x, y);

  escreve_complexo(x);
  printf(" + ");
  escreve_complexo(y);
  printf(" = ");
  escreve_complexo(z);
  printf("\n");

  return EXIT_SUCCESS;
}

complexo
soma(complexo a, complexo b)
{
  a.real += b.real;
  a.img += b.img;

  return a;
}

complexo
le_complexo()
{
  complexo a;
  char sign;

  scanf("%f%c%fi", &a.real, &sign, &a.img);

  if (sign == '-')
    a.img *= -1;

  return a;
}

void
escreve_complexo(complexo a)
{
  if (a.img >= 0)
    printf("%f+%fi", a.real, a.img);
  else
    printf("%f%fi", a.real, a.img);
}
