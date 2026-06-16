#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    for (int i = 1; i < argc; i++){
        char *file = argv[i];
        FILE *fpntr = fopen(file, "r");

        if (fpntr == NULL){
            printf("wcat: cannot open file\n");
            exit(1);
        }

        char buf[256];
        while (fgets(buf, sizeof(buf), fpntr) != NULL){
            printf("%s", buf);
        }
        fclose(fpntr);
    }
    return 0;
}