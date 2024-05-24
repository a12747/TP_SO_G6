#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "funcoes.h"

int main() {
    int opcao;
    char ficheiro[FICHEIRO_SIZE];
    char ficheiroSaida[FICHEIRO_SIZE];
    char diretoria[FICHEIRO_SIZE];

    // Menu com as opções
    write_string("Escolha uma opcao:\n");
    write_string("1 - Mostrar ficheiro\n");
    write_string("2 - Copiar ficheiro\n");
    write_string("3 - Acrescentar ficheiro\n");
    write_string("4 - Contar linhas do ficheiro\n");
    write_string("5 - Remover ficheiro\n");
    write_string("6 - Informar dados do ficheiro\n");
    write_string("7 - Listar diretoria\n");
    read_int(&opcao);

    switch (opcao) {
        case 1:
            write_string("Nome ficheiro: ");
            read_string(ficheiro, FICHEIRO_SIZE);
            mostraFicheiro(ficheiro);
            break;

        case 2:
            write_string("Nome ficheiro: ");
            read_string(ficheiro, FICHEIRO_SIZE);
            copiaFicheiro(ficheiro);
            break;

        case 3:
            write_string("Nome ficheiro de entrada: ");
            read_string(ficheiro, FICHEIRO_SIZE);
            write_string("Nome ficheiro de saida: ");
            read_string(ficheiroSaida, FICHEIRO_SIZE);

            acrescentaFicheiro(ficheiro, ficheiroSaida);
            break;

        case 4:
            write_string("Nome ficheiro: ");
            read_string(ficheiro, FICHEIRO_SIZE);
            contaFicheiro(ficheiro);
            break;

        case 5:
            write_string("Nome ficheiro: ");
            read_string(ficheiro, FICHEIRO_SIZE);
            removeFicheiro(ficheiro);
            break;

        case 6:
            write_string("Nome ficheiro: ");
            read_string(ficheiro, FICHEIRO_SIZE);
            informaFicheiro(ficheiro);
            break;

        case 7:
        {
            write_string("Nome da diretoria: ");
            read_string(diretoria, FICHEIRO_SIZE);
            listaDiretoria(diretoria);
            break;
        }
            
        default:
            write_string("Opcao invalida! Pressione qualquer tecla para continuar\n");
            while (getchar() != '\n');
            getchar();
            break;
    }
    return 0;
}