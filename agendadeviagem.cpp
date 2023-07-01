#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <stdbool.h>

// Após se certificar que o modulo de cadastro de localidades funciona, editar o modulo hotel e restaurante para dispor uma lista com os itens cadastrados
// No menu deverá exibir CÓDIGO, NOME, custos alto, medio e baixo
// Só exibirá os locais na cidade escolhida
// Dar um jeito para não cadastrar itens com código de referência duplicados



// struct para ponto de visita
typedef struct
{
    int codLugar;          // Código para o hotel ou restaurante
    int tipo;           // 1 hotel, 2 restaurante
    int codCity;        // Código da cidade na qual o lugar está, disponível na lista de cidades
    char nomeLugar[50]; // Nome do lugar
    float BMA[3];         // BMA = 3 preços diponíves, a opção de Baixo custo, Medio custo e Alto custo
    float preco;        // O preço em si

} Visita;

// Estrutura para representar um feriado
typedef struct
{
    int dia;            // Dia do feriado
    int mes;            // Mês do feriado
    char nome[50];      // Nome do feriado
    int tipo;           // Tipo: 1=Nacional, 2=Estadual, 3=Municipal
    int facultativo;    // 1=Facultativo, 2=Não Facultativo
} Feriado;

typedef struct{
    int diamedio;
    int mesmedio;
    int diainicial;
    int mesinicial;
    int diafinal;
    int mesfinal;
} Datas;

