#include "Unguided2_pelajaran.h"

int main() {
    Pelajaran matematika = create_pelajaran("Matematika", "MTK123");

    std::cout << "--- Data Mata Pelajaran ---" << std::endl;
    tampil_pelajaran(matematika);

    return 0;
}