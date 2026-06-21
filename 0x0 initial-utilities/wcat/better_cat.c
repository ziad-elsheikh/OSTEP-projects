#include <stdio.h>
#include <stdlib.h> // exit
#include <string.h> // strstr


int main(int argc, char *argv[]){
    for(int i = 1; i < argc; i++ ){
        char *path = argv[i];
        FILE *file = fopen(path, "r");

        if(file == NULL){
            printf("cat: cannot open file\n");
            exit(1);
        }

        char *buf = NULL;
        size_t size = 0;
        int sz;

        while (getline(&buf, &size, file) != -1){
            printf("%s", buf);
        }
        free(buf);
        fclose(file);
    }
    return 0;
}