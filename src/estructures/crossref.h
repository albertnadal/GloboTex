#ifndef _CROSSREF_H
#define _CROSSREF_H

#include "operacions.h"
#include "thash.h"
#include "funcio-hash.h"
#include <iostream.h>
#include <string.h>

class etiqueta{
 public:
  char* nom;
  char* label;
  char* fitxer;
  char* compt;
 etiqueta() {};
 ~etiqueta() 
  {
     delete nom;
     delete label;
     delete fitxer;
     delete compt;
  };
};

class crossRef
{ 
  THash<etiqueta*,FH<1000>,1000> t;

public:

  crossRef() {};
  ~crossRef() {};

  void inserirEtiqueta(char* nom, char* eti, char* fitxer, char* compt)
   {
      etiqueta* aux = new etiqueta;
      aux->nom = new char[strlen(nom)+1];
      strcpy(aux->nom, nom);
      aux->label = new char[strlen(eti)+1];
      strcpy(aux->label, eti);
      aux->fitxer = new char[strlen(fitxer)+1];
      strcpy(aux->fitxer, fitxer);
      aux->compt = new char[strlen(compt)+1];
      strcpy(aux->compt, compt);

      t.inserir(nom, aux);
   }

  void consultarEtiqueta(char* nom, char*& eti, char*& fitxer, char*& compt, bool& noexist)
   {
      etiqueta* aux;
      t.consulta(nom, aux, noexist);
      if(!noexist)
       {
          eti = aux->label;
          fitxer = aux->fitxer;
          compt = aux->compt;
       }
   }
};
#endif /*_CROSSREF_H*/


