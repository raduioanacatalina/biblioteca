//
// Created by Catalina on 27.11.2020.
//

#include "Articol.h"

const std::string &Articol::getTitlu() const {
    return titlu;
}

void Articol::setTitlu(const std::string &titlu) {
    Articol::titlu = titlu;
}

const std::vector<Autor *> &Articol::getAutori() const {
    return autori;
}

void Articol::setAutori(const std::vector<Autor *> &autori) {
    Articol::autori = autori;
}


void Articol::addAutor(Autor* autor){
    this->autori.push_back(autor);
}

Articol::~Articol() {
    for(int i=0; i<this->autori.size(); i++) {
        delete this->autori[i];
    }
}

Articol::Articol() {

}

Articol::Articol(std::string titlu, std::vector<Autor *> autori) : titlu(titlu), autori(autori){

}
