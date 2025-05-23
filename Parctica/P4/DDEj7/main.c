#include <stdio.h>
#include <stdlib.h>
#define FIN=0

void inicializar_lista(nodo **p,int n);
void imprimir_lista(nodo *p);
void agregar_elemeto_final(nodo **p,int e);
void agregar_elemeto_principio(nodo **p,int e);
void eliminar_lista(nodo **p);
int main()
{


    return 0;
}

void inicializar_lista(nodo **p,int n){
    int i=0;
    for(i=0;i<n;i++){
        *p=(nodo*) malloc(sizeof(nodo));
        (*p)->dato=i+1;
        p=&((*p)->sig);
    }
    *p=NULL;
}

void eliminar_lista(nodo **p){
    int i=0;
    nodo *aux;
    while(*p!=NULL){
        aux=(*p)->sig;
        free(*p);
        *p=aux;
    }
}

void agregar_elemeto_principio(nodo **p,int e){
    nodo *aux=(nodo*)malloc(sizeof(nodo));
    aux->dato=e;
    aux->sig=*p;
    *p=aux;
}

void agregar_elemeto_final(nodo **p,int e){
    if(*p==NULL){
       *p=(nodo*)malloc(sizeof(nodo));
       (*p)->dato=e;
       (*p)->sig=NULL;
    }
    else{
        nodo *aux=*p;
        while(aux->sig!=NULL)aux=aux->sig;
        aux->sig=(nodo*)malloc(sizeof(nodo));
        aux=aux->sig;
        aux->dato=e;
        aux->sig=NULL;
    }
}

void imprimir_lista(nodo *p){
    printf("- ");
    while(p!=NULL){
        printf("%d - ",p->dato);
        p=p->sig;
    }
    printf("\n");
}



