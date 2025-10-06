#include <iostream>

int hitungJumlah(int a, int b)
{
    return a + b;
}

void tampilHasil(int hasil)
{
    std::cout << "Hasil penjumlahannya adalah: " << hasil << std::endl;
}

int main()
{
    int angka1 = 25;
    int angka2 = 20;
    int hasilJumlah;

    hasilJumlah = hitungJumlah(angka1, angka2);
    tampilHasil(hasilJumlah);

    return 0;
}