#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define n 200

void potencial(double masc[n][n], double pot[n][n])
{
	int l, c, t;
	
	for(c=0; c<n; c++)
		pot[n-1][c]=100;
		
	for(t=0; t<20000; t++)
	{
		for(l=0; l<n; l++)
		{
			for(c=0; c<n; c++)
			{
				if(masc[l][c]==0)
					pot[l][c]=(pot[l+1][c]+pot[l-1][c]+pot[l][c+1]+pot[l][c-1])/4.;
			}
		}
	}
}

void mascara(double masc[n][n])
{
	int i;
	
	for(i=0; i<n; i++)
		masc[n-1][i]=1.0;
		
	for(i=n/4; i<n-(n/4); i++)
		masc[n/2][i]=1.0;
		
	for(i=1; i<n/2; i++)
		masc[i][n/2]=1.0;
}

main(int argc, char **argv[])
{
	double masc[n][n]={0}, pot[n][n]={0};
	int l, c, t;
	FILE *arq;
	
	arq=fopen(argv[1], "w");
	
	mascara(masc);
	potencial(masc,pot);
	
	for(l=0; l<n; l++)
	{
		for(c=0; c<n; c++)
			fprintf(arq, "%lf\t", M[l][c]);
		fprintf(arq, "\n");
	}
	
	fclose(arq);
}
