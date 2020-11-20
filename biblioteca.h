//
// Created by Catalina on 10.11.2020.
//

#ifndef BIBLIOTECA_BIBLIOTECA_H
#define BIBLIOTECA_BIBLIOTECA_H


#include <utility>
#include <vector>
#include "carte.h"

class biblioteca {
     std::vector<carte> nr_carti;
     std::vector<carte> carti_imprumutate;
public:
    biblioteca();

    ~biblioteca() = default;

     void citire();
     void afisare();
     void sortare_id();
     bool add_carte(carte c);
     bool arhivare_carte(carte& c);
     carte* imprumuta(std::string nume);

     friend std::ostream& operator << (std::ostream&, biblioteca&);
};



#endif //BIBLIOTECA_BIBLIOTECA_H
