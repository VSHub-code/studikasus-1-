#include <iostream>
#include <string>
using namespace std;

class Pembelian {
private:
    string nama;
    string jenis;
    double liter;
    double harga;
    double total;

public:
    Pembelian() {
        nama ;
        jenis ;
        liter ;
        harga ;
        total ;
    }
    
    void hitungTotal() {
        total = liter * harga;
    }
    friend istream& operator>>(istream& input, Pembelian& p);
    friend ostream& operator<<(ostream& output, const Pembelian& p);
};
istream& operator>>(istream& input, Pembelian& p) {
    int pilih;
    
    cout << "======= PROGRAM SPBU =======" << endl;
    cout << "Masukkan nama pelanggan: ";
    getline(input, p.nama);
    
    cout << "\nPilih jenis bensin:" << endl;
    cout << "1. Pertalite (Rp. 7.000/liter)" << endl;
    cout << "2. Pertamax (Rp. 9.000/liter)" << endl;
    cout << "Pilihan [1/2]: ";
    input >> pilih;
    
    if (pilih == 1) {
        p.jenis = "Pertalite";
        p.harga = 7000;
    } else {
        p.jenis = "Pertamax";
        p.harga = 9000;
    }
    
    cout << "Masukkan jumlah liter: ";
    input >> p.liter;
    
    p.hitungTotal();
    
    system("cls");
    
    return input;
}
ostream& operator<<(ostream& output, const Pembelian& p) {
    static int noStruk = 1001;
    
    output << "\n===========================================" << endl;
    output << "            SPBU PERTAMINA                " << endl;
    output << "===========================================" << endl;
    
    output << "\n No. Struk : " << noStruk << endl;
    
    output << "\n------------------------------------------" << endl;
    output << " Nama Pelanggan : " << p.nama << endl;
    output << "------------------------------------------" << endl;
    
    output << "\n Produk       : " << p.jenis << endl;
    output << " Harga/Liter  : Rp. " << p.harga << endl;
    output << " Jumlah Liter : " << p.liter << endl;
    output << " Total Harga  : Rp. " << p.total << endl;
    
    output << "\n------------------------------------------" << endl;
    output << " TOTAL BAYAR  : Rp. " << p.total << endl;
    output << "------------------------------------------" << endl;
    
    output << "      Terima Kasih Atas Kunjungan Anda     " << endl;
    output << "         Selamat Jalan, Hati-hati!         " << endl;
    output << "===========================================" << endl;
    
    noStruk++;
    
    return output;
}

int main() {
    Pembelian pembelian;
    cin >> pembelian;
    cout << pembelian;
    
    return 0;
}
