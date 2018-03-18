/***** Classe ASECCIONS *****/
#ifndef _ASECCIONS_H
#define _ASECCIONS_H
#include<stdio.h>
#include<iostream>
#include "operacions.h"
#include "llista.h"
#include "seccio.h"
#include "comptador.h"
#include "crossref.h"

using namespace std;

class aseccions
{

public:
seccio* secArrel;
seccio* secActual;
comptador CompActual;
char* taulaContinguts;
char* llistaDeFigures;
char* llistaDeTaules;
int compNodes, nivellMesPetitInserit;
char* carpeta;
int tamanyMenu;
bool ocultarPanell;
bool ocultarBarra;
bool ocultarMenu;
bool panell_textual;
char titol[150];
char colorf[10];
char colorl[10];
char colorv[10];
char colora[10];
char css[50];

  friend class seccio;
  friend class comptador;

  aseccions() {inicialitzarValors();}

  ~aseccions() 
   {
     delete secArrel;
     delete llistaDeTaules;
     delete llistaDeFigures;
     delete taulaContinguts;
     delete carpeta;
   }

  void inicialitzarValors()
   {
      ocultarPanell=false;
      ocultarBarra=false;
      ocultarMenu=false;
      panell_textual=false;
      tamanyMenu=35;
      strcpy(titol,"");
      strcpy(colorf,"");
      strcpy(colorl,"");
      strcpy(colorv,"");
      strcpy(colora,"");
      strcpy(css,"");
      compNodes = 0;
      nivellMesPetitInserit = 4;
      llistaDeFigures = igual("<P>");
      llistaDeTaules = igual("<P>");
      taulaContinguts = igual("<UL>");
      secArrel = new seccio;
      secArrel->seccio_seguent = secArrel;
      secArrel->seccio_anterior = secArrel;
      secArrel->seccio_superior = secArrel;
      secActual=secArrel;
   }

  char* assignarFitxer()
   {
     char fitxer[50];
     char* aux;
     int l = sprintf(fitxer, "node%d.html", compNodes);
     aux = new char[l+1];
     strcpy(aux, fitxer);
     return aux;
   } 

  char* assignarTitol(char* titol)
   {
     char* aux;
     aux = new char[strlen(titol)+1];
     strcpy(aux, titol);
     return aux;
   } 

  char* assignarCos(char* cos)
   {
     char* aux;
     aux = new char[strlen(cos)+1];
     strcpy(aux, cos);
     return aux;
   } 

  void novaSeccio(int tipus, char* titol, char* cos)
   {
     seccio* aux;
     int n;

     aux = new seccio;    
     secActual->seccio_seguent = aux;
     aux->seccio_anterior=secActual;
     aux->seccio_seguent=secArrel;

     compNodes++;
     switch(tipus)
      {
         case 0: CompActual.novaPart(); break;
         case 1: CompActual.nouCapitol(); break;
         case 2: CompActual.novaSeccio(); break;
         case 3: CompActual.novaSubseccio(); break;
         case 4: CompActual.novaSubsubseccio(); break;
      }

     aux->fitxer=assignarFitxer();
     aux->titol=assignarTitol(titol);
     aux->inserirComptador(&(CompActual));
     aux->cos=assignarCos(cos);

     secArrel->inserirSeccio(aux); //insereixo la secció a l'arbre
     secActual=aux;

     n = secActual->consultarNivell();
     if(n < nivellMesPetitInserit) nivellMesPetitInserit =  n;
   }

  char* crearMarquesTancament(int numero)
   {
      char* aux;
      aux = new char[(strlen("</UL>\n") * numero) + 1];
      strcpy(aux,"");
      for(int i=0; i<numero; i++) {strcat(aux, "</UL>\n");}

      return aux;
   }

  char* crearMarquesObertura(int numero)
   {
      char* aux;
      aux = new char[(strlen("<UL>\n") * numero) + 1];
      strcpy(aux,"");
      for(int i=0; i<numero; i++) {strcat(aux, "<UL>\n");}

      return aux;
   }

