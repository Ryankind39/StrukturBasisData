#include <iostream>
#include <iomanip> // Required for setprecision

using namespace std;

int main() {
  float bilangan1, bilangan2;

  // Meminta input dari pengguna
  cout << "Masukkan bilangan pertama: ";
  cin >> bilangan1;
  cout << "Masukkan bilangan kedua: ";
  cin >> bilangan2;

  // Melakukan perhitungan
  float penjumlahan = bilangan1 + bilangan2;
  float pengurangan = bilangan1 - bilangan2;
  float perkalian = bilangan1 * bilangan2;
  float pembagian = bilangan1 / bilangan2;

  // Menampilkan hasil dengan format yang lebih rapi
  cout << fixed << setprecision(2); // Menetapkan 2 angka desimal
  cout << "Penjumlahan: " << penjumlahan << endl;
  cout << "Pengurangan: " << pengurangan << endl;
  cout << "Perkalian: " << perkalian << endl;

  // Menangani kasus pembagian oleh nol
  if (bilangan2 != 0) {
    cout << "Pembagian: " << pembagian << endl;
  } else {
    cout << "Pembagian tidak dapat dilakukan karena bilangan kedua adalah nol." << endl;
  }

  return 0;
}