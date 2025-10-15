#include <iostream>
#include <iomanip>

using namespace std;

void displayArray(int arr[][3], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(4) << arr[i][j];
        }
        cout << endl;
    }
}

void swapArrays(int arr1[][3], int arr2[][3], int row, int col) {
    int temp = arr1[row][col];
    arr1[row][col] = arr2[row][col];
    arr2[row][col] = temp;
}

int main() {
    int array1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int array2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    int (*ptr1)[3] = array1;
    int (*ptr2)[3] = array2;

    cout << "Array 1 Asli:" << endl;
    displayArray(array1, 3, 3);

    cout << "\nArray 2 Asli:" << endl;
    displayArray(array2, 3, 3);

    swapArrays(array1, array2, 1, 1);

    cout << "\nArray 1 setelah menukar elemen pada (1,1):" << endl;
    displayArray(array1, 3, 3);

    cout << "\nArray 2 setelah menukar elemen pada (1,1):" << endl;
    displayArray(array2, 3, 3);

    return 0;
}