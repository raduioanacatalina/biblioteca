//
// Created by Catalina on 10.11.2020.
//

#ifndef BIBLIOTECA_MANUSCRIS_H
#define BIBLIOTECA_MANUSCRIS_H


#include <string>

class Manuscris {
//    std::string categorie;
    std::string nume;
    int an_aparitie;
public:
    int getAnAparitie() const;

    void setAnAparitie(int anAparitie);

    std::string getNume(){
        return this->nume;
    }

    void setNume(std::string nume){
        this->nume = nume;
    }
private:
    int id{};
    friend class biblioteca;
public:

    Manuscris();

    Manuscris(const std::string &nume, int id);

    ~Manuscris();

    bool operator==(const Manuscris &rhs) const;

};


#endif //BIBLIOTECA_MANUSCRIS_H
