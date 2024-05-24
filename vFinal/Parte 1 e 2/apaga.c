#include "header.h"
void removeFicheiro(const char *ficheiro) {
    // Tenta apagar o ficheiro
    if (unlink(ficheiro) == -1) {
        write_string("Erro: o ficheiro nao pode ser apagado ou nao existe.\n");
        return;
    }

    write_string("Ficheiro apagado com sucesso.\n");
}