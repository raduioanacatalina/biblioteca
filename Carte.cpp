//
// Created by Catalina on 27.11.2020.
//

#include "Carte.h"

const std::vector<Autor *> &Carte::getAutori() const {
    return autori;
}

void Carte::setAutori(const std::vector<Autor *> &autori) {
    Carte::autori = autori;
}

void Carte::addAutor(Autor* autor){
    this->autori.push_back(autor);
}
Carte::~Carte(){
    for(int i=0; i<this->autori.size(); i++){
        delete autori[i];
    }
}