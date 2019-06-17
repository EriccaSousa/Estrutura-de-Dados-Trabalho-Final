#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#define ESQUERDA 1
#define DIREITA 2

struct no{
    int valor;
    No *esq;
    No *dir;
    int fatorBal;//altura da sub-arvore;
};

struct arvore{
    No *raiz;
};

Arvore* criarArvore(){
    Arvore *a = (Arvore*) malloc(sizeof(Arvore));
    a->raiz = NULL;
    return a;
}


int vaziaArvore(Arvore *a){
    if(a->raiz == NULL)
        return 1;
    else
        return 0;
}

int cheiaArvore(Arvore *a){
    return 0;
}

void imprimir_no(No *n, int ordem){
    //pre ordem
    if(ordem == 1){
        if (n != NULL) {
            printf(" -%d- ", n->valor);
            imprimir_no(n->esq, 1);
            imprimir_no(n->dir, 1);
        }
    }
    
    //in ordem
    if(ordem == 2){
        if (n != NULL) {
            imprimir_no(n->esq, 2);
            printf(" -%d- ", n->valor);
            imprimir_no(n->dir, 2);
        }
    }
    
    //pós ordem
    if(ordem == 3){
        if (n != NULL) {
            imprimir_no(n->esq, 3);
            imprimir_no(n->dir, 3);
            printf(" -%d- ", n->valor);
        }
    }
}

void imprimirArvore(No *no, int ordem){
    imprimir_no(no, ordem);
}

/*
void inserirArvore(Arvore *a, int valor){
    No *temp  = a->raiz;
    No *ant = NULL;
    No *aux = a->raiz;
    int verifica = 0;
    int pos=0;
    
    No *n = (No*) malloc(sizeof(No));
    n->valor = valor;
    n->esq = NULL;
    n->dir = NULL;
    n->fatorBal = 0;
    
    if(vaziaArvore(a)){
        a->raiz = n;
    }else{
        while(temp != NULL){
            if(valor <= temp->valor){
                ant = temp;
                temp = temp->esq;
                pos = ESQUERDA;
            }else{
                if(valor >= temp->valor){
                    ant = temp;
                    temp = temp->dir;
                    pos = DIREITA;
                } 
            }
            
        }

        if(pos == ESQUERDA){
            ant->esq = n;
            int c = altura(a->raiz->esq);
            int d = altura(a->raiz->dir);
            int alt = c - d;
            printf("diferenca da arvore: %d, %d, %d ", alt, c, d);
        }else if(pos == DIREITA){
            ant->dir = n;
            int c = altura(a->raiz->esq);
            int d = altura(a->raiz->dir);
            int alt = c - d;
            printf("Diferenca da arvore: %d, %d, %d ", alt, c, d); 
        }
    }
}
 
int removerArvore(Arvore *a, int valor){
    if(!vaziaArvore(a)){
        //percorrendo a árvore com temp
        No *temp = a->raiz;
        No *ant =NULL;
        int pos_temp = 0;
        while(temp!=NULL){
            if(valor == temp->valor) break;
            ant = temp;
            if(valor < temp->valor){
               temp = temp->esq;
               pos_temp = ESQUERDA;
            }else if (valor > temp->valor){
                     temp = temp->dir;
                     pos_temp = DIREITA;
            }
        } // o fluxo sai deste laço com temp apontando para null quando não encontra o valor ou com temp apontando para a posição que tem o valor
        
        // caso que o valor não é encontrado
        if(temp == NULL) return 0;
        
        // quando o valor está em um nó que não tem direita nem esquerda
        if(temp->esq == NULL && temp->dir == NULL){
                if(temp == a->raiz) a->raiz = NULL;
                else if(pos_temp == ESQUERDA) ant->esq = NULL;
                     else ant->dir = NULL;
                free(temp);
                return(1);
        }
        
        // quando não tem esquerda mas tem direita
        if (temp->esq == NULL && temp->dir != NULL){
            if(temp == a->raiz) a->raiz = a->raiz->dir;
            if(pos_temp == ESQUERDA) ant->esq = temp->dir;
            else if(pos_temp == DIREITA) ant->dir = temp->dir;
            free(temp);
            return(1);
        }
        
        // quando não tem direita mas tem esquerda
        if (temp->dir == NULL && temp->esq != NULL){
            if(temp == a->raiz) a->raiz = a->raiz->esq;
            if(pos_temp == ESQUERDA) ant->esq = temp->esq;
            else if(pos_temp == DIREITA) ant->dir = temp->esq;
            free(temp);
            return(1);
        }
        
        //quando tem direita e esquerda. Pega o maior elemento da esquerda (elemento mais a direita da esquerda) e troca de lugar com o valor a ser removido
        No *temp2;
        No *ant2 = NULL;
        if(temp->esq != NULL && temp->dir != NULL){
            temp2 = temp->esq;
            while(temp2->dir!=NULL){
                ant2 = temp2;
                temp2 = temp2->dir;
            }
            
            temp->valor = temp2->valor;
            if(ant2 != NULL) ant2->dir = temp2->esq;
            // if(ant2 != NULL) ant2->dir = NULL;
            
            if(temp->esq == temp2) temp->esq = temp2->esq;
            
            free(temp2);
            return(1);
        }
            
    }
    
    return(0); // quando está vazia retorna 0
}
*/

