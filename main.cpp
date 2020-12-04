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
#include <bits/unique_ptr.h>

// Clasa biblioteca(vector nr_carti), clasa Manuscris (nume, id)
// pentru tema 2 -> mostenire: tip de carti


int main() {

//    std::unique_ptr<biblioteca> ptr(biblioteca b);
    biblioteca b;
    std::unique_ptr<biblioteca> ptr = std::make_unique<biblioteca>(b);
    ptr->citire();
    ptr->afisare();
//    b.sortare_id();



    Manuscris* manuscrisImprumutat = nullptr;
    std::string titlu = "Metro2033";
    try {
        manuscrisImprumutat = ptr->imprumuta(titlu);
    }catch(ExceptieTitluInexistent e){
        std::cout <<"Nu putem imprumuta cartea (nu exista in biblioteca) " << titlu << std::endl;
    }catch(ExceptieCarteImprumutata e){
        std::cout <<"Nu putem imprumuta cartea (cartea a fost deja imprumutata) " << titlu << std::endl;
    }

    try {
        manuscrisImprumutat = ptr->imprumuta(titlu);
    }catch(ExceptieTitluInexistent e){
        std::cout <<"Nu putem imprumuta cartea (nu exista in biblioteca) " << titlu << std::endl;
    }catch(ExceptieCarteImprumutata e){
        std::cout <<"Nu putem imprumuta cartea (cartea a fost deja imprumutata) " << titlu << std::endl;
    }


    titlu = "Three body problem";
    std::cout <<"HERE"<<std::endl;
    try {
        manuscrisImprumutat = ptr->imprumuta(titlu);
    }catch(ExceptieTitluInexistent e){
        std::cout <<"Nu putem imprumuta cartea (nu exista in biblioteca) " << titlu << std::endl;
    }catch(ExceptieCarteImprumutata e){
        std::cout <<"Nu putem imprumuta cartea (cartea a fost deja imprumutata) " << titlu << std::endl;
    }
    std::cout <<"HERE 2"<<std::endl;

//    std::cout << " NUME M I: " <<  manuscrisImprumutat->getNume() <<" " << manuscrisImprumutat->getAnAparitie() << std::endl;
//    Manuscris* manuscrisImprumutat2 = b.imprumuta("Metro2033");

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
