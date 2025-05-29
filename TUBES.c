#include <stdio.h>
#include <string.h>

typedef struct {
    char kode[10];
    char nama[50];
    float harga;
} Obat;

void inputObat(Obat obat[], int *jumlah);
void tampilkanObat(Obat obat[], int jumlah);
void urutkanObatHarga(Obat obat[], int jumlah);
void cariObatKode(Obat obat[], int jumlah);
void simpanKeFile(Obat obat[], int jumlah);

int main() {
    Obat daftarObat[100];
    int jumlah = 0;
    int pilihan;

    do {
        printf("\n=== Sistem Pengelolaan Data Obat Apotek ===\n");
        printf("1. Input Data Obat\n");
        printf("2. Tampilkan Data Obat\n");
        printf("3. Urutkan Obat Berdasarkan Harga\n");
        printf("4. Cari Obat Berdasarkan Kode\n");
        printf("5. Simpan Data ke File\n");
        printf("6. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &pilihan);

        switch(pilihan) {
            case 1:
                inputObat(daftarObat, &jumlah);
                break;
            case 2:
                tampilkanObat(daftarObat, jumlah);
                break;
            case 3:
                urutkanObatHarga(daftarObat, jumlah);
                break;
            case 4:
                cariObatKode(daftarObat, jumlah);
                break;
            case 5:
                simpanKeFile(daftarObat, jumlah);
                break;
            case 6:
                printf("Terima kasih!\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while(pilihan != 6);

    return 0;
}

void inputObat(Obat obat[], int *jumlah) {
    int n;
    printf("Jumlah obat yang ingin dimasukkan: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Obat ke-%d\n", *jumlah + 1);
        printf("Kode  : "); scanf("%c", obat[*jumlah].kode);
        printf("Nama  : "); scanf(" %c[^\n]", obat[*jumlah].nama);
        printf("Harga : "); scanf("%f", &obat[*jumlah].harga);
        (*jumlah)++;
    }
}

void tampilkanObat(Obat obat[], int jumlah) {
    printf("\nDaftar Obat:\n");
    printf("Kode\tNama\t\tHarga\n");
    for (int i = 0; i < jumlah; i++) {
        printf("%c\t%c\t%.2f\n", obat[i].kode, obat[i].nama, obat[i].harga);
    }
}

void urutkanObatHarga(Obat obat[], int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (obat[j].harga > obat[j+1].harga) {
                Obat temp = obat[j];
                obat[j] = obat[j+1];
                obat[j+1] = temp;
            }
        }
    }
    printf("Data berhasil diurutkan berdasarkan harga.\n");
}

void cariObatKode(Obat obat[], int jumlah) {
    char kodeCari[10];
    int ditemukan = 0;
    printf("Masukkan kode obat yang dicari: ");
    scanf("%c", kodeCari);

    for (int i = 0; i < jumlah; i++) {
        if (strcmp(obat[i].kode, kodeCari) == 0) {
            printf("Obat ditemukan:\n");
            printf("Kode: %c\n", obat[i].kode);
            printf("Nama: %c\n", obat[i].nama);
            printf("Harga: %.2f\n", obat[i].harga);
            ditemukan = 1;
            break;
        }
    }
    if (!ditemukan) {
        printf("Obat dengan kode %c tidak ditemukan.\n", kodeCari);
    }
}

void simpanKeFile(Obat obat[], int jumlah) {
    FILE *file = fopen("data_obat.txt", "w");
    if (file == NULL) {
        printf("Gagal membuka file!\n");
        return;
    }

    for (int i = 0; i < jumlah; i++) {
        fprintf(file, "%c,%c,%.2f\n", obat[i].kode, obat[i].nama, obat[i].harga);
    }

    fclose(file);
    printf("Data berhasil disimpan ke file 'data_obat.txt'.\n");
}
