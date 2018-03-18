#ifndef _FOOTNOTES_H
#define _FOOTNOTES_H

#include "operacions.h"
#include "llista.h"
#include <iostream.h>
#include <string.h>

template <class T> class Llista;

class nota{
 public:
  char* nota_al_peu;
  char* etiqueta_font;
  char* etiqueta_nota;
  int num;
 nota() {};
 ~nota() 
  {
     delete nota_al_peu;
     delete etiqueta_font;
     delete etiqueta_nota;
  };
};

class footnotes
{ 
  Llista<nota*> lnotes;
  Llista<nota*> lgracies;
  int compt;
  int compt2;
public:

  footnotes() {compt=0;};
  ~footnotes() {};
  char* obtenirEtiquetaFont(bool nota)
   {
       char* aux;
       aux = new char[15]; 
       if(nota) sprintf(aux,"NPPF%d",compt);
       else sprintf(aux,"GPPF%d",compt2);
       return aux;
   };
  char* obtenirEtiquetaNota(bool nota)
   {
       char* aux;
       aux = new char[15]; 
       if(nota) sprintf(aux,"NPPN%d",compt);
       else sprintf(aux,"GPPN%d",compt2);
       return aux;
   };

  void guardarNota(char* nota_al_peu, char*& num, char*& etiqueta_font, char*& etiqueta_nota)
   {
       nota* aux = new nota;
       compt++;
       num = intToAsc(compt, true);
       aux->nota_al_peu = nota_al_peu;
       aux->num = compt;
       aux->etiqueta_font = obtenirEtiquetaFont(true);
       aux->etiqueta_nota = obtenirEtiquetaNota(true);
       etiqueta_font = obtenirEtiquetaFont(true);
       etiqueta_nota = obtenirEtiquetaNota(true);
       lnotes.inserirFi(aux);
   };

  void guardarGracies(char* nota_al_peu, char*& num, char*& etiqueta_font, char*& etiqueta_nota)
   {
       nota* aux = new nota;
       compt2++;
       num = intToAsc(compt2, false);
       aux->nota_al_peu = nota_al_peu;
       aux->num = compt2;
       aux->etiqueta_font = obtenirEtiquetaFont(false);
       aux->etiqueta_nota = obtenirEtiquetaNota(false);
       etiqueta_font = obtenirEtiquetaFont(false);
       etiqueta_nota = obtenirEtiquetaNota(false);
       lgracies.inserirFi(aux);
   };

  void buidar()
   {
       lnotes.buidar();
       lgracies.buidar();
       compt2=0;
   }

  char* intToAsc(int numero, bool nota)
   {
       char* num = new char[20];
       
       if(nota) {sprintf(num, "%d", numero);}
       else 
        {
            switch(numero)
              {
                  case 1: sprintf(num, "*"); break;
                  case 2: sprintf(num, "&#8224;"); break;
                  case 3: sprintf(num, "&#8225;"); break;
                  case 4: sprintf(num, "&#167;"); break;
                  case 5: sprintf(num, "&#182;"); break;
                  case 6: sprintf(num, "||"); break;
                  case 7: sprintf(num, "**"); break;
                  case 8: sprintf(num, "&#8224;&#8224;"); break;
                  case 9: sprintf(num, "&#8225;&#8225;"); break;
                  default: sprintf(num, " ");
              }
        }
       return num;
   }

  char* crearPeuPagina()
   {
       char* aux = igual("");
       char* aux2;
       char* aux3;
       bool llista_agraiments_buida;
       bool llista_notes_buida;
       nota* n;

       lgracies.esBuida(llista_agraiments_buida);
       lnotes.esBuida(llista_notes_buida);
       if (!llista_agraiments_buida)
        {
            while(lgracies.primer->seg!=lgracies.primer)
             {
                 lgracies.consultarCap(n);
                 aux2 = aux;
                 aux = concatenar(aux,"\n&nbsp;&nbsp;<A NAME=", n->etiqueta_nota, " HREF=#", n->etiqueta_font);
                 delete aux2; aux2 = aux; aux3 = intToAsc(n->num, false);
                 aux = concatenar(aux, "><SUP>", aux3, "</SUP></A>", n->nota_al_peu);
                 delete aux2; aux2 = aux; delete aux3;
                 aux = concatenar(aux, "<BR>","","","");
                 delete aux2;
                 lgracies.eliminarCap();
             }
        }

       if (!llista_notes_buida)
        {
            while(lnotes.primer->seg!=lnotes.primer)
             {
                 lnotes.consultarCap(n);
                 aux2 = aux;
                 aux = concatenar(aux,"\n&nbsp;&nbsp;<A NAME=", n->etiqueta_nota, " HREF=#", n->etiqueta_font);
                 delete aux2; aux2 = aux; aux3 = intToAsc(n->num, true);
                 aux = concatenar(aux, "><SUP>", aux3, "</SUP></A>", n->nota_al_peu);
                 delete aux2; aux2 = aux; delete aux3;
                 aux = concatenar(aux, "<BR>","","","");
                 delete aux2;
                 lnotes.eliminarCap();
             }
        }

       if ((!llista_notes_buida) || (!llista_agraiments_buida))
        {
            aux2 = aux;
            aux = concatenar("\n<P><HR align=left width=175 size=1>\n<SMALL>", aux, "\n</SMALL>\n</P>\n","","");
            delete aux2;
            compt2=0;
            lgracies.buidar();
            lnotes.buidar();
        }

      return aux;
   }
};

#endif /*_FOOTNOTES_H*/



