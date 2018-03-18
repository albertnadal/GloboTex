#ifndef _PILAENTORNS_H
#define _PILAENTORNS_H

#include "operacions.h"
#include "llista.h"
#include <iostream.h>
#include <string.h>

template <class T> class Llista;

class entorn{
 public:
  char* etiqueta;
  char* compt;
 entorn() {};
 ~entorn() 
  {
     delete etiqueta;
     delete compt;
  };
};

class pilaEntorns
{ 
  Llista<entorn*> l;
public:

  pilaEntorns() {};
  ~pilaEntorns() {};
  void apilarEntorn(char* etiqueta, char* comptador)
   {
      entorn* aux = new entorn;
      aux->etiqueta = new char[strlen(etiqueta)+1];
      strcpy(aux->etiqueta, etiqueta);
      aux->compt = new char[strlen(comptador)+1];
      strcpy(aux->compt, comptador);
      l.inserirCap(aux);
   };

  void desapilarEntorn() {l.eliminarCap();};

  void consultarEntornActual(char*& etiqueta, char*& comptador)
   {
      entorn* aux;
      l.consultarCap(aux);
      etiqueta = new char[strlen(aux->etiqueta)+1];
      strcpy(etiqueta,aux->etiqueta);
      comptador = new char[strlen(aux->compt)+1];
      strcpy(comptador,aux->compt);
   }
};

#endif /*_PILAENTORNS_H*/

