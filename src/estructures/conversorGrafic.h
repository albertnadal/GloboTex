#ifndef _CONVERSORGRAFIC_H
#define _CONVERSORGRAFIC_H

#include "operacions.h"
#include "llista.h"
#include <iostream.h>
#include <string.h>

template <class T> class Llista;

class imatge{
 public:
  char* fitxer;
 imatge() {};
 ~imatge() {delete fitxer;};
};

class fragment{
 public:
  char* math;
  char* nom;
 fragment() {};
 ~fragment() {delete math; delete nom;};
};

class conversorGrafic
{ 
  Llista<imatge*> limatges;
  Llista<fragment*> lfragments;
  int comptador;
  char* carpeta;
public:

  conversorGrafic() {comptador=1;};
  ~conversorGrafic() {delete carpeta;};

  char* inserirFragmentMatematic(char* fragment_mat)
   {
       fragment* aux = new fragment;
       char* f = new char[strlen(fragment_mat) + 1];
       char* fitxer = new char[15];
       char* nom = new char[10];

       sprintf(fitxer, "mat%d.gif", comptador);
       sprintf(nom, "mat%d", comptador);
       strcpy(f, fragment_mat);
       aux->math = f;
       aux->nom = nom;
       lfragments.inserirFi(aux);
       comptador++;

       return fitxer;
   }

  void inserirImatge(char* img)
   {
       imatge* aux = new imatge;
       char* ruta = new char[strlen(img) + 1];

       strcpy(ruta, img);
       aux->fitxer = ruta;
       limatges.inserirFi(aux);
   };

  void assignarCarpeta(char* c)
   {
       carpeta = new char[strlen(c) + 1];
       strcpy(carpeta, c);
   }

  void buidar()
   {
       limatges.buidar();
       lfragments.buidar();
   }

  void iniciarConversio()
   {
      bool existeix_pstogif=true;
      bool existeix_latextogif=true;
      if(!fitxerExisteix("ps2gif")) 
       {
         existeix_pstogif=false;
         cout << "Avís-> No s'ha trobat l'script 'ps2gif' necessari per crear els fitxers gràfics\n";
       }

      if(existeix_pstogif) {iniciarConversioImatges();}

      if(!fitxerExisteix("latex2gif")) 
       {
         existeix_latextogif=false;
         cout << "Avís-> No s'ha trobat l'script 'latex2gif' necessari per tractar els fragments matemàtics\n";
       }

      if((existeix_latextogif)&&(existeix_pstogif)) {iniciarConversioMatematica();}
   }

  void iniciarConversioMatematica()
   {
       fragment* f;
       char* fitxer_gif;
       char* ruta_fitxer_gif;

       while(lfragments.primer->seg!=lfragments.primer)
         {
                 lfragments.consultarCap(f);

                 fitxer_gif = canviarExtensioGrafica(f->nom);
                 ruta_fitxer_gif = new char[strlen(carpeta) + strlen(fitxer_gif) + 2];
                 strcpy(ruta_fitxer_gif, carpeta);
                 strcat(ruta_fitxer_gif, "/");
                 strcat(ruta_fitxer_gif, fitxer_gif);
                 latexToGif(f->math, f->nom, ruta_fitxer_gif);
                 lfragments.eliminarCap();
                 free(ruta_fitxer_gif); free(fitxer_gif);
         }
   }

  void iniciarConversioImatges()
   {
       imatge* n;
       char* fitxer_gif;
       char* ruta_fitxer_gif;

       while(limatges.primer->seg!=limatges.primer)
         {
                 limatges.consultarCap(n);
                 fitxer_gif = canviarExtensioGrafica(n->fitxer);
                 ruta_fitxer_gif = new char[strlen(carpeta) + strlen(fitxer_gif) + 2];
                 strcpy(ruta_fitxer_gif, carpeta);
                 strcat(ruta_fitxer_gif, "/");
                 strcat(ruta_fitxer_gif, fitxer_gif);
                 psToGif(n->fitxer, ruta_fitxer_gif, 72); // La ressolució estàndar es 72ppi
                 free(ruta_fitxer_gif); free(fitxer_gif);
                 limatges.eliminarCap();
         }
   }
};

#endif /*_CONVERSORGRAFIC_H*/




