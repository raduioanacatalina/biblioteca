//
// Created by Catalina on 27.11.2020.
//

#ifndef BIBLIOTECA_ARTICOL_H
#define BIBLIOTECA_ARTICOL_H

#include <string>
#include <vector>
#include "Autor.h"
#include "ManuscrisCuAutor.h"

class Articol : public ManuscrisCuAutor {
private:
    std::string titlu;
    std::vector<Autor*> autori;

public:

    ~Articol();

    const std::string &getTitlu() const;

    void setTitlu(const std::string &titlu);

    const std::vector<Autor *> &getAutori() const;

    void setAutori(const std::vector<Autor *> &autori);


    void addAutor(Autor* autor);

};


#endif //BIBLIOTECA_ARTICOL_H
