/***** Classe GLOBOTEX *****/
#ifndef _GLOBOTEX_H
#define _GLOBOTEX_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include "estructures/operacions.h"
#include "estructures/aseccions.h"
#include "estructures/footnotes.h"
#include "estructures/pilaentorns.h"
#include "estructures/crossref.h"
#include "estructures/conversorGrafic.h"
#include "sintaxis.tab.c"
#include "lex.yy.c"

using namespace std;

class GloboTex : public AnalitzadorSintactic
{
 private:
 MyScanner lexic;
 FILE* fluxe_entrada;
 char arxiu[30];
 char nom_arxiu_complet[30];
 bool arxiu_carregat;
 bool final;
 bool traduccio_fallida;

 public:
 GloboTex() 
           {
              document = new aseccions;
              notes_al_peu = new footnotes;
              pila = new pilaEntorns;
              ref_creuades = new crossRef;
              conversor = new conversorGrafic;
              compt = new comptador;

              final=false;
              traduccio_fallida=false;
              restaurarConfiguracio();
              carregarConfiguracio();
              arxiu_carregat=false;
           };
 ~GloboTex() {if(arxiu_carregat) {fclose(fluxe_entrada); delete(carpeta);}};
 virtual int yylex() 
                    {  
                        int token = lexic.yylex();             // Obté l'id. del següent Token
                        yylval.valor = (char*)malloc(strlen(lexic.yytext)+1);
                        sprintf(yylval.valor,"%s",lexic.yytext);
                        return token;
                    };

 virtual void yyerror(char *missatge) 
   { 
     if(strcmp(missatge, "parse error")==0) {cout << "Error-> " << "linia " << lexic.num_linia << ": Error de sintaxi. Revisa l'estructura del document\n";}
     else {cout << "Error-> " << "linia " << lexic.num_linia << ": " << missatge << "\n";}
     traduccio_fallida=true;
   };

 void inicialitzarValors()
  {
    tm* data_actual;
    time_t rellotge=time(&rellotge);

    lexic.num_linia=1;
    lexic.car=0;
    document->assignarCarpeta(carpeta);
    conversor->assignarCarpeta(carpeta);
    document->ocultarPanell = conf.panell;
    document->ocultarBarra = conf.barra;
    document->ocultarMenu = conf.menu;
    document->tamanyMenu = conf.tmenu;
    document->panell_textual = conf.tpanell;
    strcpy(document->titol, conf.titol);
    strcpy(document->colorf, conf.colorf);
    strcpy(document->colorl, conf.colorl);
    strcpy(document->colorv, conf.colorv);
    strcpy(document->colora, conf.colora);
    strcpy(document->css, conf.css);

    equacio_en_curs = igual("");
    taula_en_curs = igual("");
    figura_en_curs = igual("");
    cos_en_curs = igual("");
    titol_en_curs = igual("");
    titol_document = igual("");
    autors_document = igual("");
       
    data_actual = localtime(&rellotge);    
    data_document = new char[60];
    sprintf(data_document, "<H4 align=center>%3d %.16s %d</H4>\n", data_actual->tm_mday,mesos[data_actual->tm_mon],1900 + data_actual->tm_year);
  }

