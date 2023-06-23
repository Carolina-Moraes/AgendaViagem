#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

//Ol� carol

// Estrutura para representar uma cidade
typedef struct {
    int codcity;        // C�digo da cidade, serve pra ver todos os lugares de uma mesma cidade
    char nomecity[50];  // Nome
} Cidade;

//struct para ponto de visita
typedef struct{
    int tipo;           // 1 hotel, 2 restaurante
    int codcity;        // C�digo da cidade na qual o lugar est�, deve ser o mesmo c�digo da struct cidade
    int lugar;          // C�digo para o hotel ou restaurante, ainda n�o sei se vai ser necess�rio isso
    char nomelugar[50]; // Nome do lugar
    int tipopreco;      // Tipo do pre�o: 1 baixo, 2 medio, 3 alto
    float preco;        // O pre�o em si

}Visita;

// Estrutura para representar um destino de viagem
typedef struct {
    char nome[50];
    float precoHotel;
    float precoRestaurante;
} Destino;

//struct para hotel
typedef struct{
    char nome[50];
    float precodiaria;
}hotel;

//struct para restaurante
typedef struct{
    char nome[50];
    float precomedio;
}restaurante;

// Estrutura para representar um feriado
typedef struct {
    int dia;
    int mes;
    char nome[50];
    int tipo;
    int facultativo;
}Feriado;


// Fun��o para cadastrar feriados por estados
void cadastroFeriados() {

    /*
    CADASTRO:
  	char mes[25]={0}, dia[2]={0}, separador[5]={" de "}, resp;
	fflush(stdin);
	printf("Deseja cadastrar um feriado? (s/n)");
	scanf("%c", &resp);
	resp = tolower(resp);
	if (resp == 's'){
		fflush(stdin);
  		printf("\nDigite o mes que deseja cadastrar o feriado: ");
  		gets(mes);
  		fflush(stdin);
  		printf("\nDigite o dia que deseja cadastrar o feriado: ");
  		gets(dia);
  		strcat(dia, separador);
  		strcat(dia, mes); 
  		puts(dia);
  		goto CADASTRO;
	}*/
}


// Fun��o para adicionar um destino de viagem
void adicionarDestino(Destino destinos[], int *numDestinos) {
    if (*numDestinos >= 10) {
        printf("Limite m�ximo de destinos alcan�ado.\n");
        return;
    }

    Destino novoDestino;

    printf("Informe o nome do destino: ");
    scanf("%s", novoDestino.nome);

    printf("Informe o pre�o m�dio do hotel: ");
    scanf("%f", &novoDestino.precoHotel);

    printf("Informe o pre�o m�dio do restaurante: ");
    scanf("%f", &novoDestino.precoRestaurante);

    destinos[*numDestinos] = novoDestino;
    (*numDestinos)++;

    printf("Destino adicionado com sucesso!\n");
}

// Fun��o para obter informa??es de hot?is e restaurantes
void obterInformacoes(Destino destinos[], int numDestinos) {
    if (numDestinos == 0) {
        printf("Nenhum destino adicionado ainda.\n");
        return;
    }

    printf("===== DESTINOS DE VIAGEM =====\n");

    for (int i = 0; i < numDestinos; i++) {
        printf("%d. %s\n", i + 1, destinos[i].nome);
    }

    printf("==============================\n");
    printf("Escolha um destino: ");

    int escolha;
    scanf("%d", &escolha);

    if (escolha < 1 || escolha > numDestinos) {
        printf("Destino inv�lido.\n");
        return;
    }

    Destino destinoEscolhido = destinos[escolha - 1];

    printf("Nome: %s\n", destinoEscolhido.nome);
    printf("Pre�o m�dio do hotel: %.2f\n", destinoEscolhido.precoHotel);
    printf("Pre�o m�dio do restaurante: %.2f\n", destinoEscolhido.precoRestaurante);
}

// Fun��o para calcular custos de transporte
void calcularCustosTransporte() {
   
}

// Fun��o para gerar relat?rio de viagem
void gerarRelatorio(Destino destinos[], int numDestinos) {

}


