//
// Created by Catalina on 10.11.2020.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include "biblioteca.h"

biblioteca::biblioteca() {
    std::cout<<"apel constructor" <<'\n';
}

bool biblioteca::add_carte(carte c){
    bool exista = false;

    for(int i=0; i< nr_carti.size(); i++){
        carte carte_din_biblioteca = nr_carti[i];
        if(c.id == carte_din_biblioteca.id){
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

bool biblioteca::arhivare_carte(carte& c) {
    int pozitie_in_vector = -1;
    for(int i=0; i<nr_carti.size(); i++){
        carte carte_b = nr_carti[i];
        if(carte_b.id == c.id){
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
    carte c;
    for (int i= 0; i < n; ++i){
        in >> c.nume >> c.id;
        bool carte_adaugata_cu_succes = add_carte(c);
        // nr_carti.push_back(c);
        if(carte_adaugata_cu_succes){
            std::cout <<"Am adaugat cartea: " << c.nume << std::endl;
        }else{
            std::cout <<"Cartea deja exista in biblioteca: "<<c.nume<< std::endl;
        }
    }
}
void biblioteca::afisare() {
    for (auto & i : nr_carti) {
        std::cout<<i.nume<<" "<<i.id<<'\n';
    }
}

carte* biblioteca::imprumuta(std::string nume){
    carte* c = NULL;

    for(int i=0; carti_imprumutate.size(); i++){
        carte carte_i = carti_imprumutate[i];
        if(carte_i.nume.compare(nume) == 0){
            return NULL;
        }
    }

    for(int i=0; i<nr_carti.size(); i++){
        carte carte_b = nr_carti[i];
        if(carte_b.nume.compare(nume) == 0){
            c = &carte_b;
            carti_imprumutate.push_back(carte_b);
        }
    }
    return c;
}

void biblioteca::sortare_id() {
    std::sort(nr_carti.begin(), nr_carti.end(), [](const carte &a, const carte &b) { return a.id < b.id; });
    std::cout<<"Sortare dupa id"<<'\n';
    for (auto& i : nr_carti)
        std::cout<<i.id<<" "<<'\n';
}

std::ostream& operator << (std::ostream& out, biblioteca& b)
{
    out<<"nr carti: " << b.nr_carti.size();
    return out;
}