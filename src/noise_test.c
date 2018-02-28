/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** Main file.
*/
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "main.h"

const double pi = 3.14159265;

static int taille = 0;
static int pas2D = 0;
static int nombre_octaves2D = 0;
static int hauteur = 0;
static int longueur = 0;
static int longueur_max = 0;
static double* valeurs2D;

static double interpolation_cos1D(double a, double b, double x) {
   double k = (1 - cos(x * pi)) / 2;
    return a * (1 - k) + b * k;
}

void initBruit2D(int l, int h, int p, int n) {
    nombre_octaves2D = n;
    if(taille != 0)
        free(valeurs2D);
    longueur = l;
    hauteur = h;
    pas2D = p;
    longueur_max = (int) ceil(longueur * pow(2, nombre_octaves2D  - 1)  / pas2D);
    int hauteur_max = (int) ceil(hauteur * pow(2, nombre_octaves2D  - 1)  / pas2D);

    valeurs2D = (double*) malloc(sizeof(double) * longueur_max * hauteur_max);

    srand(time(NULL));
    int i;
    for(i = 0; i < longueur_max * hauteur_max; i++)
        valeurs2D[i] = ((double) rand()) / RAND_MAX;
}

void destroyBruit2D() {
    if(longueur != 0)
        free(valeurs2D);
    longueur = 0;
}

static double bruit2D(int i, int j) {
    return valeurs2D[i * longueur_max + j];
}

static double interpolation_cos2D(double a, double b, double c, double d, double x, double y) {
   double y1 = interpolation_cos1D(a, b, x);
   double y2 = interpolation_cos1D(c, d, x);
   return  interpolation_cos1D(y1, y2, y);
}

static double fonction_bruit2D(double x, double y) {
   int i = (int) (x / pas2D);
   int j = (int) (y / pas2D);
   return interpolation_cos2D(bruit2D(i, j), bruit2D(i + 1, j), bruit2D(i, j + 1), bruit2D(i + 1, j + 1), fmod(x / pas2D, 1), fmod(y / pas2D, 1));
}

double bruit_coherent2D(double x, double y, double persistance) {
    double somme = 0;
    double p = 1;
    int f = 1;
    int i;

    for(i = 0 ; i < nombre_octaves2D ; i++) {
        somme += p * fonction_bruit2D(x * f, y * f);
        p *= persistance;
        f *= 2;
    }
    return somme * (1 - persistance) / (1 - p);
}

