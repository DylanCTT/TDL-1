
#include <stdio.h>
#include <stdlib.h>

int potencia(int x, int y){
    int i, res=1;
    for (i=0;i<=y;i++){
        res+=res*x;
    }
    return res;
}

int cuadrado(int x){
    return x*x;
}

int cubo(int x){
    return (x*x)*x;
}
int absoluto(int i){
    if(i<0){
        return i*(-1);
    }
    else {
        return i;
    }
}

int factorial (int i){
    int j,res=1;
    for (j=1;j<i;j++){
        res*=j;
    }
    return res;
}

int sumatoria (int i){
    int j=0, suma=0;
    for (j=1;j<=i;j++){
        suma+=j;
    }
    return suma;
}

int multiplo (int x, int y){
    if ((x%y) ==0){
        return 1;
    }
    else return 0;
}

int par (int i){
    if((i%2) ==0){
        return 1;
    }
    else return 0;
}

int impar (int i){

    if((i%2)!=0){
        return 1;
    }
    else return 0;
}
