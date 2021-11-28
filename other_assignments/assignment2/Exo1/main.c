#include <stdio.h>
#include <stdlib.h>

int i=0;

char *crypt(char *message_clair,int decalage)
{
    char *message_crypt;
    message_crypt = (char*) malloc(20*sizeof(char));
    while(message_clair[i] != NULL)
    {
        if((message_clair[i] >= 97 && message_clair[i] < 122) || (message_clair[i] >= 65 && message_clair[i] < 90))
            message_crypt[i] = message_clair[i] + decalage;
        else
            message_crypt[i] = message_clair[i];

        i++;
    }
    return message_crypt;
}

char *clair(char message_crypt[20],int decalage)
{
    char *message_clair;
    message_clair = (char*) malloc(20*sizeof(char));
    while(message_crypt[i] != NULL)
    {
        if((message_crypt[i] > 97 && message_crypt[i] <= 122) || (message_crypt[i] > 65 && message_crypt[i] <= 90))
            message_clair[i] = message_crypt[i] - decalage;
        else
            message_clair[i] = message_crypt[i];
        i++;
    }
    return message_clair;
}

int main()
{
    int choix, decalage;
    char message[20];

    printf("Donner le text: ");
    scanf("%s",message);
    //////////////////////////
    printf("Donner la quantum du décalage: ");
    scanf("%d",&decalage);
    //////////////////////////
    printf("1- Crypte\n2- Decrypte\nVotre choix: ");
    scanf("%d",&choix);
    //////////////////////////
    printf("Le nouveau text: ");
    switch(choix)
    {
    case 1:
        printf("%s",crypt(message,decalage));
    break;
    case 2:
        printf("%s",clair(message,decalage));
    break;
    }
    return 0;
}
