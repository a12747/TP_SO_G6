#include "header.h"

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