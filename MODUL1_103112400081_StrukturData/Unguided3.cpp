#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Input: ";
    cin >> n;
    
    cout << "Output:" << endl;
    
    // Simpan nilai n asli
    int original_n = n;
    
    // Loop untuk setiap baris
    for (int i = 1; i <= original_n; i++) {
        // Print angka dari n turun sampai 1
        for (int j = n; j >= 1; j--) {
            cout << j << " ";
        }
        
        // Print tanda *
        cout << "* ";
        
        // Print angka dari 1 naik sampai n
        for (int j = 1; j <= n; j++) {
            cout << j << " ";
        }
        
        cout << endl;
        
        // Kurangi n untuk baris berikutnya
        n--;
    }
    
    return 0;
}