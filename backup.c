#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int verifica_jogo(char jogo[4][4], char p)
{
    for (int i = 0; i < 3; i++)
    {
        if ((jogo[i][0] == p) && (jogo[i][1] == p) && (jogo[i][2] == p))
        {
            return 1;
        }

        else if ((jogo[0][i] == p) && (jogo[1][i] == p) && (jogo[2][i] == p))
        {
            return 1;
        }
    }

    if ((jogo[0][0] == p) && (jogo[1][1] == p) && (jogo[2][2] == p))
    {
        return 1;
    }

    else if ((jogo[0][2] == p) && (jogo[1][1] == p) && (jogo[2][0] == p))
    {
        return 1;
    }

    return 0;
}

void imprime(char jogo[4][4], FILE *arq)
{
    for (int i = 0; i < 3; i++)
    {
        fprintf(arq,"\n");
        for (int j = 0; j < 3; j++)
        {
            fprintf(arq,"%c", jogo[i][j]);
        }
    }
    fprintf(arq,"\n");
}

void processa(char jogo[4][4], char p, FILE *arq)
{

    char jogocp[4][4];

    if (verifica_jogo(jogo, 'X'))
    {
        return;
    }

    if (verifica_jogo(jogo, 'O'))
    {
        imprime(jogo,arq);
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            jogocp[i][j] = jogo[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (jogo[i][j] == 'B')
            {
                jogocp[i][j] = p;
                if (p == 'O')
                {
                    processa(jogocp, 'X', arq);
                    jogocp[i][j] = 'B';
                }
                else
                {
                    processa(jogocp, 'O', arq);
                    jogocp[i][j] = 'B';
                }
            }
        }
    }
}

void le_file(FILE *arq1, FILE *arq2)
{
    char jogo[4][4];
    char aux[4];
    for (int i = 0; i < 3; i++)
    {
        fscanf(arq1, "%s", aux);
        strcpy(jogo[i], aux);
    }
    processa(jogo, 'O', arq2);
}

int main(int argc, char *argv[])
{
    testa_parametros(argc);
    FILE *arq1 = fopen(argv[1], "r");
    FILE *arq2 = fopen(argv[2], "w");
    testa_abertura(arq1, argv[1], "r");
    le_file(arq1, arq2);
    fclose(arq1);
    fclose(arq2);
    return 0;
}
