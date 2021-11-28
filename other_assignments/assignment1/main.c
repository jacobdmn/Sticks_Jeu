#include <stdio.h>
#include <stdlib.h>

int i,j,l;
int **m1, **m2, **rs;
float **rs_f, det;
int lin1, colo1,
    lin2, colo2,
    line, colonne;

int **addition(int **m1,int **m2,int lin1,int lin2,int colo1,int colo2)     // Fonction de l'addition
{
    if((lin1 == lin2) && (colo1 == colo2))
    {
        rs = (int**) malloc(lin1*sizeof(int*));
        for(i=0;i<lin1;i++)
            rs[i] = (int*) malloc(colo1*sizeof(int));
        for(i=0;i<lin1;i++)
            for(j=0;j<colo1;j++)
                rs[i][j] = m1[i][j] + m2[i][j];
        return rs;
    }
}

int **produit(int **m1, int **m2, int lin1, int colo1, int lin2, int colo2)     // Fonction du produit
{
    if(colo1 == lin2)
    {
        rs = (int**) malloc(lin1*sizeof(int*));
        for(i=0;i<lin1;i++)
            rs[i] = (int*) malloc(colo2*sizeof(int));
        for(i=0;i<lin1;i++)
            for(j=0;j<colo2;j++)
            {
                rs[i][j]=0;
                for(l=0;l<colo1;l++)
                    rs[i][j] += m1[i][l] * m2[l][j];
            }
        return rs;
    }
}

int **transpose(int **m, int lin, int colo)         // Function du transposé
{
    rs = (int**) malloc(colo*sizeof(int*));
    for(i=0;i<colo;i++)
        rs[i] = (int*) malloc(lin*sizeof(int));
    for(i=0;i<colo;i++)
        for(j=0;j<lin;j++)
            rs[i][j] = m[j][i];
    return rs;
}

float determenant(int **m, int width)         // Function de la déterminant
{
    if(width == 2)
        det = m[0][0]*m[1][1] - m[0][1]*m[1][0];
    else if(width == 3)
        det =   m[0][0]*m[1][1]*m[2][2] +
                m[0][1]*m[1][2]*m[2][0] +
                m[0][2]*m[1][0]*m[2][1]
                -
                m[0][1]*m[1][0]*m[2][2] -
                m[0][0]*m[1][2]*m[2][1] -
                m[0][2]*m[1][1]*m[2][0];
    return det;
}

float **mat_invrs(int **m, int width)
{
    rs_f = (float**) malloc(width*sizeof(float*));
    for(i=0;i<width;i++)
        rs_f[i] = (float*) malloc(width*sizeof(float));
    if(width == 3)
    {
        rs_f[0][0] =  (m[1][1]*m[2][2]-m[1][2]*m[2][1]);
        rs_f[0][1] = -(m[1][0]*m[2][2]-m[1][2]*m[2][0]);
        rs_f[0][2] =  (m[1][0]*m[2][1]-m[1][1]*m[2][0]);
        rs_f[1][0] = -(m[0][1]*m[2][2]-m[0][2]*m[2][1]);
        rs_f[1][1] =  (m[0][0]*m[2][2]-m[0][2]*m[2][0]);
        rs_f[1][2] = -(m[0][0]*m[2][1]-m[0][1]*m[2][0]);
        rs_f[2][0] =  (m[0][1]*m[1][2]-m[0][2]*m[1][1]);
        rs_f[2][1] = -(m[0][0]*m[1][2]-m[0][2]*m[1][0]);
        rs_f[2][2] =  (m[0][0]*m[1][1]-m[0][1]*m[1][0]);
    }
    else if(width == 2)
    {
        rs_f[0][0] =  m[0][0]*m[1][1];
        rs_f[0][1] = -m[0][1]*m[1][0];
        rs_f[1][0] =  m[1][0]*m[0][1];
        rs_f[1][1] = -m[1][1]*m[0][0];
    }
    rs_f = transpose(rs_f,width,width);
    for(i=0;i<width;i++)
        for(j=0;j<width;j++)
            rs_f[i][j] /= determenant(m,width);

    return rs_f;
}

