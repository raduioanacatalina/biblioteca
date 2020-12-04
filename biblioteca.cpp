//
// Created by Catalina on 10.11.2020.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include "biblioteca.h"
#include "ExceptieTitluInexistent.h"
#include "ExceptieCarteImprumutata.h"

biblioteca::biblioteca() {
    std::cout<<"apel constructor" <<'\n';
}

bool biblioteca::add_carte(Manuscris* c){
    bool exista = false;

    for(int i=0; i< nr_carti.size(); i++){
        Manuscris* carte_din_biblioteca = nr_carti[i];
        if(c->id == carte_din_biblioteca->id){
            exista = true;
            break;
        }
    }
    if(!exista){
        nr_carti.push_back(c);
        return true;
    }
    return false;
}

bool biblioteca::arhivare_carte(Manuscris* c) {
    int pozitie_in_vector = -1;
    for(int i=0; i<nr_carti.size(); i++){
        Manuscris* carte_b = nr_carti[i];
        if(carte_b->id == c->id){
            pozitie_in_vector = i;
            break;
        }
    }
    if(pozitie_in_vector == -1){
        return false;
    }
    nr_carti.erase (nr_carti.begin()+pozitie_in_vector);
    return true;
}

void biblioteca::citire() {
    std::ifstream in("in.txt");
    int n; //n = nr carti
    in >> n;
    std::cout<<n<<'\n'; // nu citeste n, de ce?

    for (int i= 0; i < n; ++i){
        Manuscris* c = nullptr;
        c = new Manuscris();
        in >> c->nume >> c->id;
        bool carte_adaugata_cu_succes = add_carte(c);
        // nr_carti.push_back(c);
        if(carte_adaugata_cu_succes){
            std::cout <<"Am adaugat cartea: " << c->nume << std::endl;
        }else{
            std::cout <<"Cartea deja exista in biblioteca: "<<c->nume<< std::endl;
        }
    }
}
void biblioteca::afisare() {
    for (auto & i : nr_carti) {
        std::cout<< "|" << i->nume<<"| "<<i->id<<'\n';
    }
}

Manuscris* biblioteca::imprumuta(std::string nume){
    Manuscris* c = nullptr;

    bool titluGasit = false;
    for(int i=0; i<nr_carti.size(); i++){
        Manuscris* carte_i = nr_carti[i];
//        std::cout <<"DEBUG BEFORE: " << carte_i->getNume() << std::endl;
        if(carte_i->nume.compare(nume) == 0){
            titluGasit = true;
            c = carte_i;
            break;
        }
    }
//    std::cout <<"DEBUG: " << nume << " " << titluGasit << " " << std::endl;
    if(!titluGasit){
        ExceptieTitluInexistent ex;
        throw ex;
    }

    if ( std::find(carti_imprumutate.begin(), carti_imprumutate.end(), c) != carti_imprumutate.end() )
    {
        ExceptieCarteImprumutata ex;
        throw ex;
    }


    if(c != nullptr){
        this->carti_imprumutate.push_back(c);
    }
//    for(int i=0; i<nr_carti.size(); i++){
//        Manuscris* carte_b = nr_carti[i];
//        if(carte_b->nume.compare(nume) == 0){
//            c = carte_b;
//            carti_imprumutate.push_back(carte_b);
//        }
//    }
    return c;
}

void biblioteca::sortare_id() {
    std::sort(nr_carti.begin(), nr_carti.end(), [](const Manuscris *a, const Manuscris *b) { return a->id < b->id; });
    std::cout<<"Sortare dupa id"<<'\n';
    for (auto& i : nr_carti)
        std::cout<<i->id<<" "<<'\n';
}

std::ostream& operator << (std::ostream& out, biblioteca& b)
{
    out<<"nr carti: " << b.nr_carti.size();
    return out;
}