//
// Created by Catalina on 27.11.2020.
//

#ifndef BIBLIOTECA_ARTICOL_H
#define BIBLIOTECA_ARTICOL_H

#include <iostream>
#include <string>
#include <vector>
#include "Autor.h"
#include "ManuscrisCuAutor.h"

class Articol : public ManuscrisCuAutor {
private:
    std::string titlu;
    std::vector<Autor*> autori;

public:

    Articol();
    Articol(std::string titlu, std::vector<Autor*> autori);

    ~Articol();

    const std::string &getTitlu() const;

    void setTitlu(const std::string &titlu);

    const std::vector<Autor *> &getAutori() const;

    void setAutori(const std::vector<Autor *> &autori);


    void addAutor(Autor* autor);

    friend std::ostream& operator<<(std::ostream& out, const Articol& art){
        out <<"Articol: titlu = " << art.titlu << std::endl;
        out <<"Autori: "<<std::endl;
        for(Autor* a : art.getAutori()){
            out <<"\t\t" << a->getNume() << " " << a->getPrenume()<<std::endl;
        }
        return out;
    }

};


#endif //BIBLIOTECA_ARTICOL_H
