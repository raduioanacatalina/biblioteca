#include <iostream>
#include "carte.h"
#include "biblioteca.h"

// Clasa biblioteca(vector nr_carti), clasa carte (nume, id)
// pentru tema 2 -> mostenire: tip de carti


int main() {
    biblioteca b;
    b.citire();
    b.afisare();
    b.sortare_id();
     return 0;
}
