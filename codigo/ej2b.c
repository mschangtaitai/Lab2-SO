#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    
    clock_t clock1;
    clock_t clock2;

    clock1 = clock();

    if(fork() == 0){
        if(fork() == 0){
            if(fork() == 0){
                for (int i = 0; i < 1000000; i++){
                    printf("%d \n", i);
                }
            }
            else{
                for (int i = 0; i < 1000000; i++){
                    printf("%d \n", i);
                }
                wait(NULL);
            }
        }
        else{
            for (int i = 0; i < 1000000; i++){
                printf("%d \n", i);
            }
            wait(NULL);
        }
    }
    else{
        wait(NULL);
    }

    clock2 = clock();

    double resta = (double)(clock2 - clock1);

    printf("%f \n", resta);

}
