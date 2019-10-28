#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h> 
int main()
{
    int sayi = 0;
    int pid,status;

    printf("Lütfen bir sayi giriniz \n");
    scanf("%d", &sayi);

       if(sayi <= 0)
    {
          printf("Lütfen 0'dan büyük ve pozitif bir sayi giriniz. \n");
      scanf("%d", &sayi);
    }

    pid = fork();

    if(pid < 0)
    {
      printf("Görev oluşumu başarısız oldu. \n");
      exit(-1);
    }

    else if(pid == 0)
    {
             do
        {
        if(sayi%2 != 0)
        {
          sayi = (sayi*3)+1;
                }

        else if(sayi%2 == 0)
        {
          sayi = sayi/2;
        }

        printf("%d \n",sayi);
        }while(sayi != 1);
    }

    else
    {

        printf("pid %d \n",pid);
    printf("Görevin sonlandırılması bekleniyor... \n");
      wait(&status);
      }
