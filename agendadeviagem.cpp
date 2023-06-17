#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Estrutura para representar um destino de viagem
typedef struct {
    char nome[50];
    float precoHotel;
    float precoRestaurante;
} Destino;

// Estrutura para representar um feriado
struct Feriado {
    char data[11];
    char nome[50];
    char regioes[100];
};


// Função para exibir o menu principal
void exibirMenu() {
    printf("==================== MENU PRINCIPAL ====================\n");
    printf("1. Visualizar feriados no Rio Grande do Sul por estados\n");
    printf("2. Adicionar destino de viagem\n");
    printf("3. Obter informa��es sobre hot�is e restaurantes\n");
    printf("4. Calcular custos de transporte\n");
    printf("5. Gerar relat�rio de viagem\n");
    printf("0. Sair\n");
    printf("========================================================\n\n");
    printf("Escolha uma op��o: ");
}

// Função para visualizar feriados por estados
void visualizarFeriados() {

}
  

// Função para adicionar um destino de viagem
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

// Função para obter informa��es de hot�is e restaurantes
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

// Função para calcular custos de transporte
void calcularCustosTransporte() {
   
}

// Função para gerar relat�rio de viagem
void gerarRelatorio(Destino destinos[], int numDestinos) {

}

int main() {
	setlocale(0, "portuguese");
    Destino destinos[10];
    int numDestinos = 0;
    int opcao;

    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                printf("Saindo...\n");
                break;
            case 1:
                visualizarFeriados();
                break;
            case 2:
                adicionarDestino(destinos, &numDestinos);
                break;
            case 3:
                obterInformacoes(destinos, numDestinos);
                break;
            case 4:
                calcularCustosTransporte();
                break;
            case 5:
                gerarRelatorio(destinos, numDestinos);
                break;
            default:
                printf("Op��o inv�lida.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}

