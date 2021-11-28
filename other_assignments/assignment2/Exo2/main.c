#include <stdio.h>
#include <stdlib.h>

int echiq[8][8], i, j, colour=1;    // 1= noir 2= blanche

int color_case()
{
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            echiq[i][j] = colour;
            colour = !colour;
        }
        colour = !colour;
    }
    printf("Ca c'est l'echiq:\n\n");
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
            printf("%d|",echiq[i][j]);
        printf("\n");
    }
    printf("\n------------------\n");
    printf("Donner les cordonnées [i,j], (Ecrire derectement x,y): ");
    scanf("%d,%d",&i,&j);
    ///////////////////////////
    printf("La case est: ");
    if(echiq[i][j] == 1)
        printf("NOIR\n");
    else
        printf("BLANCHE\n");
}

void **Fou()
{
    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
           echiq[i][j] = 0;

    // les cordonnées du fou.
    printf("Donner les cordonnées du fou: ");
    scanf("%d,%d",&i,&j);

    int l=1,k=1;

    while((i+l)<8 && (i+l)>=0 && (j+k)<8 && (j+k)>=0)
    {
        echiq[i+l][j+k] = 1;
        l++; k++;
    }
    l=1,k=1;
    while((i+l)<8 && (i+l)>=0 && (j-k)<8 && (j-k)>=0)
    {
        echiq[i+l][j-k] = 1;
        l++; k++;
    }
    l=1,k=1;
    while((i-l)<8 && (i-l)>=0 && (j+k)<8 && (j+k)>=0)
    {
        echiq[i-l][j+k] = 1;
        l++; k++;
    }
    l=1,k=1;
    while((i-l)<8 && (i-l)>=0 && (j-k)<8 && (j-k)>=0)
    {
        echiq[i-l][j-k] = 1;
        l++; k++;
    }
    // '70' en 'ASCII' c'est le lettre 'F', puis, On le va afficher comme un Carèctère :)
    echiq[i][j] = 70;

    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
            if(echiq[i][j] == 70)
               printf("%c|",echiq[i][j]);
            else
                printf("%d|",echiq[i][j]);
        printf("\n");
    }
}

void **Cavalier()
{
    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
           echiq[i][j] = 0;

    // les cordonnées du cavalier.
    printf("Donner les cordonnées du cavalier: ");
    scanf("%d,%d",&i,&j);

    echiq[i][j] = 67;   // 67 c'est 'C' en ASCII

    if(echiq[i-2][j+1]==0)
        echiq[i-2][j+1]=1;

    if(echiq[i-2][j-1]==0)
        echiq[i-2][j-1]=1;

    if(echiq[i+2][j+1]==0)
        echiq[i+2][j+1]=1;

    if(echiq[i+2][j-1]==0)
        echiq[i+2][j-1]=1;

    if(echiq[i-1][j+2]==0)
        echiq[i-1][j+2]=1;

    if(echiq[i-1][j-2]==0)
        echiq[i-1][j-2]=1;

    if(echiq[i+1][j+2]==0)
        echiq[i+1][j+2]=1;

    if(echiq[i+1][j-2]==0)
        echiq[i+1][j-2]=1;
    ////////////////////////
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
            if(echiq[i][j] == 67)
               printf("%c|",echiq[i][j]);
            else
                printf("%d|",echiq[i][j]);
        printf("\n");
    }
}

int main()
{
    int choix;

    printf("1-Colour des cases.\n");
    printf("2-Fou.\n");
    printf("3- Cavalier.\n");
    printf("Votre choix: ");

    scanf("%d",&choix);
    switch(choix)
    {
        case 1: color_case(); break;
        case 2: Fou(); break;
        case 3: Cavalier(); break;
        default: printf("choix indisponible!");
    }
    return 0;
}
