#include "header.h"
void mostraFicheiro(const char *ficheiro) {
    // Abre o ficheiro para leitura
    int fd = open(ficheiro, O_RDONLY);
    if (fd == -1) {
        perror("Erro");
        return;
    }

    // Lê e mostra todo o conteúdo do ficheiro no ecrã
    char buffer[BUFFER_SIZE];
    ssize_t bytes_lidos;
    while ((bytes_lidos = read(fd, buffer, BUFFER_SIZE)) > 0) {
        if (write(STDOUT_FILENO, buffer, bytes_lidos) != bytes_lidos) {
            write_string("Erro ao escrever no ecra.\n");
            close(fd);
            return;
        }
    }

    // Verifica se houve um erro na leitura
    if (bytes_lidos == -1) {
        write_string("Erro ao ler o ficheiro.\n");
    }

    // Fecha o ficheiro
    close(fd);
}