/* EA876 - INTRODUÇÃO A SOFTWARE DE SISTEMA
 * Professor: Tiago Fernandes Tavares
 *
 * Nome: Danilo Aparecido Rossi Moraes  
 * RA: 169649
 *
 * Laboratório: Somador de Floats
 * Prazo: 08/03/2019 ás 23:59h
 *
 * Descrição: Através da entrada de uma string pelo usuário, o programa irá reconhecer na mesma, números no formato float, 
 * e através destes, realizará uma soma, de acordo com as regras descritas no enunciado do problema.
 * 
 */ 
 
/* Declaração de bibliotecas */
#include <stdio.h>
#include <stdlib.h>

/* Inicio da função principal do programa */
int main (){

    /* Declaração dos vetores que receberão a string e os valores floats detectados, respectivamente */
    char vetor[150], vetor_aux[150];

    /* Declaração do vetor que irá receber os valores floats convertidos da string e a variável que irá receber o resultado da soma desses elementos */
    float operando[150], total = 0.0;

    /* OBS: Como não foi definido no enunciado uma quantidade de caracteres em cada string, foi defindo nesse laboratório que o valor " 150 " estaria adequado
     * para satisfazer os testes aqui propostos */


    /* Declaração de variáveis e de flags utéis para o desenvolvimento do programa */
    int i = 0, k = 0, x = 0, y = 0, ponto = 0, find = 0, decimal = 0, stop = 0;   

    /* Inicialização dos vetores */
    for (i = 0; i < 150; i++){
   
         operando[i] = 0;     
         vetor[i] = 0; 
         vetor_aux[i] = 0;  

    }
    
    /* Entrada da string pelo usuário */
    scanf ("%[^\n]s", vetor);
    
    /* Processo em que começara a busca por números do tipo float */
    while (vetor[x] != '\0'){

          /* Etapa que verifica se o elemento é um possível candidado */
          if ((vetor[x] > 47 && vetor[x] < 58) || vetor[x] == 32){

              /* Caso o caractere seja um espaço, um descolamento no vetor é necessário para a formatação numérica */
              if (vetor[x] == 32){            
              
                x++;    
                stop = 0;           
              
              }

              /* Se um número começar com ".", ele logo será descartado */
              if (vetor[x-1] == 46)
                stop = 1;
    
          /* Caso o número não seja descatado, a formatação é iniciada, verificando se haverá mais de um " . " ou algum outro caracter adjascente */
          while (vetor[x] == 46 || (vetor[x] > 47 && vetor[x] < 58) && !stop){

                 if (vetor[x] == 46)
                    decimal++;

                 vetor_aux[k] = vetor[x];
      
                 k++;

                 x++;

                 if (decimal < 2 && (vetor[x] == 32 || vetor[x] == '\0'))             
                 
                 find = 1;
                 
                 }

           }                                    

           /* Caso esteja de acordo com o solicitado no enunciado, os valores encontrados serão convertidos em números do tipo float, para que
            *  seja possível alguma operação matemática */
           if (find == 1){
            
             decimal = 0;
             operando[y] = atof(vetor_aux);            
             y++;
             
             for (i = 0; i < 50; i++){
                 vetor_aux[i] = 0;
                 k = 0;
             }

             find = 0;

          }

          /* Caso nenhum valor seja encontrado, o índice do vetor será descolado, para que se possível, uma nova busca possa ser feita */
          else
             x++;

          find = 0; 
 
    }

    i = 0;

    /* Após todas as detecções possíveis, o valor total será calculado nesta próxima etapa */
    while (i < y){

          total = total + operando[i];
          i++;

    }
    
    /* Etapa que irá calcular a saída adequada de acordo com os "zeros" a serem considerados ou não
     * Na primeira, todo o resultado será considerado, na segundo, apenas a parte inteira será conseiderada */
    if (total - (int)total != 0)
           printf("%.1f\n", total);
   
    else 
           printf ("%d\n", (int)total);

    /* Fim da função principal */
    return 0;

}
