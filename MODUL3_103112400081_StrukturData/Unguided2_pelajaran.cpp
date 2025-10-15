#include "Unguided2_pelajaran.h"

Pelajaran create_pelajaran(std::string namaMapel, std::string kodeMapel) {
    Pelajaran pel;
    pel.namaMapel = namaMapel;
    pel.kodeMapel = kodeMapel;
    return pel;
}

void tampil_pelajaran(Pelajaran pel) {
    std::cout << "Nama Mata Pelajaran: " << pel.namaMapel << std::endl;
    std::cout << "Kode Mata Pelajaran: " << pel.kodeMapel << std::endl;
}