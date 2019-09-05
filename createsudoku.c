#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void alocation(int ***matriz, int **vetor);
void createdinamic(int ***matriz, int **vetor);
void show(int **matriz);
//void tryagain();

int main(){
    int **sudoku, *possibility, option;
    createdinamic(&sudoku, &possibility);
    while(1){
    scanf("%d", &option);
        switch(option){
        case 1:
        alocation(&sudoku, &possibility);
        break;       
        case 2:
        show(sudoku);
        break;
        }
    }
    free(sudoku);
    free(possibility);
    return 0;
}

void createdinamic(int ***matriz, int **vetor){
    int row=9;
    *matriz = (int **)malloc(sizeof(int *) * row);
    for(int i = 0; i < row; i++) {
        (*matriz)[i] = (int *)malloc(sizeof(int) * row);
        for(int j = 0; j < row; j++) {
            (*matriz)[i][j] = 0;
        }
   }
    *vetor = (int*)calloc(row, sizeof(int));
}

void alocation(int ***matriz, int **vetor){
    int number=1, random, i, sub[3]={0,0,0};
    srand(time(NULL));
    while(number <=9){
        random = rand()%9;
        printf("%d\n", random);
        puts("aaaaaaaa");
        /*if(random < 3)
        sub[i] = 1;
        else if (random < 6)
        sub[i] = 2;
        else if (random < 9)
        sub[i] = 3;*/
        printf("%d %d\n", *vetor[0], *matriz[i][random]); 
        if (*vetor[random] == 0 && (*matriz)[i][random] == 0){
            (*matriz)[i][random] = number;
            *vetor[random] = 1;
            printf("aaaaaaaaaaaaaaa");
            } else {
                i--;
            }    
    sub[0] = 0; sub[1] = 0; sub[2] = 0;
    number++;
    }
}

void show(int **matriz){
    int row, spine;

    puts("O jogo atual é:");
    puts("┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐");
        for (row = 0; row < 9; row++) {
        printf("│");
            for (spine = 0; spine < 9; spine++) {
            printf("  %d  │", matriz[row][spine]);
            }
            if (row != 8) printf("\n├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤\n");
        }
        printf("\n└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘\n");
        return;
}