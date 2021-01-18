cmake_minimum_required(VERSION 3.17)
project(biblioteca)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -Weffc++")
add_executable(biblioteca main.cpp Manuscris.cpp Manuscris.h biblioteca.cpp biblioteca.h Carte.cpp Carte.h Autor.cpp Autor.h Revista.cpp Revista.h Articol.cpp Articol.h ManuscrisCuAutor.cpp ManuscrisCuAutor.h Manga.cpp Manga.h Helper.cpp Helper.h ExceptieData.cpp ExceptieData.h ExceptieTitluInexistent.cpp ExceptieTitluInexistent.h ExceptieCarteImprumutata.cpp ExceptieCarteImprumutata.h FactoryManuscrisAutor.cpp FactoryManuscrisAutor.h TipManuscris.cpp TipManuscris.h ExceptieTipCarteInvalid.cpp ExceptieTipCarteInvalid.h Sectiune.cpp Sectiune.h)