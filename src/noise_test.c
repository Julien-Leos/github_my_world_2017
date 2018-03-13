/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** Main file.
*/

#include "main.h"

int	verif_tab(unsigned int *tab, unsigned int random)
{
	for (int i = 0; i < 256; i++)
		if (tab[i] == random)
			return (1);
	return (0);
}

unsigned int	*generate_randomised_tab(void)
{
	unsigned int *tab = malloc(sizeof(unsigned int) * 256);
	unsigned int random = 0;

	for (int i = 0; i < 256; i++) {
		random = rand() % 257;
		while (verif_tab(tab, random) != 0)
			random = rand() % 257;
		tab[i] = random;
		// printf("TABLEAU REMPLI A %d :   %d\n", i, tab[i]);
	}
	for (int i = 0; i < 256; i++) {
		printf("%d,", tab[i]);
		if (i == 32)
			printf("\n");
	}
	return (tab);
}

float Get2DPerlinNoiseValue(float x, float y)
{
    float tempX,tempY;
    int x0,y0,ii,jj,gi0,gi1,gi2,gi3;
    float unit = 1.0f/sqrt(2);
    float tmp,s,t,u,v,Cx,Cy,Li1,Li2;
    float gradient2[][2] = {{unit,unit},{-unit,unit},{unit,-unit},{-unit,-unit},{1,0},{-1,0},{0,1},{0,-1}};
    unsigned int perm[] = {102,124,132,153,185,217,73,131,177,118,230,83,109,111,176,
	    154,113,204,184,145,60,119,28,9,190,164,27,210,70,12,240,78,135,80,112,47,
	    15,231,66,211,224,225,45,3,159,134,116,26,160,126,194,89,142,215,234,223,
	    228,108,32,219,31,69,54,133,56,36,41,117,209,87,29,21,138,212,68,96,227,
	    233,143,62,128,34,5,25,129,173,18,157,114,95,163,58,191,67,247,76,146,11,
	    106,115,90,86,37,48,81,252,187,94,53,103,4,179,195,82,171,175,174,170,141,
	    49,24,33,100,1,220,213,216,13,101,2,189,188,208,180,218,46,254,6,127,226,144,
	    30,183,203,7,139,169,23,130,182,186,38,71,10,229,61,200,197,137,74,40,85,150,
	    206,105,193,91,238,120,239,161,57,107,79,88,198,156,55,43,52,64,140,245,222,166,
	    158,172,75,97,51,207,123,253,122,63,50,44,178,237,99,246,65,151,104,243,35,42,
	    199,136,147,248,16,149,165,110,181,20,17,84,202,192,125,22,98,205,162,214,14,
	    256,221,241,93,242,148,244,77,168,255,8,196,155,121,72,152,39,235,92,232,19,
	    249,167,250,236,251,59,201};

    //On récupère les positions de la grille associée à (x,y)
    x0 = (int)(x);
    y0 = (int)(y);

    //Masquage
    ii = x0 & 255;
    jj = y0 & 255;

    //Pour récupérer les vecteurs
    gi0 = perm[ii + perm[jj]] % 8;
    gi1 = perm[ii + 1 + perm[jj]] % 8;
    gi2 = perm[ii + perm[jj + 1]] % 8;
    gi3 = perm[ii + 1 + perm[jj + 1]] % 8;

    //on récupère les vecteurs et on pondère
    tempX = x-x0;
    tempY = y-y0;
    s = gradient2[gi0][0]*tempX + gradient2[gi0][1]*tempY;

    tempX = x-(x0+1);
    tempY = y-y0;
    t = gradient2[gi1][0]*tempX + gradient2[gi1][1]*tempY;

    tempX = x-x0;
    tempY = y-(y0+1);
    u = gradient2[gi2][0]*tempX + gradient2[gi2][1]*tempY;

    tempX = x-(x0+1);
    tempY = y-(y0+1);
    v = gradient2[gi3][0]*tempX + gradient2[gi3][1]*tempY;


    //Lissage
    tmp = x-x0;
    Cx = 3 * tmp * tmp - 2 * tmp * tmp * tmp;

    Li1 = s + Cx*(t-s);
    Li2 = u + Cx*(v-u);

    tmp = y - y0;
    Cy = 3 * tmp * tmp - 2 * tmp * tmp * tmp;

    return Li1 + Cy*(Li2-Li1);
}

float Noise(float x, float y)
{
  int n = x + y * 57;
  n = pow((n<<13), n);
  return ( 1.0 - ( (n * (n * n * 15731 + 789221) + 1376312589) & 7) / 1073741824.0);
}

float SmoothNoise_1(float x, float y)
{
  float corners = ( Noise(x-1, y-1)+Noise(x+1, y-1)+Noise(x-1, y+1)+Noise(x+1, y+1) ) / 16;
  float sides   = ( Noise(x-1, y)  +Noise(x+1, y)  +Noise(x, y-1)  +Noise(x, y+1) ) /  8;
  float center  =  Noise(x, y) / 4;
  return (corners + sides + center);
}

float Interpolate(float a, float b, float x)
{
      float ft = x * 3.1415927;
      float f = (1 - cos(ft)) * 0.5;

      return  (a*(1-f) + b*f);
}

float InterpolatedNoise_1(float x, float y)
{
    int integer_X    = (int)x;
    float fractional_X = x - integer_X;

    int integer_Y    = (int)y;
    float fractional_Y = y - integer_Y;

    float v1 = SmoothNoise_1(integer_X,     integer_Y);
    float v2 = SmoothNoise_1(integer_X + 1, integer_Y);
    float v3 = SmoothNoise_1(integer_X,     integer_Y + 1);
    float v4 = SmoothNoise_1(integer_X + 1, integer_Y + 1);

    float i1 = Interpolate(v1 , v2 , fractional_X);
    float i2 = Interpolate(v3 , v4 , fractional_X);

    return (Interpolate(i1 , i2 , fractional_Y));
}
