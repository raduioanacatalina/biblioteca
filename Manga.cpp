//
// Created by Catalina on 27.11.2020.
//

#include "Manga.h"

void Manga::addAutor(Autor* autor){
        this->autori.push_back(autor);
}

const std::vector<Autor *> &Manga::getAutori() const {
    return autori;
}