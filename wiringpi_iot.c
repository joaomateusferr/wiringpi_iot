#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <wiringPi.h> //biblioteca que controla os pinos do rasperepi que so vai funcionar nele
#define MAX 4

void min (char str[])
{
    int i;

    for(i = 0; str[i]; i++) // funcao para deixar tudo minusculo que roda no linux
    {
        str[i] = tolower(str[i]);
    }
}

int main()
{
    char pin[MAX][6] = { "1fh94", "3w709", "f90cg", "m2tm0"};
    int controle[MAX];
    char codigo[6];
    char fim[4];
    int i,j,encontrado=0,existe=0;

    inicio:

    for(i=0;i<MAX;i++)
    {
        controle[i]=0;  //inicia o vetor de controle com 0
    }

    printf("INSIRA OS PINS DESEJADOS EM SEGUIDA, INSIRA O CARACTER - (MENOS) OU A QUALQUER MOMENTO DA ENTRADA INSIRA TUDO PARA INSERIR TODOS DE UMA VEZ\n\n");

    printf("INPUT\n\n");

    while(codigo[0]!='-')   //ao digitar - o for para de ser executado
    {
        scanf("%s",&codigo);   //input dos codigos

        min(codigo); //deixar tudo minusculo com a fun��o que funciona no linux

        if(strcmp("tudo",codigo)==0) //tudo pode ser inserido a qualquer momento
        {
            for(i=0;i<MAX;i++)
            {
                    controle[i]=1;  //coloca 1 no controle para depois colocar os codigos no input
                    encontrado=1;   //flag para dizer que um pin foi encontrado
                    existe=1;   //flag para dizer que existe ao menos um pin
            }
            encontrado=0; //zera o encontado para evitar problemas no proximo la�o de execu��o

            break;

        }

        if(codigo[0]=='-')  //nao imprime o - no output antes de encerar o programa
        {
            break;
        }

            for(i=0;i<MAX;i++)
            {
                if((strcmp(pin[i],codigo))==0)  //compara o pin inserido com os pins possiveis
                {
                    if(controle[i]==1) //se o pin ja tiver sido inserido a mensagem aparecera para o usuario e a entrada sera desconsiderada
                    {
                        printf("CODIGO JA INSERIDO ULTIMA ENTRADA DESCONSIDERADA\n");
                    }

                    controle[i]=1;  //coloca 1 no controle para depois colocar os codigos no input
                    encontrado=1;   //flag para dizer que um pin foi encontrado
                    existe=1;   //flag para dizer que existe ao menos um pin
                }
            }

            if(encontrado==0)   //valida se um pin foi encontrado
            {
                printf("%s NOT FOUND\n");
            }

            encontrado=0; //zera o encontado para evitar problemas no proximo la�o de execu��o
    }

     printf("\nOUTPUT\n\n");

    for(i=0;i<MAX;i++)   //imprime os pins digitados no output
    {
        if(controle[i]==1)
        {
            printf("%s\n",pin[i]);
            //digitalWrite (i, HIGH) //acende os leds corespondente aos codigos no microcontrolador;
        }
    }

    if(existe==0)   //se nenhum pin valido foi encontrado
    {
        printf("0 ");

    }

    printf("\nLED(S) UP!\n");

    printf("\nDIGITE FIM PARA APAGAR OS LEDS, LIMPAR A TELA E REINICIAR O PROGRAMA\n");

    fim:

    scanf("%s",&fim);

    min(fim); //deixar tudo minusculo com a fun��o que funciona no linux

    if(strcmp(fim,"fim")==0)
    {
        strcpy(codigo," "); //limpa a string codigo para prevenir o loop infinito

        for(i=0;i<MAX;i++)
        {
            //digitalWrite (i, LOW) //apaga todos os os leds do microcontrolador;
        }

        existe=0; ////zera o existe para evitar problemas no proximo la�o de execu��o

        system("clear"); //limpa o terminal do linux

        goto inicio; //reinicia o programa fazendo
    }
    else
    {
        printf("\nA PALAVRA DIGITADA NAO CORESPONDE, DIGITE FIM PARA APAGAR OS LEDS E REINICIAR O PROGRAMA\n");

        strcpy(fim," "); //limpa a string fim para prevenir o loop infinito


        goto fim; // faz com que o usuario redigite a string fim ate o programa obter um resultado valido
    }

    return 0;
}
