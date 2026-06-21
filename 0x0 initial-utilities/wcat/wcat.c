#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  // loop on all input files
    for (int i = 1; i < argc; i++){ // starts from 1 as argv[0] has program name
        char *file = argv[i]; // store file name into string
        FILE *fpntr = fopen(file, "r"); // open file returns a pointer

        if (fpntr == NULL){ // doing some validation
            printf("wcat: cannot open file\n");
            exit(1);
        }

        char buf[256]; // create a buffer to read data
        // there are multple methods to read data (fgets, fgetc, getline, ..)
        while (fgets(buf, sizeof(buf), fpntr) != NULL){
            printf("%s", buf);
        }
        fclose(fpntr);
    }
    return 0;
}
