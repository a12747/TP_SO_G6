#include "header.h"
void copiaFicheiro(const char *nome_origem) {
    // Abre o ficheiro original para leitura
    int fd_origem = open(nome_origem, O_RDONLY);
    if (fd_origem == -1) {
        write_string("Erro: o ficheiro de origem nao pode ser aberto para leitura.\n");
        return;
    }

    // Abre o ficheiro de cópia para escrita
   char nomeCopia[BUFFER_SIZE];
   	snprintf(nomeCopia,BUFFER_SIZE,"%s.copia",nome_origem);
    int fd_copia = open(nomeCopia, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd_copia == -1) {
        write_string("Erro ao criar o ficheiro de copia.\n");
        close(fd_origem);
        return;
    }

    // Copia o conteúdo do ficheiro original para o ficheiro de cópia
    char buffer[BUFFER_SIZE];
    ssize_t bytes_lidos;
    while ((bytes_lidos = read(fd_origem, buffer, BUFFER_SIZE)) > 0) {
        if (write(fd_copia, buffer, bytes_lidos) != bytes_lidos) {
            write_string("Erro ao escrever no ficheiro de copia.\n");
            close(fd_origem);
            close(fd_copia);
            return;
        }
    }

    // Fecha os descritores de ficheiros
    close(fd_origem);
    close(fd_copia);

    write_string("Copia do ficheiro criada com sucesso como ficheiro.copia\n");
}