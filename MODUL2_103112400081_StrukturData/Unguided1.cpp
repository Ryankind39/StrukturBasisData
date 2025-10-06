#include <iostream>

int main() {
    int originalMatrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int transposedMatrix[3][3];

    std::cout << "Matriks Awal:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << originalMatrix[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            transposedMatrix[j][i] = originalMatrix[i][j];
        }
    }

    std::cout << "Matriks Hasil Transpose:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << transposedMatrix[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}