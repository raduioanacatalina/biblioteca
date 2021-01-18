#include <iostream>
#include "Manuscris.h"
#include "biblioteca.h"
#include "Carte.h"
#include "ExceptieTitluInexistent.h"
#include "ExceptieCarteImprumutata.h"
#include "TipManuscris.h"
#include "FactoryManuscrisAutor.h"
#include "Sectiune.h"
//#include <utility>
#include <memory>



int main() {

    biblioteca b;
    std::unique_ptr<biblioteca> ptr = std::make_unique<biblioteca>(b);
    ptr->citire();
    ptr->afisare();

    std::string titlu = "Metro2033";
    try {
         Manuscris* manuscrisImprumutat = nullptr;

         manuscrisImprumutat = ptr->imprumuta(titlu);
         manuscrisImprumutat = ptr->imprumuta(titlu);
         titlu = "Three body problem";
         manuscrisImprumutat = ptr->imprumuta(titlu);
         std::cout << manuscrisImprumutat->getNume() << std::endl;
    }catch(ExceptieTitluInexistent& e){
        std::cout <<"Nu putem imprumuta cartea (nu exista in biblioteca) " << titlu << std::endl;
    }catch(ExceptieCarteImprumutata& e){
        std::cout <<"Nu putem imprumuta cartea (cartea a fost deja imprumutata) " << titlu << std::endl;
    }


    Carte c1;
    Autor a1;
    a1.setNume("Asimov");
    a1.setPrenume("Isaac");
    a1.setAnNastere(2010);
    c1.addAutor(&a1);


    std::cout <<"==========================="<<std::endl;
    std::vector<Autor*> autoriNightfall;
    auto a2 = new Autor("Silverberg", "Robert", 1930);
    auto a3 = new Autor("Herbert", "Frank", 1933);

    autoriNightfall.push_back(&a1);
    autoriNightfall.push_back(a2);

    std::vector<Autor*> autoriDune;
    autoriDune.push_back(a3);

    auto a4 = new Autor("Gosling", "James", 1945);
    std::vector<Autor*> autoriArticol;
    autoriArticol.push_back(a4);

    FactoryManuscrisAutor* f1 = FactoryManuscrisAutor::getInstanta();
    ManuscrisCuAutor* nightFall = f1->createManuscris(TipManuscris::CARTE, autoriNightfall, "NightFall");
    FactoryManuscrisAutor* f2 = FactoryManuscrisAutor::getInstanta();
    ManuscrisCuAutor* dune = f2->createManuscris(TipManuscris::CARTE, autoriDune, "Dune");
    ManuscrisCuAutor* articol = f2->createManuscris(TipManuscris::ARTICOL, autoriArticol, "Best practices in Java 8");
    std::cout <<*nightFall << std::endl;
    std::cout <<*articol <<std::endl;
    std::cout <<"==========================="<<std::endl;
    Carte carte1;
    carte1.setNume("His dark materials");
    carte1.setAnAparitie(2003);
    Carte carte2;
    carte2.setNume("Independence Day");
    carte2.setAnAparitie(1994);


    Articol articol1;
    articol1.setTitlu("Articol despre C++");
    Articol articol2;
    articol2.setTitlu("Articol despre php");

    Autor autorArticol1;
    autorArticol1.setNume("Sourstroup");
    autorArticol1.setPrenume("Bjarne");

    articol1.addAutor(&autorArticol1);

    Sectiune<Articol*> sectiuneArticole;
    Sectiune<Carte*> sectiuneCarti;


    std::vector<Articol*> articoleSectiune;

    articoleSectiune.push_back(&articol1);
    articoleSectiune.push_back(&articol2);


    std::cout <<"Adaugam articolele in sectiune: "<<std::endl;
    for(Articol* a : articoleSectiune){
        std::cout <<"\t\t" << a->getTitlu() << std::endl;
    }

    std::vector<Carte*> cartiSectiune;
    cartiSectiune.push_back(&carte1);
    cartiSectiune.push_back((Carte*)dune);
    sectiuneCarti.setElemente(cartiSectiune);
    sectiuneArticole.setElemente(articoleSectiune);

    std::cout <<"==============sectiuni=============="<<std::endl;
    sectiuneArticole.displaySectiune();
    sectiuneCarti.displaySectiune();

    std::cout <<"**END PROGRAM**"<<std::endl;

    return 0;
}
