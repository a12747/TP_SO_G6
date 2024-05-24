#include "header.h"

int main(int argc, char *argv[]){
	if(argc == 1){
		display_prompt();
	}else{
        int status;
        int pid;
        if(strcmp(argv[1], "termina") == 0 && argc==2)exit(0);
        pid = fork();
        if(!pid){
        if (argc<2)return 0;
        if (strcmp(argv[1], "mostra") == 0 && argc==3) {
            mostraFicheiro(argv[2]);
        } else if (strcmp(argv[1], "copia") == 0 && argc==3) {
            copiaFicheiro(argv[2]);
        } else if (strcmp(argv[1], "acrescenta") == 0 && argc==4) {
            acrescentaFicheiro(argv[2], argv[3]);
        } else if (strcmp(argv[1], "conta") == 0 && argc==3) {
	        contaFicheiro(argv[2]);
        } else if (strcmp(argv[1], "apaga") == 0 && argc==3) {
            removeFicheiro(argv[2]);
        } else if (strcmp(argv[1], "informa") == 0 && argc==3) {
            informaFicheiro(argv[2]);
        } else if (strcmp(argv[1], "lista") == 0 && argc>2){
           if (argc != 3) {
                const char *usage = "Diretoria invalida\n";
                write(STDOUT_FILENO, usage, strlen(usage));
            }else listaDiretoria(argv[2]);
        }else{
	        const char *fail_msg = "Comando invalido\n";
            write(STDOUT_FILENO, fail_msg, strlen(fail_msg));
   	     }
        }else{
	        wait(NULL);
	        display_prompt();
        }
	}
    return 0;
}