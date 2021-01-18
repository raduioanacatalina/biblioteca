//
// Created by Catalina on 09.01.2021.
//

#ifndef BIBLIOTECA_FACTORYMANUSCRISAUTOR_H
#define BIBLIOTECA_FACTORYMANUSCRISAUTOR_H


#include "ManuscrisCuAutor.h"
#include "TipManuscris.h"
#include "ExceptieTipCarteInvalid.h"
#include "Carte.h"
#include "Articol.h"
#include <vector>
#include "Autor.h"
#include "Manga.h"

class FactoryManuscrisAutor {
private:
    FactoryManuscrisAutor();
    static FactoryManuscrisAutor* instanta;
public:

    static FactoryManuscrisAutor* getInstanta(){
        if(instanta == nullptr){
            instanta = new FactoryManuscrisAutor();
        }
        return instanta;
    }

    ManuscrisCuAutor* createManuscris(TipManuscris tip, std::vector<Autor*> autorii, std::string titlu){
        ManuscrisCuAutor* rezultat = nullptr;
        switch(tip){
            case TipManuscris::CARTE: {
                Carte *c = new Carte();
                c->setNume(titlu);
                rezultat = c;
                break;
            }
            case TipManuscris::ARTICOL: {
                Articol *a = new Articol();
                a->setTitlu(titlu);
                rezultat = a;
                break;
            }
            case TipManuscris::MANGA :{
                Manga* m = new Manga();
                m->setNume(titlu);
            }
            default:
                ExceptieTipCarteInvalid* ex = new ExceptieTipCarteInvalid();
                throw ex;
        }
        for(Autor* a : autorii){
            rezultat->addAutor(a);
        }
        return rezultat;
    }
};



#endif //BIBLIOTECA_FACTORYMANUSCRISAUTOR_H
