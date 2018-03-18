/***** Classe COMPTADOR *****/
#ifndef _COMPTADOR_H
#define _COMPTADOR_H

#include "operacions.h"
#include<stdio.h>
#include<string.h>

class comptador
{
  int c[5];
  int nivell; //0 part, 1 capítol, 2 secció, 3 subsecció i 4 subsubsecció

public:

  friend class seccio;
  friend class aseccions;
  comptador() { for(int e=0; e<=4; e++) { c[e]=0; }; nivell = 0; }
  comptador(int p, int ca, int s, int ss, int sss) 
   {
      c[0] = p; c[1] = ca; c[2] = s; c[3] = ss; c[4] = sss;
      nivell = DeterminarNivell();
   }
  void novaPart() {c[0]++; c[1]=0; c[2]=0; c[3]=0; c[4]=0; nivell = 0;}
  void nouCapitol() {c[1]++; c[2]=0; c[3]=0; c[4]=0; nivell = 1;}
  void novaSeccio() {c[2]++; c[3]=0; c[4]=0; nivell = 2;}
  void novaSubseccio() {c[3]++; c[4]=0; nivell = 3;}
  void novaSubsubseccio() {c[4]++; nivell = 4;}
  ~comptador() { }
  void operator=(comptador& i) { for(int e=0; e<=4; e++) { c[e]=i.c[e]; }; nivell=i.nivell; }
  bool operator<(comptador& i) 
   {
      int e=0;
      bool mespetit=false;
      bool final=false;
      while ((!mespetit)&&(e<=4)&&(!final))
       {
          if (c[e] < i.c[e]) {mespetit=true;}
          else if (c[e] > i.c[e]) {final=true;}
          e++;
       }
      return mespetit;     
   }
  char* copiar() 
   { 
     char* comp;
     char buffer[50];
     int l = sprintf(buffer, "%d.%d.%d.%d.%d", c[0],c[1],c[2],c[3],c[4]);  
     comp = new char[l+1];
     strcpy(comp, buffer);
     return comp;
   };
  friend ostream& operator<<(ostream& s, comptador& i)
   {
     for(int e=0; e<=3; e++) { cout << i.c[e] << "."; }
     cout << i.c[4];

     return s;
   }
  friend int CompCmp(comptador* c1, comptador* c2)
   {
     // retorna 0 si c1 o c2 correspon a una subsecció de l'altre
     // retorna 1 si c1 correspon a una secció superior a c2 
     // retorna 2 si c2 correspon a una secció superior a c1

     int a;
     if(c1->nivell < c2->nivell) {a = c1->nivell;}
     else {a = c2->nivell;}
   
     for(int e=0; e<=a; e++)
       {
          if(c2->c[e]>c1->c[e]) {return 2;}
          if(c1->c[e]>c2->c[e]) {return 1;}
       }
      return 0;
   }

  int DeterminarNivell()
    {
       int n = 4;
       while((c[n]==0)&&(n>0)) { n--; }
       return n;
    }

  char* obtenirNom()
    {
       char* aux;
       aux = new char[35]; 
       sprintf(aux,"sec%d_%d_%d_%d_%d",c[0],c[1],c[2],c[3],c[4]);
       return aux;
    }

  char* obtenirValorComptador()
    {
       char* aux;
       aux = new char[20]; 
       if(nivell==0)      {sprintf(aux,"Part %d  ",c[0]);}
       else if(nivell==1) {sprintf(aux,"Capítol %d",c[1]);}
       else if(nivell==2) {sprintf(aux,"%d",c[2]);}
       else if(nivell==3) {sprintf(aux,"%d.%d",c[2],c[3]);}
       else {sprintf(aux,"%d.%d.%d",c[2],c[3],c[4]);}
       return aux;
    }
};

#endif