void cadastroCidade(){
    FILE *arqCidade;
    Cidade *cid;
    int n, i;

    fflush(stdin);
    printf("\nDigite quantas cidades vai cadastrar dessa vez: ");
    scanf("%d", &n);

    cid = (Cidade*)calloc(n, sizeof(Cidade)); // O calloc aloca na mem�ria o tamanho em bytes do conteudo da struct
    arqCidade = fopen("cidades.txt","a");     // e usa esse tamanho para definir come�o e fim para cada linha dentro do txt;
    
    for (i=0; i<n; i++){
        fflush(stdin);
        printf("\nDefina o c�digo da cidade que vai cadastrar, %d� posi��o: ", i+1);
        scanf("%d", &cid[i]);
        fflush(stdin);
        printf("\nDigite o nome da cidade que vai cadastrar (sem acentos), %d� posi��o: ", i+1);
        scanf("%[^\n]s", cid[i].nomecity);
        fwrite(&cid[i],sizeof(Cidade),1,arqCidade);
    }
    fclose(arqCidade);
    free(cid); //para liberar o espa�o da mem�ria usado pela variavel "cid"
}

void leituraCidade(){
    Cidade cid1;
    FILE *arqCid;
    arqCid = fopen("cidades.txt","r");
    if (arqCid==NULL)
     {
                   printf("Erro ao abrir arquivo\n");
                   getch();
                   return;
     }
    printf("\n=====================================\n");
    printf("| C�DIGO |         NOME             |");
    printf("\n=====================================");
    while(fread(&cid1,sizeof(Cidade),1,arqCid)){ //o while ser� verdadeiro enquanto tiver conte�do no txt;
        printf("\n|  %-5d | %-22s   |", cid1.codcity,cid1.nomecity); // O -5 e o -22 � pra tirar os espa�os em branco
    }                                                                // que fica no txt, por que ele grava at� bytes
    printf("\n=====================================\n");             // em branco;
    fclose(arqCid);
}

void menuCidades(){
    int x;
    do{
        system("cls");
        printf("\n\n==================== MENU CIDADES ====================\n");
        printf("1. Voltar ao menu principal\n");
        printf("2. Cadastrar nova cidade\n");
        printf("3. Visualizar cidades cadastradas\n");
        printf("4. \n");
        printf("5. \n");
        printf("========================================================\n\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &x);
        system("cls");
        switch (x) {
                case 1:
                    return;
                    break;
                case 2:
                    cadastroCidade();
                    break;
                case 3:
                    leituraCidade();
                    break;
                case 4:

                    break;
                case 5:

                    break;
                default:
                    printf("====================!!! OP��O INV�LIDA !!!====================\n");
                    printf("\n");
                    printf("Pressione qualquer tecla para tentar novamente.\n");
                    getch();
                    break;
        }
    }while(x<1 || x>5);
}

void cadastrarFeriados(){
FILE *arqFeriado;
Feriado cadastroFeriado;
int n, x, y, num, sair, tipoferiado;

//fflush(stdin);
//printf("\nDigite quantos feriados vai cadastrar dessa vez: ");
//scanf("%d", &num);

//cadastroFeriado = (Feriado*)calloc(num, sizeof(Feriado));
arqFeriado = fopen("feriados.txt","a");



    printf("\n1.Cadastrar\n2.Voltar ao menu\n");
    scanf("%d", &sair);
    if (sair==1){
        printf("Digite o ano atual:");
        scanf("%d", &y);
        bool anobissexto = ((y % 4 == 0)&&(y % 100 != 0));
        do{
            fflush(stdin);
            printf("\n1.JANEIRO\n2.FEVEREIRO\n3.MAR�O\n4.ABRIL\n5.MAIO\n6.JUNHO\n7.JULHO\n8.AGOSTO\n9.SETEMBRO\n10.OUTUBRO\n11.NOVEMBRO\n12.DEZEMBRO\nDigite o m�s:");
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
                    fflush(stdin);
                    printf("Digite o nome do feriado:");
                    gets(cadastroFeriado.nome);
                    fflush(stdin);
                    printf("\n1.Nacional\n2.Estadual\n3.Municipal\nDigite o tipo do feriado: ");
                    scanf("%d", &cadastroFeriado.tipo);
                    fflush(stdin);
                    printf("\n1.Facultativo\n2.N�o facultativo\nDigite se � facultativo ou n�o: ");
                    scanf("%d", &cadastroFeriado.facultativo);
                    fprintf(arqFeriado,"%d, %d, %s, %d\n", cadastroFeriado.mes, cadastroFeriado.dia, cadastroFeriado.nome, cadastroFeriado.tipo);
                    fflush(stdin);
                }while (x<1 || x>31);

                break;
            case 2:
                cadastroFeriado.mes = n;
                if (anobissexto){
                    do{
                    printf("1  2  3  4  5  6\n7  8  9  10 11 12\n13 14 15 16 17 18\n19 20 21 22 23 24\n25 26 27 28 29\nDigite o dia:");
                    scanf("%d", &x);
                    }while (x<1 || x>29);
                }
                else{
                    do{
                    printf("1  2  3  4  5  6\n7  8  9  10 11 12\n13 14 15 16 17 18\n19 20 21 22 23 24\n25 26 27 28\nDigite o dia:");
                    scanf("%d", &x);
                    }while (x<1 || x>28);
                }

                break;
            case 4:
            case 6:
            case 9:
            case 11:
                cadastroFeriado.mes = n;
                do{
                    printf("1  2  3  4  5  6\n7  8  9  10 11 12\n13 14 15 16 17 18\n19 20 21 22 23 24\n25 26 27 28 29 30\nDigite o dia:");
                    scanf("%d", &x);
                }while (x<1 || x>30);

                break;
            default:
                printf("\nData inv�lida!");
                printf("\n");
                printf("Pressione qualquer tecla para tentar novamente.\n");
                getch();
                break;
            }
        }while (n<1 || n>12);
    }
    else if (sair==2){
        return;
        fclose(arqFeriado);
    }
    else{
    printf("\nOp��o inv�lida. Mas ir� voltar ao menu mesmo assim.\n");
    printf("\n");
    printf("Pressione qualquer tecla para continuar.\n");
    getch();
    }
