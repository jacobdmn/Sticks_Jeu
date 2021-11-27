#include <stdio.h>
#include <stdlib.h>
void Logo() // The LOGO of the game :)
{
    space();
    space();
    printf(" -------------------------------------------\n");
    space();
    space();
    printf("|  ######  ######## ########  #####  ###### |\n");
    space();
    space();
    printf("|  #          ##       ##    ##      #      |\n");
    space();
    space();
    printf("|  ######     ##       ##    ##      ###### |\n");
    space();
    space();
    printf("|       #     ##       ##    ##           # |\n");
    space();
    space();
    printf("|  ######     ##    ########  #####  ###### |\n");
    space();
    space();
    printf(" -------------------------------------------\n");
}
void Bienvenue()   // Introduction de ce jou
{
    Logo();
    printf("\n");
    space();
    printf("Bienvenue a tous..\n");
    Sprtiv(60);
    space();
    printf("Voici Un Petit Jeu Des Sticks,\n");
    space();
    printf("Et Vous Pouvez Prendre 1, 2 ou 3 Sticks Seulement,\n");
    space();
    printf("Et Le Joueur Qui Prend Le Dernier Stick Est Perdu !\n");
    space();
    printf("Bon, Commencons mes amis :)\n");
    Sprtiv(60);
}
void space()  // juste un petit espace qui utilise bcp dans ce programme
{
	printf("\t");
}
void Sprtiv(int n_moin)  // n_sep = nombre des moins
{
	int i;
	space();
	for (i = 1; i <= n_moin; i++)
	{
		printf("-");
	}
	printf("\n");

}
int getLvl()  // For get the number of level
{
    int niveau;
    {  // Explication de les niveaux de ce jou.
    printf("\n");
    space();
    printf("Il y a 3 niveaux Dans ce Jou:\n\n");
    space();
    printf("1- Facile.");
    space();
    printf("2- Moyenne.");
    space();
    printf("3- Difficle.\n");
    Sprtiv(45);
    space();
    }
    printf("Donner Le Nombre De Votre Niveau svp: ");

    ////// boucle pour protéger le SCANF
    do
    {
        scanf("%d",&niveau);
        if (niveau<1 || niveau>3)
		{
			space();

			printf("Svp entrer un niveau parmi ces 3 valables ! : ");
		}
    }
    while(niveau<1 || niveau>3);

    Sprtiv(40);
    space();
    printf("Vous Avez Choisis : Niveau ");
	switch(niveau)   // afficher le niveau choiser
	{
    case 1: printf("Facile\n"); break;
    case 2: printf("Moyenne\n"); break;
    case 3: printf("Defficile\n"); break;
	}
    return niveau;
}
int howStart()  // For Ask the user who start the game
{
    int joueur;
    Sprtiv(40);
    space();
    printf("Bon, Qui Commence ?\t");
    printf("0-PC\t1-Vous\n");
    Sprtiv(40);
    space();
    printf("Votre Choix: ");
	do
	{
        scanf("%d",&joueur);
		if (joueur < 0 || joueur > 1)
		{
			space();
			printf("Choix Non valable !, Recommencer: ");
		}
	}
	while (joueur < 0 || joueur > 1);
	return joueur;
}
void Init() // this is the full faction
{
    int n=rand()%30+23,niveau=getLvl();
    /////////////////////////////////
	Sprtiv(40);
	space();
	printf("On prend %d sticks.. \n",n);

    ///// Start the game !
    /* ............ */
    // this step For Call the required level
    if(niveau==1)
        Facile(n,howStart());
    else
        if(niveau==2)
            Moyenne(n,howStart());
        else
            Defficile(n,howStart());
}

