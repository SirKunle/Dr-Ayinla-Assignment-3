#include <stdio.h>
#include <string.h>
#include <stdlib.h>




int main(){

    char strnumber[100];
    int number[100];
    int count = 0;
    int frequency;
    int attempt;

    char self_describing = 'T';

    FILE *fp;
    fp = fopen("self.in", "r");

    fscanf(fp, "%d", &frequency);
    printf("Number of caseS: %d\n", frequency);

    for (int i = 0; i< frequency; i++) {
        fscanf(fp, "%s", strnumber);
        attempt = strlen(strnumber);


        for (int j = 0; j < attempt; j++) {
            number[j] = strnumber[j] - '0';
        }
        printf("\n");
        for (int j = 0; j < attempt; j++) {
            printf("We have %d , %d in the number \n", number[j],j);
        }
        for (int m = 0; m< attempt; m++) {
            for (int i = 0; i< attempt; i++) {
                if (number[i] == m) count++;
            }
            if(count == number[m]){
                self_describing = 'T';
            }
            else{
                self_describing = 'F';
                printf("\n");
                printf("Number is not 'self-describing'\n\n");
                break;
            }
            count = 0;
            if (self_describing != 'F'){
                printf("\n");
                printf("Number is 'Self-describing'\n\n");
                break;
            }
        }
    }

}
