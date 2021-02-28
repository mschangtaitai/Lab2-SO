#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main(){

    if(fork() == 0){
        for (int i = 0;i < 10000000; i++){
            printf("%d", i);
        }
        printf("This is the child!");
        
    }
    else{
        while(1) {
            
        }
    }

    return 0;
}
