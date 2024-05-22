#ifndef FUNCOES_H
#define FUNCOES_H
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
int contaFicheiro(char *ficheiro);
void removeFicheiro(const char *ficheiro);
int informaFicheiro(char *filename);
int lista(char *dir_name);

#endif