//
// Created by Catalina on 15.01.2021.
//

#ifndef BIBLIOTECA_SECTIUNE_H
#define BIBLIOTECA_SECTIUNE_H

#include <iostream>
#include <string>
#include <vector>

template <class T>
class Sectiune {
private:
    std::string denumire;
    std::vector<T> elemente;
public:
//    const std::string &getDenumire() const;
//
//    void setDenumire(const std::string &denumire);
//
//    // std::vector<T*> &getElemente();
//
//    void setElemente(const std::vector<T*> &elemente);
//
//
//    void displaySectiune();
//
//





    // ==================




    const std::string getDenumire() const {
        return denumire;
    }


    void setDenumire(const std::string &denumire) {
        Sectiune::denumire = denumire;
    }



    void setElemente(const std::vector<T> &elemente) {
        Sectiune::elemente = elemente;
    }


    void displaySectiune() {
        std::cout <<"In sectiunea: " << this->denumire <<" avem elementele: " << std::endl;
        for(T element : elemente){
            std::cout << "\t\t" << *element << std::endl;
        }
    }
};


#endif //BIBLIOTECA_SECTIUNE_H
