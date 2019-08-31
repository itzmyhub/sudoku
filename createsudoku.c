#include<stdio.h>
#include<stdlib.h>

//void alocation(int **matriz, int *vetor);
void createdinamic(int ***matriz, int **vetor);
void show(int **matriz);
void showVector(int *vector);

int main(){
    int **sudoku, *possibility, option, i, j;
    createdinamic(&sudoku, &possibility);
    while(1){
    scanf("%d", &option);
        switch(option){
        case 1:
        //alocation(sudoku, possibility);
        break;       
        case 2:
        show(sudoku);
        showVector(possibility);
        break;
        }
    }
    free(sudoku);
    return 0;
}


/*void alocation(int **matriz, int *vetor){
    int row=9, random, i, number=1;
    while(number <=9){
        for (i = 0; i < row; i++){
        random = rand()%9;
        vetor[random]=1;
        matriz[i][random] = number;
    	   //}	else {
    		//i--;
    	   //}
        }
    number++;
    }
}*/

void createdinamic(int ***matriz, int **vetor){
    int j, row=9, column=9;

   *matriz = (int **)malloc(sizeof(int *) * row);
   for(int i = 0; i < row; i++) {
        (*matriz)[i] = (int *)malloc(sizeof(int) * row);
        for(int j = 0; j < row; j++) {
            (*matriz)[i][j] = 0;
        }
   }
    *vetor = (int*)calloc(column, sizeof(int));
}

void showVector(int *vector) {
    int i;
    for (int i = 0; i < 9; i++)
    {
        printf("%d\n", vector[i]);
    }
}

void show(int **matriz){
    int row, spine, i, j;
    /*for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            printf("%d", matriz[i][j]);
        }
        printf("\n");
    }*/ 
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