#include <stdio.h>
#include <stdlib.h>

struct lista
{
    int dato;
    struct lista *sig;
};
typedef struct lista lista;

void inicializar_lista(lista **p,int n);
void imprimir_lista(lista *p);
void eliminar_lista(lista **p);
void eliminar_multiplo(lista **p,int e);
void agregar_elemeto_principio(lista **p,int e);
void agregar_elemeto_final(lista **p,int e);
int cant_elementos(lista *p);
int main(){
    lista *p=NULL;
    int num;
    scanf(" %d",&num);
    while(num!=0){
        agregar_elemeto_final(&p,num);
        scanf(" %d",&num);
    }
    imprimir_lista(p);
    printf("Ingrese multiplo:");
    scanf(" %d",&num);
    eliminar_multiplo(&p,2);
    imprimir_lista(p);
    eliminar_lista(&p);
    imprimir_lista(p);
}

void inicializar_lista(lista **p,int n){
    int i=0;
    for(i=0;i<n;i++){
        *p=(lista*) malloc(sizeof(lista));
        (*p)->dato=i+1;
        p=&((*p)->sig);
    }
}
void eliminar_lista(lista **p){
    int i=0;
    lista *aux;
    while(*p!=NULL){
        aux=(*p)->sig;
        free(*p);
        *p=aux;
    }
}
void eliminar_multiplo(lista **p,int e){
    lista *act=*p,*ant=*p;
    if(act!=NULL){
        while(act!=NULL){
            while(act!=NULL&&act->dato%e!=0){
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
void agregar_elemeto_principio(lista **p,int e){
    lista *aux=(lista*)malloc(sizeof(lista));
    aux->dato=e;
    aux->sig=*p;
    *p=aux;
}
void agregar_elemeto_final(lista **p,int e){
    if(*p==NULL){
       *p=(lista*)malloc(sizeof(lista));
       (*p)->dato=e;
       (*p)->sig=NULL;
    }
    else{
        lista *aux=*p;
        while(aux->sig!=NULL)aux=aux->sig;
        aux->sig=(lista*)malloc(sizeof(lista));
        aux=aux->sig;
        aux->dato=e;
        aux->sig=NULL;
    }
}
int cant_elementos(lista *p){
    int cont=0;
    while(p!=NULL){
        cont++;
        p=p->sig;
    }
    return cont;
}
void imprimir_lista(lista *p){
    printf("- ");
    while(p!=NULL){
        printf("%d - ",p->dato);
        p=p->sig;
    }
    printf("\n");
}