 void copiarIcones()
  {
         char ruta_mes_fitxer[100];
         strcpy(ruta_mes_fitxer,conf.path); strcat(ruta_mes_fitxer, "last.gif");
         if(!fitxerExisteix(ruta_mes_fitxer)) {cout << "Avís-> No s'ha trobat l'icona "<<ruta_mes_fitxer<<". Revisa la configuració.\n";}
         else {cout << "["<<carpeta<<"/"<<"last.gif"<<"]\n"; copiarFitxer(carpeta, ruta_mes_fitxer);}

         strcpy(ruta_mes_fitxer,conf.path); strcat(ruta_mes_fitxer, "first.gif");
         if(!fitxerExisteix(ruta_mes_fitxer)) {cout << "Avís-> No s'ha trobat l'icona "<<ruta_mes_fitxer<<". Revisa la configuració.\n";}
         else {cout << "["<<carpeta<<"/"<<"first.gif"<<"]\n"; copiarFitxer(carpeta, ruta_mes_fitxer);}

         strcpy(ruta_mes_fitxer,conf.path); strcat(ruta_mes_fitxer, "left.gif");
         if(!fitxerExisteix(ruta_mes_fitxer)) {cout << "Avís-> No s'ha trobat l'icona "<<ruta_mes_fitxer<<". Revisa la configuració.\n";}
         else {cout << "["<<carpeta<<"/"<<"left.gif"<<"]\n"; copiarFitxer(carpeta, ruta_mes_fitxer);}

         strcpy(ruta_mes_fitxer,conf.path); strcat(ruta_mes_fitxer, "up.gif");
         if(!fitxerExisteix(ruta_mes_fitxer)) {cout << "Avís-> No s'ha trobat l'icona "<<ruta_mes_fitxer<<". Revisa la configuració.\n";}
         else {cout << "["<<carpeta<<"/"<<"up.gif"<<"]\n"; copiarFitxer(carpeta, ruta_mes_fitxer);}

         strcpy(ruta_mes_fitxer,conf.path); strcat(ruta_mes_fitxer, "right.gif");
         if(!fitxerExisteix(ruta_mes_fitxer)) {cout << "Avís-> No s'ha trobat l'icona "<<ruta_mes_fitxer<<". Revisa la configuració.\n";}
         else {cout << "["<<carpeta<<"/"<<"right.gif"<<"]\n"; copiarFitxer(carpeta, ruta_mes_fitxer);}

         strcpy(ruta_mes_fitxer,conf.path); strcat(ruta_mes_fitxer, "d_first.gif");
         if(!fitxerExisteix(ruta_mes_fitxer)) {cout << "Avís-> No s'ha trobat l'icona "<<ruta_mes_fitxer<<". Revisa la configuració.\n";}
         else {cout << "["<<carpeta<<"/"<<"d_first.gif"<<"]\n"; copiarFitxer(carpeta, ruta_mes_fitxer);}

         strcpy(ruta_mes_fitxer,conf.path); strcat(ruta_mes_fitxer, "d_last.gif");
         if(!fitxerExisteix(ruta_mes_fitxer)) {cout << "Avís-> No s'ha trobat l'icona "<<ruta_mes_fitxer<<". Revisa la configuració.\n";}
         else {cout << "["<<carpeta<<"/"<<"d_last.gif"<<"]\n"; copiarFitxer(carpeta, ruta_mes_fitxer);}

         strcpy(ruta_mes_fitxer,conf.path); strcat(ruta_mes_fitxer, "d_left.gif");
         if(!fitxerExisteix(ruta_mes_fitxer)) {cout << "Avís-> No s'ha trobat l'icona "<<ruta_mes_fitxer<<". Revisa la configuració.\n";}
         else {cout << "["<<carpeta<<"/"<<"d_left.gif"<<"]\n"; copiarFitxer(carpeta, ruta_mes_fitxer);}

         strcpy(ruta_mes_fitxer,conf.path); strcat(ruta_mes_fitxer, "d_up.gif");
         if(!fitxerExisteix(ruta_mes_fitxer)) {cout << "Avís-> No s'ha trobat l'icona "<<ruta_mes_fitxer<<". Revisa la configuració.\n";}
         else {cout << "["<<carpeta<<"/"<<"d_up.gif"<<"]\n"; copiarFitxer(carpeta, ruta_mes_fitxer);}

         strcpy(ruta_mes_fitxer,conf.path); strcat(ruta_mes_fitxer, "d_right.gif");
         if(!fitxerExisteix(ruta_mes_fitxer)) {cout << "Avís-> No s'ha trobat l'icona "<<ruta_mes_fitxer<<". Revisa la configuració.\n";}
         else {cout << "["<<carpeta<<"/"<<"d_right.gif"<<"]\n"; copiarFitxer(carpeta, ruta_mes_fitxer);}
  }

 void carregarFitxer(char* fitxer)
  {
     
   if(final) {cout << "Només es pot realitzar una única traducció\n";}
   else
    {
      fluxe_entrada = fopen(fitxer, "r");
      if(fluxe_entrada==NULL) {cout << "Error-> No s'ha pogut obrir el fitxer " << fitxer << "\n";}
      else 
       {
           strcpy(arxiu, fitxer);
           strcpy(nom_arxiu_complet, fitxer);
           carpeta = obtenirNomArxiu();

           lexic.yyin=fluxe_entrada;
           arxiu_carregat=true;
       }
     }
  }

char* obtenirNomArxiu()
 {
     int e=0;
     char* aux = new char[strlen(arxiu) + 1];
     
     while((arxiu[e]!='.')&&(arxiu[e]!='\0'))
      {
         aux[e] = arxiu[e];
         e++;
      }
     arxiu[e]='\0';
     return aux;
 }

