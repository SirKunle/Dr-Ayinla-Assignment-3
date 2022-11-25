#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    int attepts;
    int similar = 0;
    FILE *fp;
    fp = fopen("files.in", "r");
    if(fp == NULL){
        printf("Error accessing the file");
        exit(0);
    }

    int number_file;
    fscanf(fp, "%d", &attepts);



    int t;


    int lowest_value = 0;
    char name_of_file[100][50];
    int file_id[100];

    for (int i = 0; i< attepts; i++) {
        fscanf(fp, "%d", &number_file);

        int j = 0;

        while (j<number_file) {
            fscanf(fp,"%s %d", name_of_file[j], &file_id[j]);
            j++;
        }
        printf("\n");
        lowest_value = file_id[0];
        for (int j = 0; j< number_file; j++) {
            for (int i = j + 1; i < number_file; i++) {
                similar = strcmp(name_of_file[j], name_of_file[i]);
                if((strcmp(name_of_file[j], name_of_file[i]) == 0) &&  (lowest_value > file_id[j])){

                    lowest_value = file_id[j];
                }
                else if((strcmp(name_of_file[j], name_of_file[i]) != 0) && (file_id[j] > file_id[i])){
                    t = file_id[j];
                    file_id[j] = file_id[i];
                    file_id[i] = t;
                }
            }
        }
        for (int j = 0; j< number_file; j++) {
            if (similar != 0){
                printf("%d\n", file_id[j]);
            }
        }
        if (similar == 0){
            printf("%d\n", lowest_value);
        }
    }
}

