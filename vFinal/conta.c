#include "header.h"
void contaFicheiro(const char *ficheiro) {
    // Abre o ficheiro para leitura
    int fd = open(ficheiro, O_RDONLY);
    if (fd == -1) {
        perror("Erro");
        return;
    }

    int num_linhas = 0;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_lidos;
    char *nl_ptr;

    // Lê o ficheiro e conta o número de linhas
    while ((bytes_lidos = read(fd, buffer, BUFFER_SIZE)) > 0) {
        nl_ptr = buffer;
        while ((nl_ptr = strchr(nl_ptr, '\n')) != NULL) {
            num_linhas++;
            nl_ptr++; // Avança para o próximo caracter depois do '\n'
        }
    }

    if (bytes_lidos == -1) {
        write_string("Erro ao ler o ficheiro.\n");
        close(fd);
    }

    // Fecha o ficheiro
    close(fd);
    char print[BUFFER_SIZE];
    snprintf(print, sizeof(print), "Linhas do ficheiro: %d\n", num_linhas);
    write_string(print);

}