int main()
{
    // les variables

    int choix, witch_m;

    // donner les lines et les colonnes de m1 & m2
{
        /* pour M1 */
    printf("Pour la matrice M1:\n");

    printf("Donner le nombre des lines: ");
    scanf("%d",&lin1);

    printf("Donner le nombre des colonnes: ");
    scanf("%d",&colo1);
    /*****************************************/
    /* pour M2 */
    printf("Pour la matrice M2:\n");

    printf("Donner le nombre des lines: ");
    scanf("%d",&lin2);

    printf("Donner le nombre des colonnes: ");
    scanf("%d",&colo2);

    /*****************************************/
}
    // alouer pour m1 & m2
{
    m1 = (int**) malloc(lin1*sizeof(int*));
    for(i=0;i<lin1;i++)
        m1[i] = (int*) malloc(colo1*sizeof(int));
    m2 = (int**) malloc(lin2*sizeof(int*));
    for(i=0;i<lin2;i++)
        m2[i] = (int*) malloc(colo2*sizeof(int));
}
    // charger m1 & m2
{
    // Charger le m1
    printf("-------M1-------\n");
    for(i=0;i<lin1;i++)
        for(j=0;j<colo1;j++)
        {
            printf("M1[%d,%d]=",i,j);
            scanf("%d",&m1[i][j]);
        }

    // Charger le m2
    printf("-------M2-------\n");
    for(i=0;i<lin2;i++)
        for(j=0;j<colo2;j++)
        {
            printf("M2[%d,%d]=",i,j);
            scanf("%d",&m2[i][j]);
        }
}
    // Demander de l'utilisateur
do
{

    printf("----------------\n");
    printf("- 1- Addition.\n");
    printf("- 2- Multiplication.\n");
    printf("- 3- Transposé.\n");
    printf("- 4- Déterminant.\n");
    printf("- 5- L'inverse de matrice.\n");
    /******************/
    printf("- Votre choix: ");
    scanf("%d",&choix);

    switch(choix)
    {
    case 1:
    // Fonction d'addition
    {
        printf("-------Matrice d'addition-------\n");
        rs = addition(m1,m2,lin1,lin2,colo1,colo2);
        if((lin1 == lin2) && (colo1 == colo2))
        {
            for(i=0;i<lin1;i++)
            {
                printf("\t");
                for(j=0;j<colo1;j++)
                    printf("%7d",rs[i][j]);
                printf("\n");
            }
        }
        else
            printf("On ne peut pas faire l'addition\n");
    }
    break;
    case 2:
    // Fonction du produit
    {
        printf("-------Matrice du produit-------\n");
        rs = produit(m1,m2,lin1,colo1,lin2,colo2);
        if(colo1 == lin2)
        {
            for(i=0;i<lin1;i++)
            {
                printf("\t");
                for(j=0;j<colo2;j++)
                    printf("%7d\t",rs[i][j]);
                printf("\n");
            }
        }
        else
            printf("On ne peut pas faire le produit\n");
    }
    break;
    case 3:
    // Fonction du transposé
    {
        printf("Choisez la matrice: M");
        scanf("%d",&witch_m);
        printf("-------Matrice transposé de 'M%d'-------\n",witch_m);
        if(witch_m == 1)
        {
            rs= transpose(m1,lin1,colo1);
            line=colo1;
            colonne=lin1;
        }
        else if(witch_m == 2)
        {
            rs= transpose(m2,lin2,colo2);
            line=colo2;
            colonne=lin2;
        }
        for(i=0;i<line;i++)
        {
            printf("\t");
            for(j=0;j<colonne;j++)
                printf("%7d\t",rs[i][j]);
            printf("\n");
        }

    }
    break;
    case 4:
    // Fonction de la déterminant
    {
        printf("Choisez la matrice: M");
        scanf("%d",&witch_m);
        if(witch_m == 1 && lin1 == colo1)
        {
            det = determenant(m1,lin1);
            printf("----Le détermenant----\n\t%d",det);
        }
        else if(witch_m == 2 && lin2 == colo2)
        {
            det = determenant(m2,lin2);
            printf("----Le détermenant----\n\t%d",det);
        }
        else
            printf("la matrice n'est pas carrée !");

    }
    break;
    case 5:
    // Fonction de la matrice inverse
    {
        printf("Choisez la matrice: M");
        scanf("%d",&witch_m);
        if((witch_m == 1) && (lin1 == colo1))
        {
            rs_f = mat_invrs(m1,lin1);
            det = determenant(m1,lin1);
            line = lin1;
        }
        else if((witch_m == 2) && (lin2 == colo2))
        {
            rs_f = mat_invrs(m2,lin2);
            det = determenant(m2,lin2);
            line = lin2;
        }
        // l'affichage:
        if(det != 0)
        {
            printf("--------La matrice inverse de M%d--------\n",witch_m);
            for(i=0;i<line;i++)
            {
                printf("\t");
                for(j=0;j<line;j++)
                    printf("%.2f\t",rs_f[i][j]);
                printf("\n");
            }
        }
        else
            printf("On peut pas calculer l'inverse");
    }
    break;
    }
}
while(1<2);
    return 0;
}
