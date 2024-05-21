#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10

int afisare(int matriceFill[N][N])
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			printf("%d ", matriceFill[i][j]);
		printf("\n");
	}
	return 0;
}
int FillMatrice(int matriceFill[N][N], int i, int j)
{
	if (i < 0 || i >= N || j < 0 || j >= N)
		return 0;
	if (matriceFill[i][j] == 1)
		return 0;
	if (matriceFill[i][j] == 0)
	{
		matriceFill[i][j] = 2;
		FillMatrice(matriceFill, i + 1, j);
		FillMatrice(matriceFill, i - 1, j);
		FillMatrice(matriceFill, i, j - 1);
		FillMatrice(matriceFill, i, j + 1);
	}
	return 0;
}



int main()
{
	int matriceFill[N][N] = {	0,0,0,1,0,0,0,0,0,0,
								1,1,0,1,1,1,1,1,1,0,
								0,1,0,0,0,0,0,0,1,0,
								0,1,0,1,1,1,1,0,1,0,
								0,1,0,0,0,1,1,0,1,0,
								0,1,0,0,0,0,1,0,1,0,
								0,1,0,1,1,1,1,0,1,0,
								0,1,0,0,0,0,0,0,1,0,
								0,1,1,1,1,1,1,1,1,0,
								0,0,0,0,0,0,0,0,0,0 };
	// sau daca doriti sa rulati programul cu fisier.txt
	//FILE *f;
	//f = fopen("matrice.txt", "r");
	//if (f == NULL)
	//{
	//	printf("Eroare la deschiderea fisierului\n");
	//	return 0;
	//}
	// int lungimeMatrice = 0;
	// fscanf(f, "%d", &lungimeMatrice);
	// int matriceFill[N][N];
	// for (int i = 0; i < lungimeMatrice; i++)
	// {
	// for (int j = 0; j < lungimeMatrice; j++)
	// {
	// fscanf(f, "%d", &matriceFill[i][j]);
	// }
	// }
	//fclose(f);
	//FillMatrice(matriceFill, Si, Sj);
	//afisare(matriceFill);
	int Si = 0, Sj = 0;
	printf("Citeste i Start : ");
	scanf("%d", &Si);
	printf("Citeste j Start : ");
	scanf("%d", &Sj);
	if (matriceFill[Si][Sj] == 1)
	{
		printf("Elementul selectat este deja pe pozitia 1\n");
	}
	else
	{
	FillMatrice(matriceFill, Si, Sj);
	afisare(matriceFill);
	}
	system("pause");
	return 0;
}

