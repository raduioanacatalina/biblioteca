//
// Created by Catalina on 27.11.2020.
//

#include "Revista.h"

const std::vector<Articol *> &Revista::getArticole() const {
    return articole;
}

void Revista::setArticole(const std::vector<Articol *> &articole) {
    Revista::articole = articole;
}


void Revista::addArticol(Articol* articolNou){
    this->articole.push_back(articolNou);
}

Revista::~Revista(){
    for(int i=0; i<this->articole.size(); i++){
        delete this->articole[i];
    }
}