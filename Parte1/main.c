#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"


int main(){
    int opcao;
    char ficheiro[50];
    
    // Menu com as opções
    printf("Escolha uma opcao:\n"); 
    printf("1 - Mostrar ficheiro\n");
    printf("2 - Copiar ficheiro\n");
    printf("3 - Acrescentar ficheiro\n");
    printf("4 - Contar linhas do ficheiro\n");
    printf("5 - Remover ficheiro\n");
    printf("6 - Informar dados do ficheiro\n");
    printf("7 - Listar diretoria\n");
    scanf("%d", &opcao);

    switch(opcao){
        case 1:
            printf("Nome ficheiro: ");
            scanf("%s", ficheiro);

            mostraFicheiro(ficheiro);
            break;

        case 2:
            printf("Nome ficheiro: ");
            scanf("%s", ficheiro);

            copiaFicheiro(ficheiro);
            break;

        case 3:
            char ficheiroSaida[50];
            
            printf("Nome ficheiro de entrada: ");
            scanf("%s", ficheiro);
            printf("Nome ficheiro de saida: ");
            scanf("%s", ficheiroSaida);	
            
            acrescentaFicheiro(ficheiro, ficheiroSaida);
            break;

        case 4:
            printf("Nome ficheiro: ");
            scanf("%s", ficheiro);
            
            int numeroLinhas = contaFicheiro(ficheiro);
            
            printf("O ficheiro %s tem %d linhas.\n", ficheiro, numeroLinhas);
            break;

        case 5:
            printf("Nome ficheiro: ");
            scanf("%s", ficheiro);
            
            removeFicheiro(ficheiro);
            break;

        case 6:
            printf("Nome ficheiro: ");
            scanf("%s", ficheiro);

            informaFicheiro(ficheiro);
            break;

        case 7:
            char diretoria[50];
            
            printf("Nome da diretoria: ");
            scanf("%s", diretoria);
            
            lista(diretoria);
            break;

        default:
            printf("Opcao invalida! Pressione qualquer tecla para continuar\n");
            while(getchar() != '\n');
            getchar();
            break;
    }
    return 0;
}