%{
// Analitzador Sintàctic (gramàtica)
%}

%name AnalitzadorSintactic
%union { char *valor; }
%define LSP_NEEDED
%define ERROR_BODY =0
%define LEX_BODY =0
%define MEMBERS virtual void warning(int){};

%header{
  #include<iostream.h>
  #include<stdlib.h>
  #include<string.h>
  #include "estructures/operacions.h"
  #include "estructures/aseccions.h"
  #include "estructures/footnotes.h"
  #include "estructures/pilaentorns.h"
  #include "estructures/crossref.h"
  #include "estructures/conversorGrafic.h"
  struct configuracio
   {
     char titol[150];
     char colorf[10];
     char colorl[10];
     char colorv[10];
     char colora[10];
     char css[50];
     bool refc;
     bool nopart;
     bool nocapitol;
     bool nosec;
     bool nosubsec;
     bool nosubsubsec;
     bool panell;
     bool tpanell;
     bool menu;
     int tmenu;
     bool barra;
     char path[50];
   };
  enum tipus_classe {article, report, book, letter, slides};
  enum tipus_seccio {part=0, capitol=1, seccio=2, subseccio=3, subsubseccio=4};

  aseccions* document;
  pilaEntorns* pila;
  footnotes* notes_al_peu;
  crossRef* ref_creuades;
  conversorGrafic* conversor;
  configuracio conf;
  char* carpeta;

  int compt_figures=0;
  int compt_taules=0;
  int compt_nodes=1;
  int compt_etiquetes=1;
  int compt_equacions=0;
  int compt_bibliografia=1;
  comptador* compt;

  char* titol_document;
  char* autors_document;
  char* data_document;

  char* nom_en_curs;
  char* cos_en_curs;
  char* titol_en_curs;
  char* taula_en_curs;
  char* figura_en_curs;
  char* equacio_en_curs;

  tipus_seccio tipus_seccio_en_curs = part;
  tipus_classe classe;
  int nivell_enumerat=0;
  bool iniciat = false;

  bool centrat=false;
  bool esquerra=false;
  bool dreta=false;

  bool negreta = false;
  bool emfasi = false;
  bool subratllat = false;
  bool italica = false;
  bool super = false;
  bool mecanografic = false;

  bool flag_italica=false;
  bool flag_negreta=false;
  bool flag_emfasi=false;
  bool flag_mecanografic=false;

  int tab_espais[20]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  int tab_compt=0;
  int espais=0;
  int tab=0;
  bool tabbing_flag=false;

  bool multi_bib=false;
  bool entorn_html=false;
  bool hyperref=false;
  static const char mesos[12][16] = {"de Gener de", "de Febrer de", "de Març de", 
                                     "d'Abril de", "de Maig de", "de Juny de",
                                     "de Juliol de", "d'Agost de", "de Setembre de",
                                     "d'Octubre de", "de Novembre de", "de Desembre de"};

tipus_classe obtenir_classe(char* a, bool* error)
 {
   if (strcmp(a,"article")==0)      return article;
   else if (strcmp(a,"report")==0)  return report;
   else if (strcmp(a,"book")==0)    return book;
   else if (strcmp(a,"letter")==0)  return letter;
   else if (strcmp(a,"slides")==0)  return slides;
   else                             *error = true;
 }

void inserirSeccioEnCurs()
 {
   char* aux = cos_en_curs;
   char* peu_pagina = notes_al_peu->crearPeuPagina();
   cos_en_curs = concatenar(cos_en_curs, peu_pagina,"","","");
   free(aux); free(peu_pagina);

   document->novaSeccio(tipus_seccio_en_curs, titol_en_curs, cos_en_curs);
   compt_nodes++;
 }

void novaSeccio(tipus_seccio tipus, char* titol)
 {
   if (!iniciat) {iniciat = true;}
   else
     {
       inserirSeccioEnCurs();
       cos_en_curs = igual("");
       free(nom_en_curs);
       nom_en_curs = igual("");
     }
   tipus_seccio_en_curs = tipus;
   free(titol_en_curs); titol_en_curs = igual("");
 }

void addTitol(char* fragment_traduit)
 {
   char* aux;
   aux = new char[strlen(titol_en_curs) + strlen(fragment_traduit) + 1];
   strcpy(aux, titol_en_curs);
   strcat(aux,fragment_traduit);
   delete titol_en_curs;
   titol_en_curs = aux;
 }

void addCos(char* fragment_traduit)
 {
   char* aux;
   aux = new char[strlen(cos_en_curs) + strlen(fragment_traduit) + 1];
   strcpy(aux, cos_en_curs);
   strcat(aux,fragment_traduit);
   delete cos_en_curs;
   cos_en_curs = aux;
 }

char* obtenirNomFigura()
 {
    char* aux = new char[10];
    sprintf(aux,"F%d",compt_figures);
    return aux;
 }

char* obtenirNomTaula()
 {
    char* aux = new char[10];
    sprintf(aux,"T%d",compt_taules);
    return aux;
 }

char* obtenirNomEquacio()
 {
    char* aux = new char[10];
    sprintf(aux,"E%d",compt_equacions);
    return aux;
 }

char* assignarFitxer()
 {
    char fitxer[50];
    char* aux;
    int l = sprintf(fitxer, "node%d.html", compt_nodes);
    aux = new char[l+1];
    strcpy(aux, fitxer);
    return aux;
 } 
%}

/*** Declaració de tokens específics ***/
%token <valor> TEXT_CONTINGUT MATEMATIC COMA
%token IMATGE IMATGEFIG PO PT CT CO FP NL LINIA TAB POS_TAB HLINE

