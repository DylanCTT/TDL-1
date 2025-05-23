#include <stdio.h>
#include <stdlib.h>

struct nodo
{
    int dato;
    struct nodo *sig;
};
typedef struct nodo nodo;

void inicializar_lista(nodo **p,int n);
void imprimir_lista(nodo *p);
void eliminar_lista(nodo **p);
void eliminar_elemento(nodo **p,int e);
void agregar_elemeto_principio(nodo **p,int e);
void agregar_elemeto_final(nodo **p,int e);
int cant_elementos(nodo *p);
int main(){
    /*
    Si no pongo NULL explicitamente, me reservaba aún así
    espacio de memoria para una struct lista en todo 0
    */
    nodo *p=NULL;
    int i;
    inicializar_lista(&p,5);
    imprimir_lista(p);
    agregar_elemeto_principio(&p,0);
    imprimir_lista(p);
    agregar_elemeto_final(&p,6);
    imprimir_lista(p);
    printf("%d",cant_elementos(p));
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
void eliminar_elemento(nodo **p,int e){
    nodo *act=*p,*ant=*p;
    if(act!=NULL){
        while(act!=NULL){
            while(act!=NULL&&act->dato!=e){
                ant=act;
                act=act->sig;
            }
            if(act!=NULL){
                if(ant==act){
                    *p=act->sig;
                    free(act);
                    act=*p;
                    ant=act;
                }
                else{
                    ant->sig=act->sig;
                    free(act);
                    act=ant->sig;
                }
            }
        }
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
int cant_elementos(nodo *p){
    int cont=0;
    while(p!=NULL){
        cont++;
        p=p->sig;
    }
    return cont;
}
void imprimir_lista(nodo *p){
    printf("- ");
    while(p!=NULL){
        printf("%d - ",p->dato);
        p=p->sig;
    }
    printf("\n");
}
