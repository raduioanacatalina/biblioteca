#include <iostream>
#include "Manuscris.h"
#include "biblioteca.h"
#include "Carte.h"
#include "Manga.h"
#include "Helper.h"
#include "ExceptieTitluInexistent.h"
#include "ExceptieCarteImprumutata.h"
#include <utility>
#include <memory>


// Clasa biblioteca(vector nr_carti), clasa Manuscris (nume, id)
// pentru tema 2 -> mostenire: tip de carti


int main() {

//    std::unique_ptr<biblioteca> ptr(biblioteca b);
    biblioteca b;
    std::unique_ptr<biblioteca> ptr = std::make_unique<biblioteca>(b);
    ptr->citire();
    ptr->afisare();
//    b.sortare_id();

    std::string titlu = "Metro2033";
    try {
         Manuscris* manuscrisImprumutat = nullptr;

         manuscrisImprumutat = ptr->imprumuta(titlu);
         manuscrisImprumutat = ptr->imprumuta(titlu);
         titlu = "Three body problem";
         manuscrisImprumutat = ptr->imprumuta(titlu);
    }catch(ExceptieTitluInexistent e){
        std::cout <<"Nu putem imprumuta cartea (nu exista in biblioteca) " << titlu << std::endl;
    }catch(ExceptieCarteImprumutata e){
        std::cout <<"Nu putem imprumuta cartea (cartea a fost deja imprumutata) " << titlu << std::endl;
    }


    Carte c1;
    Autor a1; // Autor* a1 = new Autor();
    a1.setNume("Asimov");
    a1.setPrenume("Isaac");

    a1.setAnNastere(2010);
    c1.addAutor(&a1);
//
//    Manga manga1;

    std::cout <<"**END PROGRAM**"<<std::endl;

     return 0;
}
