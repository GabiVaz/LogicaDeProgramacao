#include <stdio.h>

int main() {

    int n, i, j, k, l;
    
    /*le o numero de matrizes que seram inseridas*/
    scanf(" %d", &n);
  
    /*matriz sudoku guarda uma solucao que sera testada se eh possivel ou nao;
    vetor result guarda a resposta da matriz sudoku, sendo 0 = SIM e 1 = NAO*/
    short int sudoku[9][9], result[n];


    /*laco que repete n vezes, que eh o numero de instancia que teram*/
    for(i = 0; i < n; i++){ // laco I
        /*deixa em 0 o resultado, caso chegue ate o final com 0, significa que sta correto*/
        result[i] = 0; 

        /*laco que le cada numero do da solucao e armazena na matriz sudoku*/
        for(j = 0; j < 9; j++){
            for(k = 0; k < 9; k++){
                scanf("%hi", &sudoku[j][k]);
            }
        }



        /*laco for que caminha pelas linhas da matriz, delimitada pelo
        numero de linhas que eh 9*/
        for(j = 0; j < 9; j++){ // laco J

            /*laco que caminha por elemento da linha, tambem delimitada por 9*/
            for(k = 0; k < 9; k++){ // laco K

                /*laco tambem caminha por elemento da linha,
                usados para comparar todos elementos da linha*/
                for(l = k+1; l < 9; l++){ // laco L

                   

                    /*idenifica quando ha algum elemento repetido na linha*/
                    if(sudoku[j][k] == sudoku[j][l] && sudoku[j][k] != 0){
                        /*chave que idetifica quando aparece um erro*/
                        result[i] = 1;
                        /*e nesse caso deve interromper o laco*/
                        break; // sai do laco L
                    }
                    /*do mesmo passo que caminha pela linha, pode-se caminhar
                    pela coluna, esse trecho aproveita disso e tambem
                    identifica quando ha algum elemento repetido na coluna,
                    */
                    if(sudoku[k][j] == sudoku[l][j] && sudoku[k][j] != 0){
                        result[i] = 1;
                        break; // sai do laco L
                    }
                }
                /*quando identifica a primeira irregularidade ja interrompe o laco
                em outros ifs tambem fazem isso para otimizar o programa*/
                if(result[i] == 1)
                    break; // sai do laco K



                /*os if's identificam elementos repetidos dentro de um bloco 3x3*/
                /*quando na 1a linha do bloco ... */
                if(j % 3 == 0){

                    /*e na 1a coluna do bloco ... */
                    if(k % 3 == 0){

                        /*compara com os demais elementos do bloco exceto com os da
                        mesma linha e mesma coluna ja q ja foi coparado anteriormente
                        nos lacos for

                        identifica se ha elementos repetidos dentro do bloco na 2a ou 3a
                        linha e 2a ou 3a coluna*/
                        if(sudoku[j][k] == sudoku[j+1][k+1] || sudoku[j][k] == sudoku[j+1][k+2]
                        || sudoku[j][k] == sudoku[j+2][k+1] || sudoku[j][k] == sudoku[j+2][k+2]){
                            if(sudoku[j][k] != 0){
                              result[i] = 1;
                              break; // sai do laco K
                            }
                        }
                    }

                    /*e na 2a coluna do bloco ... */
                    else if(k % 3 == 1){

                        /*compara com os demais elementos do bloco exceto com os da
                        mesma linha e mesma coluna ja q ja foi coparado anteriormente
                        nos lacos for

                        identifica se ha elementos repetidos dentro do bloco na 2a ou 3a
                        linha e 1a ou 3a coluna*/
                        if(sudoku[j][k] == sudoku[j+1][k+1] || sudoku[j][k] == sudoku[j+1][k-1]
                        || sudoku[j][k] == sudoku[j+2][k+1] || sudoku[j][k] == sudoku[j+2][k-1]){
                            if(sudoku[j][k] != 0){
                              result[i] = 1;
                              break; // sai do laco K
                            }
                        }
                    }

                    /*e na 3a coluna do bloco ... */
                    else if(k % 3 == 2){

                        /*compara com os demais elementos do bloco exceto com os da
                        mesma linha e mesma coluna ja q ja foi coparado anteriormente
                        nos lacos for

                        identifica se ha elementos repetidos dentro do bloco na 2a ou 3a
                        linha e 1a ou 2a coluna*/
                        if(sudoku[j][k] == sudoku[j+1][k-1] || sudoku[j][k] == sudoku[j+1][k-2]
                        || sudoku[j][k] == sudoku[j+2][k-1] || sudoku[j][k] == sudoku[j+2][k-2]){
                            if(sudoku[j][k] != 0){
                              result[i] = 1;
                              break; // sai do laco K
                            }
                        }

                    }
                }

                /*quando na 2a linha do bloco ... */
                else if(j % 3 == 1){

                    /*e na 1a coluna do bloco ... */
                    if(k % 3 == 0){

                        /*compara com os demais elementos do bloco exceto com os da
                        mesma linha e mesma coluna ja q ja foi coparado anteriormente
                        nos lacos for e com os da 1a linha do bloco pq ja foi comparado
                        nos if's anteriores

                        identifica se ha elementos repetidos dentro do bloco na 3a
                        linha e 2a ou 3a coluna*/
                        if(sudoku[j][k] == sudoku[j+1][k+1] || sudoku[j][k] == sudoku[j+1][k+2]){
                            if(sudoku[j][k] != 0){
                              result[i] = 1;
                              break; // sai do laco K
                            }
                        }
                    }

                    /*e na 2a coluna do bloco ... */
                    else if(k % 3 == 1){

                        /*compara com os demais elementos do bloco exceto com os da
                        mesma linha e mesma coluna ja q ja foi coparado anteriormente
                        nos lacos for e com os da 1a linha do bloco pq ja foi comparado
                        nos if's anteriores

                        identifica se ha elementos repetidos dentro do bloco na 3a
                        linha e 1a ou 3a coluna*/
                        if(sudoku[j][k] == sudoku[j+1][k+1] || sudoku[j][k] == sudoku[j+1][k-1]){
                            if(sudoku[j][k] != 0){
                              result[i] = 1;
                              break; // sai do laco K
                            }
                        }
                    }

                    /*e na 3a coluna do bloco ... */
                    else if(k % 3 == 2){

                        /*compara com os demais elementos do bloco exceto com os da
                        mesma linha e mesma coluna ja q ja foi coparado anteriormente
                        nos lacos for e com os da 1a linha do bloco pq ja foi comparado
                        nos if's anteriores

                        identifica se ha elementos repetidos dentro do bloco na 3a
                        linha e 1a ou 2a coluna*/
                        if(sudoku[j][k] == sudoku[j+1][k-1] || sudoku[j][k] == sudoku[j+1][k-2]){
                            if(sudoku[j][k] != 0){
                              result[i] = 1;
                              break; // sai do laco K
                            }
                        }

                    }
                }
                /*quando na 3a linha do bloco ...
                nao precisa ser comparada porque ja foi comparada com os
                da 1a e 2a linha e com ela propria*/



                /*interrompe laco...*/
                if(result[i] == 1)
                    break; // sai do laco K
            }
            /*interrompe laco...*/
            if(result[i] == 1)
                break; // sai do laco J
        }
    }



    /*da o resultado armazenado no vetor result*/
    for(i = 0; i < n; i++){
        printf("\nInstancia %d\n", i+1);
        if(result[i] == 0)
            printf("SIM\n");
        else
            printf("NÃO\n");
    }

        
  return 0;
}
