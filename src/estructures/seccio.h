/***** Classe SECCIO *****/
#ifndef _SECCIO_H
#define _SECCIO_H
#include "comptador.h"
#include "itellis.h"
#include "llista.h"

template <class T> class Llista;

class seccio
{

  comptador compt;
  Llista<seccio*> l;
public:
  char* nom;
  char* fitxer;
  char* cos;
  char* titol;
  seccio* seccio_superior;
  seccio* seccio_seguent;
  seccio* seccio_anterior;

  friend class aseccions;
  seccio() {};
  ~seccio() 
   {
      if (nom!=NULL) delete nom;
      if (fitxer!=NULL) delete fitxer;
      if (cos!=NULL) delete cos;
      if (titol!=NULL) delete titol;

      l.buidar(); 
   };

  void inserirSeccio(seccio* s) 
   {
      // L'estructura d'un document LaTeX garanteix que les seccions 
      // s'insereixen ordenadament

      bool buida;
      l.esBuida(buida);
      s->seccio_superior = this;

      if(buida) {l.inserirCap(s);}
      else 
        {
           seccio* u;
           l.consultarFi(u);
           comptador* c1 = u->consultarComptador();
           comptador* c2 = s->consultarComptador();
           if (CompCmp(c1,c2)==0) {u->inserirSeccio(s);}
           else {l.inserirFi(s);}
        }
   }

  void inserirComptador(comptador* c) 
    {
        compt = *(c);
        nom = compt.obtenirNom();
    };
  comptador* consultarComptador(){return &(compt);};
  int consultarNivell() {return compt.nivell;};
};


#endif










