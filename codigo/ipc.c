#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <sys/wait.h>


int main() {

    char x;
    int n;
    
    printf("Enter the letter: ");
    scanf("%c", &x);
    printf("Enter the number: ");
    scanf("%d", &n);

    key_t Clave;
    int Id_Memoria;
    int *Memoria = NULL;
    int i,j;

    Clave = ftok ("/bin/ls", 33);
    if(Clave == -1)
    {
        printf("No consigo clave para memoria compartida");
        exit(0);
    }
    
    Id_Memoria = shmget (Clave, sizeof(int)*100, 0777 | IPC_CREAT);
    if(Id_Memoria == -1)
    {
        printf("No consigo Id para memoria compartida");
        exit(0);
    }

    Memoria = (int *)shmat (Id_Memoria, (char *)0, 0);
    if(Memoria == NULL)
    {
        printf("No consigo memoria compartida");
        exit(0);
    }

    if (fork() == 0){
        Memoria[0] = n;
        Memoria[1] = x;
        for (int i = 0; i < Memoria[0]; i++)
            printf("%c \n", Memoria[i+2]);
    }
    else{
        wait(NULL);
        int num = Memoria[0];
        char cha = Memoria[1];
        for (int i = 0; i < num; i++){
            Memoria[i+2] = cha;       
        }
        
    }

    shmdt ((char *)Memoria);
    shmctl (Id_Memoria, IPC_RMID, (struct shmid_ds *)NULL);

    return 0;

}
