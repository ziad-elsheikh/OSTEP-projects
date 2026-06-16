#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]){
    
    if (argc <= 1){
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }
    
    char *search = argv[1];
    char *buf = NULL;
    size_t size = 0;    

    if (argc == 2){
        while(getline(&buf, &size, stdin) != -1){
            if (strstr(buf, search) != NULL){
                printf("%s", buf);
            }
        }
    }

    else{
        for(int i = 2; i < argc; i++ ){
            FILE *file = fopen(argv[i], "r");
            if(file == NULL){
                printf("wgrep: cannot open file\n");
                exit(1);
            }

            while (getline(&buf, &size, file) != -1){
                if (strstr(buf, search) != NULL)
                    // printf("%S", strstr(buf, search));
                    printf("%s", buf);
                }
            fclose(file);
            }

            free(buf);
        }
    return 0;
}