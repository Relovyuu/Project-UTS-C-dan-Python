#include <stdio.h>
#include <string.h>

int main() {
    char nama_siswa[4][10] = {"nigel", "fadhil", "raden", "rifqi"};
    int kas_siswa[4] = {0, 0, 0, 0};
    int jumlah_siswa = 4;

    int tarif_kas = 5000;
    int total_kas = 0;
    int total_pengeluaran = 0;

    int pilihan, pilihan_bendahara, pilihan_siswa;

    while (1) {
        printf("\n==============================\n");
        printf(" LITERASI KEUANGAN KAS X-PPLG\n");
        printf("==============================\n");
        printf("1. Masuk Sebagai BENDAHARA\n");
        printf("2. Masuk Sebagai SISWA\n");
        printf("3. Keluar\n");
        printf("Pilih Menu (1-3) : ");
        scanf("%d", &pilihan);
        // MENU 1: BENDAHARA
        if (pilihan == 1) {
            printf("\n==============================\n");
            printf("     Anda Adalah BENDAHARA\n");
            printf("==============================\n");
            printf("1. Input Pemasukan Kas\n");
            printf("2. Input Pengeluaran Kas\n");
            printf("3. Lihat Data Kas SISWA\n");
            printf("4. Kembali\n");
            printf("Pilih Menu (1-4) : ");
            scanf("%d", &pilihan_bendahara);

            // 1.1 Input Pemasukan Kas
            if (pilihan_bendahara == 1) {
                char nama_input[10];
                printf("\nMasukan Nama SISWA : ");
                scanf("%s", nama_input);

                int ditemukan = 0;
                for (int i = 0; i < jumlah_siswa; i++) {
                    if (strcmp(nama_siswa[i], nama_input) == 0) {
                        ditemukan = 1;
                        int jumlah_minggu;
                        printf("Tarif KAS / Minggu : Rp.%d\n", tarif_kas);
                        printf("%s Bayar Untuk Berapa Minggu? : ", nama_input);
                        scanf("%d", &jumlah_minggu);

                        int total_pemasukan = tarif_kas * jumlah_minggu;
                        kas_siswa[i] += total_pemasukan;
                        total_kas += total_pemasukan;

                        printf("%s Membayar KAS Sebesar Rp.%d\n", nama_input, total_pemasukan);
                        printf("\n[SUCCESS] Pembayaran KAS Berhasil\n");
                        break;
                    }
                }

                if (ditemukan == 0) {
                    printf("\n[FAILED] Nama SISWA Tidak Valid\n");
                }
            } 
            // 1.2 Input Pengeluaran Kas
            else if (pilihan_bendahara == 2) {
                char keterangan[50];
                int pengeluaran;

                printf("\nKeterangan Pengeluaran : ");
                scanf("%s", keterangan);
                printf("Jumlah Pengeluaran     : Rp.");
                scanf("%d", &pengeluaran);

                if (total_kas >= pengeluaran) {
                    total_kas -= pengeluaran;
                    total_pengeluaran += pengeluaran;
                    printf("\n[SUCCESS] Pengeluaran KAS Berhasil!\n");
                } else {
                    printf("\n[FAILED] Saldo Kas Tidak Cukup\n");
                }
            } 
            // 1.3 Lihat Data Kas SISWA
            else if (pilihan_bendahara == 3) {
                printf("\n==============================\n");
                printf("     List Data Kas SISWA\n");
                printf("==============================\n");
                
                int total_pembayaran_kas = 0;
                for (int i = 0; i < jumlah_siswa; i++) {
                    printf("- %-10s : Rp.%d\n", nama_siswa[i], kas_siswa[i]);
                    total_pembayaran_kas += kas_siswa[i];
                }

                printf("Total Pembayaran KAS : Rp.%d\n", total_pembayaran_kas);
                printf("\nTotal Pengeluaran    : Rp.%d\n", total_pengeluaran);
                printf("------------------------------\n");
                printf("Total Uang KAS Saat Ini : Rp.%d\n", total_kas);

                if (total_kas > 0) {
                    int alokasi_per_siswa = total_kas / jumlah_siswa;
                    int sisa_alokasi = total_kas % jumlah_siswa;
                    printf("Alokasi KAS Per SISWA   : Rp.%d\n", alokasi_per_siswa);
                    printf("Sisa Alokasi Kas        : Rp.%d\n", sisa_alokasi);
                }

                printf("\nTekan ENTER untuk kembali ke menu...");
                getchar(); 
                getchar(); 
            } 
            // 1.4 Kembali
            else if (pilihan_bendahara == 4) {
                continue;
            } 
            else {
                printf("\n[FAILED] Pilihan Tidak Valid\n");
            }
        } 
        // MENU 2: SISWA
        else if (pilihan == 2) {
            printf("\n==============================\n");
            printf("     Anda Adalah SISWA\n");
            printf("==============================\n");
            printf("1. Lihat Data Kas SISWA\n");
            printf("2. Kembali\n");
            printf("Pilih Menu (1-2) : ");
            scanf("%d", &pilihan_siswa);

            if (pilihan_siswa == 1) {
                printf("\n==============================\n");
                printf("     List Data Kas SISWA\n");
                printf("==============================\n");
                
                int total_pembayaran_kas = 0;
                for (int i = 0; i < jumlah_siswa; i++) {
                    printf("- %-10s : Rp.%d\n", nama_siswa[i], kas_siswa[i]);
                    total_pembayaran_kas += kas_siswa[i];
                }

                printf("Total Pembayaran KAS : Rp.%d\n", total_pembayaran_kas);
                printf("\nTotal Pengeluaran    : Rp.%d\n", total_pengeluaran);
                printf("------------------------------\n");
                printf("Total Uang KAS Saat Ini : Rp.%d\n", total_kas);

                if (total_kas > 0) {
                    int alokasi_per_siswa = total_kas / jumlah_siswa;
                    int sisa_alokasi = total_kas % jumlah_siswa;
                    printf("Alokasi KAS Per SISWA   : Rp.%d\n", alokasi_per_siswa);
                    printf("Sisa Alokasi Kas        : Rp.%d\n", sisa_alokasi);
                }

                printf("\nTekan ENTER untuk kembali ke menu...");
                getchar();
                getchar();
            } 
            else if (pilihan_siswa == 2) {
                continue;
            } 
            else {
                printf("\n[FAILED] Pilihan tidak valid\n");
            }
        } 
        // MENU 3: KELUAR
        else if (pilihan == 3) {
            printf("\nTerimakasih\n");
            break;
        } 
        
        else {
            printf("\n[FAILED] Pilihan tidak valid\n");
        }
    }

    return 0;
}