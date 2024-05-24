#include "header.h"
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