data_siswa = {
    "nigel"  : 0,
    "fadhil" : 0,
    "raden"  : 0,
    "rifqi"  : 0,
    "riska"  : 0,
}

tarif_kas         = 5000
total_kas         = 0
total_pengeluaran = 0

while True:
    print("="*30)
    print(" LITERASI KEUANGAN KAS X-PPLG")
    print("="*30)
    print("1. Masuk Sebagai BENDAHARA")
    print("2. Masuk Sebagai SISWA")
    print("3. Keluar")

    pilihan = input("Pilih Menu (1-3) : ")

    if pilihan == '1': #BENDAHARA
        print("="*30)
        print("     Anda Adalah BENDAHARA")
        print("="*30)
        print("1. Input Pemasukan Kas")
        print("2. Input Pengeluaran Kas")
        print("3. Lihat Data Kas SISWA")
        print("4. Kembali")
        pilihan_bendahara = input("Pilih Menu (1-4) : ")
        if pilihan_bendahara == '1': #PEMASUKAN
            nama      = input("\nMasukan Nama SISWA : ").lower()
            if nama in data_siswa: #menambahkan uang kas
                print(f"Tarif KAS / Minggu : Rp.{tarif_kas}")
                jumlah_minggu = int(input(f"{nama} Bayar Untuk Berapa Minggu? : "))
                total_pemasukan = tarif_kas * jumlah_minggu
                data_siswa[nama] += total_pemasukan
                total_kas += total_pemasukan
                print(f"{nama} Membayar KAS Sebesar Rp.{total_kas}")
                print("\n[SUCCESS] Pembayaran KAS Berhasil")
            else: 
                print("\n[FAILED] Nama SISWA Tidak Valid")
                continue;
        elif pilihan_bendahara == '2': #PENGELUARAN
            keterangan  = input("\nKeterangan Pengeluaran : ")
            pengeluaran = int(input("Jumlah Pengeluaran     : Rp."))
            if total_kas >= pengeluaran:
                total_kas -= pengeluaran
                total_pengeluaran += pengeluaran
            else:
                print("\n[FAILED] Saldo Kas Tidak Cukup")
                continue;
            print("\n[SUCCESS] Pengeluaran KAS Berhasil!")
        elif pilihan_bendahara == "3": #DATA KAS SISWA
            print("="*30)
            print("     List Data Kas SISWA")
            print("="*30)
            for siswa, kas in data_siswa.items():
                print(f"- {siswa.capitalize():19}: Rp.{kas}")
            total_pembayaran_kas = sum(data_siswa.values())
            print(f"Total Pembayaran KAS : Rp.{total_pembayaran_kas}")
            print(f"\nTotal Pengeluaran    : Rp.{total_pengeluaran}", )
            print("-"*30)
            print(f"Total Uang KAS Saat Ini : Rp.{total_kas}")
            jumlah_siswa = len(data_siswa)
            if jumlah_siswa > 0 and total_kas > 0:
                alokasi_per_siswa = total_kas // jumlah_siswa
                sisa_alokasi = total_kas % jumlah_siswa
                print(f"Alokasi KAS Per SISWA   : Rp.{alokasi_per_siswa}")
                print(f"Sisa Alokasi Kas        : Rp.{sisa_alokasi}")
            input("\nKlik ENTER untuk kembali...")
        elif pilihan_bendahara == "4": #KEMBALI
            continue;
        else:
            print("\n[FAILED] Pilihan Tidak Valid")
            break;

    elif pilihan == '2': #SISWA
        print("="*30)
        print("     Anda Adalah SISWA")
        print("="*30)
        print("1. Lihat Data Kas SISWA")
        print("2. Kembali")
        pilihan_siswa = input("Pilih Menu (1-2) : ")
        if pilihan_siswa == "1": #DATA KAS SISWA
            print("="*30)
            print("     List Data Kas SISWA")
            print("="*30)
            for siswa, kas in data_siswa.items():
                print(f"- {siswa.capitalize():19}: Rp.{kas}")
            total_pembayaran_kas = sum(data_siswa.values())
            print(f"Total Pembayaran KAS : Rp.{total_pembayaran_kas}")
            print(f"\nTotal Pengeluaran    : Rp.{total_pengeluaran}", )
            print("-"*30)
            print(f"Total Uang KAS Saat Ini : Rp.{total_kas}")
            jumlah_siswa = len(data_siswa)
            if jumlah_siswa > 0 and total_kas > 0:
                alokasi_per_siswa = total_kas // jumlah_siswa
                sisa_alokasi = total_kas % jumlah_siswa
                print(f"Alokasi KAS Per SISWA   : Rp.{alokasi_per_siswa}")
                print(f"Sisa Alokasi Kas        : Rp.{sisa_alokasi}")
            input("\nKlik ENTER untuk kembali...")
        elif pilihan_siswa == "2": #KEMBALI
            continue;
        else:
            print("\n[FAILED] Pilihan tidak valid")
            break;
        
    elif pilihan == '3':
        print("Terimakasih")
        break;

    else:
        print("\n[FAILED] Pilihan tidak valid")
        break;