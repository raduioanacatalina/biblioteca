//
// Created by Catalina on 27.11.2020.
//

#include "Autor.h"
#include "Helper.h"
#include "ExceptieData.h"

const std::string &Autor::getNume() const {
    return nume;
}

void Autor::setNume(const std::string &nume) {
    Autor::nume = nume;
}

const std::string &Autor::getPrenume() const {
    return prenume;
}

void Autor::setPrenume(const std::string &prenume) {
    Autor::prenume = prenume;
}

int Autor::getAnNastere() const {
    return an_nastere;
}

void Autor::setAnNastere(int anNastere) {
    int anCurent = Helper::getAnCurent();
    if(anNastere >= anCurent){
        ExceptieData exceptie;
        throw exceptie;
    }
    an_nastere = anNastere;
}
