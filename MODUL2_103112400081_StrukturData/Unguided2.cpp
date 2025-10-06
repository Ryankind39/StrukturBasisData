#include <iostream>

void kuadratkan(int &angka) {
    angka = angka * angka;
}

int main() {
    int nilaiAwal;

    std::cout << "Masukkan nilai awal: ";
    std::cin >> nilaiAwal;

    std::cout << "Nilai awal: " << nilaiAwal << std::endl;

    kuadratkan(nilaiAwal);

    std::cout << "Nilai setelah dikuadratkan: " << nilaiAwal << std::endl;

    return 0;
}