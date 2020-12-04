//
// Created by Catalina on 10.11.2020.
//

#include <iostream>
#include "Manuscris.h"

Manuscris::Manuscris(const std::string &nume, int id) {
    this->nume = nume;
    this->id = id;
}

Manuscris::~Manuscris() {
    nume = " ";
}

bool Manuscris::operator==(const Manuscris &rhs) const {
    return nume == rhs.nume &&
           id == rhs.id;
}

Manuscris::Manuscris() {
   std::cout<<"Apeld construcotr"<<'\n';
}

int Manuscris::getAnAparitie() const {
    return an_aparitie;
}

void Manuscris::setAnAparitie(int anAparitie) {
    an_aparitie = anAparitie;
}

