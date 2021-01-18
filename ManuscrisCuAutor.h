//
// Created by Catalina on 27.11.2020.
//

#ifndef BIBLIOTECA_MANUSCRISCUAUTOR_H
#define BIBLIOTECA_MANUSCRISCUAUTOR_H


#include "Autor.h"
#include "Manuscris.h"
#include <iostream>
#include <vector>
class ManuscrisCuAutor {
public:
    virtual void addAutor(Autor* autor) = 0;
    virtual const std::vector<Autor *> &getAutori() const = 0;
    friend std::ostream& operator<<(std::ostream& out, const ManuscrisCuAutor& m){
        out <<"Manuscris"<< std::endl;
        out <<"Autori: "<<std::endl;
        for(Autor* a : m.getAutori()){
            out <<"\t\t" << a->getNume() << " " << a->getPrenume()<<std::endl;
        }
        return out;
    }

    virtual ~ManuscrisCuAutor();
};


#endif //BIBLIOTECA_MANUSCRISCUAUTOR_H
