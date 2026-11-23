#include <stdio.h>

int main()
{   int opcao;


    printf("\n====Controle de estacionamento====\n ");
    printf("1- Consultar vagas\n");
    printf(" 2- Consultar senha\n");
    printf(" 3- Gerar senhas\n");
    printf(" 4- Pagar\n");
    printf(" 5- Sair\n");
    printf("==================================\n");
    printf("Escolha uma opcao: \n");
    scanf("%d", &opcao);

    switch(opcao)
        case 1
            printf("Consultando vagas\n");
            break;
        case 2
            printf("Consultando senhas\n");
            break;
        case 3
            printf("Gerando senha\n");
            break;
        case 4
            printf("Pagar\n");
            break;
        case 5
            printf("Sair\n");
            break;
    return 0;

}
