#include <stdio.h>

#ifdef _WIN32
    #include <windows.h>
    #define ESPERAR(seg) Sleep((seg) * 1000)
#else
    #include <unistd.h>
    #define ESPERAR(seg) sleep(seg)
#endif

#define TOTAL_VAGAS 10
#define TARIFA_HORA 5.00
#define TEMPO_PAUSA 10


void pausa(void)
{
    int s;
    printf("\nVoltando ao menu em ");
    fflush(stdout);
    for (s = TEMPO_PAUSA; s > 0; s--)
    {
        printf("%d... ", s);
        fflush(stdout);
        ESPERAR(1);
    }
    printf("\n");
}

int main()
{
    int opcao;
    int vagas[TOTAL_VAGAS] = {0};
    int proximaSenha = 1;
    int i, senha, encontrou, ocupadas;
    int minutos, horas;
    float valor, pago, troco;

    do
    {
        printf("\n====Controle de estacionamento====\n");
        printf(" 1- Consultar vagas\n");
        printf(" 2- Consultar senha\n");
        printf(" 3- Gerar senhas\n");
        printf(" 4- Pagar\n");
        printf(" 5- Sair\n");
        printf("==================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                printf("\nConsultando vagas...\n");
                ocupadas = 0;
                for (i = 0; i < TOTAL_VAGAS; i++)
                {
                    if (vagas[i] == 0)
                        printf("Vaga %02d: LIVRE\n", i + 1);
                    else
                    {
                        printf("Vaga %02d: OCUPADA (senha %d)\n", i + 1, vagas[i]);
                        ocupadas++;
                    }
                }
                printf("\nTotal: %d ocupadas | %d livres\n", ocupadas, TOTAL_VAGAS - ocupadas);
                pausa();
                break;

            case 2:
                printf("\nConsultando senha...\n");
                printf("Digite a senha: ");
                scanf("%d", &senha);
                encontrou = 0;
                for (i = 0; i < TOTAL_VAGAS; i++)
                {
                    if (senha > 0 && vagas[i] == senha)
                    {
                        printf("Senha %d encontrada na vaga %02d.\n", senha, i + 1);
                        encontrou = 1;
                        break;
                    }
                }
                if (!encontrou)
                    printf("Senha %d nao encontrada.\n", senha);
                pausa();
                break;

            case 3:
                printf("\nGerando senha...\n");
                encontrou = 0;
                for (i = 0; i < TOTAL_VAGAS; i++)
                {
                    if (vagas[i] == 0)
                    {
                        vagas[i] = proximaSenha;
                        printf("Senha gerada: %d\n", proximaSenha);
                        printf("Vaga destinada: %02d\n", i + 1);
                        proximaSenha++;
                        encontrou = 1;
                        break;
                    }
                }
                if (!encontrou)
                    printf("Estacionamento lotado! Nao ha vagas livres.\n");
                pausa();
                break;

            case 4:
                printf("\nPagamento\n");
                printf("Digite a senha: ");
                scanf("%d", &senha);
                encontrou = 0;
                for (i = 0; i < TOTAL_VAGAS; i++)
                {
                    if (senha > 0 && vagas[i] == senha)
                    {
                        encontrou = 1;
                        printf("Tempo de permanencia (em minutos): ");
                        scanf("%d", &minutos);

                        /* cobra por hora iniciada, minimo 1 hora */
                        horas = (minutos + 59) / 60;
                        if (horas < 1)
                            horas = 1;
                        valor = horas * TARIFA_HORA;

                        printf("Horas cobradas: %d\n", horas);
                        printf("Valor a pagar: R$ %.2f\n", valor);
                        printf("Valor recebido: R$ ");
                        scanf("%f", &pago);

                        if (pago < valor)
                            printf("Valor insuficiente! Pagamento nao realizado.\n");
                        else
                        {
                            troco = pago - valor;
                            printf("Pagamento realizado! Troco: R$ %.2f\n", troco);
                            printf("Vaga %02d liberada. Volte sempre!\n", i + 1);
                            vagas[i] = 0;
                        }
                        break;
                    }
                }
                if (!encontrou)
                    printf("Senha %d nao encontrada.\n", senha);
                pausa();
                break;

            case 5:
                printf("\nSaindo... Ate logo!\n");
                break;

            default:
                printf("\nOpcao invalida! Escolha de 1 a 5.\n");
                pausa();
        }

    } while (opcao != 5);

    return 0;
}