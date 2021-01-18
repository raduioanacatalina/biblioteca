//
// Created by Catalina on 27.11.2020.
//

#ifndef BIBLIOTECA_MANGA_H
#define BIBLIOTECA_MANGA_H


#include "Manuscris.h"
#include "ManuscrisCuAutor.h"

class Manga : public Manuscris, public ManuscrisCuAutor {
private:
    std::vector<Autor*> autori;

public:
    void addAutor(Autor* autor);
    const std::vector<Autor *> &getAutori() const;

};


#endif //BIBLIOTECA_MANGA_H
