#include <stdio.h>
#define MAX 9

void show(int matriz[MAX][MAX]);
//void search(int matriz);
//void possibilities(int matriz);

int main()
{
    int num, op, i, j, a, line, column, startline, startcolumn; 
    int sudoku[MAX][MAX]= {5, 3, 0, 0, 7, 0, 0, 0, 0,
                           6, 0, 0, 1, 9, 5, 0, 0, 0,
                           0, 9, 8, 0, 0, 0, 0, 6, 0,
                           8, 0, 0, 0, 6, 0, 0, 0, 3,
                           4, 0, 0, 8, 0, 3, 0, 0, 1,
                           7, 0, 0, 0, 2, 0, 0, 0, 6,
                           0, 6, 0, 0, 0, 0, 2, 8, 0,
                           0, 0, 0, 4, 1, 9, 0, 0, 5,
                           0, 0, 0, 0, 8, 0, 0, 7, 9};
    int vet[MAX]= {1, 1, 1, 1, 1, 1, 1, 1, 1};
    while(1){
        puts("Digite:");
        puts("0 - Sair do programa.");
        puts("1 - Preencher o Sudoku manualmente.");
        puts("2 - Mostrar o jogo atual (caso nao tenha sido alterado, preenchimento padrão).");
        puts("3 - possibilidades nas posições vagas do jogo.");
        scanf("%d", &op);
        switch(op) {
            case 0:
                return 0;
            case 1:
                puts("\npreencha o Sudoku que você deseja analisar:");
                for(i = 0; i < MAX; i++, putchar('\n')) {//varrer a matriz, passando por todas as posições
                    for (j = 0; j < MAX; j++) {
                    printf("posição[%d][%d]\n", i, j);//mostrar a posição atual ao usuário.
                    scanf("%d", &num);//receber um valor para a posição.
                    sudoku[i][j] = num;//atribuir o valor à posição.
                    }
                }
                break;
            case 2:
                show(&sudoku);
                break;
            case 3://por enquanto estou ignorando a submatriz!!!!!!!!!
                for (i = 0; i < MAX; i++) {//varrendo toda a matriz, por linhas e colunas
                    for(j = 0; j < MAX; j++) {
                        if(sudoku[i][j] == 0) {//se encontrar um espaço, não preenchido:
                            for(a = 0; a < MAX; a++) {//verificar:
                                if(sudoku[i][a] != 0){//1 - toda a linha desse elemento
                                    vet[sudoku[i][a]]=0;//alterar o valor para 0 na posição correspondente ao número encontrado.
                                }
                                if(sudoku[a][j] != 0){//2- toda a coluna desse elemento
                                    vet[sudoku[a][j]]=0;//alterar o valor para 0 na posição correspondente ao número encontrado.
                                }
                            }
                                if(i < 3) {
                                    startline=0;
                                }
                                else if(i < 6) {
                                    startline=3;
                                }
                                else if(i < 9) {
                                    startline=6;
                                }
                                if(j < 3) {
                                    startcolumn=0;
                                }
                                else if(j < 6) {
                                    startcolumn=3;
                                }
                                else if(j < 9) {
                                    startcolumn=6;
                                }
                                for (line = startline; line < startline+3; line++) {
                                    for (column = startcolumn; column < startcolumn+3; column++)
                                        if(sudoku[line][column] != 0)
                                        vet[sudoku[line][column]]=0;
                                }
                                    for (int b = 1; b <= MAX; b++) {//printar as possibilidades(números 1's do vetor), ainda sem verificar a submatriz.
                                        if (vet[b] != 0)
                                        printf("Na posição [%d][%d] = %d é uma possibilidade.\n", i, j, b);
                                    }//retornar o valor original para todas as posições do vetor.
                                    vet[0]=1;   vet[1]=1;   vet[2]=1;
                                    vet[3]=1;   vet[4]=1;   vet[5]=1;
                                    vet[6]=1;   vet[7]=1;   vet[8]=1;
                                    vet[9]=1;
                        }
                    }
                }
                break;
        }
    }
    return 0;
}

void show(int matriz[MAX][MAX]){
    puts("O jogo atual é:");
    puts("┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐");
        for (int row = 0; row < 9; row++) {
            printf("│");
            for (int spine = 0; spine < 9; spine++) {
                printf("  %d  │", matriz[row][spine]);
            }
            if (row != 8) printf("\n├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤\n");
        }
            printf("\n└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘\n");
        return 0;
}