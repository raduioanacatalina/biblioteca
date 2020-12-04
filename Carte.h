//
// Created by Catalina on 27.11.2020.
//

#ifndef BIBLIOTECA_CARTE_H
#define BIBLIOTECA_CARTE_H


#include <vector>
#include "Autor.h"
#include "Manuscris.h"
#include "ManuscrisCuAutor.h"

class Carte : public Manuscris, public ManuscrisCuAutor{
private:

    std::vector<Autor*> autori;
public:

    ~Carte();

    const std::vector<Autor *> &getAutori() const;

    void setAutori(const std::vector<Autor *> &autori);

    void addAutor(Autor* autor);
};


#endif //BIBLIOTECA_CARTE_H
