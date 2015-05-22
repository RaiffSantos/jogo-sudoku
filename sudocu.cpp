#include<stdio.h>
#include<stdlib.h>

int main(){
	
  printf("\n#### #  #    # #### #  # #  # \n");
	printf("#    #  #    # #  # # #  #  # \n");
	printf("#### #  # #### #  # ##   #  # \n");
	printf("   # #  # #  # #  # # #  #  # \n");
	printf("#### #### #### #### #  # #### \n \n");
	
	int i, l, c, vetor[9][9];
	int linha, coluna, valor, dif;
	char estado = 'e';
	char errol = 'f';
	char erroc = 'f';
	
	l = 0;
	c = 0;

	//atribui o valor 0 a todos os espaços
	for(l = 0; l < 9; l++){
		for(c = 0; c < 9; c++){
			vetor[l][c] = 0;
			//printf("%d | ", vetor[l][c]);
		}
    //printf("\n \n");
	}
	
	//selecionar dificuldade
	printf("selecione a dificuldade \n");
	printf("iniciante - 1 \n");
	printf("avancado  - 2 \n");
	printf("selecione a dificuldade: [1 / 2] ? ");
	scanf("%d", &dif);
	
	if(dif == 1){
	    //constantes do jogo
	    vetor[0][0] = 2;
	    vetor[0][2] = 4;
	    vetor[0][3] = 5;
	    vetor[0][4] = 1;
	    vetor[0][7] = 7;
	    vetor[0][8] = 9;
	    vetor[1][0] = 3;
	    vetor[1][1] = 7;
	    vetor[1][2] = 1;
	    vetor[1][5] = 9;
	    vetor[1][7] = 6;
	    vetor[2][2] = 9;
	    vetor[2][3] = 7;
	    vetor[2][7] = 2;
	    vetor[3][0] = 4;
	    vetor[3][1] = 9;
	    vetor[3][6] = 5;
	    vetor[4][0] = 7;
	    vetor[4][1] = 1;
	    vetor[4][3] = 9;
	    vetor[4][5] = 6;
	    vetor[4][7] = 4;
	    vetor[4][8] = 3;
	    vetor[5][2] = 5;
	    vetor[5][7] = 1;
	    vetor[5][8] = 7;
	    vetor[6][1] = 8;
	    vetor[6][5] = 1;
	    vetor[6][6] = 7;
	    vetor[7][1] = 2;
	    vetor[7][3] = 6;
	    vetor[7][6] = 1;
	    vetor[7][7] = 3;
	    vetor[7][4] = 4;
	    vetor[8][0] = 1;
	    vetor[8][1] = 4;
	    vetor[8][4] = 7;
	    vetor[8][5] = 5;
	    vetor[8][6] = 6;
	    vetor[8][8] = 8;
	    printf("\nnivel iniciante selecionado! \n\n");
    }else if(dif == 2){
        //constantes do jogo
	    vetor[0][2] = 1;
	    vetor[0][3] = 5;
	    vetor[0][5] = 3;
	    vetor[1][7] = 7;
	    vetor[2][0] = 9;
	    vetor[2][8] = 2;
	    vetor[3][4] = 2;
	    vetor[3][5] = 7;
	    vetor[4][2] = 4;
	    vetor[4][6] = 5;
	    vetor[4][8] = 6;
	    vetor[5][5] = 9;
	    vetor[6][0] = 7;
	    vetor[7][1] = 6;
	    vetor[7][3] = 8;
	    vetor[7][6] = 4;
	    vetor[8][6] = 1;
		printf("\nnivel avancado selecionado! \n\n");    	
	}
		
	printf("Inicio do jogo \n \n");
	for(l = 0; l < 9; l++){
		for(c = 0; c < 9; c++){
			printf("%d    ", vetor[l][c]);
		}
		//printf("\n-----------------------------------");
    printf("\n \n \n");
	}
	
    while(estado != 'f'){
    	errol = 'f';
    	erroc = 'f';
	    // pega as cordenadas e o valor
	    printf("digite a linha: ");
	    scanf("%d", &linha);
	
    	printf("digite a coluna: ");
	    scanf("%d", &coluna);
	
	    printf("digite o valor: ");
	    scanf("%d", &valor);
	
	    linha = linha-1;
	    coluna = coluna-1;
	    
	    //buscando erro
	    for(i = 0; i < 9; i++){
		    if(vetor[linha][i] == valor){
			  /*printf("\n### ### ### ###\n");
			    printf("#   # # # # # #\n");
			    printf("### ### ### # #\n");
			    printf("#   ##  ##  # #\n");
			    printf("### # # # # ### LINHA\n \n");*/
			    errol = 'v';
		    }
	    }
	    for(i = 0; i < 9; i++){
		    if(vetor[i][coluna] == valor){
			  /*printf("\n### ### ### ###\n");
			    printf("#   # # # # # #\n");
			    printf("### ### ### # #\n");
			    printf("#   ##  ##  # #\n");
			    printf("### # # # # ### COLUNA\n \n");*/
				erroc = 'v';		    
		    }
	    }
	    if(errol == 'v' || erroc == 'v'){
	    	  printf("\n### ### ### ###\n");
			    printf("#   # # # # # #\n");
			    printf("### ### ### # #\n");
			    printf("#   ##  ##  # #\n");
			    printf("### # # # # ###\n \n");
		}else{
		    //gravando jogada
			vetor[linha][coluna] = valor;	
		}
	    
	    printf("\nresultado da jogada: \n \n");
	    for(l = 0; l < 9; l++){
		    for(c = 0; c < 9; c++){
			    printf("%d    ", vetor[l][c]);
		    }
            printf("\n \n \n");
	    }
	
	    // testando estado do jogo
	    for(l = 0; l < 9; l++){
		    for(c = 0; c < 9; c++){
			    if(vetor[l][c] == 0){ //enquanto tiver espaço 0 o jogo continua
				    estado = 'e';
			    break;
				}//else{
			    //	estado = 'f';
			    //}
		        //break;
			}
		    //break;
            //printf("\n \n");
	    }
    }// fim while

	system("PAUSE");
	return 0;
}