// #include "main.h"
//
// int	verif_tab(unsigned int *tab, unsigned int random)
// {
// 	for (int i = 0; i < 256; i++)
// 		if (tab[i] == random)
// 			return (1);
// 	return (0);
// }
//
// unsigned int	*generate_randomised_tab(void)
// {
// 	unsigned int *tab = malloc(sizeof(unsigned int) * 256);
// 	unsigned int random = 0;
//
// 	for (int i = 0; i < 256; i++) {
// 		random = rand() % 257;
// 		while (verif_tab(tab, random) != 0)
// 			random = rand() % 257;
// 		tab[i] = random;
// 		// printf("TABLEAU REMPLI A %d :   %d\n", i, tab[i]);
// 	}
// 	for (int i = 0; i < 256; i++) {
// 		printf("%d,", tab[i]);
// 		if (i == 32)
// 			printf("\n");
// 	}
// 	return (tab);
// }
//
// float Get2DPerlinNoiseValue(float x, float y, float resX, float resY)
// {
//     float tempX,tempY;
//     int x0,y0,ii,jj,gi0,gi1,gi2,gi3;
//     float unit = 1.0f/sqrt(2);
//     float tmp,s,t,u,v,Cx,Cy,Li1,Li2;
//     float gradient2[][2] = {{unit,unit},{-unit,unit},{unit,-unit},{-unit,-unit},{1,0},{-1,0},{0,1},{0,-1}};
//     static int i = 0;
//     unsigned int perm[] = {102,124,132,153,185,217,73,131,177,118,230,83,109,111,176,
// 	    154,113,204,184,145,60,119,28,9,190,164,27,210,70,12,240,78,135,80,112,47,
// 	    15,231,66,211,224,225,45,3,159,134,116,26,160,126,194,89,142,215,234,223,
// 	    228,108,32,219,31,69,54,133,56,36,41,117,209,87,29,21,138,212,68,96,227,
// 	    233,143,62,128,34,5,25,129,173,18,157,114,95,163,58,191,67,247,76,146,11,
// 	    106,115,90,86,37,48,81,252,187,94,53,103,4,179,195,82,171,175,174,170,141,
// 	    49,24,33,100,1,220,213,216,13,101,2,189,188,208,180,218,46,254,6,127,226,144,
// 	    30,183,203,7,139,169,23,130,182,186,38,71,10,229,61,200,197,137,74,40,85,150,
// 	    206,105,193,91,238,120,239,161,57,107,79,88,198,156,55,43,52,64,140,245,222,166,
// 	    158,172,75,97,51,207,123,253,122,63,50,44,178,237,99,246,65,151,104,243,35,42,
// 	    199,136,147,248,16,149,165,110,181,20,17,84,202,192,125,22,98,205,162,214,14,
// 	    256,221,241,93,242,148,244,77,168,255,8,196,155,121,72,152,39,235,92,232,19,
// 	    249,167,250,236,251,59,201};
//
// 	// if (i == 0) {
//     	// 	perm = generate_randomised_tab();
// 	// 	i = 1;
// 	// }
//        // {151,160,137,91,90,15,131,13,201,95,96,53,194,233,7,225,140,36,103,30,69,
//        //  142,8,99,37,240,21,10,23,190,6,148,247,120,234,75,0,26,197,62,94,252,219,
//        //  203,117,35,11,32,57,177,33,88,237,149,56,87,174,20,125,136,171,168,68,175,
//        //  74,165,71,134,139,48,27,123,77,146,158,231,83,111,229,122,60,211,133,230,220,
//        //  105,92,41,55,46,245,40,244,102,143,54,65,25,63,161,1,216,80,73,209,76,132,
//        //  187,208,89,18,169,200,196,135,130,116,188,159,86,164,100,109,198,173,186,3,
//        //  64,52,217,226,250,124,166,5,202,38,147,118,126,255,82,85,212,207,206,59,227,
//        //  47,16,58,17,182,189,28,42,223,183,170,213,119,248,152,2,44,154,163,70,221,
//        //  153,101,155,167,43,172,9,129,22,39,253,19,98,108,110,79,113,224,232,178,185,
//        //  112,104,218,246,97,228,251,34,242,193,238,210,144,12,191,179,162,241,81,51,145,
//        //  235,249,14,239,107,49,192,214,31,181,199,106,157,184,84,204,176,115,121,50,45,
//        //  127,4,150,254,138,236,205,93,222,114,67,29,24,72,243,141,128,195,78,66,215,61,
//        //  156,180};
//
//     //Adapter pour la résolution
//     x /= resX;
//     y /= resY;
//
//     //On récupère les positions de la grille associée à (x,y)
//     x0 = (int)(x);
//     y0 = (int)(y);
//
//     //Masquage
//     ii = x0 & 255;
//     jj = y0 & 255;
//
//     //Pour récupérer les vecteurs
//     gi0 = perm[ii + perm[jj]] % 8;
//     gi1 = perm[ii + 1 + perm[jj]] % 8;
//     gi2 = perm[ii + perm[jj + 1]] % 8;
//     gi3 = perm[ii + 1 + perm[jj + 1]] % 8;
//
//     //on récupère les vecteurs et on pondère
//     tempX = x-x0;
//     tempY = y-y0;
//     s = gradient2[gi0][0]*tempX + gradient2[gi0][1]*tempY;
//
//     tempX = x-(x0+1);
//     tempY = y-y0;
//     t = gradient2[gi1][0]*tempX + gradient2[gi1][1]*tempY;
//
//     tempX = x-x0;
//     tempY = y-(y0+1);
//     u = gradient2[gi2][0]*tempX + gradient2[gi2][1]*tempY;
//
//     tempX = x-(x0+1);
//     tempY = y-(y0+1);
//     v = gradient2[gi3][0]*tempX + gradient2[gi3][1]*tempY;
//
//
//     //Lissage
//     tmp = x-x0;
//     Cx = 3 * tmp * tmp - 2 * tmp * tmp * tmp;
//
//     Li1 = s + Cx*(t-s);
//     Li2 = u + Cx*(v-u);
//
//     tmp = y - y0;
//     Cy = 3 * tmp * tmp - 2 * tmp * tmp * tmp;
//
//     // printf("LOOOOOL\n");
//     return Li1 + Cy*(Li2-Li1);
// }
