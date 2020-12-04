//
// Created by Catalina on 27.11.2020.
//

#ifndef BIBLIOTECA_REVISTA_H
#define BIBLIOTECA_REVISTA_H


#include <vector>
#include "Manuscris.h"
#include "Articol.h"

class Revista : public Manuscris{
private:
    std::vector<Articol*> articole;
public:

    ~Revista();
    const std::vector<Articol *> &getArticole() const;

    void setArticole(const std::vector<Articol *> &articole);

    void addArticol(Articol* articolNou);
};


#endif //BIBLIOTECA_REVISTA_H
