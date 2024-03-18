#include <stdio.h>

void koboImaginaryChess(int i, int j, int size, int *chessBoard)
{
    // Menandai posisi awal kuda
    chessBoard[i * size + j] = 1;

    // Delapan kemungkinan arah gerakan kuda
    int di[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dj[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

    // Menjelajahi semua kemungkinan arah
    for (int k = 0; k < 8; k++)
    {
        // Menghitung posisi baru
        int newi = i + di[k];
        int newj = j + dj[k];

        // Memastikan posisi baru berada dalam papan catur
        if (0 <= newi && newi < size && 0 <= newj && newj < size)
        {
            // Menandai posisi baru
            chessBoard[newi * size + newj] = 1;
        }
    }
}

int main()
{
    int size = 8;                // Ukuran papan catur
    int chessBoard[size * size]; // Array untuk mensimulasikan papan catur

    // Membaca posisi awal kuda
    int i, j;
    scanf("%d %d", &i, &j);

    // Menjalankan simulasi
    koboImaginaryChess(i, j, size, chessBoard);

    // Mencetak hasil simulasi
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", chessBoard[i * size + j]);
        }
        printf("\n");
    }

    return 0;
}