/*** Declaració de tokens d'accents ***/
%token <valor> A_A_OBERT A_A_TANCAT A_A_CIRCUM A_A_DIERESIS A_A_TILDE A_A_MACRON A_A_DOT A_A_BREVE A_A_CHECK A_A_HUNGARIAN A_A_TIE A_A_RING A_A_RING_M
%token <valor> A_A_CEDILLA A_A_DOTUNDER A_A_BARUNDER A_A_VECTOR A_A_OBERT_M A_A_TANCAT_M A_A_CIRCUM_M A_A_DIERESIS_M A_A_TILDE_M A_A_AE_DIFTONG_M A_A_AE_DIFTONG
%token <valor> A_A_MACRON_M A_A_DOT_M A_A_BREVE_M A_A_CHECK_M A_A_HUNGARIAN_M A_A_TIE_M A_A_CEDILLA_M A_A_DOTUNDER_M A_A_BARUNDER_M
%token <valor> A_E_OBERT A_E_TANCAT A_E_CIRCUM A_E_DIERESIS A_E_TILDE A_E_MACRON A_E_DOT A_E_BREVE A_E_CHECK A_E_HUNGARIAN
%token <valor> A_E_TIE A_E_CEDILLA A_E_DOTUNDER A_E_BARUNDER A_E_VECTOR A_E_OBERT_M A_E_TANCAT_M A_E_CIRCUM_M A_E_DIERESIS_M A_E_TILDE_M
%token <valor> A_E_MACRON_M A_E_DOT_M A_E_BREVE_M A_E_CHECK_M A_E_HUNGARIAN_M A_E_TIE_M A_E_CEDILLA_M A_E_DOTUNDER_M A_E_BARUNDER_M A_I_OBERT
%token <valor> A_I_TANCAT A_I_CIRCUM A_I_DIERESIS A_I_TILDE A_I_MACRON A_I_DOT A_I_BREVE A_I_CHECK A_I_HUNGARIAN A_I_TIE A_I_CEDILLA
%token <valor> A_I_DOTUNDER A_I_BARUNDER A_I_VECTOR A_I_OBERT_M A_I_TANCAT_M A_I_CIRCUM_M A_I_DIERESIS_M A_I_TILDE_M A_I_MACRON_M
%token <valor> A_I_DOT_M A_I_BREVE_M A_I_CHECK_M A_I_HUNGARIAN_M A_I_TIE_M A_I_CEDILLA_M A_I_DOTUNDER_M A_I_BARUNDER_M A_O_OBERT
%token <valor> A_O_TANCAT A_O_CIRCUM A_O_DIERESIS A_O_TILDE A_O_MACRON A_O_DOT A_O_BREVE A_O_CHECK A_O_HUNGARIAN A_O_TIE A_O_CEDILLA
%token <valor> A_O_DOTUNDER A_O_BARUNDER A_O_VECTOR A_O_OBERT_M A_O_TANCAT_M A_O_CIRCUM_M A_O_DIERESIS_M A_O_TILDE_M A_O_MACRON_M
%token <valor> A_O_DOT_M A_O_BREVE_M A_O_CHECK_M A_O_HUNGARIAN_M A_O_TIE_M A_O_CEDILLA_M A_O_DOTUNDER_M A_O_BARUNDER_M A_U_OBERT A_U_TANCAT
%token <valor> A_U_CIRCUM A_U_DIERESIS A_U_TILDE A_U_MACRON A_U_DOT A_U_BREVE A_U_CHECK A_U_HUNGARIAN A_U_TIE A_U_CEDILLA A_U_DOTUNDER
%token <valor> A_U_BARUNDER A_U_VECTOR A_U_OBERT_M A_U_TANCAT_M A_U_CIRCUM_M A_U_DIERESIS_M A_U_TILDE_M A_U_MACRON_M A_U_DOT_M A_U_BREVE_M
%token <valor> A_U_CHECK_M A_U_HUNGARIAN_M A_U_TIE_M A_U_CEDILLA_M A_U_DOTUNDER_M A_U_BARUNDER_M A_C_TRENCADA A_C_TRENCADA_M A_N_CEDILLA A_N_CEDILLA_M

/*** Declaració de tokens de tamany de font ***/
%token D_TEXT_TINY D_TEXT_SCRIPTSIZE D_TEXT_FOOTNOTESIZE D_TEXT_SMALL D_TEXT_NORMALSIZE D_TEXT_LARGE D_TEXT_LLARGE D_TEXT_LLLARGE D_TEXT_HUGE D_TEXT_HHUGE

/*** Declaració de tokens de tipus declaració ***/
%token <valor> D_TEXT_IT D_TEXT_BF D_TEXT_TT D_TEXT_EM

/*** Declaració de tokens de marca ***/
%token M_PACKAGE M_DOC_CLASS M_SECCIO M_SUBSECCIO M_SUBSUBSECCIO M_TEXT_EMF M_TEXT_NORMAL M_TEXT_ITALICA M_TEXT_BOLD M_TEXT_SUBR M_TEXT_SUP M_TEXT_MECANOGRAFIC
%token M_LLISTA_DE_FIGURES M_LLISTA_DE_TAULES M_TAULA_DE_CONTINGUTS M_CAPITOL M_TITOL M_AUTOR M_AND M_DATA M_THANKS M_FER_TITOL M_PART M_ITEM M_SUBITEM
%token M_PEU_DE_PAGINA M_ETIQUETA M_REFERENCIA M_PARAGRAF M_SUBPARAGRAF M_APENDIX M_CAPTION M_CITACIO M_ITEM_BIBLIOGRAFIC M_LINK M_TARGET M_HREF


/*** Declaració de tokens de símbols ***/
%token <valor> S_DOLLAR S_AMPERSAND S_TANPERCENT S_GUIOINF S_CLAUOBERTA S_CLAUTANCADA S_MENORQUE S_MAJORQUE
%token <valor> S_CONTRABARRA S_BARRA S_PUNT S_DOBLECREUETA S_CREUETA S_PARAGRAF S_SECCIO S_COPYRIGHT S_CIRCUM
%token <valor> S_TILDE S_REGISTRAT S_TRADEMARK S_AFEM S_OMASC S_SHARP S_DIFERENT S_MENOR_IGUAL S_MAJOR_IGUAL
%token <valor> S_APROXIMAT S_IDENTIC S_INFINIT S_INTERSECCIO S_INTEGRAL S_ARREL_QUADRADA S_SUMATORI S_PRODUCTORI
%token <valor> S_INCREMENT S_DIFERENCIAL

/*** Declaració de tokens d'entorn ***/
%token <valor> INICI_DOC FI_DOC INICI_TITOL FI_TITOL INICI_ENUMERAT FI_ENUMERAT INICI_BIBLIOGRAFIA FI_BIBLIOGRAFIA INICI_ABSTRACT FI_ABSTRACT
%token <valor> INICI_FIGURA FI_FIGURA INICI_TAULA FI_TAULA INICI_TABULAR FI_TABULAR INICI_EQUACIO FI_EQUACIO INICI_ITEMIZE FI_ITEMIZE
%token <valor> INICI_ARRAY FI_ARRAY INICI_EQARRAY FI_EQARRAY INICI_TEOREMA FI_TEOREMA INICI_TEXT_CENTRAT FI_TEXT_CENTRAT 
%token <valor> INICI_TEXT_ESQ FI_TEXT_ESQ INICI_TEXT_DRETA FI_TEXT_DRETA INICI_VERS FI_VERS INICI_TABBING FI_TABBING INICI_RAWHTML FI_RAWHTML

/*** Declaració d'estructures sintàctiques ***/
%type <valor> cos_itemize itemize taula cos_taula cos_figura conjunt_titol inici_preambul cos_preambul preambul document cos cos_document cos_titol text seccio subseccio subsubseccio text_centrat simbol lletra_accentuada text_fonts text_emfatitzat text_mecanografic
%type <valor> etiqueta referencia liniah capitol part thanks titol data cos_autor autor text_normal text_italica text_negreta text_subratllat text_super pagina_titol abstract entorn cos_entorn_it cos_entorn_bf cos_entorn_tt cos_entorn_em cos_bibliografia bibliografia
%type <valor> paragraf subparagraf citacio text_esquerra text_dreta figura grafic enumerat nota_peu_pagina tamany_font caption_figura caption_taula fragment_matematic equacio html hyperlink hypertarget hyperreferencia tabbing cos_tabbing cos_citacio

%start document

%%

/******* DOCUMENT *******/
document: preambul cos_document {inserirSeccioEnCurs();}
        | cos_document {inserirSeccioEnCurs();}
        ;

/******* PREAMBUL ********/
preambul: inici_preambul cos_preambul {}
        | inici_preambul {}
        ;

inici_preambul: M_DOC_CLASS CO text CT PO text PT 
                 {
                    bool error = false;
                    classe = obtenir_classe($6, &error);
                    if (error) {warning(1);}
                 }
               | M_DOC_CLASS PO text PT
                 {
                    bool error = false;
                    classe = obtenir_classe($3, &error);
                    if (error) {warning(1);} 
                 }
               ;

conjunt_titol: conjunt_titol conjunt_titol {}
             | autor {}
             | data {}
             | titol {}
             ;

cos_preambul: cos_preambul cos_preambul {}            
            | conjunt_titol {}
            | paquets {warning(2);}
            ;