fclose(arqFeriado);

}

void menuFeriados(){
int x;
    do{
        system("cls");
        printf("\n\n==================== MENU FERIADOS ====================\n");
        printf("1. Voltar ao menu principal\n");
        printf("2. Cadastrar novo feriado\n");
        printf("3. Visualizar os feriados cadastrados\n");
        printf("4. \n");
        printf("5. \n");
        printf("========================================================\n\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &x);
        system("cls");
        switch (x) {
                case 1:
                    return;
                    break;
                case 2:
                    cadastrarFeriados();
                    break;
                case 3:
                    
                    break;
                case 4:

                    break;
                case 5:

                    break;
                default:
                    printf("====================!!! OP��O INV�LIDA !!!====================\n");
                    printf("\n");
                    printf("Pressione qualquer tecla para tentar novamente.\n");
                    getch();
                    break;
        }
    }while(x<1 || x>5);
}

// Fun��o para exibir o menu principal
int exibirMenu() {
    printf("\n\n==================== MENU PRINCIPAL ====================\n");
    printf("1. Informar o or�amento\n");
    printf("2. Visualizar op��es em rela��o �s cidades\n");
    printf("3. Visualizar op��es em rela��o �s feriados\n");
    printf("4. Visualizar op��es em rela��o �s hot�is e restaurantes\n");
    printf("5. \n");
    printf("6. \n");
    printf("7. \n");
    printf("8.\n");
    printf("9.\n");
    printf("10.\n");
    printf("11. Calcular custos de transporte\n");
    printf("12. Gerar relat�rio de viagem\n");
    printf("0. Sair\n");
    printf("========================================================\n\n");
    printf("Escolha uma op��o: ");
    int n;
    scanf("%d", &n);
    return(n);
}

int main() {
	setlocale(LC_ALL,"portuguese");
    Destino destinos[10];
    int numDestinos = 0;
    int opcao;

    do {
        fflush(stdin);
        opcao = exibirMenu();

        switch (opcao) {
            case 0:
                printf("\nSaindo...\n");
                break;
            case 1:
                
                break;
            case 2:
                menuCidades();
                break;
            case 3:
                menuFeriados();
                break;
            case 4:
                
                break;
            case 5:
                
                break;
            case 6:
                
                break;
            case 7:
                
                break;
            case 8:
                
                break;
            case 9:
                
                break;
            case 10:
                
                break;
            case 11:
                
                break;
            case 12:
                
                break;
            default:
                printf("====================!!! OP��O INV�LIDA !!!====================\n");
                printf("\n");
                printf("Pressione qualquer tecla para tentar novamente.\n");
                getch();
                break;
        }
    } while (opcao != 0);
    return 0;
}