 void Iniciar() 
  {

     if(final) {cout << "Només es pot realitzar una única traducció\n";}
     else if(!arxiu_carregat) {cout << "Has de carregar un fitxer vàlid\n";}
     else 
      {
         inicialitzarValors();
         yyparse();                                // Comença el procés de traducció...

         if(!traduccio_fallida)
          {
              mkdir(carpeta,0750);
              cout << "\nCreant fitxers HTML...\n";
              document->crearWeb(ref_creuades);
              if((conf.panell==false)&&(conf.tpanell==false))
               {
                   cout << "\nCopiant icones...\n";
                   copiarIcones();
               }
              cout << "\nCreant fitxers GIF...\n";
              conversor->iniciarConversio();
          }

         delete document;
         delete notes_al_peu;
         delete pila;
         delete ref_creuades;
         delete conversor;
         delete compt;
 
         delete equacio_en_curs;
         delete taula_en_curs;
         delete figura_en_curs;
         delete cos_en_curs;
         delete titol_en_curs;
         delete titol_document;
         delete autors_document;
         delete data_document;
         final=true;
         fclose(fluxe_entrada);
      }
  }

 void restaurarConfiguracio()
  {
     strcpy(conf.titol, "");     
     strcpy(conf.colorf, "");
     strcpy(conf.colorl, "");
     strcpy(conf.colorv, "");
     strcpy(conf.colora, "");
     strcpy(conf.css, "");
     conf.refc=false;
     conf.nopart=false;
     conf.nocapitol=false;
     conf.nosec=false;
     conf.nosubsec=false;
     conf.nosubsubsec=false;
     conf.panell=false;
     conf.tpanell=false;
     conf.menu=false;
     conf.tmenu=35;
     conf.barra=true;
     strcpy(conf.path, "./");
  }

 void guardarConfiguracio()
  {
     FILE* fconf;
     char resposta;

     cout << "Vols guardar la configuració? (s/n)";
     resposta = getchar();
     resposta = toupper(resposta);
     if(resposta=='S')
      {
          fconf = fopen("globo.cfg", "w");
          fwrite(&conf,1,sizeof(conf), fconf);
          fclose(fconf);
      }
  } 

 void carregarConfiguracio()
  {
     FILE* fconf;

     fconf = fopen("globo.cfg", "r");
     if(fconf==NULL) 
      {
          fconf = fopen("globo.cfg", "w");
          fwrite(&conf,1,sizeof(conf), fconf);
          fclose(fconf);
      }
     else
      {
          fread(&conf,1,sizeof(configuracio),fconf);
          fclose(fconf);
      }
  }

 void mostrarPanellConfiguracio()
  {
    cout<<"\n Configuració\n\n";
    cout<<" [Comanda]     [Descripció]                          [Configuració actual]\n\n";
    cout<<" titol         Títol del document                   "<<conf.titol<<"\n";
    cout<<" colorf        Color de fons del document           "<<conf.colorf<<"\n";
    cout<<" colorl        Color dels enllaços                  "<<conf.colorl<<"\n";
    cout<<" colorv        Color dels enllaços visitats         "<<conf.colorv<<"\n";
    cout<<" colora        Color dels enllaços actius           "<<conf.colora<<"\n";
    cout<<" css           Fitxer de la fulla d'estils          "<<conf.css<<"\n";
    cout<<" refc          Tipus de referències creuades        "<<conf.refc<<"\n";
    cout<<" nopart        Les parts no s'estructuren           "<<conf.nopart<<"\n";
    cout<<" nocapitol     Els capítols no s'estructuren        "<<conf.nocapitol<<"\n";
    cout<<" nosec         Les seccions no s'estructuren        "<<conf.nosec<<"\n";
    cout<<" nosubsec      Les subseccions no s'estructuren     "<<conf.nosubsec<<"\n";
    cout<<" nosubsubsec   Les subsubseccions no s'estructuren  "<<conf.nosubsubsec<<"\n";
    cout<<" panell        Oculta el panell de navegació        "<<conf.panell<<"\n";
    cout<<" tpanell       Tipus de panell de navegació         "<<conf.tpanell<<"\n";
    cout<<" menu          Oculta el menú a l'esquerra          "<<conf.menu<<"\n";
    cout<<" tmenu         Tamany del menú a l'esquerra         "<<conf.tmenu<<"\n";
    cout<<" barra         Oculta la barra central              "<<conf.barra<<"\n";
    cout<<" path          Directori de les icones              "<<conf.path<<"\n\n"; 
    cout<<" ls            Mostra novament aquesta llista\n";
    cout<<" sortir        Sortir de la configuració\n\n";
    cout<<"Escriu la comanda seguida d'un espai i la nova configuració\n";
    cout<<"*Consulta la documentació per a més informació\n";
  }