cos_document: INICI_DOC {notes_al_peu->buidar();} cos FI_DOC {}
            | INICI_DOC M_FER_TITOL 
               {  char* titol = concatenar(titol_document, autors_document, data_document,"","");
                  addCos(titol);
                  free(titol); 
               } cos FI_DOC {}
            | INICI_DOC conjunt_titol M_FER_TITOL 
               {  char* titol = concatenar(titol_document, autors_document, data_document,"","");
                  addCos(titol);
                  free(titol); 
               } cos FI_DOC {};

cos: cos cos {}
   | text {addCos($1); free($1);}
   | part 
      {
         char* aux;
         char* aux2;
         if(conf.nopart==false)
          {   novaSeccio(part, $1);
              addTitol($1);
          }else {document->CompActual.novaPart();}
        
         compt->novaPart();      
         nom_en_curs = compt->obtenirNom();
         aux2 = compt->obtenirValorComptador();
         pila->desapilarEntorn();
         pila->apilarEntorn(nom_en_curs, aux2);
         aux = concatenar("<H1><A NAME=", nom_en_curs, ">", aux2, "<P>");
         addCos(aux); addCos($1); addCos("</A></H1>\n");
         free(aux); free(aux2); free($1);
      }
   | capitol 
      {
         char* aux;
         char* aux2;
         if(conf.nocapitol==false) 
          {   novaSeccio(capitol, $1);
              addTitol($1);
          }else {document->CompActual.nouCapitol();}

         compt->nouCapitol();
         nom_en_curs = compt->obtenirNom();
         aux2 = compt->obtenirValorComptador();
         pila->desapilarEntorn();
         pila->apilarEntorn(nom_en_curs, aux2);
         aux = concatenar("<H2><A NAME=", nom_en_curs, ">", aux2, "<P>");
         addCos(aux); addCos($1); addCos("</A></H2>\n");
         free(aux); free(aux2); free($1);
      }
   | seccio 
      {
         char* aux;
         char* aux2;
         if(conf.nosec==false) 
          {   novaSeccio(seccio, $1);
              addTitol($1);
          }else {document->CompActual.novaSeccio();}

         compt->novaSeccio();
         nom_en_curs = compt->obtenirNom();
         aux2 = compt->obtenirValorComptador();
         pila->desapilarEntorn();
         pila->apilarEntorn(nom_en_curs, aux2);
         aux = concatenar("<H2><A NAME=", nom_en_curs, ">", aux2, "   ");
         addCos(aux); addCos($1); addCos("</A></H2>\n");
         free(aux); free(aux2); free($1);
      }
   | subseccio
      {
         char* aux;
         char* aux2;
         if(conf.nosubsec==false) 
          {   novaSeccio(subseccio, $1);
              addTitol($1);
          }else {document->CompActual.novaSubseccio();}

         compt->novaSubseccio();
         nom_en_curs = compt->obtenirNom();
         aux2 = compt->obtenirValorComptador();
         pila->desapilarEntorn();
         pila->apilarEntorn(nom_en_curs, aux2);
         aux = concatenar("<H3><A NAME=", nom_en_curs, ">", aux2, "   ");
         addCos(aux); addCos($1); addCos("</A></H3>\n");
         free(aux); free(aux2); free($1);
      }
   | subsubseccio
      {
         char* aux;
         char* aux2;
         if(conf.nosubsubsec==false) 
          {   novaSeccio(subsubseccio, $1);
              addTitol($1);
          }else {document->CompActual.novaSubsubseccio();}

         compt->novaSubsubseccio();
         nom_en_curs = compt->obtenirNom();
         aux2 = compt->obtenirValorComptador();
         pila->desapilarEntorn();
         pila->apilarEntorn(nom_en_curs, aux2);
         aux = concatenar("<H4><A NAME=", nom_en_curs, ">", aux2, "   ");
         addCos(aux); addCos($1); addCos("</A></H4>\n");
         free(aux); free(aux2); free($1);
      }
   ;

text: text text               {$$=concatenar($1,$2,"","",""); free($1); free($2);}
    | TEXT_CONTINGUT          {
                               if(tabbing_flag){espais = espais + strlen($1);}
                               if((!entorn_html)&&(!hyperref)) {$$=resaltarLinksUrl($1); free($1);} else {$$=$1;}
                              }
    | COMA                    {$$=$1;}
    | lletra_accentuada       {$$=$1;}
    | text_fonts              {$$=$1;}
    | text_centrat            {$$=$1;}
    | text_esquerra           {$$=$1;}
    | text_dreta              {$$=$1;}
    | simbol                  {$$=$1;}
    | liniah                  {$$=$1;}
    | citacio                 {$$=$1;}
    | etiqueta                {$$=$1;}
    | referencia              {$$=$1;}
    | FP                      {
                               if(tabbing_flag){espais=0;tab_compt=0;$$=igual("<BR>\n");}
                               else {$$=igual("\n<P>");}
                              }
    | NL                      {$$=igual("<BR>\n");}
    | grafic                  {$$=$1;}
    | enumerat                {$$=$1;}
    | nota_peu_pagina         {$$=$1;}
    | tamany_font             {}
    | M_TAULA_DE_CONTINGUTS   {$$=igual("\n<P><H2>Taula de continguts</H2>\n<P>%C</P>\n");}
    | M_LLISTA_DE_FIGURES     {$$=igual("\n<P><H2>Llista de figures</H2>\n<P>%F</P>\n");}
    | M_LLISTA_DE_TAULES      {$$=igual("\n<P><H2>Llista de taules</H2>\n<P>%T</P>\n");}
    | paragraf                {$$=$1;}
    | subparagraf             {$$=$1;}
    | fragment_matematic      {$$=$1;}
    | figura                  {$$=$1;}
    | taula                   {$$=$1;}
    | abstract                {$$=$1;}
    | D_TEXT_IT               {$$=igual("<I>");}
    | D_TEXT_BF               {$$=igual("<B>");}
    | D_TEXT_TT               {$$=igual("<TT>");}
    | D_TEXT_EM               {$$=igual("<EM>");}
    | entorn                  {$$=$1;}
    | equacio                 {$$=$1;}
    | pagina_titol            {$$=$1;}
    | itemize                 {$$=$1;}
    | html                    {$$=$1;}
    | hyperlink               {$$=$1;}
    | hypertarget             {$$=$1;}
    | hyperreferencia         {$$=$1;}
    | tabbing                 {$$=$1;}
    | bibliografia            {$$=$1;}
    ;

