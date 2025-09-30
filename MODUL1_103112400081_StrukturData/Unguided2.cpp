#include <iostream>
#include <string>

using namespace std;

// Fungsi untuk mengonversi angka satuan menjadi tulisan
string angkaKeSatuan(int n) {
    switch (n) {
        case 0: return "Nol"; // Meskipun soal bilang positif, 0 sering disertakan
        case 1: return "Satu";
        case 2: return "Dua";
        case 3: return "Tiga";
        case 4: return "Empat";
        case 5: return "Lima";
        case 6: return "Enam";
        case 7: return "Tujuh";
        case 8: return "Delapan";
        case 9: return "Sembilan";
        default: return ""; // Seharusnya tidak tercapai untuk input 0-9
    }
}

// Fungsi utama untuk mengonversi angka 0-100 menjadi tulisan
string angkaKeTulisan(int n) {
    if (n >= 0 && n <= 9) {
        return angkaKeSatuan(n);
    } else if (n >= 10 && n <= 19) {
        if (n == 10) return "Sepuluh";
        else if (n == 11) return "Sebelas";
        else { // 12-19
            return angkaKeSatuan(n % 10) + " Belas";
        }
    } else if (n >= 20 && n <= 99) {
        int puluhan = n / 10;
        int satuan = n % 10;
        string hasil = angkaKeSatuan(puluhan) + " Puluh";
        if (satuan != 0) {
            hasil += " " + angkaKeSatuan(satuan);
        }
        return hasil;
    } else if (n == 100) {
        return "Seratus";
    }
    return "Angka di luar rentang (0-100)"; // Untuk input di luar 0-100
}

int main() {
    int angka;

    cout << "Masukkan bilangan bulat positif (0 s.d 100): ";
    cin >> angka;

    // Validasi input
    if (angka < 0 || angka > 100) {
        cout << "Maaf, angka yang Anda masukkan harus antara 0 sampai 100." << endl;
    } else {
        cout << angka << " : " << angkaKeTulisan(angka) << endl;
    }

    return 0;
}