#include <stdio.h>
typedef struct ponto2d
{
    float x;
    float y;
}TPonto2d;

int main (void)
{
    TPonto2d p;
    printf("Digite as coordenadas do ponto(x y)" );
    scanf("&f &f",&p.x, &p.y);
    printf("O ponto fornecido foi: (%.2f, %.2f)\n", p.x, p.y);
    return 0;
}