void liberarArvore(Arvore *a){
    free(a);
}


int busca_menor(No *no){
    int menor = no->valor;
    No *temp = no;
    No *ant = NULL;

    while(temp->esq != NULL){
      
        temp = temp->esq;
    }
    menor = temp->valor;
    return menor;
}

int noRaiz(No *n){
    return n->valor;
}

No* removeA(No *no, int valor){
    if(no == NULL){
        return NULL;
    }
    printf("\nErro aqui 1");
    if(valor < no->valor){
                printf("\nErro aqui 2");
            printf("--\nValor no->valor -- %d", no->valor);
            no->esq = removeA(no->esq, valor);
                printf("\nErro aqui 3");

            if(altura(no->esq) - altura(no->dir) == 2){
                    printf("\nErro aqui 4");

                if(altura(no->dir->esq) <= altura(no->dir->dir)){
                        printf("\nErro aqui 5");
                        no = rotacaoRR(no);


                }
                else{
                    printf("\nErro aqui 6");

                    no = rotacaoLL(no);

                }
            }
    }else if(valor > no->valor){
        no->dir = removeA(no->dir, valor);
            if(altura(no->esq) - altura(no->dir) >= 2){
                if(altura(no->esq->dir) <= altura(no->esq->esq))
                    no = rotacaoLL(no);
                else
                    no = rotacaoLR(no);
            }
        
    }else if(no->valor == valor){
        if(no->dir == NULL || no->esq == NULL){
            printf("\n estou aqui10");
            No *ant_no = no;
            if(no->esq != NULL)
                no = no->esq;
            else
                no = no->dir; 
            printf("\n estou aqui11");

        }else{
            printf("\n estou aqui12");

            no->valor = busca_menor(no->dir);
            no->dir = removeA(no->dir, no->valor);
                        printf("\n estou aqui13");

            if(altura(no->esq) - altura(no->dir) == 2){
                if(altura(no->esq->dir) <= altura(no->esq->esq))
                    no = rotacaoLL(no);
                else
                    no = rotacaoLR(no);
            printf("\n estou aqui14");

            }
            return no;
        }
        printf("\n Estou aqui 15");
        return no;
    }
}
 
int altura(No *no) {
  if(no == NULL){
      return -1;
  }else{
      return no->fatorBal;
  }
}

int maior(int x, int y){
    if(x > y) return x;
    else return y;
}

No* rotacaoLL(No *no){
    printf("\n ---- Rotacionou RR ---- \n");

    No *aux = no->esq;
    no->esq = aux->dir;
    aux->dir = no;
printf("\nAqui 13\n");
    no->fatorBal = (maior(altura(no->dir), altura(no->esq)) + 1);

    aux->fatorBal = (maior(altura(no->esq), no->fatorBal) + 1);
    printf("\nAqui 14\n");
    return aux;
}

No* rotacaoRR(No *no){
        printf("\n ---- Rotacionou LL ---- \n");

    No *aux = no->dir;
    no->dir = aux->esq;
    aux->esq = no;
printf("\nAqui 10\n");
    no->fatorBal = (maior(altura(no->dir), altura(no->esq)) + 1);
    aux->fatorBal = (maior(altura(no->dir), no->fatorBal) + 1);
printf("\nAqui 11\n");
    
    return aux;
}

No* rotacaoRL(No *no){
        printf("\n ---- Rotacionou LR ---- \n");

    no->dir = rotacaoLL(no->dir);

    return(rotacaoRR(no));
}

No* rotacaoLR(No *no){
            printf("\n ---- Rotacionou RL ---- \n");

    no->esq = rotacaoRR(no->esq);

    return(rotacaoLL(no));
}

No* criarNo(int valor){
   
    No *no = (No*) malloc(sizeof(No));
   
    if(no == NULL){
        //Alocacao falhou!
        return 0;
    }

    no->valor = valor;
    no->fatorBal = 0;
    no->esq = NULL;
    no->dir = NULL;
    return no;
}

No* insereAVL(No *no, int valor){

    if(no == NULL){
        return criarNo(valor);;
    }

    if(valor <= no->valor){
        no->esq = insereAVL(no->esq, valor);
            if(altura(no->esq) - altura(no->dir) == 2){
                if(valor < (no->esq->valor)){
                    printf("\nAqui 1\n");
                    no = rotacaoLL(no);
                    printf("\nAqui 2\n");
                }else{
                    printf("\nAqui 3\n");
                    no = rotacaoLR(no);
                    printf("\nAqui 4\n");
                }
            }
    }else{
        if(valor >= no->valor){
            no->dir = insereAVL(no->dir, valor);
                if(altura(no->dir) - altura(no->esq) == 2){
                    if(no->dir->valor < valor){
                        printf("\nAqui 5\n");
                        no = rotacaoRR(no);
                        printf("\nAqui 6\n");
                    }else{
                        printf("\nAqui 7\n");
                        no = rotacaoRL(no);
                        printf("\nAqui 8\n");
                    }
                }
        }
    }
    no->fatorBal = maior(altura(no->esq), altura(no->dir)) + 1;
    printf("\nAqui 9\n");
    return no;
}
 
