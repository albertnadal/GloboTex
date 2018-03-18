#ifndef _ITELLIS_H
#define _ITELLIS_H

#include <stdlib.h>
#include <iostream>
#include "iterador.h"
#include "llista.h"

using namespace std;

/******************************************************************

Classe IteradorLlista

Subclasse de Iterador<T>. Permet fer iteracions sobre llistes.

l'anterior de l'actual.  
*******************************************************************/

template<class T>
class IteradorLlista :public Iterador<T>{
  Llista<T>* ref;
 node<T>* ed; // ed apunta al node anterior del que es refereix l'iterador.

 public:

 friend class Llista<T>;

 IteradorLlista(Llista<T>& l);
 void situarInici();
 void situarFinal();
 IteradorLlista<T>& operator++();
 IteradorLlista<T>& operator++(int i);
 T& operator*();
 bool fi();
 bool inici();
 void operator=(IteradorLlista<T>& it2);
 friend bool operator==<T>(IteradorLlista<T>&, IteradorLlista<T>&);
};


template<class T>
IteradorLlista<T>::IteradorLlista(Llista<T>& l)
{ref=&l; ed=l.primer;}

template<class T>
void IteradorLlista<T>::situarInici()
{ed=ref->primer;}

template<class T>
void IteradorLlista<T>::situarFinal()
{ed=ref->primer->ant;} 
 
template<class T>
IteradorLlista<T>& IteradorLlista<T>::operator++() // ++it
{ // Retornem una copia del objecte despres d'incrementar-lo
  // Recordeu en el cas de variables enteres:
  // x = 4;
  // y = ++x;
  // x i y valen 5.

  IteradorLlista<T>* aux;
  aux=new IteradorLlista<T>(*ref);
  ed=ed->seg; 
  *aux=*this; 
  return *aux;
}
 
template<class T>
IteradorLlista<T>& IteradorLlista<T>::operator++(int i) // it++
{ // Retornerm una copia de l'objecte abans d'incrementar-lo
  // Recordeu en el cas de variables enteres:
  // x = 4;
  // y = x++;
  // x val 5 pero y val 4

  IteradorLlista<T>* aux;
  aux=new IteradorLlista<T>(*ref);
  *aux=*this; 
  ed=ed->seg; 
  return *aux;
}

template<class T>
T& IteradorLlista<T>::operator*()
{return ed->seg->valor;}
 
template<class T>
bool IteradorLlista<T>::fi()
{return  ed->seg==ref->primer;}

template<class T>
bool IteradorLlista<T>::inici()
{return  ed==ref->primer;}
 
template<class T>
void IteradorLlista<T>::operator=(IteradorLlista<T>& it2)
{ //En realitat es innecessaria. 
  //La definida per defecte pel compilador fa el mateix.
  ref=it2.ref; 
  ed=it2.ed;} 


  
template <class T>
bool operator==(IteradorLlista<T>& i1, IteradorLlista<T>& i2){

  return (i1.ref==i2.ref && i1.ed==i2.ed);
}  

#endif

