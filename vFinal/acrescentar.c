#include "header.h"
void acrescentaFicheiro(const char *origem, const char *destino) {
    // Abre o ficheiro de origem para leitura
    int fd_origem = open(origem, O_RDONLY);
    if (fd_origem == -1) {
        perror("Erro");
        return;
    }

    // Abre o ficheiro de destino para escrita, com a flag O_APPEND para acrescentar no final
    int fd_destino = open(destino, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (fd_destino == -1) {
        write_string("Erro: o ficheiro de destino nao pode ser aberto para escrita.\n");
        close(fd_origem);
        return;
    }

    // Copia o conteúdo do ficheiro de origem para o ficheiro de destino
    char buffer[BUFFER_SIZE];
    ssize_t bytes_lidos;
    while ((bytes_lidos = read(fd_origem, buffer, BUFFER_SIZE)) > 0) {
        if (write(fd_destino, buffer, bytes_lidos) != bytes_lidos) {
            write_string("Erro ao escrever no ficheiro de destino.\n");
            close(fd_origem);
            close(fd_destino);
            return;
        }
    }

    // Verifica se houve um erro na leitura do ficheiro de origem
    if (bytes_lidos == -1) {
        write_string("Erro ao ler o ficheiro de origem.\n");
    }

    // Fecha os descritores de ficheiros
    close(fd_origem);
    close(fd_destino);

    write_string("Conteudo da origem acrescentado ao destino com sucesso.\n");
}