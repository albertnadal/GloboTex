#ifndef _TAULA_H
#define _TAULA_H

#include "ed.h"

// Classe base dels contenidors Taula.

template <class T>
class IteradorTaula;

template <class T>
class Taula :public ED{

 public:

 void inserir(char* k,const T& x, IteradorTaula<T>& it);
 void consulta(char* k, T& x, bool& noexist);
 void consulta(char* k, IteradorTaula<T>& it, bool& noexist);
 void consulta(IteradorTaula<T>& it, T& x);
 void eliminar(char* k);
 void eliminar(IteradorTaula<T>& it);
 void buidar();
};

#endif /*_TAULA_H*/  

