//#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#define N 52

struct lista{
   int v[N];
   int qtd_elem;
};

Lista* criarl(int ord){
   Lista *l = (Lista*) malloc(sizeof(Lista));
   l->qtd_elem = 0;
   return(l);
}

int cheial(Lista *l){
   if(l->qtd_elem == N) return 1;
   else return(0);
}

void inserirl(Lista *l, int valor, int pos){
   int i;
   if(cheial(l)) printf("A lista está cheia");
   else if(pos > l->qtd_elem || pos<0)              printf("A posição da inserção é inválida");
        else{
          i=l->qtd_elem;
          while(i>pos){
            l->v[i] = l->v[i-1];
              i--;
          }
          l->v[pos] = valor;
          l->qtd_elem += 1;
            
        }
}

int vazial(Lista *l){
  if(l->qtd_elem ==0) return 1;
  else return 0;
}

int removerl(Lista *l, int pos){
   int i=0, valor=0;
   if(vazial(l)){ printf("A lista está vazia, não é possivel fazer remoção");
    exit(1);
   }else if(pos >= l->qtd_elem || pos<0) { 
           printf("Posição inválida, impossível fazer a remoção"); 
           exit(1);
         }else{
            valor = l-> v[pos];
 	    
	    for(i=pos+1;i<l->qtd_elem; i++)
	       l->v[i-1] = l->v[i];
 	    
	    l->qtd_elem -= 1;
	    return(valor); 
         }
}

void imprimirl(Lista *l, int pos){
  if(!vazial(l) && pos >= 0 && pos <l->qtd_elem)
    printf("\nO elemento  %d da Lista é  %d", pos, l->v[pos]);
  else printf("Lista vazia ou posição inválida");
}

int qtd_elem(Lista *l){
  return l->qtd_elem;
}

void liberarl(Lista *l){
  free(l);
}
