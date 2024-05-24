#ifndef FUNCOES_H
#define FUNCOES_H

#include <dirent.h>
#include <fcntl.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define FICHEIRO_SIZE 50

// Auxiliares
void write_string(const char *str);
void read_string(char *buffer, size_t size);
void read_int(int *number);

// Ações
void mostraFicheiro(const char *ficheiro);
void copiaFicheiro(const char *ficheiro);
void acrescentaFicheiro(const char *origem, const char *destino);
int contaFicheiro(const char *ficheiro);
void removeFicheiro(const char *ficheiro);
void informaFicheiro(const char *ficheiro);
void listaDiretoria(const char *diretoria);

#endif