//
// Created by Catalina on 27.11.2020.
//

#ifndef BIBLIOTECA_AUTOR_H
#define BIBLIOTECA_AUTOR_H


#include <string>

class Autor {
private:
    std::string nume;
    std::string prenume;
    int an_nastere;
public:
    int getAnNastere() const;

    void setAnNastere(int anNastere);

    const std::string &getNume() const;

    void setNume(const std::string &nume);

    const std::string &getPrenume() const;

    void setPrenume(const std::string &prenume);

};


#endif //BIBLIOTECA_AUTOR_H
