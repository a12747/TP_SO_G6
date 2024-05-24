#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>
#include <dirent.h>
#include <pwd.h>


// Funções Auxiliares
void display_prompt() {
    const char *prompt = "%\n ";
    write(STDOUT_FILENO, prompt, strlen(prompt));
}

void write_string(const char *str) {
    write(1, str, strlen(str));
}

void read_string(char *buffer, size_t size) {
    ssize_t bytesRead = read(0, buffer, size - 1);
    if (bytesRead > 0) {
        buffer[bytesRead - 1] = '\0';
    }
}

void read_int(int *number) {
    char buffer[BUFFER_SIZE];
    read_string(buffer, BUFFER_SIZE);
    *number = atoi(buffer);
}

// =============


// Açõoes

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

    write_string("Copia do ficheiro criada com sucesso como 'NomeOrigem'.copia\n");
}

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

void removeFicheiro(const char *ficheiro) {
    // Tenta apagar o ficheiro
    if (unlink(ficheiro) == -1) {
        write_string("Erro: o ficheiro nao pode ser apagado ou nao existe.\n");
        return;
    }

    write_string("Ficheiro apagado com sucesso.\n");
}

void informaFicheiro(const char *ficheiro) {
    struct stat info;
    if (stat(ficheiro, &info) == -1) {
        write_string("Erro: nao foi possivel obter informacoes do ficheiro.\n");
        return;
    }

    // Tipo de ficheiro
    write_string("Tipo: ");
    if (S_ISREG(info.st_mode))
        write_string("Ficheiro regular\n");
    else if (S_ISDIR(info.st_mode))
        write_string("Diretoria\n");
    else if (S_ISLNK(info.st_mode))
        write_string("Link simbolico\n");
    else if (S_ISCHR(info.st_mode))
        write_string("Dispositivo de caracteres\n");
    else if (S_ISBLK(info.st_mode))
        write_string("Dispositivo de blocos\n");
    else if (S_ISFIFO(info.st_mode))
        write_string("FIFO/pipe\n");
    else if (S_ISSOCK(info.st_mode))
        write_string("Socket\n");
    else
        write_string("Desconhecido\n");

    // I-node
    char inode_str[20];
    snprintf(inode_str, sizeof(inode_str), "I-node: %lu\n", (unsigned long)info.st_ino);
    write_string(inode_str);

    // Utilizador dono
    struct passwd *pwd = getpwuid(info.st_uid);
    if (pwd != NULL) {
        char owner_str[50];
        snprintf(owner_str, sizeof(owner_str), "Dono: %s\n", pwd->pw_name);
        write_string(owner_str);
    }

    // Data de criação
    char ctime_str[100];
    strftime(ctime_str, sizeof(ctime_str), "Data de criacao: %c\n", localtime(&info.st_ctime));
    write_string(ctime_str);

    // Data de última leitura
    char atime_str[100];
    strftime(atime_str, sizeof(atime_str), "Data de ultima leitura: %c\n", localtime(&info.st_atime));
    write_string(atime_str);

    // Data de última modificação
    char mtime_str[100];
    strftime(mtime_str, sizeof(mtime_str), "Data de ultima modificacao: %c\n", localtime(&info.st_mtime));
    write_string(mtime_str);
}

void listaDiretoria(const char *diretoria) {
    DIR *dir;
    struct dirent *ent;
    struct stat info;

    // Abre a diretoria
    if ((dir = opendir(diretoria)) == NULL) {
        perror("Erro");
        return;
    }

    // Percorre os ficheiros e diretórios na diretoria
    while ((ent = readdir(dir)) != NULL) {
        // Ignora os diretórios "." e ".."
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)
            continue;

        // Obtém as informações do ficheiro/diretório
        char path[PATH_MAX];
        snprintf(path, sizeof(path), "%s/%s", diretoria, ent->d_name);
        if (stat(path, &info) == -1) {
            write_string("Erro: nao foi possivel obter informacoes do ficheiro.\n");
            continue;
        }

        // Exibe o nome do ficheiro/diretório
        write_string(ent->d_name);

        // Verifica se é um diretório
        if (S_ISDIR(info.st_mode))
            write_string(" (diretorio)");
        
        write_string("\n");
    }

    closedir(dir);
}