cos_bibliografia: cos_bibliografia cos_bibliografia {$$=concatenar($1,$2,"","",""); free($1); free($2);}
                | M_ITEM_BIBLIOGRAFIC CO text CT PO TEXT_CONTINGUT PT text
                   {
                     char* etiqueta;
                     char* aux=concatenar("&#91;",$3,"&#93;","","");
                     char* fitxer = assignarFitxer();
 
                     etiqueta=concatenar("B",$6,"","","");
                     ref_creuades->inserirEtiqueta(etiqueta, etiqueta, fitxer, aux);
                     $$=concatenar("<TABLE border=0 width=100%>\n<TR>\n<TD width=10% valign=top><A NAME=",etiqueta,">",aux,"</A></TD>\n<TD width=90%>");
                     free(aux); aux=$$;
                     $$=concatenar($$,$8,"</TD>\n</TR>\n</TABLE>\n","","");
                     free(etiqueta); free(fitxer); free($3); free($6); free(aux); free($8);
                   }
                | M_ITEM_BIBLIOGRAFIC text CO text CT PO TEXT_CONTINGUT PT text
                   {
                     char* etiqueta;
                     char* aux=concatenar("[",$4,"]","","");
                     char* fitxer = assignarFitxer();
 
                     etiqueta=concatenar("B",$7,"","","");
                     ref_creuades->inserirEtiqueta(etiqueta, etiqueta, fitxer, aux);
                     $$=concatenar("<TABLE border=0 width=100%>\n<TR>\n<TD width=10% valign=top><A NAME=",etiqueta,">",aux,"</A></TD>\n<TD width=90%>");
                     free(aux); aux=$$;
                     $$=concatenar($$,$9,"</TD>\n</TR>\n</TABLE>\n","","");
                     free(etiqueta); free(fitxer); free($4); free($7); free(aux); free($9);
                   }
                | M_ITEM_BIBLIOGRAFIC PO TEXT_CONTINGUT PT text
                   {
                     char* etiqueta;
                     char* numero=intToAsc(compt_bibliografia);
                     char* aux=concatenar("[",numero,"]","","");
                     char* fitxer = assignarFitxer();

                     compt_bibliografia++;
                     etiqueta=concatenar("B",$3,"","","");
                     ref_creuades->inserirEtiqueta(etiqueta, etiqueta, fitxer, aux);
                     $$=concatenar("<TABLE border=0 width=100%>\n<TR>\n<TD width=10% valign=top><A NAME=",etiqueta,">",aux,"</A></TD>\n<TD width=90%>");
                     free(aux); aux=$$;
                     $$=concatenar($$,$5,"</TD>\n</TR>\n</TABLE>\n","","");
                     free(etiqueta); free(fitxer); free($3); free(aux); free(numero);
                   }
                | M_ITEM_BIBLIOGRAFIC text PO TEXT_CONTINGUT PT text
                   {
                     char* etiqueta;
                     char* numero=intToAsc(compt_bibliografia);
                     char* aux=concatenar("[",numero,"]","","");
                     char* fitxer = assignarFitxer();

                     compt_bibliografia++;
                     etiqueta=concatenar("B",$4,"","","");
                     ref_creuades->inserirEtiqueta(etiqueta, etiqueta, fitxer, aux);
                     $$=concatenar("<TABLE border=0 width=100%>\n<TR>\n<TD width=10% valign=top><A NAME=",etiqueta,">",aux,"</A></TD>\n<TD width=90%>");

                     free(aux); aux=$$;
                     $$=concatenar($$,$6,"</TD>\n</TR>\n</TABLE>\n","","");
                     free(etiqueta); free(fitxer); free($4); free(aux); free(numero);

                   };


bibliografia: INICI_BIBLIOGRAFIA cos_bibliografia FI_BIBLIOGRAFIA 
              {
                $$=concatenar("\n<P><H2>Referències bibliogràfiques</H2>\n", $2,"","","");
                compt_bibliografia=1;
                free($2);
              }
            | INICI_BIBLIOGRAFIA entorn cos_bibliografia FI_BIBLIOGRAFIA 
              {
                $$=concatenar("\n<P><H2>Referències bibliogràfiques</H2>\n", $3,"","","");
                compt_bibliografia=1;
                free($3); free($2);
              };
            

cos_tabbing: cos_tabbing cos_tabbing {$$=concatenar($1,$2,"","","");free($1);free($2);}
           | POS_TAB {tab_espais[tab]=espais; tab++; espais=0; $$=igual("");}
           | TAB 
              {
                 char* aux=igual("");
                 char* aux2;
                 for(int e=0; e<tab_espais[tab_compt]; e++)
                  {
                     aux2=aux;
                     aux=concatenar(aux, "&nbsp;&nbsp;","","",""); free(aux2);
                  }
                 $$=aux;
                 if(tab_compt<tab){tab_compt++;}
              }
           | text {$$=$1;}
           ;

tabbing: INICI_TABBING {tabbing_flag=true;} cos_tabbing FI_TABBING
          {
             tabbing_flag=false;
             espais=0;
             tab_compt=0;
             tab=0;
             tab_espais[0]=0;
             $$=concatenar("\n<P><TABLE border=0>\n<TR>\n<TD align=left>",$3,"</TD>\n</TR>\n</TABLE></P>\n","",""); free($3);
          };

hyperreferencia: M_HREF {hyperref=true;} PO TEXT_CONTINGUT PT PO text PT
                  {
                     $$=concatenar("<A HREF=",$4,">",$7,"</A>"); free($4); free($7);
                     hyperref=false;
                  };

hyperlink: M_LINK PO TEXT_CONTINGUT PT PO text PT
            {
               $$=concatenar("<A HREF={H",$3,"}>",$6,"</A>"); free($3); free($6);
            };

hypertarget: M_TARGET PO TEXT_CONTINGUT PT PO text PT
          {
             char* aux = igual("");
             char* fitxer = assignarFitxer();
             char* etiqueta = new char[strlen($3) + 2];
             etiqueta = concatenar("H",$3,"","","");

             ref_creuades->inserirEtiqueta(etiqueta, etiqueta, fitxer, aux);
             $$=concatenar("<A NAME=",etiqueta,">",$6,"</A>");
             free(aux); free(fitxer); free($3);
          };

html: INICI_RAWHTML {entorn_html=true;} text FI_RAWHTML {$$=$3; entorn_html=false;};

cos_itemize: cos_itemize cos_itemize {$$=concatenar($1,$2,"","",""); free($1); free($2);}
           | M_ITEM CO text CT text {$$=concatenar("<LI>",$3,"&nbsp;&nbsp;&nbsp;",$5,"</LI>\n"); free($3); free($5);}
           | M_ITEM text CO text CT text {$$=concatenar("<LI>",$4,"&nbsp;&nbsp;&nbsp;",$6,"</LI>\n"); free($4); free($6);}
           | M_ITEM text {$$=concatenar("<LI>",$2,"</LI>\n","",""); free($2);}
           | M_ITEM {$$=igual("");}
           | M_SUBITEM CO text CT text {$$=concatenar("<LI>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;",$3,"&nbsp;&nbsp;&nbsp;",$5,"</LI>\n"); free($3); free($5);}
           | M_SUBITEM text CO text CT text {$$=concatenar("<LI>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;",$4,"&nbsp;&nbsp;&nbsp;",$6,"</LI>\n"); free($4); free($6);}
           | M_SUBITEM text {$$=concatenar("<LI>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;",$2,"</LI>\n","",""); free($2);}
           | M_SUBITEM {$$=igual("");}
           | text {$$=$1;}
           ;

itemize: INICI_ITEMIZE cos_itemize FI_ITEMIZE 
          {
             $$=concatenar("\n<UL>\n",$2,"\n</UL>\n","",""); free($2);
          }
        | INICI_ITEMIZE FI_ITEMIZE {$$=igual("");};

enumerat: INICI_ENUMERAT {nivell_enumerat++;} cos_itemize FI_ENUMERAT 
          {
             nivell_enumerat--;
             switch(nivell_enumerat)
              {
                  case 0: $$=concatenar("\n<OL TYPE=1>\n",$3,"</OL>\n","",""); break;
                  case 1: $$=concatenar("\n<OL TYPE=a>\n",$3,"</OL>\n","",""); break;
                  case 2: $$=concatenar("\n<OL TYPE=i>\n",$3,"</OL>\n","",""); break;
                  default: $$=concatenar("\n<OL TYPE=A>\n",$3,"</OL>\n","","");
              }
          }
        | INICI_ENUMERAT FI_ENUMERAT {$$=igual("");}
        ;