void cadastroAgenda(){
	FILE *agenda, *feri;
    Feriado fer;
    Datas data;

    char facu[20]={0}, tipo[20]={0}, c, meses[13][15]={"zero", "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    
    int y;

	bool dialimite;
	bool meslimite;	
	bool datalimite;
	bool anobissexto = ((y % 4 == 0)&&(y % 100 != 0));

	printf("\nDigite o ano:");
	scanf("%d", &y);
	printf("\n1.JANEIRO\n2.FEVEREIRO\n3.MARÇO\n4.ABRIL\n5.MAIO\n6.JUNHO\n7.JULHO\n8.AGOSTO\n9.SETEMBRO\n10.OUTUBRO\n11.NOVEMBRO\n12.DEZEMBRO\nDigite o MÊS no qual a viagem se INICIARÁ:");
	scanf("%d", &data.mesinicial);
	printf("\nDigite o DIA no qual a viagem se INICIARÁ: ");
	scanf("%d", &data.diainicial);
	system("cls");
	printf("\n1.JANEIRO\n2.FEVEREIRO\n3.MARÇO\n4.ABRIL\n5.MAIO\n6.JUNHO\n7.JULHO\n8.AGOSTO\n9.SETEMBRO\n10.OUTUBRO\n11.NOVEMBRO\n12.DEZEMBRO\nDigite o MÊS no qual a viagem TERMINARÁ:");
	scanf("%d", &data.mesfinal);
	printf("\nDigite o DIA no qual a viagem se TERMINARÁ: ");
	scanf("%d", &data.diafinal);
	
	data.diamedio = data.diainicial;
	data.mesmedio = data.mesinicial;

    do{
        
        if (data.diamedio>28){
            switch(data.mesmedio){
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                if (data.diamedio >31){
                    data.diamedio=1;
                    data.mesmedio++;
                    }
                    break;
                case 4:
                case 6:
                case 9:
                case 11:	
                    if (data.diamedio > 30){
                    data.diamedio=1;
                    data.mesmedio++;
                    }
                    break;
                case 2:
                    if (anobissexto){
                    if (data.diamedio > 29){
                    data.diamedio=1;
                    data.mesmedio++;
                    }
                    break;
                }else if (!anobissexto){
                    if (data.diamedio > 28){
                    data.diamedio=1;
                    data.mesmedio++;
                    }
                    break;
                }
            }
        }

    data.diamedio++;

    dialimite = (data.diamedio == data.diafinal);
    meslimite = (data.mesmedio == data.mesfinal);
    datalimite = (dialimite && meslimite);

    agenda = fopen("agenda", "a+b");
    fwrite(&data, sizeof(Datas),1,agenda);
    fclose(agenda);

    }while(not datalimite);

}

void leituraAgenda(){

	FILE *agenda, *feri;
    Feriado fer;
    Datas data;

    char facu[20]={0}, tipo[20]={0}, c, meses[13][15]={"zero", "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};

        feri = fopen("feriados", "r+b");
        agenda = fopen("agenda", "r+b");

        if (feri==NULL){
            printf("\nErro ao abrir arquivo da agenda!");
        }

        else{
            if (feri==NULL){
                printf("\nErro ao abrir arquivo de feriados, ou arquivo não existe.");
            }
            else{
                while((!feof(feri)) && (!feof(agenda))){
                fread(&fer,sizeof(Feriado),1,feri);
                switch(fer.tipo){
                        case 1:
                            strcpy(tipo,"Nacional");
                            break;
                        case 2:
                            strcpy(tipo,"Estadual");
                            break;
                        case 3:
                            strcpy(tipo,"Municipal");
                            break;
                        default:
                        break;
                }
                switch(fer.facultativo){
                        case 1:
                            strcpy(facu,"Facultativo");
                            break;
                        case 2:
                            strcpy(facu,"Não Facultativo");
                            break;
                        default:
                            break;
                }

                printf("\n%i de %s", data.diamedio, meses[data.mesmedio]);

                if ((data.diamedio == fer.dia) && (data.mesmedio == fer.mes))
                    printf(" == %s (%s e %s)", fer.nome, tipo, facu);

                }
            }
    }
}
float Hotel()
{
    char cidade[50];
    char hotel[50];
    float valorEstadia;
    int quantidade;

    printf("\n ==================== Hotel ====================\n\n");
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", cidade);
    printf("Digite o nome do hotel: ");
    scanf(" %[^\n]", hotel);
    printf("Digite o valor da estadia: ");
    scanf("%f", &valorEstadia);

    printf("Digite a quantidade de dias que você ficará hopedado: ");
    scanf("%d", &quantidade);

    float valorTotalHotel = valorEstadia * quantidade;

    printf("\n------------------------------------------------------\n\n");
    printf("\n ==================== Relatório da Estadia ====================\n");
    printf("\nCidade: %s\n", cidade);
    printf("Hotel: %s\n", hotel);
    printf("Valor da Diária: R$ %.2f\n", valorEstadia);
    printf("Quantidade de Vezes: %d\n", quantidade);
    printf("Valor Total: R$ %.2f\n", valorTotalHotel);

    return valorTotalHotel;
}

// Função para informar sobre a alimentação
float Alimentacao()
{
    char cidade[50];
    char refeicao[50];
    float valorRefeicao;
    int quantidade;

    printf("\n ==================== Alimentação ====================\n\n");
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", cidade);
    printf("Digite o valor que você pretende gastar com cada refeição: ");
    scanf("%f", &valorRefeicao);

    printf("Digite a quantidade de vezes que você irá comer nesse restaurante: ");
    scanf("%d", &quantidade);

    float valorTotalRefeicao = valorRefeicao * quantidade;

    printf("\n------------------------------------------------------\n\n");
    printf("\n ==================== Relatório da Alimentação ====================\n");
    printf("\nCidade: %s\n", cidade);
    printf("Valor da Refeição: R$ %.2f\n", valorRefeicao);
    printf("Quantidade de Vezes: %d\n", quantidade);
    printf("Valor Total: R$ %.2f\n", valorTotalRefeicao);

    return valorTotalRefeicao;
}

// Função para calcular o custo da gasolina
float calcularCustoGasolina()
{
    float distancia, consumo, precoGasolina;

    printf("\n\n==================== Carro ou Moto ====================\n");
    printf("Digite a distância da viagem (em km): ");
    scanf("%f", &distancia);
    printf("Digite o consumo médio de combustível do veículo (em km/l): ");
    scanf("%f", &consumo);
    printf("Digite o preço da gasolina (por litro): ");
    scanf("%f", &precoGasolina);

    if (distancia <= 0 || consumo <= 0 || precoGasolina <= 0){
        return -1; // Valor de retorno inválido para indicar entrada inválida
    }

    float totalGasolina = (distancia / consumo) * precoGasolina;

    return totalGasolina;
}

// Função para calcular o custo das passagens
float calcularCustoPassagens()
{
    float precoPassagem;
    int quantidadePassagens, quantidadePessoas;

    printf("\n\n==================== Avião ou Ônibus ====================\n");
    printf("Digite o preço da passagem: ");
    scanf("%f", &precoPassagem);

    if (precoPassagem <= 0)
    {
        return -1; // Valor de retorno inválido para indicar entrada inválida
    }

    printf("Digite a quantidade de pessoas: ");
    scanf("%d", &quantidadePessoas);

    if (quantidadePessoas <= 0)
    {
        return -1; // Valor de retorno inválido para indicar entrada inválida
    }

    printf("Digite quantas passagens você precisa para ir e para voltar: ");
    scanf("%d", &quantidadePassagens);

    if (quantidadePassagens <= 0)
    {
        return -1; // Valor de retorno inválido para indicar entrada inválida
    }

    float totalPassagens = precoPassagem * quantidadePessoas * quantidadePassagens;

    return totalPassagens;
}

// Função para calcular o custo estimado das passagens
float calcularCustoTransporte(){
    int escolha;
    do
    {
        printf(" ===== Selecione o tipo de transporte que você irá utilizar =====\n");
        printf("1. Voltar\n");
        printf("2. Carro/Moto\n");
        printf("3. Avião/Ônibus\n");
        printf("0. Sair\n");
        printf("========================================================\n\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);
        switch (escolha)
        {
        case 1:
            break;
        case 2:
        {
            float custoGasolina = calcularCustoGasolina();
            if (custoGasolina >= 0)
            {
                printf("O custo estimado da viagem de carro/moto será de R$ %.2f\n", custoGasolina);
                return (custoGasolina);
            }
            else
            {
                printf("Entrada inválida. Por favor, verifique os valores digitados.\n");
            }
            break;
        }
        case 3:
        {
            float custoPassagens = calcularCustoPassagens();
            if (custoPassagens >= 0)
            {
                printf("O custo estimado das passagens será de R$ %.2f\n", custoPassagens);
                return (custoPassagens);
            }
            else
            {
                printf("Entrada inválida. Por favor, verifique os valores digitados.\n");
            }
            break;
        }
        case 0:
                printf("\nSaindo...\n");
            break;

        default:
                printf("====================!!! OPÇÃO INVÁLIDA !!!====================\n");
                printf("\nPressione qualquer tecla para tentar novamente.\n");
                getchar();
            break;
        }
    } while (escolha != 0);
}

void cadastroVisita(int cidade){
    FILE *arqVisita;
    Visita vis;
    int n, x=0;

    CODIGOREPETIDO:

    arqVisita = fopen("visita","a+b");
    rewind(arqVisita);
    do{
    printf("\nDigite o que deseja cadastrar:\n1. Hotel\n2. Restaurante");
    printf("\n\nEscolha uma opção: ");
    scanf("%d", &n);
    switch(n){
        case 1:
            vis.tipo = n;
            vis.codCity = cidade;
            printf("\nDefina um código para o estabelecimento: ");
            scanf("%d", &x);
            
            while(!feof(arqVisita)){
                fread(&vis, sizeof(Visita),1,arqVisita);
                    if ((x == vis.codLugar) && (cidade == vis.codCity)){
                        printf("\nJá foi cadastrado um estabelecimento com esse código.");
                        fclose(arqVisita);
                        printf("\n\nPressione qualquer tecla para tentar novamente.\n");
            			getch();
            			system("cls");
                        goto CODIGOREPETIDO;
                    }
            }
            
            vis.codLugar = x;
            fflush(stdin);
            printf("\nDigite o nome do estabelecimento: ");
            gets(vis.nomeLugar);
            for (int i=0; i<3; i++){
                char preco[10];
                switch(i){
                    case 0:
                        strcpy(preco,"Baixo");
                        break;
                    case 1:
                        strcpy(preco,"Médio");
                        break;
                    case 2:
                        strcpy(preco,"Alto");
                        break;
                }
                printf("\nDigite o valor da opção de %s custo desse estabelecimento em R$: ", preco);
                scanf("%f", &vis.BMA);
            }
            fwrite(&vis, sizeof(Visita),1,arqVisita);
            break;
        case 2:
            vis.tipo = n;
            vis.codCity = cidade;
            printf("\nDefina um código para o estabelecimento: ");
            scanf("%d", &x);
            while(!feof(arqVisita)){
            fread(&vis, sizeof(Visita),1,arqVisita);
                if ((x == vis.codLugar) && (cidade == vis.codCity)){
                    printf("\nJá foi cadastrado um estabelecimento com esse código.");
                    fclose(arqVisita);
                    printf("\n\nPressione qualquer tecla para tentar novamente.\n");
            		getch();
            		system("cls");
                    goto CODIGOREPETIDO;
                }
            }
            vis.codLugar = x;
            fflush(stdin);
            printf("\nDigite o nome do estabelecimento: ");
            gets(vis.nomeLugar);
            for (int i=0; i<3; i++){
                char preco[10];
                switch(i){
                    case 0:
                        strcpy(preco,"Baixo");
                        break;
                    case 1:
                        strcpy(preco,"Médio");
                        break;
                    case 2:
                        strcpy(preco,"Alto");
                        break;
                }
                printf("\nDigite o valor da opção de %s custo desse estabelecimento em R$: ", preco);
                scanf("%f", &vis.BMA);
            }

            fwrite(&vis, sizeof(Visita),1,arqVisita);
            break;
        default:
            printf("====================!!! OPÇÃO INVÁLIDA !!!====================\n");
            printf("\n");
            printf("Pressione qualquer tecla para tentar novamente.\n");
            getch();
            break;
    }
    }while (n < 1 || n > 2);
    fclose(arqVisita);
}


int leituraCidade()
{
    int cidade;
    printf("\n\n=====================================\n");
    printf("| CÓDIGO |         NOME             |");
    printf("\n=====================================");
    printf("\n|   01   |      Caxias do Sul       |\n|   02   |      Farroupilha         |\n|   03   |      Bento Gonçalves     |\n|   04   |      Gramado             |\n|   05   |      Porto Alegre        |\n|   06   |      Nova Petrópolis     |\n|   07   |      Capão da Canoa      |\n|   08   |      Carlos Barbosa      |\n|   09   |      Garibaldi           |\n|   10   |    São Lourenço do Sul   |\n|   11   |      Rio Grande          |\n|   12   |      Tramandaí           |\n|   13   |      Santiago            |\n|   14   |      Cambará do Sul      |\n|   15   |      Bom Jesus           |\n|   16   |      Bom Princípio       |\n|   17   |      Pelotas             |\n|   18   |      Erechim             |\n|   19   |      Atlântida           |\n|   20   |  Sant'Ana do Livramento  |");
    printf("\n=====================================");
    printf("\n\nDigite seu destino:");
    scanf("%d", &cidade);
   return (cidade);
}

void cadastrarFeriados(){
FILE *arqFeriado;
Feriado cadastroFeriado;
int n, x, y, num, sair, tipoferiado;

arqFeriado = fopen("feriados","a+b");

    printf("Digite o ano atual:");
    scanf("%d", &y);
    bool anobissexto = ((y % 4 == 0)&&(y % 100 != 0));
    do{
        fflush(stdin);
        printf("\n1.JANEIRO\n2.FEVEREIRO\n3.MARÇO\n4.ABRIL\n5.MAIO\n6.JUNHO\n7.JULHO\n8.AGOSTO\n9.SETEMBRO\n10.OUTUBRO\n11.NOVEMBRO\n12.DEZEMBRO\nDigite o mês:");
        scanf("%d", &n);
        printf("\n");
        switch(n){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            cadastroFeriado.mes = n;
            do{
                printf("1  2  3  4  5  6\n7  8  9  10 11 12\n13 14 15 16 17 18\n19 20 21 22 23 24\n25 26 27 28 29 30 31\nDigite o dia:");
                scanf("%d", &cadastroFeriado.dia);
            }while (cadastroFeriado.dia <1 || cadastroFeriado.dia > 31);
                fflush(stdin);
                printf("Digite o nome do feriado:");
                gets(cadastroFeriado.nome);
                printf("\n1.Nacional\n2.Estadual\n3.Municipal\nDigite o tipo do feriado: ");
                scanf("%d", &cadastroFeriado.tipo);
                printf("\n1.Facultativo\n2.Não facultativo\nDigite se é facultativo ou não: ");
                scanf("%d", &cadastroFeriado.facultativo);
                fwrite(&cadastroFeriado, sizeof(Feriado),1,arqFeriado);

            break;
        case 2:
            cadastroFeriado.mes = n;
            if (anobissexto){
                do{
                printf("1  2  3  4  5  6\n7  8  9  10 11 12\n13 14 15 16 17 18\n19 20 21 22 23 24\n25 26 27 28 29\nDigite o dia:");
                scanf("%d", &cadastroFeriado.dia);
                }while (cadastroFeriado.dia<1 || cadastroFeriado.dia>29);
                fflush(stdin);
                printf("Digite o nome do feriado:");
                gets(cadastroFeriado.nome);
                printf("\n1.Nacional\n2.Estadual\n3.Municipal\nDigite o tipo do feriado: ");
                scanf("%d", &cadastroFeriado.tipo);
                printf("\n1.Facultativo\n2.Não facultativo\nDigite se é facultativo ou não: ");
                scanf("%d", &cadastroFeriado.facultativo);
                fwrite(&cadastroFeriado, sizeof(Feriado),1,arqFeriado);
            }
            else{
                do{
                printf("1  2  3  4  5  6\n7  8  9  10 11 12\n13 14 15 16 17 18\n19 20 21 22 23 24\n25 26 27 28\nDigite o dia:");
                scanf("%d", &cadastroFeriado.dia);
                }while (cadastroFeriado.dia<1 || cadastroFeriado.dia>28);
                fflush(stdin);
                printf("Digite o nome do feriado:");
                gets(cadastroFeriado.nome);
                printf("\n1.Nacional\n2.Estadual\n3.Municipal\nDigite o tipo do feriado: ");
                scanf("%d", &cadastroFeriado.tipo);
                printf("\n1.Facultativo\n2.Não facultativo\nDigite se é facultativo ou não: ");
                scanf("%d", &cadastroFeriado.facultativo);
                fwrite(&cadastroFeriado, sizeof(Feriado),1,arqFeriado);
            }

            break;
        case 4:
        case 6:
        case 9:
        case 11:
            cadastroFeriado.mes = n;
            do{
                printf("1  2  3  4  5  6\n7  8  9  10 11 12\n13 14 15 16 17 18\n19 20 21 22 23 24\n25 26 27 28 29 30\nDigite o dia:");
                scanf("%d", &cadastroFeriado.dia);
            }while (cadastroFeriado.dia<1 || cadastroFeriado.dia>30);
                fflush(stdin);
                printf("Digite o nome do feriado:");
                gets(cadastroFeriado.nome);
                printf("\n1.Nacional\n2.Estadual\n3.Municipal\nDigite o tipo do feriado: ");
                scanf("%d", &cadastroFeriado.tipo);
                printf("\n1.Facultativo\n2.Não facultativo\nDigite se é facultativo ou não: ");
                scanf("%d", &cadastroFeriado.facultativo);
                fwrite(&cadastroFeriado, sizeof(Feriado),1,arqFeriado);

            break;
        default:
            printf("\nData inválida!");
            printf("\n");
            printf("Pressione qualquer tecla para tentar novamente.\n");
            getch();
            break;
        }
    }while (n<1 || n>12);
fclose(arqFeriado);
}

void leituraFeriados(){
    FILE *arqFeriado;
    Feriado cadastroFeriado;
    char facu[20]={0}, tipo[20]={0}, meses[13][15]={"zero", "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    int EOF_ctrl;

    arqFeriado = fopen("feriados", "r+b");
    if (arqFeriado==NULL){
        printf("\nErro ao abrir arquivo de feriados!");
    }
    else{
        printf("============== LEITURA DE FERIADOS ==============");
        printf("\n\nEstes são os feriados cadastrados.");
        printf("\n\n=====================================================================================\n");
        printf("|         NOME             |   TIPO        |   FACULTATIVO        |   DIA  |   MÊS  ");
        printf("\n=====================================================================================");
        while(!feof(arqFeriado)){
            fread(&cadastroFeriado,sizeof(Feriado),1,arqFeriado);
            switch(cadastroFeriado.facultativo){
                case 1:
                    strcpy(facu,"Facultativo");
                    break;
                case 2:
                    strcpy(facu,"Não Facultativo");
                    break;
                default:
                    printf("\n        !!ERRO!!        \nEste feriado (%-22s) não foi definido se é facultativo ou não", cadastroFeriado.nome);
                    printf("\n");
                    printf("Pressione qualquer tecla para continuar.\n");
                    getch();
            }
            switch(cadastroFeriado.tipo){
                case 1:
                    strcpy(tipo,"Nacional");
                    break;
                case 2:
                    strcpy(tipo,"Estadual");
                    break;
                case 3:
                    strcpy(tipo,"Municipal");
                    break;
                default:
                    printf("\n        !!ERRO!!        \nEste feriado (%-22s) não foi definido se é nacional, estadual ou municipal", cadastroFeriado.nome);
                    printf("\n");
                    printf("Pressione qualquer tecla para continuar.\n");
                    getch();
                    break;
            }
            EOF_ctrl = fread(&cadastroFeriado,sizeof(Feriado),1,arqFeriado);
            if (ferror(arqFeriado)){
                printf("\nErro na leitura do arquivo.");
                getch();
                return;
            }
            else{
                
                 printf("\n| %-22s   |   %-10s  |   %-15s    |  %-5d |  %-15s ", cadastroFeriado.nome, tipo, facu, cadastroFeriado.dia, meses[cadastroFeriado.mes]);
                
            }
        }
        printf("\n=====================================================================================");
    }
    fclose(arqFeriado);
}

void menuFeriados()
{
    int x;
    do
    {
        system("cls");
        printf("\n\n==================== MENU FERIADOS ====================\n");
        printf("0. Voltar ao menu principal\n");
        printf("1. Cadastrar novo feriado\n");
        printf("2. Visualizar os feriados cadastrados\n");
        printf("========================================================\n\n");
        printf("Escolha uma opção: ");
        scanf("%d", &x);
        system("cls");
        switch (x)
        {
        case 0:
            return;
            break;
        case 1:
            cadastrarFeriados();
            break;
        case 2:
            leituraFeriados();
            break;
        default:
            printf("====================!!! OPÇÃO INVÁLIDA !!!====================\n");
            printf("\n");
            printf("Pressione qualquer tecla para tentar novamente.\n");
            getch();
            break;
        }
    } while (x < 0 || x > 2);
}

// Função para exibir o relatório final com os valores selecionados
void exibirRelatorio(float valorHoteis, float valorRestaurantes, float valorTransporte)
{
    printf("\n=== Relatorio Final da sua Viagem ===\n");
    //printf("Cidade: %s\n", cidade);
    printf("Valor total dos Hoteis: R$ %.2f\n", valorHoteis);
    printf("Valor total dos Restaurantes: R$ %.2f\n", valorRestaurantes);
    printf("Valor total do Transporte: R$ %.2f\n", valorTransporte);
    // Calcular e exibir o valor total da viagem (pode incluir outros cálculos, como transporte)
    float valorTotal = valorHoteis + valorRestaurantes + valorTransporte;
    printf("Valor total da Viagem: R$ %.2f\n", valorTotal);
}

int exibirMenu(int cidade, char Scidade[25]){
    if(cidade==0){
        printf("\n  ===============================================");
        printf("\n  | Por enquanto nenhuma cidade foi selecionada |");
        printf("\n  ===============================================");
    }
    else{
        printf("\n  =====================================================");
        printf("\n   Cidade selecionada ---> %i. %-26s ", cidade, Scidade);
        printf("\n  =====================================================");
    }
    printf("\n\n==================== MENU PRINCIPAL ====================\n");
    printf("1. Informar o orçamento\n");
    printf("2. Selecionar uma cidade como destino\n");
    printf("3. Visualizar opções em relação às feriados\n");
    printf("4. Cadastrar um local de visita\n");
    printf("5. Visualizar opções em relação aos restaurantes\n");
    printf("6. Visualizar opções em relação ao meio de transporte da viagem\n");
    printf("7. Gerar relatório de viagem\n");
    printf("8. Informar início e termino da viagem\n");
    printf("0. Sair\n");
    printf("========================================================\n\n");
    printf("Escolha uma opção: ");
    int n;
    scanf("%d", &n);
    return (n);
}

int main()
{
    // Somente para o VScode
    // Define o valor das páginas de código UTF8 e default do Windows
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();

    // Define codificação como sendo UTF-8
    SetConsoleOutputCP(CPAGE_UTF8);

    // Somente para o Dev C++
   // setlocale(LC_ALL, "Portuguese");

    float totalHotel, totalAlimento, totalTransporte;
    int opcao, cidade=0;
    char Scidade[25];

    do
    {
        fflush(stdin);
        opcao = exibirMenu(cidade, Scidade);

        switch (opcao)
        {
        case 0:
            printf("\nSaíndo...\n");
            break;
        case 1:
                //informarOrçamento
            break;
        case 2:
            cidade = leituraCidade();
            switch(cidade){     //Este switch converte o código da cidade, que o usuário selecionou, para uma string com o nome da cidade
                    case 1:
                        strcpy(Scidade,"Caxias do Sul");
                        break;
                    case 2:
                        strcpy(Scidade,"Farroupilha");
                        break;
                    case 3:
                        strcpy(Scidade,"Bento Gonçalves");
                        break;
                    case 4:
                        strcpy(Scidade,"Gramado");
                        break;
                    case 5:
                        strcpy(Scidade,"Porto Alegre");
                        break;
                    case 6:
                        strcpy(Scidade,"Nova Petrópolis");
                        break;
                    case 7:
                        strcpy(Scidade,"Capão da Canoa");
                        break;
                    case 8:
                        strcpy(Scidade,"Carlos Barbosa");
                        break;
                    case 9:
                        strcpy(Scidade,"Garibaldi");
                        break;
                    case 10:
                        strcpy(Scidade,"São Lourenço do Sul");
                        break;
                    case 11:
                        strcpy(Scidade,"Rio Grande");
                        break;
                    case 12:
                        strcpy(Scidade,"Tramandaí");
                        break;
                    case 13:
                        strcpy(Scidade,"Santiago");
                        break;
                    case 14:
                        strcpy(Scidade,"Cambará do Sul");
                        break;
                    case 15:
                        strcpy(Scidade,"Bom Jesus");
                        break;
                    case 16:
                        strcpy(Scidade,"Bom Princípio");
                        break;
                    case 17:
                        strcpy(Scidade,"Pelotas");
                        break;
                    case 18:
                        strcpy(Scidade,"Erechim");
                        break;
                    case 19:
                        strcpy(Scidade,"Atlântida");
                        break;
                    case 20:
                        strcpy(Scidade,"Sant'Ana do Livramento");
                        break;
                    default:
                        printf("====================!!! OPÇÃO INVÁLIDA !!!====================\n");
                        printf("\n");
                        printf("Pressione qualquer tecla para tentar novamente.\n");
                        getch();
                        break;
                }
               //printf("%s", Scidade);
            system("cls");
            break;
        case 3:
            menuFeriados();
            break;
        case 4:
            //totalHotel = Hotel();
            if (cidade==0){
                printf("\nPrimeiro selecione uma cidade da listagem.");
                printf("\n");
                printf("\nPressione qualquer tecla para continuar.\n");
                getch();
                system("cls");
            }
            else{
                cadastroVisita(cidade);
            }
            break;
        case 5:
            totalAlimento = Alimentacao();
            break;
        case 6:
            totalTransporte = calcularCustoTransporte();
            break;
        case 7:
            exibirRelatorio(totalHotel, totalAlimento, totalTransporte);
            break;
        case 8:
        	cadastroAgenda();
        	break;
        default:
            printf("====================!!! OPÇÃO INVÁLIDA !!!====================\n");
            printf("\n");
            printf("Pressione qualquer tecla para tentar novamente.\n");
            getch();
            break;
        }
    } while (opcao != 0);
    return 0;
}
