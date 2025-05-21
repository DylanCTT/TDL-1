#include <stdio.h>
int main(){
char c= 'a';
int x = 2*32+10%2-1;
printf("int x= %d\n", x);
return 0;
}
/* (a) se puede hacer esto ya que cuando se le asigna a un char un integer se lo busca en la tabla ascii y viceversa */
/*(b) un double tiene precision doble, quiere decir que puede representar numeros con más exactitud mientras que el float representa una menor cantidad de numeros y ocupa menos */
/*(c) cuando hace x = 2*32+10%2-1, primero va a hacer * y despues % de izquierda a derecha y luego la resta*/
/*(d) el sizeof sirve para saber cuando pesa, en bytes un tipo de dato */
