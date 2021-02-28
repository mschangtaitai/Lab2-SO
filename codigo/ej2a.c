#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main(){
    
    clock_t clock1;
    clock_t clock2;

    clock1 = clock();

    for (int i = 0; i < 1000000; i++){
        printf("%d \n", i);
    }
    for (int i = 0; i < 1000000; i++){
        printf("%d \n", i);    
    }
    for (int i = 0; i < 1000000; i++){
        printf("%d \n", i);
    }

    clock2 = clock();

    double resta = (double)(clock2 - clock1);

    printf("\n %f \n", resta);

}
