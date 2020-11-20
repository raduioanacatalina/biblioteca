//
// Created by Catalina on 10.11.2020.
//

#ifndef BIBLIOTECA_CARTE_H
#define BIBLIOTECA_CARTE_H


#include <string>

class carte {
    std::string nume;
    int id{};
    friend class biblioteca;
public:

    carte();

    carte(const std::string &nume, int id);

    ~carte();

    bool operator==(const carte &rhs) const;

};


#endif //BIBLIOTECA_CARTE_H
