#include <iostream>
using namespace std;

int main()
{
    int nilai[5] = {1,2,3,4,5};
    int panjang_var = sizeof(nilai) / sizeof(*nilai);
    cout << sizeof(*nilai);
    cout << panjang_var << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "Elemen ke-" << i << " = " << nilai[i] << endl;
    }

    return 0;
}