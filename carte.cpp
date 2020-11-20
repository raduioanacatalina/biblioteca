//
// Created by Catalina on 10.11.2020.
//

#include <iostream>
#include "carte.h"

carte::carte(const std::string &nume, int id) {
    this->nume = nume;
    this->id = id;
}

carte::~carte() {
    nume = " ";
}

bool carte::operator==(const carte &rhs) const {
    return nume == rhs.nume &&
           id == rhs.id;
}

carte::carte() {
   std::cout<<"Apeld construcotr"<<'\n';
}

