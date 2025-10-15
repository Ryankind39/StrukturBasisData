#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>
#include <iostream>

struct Pelajaran {
    std::string namaMapel;
    std::string kodeMapel;
};

Pelajaran create_pelajaran(std::string namaMapel, std::string kodeMapel);

void tampil_pelajaran(Pelajaran pel);

#endif