equacio: INICI_EQUACIO 
          {
             char* aux;
             char* fitxer = assignarFitxer();

             compt_equacions++;
             free(equacio_en_curs);
             equacio_en_curs = obtenirNomEquacio();

             aux = intToAsc(compt_equacions);
             pila->apilarEntorn(equacio_en_curs, aux);
             free(aux); free(fitxer);
          }
         text FI_EQUACIO 
          {
             pila->desapilarEntorn();

             char* num = intToAsc(compt_equacions);
             $$=concatenar("\n<DIV ALIGN=right>\n<TABLE BORDER=0 WIDTH=80% CELLSPACING=5>\n<TR>\n<TD WIDTH=70% ALIGN=center><EM>",$3, "</EM></TD>\n<TD WIDTH=30%>(", num, ")</TD>\n</TR>\n</TABLE>\n</DIV><P>\n");
             free(num); free($3);
          };

cos_entorn_it: text D_TEXT_IT text {$$=concatenar($1,"<I>",$3,"",""); free($1); free($2); free($3);}
             | text D_TEXT_IT {$$=concatenar($1,"<I>","","",""); free($1); free($2);}
             | D_TEXT_IT text {$$=concatenar("<I>",$2,"","",""); free($1); free($2);}
             | D_TEXT_IT {$$=igual("<I>");;};

cos_entorn_bf: text D_TEXT_BF text {$$=concatenar($1,"<B>",$3,"",""); free($1); free($2); free($3);}
             | text D_TEXT_BF {$$=concatenar($1,"<B>","","",""); free($1); free($2);}
             | D_TEXT_BF text {$$=concatenar("<B>",$2,"","",""); free($1); free($2);}
             | D_TEXT_BF {$$=igual("<B>");};

cos_entorn_tt: text D_TEXT_TT text {$$=concatenar($1,"<TT>",$3,"",""); free($1); free($2); free($3);}
             | text D_TEXT_TT {$$=concatenar($1,"<TT>","","",""); free($1); free($2);}
             | D_TEXT_TT text {$$=concatenar("<TT>",$2,"","",""); free($1); free($2);}
             | D_TEXT_TT {$$=igual("<TT>");};

cos_entorn_em: text D_TEXT_EM text {$$=concatenar($1,"<EM>",$3,"",""); free($1); free($2); free($3);}
             | text D_TEXT_EM {$$=concatenar($1,"<EM>","","",""); free($1); free($2);}
             | D_TEXT_EM text {$$=concatenar("<EM>",$2,"","",""); free($1); free($2);}
             | D_TEXT_EM {$$=igual("<EM>");};

entorn: PO PT {$$=igual("");}
      | PO text PT {$$=$2;}
      | PO cos_entorn_it PT {$$=concatenar($2,"</I>","","",""); free($2);}
      | PO cos_entorn_bf PT {$$=concatenar($2,"</B>","","",""); free($2);}
      | PO cos_entorn_tt PT {$$=concatenar($2,"</TT>","","",""); free($2);}
      | PO cos_entorn_em PT {$$=concatenar($2,"</EM>","","",""); free($2);}
      ;

abstract: INICI_ABSTRACT text FI_ABSTRACT 
           {
               $$=concatenar("\n<DIV ALIGN=center><CENTER>\n<TABLE BORDER=0 WIDTH=75%>\n<TR><TD WIDTH=100%><P ALIGN=center><B>Resum</B></P>\n<P>",$2,"</TD>\n</TR></TABLE>\n</CENTER></DIV><P>\n","","");
               free($2);
           };

nota_peu_pagina: M_PEU_DE_PAGINA entorn
                   {
                      char* numero;
                      char* etiqueta_font;
                      char* etiqueta_nota;
                      char* aux; char* aux2;
                      char* num_node=intToAsc(compt_nodes);
                      notes_al_peu->guardarNota($2, numero, etiqueta_font, etiqueta_nota);
                      aux = concatenar("<A NAME=", etiqueta_font, " HREF=node",num_node,".html#");
                      aux2 = aux; free(num_node);
                      $$ = concatenar(aux,etiqueta_nota ,"><SUP>", numero, "</SUP></A>");
                      delete aux2; delete numero; delete etiqueta_font; delete etiqueta_nota;
                   };
          
fragment_matematic: MATEMATIC 
                    {
                        char* aux;
                        aux = conversor->inserirFragmentMatematic($1);
                        $$=concatenar("<img align=absmiddle src=",aux,">","","");
                        free(aux);
                    }

grafic: IMATGE PO text PT
          {
            if(fitxerExisteix($3))
             {
               char* aux = $3;
               conversor->inserirImatge($3);
               $3=canviarExtensioGrafica($3); free(aux);
               $$=concatenar("<img  align=absmiddle src=",$3,">","","");
             }else {cout << "Avís-> No existeix el fitxer "<<$3<<"\n";}
            free($3);
          }
      | IMATGEFIG PO text PT
          {
            if(fitxerExisteix($3))
             {
               char* aux = $3;
               conversor->inserirImatge($3);
               $3=canviarExtensioGrafica($3); free(aux);
               $$=concatenar("<img  align=absmiddle src=",$3,">","","");
             }else {cout << "Avís-> No existeix el fitxer "<<$3<<"\n";}
            free($3);
          }
      ;

cos_figura: text caption_figura text {$$=concatenar($1,$2,$3,"",""); free($1); free($2); free($3);}
          | caption_figura text {$$=concatenar($1, $2, "","",""); free($1); free($2);}
          | text caption_figura {$$=concatenar($1, $2, "","",""); free($1); free($2);};
          | caption_figura {$$=$1;}

caption_figura: M_CAPTION entorn
          {
             char* aux;
             char* fitxer = assignarFitxer();

             compt_figures++;
             free(figura_en_curs);
             figura_en_curs = obtenirNomFigura();

             aux = intToAsc(compt_figures);
             pila->apilarEntorn(figura_en_curs, aux);
             $$=concatenar("\n<CENTER>Figura ",aux,": ",$2,"</CENTER>\n");

             document->inserirFigura(figura_en_curs, aux, $2, fitxer);
             free(aux); free(fitxer); free($2);
          };

figura: INICI_FIGURA cos_figura FI_FIGURA 
           {
              pila->desapilarEntorn();
              $$=concatenar("\n<P><A NAME=", figura_en_curs,">", $2,"</P>\n"); free($2);
           }

      | INICI_FIGURA text FI_FIGURA 
           {
              $$=concatenar("\n<P>", $2, "</P>\n","","");
              free($2);
           };

cos_taula:  text caption_taula text {$$=concatenar($1,$2,$3,"",""); free($1); free($2); free($3);}
          | caption_taula text {$$=concatenar($1, $2, "","",""); free($1); free($2);}
          | text caption_taula {$$=concatenar($1, $2, "","",""); free($1); free($2);};
          | caption_taula {$$=$1;}

caption_taula: M_CAPTION entorn 
          {
             char* aux;
             char* fitxer = assignarFitxer();

             compt_taules++;
             free(taula_en_curs);
             taula_en_curs = obtenirNomTaula();

             aux = intToAsc(compt_taules);
             pila->apilarEntorn(taula_en_curs, aux);
             $$=concatenar("\n<CENTER>Taula ",aux,": ",$2,"</CENTER>\n");

             document->inserirTaula(taula_en_curs, aux, $2, fitxer);
             free(aux); free(fitxer); free($2);
          };

