#include <stdio.h>
#include <string.h>

struct Mahasiswa
{
    char nim[20];
    char nama[50];
    char alamat[100];
    float ipk;
};

struct Mahasiswa mahasiswa[100];
int jumlah_mahasiswa = 0;

// Function prototypes
void lihat_semua_data();
void masukkan_data(int n);
void lihat_data_ipk_rendah();
void lihat_data_urut_nim();
void edit_data();

int main()
{
    // Initialize with 2 static students (IPK 4.00 and 2.00)
    strcpy(mahasiswa[0].nim, "1234567890");
    strcpy(mahasiswa[0].nama, "Agung Jaya");
    strcpy(mahasiswa[0].alamat, "Jl. Sudirman No. 1");
    mahasiswa[0].ipk = 4.00;
    jumlah_mahasiswa++;

    strcpy(mahasiswa[1].nim, "0987654321");
    strcpy(mahasiswa[1].nama, "Bintang Sulistyo");
    strcpy(mahasiswa[1].alamat, "Jl. Merdeka No. 2");
    mahasiswa[1].ipk = 2.00;
    jumlah_mahasiswa++;

    int pilihan;

    do
    {
        printf("\nMenu:\n");
        printf("1. Lihat semua data mahasiswa\n");
        printf("2. Masukkan 1 data mahasiswa\n");
        printf("3. Masukkan 3 data mahasiswa\n");
        printf("4. Lihat data mahasiswa yang memiliki IPK < 3.00\n");
        printf("5. Lihat data mahasiswa berdasarkan urutan NIM ascending\n");
        printf("6. Edit data mahasiswa\n");
        printf("0. Exit\n");

        printf("Masukkan pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            lihat_semua_data();
            break;
        case 2:
            masukkan_data(1);
            break;
        case 3:
            masukkan_data(3);
            break;
        case 4:
            lihat_data_ipk_rendah();
            break;
        case 5:
            lihat_data_urut_nim();
            break;
        case 6:
            edit_data();
            break;
        }
    } while (pilihan != 0);

    return 0;
}

void lihat_semua_data()
{
    if (jumlah_mahasiswa == 0)
    {
        printf("Belum ada data mahasiswa.\n");
        return;
    }

    printf("\nData semua mahasiswa:\n");
    for (int i = 0; i < jumlah_mahasiswa; i++)
    {
        printf("NIM: %s\n", mahasiswa[i].nim);
        printf("Nama: %s\n", mahasiswa[i].nama);
        printf("Alamat: %s\n", mahasiswa[i].alamat);
        printf("IPK: %.2f\n", mahasiswa[i].ipk);
        printf("\n");
    }
}

void masukkan_data(int n)
{
    if (jumlah_mahasiswa + n > 100)
    {
        printf("Kapasitas data mahasiswa penuh.\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        printf("\nData mahasiswa %d:\n", i + 1);
        printf("NIM: ");
        scanf("%s", mahasiswa[jumlah_mahasiswa + i].nim);
        printf("Nama: ");
        scanf(" %[^\n]", mahasiswa[jumlah_mahasiswa + i].nama); // Use scanf with %[^\n] to read names with spaces
        printf("Alamat: ");
        scanf(" %[^\n]", mahasiswa[jumlah_mahasiswa + i].alamat);
        printf("IPK: ");
        scanf("%f", &mahasiswa[jumlah_mahasiswa + i].ipk);
    }

    jumlah_mahasiswa += n;
}

void lihat_data_ipk_rendah()
{
    if (jumlah_mahasiswa == 0)
    {
        printf("Belum ada data mahasiswa.\n");
        return;
    }

    int flag = 0; // Flag to indicate if there are students with IPK < 3.00

    printf("\nData mahasiswa dengan IPK < 3.00:\n");
    for (int i = 0; i < jumlah_mahasiswa; i++)
    {
        if (mahasiswa[i].ipk < 3.00)
        {
            printf("NIM: %s\n", mahasiswa[i].nim);
            printf("Nama: %s\n", mahasiswa[i].nama);
            printf("Alamat: %s\n", mahasiswa[i].alamat);
            printf("IPK: %.2f\n", mahasiswa[i].ipk);
            printf("\n");
            flag = 1;
        }
    }

    if (!flag)
    {
        printf("Tidak ada mahasiswa dengan IPK < 3.00.\n");
    }
}

void lihat_data_urut_nim()
{
    if (jumlah_mahasiswa == 0)
    {
        printf("Belum ada data mahasiswa.\n");
        return;
    }

    // Bubble sort to sort students by NIM in ascending order
    for (int i = 0; i < jumlah_mahasiswa - 1; i++)
    {
        for (int j = 0; j < jumlah_mahasiswa - i - 1; j++)
        {
            if (strcmp(mahasiswa[j].nim, mahasiswa[j + 1].nim) > 0)
            {
                struct Mahasiswa temp = mahasiswa[j];
                mahasiswa[j] = mahasiswa[j + 1];
                mahasiswa[j + 1] = temp;
            }
        }
    }

    printf("\nData mahasiswa berdasarkan urutan NIM ascending:\n");
    for (int i = 0; i < jumlah_mahasiswa; i++)
    {
        printf("NIM: %s\n", mahasiswa[i].nim);
        printf("Nama: %s\n", mahasiswa[i].nama);
        printf("Alamat: %s\n", mahasiswa[i].alamat);
        printf("IPK: %.2f\n", mahasiswa[i].ipk);
        printf("\n");
    }
}

void edit_data()
{
    if (jumlah_mahasiswa == 0)
    {
        printf("Belum ada data mahasiswa.\n");
        return;
    }

    char nim_cari[10];
    int idx = -1;

    printf("Masukkan NIM mahasiswa yang ingin diedit: ");
    scanf("%s", nim_cari);

    // Find the index of the student with the given NIM
    for (int i = 0; i < jumlah_mahasiswa; i++)
    {
        if (strcmp(mahasiswa[i].nim, nim_cari) == 0)
        {
            idx = i;
            break;
        }
    }

    if (idx == -1)
    {
        printf("Mahasiswa dengan NIM %s tidak ditemukan.\n", nim_cari);
        return;
    }

    printf("\nData mahasiswa yang ingin diedit:\n");
    printf("NIM: %s\n", mahasiswa[idx].nim);
    printf("Nama: %s\n", mahasiswa[idx].nama);
    printf("Alamat: %s\n", mahasiswa[idx].alamat);
    printf("IPK: %.2f\n", mahasiswa[idx].ipk);

    int pilihan;
    do
    {
        printf("\nData apa yang ingin diedit?\n");
        printf("1. Nama\n");
        printf("2. Alamat\n");
        printf("3. IPK\n");
        printf("0. Kembali\n");

        printf("Masukkan pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            printf("Masukkan nama baru: ");
            scanf(" %[^\n]", mahasiswa[idx].nama);
            break;
        case 2:
            printf("Masukkan alamat baru: ");
            scanf(" %[^\n]", mahasiswa[idx].alamat);
            break;
        case 3:
            printf("Masukkan IPK baru: ");
            scanf("%f", &mahasiswa[idx].ipk);
            break;
        }
    } while (pilihan != 0);

    printf("\nData mahasiswa setelah diedit:\n");
    printf("NIM: %s\n", mahasiswa[idx].nim);
    printf("Nama: %s\n", mahasiswa[idx].nama);
    printf("Alamat: %s\n", mahasiswa[idx].alamat);
    printf("IPK: %.2f\n", mahasiswa[idx].ipk);
}