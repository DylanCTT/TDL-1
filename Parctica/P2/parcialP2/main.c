#include <stdio.h>
#include <stdlib.h>

unsigned F (unsigned N);
int main()
{
    unsigned N=7;
    while (N){
        N=N^F(N);
        printf("N= %u \n", N);
    }
    return 0;
}
unsigned F(unsigned N){
    static unsigned mask =1;
    unsigned aux= N& mask;
    mask=mask<<1;
    return (aux);
}
