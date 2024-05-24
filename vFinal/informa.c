#include "header.h"
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