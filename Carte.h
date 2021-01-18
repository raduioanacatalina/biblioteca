//
// Created by Catalina on 27.11.2020.
//

#ifndef BIBLIOTECA_CARTE_H
#define BIBLIOTECA_CARTE_H


#include <vector>
#include "Autor.h"
#include "Manuscris.h"
#include "ManuscrisCuAutor.h"
#include <iostream>

class Carte : public Manuscris, public ManuscrisCuAutor{
private:

    std::vector<Autor*> autori;
public:

    ~Carte();

    const std::vector<Autor *> &getAutori() const;

    void setAutori(const std::vector<Autor *> &autori);

    void addAutor(Autor* autor);
    friend std::ostream& operator<<(std::ostream& out, const Carte& c){
        out <<"Carte: titlu = " << c.nume << std::endl;
        out <<"Autori: "<<std::endl;
        for(Autor* a : c.getAutori()){
            out <<"\t\t" << a->getNume() << " " << a->getPrenume()<<std::endl;
        }
        return out;
    }
};


#endif //BIBLIOTECA_CARTE_H