/* the three levels:
    - Easy
    - Middle
    - Hard
*/
int x;  // cette variable est utilisé dans les 3 niveaux donc il faut que lui mise en variable GLOBALE
void Facile(int n, int joueur)  // Easy Level
{

    while(n>1)
    {
        Sprtiv(33);
        space();
        printf("Il y a %d Sticks, ",n);
        if(joueur==0)
        {
            x=rand()%3+ 1;
            printf("J'enleve %d\n",x);
        }
        else
        {
            printf("Votre coup : ");
            ////// boucle pour protéger le SCANF
            do
            {
                do
                {
                    scanf("%d",&x);
                    if (x<1 || x>3)
                    {
                        space();
                        printf("Svp entrer un nombre parmi 1 et 3 suelement ! : ");
                    }

                }
                while(x<1 || x>3);
                if (n<=x)
                {
                    space();
                    printf("Svp entrer un nombre moins de le nombre total ! : ");
                }
            }
            while(n<=x);
        }
        n-=x;
        joueur=!joueur;
    }
    Sprtiv(33);
    detect_rslt(joueur);
}
void Moyenne(int n, int joueur)   // Middle Level
{
    while(n>1)
    {
        Sprtiv(33);
        space();
        printf("Il y a %d Sticks, ",n);
        if(joueur==0)
        {
            x=n%4;

            if(n>10)
            {
                if(x==0 || x==2)
                    x=1;
                else if(x==1)
                    x=3;
            }
            else if(n>5)
            {
                if(x==0)
                    x=3;
                else if(x==3)
                    x=2;
                else if(x==2)
                    x=1;
            }
            else
            {
                if(n==4)
                    x=3;
                else if(n==3)
                    x=2;
                else if(n==2)
                    x=1;
            }
            printf("J'enleve %d\n",x);
        }
        else
        {
            printf("Votre coup : ");
            ////// boucle pour protéger le SCANF
            do
            {
                do
                {
                    scanf("%d",&x);
                    if (x<1 || x>3)
                    {
                        space();
                        printf("Svp entrer un nombre parmi 1 et 3 suelement ! : ");
                    }

                }
                while(x<1 || x>3);
                if (n<=x)
                {
                    space();
                    printf("Svp entrer un nombre moins de le nombre total ! : ");
                }
            }
            while(n<=x);
        }
        n-=x;
        joueur=!joueur;
    }
    Sprtiv(33);
    detect_rslt(joueur);
}
void Defficile(int n, int joueur)  // Hard Level
{
    while(n>1)
    {
        Sprtiv(33);
        space();
        printf("Il y a %d Sticks, ",n);
        if(joueur==0)
        {
            x=n%4;
            if(x==1 || x==3)
                x=2;
            else if(x==2)
                x=1;
            else if(x==0)
                x=3;
            printf("J'enleve %d\n",x);
        }
        else
        {
            printf("Votre coup : ");
            ////// boucle pour protèger le SCANF
            do
            {
                do
                {
                    scanf("%d",&x);
                    if (x<1 || x>3)
                    {
                        space();
                        printf("Svp entrer un nombre parmi 1 et 3 suelement ! : ");
                    }

                }
                while(x<1 || x>3);
                if (n<=x)
                {
                    space();
                    printf("Svp entrer un nombre moins de le nombre total ! : ");
                }
            }
            while(n<=x);
        }
        n-=x;
        joueur=!joueur;
    }
    Sprtiv(33);
    detect_rslt(joueur);
}
void detect_rslt(int joueur)    // this fanction for detect the result and print it
{
    if(joueur==1)
        gameOver();
    else
        Bravo();
}
void gameOver()   // For print the text " Game Over "
{
    Sprtiv(65);
    space();
	printf("     ####    ##    ##   ##   ###    ###  #   #  ### ####   |\n");
	space();
	printf("    #       #  #   # # # #  #      #   # #   # #    #  #   |\n");
	space();
	printf("    #  ##  ######  #  #  #  ####   #   # #   # #### ###    |\n");
	space();
	printf("    #   #  #    #  #     #  #      #   #  # #  #    #  #   |\n");
	space();
	printf("     ####  #    #  #     #   ###    ###    #    ### #  #   .\n");
	Sprtiv(65);
	printf("\n\n");
}
void Bravo()     // For print the text " Bravo "
{
    Sprtiv(65);
    space();
    space();
    printf("#######   #####        #   #       #  ######    |\n");
    space();
    space();
    printf("#      #  #    #      # #   #     #  #      #   |\n");
    space();
    space();
    printf("#######   #####      #####   #   #   #      #   |\n");
    space();
    space();
    printf("#      #  #    #    #     #   # #    #      #   |\n");
    space();
    space();
    printf("#######   #     #  #       #   #      ######    .\n");
    Sprtiv(65);
    printf("\n\n");
}
void PoweredBy() // le signature des programmeurs
{
    printf("\n");
    space();
    printf("This Project Powered By:\n");
    printf("\t- Bilal Bentoumi\n");
    printf("\t- Yakoub Demmane\n");
}

int main()
{
    int choix=0;
    Bienvenue();
    do
    {
        Init();
        Sprtiv(60);
        Sprtiv(60);
        printf("\n");
        space();
        printf("Voulez-vous rejouer ? (Entrer '1' Pour Rejouer) : ");
        scanf("%d",&choix);
        Sprtiv(60);
    }
    while(choix==1);
    {  // Just Print info about the programmers
    Sprtiv(60);
    printf("\n");
    space();
    printf("Mercii Pour Votre etant, En Voir :)\n");
	Sprtiv(60);
	PoweredBy();
	Sprtiv(60);
    printf("\n");
    }
    return 0;
}
