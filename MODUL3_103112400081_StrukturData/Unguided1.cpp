#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    double nilai_uts;
    double nilai_uas;
    double nilai_tugas;
    double nilai_akhir;
};

double hitungNilaiAkhir(double uts, double uas, double tugas) {
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

int main() {
    vector<Mahasiswa> daftar_mahasiswa;
    int jumlah_mahasiswa;

    cout << "Masukkan jumlah mahasiswa yang akan diinput (maksimal 10): ";
    cin >> jumlah_mahasiswa;

    if (jumlah_mahasiswa <= 0 || jumlah_mahasiswa > 10) {
        cout << "Jumlah mahasiswa tidak valid. Harap masukkan angka antara 1 dan 10." << endl;
        return 1;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < jumlah_mahasiswa; ++i) {
        Mahasiswa mahasiswa;

        cout << "\nMasukkan data untuk mahasiswa ke-" << i + 1 << ":" << endl;
        cout << "Nama: ";
        getline(cin, mahasiswa.nama);

        cout << "NIM: ";
        cin >> mahasiswa.nim;

        cout << "Nilai UTS: ";
        cin >> mahasiswa.nilai_uts;

        cout << "Nilai UAS: ";
        cin >> mahasiswa.nilai_uas;

        cout << "Nilai Tugas: ";
        cin >> mahasiswa.nilai_tugas;

        mahasiswa.nilai_akhir = hitungNilaiAkhir(mahasiswa.nilai_uts, mahasiswa.nilai_uas, mahasiswa.nilai_tugas);

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        daftar_mahasiswa.push_back(mahasiswa);
    }

    cout << "\n--- Data Mahasiswa ---" << endl;
    for (const auto& mhs : daftar_mahasiswa) {
        cout << "Nama: " << mhs.nama << endl;
        cout << "NIM: " << mhs.nim << endl;
        cout << "Nilai UTS: " << mhs.nilai_uts << endl;
        cout << "Nilai UAS: " << mhs.nilai_uas << endl;
        cout << "Nilai Tugas: " << mhs.nilai_tugas << endl;
        cout << "Nilai Akhir: " << mhs.nilai_akhir << endl;
        cout << "------------------------" << endl;
    }

    return 0;
}