 void obtenirOperands(char operacio[], char comanda[], char nova_conf[])
  {
    int e=0;
    int i=0;

    while((operacio[e]!=' ')&&(operacio[e]!='\0'))
     {
        comanda[e] = operacio[e];
        e++;
     }
    comanda[e]='\0';
    if(operacio[e]==' ') {e++;}
    while(operacio[e]!='\0')
     {
        if(operacio[e]!='\n'){nova_conf[i] = operacio[e]; i++;}
        e++;
     }
    nova_conf[i]='\0';
  }
 
 void obtenirCadena(char operacio[])
  {
     char c = '\0';
     int e = 0;
     strcpy(operacio,"");
     while((c = getchar())!='\n')
      {         
         operacio[e] = c;
         e++;
      }
     operacio[e]='\0';
  }

 void configurar()
  {
    char operacio[200];
    char comanda[9];
    char nova_conf[180];
    char c;

    restaurarConfiguracio();
    carregarConfiguracio();
    mostrarPanellConfiguracio();
    while(strcmp(operacio, "sortir")!=0)
     {
        cout << ": ";
        obtenirCadena(operacio);
        obtenirOperands(operacio, comanda, nova_conf);

        if(strcmp(comanda,"ls")==0)            {mostrarPanellConfiguracio();}
        else if(strcmp(comanda,"sortir")==0)   {guardarConfiguracio();}
        else if(strcmp(comanda,"titol")==0)    {strcpy(conf.titol, nova_conf);}
        else if(strcmp(comanda,"colorf")==0)   {strcpy(conf.colorf, nova_conf);}
        else if(strcmp(comanda,"colorl")==0)   {strcpy(conf.colorl, nova_conf);}
        else if(strcmp(comanda,"colorv")==0)   {strcpy(conf.colorv, nova_conf); }
        else if(strcmp(comanda,"colora")==0)   {strcpy(conf.colora, nova_conf); }
        else if(strcmp(comanda,"css")==0)      {strcpy(conf.css, nova_conf); }
        else if(strcmp(comanda,"refc")==0)     {if(strcmp(nova_conf,"0")==0) {conf.refc = false;}
                                                else {conf.refc = true;}}

        else if(strcmp(comanda,"nopart")==0)   {if(strcmp(nova_conf,"0")==0) {conf.nopart = false;}
                                                else {conf.nopart = true;}}
        else if(strcmp(comanda,"nocapitol")==0){if(strcmp(nova_conf,"0")==0) {conf.nocapitol = false;}
                                                else {conf.nocapitol = true;}}
        else if(strcmp(comanda,"nosec")==0)    {if(strcmp(nova_conf,"0")==0) {conf.nosec = false;}
                                                else {conf.nosec = true;}}
        else if(strcmp(comanda,"nosubsec")==0) {if(strcmp(nova_conf,"0")==0) {conf.nosubsec = false;}
                                                else {conf.nosubsec = true;}}
        else if(strcmp(comanda,"nosubsubsec")==0){if(strcmp(nova_conf,"0")==0) {conf.nosubsubsec = false;}
                                                else {conf.nosubsubsec = true;}}
        else if(strcmp(comanda,"panell")==0)   {if(strcmp(nova_conf,"0")==0) {conf.panell = false;}
                                                else {conf.panell = true;}}
        else if(strcmp(comanda,"tpanell")==0)  {if(strcmp(nova_conf,"0")==0) {conf.tpanell = false;}
                                                else {conf.tpanell = true;}}
        else if(strcmp(comanda,"menu")==0)     {if(strcmp(nova_conf,"0")==0) {conf.menu = false;}
                                                else {conf.menu = true;}}
        else if(strcmp(comanda,"tmenu")==0)    {conf.tmenu=atoi(nova_conf);}
        else if(strcmp(comanda,"barra")==0)    {if(strcmp(nova_conf,"0")==0) {conf.barra = false;}
                                                else {conf.barra = true;}}
        else if(strcmp(comanda,"path")==0)   
          {
             if((strlen(nova_conf)!=0)&&(nova_conf[strlen(nova_conf)-1]!='/')) {strcat(nova_conf,"/");}
             strcpy(conf.path, nova_conf);
          }
        else {cout << "Comanda incorrecta. Escriu 'ls' per veure la llista de comandes.\n";}
     }
  }

 void mostrarTitol() 
    {cout << "globoTeX/Linux v1.0   [La]TeX -> HTML\n\n";}
};

#endif