taula: INICI_TAULA cos_taula FI_TAULA 
           {
              pila->desapilarEntorn();
              $$=concatenar("\n<P><A NAME=", taula_en_curs,">", $2,"</P>\n"); free($2);
           }
     | INICI_TAULA text FI_TAULA
           {
              $$=concatenar("\n<P>", $2, "</P>\n","","");
              free($2);
           };

cos_citacio: cos_citacio cos_citacio {$$=concatenar($1,$2,"","",""); free($1); free($2);}
           | COMA {$$=igual("; "); free($1); multi_bib=true;}
           | TEXT_CONTINGUT {$$=concatenar("{B",$1,"}","",""); free($1);}
           ;

citacio: M_CITACIO PO cos_citacio PT 
          {
             if(!multi_bib) {$$=$3;}
             else {$$=concatenar("(",$3,")","",""); free($3);}
             multi_bib=false;
          }
       | M_CITACIO CO text CT PO cos_citacio PT
          {
               $$=concatenar("(",$6,",",$3,")"); free($3); free($6);
          };

etiqueta: M_ETIQUETA PO text PT 
          {
             char* etiqueta;
             char* comptador;
             char* aux;
             char* fitxer = assignarFitxer();

             pila->consultarEntornActual(etiqueta, comptador);
             if(conf.refc==true)
              {
                free(etiqueta);
                etiqueta = intToAsc(compt_etiquetes);
                aux=etiqueta;
                etiqueta=concatenar("etiqueta", etiqueta,"","","");
                free(aux);
              }
             aux=concatenar("R",$3,"","","");
             ref_creuades->inserirEtiqueta(aux, etiqueta, fitxer, comptador);
             $$=concatenar("<A NAME=",etiqueta,"></A>","","");
             free(etiqueta); free(comptador); free(fitxer); free($3); free(aux);
             compt_etiquetes++;
          };

referencia: M_REFERENCIA PO text PT 
            {
               $$=concatenar("{R",$3,"}","",""); free($3);
            };

paragraf: M_PARAGRAF entorn {$$=concatenar("\n<P><B>",$2,"</B>&nbsp;&nbsp;&nbsp;","",""); free($2);}
        | M_PARAGRAF PO PT {$$=igual("\n<P>&nbsp;&nbsp;&nbsp;");}
        ;

subparagraf: M_SUBPARAGRAF entorn {$$=concatenar("\n<P>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<B>",$2,"</B>&nbsp;&nbsp;&nbsp;","",""); free($2);}
           | M_SUBPARAGRAF PO PT {$$=igual("\n<P>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;");}
           ;

text_fonts: text_emfatitzat
             {
                char* aux;

                if(emfasi) {aux = concatenar("</EM>",$1,"<EM>","","");}
                else {aux = concatenar("<EM>",$1,"</EM>","","");}

                $$=aux; free($1);
             }
          | text_italica
             {
                char* aux;

                if(italica) aux = concatenar("</I>",$1,"<I>","","");
                else aux = concatenar("<I>",$1,"</I>","","");

                $$=aux; free($1);
             }
          | text_normal
             {
                char* it = igual(""); char* io = igual("");
                char* nt = igual(""); char* no = igual("");
                char* et = igual(""); char* eo = igual("");
                char* mt = igual(""); char* mo = igual("");
                char* tancament;
                char* obertura;

                if(flag_italica)      {free(it); it = igual("</I>");
                                       free(io); io = igual("<I>");
                                       flag_italica=false; italica=true;}
                if(flag_negreta)      {free(nt); nt = igual("</B>");
                                       free(no); no = igual("<B>");
                                       flag_negreta=false; negreta=true;}
                if(flag_emfasi)       {free(et); et = igual("</EM>");
                                       free(eo); eo = igual("<EM>");
                                       flag_emfasi=false; emfasi=true;}
                if(flag_mecanografic) {free(mt); mt = igual("</TT>");
                                       free(mo); mo = igual("<TT>");
                                       flag_mecanografic=false; mecanografic=true;}

                tancament = concatenar(it,nt,et,mt,"");
                obertura  = concatenar(io,no,eo,mo,"");

                $$ = concatenar(tancament,$1,obertura,"","");
                free(tancament); free(obertura); free($1); free(it); free(nt); free(et);
                free(mt); free(io); free(no); free(eo); free(mo);
             }
          | text_negreta 
             {
                char* aux;

                if(negreta) aux = concatenar("</B>",$1,"<B>","","");
                else aux = concatenar("<B>",$1,"</B>","","");

                $$=aux; free($1);
             }
          | text_subratllat
             {
                char* aux;

                if(subratllat) aux = concatenar("</U>",$1,"<U>","","");
                else aux = concatenar("<U>",$1,"</U>","","");

                $$=aux; free($1);
             }
          | text_super
             {
                char* aux;

                if(super) aux = concatenar("</SUP>",$1,"<SUP>","","");
                else aux = concatenar("<SUP>",$1,"</SUP>","","");

                $$=aux; free($1);
             }
          | text_mecanografic
             {
                char* aux;

                if(mecanografic) aux = concatenar("</TT>",$1,"<TT>","","");
                else aux = concatenar("<TT>",$1,"</TT>","","");

                $$=aux; free($1);
             }
          ;

text_emfatitzat: M_TEXT_EMF {emfasi=!emfasi;} entorn {$$=$3; emfasi=!emfasi;};             

text_italica: M_TEXT_ITALICA PO {italica=!italica;} text PT {$$=$4; italica=!italica;};

text_normal: M_TEXT_NORMAL PO 
                { 
                  if (italica) {italica=false; flag_italica=true;}
                  if (negreta) {negreta=false; flag_negreta=true;}
                  if (emfasi) {emfasi=false; flag_emfasi=true;}
                  if (mecanografic) {mecanografic=false; flag_mecanografic=true;}
                } text PT {$$=$4;}
           ;

text_negreta: M_TEXT_BOLD PO {negreta=!negreta;} text PT {$$=$4; negreta=!negreta;};

text_mecanografic: M_TEXT_MECANOGRAFIC PO {mecanografic=!mecanografic;} text PT {$$=$4; mecanografic=!mecanografic;};

text_subratllat: M_TEXT_SUBR PO {subratllat=!subratllat;} text PT {$$=$4; subratllat=!subratllat;};

text_super: M_TEXT_SUP PO {super=!super;} text PT {$$=$4; super=!super;};

liniah: LINIA PO text PT PO text PT 
         {
             char* amplada = obtenirNumeros($3);
             char* gruix = obtenirNumeros($6);

             if(dreta) { $$=concatenar("\n<HR WIDTH=", amplada, " SIZE=", gruix, " ALIGN=right NOSHADE>\n"); }
             else if(esquerra) { $$=concatenar("\n<HR WIDTH=", amplada, " SIZE=", gruix, " ALIGN=left NOSHADE>\n"); }
             else { $$=concatenar("\n<HR WIDTH=", amplada, " SIZE=", gruix, " NOSHADE>\n"); }
             free(amplada); free(gruix); free($3); free($6);
         };

tamany_font: D_TEXT_TINY {}
           | D_TEXT_SCRIPTSIZE {}
           | D_TEXT_FOOTNOTESIZE {}
           | D_TEXT_SMALL {}
           | D_TEXT_NORMALSIZE {}
           | D_TEXT_LARGE {}
           | D_TEXT_LLARGE {}
           | D_TEXT_HUGE {}
           | D_TEXT_HHUGE {}
           ;

text_centrat: INICI_TEXT_CENTRAT {centrat=true;} text FI_TEXT_CENTRAT 
               {
                  centrat=false;
                  $$=concatenar("<CENTER>",$3,"</CENTER>","","");
                  free($3);
               }
            | INICI_TEXT_CENTRAT FI_TEXT_CENTRAT {$$=igual("");}
            ;