  void crearTaulaContinguts()
   {

      seccio* a;
      int n[5], dist, pos=1;
      char* contingut;
      char* marques_tancament;
      char* marques_obertura;
      char* aux;
      bool final;
      int dif1=0;
      int dif2=0;
      int e=0; 
      int anterior,nivell;

      n[0]=nivellMesPetitInserit;
      a=secArrel->seccio_seguent;
      
      while(a!=secArrel)
        {
           final = false;
           e=0;
           dif1=0;
           dif2=0;
           anterior = n[e];
           nivell = a->consultarNivell();

           while(!final)
            {
                 if(e==pos)
                  {
                       if ((nivell-anterior)!=0) dif2=1;
                       while(((nivell-anterior)!=1)&&((nivell-anterior)!=0))
                        {
                           anterior++;
                           n[e]=anterior;
                           e++;
                           dif2++;
                        }
                       n[e]=nivell;
                       dif1=0;
                       pos=e+1;
                       final=true;
                  }
                 else if(n[e]>=nivell) 
                  {
                       n[e]=nivell;
                       e++;
                       dif1 = pos-e;
                       pos=e;
                       final=true;
                  }
                else 
                  {
                       anterior=n[e];
                       e++;
                  }
            }

           marques_tancament = crearMarquesTancament(dif1);
           marques_obertura = crearMarquesObertura(dif2);
           contingut = new char[strlen(a->titol) + strlen(a->fitxer) + strlen(marques_tancament) + strlen(marques_obertura) + strlen(a->nom) + 47];
  
           if (dif1==0) sprintf(contingut, "%s<LI><A HREF=%s#%s target=principal>%s</A>\n", marques_obertura, a->fitxer, a->nom, a->titol);
           else sprintf(contingut, "%s<LI><A HREF=%s#%s target=principal>%s</A>\n", marques_tancament, a->fitxer, a->nom, a->titol);

           aux = new char[strlen(contingut) + strlen(taulaContinguts) + 1];
           sprintf(aux, "%s%s", taulaContinguts, contingut);

           delete marques_tancament;
           delete marques_obertura;
           delete contingut;
           delete taulaContinguts;
 
           taulaContinguts = aux;

           a=a->seccio_seguent;
        }



        marques_tancament = crearMarquesTancament(pos);
      
        aux = new char[strlen(marques_tancament) + strlen(taulaContinguts) + 1];
        sprintf(aux, "%s%s", taulaContinguts, marques_tancament);
  
        delete marques_tancament;
        delete taulaContinguts;
  
        taulaContinguts = aux;     

   }

char* crearLinkCss()
 {
    char* aux;
    if(strcmp(css,"")==0) {aux=igual("");}
    else{aux=concatenar("<link rel=stylesheet href=", css, " type=text/css>\n","","");}

    return aux;
 }

char* crearCapcalera()
 {
    char* fulla_estils=crearLinkCss();
    char* aux = concatenar("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0 Transitional//EN\"\n\"http://www.w3.org/TR/REC-html40/loose.dtd\">\n<HTML>\n<meta name=\"GENERATOR\" content=\"globoTeX v1.0\">\n<HEAD>\n",fulla_estils,"<TITLE>", titol, "</TITLE>\n</HEAD>\n");
    free(fulla_estils);
    return aux;
 }

char* crearIniciBody()
 {
    char* body = igual("\n<BODY");
    char* aux = body;

    if(strcmp(colorf,"")!=0) {body=concatenar(body, " BGCOLOR=",colorf,"",""); free(aux); aux=body;}
    if(strcmp(colorl,"")!=0) {body=concatenar(body, " LINK=",colorl,"",""); free(aux); aux=body;}
    if(strcmp(colorv,"")!=0) {body=concatenar(body, " VLINK=",colorv,"",""); free(aux); aux=body;}
    if(strcmp(colora,"")!=0) {body=concatenar(body, " ALINK=",colora,"",""); free(aux); aux=body;}

    body=concatenar(body,">\n","","",""); free(aux);
    return body;
 }

void crearFitxer(char* nom_fitxer, char* codi_html)
 {
    FILE* fitxer;
    char* ruta = new char[strlen(nom_fitxer) + strlen(carpeta) + 2];
    char* aux;
    char* cap = crearCapcalera();
    char* body = crearIniciBody();

    aux=concatenar(cap, body ,codi_html, "\n</BODY>\n</HTML>","");
    free(cap); free(body);
    strcpy(ruta, carpeta);
    strcat(ruta, "/");
    strcat(ruta, nom_fitxer);

    fitxer = fopen(ruta, "wt");
    if (fitxer!=NULL)
     {
       fputs(aux, fitxer);
       fclose(fitxer);
       cout << "["<<carpeta<<"/"<<nom_fitxer<<"]\n";
     }
    else {cout << "Error-> No s'ha pogut crear " << nom_fitxer << "\n";}
    free(ruta); free(aux);
 }

void crearFitxerTaulaContinguts()
 {
    free(taulaContinguts);
    taulaContinguts = igual("<UL>\n");
    crearTaulaContinguts();
    crearFitxer("continguts.html", taulaContinguts);
 }

void crearFitxerFrames()
 {
    FILE* fitxer;
    char* ruta = new char[strlen("/index.html") + strlen(carpeta) + 1];
    strcpy(ruta, carpeta);
    strcat(ruta, "/index.html");
    char* t_menu = intToAsc(tamanyMenu);
    char* cap = crearCapcalera();

    fitxer = fopen(ruta, "wt");
    if (fitxer!=NULL)
     {
       fputs("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0 Transitional//EN\"\n\"http://www.w3.org/TR/REC-html40/loose.dtd\">\n<HTML>\n<meta name=\"GENERATOR\" content=\"globoTeX v1.0\">\n", fitxer);
       fputs(cap, fitxer);
       fputs("<frameset ", fitxer);

       if(ocultarMenu==false)
        {
            if(ocultarBarra) {fputs("frameborder=0", fitxer);}
            fputs(" cols=", fitxer);
            fputs(t_menu, fitxer);
            fputs("%,*>\n  <frame name=continguts target=principal src=continguts.html scrolling=auto>\n",fitxer);
        }
       else {fputs(" cols=100%>\n",fitxer);}

       fputs("  <frame name=principal src=node1.html scrolling=", fitxer);
       fputs("auto", fitxer);
       fputs(" marginwidth=", fitxer);
       fputs("5", fitxer);
       fputs(" marginheight=", fitxer);
       fputs("5", fitxer);

       fputs(">\n  <noframes>\n  <body>\n  <p>Aquesta pàgina usa frames, però el teu navegador no els suporta.</p>\n", fitxer);
       fputs("  </body>\n  </noframes>\n</frameset>\n</HTML>", fitxer);
       fclose(fitxer);
       cout << "["<< carpeta<<"/"<<"index.html]\n";
     }
    else {cout << "Error-> No s'ha pogut crear index.html\n";}
    free(t_menu); free(cap); free(ruta);
 }

char* crearPanellNavegacio(seccio* s)
 {
    char* panell;
    char* aux;
    char* ult;
    char* pri;
    char* esq;
    char* sup;
    char* dre;

    if(panell_textual)
     {
       pri = igual("Primer&nbsp;|&nbsp;");
       esq = igual("Anterior&nbsp;|&nbsp;");
       sup = igual("Superior&nbsp;|&nbsp;");
       dre = igual("Següent&nbsp;|&nbsp;");
       ult = igual("Últim");

       if(s!=secArrel->seccio_seguent)  {free(pri); pri = concatenar("<a href=", secArrel->seccio_seguent->fitxer, ">Primer</a>&nbsp;|&nbsp;\n","","");}
       if(s->seccio_anterior!=secArrel) {free(esq); esq = concatenar("<a href=", s->seccio_anterior->fitxer, ">Anterior</a>&nbsp;|&nbsp;\n","","");}
       if(s->seccio_superior!=secArrel) {free(sup); sup = concatenar("<a href=", s->seccio_superior->fitxer, ">Superior</a>&nbsp;|&nbsp;\n","","");}
       if(s->seccio_seguent!=secArrel)  {free(dre); dre = concatenar("<a href=", s->seccio_seguent->fitxer, ">Següent</a>&nbsp;|&nbsp;\n","","");}
       if(s!=secArrel->seccio_anterior) {free(ult); ult = concatenar("<a href=", secArrel->seccio_anterior->fitxer, ">Últim</a>\n","","");}

       panell = concatenar("\n\n<!-- panell de navegació -->\n<p align=center><BIG>", pri, esq, sup, dre);
       aux = panell;
       panell = concatenar(panell,ult,"</BIG></p>\n<!-- fi panell de navegació -->\n\n","","");
     }
    else
     {
       pri = igual("<img src=d_first.gif border=0>&nbsp;\n");
       esq = igual("<img src=d_left.gif border=0>&nbsp;\n");
       sup = igual("<img src=d_up.gif border=0>&nbsp;\n");
       dre = igual("<img src=d_right.gif border=0>&nbsp;\n");
       ult = igual("<img src=d_last.gif border=0>&nbsp;\n");

       if(s!=secArrel->seccio_seguent)  {free(pri); pri = concatenar("<a href=", secArrel->seccio_seguent->fitxer, "><img src=first.gif alt=\"",secArrel->seccio_seguent->titol,"\" border=0></a>&nbsp;\n");}
       if(s->seccio_anterior!=secArrel) {free(esq); esq = concatenar("<a href=", s->seccio_anterior->fitxer, "><img src=left.gif alt=\"",s->seccio_anterior->titol,"\" border=0></a>&nbsp;\n");}
       if(s->seccio_superior!=secArrel) {free(sup); sup = concatenar("<a href=", s->seccio_superior->fitxer, "><img src=up.gif alt=\"",s->seccio_superior->titol,"\" border=0></a>&nbsp;\n");}
       if(s->seccio_seguent!=secArrel)  {free(dre); dre = concatenar("<a href=", s->seccio_seguent->fitxer, "><img src=right.gif alt=\"",s->seccio_seguent->titol,"\" border=0></a>&nbsp;\n");}
       if(s!=secArrel->seccio_anterior) {free(ult); ult = concatenar("<a href=", secArrel->seccio_anterior->fitxer, "><img src=last.gif alt=\"",secArrel->seccio_anterior->titol,"\" border=0></a>\n");}

       panell = concatenar("\n\n<!-- panell de navegació -->\n<p align=center>", pri, esq, sup, dre);
       aux = panell;
       panell = concatenar(panell,ult,"</p>\n<!-- fi panell de navegació -->\n\n","","");
     }

    free(esq); free(sup); free(dre); free(pri); free(ult); free(aux);
    return panell;
 }

void crearNodes()
 {
    seccio* a;
    char* panell_navegacio;
    char* aux;

    a=secArrel->seccio_seguent;
    while(a!=secArrel)
     {
        if(ocultarPanell) {panell_navegacio=igual("");}
        else {panell_navegacio = crearPanellNavegacio(a);}

        aux = concatenar(panell_navegacio, a->cos, panell_navegacio,"","");
        free(a->cos); free(panell_navegacio);
        a->cos = aux;
        crearFitxer(a->fitxer, a->cos);
        a=a->seccio_seguent;
     }    
 }

void crearWeb(crossRef* etiquetes)
 {
    secArrel->seccio_anterior=secActual;
    crearFitxerFrames();

    if(ocultarMenu)
     {   free(taulaContinguts);
         taulaContinguts = igual("<UL>\n");
         crearTaulaContinguts();
     }else{crearFitxerTaulaContinguts();}

    completarOperacionsPendents(etiquetes);
    crearNodes();
 }

void inserirFigura(char* nom_figura, char* numero, char* caption, char* fitxer)
 {
    char* aux = llistaDeFigures;
    llistaDeFigures = concatenar(llistaDeFigures, "<A HREF=", fitxer, "#", nom_figura);
    free(aux); aux = llistaDeFigures;
    llistaDeFigures = concatenar(llistaDeFigures, ">",numero,"</A>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;",caption);
    free(aux); aux = llistaDeFigures;
    llistaDeFigures = concatenar(llistaDeFigures, "<BR>\n", "","","");
    free(aux);
 }

void inserirTaula(char* nom_taula, char* numero, char* caption, char* fitxer)
 {
    char* aux = llistaDeTaules;
    llistaDeTaules = concatenar(llistaDeTaules, "<A HREF=", fitxer, "#", nom_taula);
    free(aux); aux = llistaDeTaules;
    llistaDeTaules = concatenar(llistaDeTaules, ">",numero,"</A>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;",caption);
    free(aux); aux = llistaDeTaules;
    llistaDeTaules = concatenar(llistaDeTaules, "<BR>\n", "","","");
    free(aux);
 }

void inserirCodiHtml(char*& cadena, const char* codi, int c, int d)
 {
    char* aux = new char[strlen(cadena) + strlen(codi) - (d - c)];
    int e = 0;
    int i = 0;

    while(e<c) {aux[e]=cadena[e]; e++;}
    while(codi[i]!='\0') {aux[e]=codi[i]; i++; e++;}
    i=d+1;
    while(cadena[i]!='\0') {aux[e]=cadena[i]; e++; i++;}
    aux[e]='\0';
    free(cadena);
    cadena = aux;
 }

void completarSeccio(crossRef* etiquetes, char*& codi_seccio)
 {
    int c=0;
    int i=0;
    int e=0;
    char* aux;
    char* aux2;
    char nom[200];
    char* eti;
    char* fitxer;
    char* compt;
    bool noexist=true;

    aux=igual("");
    strcpy(nom,"");
    if(strlen(codi_seccio)>1)
     {
        while(codi_seccio[c+1]!='\0')
         {
             if((codi_seccio[c]=='%') && (codi_seccio[c+1]=='C'))
              {
                 inserirCodiHtml(codi_seccio, taulaContinguts, c, c+1);
              }
             else if((codi_seccio[c]=='%') && (codi_seccio[c+1]=='F'))
              {
                 inserirCodiHtml(codi_seccio, llistaDeFigures, c, c+1);
              }
             else if((codi_seccio[c]=='%') && (codi_seccio[c+1]=='T'))
              {
                 inserirCodiHtml(codi_seccio, llistaDeTaules, c, c+1);
              }
             else if((codi_seccio[c]=='{')&&(codi_seccio[c+1]=='H'))
              {
                   i=c+1;
                   while((codi_seccio[i]!='}')&&(e<199))
                    {
                        nom[e]=codi_seccio[i];
                        i++; e++;
                    }
                   nom[e]='\0';
                   e=0;

                   etiquetes->consultarEtiqueta(nom, eti, fitxer, compt, noexist);
                   free(aux);
                   if(noexist) {cout << "S'ha trobat una referència a una etiqueta inexistent\n";}
                   else
                    {
                        aux=concatenar(fitxer,"#",eti,"","");
                        inserirCodiHtml(codi_seccio, aux, c, i); free(aux);
                    }
                   aux=igual("");
              }
             else if(codi_seccio[c]=='{')
              {
                   i=c+1;
                   while((codi_seccio[i]!='}')&&(e<199))
                    {
                        nom[e]=codi_seccio[i];
                        i++; e++;
                    }
                   nom[e]='\0';
                   e=0;

                   etiquetes->consultarEtiqueta(nom, eti, fitxer, compt, noexist);
                   free(aux);
                   if(noexist) {cout << "S'ha trobat una referència a una etiqueta inexistent\n";}
                   else
                    {
                        aux=concatenar("<A HREF=",fitxer,"#",eti,">");
                        aux2=aux;
                        aux=concatenar(aux, compt, "</A>","",""); free(aux2);
                        inserirCodiHtml(codi_seccio, aux, c, i); free(aux);
                    }
                   aux=igual("");
              }

             c++;             
         }
        free(aux);
     }
 }

void completarOperacionsPendents(crossRef* etiquetes)
 {
    seccio* a;

    a=secArrel->seccio_seguent;
    while(a!=secArrel)
     {
        completarSeccio(etiquetes, a->cos);
        a=a->seccio_seguent;
     }
 }

void assignarCarpeta(char* c)
 {
    carpeta = new char[strlen(c) + 1];
    strcpy(carpeta, c);
 }
};

#endif














