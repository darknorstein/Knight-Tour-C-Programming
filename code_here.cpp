// knight work.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <stdio.h>
#define size 8
int grid_x[] = { 1, -1, -2, 2, -2, 2, -1, 1 }; //array yang menentukan langkah kuda//
int grid_y[] = { 2, 2, 1, 1, -1, -1, -2, -2 }; //array yang menentukan langkah kuda//

int done(int papan[][size]) // Fungsi yang mendefinisikan papan catur //
{
	int i, j;
	for (i = 0; i<size; i++)
	{
		for (j = 0; j<size; j++)
		{
			if (papan[i][j] == 0)
				return 0;
		}
	}
	return 1;
}
//hitung - variabel untuk menghitung langkah kuda//
void cari(int papan[][size], int x, int y, int hitung)
{
	int i;
	papan[x][y] = hitung;
	if (hitung<size*size){
		for (i = 0; i <= 7; i++){ //perulangan akan mencari setiap langkah yang mungkin terjadi//
			if (papan[x + grid_x[i]][y + grid_y[i]] == 0 && x + grid_x[i] >= 0 && x + grid_x[i]<size&&y + grid_y[i] >= 0 && y + grid_y[i]<size)
				// mengecek apakah langkah sudah pernah dikunjungi atau di luar papan catur//  {
				cari(papan, x + grid_x[i], y + grid_y[i], hitung + 1);
		}
	}

	if (done(papan) == 1) return; //Mengecek apakah semua telah terisi, jika iya maka langkah akan dihentikan / kembali dikosongkan//
	papan[x][y] = 0;
}

int main()
{
	// mencetak dan menentukan urutan angka langkah kuda 
	int i, j, x, y;
	printf("masukkan x\n");
	scanf_s("%d", &x);
	printf("masukkan y\n");
	scanf_s("%d", &y);

	int papan[size][size];
	for (i = 0; i<size; i++) {
		for (j = 0; j<size; j++) {
			papan[i][j] = 0;
		}
	}
	cari(papan, x, y, 1);



	for (i = 0; i<size; i++) {
		for (j = 0; j<size; j++) {
			printf("%d\t", papan[j][i]);
		}
		printf("\n\n");
	}
	printf("\n");
	getchar();
	getchar();
}