text_esquerra: INICI_TEXT_ESQ {esquerra=true;} text FI_TEXT_ESQ
               {
                  esquerra=false;
                  $$=concatenar("<P ALIGN=left>",$3,"</P>","","");
                  free($3);
               }
             | INICI_TEXT_ESQ FI_TEXT_ESQ {$$=igual("");}
             ;

text_dreta: INICI_TEXT_DRETA {dreta=true;} text FI_TEXT_DRETA
               {
                  dreta=false;
                  $$=concatenar("<P ALIGN=right>",$3,"</P>","","");
                  free($3);
               }                   
          | INICI_TEXT_DRETA FI_TEXT_DRETA {$$=igual("");}
          ;

pagina_titol: INICI_TITOL text FI_TITOL {$$=igual($2); free($2);};
            | INICI_TITOL FI_TITOL {$$=igual("");};

part: M_PART entorn {$$=$2;}
    | M_PART PO PT { $$=igual("");}
    ;


capitol: M_CAPITOL entorn {$$=$2;}
       | M_CAPITOL PO PT {$$=igual("");}
       ;


seccio: M_SECCIO entorn {$$=$2;}
      | M_SECCIO PO PT {$$=igual("");}
      ;

subseccio: M_SUBSECCIO entorn {$$=$2;}
         | M_SUBSECCIO PO PT {$$=igual("");}
         ;


subsubseccio: M_SUBSUBSECCIO entorn {$$=$2;}
            | M_SUBSUBSECCIO PO PT {$$=igual("")}
            ;

paquets: M_PACKAGE CO text CT PO text PT {}
       | M_PACKAGE PO text PT {}
       ;

thanks: M_THANKS entorn
         {
           char* numero;
           char* etiqueta_font;
           char* etiqueta_nota;
           char* aux; char* aux2;
           notes_al_peu->guardarGracies($2, numero, etiqueta_font, etiqueta_nota);
           aux = concatenar("<A NAME=", etiqueta_font, " HREF=#", etiqueta_nota, "><SUP>");
           aux2 = aux;
           $$ = concatenar(aux, numero, "</SUP></A>", "", "");
           delete aux2; delete numero; delete etiqueta_font; delete etiqueta_nota;
         };

cos_autor: cos_autor cos_autor {$$ = concatenar($1, $2, "", "", ""); free($1); free($2);}
         | M_AND {$$ = igual("&nbsp;&nbsp;");}
         | thanks {$$=$1;}
         | text {$$=$1;}
         ;

autor: M_AUTOR PO cos_autor PT 
        {free(autors_document);
         autors_document = concatenar("<H3 align=center>",$3,"</H3>\n","","");
         free($3);}
     | M_AUTOR PO cos_autor PT 
        {free(autors_document);
         autors_document = concatenar("<H3 align=center>"," ","</H3>\n","","");};

data: M_DATA PO text PT 
       {free(data_document);
        data_document = concatenar("<H4 align=center>",$3,"</H4>\n","","");
        free($3);};
    | M_DATA PO PT {};

cos_titol: cos_titol cos_titol {$$ = concatenar($1, $2, "", "", ""); free($1); free($2);}
         | thanks {$$=$1;}
         | text {$$=$1;}
         ;

titol: M_TITOL PO cos_titol PT 
        {free(titol_document);
         titol_document = concatenar("<H1 align=center>",$3,"</H1>\n","","");
         free($3);}
     | M_TITOL PO PT 
        {free(titol_document);
         titol_document = concatenar("<H1 align=center>"," ","</H1>\n","","");};

/******* SIMBOLS *******/
simbol: S_DOLLAR { $$ = igual("&#36;"); }
      | S_AMPERSAND { $$ = igual("&#38;"); }
      | S_TANPERCENT { $$ = igual("&#37;"); }
      | S_GUIOINF { $$ = igual("&#95;"); }
      | S_CLAUOBERTA { $$ = igual("&#123;"); }
      | S_CLAUTANCADA { $$ = igual("&#125;"); } 
      | S_MENORQUE { $$ = igual("&#60;"); }
      | S_MAJORQUE { $$ = igual("&#62;"); }
      | S_DIFERENT { $$ = igual("&#8800;"); }
      | S_MENOR_IGUAL { $$ = igual("&#8804;"); }
      | S_MAJOR_IGUAL { $$ = igual("&#8805;"); }
      | S_APROXIMAT { $$ = igual("&#8776;"); }
      | S_SHARP { $$ = igual("&#223;"); }
      | S_IDENTIC { $$ = igual("&#8801;"); }
      | S_INFINIT { $$ = igual("&#8734;"); }
      | S_INTERSECCIO { $$ = igual("&#8745;"); }
      | S_INTEGRAL { $$ = igual("&#8747;"); }
      | S_ARREL_QUADRADA { $$ = igual("&#8730;"); }
      | S_SUMATORI { $$ = igual("&#8721;"); }
      | S_PRODUCTORI { $$ = igual("&#8719;"); }
      | S_INCREMENT { $$ = igual("&#8710;"); }
      | S_DIFERENCIAL { $$ = igual("&#8706;"); }
      | S_CONTRABARRA { $$ = igual("&#92;"); }
      | S_BARRA { $$ = igual("&#124;"); }
      | S_PUNT { $$ = igual("&#8226;"); }
      | S_DOBLECREUETA { $$ = igual("&#8225;"); }
      | S_CREUETA { $$ = igual("&#8224;"); }
      | S_PARAGRAF { $$ = igual("&#182;"); }
      | S_SECCIO { $$ = igual("&#167;"); }
      | S_COPYRIGHT { $$ = igual("&#169;"); }
      | S_CIRCUM { $$ = igual("&#94;"); }
      | S_TILDE { $$ = igual("&#732;"); }
      | S_REGISTRAT { $$ = igual("&#174;"); }
      | S_TRADEMARK { $$ = igual("&#8482;"); }
      | S_AFEM { $$ = igual("&#170;"); }
      | S_OMASC { $$ = igual("&#186;"); }
      ;

