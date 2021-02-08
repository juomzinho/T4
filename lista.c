#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "lista.h"
#include "resolveQry.h"
#include "posto.h"
#include "covid.h"

typedef struct node{
    Info info;
    struct node *anterior;
    struct node *proximo;
} NoStruct;

typedef struct lista{
    NoStruct *primeiro;
    NoStruct *ultimo;
} ListaStruct;


Lista create(){

    ListaStruct* lista = (ListaStruct*) malloc(sizeof(ListaStruct));
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    return lista;

};

void insere(Lista l, Info info){

    ListaStruct* lista = (ListaStruct*) l;

    NoStruct* no = (NoStruct*) malloc(sizeof(NoStruct));
    no->info = info;

    if(lista->primeiro == NULL){
        no->anterior = NULL;
        lista->primeiro = no;
    }
    else{
        lista->ultimo->proximo = no;
        no->anterior = lista->ultimo;
    }

    no->proximo = NULL;
    lista->ultimo = no;
    
}


void insertAfter(Lista l, Info posicao, Info info){
    ListaStruct* lista = (ListaStruct*) l;
    NoStruct* aux = lista->primeiro, *no;
    no = (NoStruct*) malloc (sizeof(NoStruct));

    no->info = info;

    while (aux!=NULL){
        if (getInfo(aux)==posicao){
            no->proximo = aux->proximo;
            no->anterior = aux;
            aux->proximo = no;
        }
        aux = getNext(aux);
    }
    
}


void insertBefore(Lista l, Info posicao, Info info){
    ListaStruct* lista = (ListaStruct*) l;
    NoStruct* aux = lista->primeiro, *no;
    no = (NoStruct*) malloc (sizeof(NoStruct));

    no->info = info;

    while (aux!=NULL){
        if (getInfo(aux)==posicao){
            no->proximo = aux;
            no->anterior = aux->anterior;
            aux->anterior = no;
            if (no->anterior == NULL){
                lista->primeiro = no;
            }else{
                no->anterior->proximo = no;
            }
                 
        }
        aux = aux->proximo;
    }
}

int length(Lista l){
    No node = getFirst(l);
    int i = 0; 

    while (node!=NULL){
        i++;
        node = getNext(node);
    }
    
    return i;
}


No getFirst(Lista lista){
    ListaStruct* l = (ListaStruct*) lista;
    return l->primeiro;
}

No getLast(Lista lista){
    ListaStruct* l = (ListaStruct*) lista;
    return l->ultimo;
}

No getNext(No elemento){
    NoStruct* no = (NoStruct*) elemento;
    return no->proximo;
}

No getPrevious(No elemento){
    NoStruct* no = (NoStruct*) elemento;
    return no->anterior;
}

Info getInfo(No elemento){
    NoStruct* no = (NoStruct*) elemento;
    return no->info;
}

void desalocaLista(Lista l){
    ListaStruct* lista = (ListaStruct*) l;
    NoStruct *aux, *aux2;

    aux = lista->primeiro;

    while (aux!=NULL){
        aux2 = aux->proximo;
        free(aux->info);
        free(aux);
        aux = aux2;
    }   
}

void removeElemento(Lista l, Info info){
    ListaStruct* lista = (ListaStruct*) l;
    NoStruct *aux, *aux2;
    aux = lista->primeiro;
    
    while (aux!=NULL){
        if(aux->info == info){
            if (aux==lista->primeiro){
                lista->primeiro = aux->proximo;
                aux->proximo->anterior = NULL;
            }else if(aux==lista->ultimo){
                lista->ultimo = aux->anterior;
                aux->anterior->proximo = NULL;
            }else{
                aux2 = aux->proximo;
                aux2->anterior = aux->anterior;
                aux2->proximo->anterior = aux2;

                if(aux->anterior!=NULL){
                    aux->anterior->proximo = aux2;
                }
            }
            
            free(aux->info);
            free(aux);
            break;
         }
        aux = aux->proximo;
    }  
}

void alterarAtras(NoStruct *node, int h, double x, double y){
    int cont = 0;
    NoStruct* aux = node, aux2;

    while (cont != h && aux != NULL){
        aux = getPrevious(aux);
        cont++;
    }
    if (aux == NULL){
        return;
    }
    if (dist(x, y, getXPS(getInfo(node)), getYPS(getInfo(node))) < dist(x, y, getXPS(getInfo(aux)), getYPS(getInfo(aux)))){
        aux2.info = node->info;
        node->info = aux->info;
        aux->info = aux2.info;
        alterarAtras(aux, h, x ,y);
    }else{
        return;
    }
}


void shellSort(Lista lista, int size, double x, double y){
	int h = size/2, cont;
    NoStruct *node, *aux, aux2;  
    

	while (h > 0){
        aux = getFirst(lista); 
        node = getFirst(lista);

        cont = 0;
        while (cont != h){
            aux = getNext(aux);
            cont++;
        }
        
        while (aux!=NULL){
            if (dist(x, y, getXPS(getInfo(aux)), getYPS(getInfo(aux))) < dist(x, y, getXPS(getInfo(node)), getYPS(getInfo(node)))){
                aux2.info = node->info;
                node->info = aux->info;
                aux->info = aux2.info;
           
                alterarAtras(node, h, x, y);
            }
            aux = getNext(aux);
            node = getNext(node);
        }

        h /= 2;

	}
	
}

void swap(Lista lista, int min){
    NoStruct *node1, *node2, aux;

    node1 = getFirst(lista);
    for (int i = 0; i < min; i++){
        node1 = getNext(node1);
    }
    node2 = getFirst(lista);

    aux.info = node1->info;
    node1->info = node2->info;
    node2->info = aux.info;    
}

void quickSort(Lista lista, int inicio, int size){
    int i = inicio;
    int j = size-1;
    NoStruct *aux, *pivo, *aux2, aux3;
    Info *d1, *d2;

    pivo = getFirst(lista);
    for (int k = 0; k < ((inicio+size)/2); k++){
        pivo = getNext(pivo);
    }
    d1 = getInfo(pivo);

    while(i<=j){
        aux = getFirst(lista);
        for (int k = 0; k < i; k++){
            aux = getNext(aux);
        }
        d2 = getInfo(aux);

        while(compare(getInfo(getFirst(lista)), d1, d2) > 0 && i < size){
                aux = getNext(aux);
                d2 = getInfo(aux);
                i++;
        }

        aux = getFirst(lista);
        for (int k = 0; k < j; k++){
            aux = getNext(aux);
        }
        d2 = getInfo(aux);
        while(compare(getInfo(getFirst(lista)), d2, d1) > 0 && j > inicio){
                aux = getPrevious(aux);
                d2 = getInfo(aux);

                j--;
        }
        
        if (i <= j){
            aux2 = getFirst(lista);
            for (int k = 0; k < j; k++){
                aux2 = getNext(aux2);
            }
            aux = getFirst(lista);
            for (int k = 0; k < i; k++){
                aux = getNext(aux);
            }

            aux3.info = aux->info;
            aux->info = aux2->info;
            aux2->info = aux3.info;
            j--;
            i++;
        }
        
    }
    if (inicio < j){
        quickSort(lista, inicio, j + 1);
    }if (size > i){
        quickSort(lista, i, size);
    }
}