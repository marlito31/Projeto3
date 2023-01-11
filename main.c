#include <stdio.h>
#include <stdlib.h>

void testa_parametros(int argc)
{
    if (argc != 3)
    {
        printf("uso: ./main <arquivo de entrada> <arquivo de saída>\n");
        exit(0);
    }
}

void testa_abertura(FILE *fp, const char *path, const char *mode)
{
    if (fp == NULL)
    {
        printf("Erro ao abrir %s com o modo %s\n", path, mode);
        exit(0);
    }
}

void processa(char aux[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (aux[i][j] == 'B')
            {
                aux[i][j] = 'O';
            } 
        } 
    }
}

void le_file(FILE *arq1, FILE *arq2)
{
    char aux[3][3];
    for (int i = 0; i < 3; i++)
    {
        fscanf(arq1,"%s",aux[i]);
    }
    processa(aux[3][3]);
}

int main (int argc, char *argv[])
{
    testa_parametros(argc);
    FILE *arq1 = fopen(argv[1], "r");
    FILE *arq2 = fopen(argv[2], "w");
    testa_abertura(arq1, argv[1], "r");
    le_file(arq1,arq2);
    return 0;
}
