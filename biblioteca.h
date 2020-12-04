//
// Created by Catalina on 10.11.2020.
//

#ifndef BIBLIOTECA_BIBLIOTECA_H
#define BIBLIOTECA_BIBLIOTECA_H


#include <utility>
#include <vector>
#include "Manuscris.h"
#include <algorithm>

class biblioteca {
     std::vector<Manuscris*> nr_carti;
     std::vector<Manuscris*> carti_imprumutate;
public:
    biblioteca();

    ~biblioteca() = default;

     void citire();
     void afisare();
     void sortare_id();
     bool add_carte(Manuscris* c);
     bool arhivare_carte(Manuscris* c);
     Manuscris* imprumuta(std::string nume);

     friend std::ostream& operator << (std::ostream&, biblioteca&);
};



#endif //BIBLIOTECA_BIBLIOTECA_H
