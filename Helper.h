//
// Created by Catalina on 27.11.2020.
//

#ifndef BIBLIOTECA_HELPER_H
#define BIBLIOTECA_HELPER_H

#include <ctime>


class Helper {
public:
    static int getAnCurent(){
        time_t now = time(0);
        tm *ltm = localtime(&now);
        int anCurent = 1900 + ltm->tm_year;
        return anCurent;
    }
};


#endif //BIBLIOTECA_HELPER_H
