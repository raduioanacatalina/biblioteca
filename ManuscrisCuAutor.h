//
// Created by Catalina on 27.11.2020.
//

#ifndef BIBLIOTECA_MANUSCRISCUAUTOR_H
#define BIBLIOTECA_MANUSCRISCUAUTOR_H


#include "Autor.h"
#include "Manuscris.h"

class ManuscrisCuAutor {
public:
    virtual void addAutor(Autor* autor) = 0;
};


#endif //BIBLIOTECA_MANUSCRISCUAUTOR_H