/******* LLETRES ACCENTUADES *******/
lletra_accentuada: A_A_OBERT { $$ = igual("&#224;"); }
                 | A_A_TANCAT { $$ = igual("&#225;"); }
                 | A_A_CIRCUM { $$ = igual("&#226;"); }
                 | A_A_DIERESIS { $$ = igual("&#228;"); }
                 | A_A_TILDE { $$ = igual("&#227;");}
                 | A_A_MACRON { $$ = igual("&#257;");}
                 | A_A_DOT {}
                 | A_A_BREVE { $$ = igual("&#259;");}
                 | A_A_CHECK {}
                 | A_A_HUNGARIAN {}
                 | A_A_TIE {}
                 | A_A_CEDILLA {}
                 | A_A_DOTUNDER {}
                 | A_A_BARUNDER {}
                 | A_A_VECTOR {}
                 | A_A_RING { $$ = igual("&#229;");}
                 | A_A_AE_DIFTONG { $$ = igual("&#230;");}
                 | A_A_OBERT_M { $$ = igual("&#192;"); }
                 | A_A_TANCAT_M { $$ = igual("&#193;"); }
                 | A_A_CIRCUM_M { $$ = igual("&#194;"); }
                 | A_A_DIERESIS_M { $$ = igual("&#196;"); }
                 | A_A_TILDE_M { $$ = igual("&#195;");}
                 | A_A_MACRON_M { $$ = igual("&#256;");}
                 | A_A_DOT_M {}
                 | A_A_BREVE_M { $$ = igual("&#258;");}
                 | A_A_CHECK_M {}
                 | A_A_HUNGARIAN_M {}
                 | A_A_TIE_M {}
                 | A_A_CEDILLA_M {}
                 | A_A_DOTUNDER_M {}
                 | A_A_BARUNDER_M {}
                 | A_A_AE_DIFTONG_M { $$ = igual("&#198;");}
                 | A_A_RING_M { $$ = igual("&#197;");}

                 | A_E_OBERT { $$ = igual("&#232;"); }
                 | A_E_TANCAT { $$ = igual("&#233;"); }
                 | A_E_CIRCUM { $$ = igual("&#234;"); }
                 | A_E_DIERESIS { $$ = igual("&#235;"); }
                 | A_E_TILDE {}
                 | A_E_MACRON { $$ = igual("&#275;"); }
                 | A_E_DOT { $$ = igual("&#279;"); }
                 | A_E_BREVE { $$ = igual("&#277;"); }
                 | A_E_CHECK { $$ = igual("&#283;"); }
                 | A_E_HUNGARIAN {}
                 | A_E_TIE {}
                 | A_E_CEDILLA {}
                 | A_E_DOTUNDER {}
                 | A_E_BARUNDER {}
                 | A_E_VECTOR {}
                 | A_E_OBERT_M { $$ = igual("&#200;"); }
                 | A_E_TANCAT_M { $$ = igual("&#201;"); }
                 | A_E_CIRCUM_M { $$ = igual("&#202;"); }
                 | A_E_DIERESIS_M { $$ = igual("&#203;"); }
                 | A_E_TILDE_M {}
                 | A_E_MACRON_M { $$ = igual("&#274;"); }
                 | A_E_DOT_M { $$ = igual("&#278;"); }
                 | A_E_BREVE_M { $$ = igual("&#276;"); }
                 | A_E_CHECK_M { $$ = igual("&#282;"); }
                 | A_E_HUNGARIAN_M {}
                 | A_E_TIE_M {}
                 | A_E_CEDILLA_M {}
                 | A_E_DOTUNDER_M {}
                 | A_E_BARUNDER_M {}

                 | A_I_OBERT { $$ = igual("&#236;"); }
                 | A_I_TANCAT { $$ = igual("&#237;"); }
                 | A_I_CIRCUM { $$ = igual("&#238;"); }
                 | A_I_DIERESIS { $$ = igual("&#239;"); }
                 | A_I_TILDE { $$ = igual("&#297;"); }
                 | A_I_MACRON { $$ = igual("&#299;"); }
                 | A_I_DOT {}
                 | A_I_BREVE { $$ = igual("&#301;"); }
                 | A_I_CHECK {}
                 | A_I_HUNGARIAN {}
                 | A_I_TIE {}
                 | A_I_CEDILLA {}
                 | A_I_DOTUNDER {}
                 | A_I_BARUNDER {}
                 | A_I_VECTOR {}
                 | A_I_OBERT_M { $$ = igual("&#204;"); }
                 | A_I_TANCAT_M { $$ = igual("&#205;"); }
                 | A_I_CIRCUM_M { $$ = igual("&#206;"); }
                 | A_I_DIERESIS_M { $$ = igual("&#207;"); }
                 | A_I_TILDE_M { $$ = igual("&#296;"); }
                 | A_I_MACRON_M { $$ = igual("&#298;"); }
                 | A_I_DOT_M { $$ = igual("&#304;"); }
                 | A_I_BREVE_M { $$ = igual("&#300;"); }
                 | A_I_CHECK_M {}
                 | A_I_HUNGARIAN_M {}
                 | A_I_TIE_M {}
                 | A_I_CEDILLA_M {}
                 | A_I_DOTUNDER_M {}
                 | A_I_BARUNDER_M {}

                 | A_O_OBERT { $$ = igual("&#242;"); }
                 | A_O_TANCAT { $$ = igual("&#243;"); }
                 | A_O_CIRCUM { $$ = igual("&#244;"); }
                 | A_O_DIERESIS { $$ = igual("&#246;"); }
                 | A_O_TILDE { $$ = igual("&#245;"); }
                 | A_O_MACRON { $$ = igual("&#333;"); }
                 | A_O_DOT {}
                 | A_O_BREVE { $$ = igual("&#335;"); }
                 | A_O_CHECK {}
                 | A_O_HUNGARIAN { $$ = igual("&#337;"); }
                 | A_O_TIE {}
                 | A_O_CEDILLA {}
                 | A_O_DOTUNDER {}
                 | A_O_BARUNDER {}
                 | A_O_VECTOR {}
                 | A_O_OBERT_M { $$ = igual("&#210;"); }
                 | A_O_TANCAT_M { $$ = igual("&#211;"); }
                 | A_O_CIRCUM_M { $$ = igual("&#212;"); }
                 | A_O_DIERESIS_M { $$ = igual("&#214;"); }
                 | A_O_TILDE_M { $$ = igual("&#213;"); } 
                 | A_O_MACRON_M { $$ = igual("&#332;"); }
                 | A_O_DOT_M {}
                 | A_O_BREVE_M { $$ = igual("&#334;"); }
                 | A_O_CHECK_M {}
                 | A_O_HUNGARIAN_M { $$ = igual("&#336;"); }
                 | A_O_TIE_M {}
                 | A_O_CEDILLA_M {}
                 | A_O_DOTUNDER_M {}
                 | A_O_BARUNDER_M {}

                 | A_U_OBERT { $$ = igual("&#249;"); }
                 | A_U_TANCAT { $$ = igual("&#250;"); }
                 | A_U_CIRCUM { $$ = igual("&#251;"); }
                 | A_U_DIERESIS { $$ = igual("&#252;"); }
                 | A_U_TILDE { $$ = igual("&#361;"); }
                 | A_U_MACRON { $$ = igual("&#363;"); }
                 | A_U_DOT {}
                 | A_U_BREVE { $$ = igual("&#365;"); }
                 | A_U_CHECK {}
                 | A_U_HUNGARIAN { $$ = igual("&#369;"); }
                 | A_U_TIE {}
                 | A_U_CEDILLA {}
                 | A_U_DOTUNDER {}
                 | A_U_BARUNDER {}
                 | A_U_VECTOR {}
                 | A_U_OBERT_M { $$ = igual("&#217;"); }
                 | A_U_TANCAT_M { $$ = igual("&#218;"); }
                 | A_U_CIRCUM_M { $$ = igual("&#219;"); }
                 | A_U_DIERESIS_M { $$ = igual("&#220;"); }
                 | A_U_TILDE_M { $$ = igual("&#360;"); }
                 | A_U_MACRON_M { $$ = igual("&#362;"); }
                 | A_U_DOT_M {}
                 | A_U_BREVE_M { $$ = igual("&#364;"); }
                 | A_U_CHECK_M {}
                 | A_U_HUNGARIAN_M { $$ = igual("&#368;"); }
                 | A_U_TIE_M {}
                 | A_U_CEDILLA_M {}
                 | A_U_DOTUNDER_M {}
                 | A_U_BARUNDER_M {}

                 | A_C_TRENCADA { $$ = igual("&#231;"); }
                 | A_C_TRENCADA_M { $$ = igual("&#199;"); }
                 | A_N_CEDILLA { $$ = igual("&#241;"); }
                 | A_N_CEDILLA_M { $$ = igual("&#209;"); }
                 ;   
%%

extern "C" { int yywrap() {return 1;} }
















































