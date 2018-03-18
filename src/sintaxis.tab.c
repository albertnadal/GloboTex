#define YY_AnalitzadorSintactic_h_included

/*  A Bison++ parser, made from sintaxis.y  */

 /* with Bison++ version bison++ Version 1.21-5, adapted from GNU bison by coetmeur@icdc.fr
  */


#line 1 "/usr/local/lib/bison.cc"
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Bob Corbett and Richard Stallman

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 1, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* HEADER SECTION */
#ifndef _MSDOS
#ifdef MSDOS
#define _MSDOS
#endif
#endif
/* turboc */
#ifdef __MSDOS__
#ifndef _MSDOS
#define _MSDOS
#endif
#endif

#ifndef alloca
#if defined( __GNUC__)
#define alloca __builtin_alloca

#elif (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc)  || defined (__sgi)
#include <alloca.h>

#elif defined (_MSDOS)
#include <malloc.h>
#ifndef __TURBOC__
/* MS C runtime lib */
#define alloca _alloca
#endif

#elif defined(_AIX)
#include <malloc.h>
#pragma alloca

#elif defined(__hpux)
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */

#endif /* not _AIX  not MSDOS, or __TURBOC__ or _AIX, not sparc.  */
#endif /* alloca not defined.  */
#ifdef c_plusplus
#ifndef __cplusplus
#define __cplusplus
#endif
#endif
#ifdef __cplusplus
#ifndef YY_USE_CLASS
#define YY_USE_CLASS
#endif
#else
#ifndef __STDC__
#define const
#endif
#endif
#include <stdio.h>
#define YYBISON 1  

/* #line 77 "/usr/local/lib/bison.cc" */
#line 1 "sintaxis.y"

// Analitzador Sintàctic (gramàtica)

#line 6 "sintaxis.y"
typedef union { char *valor; } yy_AnalitzadorSintactic_stype;
#define YY_AnalitzadorSintactic_STYPE yy_AnalitzadorSintactic_stype
#define YY_AnalitzadorSintactic_LSP_NEEDED 
#define YY_AnalitzadorSintactic_ERROR_BODY  =0
#define YY_AnalitzadorSintactic_LEX_BODY  =0
#define YY_AnalitzadorSintactic_MEMBERS  virtual void warning(int){};
#line 12 "sintaxis.y"

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

#line 77 "/usr/local/lib/bison.cc"
/* %{ and %header{ and %union, during decl */
#define YY_AnalitzadorSintactic_BISON 1
#ifndef YY_AnalitzadorSintactic_COMPATIBILITY
#ifndef YY_USE_CLASS
#define  YY_AnalitzadorSintactic_COMPATIBILITY 1
#else
#define  YY_AnalitzadorSintactic_COMPATIBILITY 0
#endif
#endif

#if YY_AnalitzadorSintactic_COMPATIBILITY != 0
/* backward compatibility */
#ifdef YYLTYPE
#ifndef YY_AnalitzadorSintactic_LTYPE
#define YY_AnalitzadorSintactic_LTYPE YYLTYPE
#endif
#endif
#ifdef YYSTYPE
#ifndef YY_AnalitzadorSintactic_STYPE 
#define YY_AnalitzadorSintactic_STYPE YYSTYPE
#endif
#endif
#ifdef YYDEBUG
#ifndef YY_AnalitzadorSintactic_DEBUG
#define  YY_AnalitzadorSintactic_DEBUG YYDEBUG
#endif
#endif
#ifdef YY_AnalitzadorSintactic_STYPE
#ifndef yystype
#define yystype YY_AnalitzadorSintactic_STYPE
#endif
#endif
#endif

#ifndef YY_AnalitzadorSintactic_PURE

/* #line 112 "/usr/local/lib/bison.cc" */

#line 112 "/usr/local/lib/bison.cc"
/*  YY_AnalitzadorSintactic_PURE */
#endif

/* section apres lecture def, avant lecture grammaire S2 */

/* #line 116 "/usr/local/lib/bison.cc" */

#line 116 "/usr/local/lib/bison.cc"
/* prefix */
#ifndef YY_AnalitzadorSintactic_DEBUG

/* #line 118 "/usr/local/lib/bison.cc" */

#line 118 "/usr/local/lib/bison.cc"
/* YY_AnalitzadorSintactic_DEBUG */
#endif


#ifndef YY_AnalitzadorSintactic_LSP_NEEDED

/* #line 123 "/usr/local/lib/bison.cc" */

#line 123 "/usr/local/lib/bison.cc"
 /* YY_AnalitzadorSintactic_LSP_NEEDED*/
#endif



/* DEFAULT LTYPE*/
#ifdef YY_AnalitzadorSintactic_LSP_NEEDED
#ifndef YY_AnalitzadorSintactic_LTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YY_AnalitzadorSintactic_LTYPE yyltype
#endif
#endif
/* DEFAULT STYPE*/
      /* We used to use `unsigned long' as YY_AnalitzadorSintactic_STYPE on MSDOS,
	 but it seems better to be consistent.
	 Most programs should declare their own type anyway.  */

#ifndef YY_AnalitzadorSintactic_STYPE
#define YY_AnalitzadorSintactic_STYPE int
#endif
/* DEFAULT MISCELANEOUS */
#ifndef YY_AnalitzadorSintactic_PARSE
#define YY_AnalitzadorSintactic_PARSE yyparse
#endif
#ifndef YY_AnalitzadorSintactic_LEX
#define YY_AnalitzadorSintactic_LEX yylex
#endif
#ifndef YY_AnalitzadorSintactic_LVAL
#define YY_AnalitzadorSintactic_LVAL yylval
#endif
#ifndef YY_AnalitzadorSintactic_LLOC
#define YY_AnalitzadorSintactic_LLOC yylloc
#endif
#ifndef YY_AnalitzadorSintactic_CHAR
#define YY_AnalitzadorSintactic_CHAR yychar
#endif
#ifndef YY_AnalitzadorSintactic_NERRS
#define YY_AnalitzadorSintactic_NERRS yynerrs
#endif
#ifndef YY_AnalitzadorSintactic_DEBUG_FLAG
#define YY_AnalitzadorSintactic_DEBUG_FLAG yydebug
#endif
#ifndef YY_AnalitzadorSintactic_ERROR
#define YY_AnalitzadorSintactic_ERROR yyerror
#endif
#ifndef YY_AnalitzadorSintactic_PARSE_PARAM
#ifndef __STDC__
#ifndef __cplusplus
#ifndef YY_USE_CLASS
#define YY_AnalitzadorSintactic_PARSE_PARAM
#ifndef YY_AnalitzadorSintactic_PARSE_PARAM_DEF
#define YY_AnalitzadorSintactic_PARSE_PARAM_DEF
#endif
#endif
#endif
#endif
#ifndef YY_AnalitzadorSintactic_PARSE_PARAM
#define YY_AnalitzadorSintactic_PARSE_PARAM void
#endif
#endif
/* TOKEN C */
#if YY_AnalitzadorSintactic_COMPATIBILITY != 0
/* backward compatibility */
#ifdef YY_AnalitzadorSintactic_LTYPE
#ifndef YYLTYPE
#define YYLTYPE YY_AnalitzadorSintactic_LTYPE
#else
/* WARNING obsolete !!! user defined YYLTYPE not reported into generated header */
#endif
#endif
#ifndef YYSTYPE
#define YYSTYPE YY_AnalitzadorSintactic_STYPE
#else
/* WARNING obsolete !!! user defined YYSTYPE not reported into generated header */
#endif
#ifdef YY_AnalitzadorSintactic_PURE
#ifndef YYPURE
#define YYPURE YY_AnalitzadorSintactic_PURE
#endif
#endif
#ifdef YY_AnalitzadorSintactic_DEBUG
#ifndef YYDEBUG
#define YYDEBUG YY_AnalitzadorSintactic_DEBUG 
#endif
#endif
#ifndef YY_AnalitzadorSintactic_ERROR_VERBOSE
#ifdef YYERROR_VERBOSE
#define YY_AnalitzadorSintactic_ERROR_VERBOSE YYERROR_VERBOSE
#endif
#endif
#ifndef YY_AnalitzadorSintactic_LSP_NEEDED
#ifdef YYLSP_NEEDED
#define YY_AnalitzadorSintactic_LSP_NEEDED YYLSP_NEEDED
#endif
#endif


/* #line 230 "/usr/local/lib/bison.cc" */
#define	TEXT_CONTINGUT	258
#define	MATEMATIC	259
#define	COMA	260
#define	IMATGE	261
#define	IMATGEFIG	262
#define	PO	263
#define	PT	264
#define	CT	265
#define	CO	266
#define	FP	267
#define	NL	268
#define	LINIA	269
#define	TAB	270
#define	POS_TAB	271
#define	HLINE	272
#define	A_A_OBERT	273
#define	A_A_TANCAT	274
#define	A_A_CIRCUM	275
#define	A_A_DIERESIS	276
#define	A_A_TILDE	277
#define	A_A_MACRON	278
#define	A_A_DOT	279
#define	A_A_BREVE	280
#define	A_A_CHECK	281
#define	A_A_HUNGARIAN	282
#define	A_A_TIE	283
#define	A_A_RING	284
#define	A_A_RING_M	285
#define	A_A_CEDILLA	286
#define	A_A_DOTUNDER	287
#define	A_A_BARUNDER	288
#define	A_A_VECTOR	289
#define	A_A_OBERT_M	290
#define	A_A_TANCAT_M	291
#define	A_A_CIRCUM_M	292
#define	A_A_DIERESIS_M	293
#define	A_A_TILDE_M	294
#define	A_A_AE_DIFTONG_M	295
#define	A_A_AE_DIFTONG	296
#define	A_A_MACRON_M	297
#define	A_A_DOT_M	298
#define	A_A_BREVE_M	299
#define	A_A_CHECK_M	300
#define	A_A_HUNGARIAN_M	301
#define	A_A_TIE_M	302
#define	A_A_CEDILLA_M	303
#define	A_A_DOTUNDER_M	304
#define	A_A_BARUNDER_M	305
#define	A_E_OBERT	306
#define	A_E_TANCAT	307
#define	A_E_CIRCUM	308
#define	A_E_DIERESIS	309
#define	A_E_TILDE	310
#define	A_E_MACRON	311
#define	A_E_DOT	312
#define	A_E_BREVE	313
#define	A_E_CHECK	314
#define	A_E_HUNGARIAN	315
#define	A_E_TIE	316
#define	A_E_CEDILLA	317
#define	A_E_DOTUNDER	318
#define	A_E_BARUNDER	319
#define	A_E_VECTOR	320
#define	A_E_OBERT_M	321
#define	A_E_TANCAT_M	322
#define	A_E_CIRCUM_M	323
#define	A_E_DIERESIS_M	324
#define	A_E_TILDE_M	325
#define	A_E_MACRON_M	326
#define	A_E_DOT_M	327
#define	A_E_BREVE_M	328
#define	A_E_CHECK_M	329
#define	A_E_HUNGARIAN_M	330
#define	A_E_TIE_M	331
#define	A_E_CEDILLA_M	332
#define	A_E_DOTUNDER_M	333
#define	A_E_BARUNDER_M	334
#define	A_I_OBERT	335
#define	A_I_TANCAT	336
#define	A_I_CIRCUM	337
#define	A_I_DIERESIS	338
#define	A_I_TILDE	339
#define	A_I_MACRON	340
#define	A_I_DOT	341
#define	A_I_BREVE	342
#define	A_I_CHECK	343
#define	A_I_HUNGARIAN	344
#define	A_I_TIE	345
#define	A_I_CEDILLA	346
#define	A_I_DOTUNDER	347
#define	A_I_BARUNDER	348
#define	A_I_VECTOR	349
#define	A_I_OBERT_M	350
#define	A_I_TANCAT_M	351
#define	A_I_CIRCUM_M	352
#define	A_I_DIERESIS_M	353
#define	A_I_TILDE_M	354
#define	A_I_MACRON_M	355
#define	A_I_DOT_M	356
#define	A_I_BREVE_M	357
#define	A_I_CHECK_M	358
#define	A_I_HUNGARIAN_M	359
#define	A_I_TIE_M	360
#define	A_I_CEDILLA_M	361
#define	A_I_DOTUNDER_M	362
#define	A_I_BARUNDER_M	363
#define	A_O_OBERT	364
#define	A_O_TANCAT	365
#define	A_O_CIRCUM	366
#define	A_O_DIERESIS	367
#define	A_O_TILDE	368
#define	A_O_MACRON	369
#define	A_O_DOT	370
#define	A_O_BREVE	371
#define	A_O_CHECK	372
#define	A_O_HUNGARIAN	373
#define	A_O_TIE	374
#define	A_O_CEDILLA	375
#define	A_O_DOTUNDER	376
#define	A_O_BARUNDER	377
#define	A_O_VECTOR	378
#define	A_O_OBERT_M	379
#define	A_O_TANCAT_M	380
#define	A_O_CIRCUM_M	381
#define	A_O_DIERESIS_M	382
#define	A_O_TILDE_M	383
#define	A_O_MACRON_M	384
#define	A_O_DOT_M	385
#define	A_O_BREVE_M	386
#define	A_O_CHECK_M	387
#define	A_O_HUNGARIAN_M	388
#define	A_O_TIE_M	389
#define	A_O_CEDILLA_M	390
#define	A_O_DOTUNDER_M	391
#define	A_O_BARUNDER_M	392
#define	A_U_OBERT	393
#define	A_U_TANCAT	394
#define	A_U_CIRCUM	395
#define	A_U_DIERESIS	396
#define	A_U_TILDE	397
#define	A_U_MACRON	398
#define	A_U_DOT	399
#define	A_U_BREVE	400
#define	A_U_CHECK	401
#define	A_U_HUNGARIAN	402
#define	A_U_TIE	403
#define	A_U_CEDILLA	404
#define	A_U_DOTUNDER	405
#define	A_U_BARUNDER	406
#define	A_U_VECTOR	407
#define	A_U_OBERT_M	408
#define	A_U_TANCAT_M	409
#define	A_U_CIRCUM_M	410
#define	A_U_DIERESIS_M	411
#define	A_U_TILDE_M	412
#define	A_U_MACRON_M	413
#define	A_U_DOT_M	414
#define	A_U_BREVE_M	415
#define	A_U_CHECK_M	416
#define	A_U_HUNGARIAN_M	417
#define	A_U_TIE_M	418
#define	A_U_CEDILLA_M	419
#define	A_U_DOTUNDER_M	420
#define	A_U_BARUNDER_M	421
#define	A_C_TRENCADA	422
#define	A_C_TRENCADA_M	423
#define	A_N_CEDILLA	424
#define	A_N_CEDILLA_M	425
#define	D_TEXT_TINY	426
#define	D_TEXT_SCRIPTSIZE	427
#define	D_TEXT_FOOTNOTESIZE	428
#define	D_TEXT_SMALL	429
#define	D_TEXT_NORMALSIZE	430
#define	D_TEXT_LARGE	431
#define	D_TEXT_LLARGE	432
#define	D_TEXT_LLLARGE	433
#define	D_TEXT_HUGE	434
#define	D_TEXT_HHUGE	435
#define	D_TEXT_IT	436
#define	D_TEXT_BF	437
#define	D_TEXT_TT	438
#define	D_TEXT_EM	439
#define	M_PACKAGE	440
#define	M_DOC_CLASS	441
#define	M_SECCIO	442
#define	M_SUBSECCIO	443
#define	M_SUBSUBSECCIO	444
#define	M_TEXT_EMF	445
#define	M_TEXT_NORMAL	446
#define	M_TEXT_ITALICA	447
#define	M_TEXT_BOLD	448
#define	M_TEXT_SUBR	449
#define	M_TEXT_SUP	450
#define	M_TEXT_MECANOGRAFIC	451
#define	M_LLISTA_DE_FIGURES	452
#define	M_LLISTA_DE_TAULES	453
#define	M_TAULA_DE_CONTINGUTS	454
#define	M_CAPITOL	455
#define	M_TITOL	456
#define	M_AUTOR	457
#define	M_AND	458
#define	M_DATA	459
#define	M_THANKS	460
#define	M_FER_TITOL	461
#define	M_PART	462
#define	M_ITEM	463
#define	M_SUBITEM	464
#define	M_PEU_DE_PAGINA	465
#define	M_ETIQUETA	466
#define	M_REFERENCIA	467
#define	M_PARAGRAF	468
#define	M_SUBPARAGRAF	469
#define	M_APENDIX	470
#define	M_CAPTION	471
#define	M_CITACIO	472
#define	M_ITEM_BIBLIOGRAFIC	473
#define	M_LINK	474
#define	M_TARGET	475
#define	M_HREF	476
#define	S_DOLLAR	477
#define	S_AMPERSAND	478
#define	S_TANPERCENT	479
#define	S_GUIOINF	480
#define	S_CLAUOBERTA	481
#define	S_CLAUTANCADA	482
#define	S_MENORQUE	483
#define	S_MAJORQUE	484
#define	S_CONTRABARRA	485
#define	S_BARRA	486
#define	S_PUNT	487
#define	S_DOBLECREUETA	488
#define	S_CREUETA	489
#define	S_PARAGRAF	490
#define	S_SECCIO	491
#define	S_COPYRIGHT	492
#define	S_CIRCUM	493
#define	S_TILDE	494
#define	S_REGISTRAT	495
#define	S_TRADEMARK	496
#define	S_AFEM	497
#define	S_OMASC	498
#define	S_SHARP	499
#define	S_DIFERENT	500
#define	S_MENOR_IGUAL	501
#define	S_MAJOR_IGUAL	502
#define	S_APROXIMAT	503
#define	S_IDENTIC	504
#define	S_INFINIT	505
#define	S_INTERSECCIO	506
#define	S_INTEGRAL	507
#define	S_ARREL_QUADRADA	508
#define	S_SUMATORI	509
#define	S_PRODUCTORI	510
#define	S_INCREMENT	511
#define	S_DIFERENCIAL	512
#define	INICI_DOC	513
#define	FI_DOC	514
#define	INICI_TITOL	515
#define	FI_TITOL	516
#define	INICI_ENUMERAT	517
#define	FI_ENUMERAT	518
#define	INICI_BIBLIOGRAFIA	519
#define	FI_BIBLIOGRAFIA	520
#define	INICI_ABSTRACT	521
#define	FI_ABSTRACT	522
#define	INICI_FIGURA	523
#define	FI_FIGURA	524
#define	INICI_TAULA	525
#define	FI_TAULA	526
#define	INICI_TABULAR	527
#define	FI_TABULAR	528
#define	INICI_EQUACIO	529
#define	FI_EQUACIO	530
#define	INICI_ITEMIZE	531
#define	FI_ITEMIZE	532
#define	INICI_ARRAY	533
#define	FI_ARRAY	534
#define	INICI_EQARRAY	535
#define	FI_EQARRAY	536
#define	INICI_TEOREMA	537
#define	FI_TEOREMA	538
#define	INICI_TEXT_CENTRAT	539
#define	FI_TEXT_CENTRAT	540
#define	INICI_TEXT_ESQ	541
#define	FI_TEXT_ESQ	542
#define	INICI_TEXT_DRETA	543
#define	FI_TEXT_DRETA	544
#define	INICI_VERS	545
#define	FI_VERS	546
#define	INICI_TABBING	547
#define	FI_TABBING	548
#define	INICI_RAWHTML	549
#define	FI_RAWHTML	550


#line 230 "/usr/local/lib/bison.cc"
 /* #defines tokens */
#else
/* CLASS */
#ifndef YY_AnalitzadorSintactic_CLASS
#define YY_AnalitzadorSintactic_CLASS AnalitzadorSintactic
#endif
#ifndef YY_AnalitzadorSintactic_INHERIT
#define YY_AnalitzadorSintactic_INHERIT
#endif
#ifndef YY_AnalitzadorSintactic_MEMBERS
#define YY_AnalitzadorSintactic_MEMBERS 
#endif
#ifndef YY_AnalitzadorSintactic_LEX_BODY
#define YY_AnalitzadorSintactic_LEX_BODY  
#endif
#ifndef YY_AnalitzadorSintactic_ERROR_BODY
#define YY_AnalitzadorSintactic_ERROR_BODY  
#endif
#ifndef YY_AnalitzadorSintactic_CONSTRUCTOR_PARAM
#define YY_AnalitzadorSintactic_CONSTRUCTOR_PARAM
#endif
#ifndef YY_AnalitzadorSintactic_CONSTRUCTOR_CODE
#define YY_AnalitzadorSintactic_CONSTRUCTOR_CODE
#endif
#ifndef YY_AnalitzadorSintactic_CONSTRUCTOR_INIT
#define YY_AnalitzadorSintactic_CONSTRUCTOR_INIT
#endif

class YY_AnalitzadorSintactic_CLASS YY_AnalitzadorSintactic_INHERIT
{
public: /* static const int token ... */

/* #line 261 "/usr/local/lib/bison.cc" */
static const int TEXT_CONTINGUT;
static const int MATEMATIC;
static const int COMA;
static const int IMATGE;
static const int IMATGEFIG;
static const int PO;
static const int PT;
static const int CT;
static const int CO;
static const int FP;
static const int NL;
static const int LINIA;
static const int TAB;
static const int POS_TAB;
static const int HLINE;
static const int A_A_OBERT;
static const int A_A_TANCAT;
static const int A_A_CIRCUM;
static const int A_A_DIERESIS;
static const int A_A_TILDE;
static const int A_A_MACRON;
static const int A_A_DOT;
static const int A_A_BREVE;
static const int A_A_CHECK;
static const int A_A_HUNGARIAN;
static const int A_A_TIE;
static const int A_A_RING;
static const int A_A_RING_M;
static const int A_A_CEDILLA;
static const int A_A_DOTUNDER;
static const int A_A_BARUNDER;
static const int A_A_VECTOR;
static const int A_A_OBERT_M;
static const int A_A_TANCAT_M;
static const int A_A_CIRCUM_M;
static const int A_A_DIERESIS_M;
static const int A_A_TILDE_M;
static const int A_A_AE_DIFTONG_M;
static const int A_A_AE_DIFTONG;
static const int A_A_MACRON_M;
static const int A_A_DOT_M;
static const int A_A_BREVE_M;
static const int A_A_CHECK_M;
static const int A_A_HUNGARIAN_M;
static const int A_A_TIE_M;
static const int A_A_CEDILLA_M;
static const int A_A_DOTUNDER_M;
static const int A_A_BARUNDER_M;
static const int A_E_OBERT;
static const int A_E_TANCAT;
static const int A_E_CIRCUM;
static const int A_E_DIERESIS;
static const int A_E_TILDE;
static const int A_E_MACRON;
static const int A_E_DOT;
static const int A_E_BREVE;
static const int A_E_CHECK;
static const int A_E_HUNGARIAN;
static const int A_E_TIE;
static const int A_E_CEDILLA;
static const int A_E_DOTUNDER;
static const int A_E_BARUNDER;
static const int A_E_VECTOR;
static const int A_E_OBERT_M;
static const int A_E_TANCAT_M;
static const int A_E_CIRCUM_M;
static const int A_E_DIERESIS_M;
static const int A_E_TILDE_M;
static const int A_E_MACRON_M;
static const int A_E_DOT_M;
static const int A_E_BREVE_M;
static const int A_E_CHECK_M;
static const int A_E_HUNGARIAN_M;
static const int A_E_TIE_M;
static const int A_E_CEDILLA_M;
static const int A_E_DOTUNDER_M;
static const int A_E_BARUNDER_M;
static const int A_I_OBERT;
static const int A_I_TANCAT;
static const int A_I_CIRCUM;
static const int A_I_DIERESIS;
static const int A_I_TILDE;
static const int A_I_MACRON;
static const int A_I_DOT;
static const int A_I_BREVE;
static const int A_I_CHECK;
static const int A_I_HUNGARIAN;
static const int A_I_TIE;
static const int A_I_CEDILLA;
static const int A_I_DOTUNDER;
static const int A_I_BARUNDER;
static const int A_I_VECTOR;
static const int A_I_OBERT_M;
static const int A_I_TANCAT_M;
static const int A_I_CIRCUM_M;
static const int A_I_DIERESIS_M;
static const int A_I_TILDE_M;
static const int A_I_MACRON_M;
static const int A_I_DOT_M;
static const int A_I_BREVE_M;
static const int A_I_CHECK_M;
static const int A_I_HUNGARIAN_M;
static const int A_I_TIE_M;
static const int A_I_CEDILLA_M;
static const int A_I_DOTUNDER_M;
static const int A_I_BARUNDER_M;
static const int A_O_OBERT;
static const int A_O_TANCAT;
static const int A_O_CIRCUM;
static const int A_O_DIERESIS;
static const int A_O_TILDE;
static const int A_O_MACRON;
static const int A_O_DOT;
static const int A_O_BREVE;
static const int A_O_CHECK;
static const int A_O_HUNGARIAN;
static const int A_O_TIE;
static const int A_O_CEDILLA;
static const int A_O_DOTUNDER;
static const int A_O_BARUNDER;
static const int A_O_VECTOR;
static const int A_O_OBERT_M;
static const int A_O_TANCAT_M;
static const int A_O_CIRCUM_M;
static const int A_O_DIERESIS_M;
static const int A_O_TILDE_M;
static const int A_O_MACRON_M;
static const int A_O_DOT_M;
static const int A_O_BREVE_M;
static const int A_O_CHECK_M;
static const int A_O_HUNGARIAN_M;
static const int A_O_TIE_M;
static const int A_O_CEDILLA_M;
static const int A_O_DOTUNDER_M;
static const int A_O_BARUNDER_M;
static const int A_U_OBERT;
static const int A_U_TANCAT;
static const int A_U_CIRCUM;
static const int A_U_DIERESIS;
static const int A_U_TILDE;
static const int A_U_MACRON;
static const int A_U_DOT;
static const int A_U_BREVE;
static const int A_U_CHECK;
static const int A_U_HUNGARIAN;
static const int A_U_TIE;
static const int A_U_CEDILLA;
static const int A_U_DOTUNDER;
static const int A_U_BARUNDER;
static const int A_U_VECTOR;
static const int A_U_OBERT_M;
static const int A_U_TANCAT_M;
static const int A_U_CIRCUM_M;
static const int A_U_DIERESIS_M;
static const int A_U_TILDE_M;
static const int A_U_MACRON_M;
static const int A_U_DOT_M;
static const int A_U_BREVE_M;
static const int A_U_CHECK_M;
static const int A_U_HUNGARIAN_M;
static const int A_U_TIE_M;
static const int A_U_CEDILLA_M;
static const int A_U_DOTUNDER_M;
static const int A_U_BARUNDER_M;
static const int A_C_TRENCADA;
static const int A_C_TRENCADA_M;
static const int A_N_CEDILLA;
static const int A_N_CEDILLA_M;
static const int D_TEXT_TINY;
static const int D_TEXT_SCRIPTSIZE;
static const int D_TEXT_FOOTNOTESIZE;
static const int D_TEXT_SMALL;
static const int D_TEXT_NORMALSIZE;
static const int D_TEXT_LARGE;
static const int D_TEXT_LLARGE;
static const int D_TEXT_LLLARGE;
static const int D_TEXT_HUGE;
static const int D_TEXT_HHUGE;
static const int D_TEXT_IT;
static const int D_TEXT_BF;
static const int D_TEXT_TT;
static const int D_TEXT_EM;
static const int M_PACKAGE;
static const int M_DOC_CLASS;
static const int M_SECCIO;
static const int M_SUBSECCIO;
static const int M_SUBSUBSECCIO;
static const int M_TEXT_EMF;
static const int M_TEXT_NORMAL;
static const int M_TEXT_ITALICA;
static const int M_TEXT_BOLD;
static const int M_TEXT_SUBR;
static const int M_TEXT_SUP;
static const int M_TEXT_MECANOGRAFIC;
static const int M_LLISTA_DE_FIGURES;
static const int M_LLISTA_DE_TAULES;
static const int M_TAULA_DE_CONTINGUTS;
static const int M_CAPITOL;
static const int M_TITOL;
static const int M_AUTOR;
static const int M_AND;
static const int M_DATA;
static const int M_THANKS;
static const int M_FER_TITOL;
static const int M_PART;
static const int M_ITEM;
static const int M_SUBITEM;
static const int M_PEU_DE_PAGINA;
static const int M_ETIQUETA;
static const int M_REFERENCIA;
static const int M_PARAGRAF;
static const int M_SUBPARAGRAF;
static const int M_APENDIX;
static const int M_CAPTION;
static const int M_CITACIO;
static const int M_ITEM_BIBLIOGRAFIC;
static const int M_LINK;
static const int M_TARGET;
static const int M_HREF;
static const int S_DOLLAR;
static const int S_AMPERSAND;
static const int S_TANPERCENT;
static const int S_GUIOINF;
static const int S_CLAUOBERTA;
static const int S_CLAUTANCADA;
static const int S_MENORQUE;
static const int S_MAJORQUE;
static const int S_CONTRABARRA;
static const int S_BARRA;
static const int S_PUNT;
static const int S_DOBLECREUETA;
static const int S_CREUETA;
static const int S_PARAGRAF;
static const int S_SECCIO;
static const int S_COPYRIGHT;
static const int S_CIRCUM;
static const int S_TILDE;
static const int S_REGISTRAT;
static const int S_TRADEMARK;
static const int S_AFEM;
static const int S_OMASC;
static const int S_SHARP;
static const int S_DIFERENT;
static const int S_MENOR_IGUAL;
static const int S_MAJOR_IGUAL;
static const int S_APROXIMAT;
static const int S_IDENTIC;
static const int S_INFINIT;
static const int S_INTERSECCIO;
static const int S_INTEGRAL;
static const int S_ARREL_QUADRADA;
static const int S_SUMATORI;
static const int S_PRODUCTORI;
static const int S_INCREMENT;
static const int S_DIFERENCIAL;
static const int INICI_DOC;
static const int FI_DOC;
static const int INICI_TITOL;
static const int FI_TITOL;
static const int INICI_ENUMERAT;
static const int FI_ENUMERAT;
static const int INICI_BIBLIOGRAFIA;
static const int FI_BIBLIOGRAFIA;
static const int INICI_ABSTRACT;
static const int FI_ABSTRACT;
static const int INICI_FIGURA;
static const int FI_FIGURA;
static const int INICI_TAULA;
static const int FI_TAULA;
static const int INICI_TABULAR;
static const int FI_TABULAR;
static const int INICI_EQUACIO;
static const int FI_EQUACIO;
static const int INICI_ITEMIZE;
static const int FI_ITEMIZE;
static const int INICI_ARRAY;
static const int FI_ARRAY;
static const int INICI_EQARRAY;
static const int FI_EQARRAY;
static const int INICI_TEOREMA;
static const int FI_TEOREMA;
static const int INICI_TEXT_CENTRAT;
static const int FI_TEXT_CENTRAT;
static const int INICI_TEXT_ESQ;
static const int FI_TEXT_ESQ;
static const int INICI_TEXT_DRETA;
static const int FI_TEXT_DRETA;
static const int INICI_VERS;
static const int FI_VERS;
static const int INICI_TABBING;
static const int FI_TABBING;
static const int INICI_RAWHTML;
static const int FI_RAWHTML;


#line 261 "/usr/local/lib/bison.cc"
 /* decl const */
public:
 int YY_AnalitzadorSintactic_PARSE (YY_AnalitzadorSintactic_PARSE_PARAM);
 virtual void YY_AnalitzadorSintactic_ERROR(char *msg) YY_AnalitzadorSintactic_ERROR_BODY;
#ifdef YY_AnalitzadorSintactic_PURE
#ifdef YY_AnalitzadorSintactic_LSP_NEEDED
 virtual int  YY_AnalitzadorSintactic_LEX (YY_AnalitzadorSintactic_STYPE *YY_AnalitzadorSintactic_LVAL,YY_AnalitzadorSintactic_LTYPE *YY_AnalitzadorSintactic_LLOC) YY_AnalitzadorSintactic_LEX_BODY;
#else
 virtual int  YY_AnalitzadorSintactic_LEX (YY_AnalitzadorSintactic_STYPE *YY_AnalitzadorSintactic_LVAL) YY_AnalitzadorSintactic_LEX_BODY;
#endif
#else
 virtual int YY_AnalitzadorSintactic_LEX() YY_AnalitzadorSintactic_LEX_BODY;
 YY_AnalitzadorSintactic_STYPE YY_AnalitzadorSintactic_LVAL;
#ifdef YY_AnalitzadorSintactic_LSP_NEEDED
 YY_AnalitzadorSintactic_LTYPE YY_AnalitzadorSintactic_LLOC;
#endif
 int   YY_AnalitzadorSintactic_NERRS;
 int    YY_AnalitzadorSintactic_CHAR;
#endif
#if YY_AnalitzadorSintactic_DEBUG != 0
 int YY_AnalitzadorSintactic_DEBUG_FLAG;   /*  nonzero means print parse trace     */
#endif
public:
 YY_AnalitzadorSintactic_CLASS(YY_AnalitzadorSintactic_CONSTRUCTOR_PARAM);
public:
 YY_AnalitzadorSintactic_MEMBERS 
};
/* other declare folow */

/* #line 289 "/usr/local/lib/bison.cc" */
const int YY_AnalitzadorSintactic_CLASS::TEXT_CONTINGUT=258;
const int YY_AnalitzadorSintactic_CLASS::MATEMATIC=259;
const int YY_AnalitzadorSintactic_CLASS::COMA=260;
const int YY_AnalitzadorSintactic_CLASS::IMATGE=261;
const int YY_AnalitzadorSintactic_CLASS::IMATGEFIG=262;
const int YY_AnalitzadorSintactic_CLASS::PO=263;
const int YY_AnalitzadorSintactic_CLASS::PT=264;
const int YY_AnalitzadorSintactic_CLASS::CT=265;
const int YY_AnalitzadorSintactic_CLASS::CO=266;
const int YY_AnalitzadorSintactic_CLASS::FP=267;
const int YY_AnalitzadorSintactic_CLASS::NL=268;
const int YY_AnalitzadorSintactic_CLASS::LINIA=269;
const int YY_AnalitzadorSintactic_CLASS::TAB=270;
const int YY_AnalitzadorSintactic_CLASS::POS_TAB=271;
const int YY_AnalitzadorSintactic_CLASS::HLINE=272;
const int YY_AnalitzadorSintactic_CLASS::A_A_OBERT=273;
const int YY_AnalitzadorSintactic_CLASS::A_A_TANCAT=274;
const int YY_AnalitzadorSintactic_CLASS::A_A_CIRCUM=275;
const int YY_AnalitzadorSintactic_CLASS::A_A_DIERESIS=276;
const int YY_AnalitzadorSintactic_CLASS::A_A_TILDE=277;
const int YY_AnalitzadorSintactic_CLASS::A_A_MACRON=278;
const int YY_AnalitzadorSintactic_CLASS::A_A_DOT=279;
const int YY_AnalitzadorSintactic_CLASS::A_A_BREVE=280;
const int YY_AnalitzadorSintactic_CLASS::A_A_CHECK=281;
const int YY_AnalitzadorSintactic_CLASS::A_A_HUNGARIAN=282;
const int YY_AnalitzadorSintactic_CLASS::A_A_TIE=283;
const int YY_AnalitzadorSintactic_CLASS::A_A_RING=284;
const int YY_AnalitzadorSintactic_CLASS::A_A_RING_M=285;
const int YY_AnalitzadorSintactic_CLASS::A_A_CEDILLA=286;
const int YY_AnalitzadorSintactic_CLASS::A_A_DOTUNDER=287;
const int YY_AnalitzadorSintactic_CLASS::A_A_BARUNDER=288;
const int YY_AnalitzadorSintactic_CLASS::A_A_VECTOR=289;
const int YY_AnalitzadorSintactic_CLASS::A_A_OBERT_M=290;
const int YY_AnalitzadorSintactic_CLASS::A_A_TANCAT_M=291;
const int YY_AnalitzadorSintactic_CLASS::A_A_CIRCUM_M=292;
const int YY_AnalitzadorSintactic_CLASS::A_A_DIERESIS_M=293;
const int YY_AnalitzadorSintactic_CLASS::A_A_TILDE_M=294;
const int YY_AnalitzadorSintactic_CLASS::A_A_AE_DIFTONG_M=295;
const int YY_AnalitzadorSintactic_CLASS::A_A_AE_DIFTONG=296;
const int YY_AnalitzadorSintactic_CLASS::A_A_MACRON_M=297;
const int YY_AnalitzadorSintactic_CLASS::A_A_DOT_M=298;
const int YY_AnalitzadorSintactic_CLASS::A_A_BREVE_M=299;
const int YY_AnalitzadorSintactic_CLASS::A_A_CHECK_M=300;
const int YY_AnalitzadorSintactic_CLASS::A_A_HUNGARIAN_M=301;
const int YY_AnalitzadorSintactic_CLASS::A_A_TIE_M=302;
const int YY_AnalitzadorSintactic_CLASS::A_A_CEDILLA_M=303;
const int YY_AnalitzadorSintactic_CLASS::A_A_DOTUNDER_M=304;
const int YY_AnalitzadorSintactic_CLASS::A_A_BARUNDER_M=305;
const int YY_AnalitzadorSintactic_CLASS::A_E_OBERT=306;
const int YY_AnalitzadorSintactic_CLASS::A_E_TANCAT=307;
const int YY_AnalitzadorSintactic_CLASS::A_E_CIRCUM=308;
const int YY_AnalitzadorSintactic_CLASS::A_E_DIERESIS=309;
const int YY_AnalitzadorSintactic_CLASS::A_E_TILDE=310;
const int YY_AnalitzadorSintactic_CLASS::A_E_MACRON=311;
const int YY_AnalitzadorSintactic_CLASS::A_E_DOT=312;
const int YY_AnalitzadorSintactic_CLASS::A_E_BREVE=313;
const int YY_AnalitzadorSintactic_CLASS::A_E_CHECK=314;
const int YY_AnalitzadorSintactic_CLASS::A_E_HUNGARIAN=315;
const int YY_AnalitzadorSintactic_CLASS::A_E_TIE=316;
const int YY_AnalitzadorSintactic_CLASS::A_E_CEDILLA=317;
const int YY_AnalitzadorSintactic_CLASS::A_E_DOTUNDER=318;
const int YY_AnalitzadorSintactic_CLASS::A_E_BARUNDER=319;
const int YY_AnalitzadorSintactic_CLASS::A_E_VECTOR=320;
const int YY_AnalitzadorSintactic_CLASS::A_E_OBERT_M=321;
const int YY_AnalitzadorSintactic_CLASS::A_E_TANCAT_M=322;
const int YY_AnalitzadorSintactic_CLASS::A_E_CIRCUM_M=323;
const int YY_AnalitzadorSintactic_CLASS::A_E_DIERESIS_M=324;
const int YY_AnalitzadorSintactic_CLASS::A_E_TILDE_M=325;
const int YY_AnalitzadorSintactic_CLASS::A_E_MACRON_M=326;
const int YY_AnalitzadorSintactic_CLASS::A_E_DOT_M=327;
const int YY_AnalitzadorSintactic_CLASS::A_E_BREVE_M=328;
const int YY_AnalitzadorSintactic_CLASS::A_E_CHECK_M=329;
const int YY_AnalitzadorSintactic_CLASS::A_E_HUNGARIAN_M=330;
const int YY_AnalitzadorSintactic_CLASS::A_E_TIE_M=331;
const int YY_AnalitzadorSintactic_CLASS::A_E_CEDILLA_M=332;
const int YY_AnalitzadorSintactic_CLASS::A_E_DOTUNDER_M=333;
const int YY_AnalitzadorSintactic_CLASS::A_E_BARUNDER_M=334;
const int YY_AnalitzadorSintactic_CLASS::A_I_OBERT=335;
const int YY_AnalitzadorSintactic_CLASS::A_I_TANCAT=336;
const int YY_AnalitzadorSintactic_CLASS::A_I_CIRCUM=337;
const int YY_AnalitzadorSintactic_CLASS::A_I_DIERESIS=338;
const int YY_AnalitzadorSintactic_CLASS::A_I_TILDE=339;
const int YY_AnalitzadorSintactic_CLASS::A_I_MACRON=340;
const int YY_AnalitzadorSintactic_CLASS::A_I_DOT=341;
const int YY_AnalitzadorSintactic_CLASS::A_I_BREVE=342;
const int YY_AnalitzadorSintactic_CLASS::A_I_CHECK=343;
const int YY_AnalitzadorSintactic_CLASS::A_I_HUNGARIAN=344;
const int YY_AnalitzadorSintactic_CLASS::A_I_TIE=345;
const int YY_AnalitzadorSintactic_CLASS::A_I_CEDILLA=346;
const int YY_AnalitzadorSintactic_CLASS::A_I_DOTUNDER=347;
const int YY_AnalitzadorSintactic_CLASS::A_I_BARUNDER=348;
const int YY_AnalitzadorSintactic_CLASS::A_I_VECTOR=349;
const int YY_AnalitzadorSintactic_CLASS::A_I_OBERT_M=350;
const int YY_AnalitzadorSintactic_CLASS::A_I_TANCAT_M=351;
const int YY_AnalitzadorSintactic_CLASS::A_I_CIRCUM_M=352;
const int YY_AnalitzadorSintactic_CLASS::A_I_DIERESIS_M=353;
const int YY_AnalitzadorSintactic_CLASS::A_I_TILDE_M=354;
const int YY_AnalitzadorSintactic_CLASS::A_I_MACRON_M=355;
const int YY_AnalitzadorSintactic_CLASS::A_I_DOT_M=356;
const int YY_AnalitzadorSintactic_CLASS::A_I_BREVE_M=357;
const int YY_AnalitzadorSintactic_CLASS::A_I_CHECK_M=358;
const int YY_AnalitzadorSintactic_CLASS::A_I_HUNGARIAN_M=359;
const int YY_AnalitzadorSintactic_CLASS::A_I_TIE_M=360;
const int YY_AnalitzadorSintactic_CLASS::A_I_CEDILLA_M=361;
const int YY_AnalitzadorSintactic_CLASS::A_I_DOTUNDER_M=362;
const int YY_AnalitzadorSintactic_CLASS::A_I_BARUNDER_M=363;
const int YY_AnalitzadorSintactic_CLASS::A_O_OBERT=364;
const int YY_AnalitzadorSintactic_CLASS::A_O_TANCAT=365;
const int YY_AnalitzadorSintactic_CLASS::A_O_CIRCUM=366;
const int YY_AnalitzadorSintactic_CLASS::A_O_DIERESIS=367;
const int YY_AnalitzadorSintactic_CLASS::A_O_TILDE=368;
const int YY_AnalitzadorSintactic_CLASS::A_O_MACRON=369;
const int YY_AnalitzadorSintactic_CLASS::A_O_DOT=370;
const int YY_AnalitzadorSintactic_CLASS::A_O_BREVE=371;
const int YY_AnalitzadorSintactic_CLASS::A_O_CHECK=372;
const int YY_AnalitzadorSintactic_CLASS::A_O_HUNGARIAN=373;
const int YY_AnalitzadorSintactic_CLASS::A_O_TIE=374;
const int YY_AnalitzadorSintactic_CLASS::A_O_CEDILLA=375;
const int YY_AnalitzadorSintactic_CLASS::A_O_DOTUNDER=376;
const int YY_AnalitzadorSintactic_CLASS::A_O_BARUNDER=377;
const int YY_AnalitzadorSintactic_CLASS::A_O_VECTOR=378;
const int YY_AnalitzadorSintactic_CLASS::A_O_OBERT_M=379;
const int YY_AnalitzadorSintactic_CLASS::A_O_TANCAT_M=380;
const int YY_AnalitzadorSintactic_CLASS::A_O_CIRCUM_M=381;
const int YY_AnalitzadorSintactic_CLASS::A_O_DIERESIS_M=382;
const int YY_AnalitzadorSintactic_CLASS::A_O_TILDE_M=383;
const int YY_AnalitzadorSintactic_CLASS::A_O_MACRON_M=384;
const int YY_AnalitzadorSintactic_CLASS::A_O_DOT_M=385;
const int YY_AnalitzadorSintactic_CLASS::A_O_BREVE_M=386;
const int YY_AnalitzadorSintactic_CLASS::A_O_CHECK_M=387;
const int YY_AnalitzadorSintactic_CLASS::A_O_HUNGARIAN_M=388;
const int YY_AnalitzadorSintactic_CLASS::A_O_TIE_M=389;
const int YY_AnalitzadorSintactic_CLASS::A_O_CEDILLA_M=390;
const int YY_AnalitzadorSintactic_CLASS::A_O_DOTUNDER_M=391;
const int YY_AnalitzadorSintactic_CLASS::A_O_BARUNDER_M=392;
const int YY_AnalitzadorSintactic_CLASS::A_U_OBERT=393;
const int YY_AnalitzadorSintactic_CLASS::A_U_TANCAT=394;
const int YY_AnalitzadorSintactic_CLASS::A_U_CIRCUM=395;
const int YY_AnalitzadorSintactic_CLASS::A_U_DIERESIS=396;
const int YY_AnalitzadorSintactic_CLASS::A_U_TILDE=397;
const int YY_AnalitzadorSintactic_CLASS::A_U_MACRON=398;
const int YY_AnalitzadorSintactic_CLASS::A_U_DOT=399;
const int YY_AnalitzadorSintactic_CLASS::A_U_BREVE=400;
const int YY_AnalitzadorSintactic_CLASS::A_U_CHECK=401;
const int YY_AnalitzadorSintactic_CLASS::A_U_HUNGARIAN=402;
const int YY_AnalitzadorSintactic_CLASS::A_U_TIE=403;
const int YY_AnalitzadorSintactic_CLASS::A_U_CEDILLA=404;
const int YY_AnalitzadorSintactic_CLASS::A_U_DOTUNDER=405;
const int YY_AnalitzadorSintactic_CLASS::A_U_BARUNDER=406;
const int YY_AnalitzadorSintactic_CLASS::A_U_VECTOR=407;
const int YY_AnalitzadorSintactic_CLASS::A_U_OBERT_M=408;
const int YY_AnalitzadorSintactic_CLASS::A_U_TANCAT_M=409;
const int YY_AnalitzadorSintactic_CLASS::A_U_CIRCUM_M=410;
const int YY_AnalitzadorSintactic_CLASS::A_U_DIERESIS_M=411;
const int YY_AnalitzadorSintactic_CLASS::A_U_TILDE_M=412;
const int YY_AnalitzadorSintactic_CLASS::A_U_MACRON_M=413;
const int YY_AnalitzadorSintactic_CLASS::A_U_DOT_M=414;
const int YY_AnalitzadorSintactic_CLASS::A_U_BREVE_M=415;
const int YY_AnalitzadorSintactic_CLASS::A_U_CHECK_M=416;
const int YY_AnalitzadorSintactic_CLASS::A_U_HUNGARIAN_M=417;
const int YY_AnalitzadorSintactic_CLASS::A_U_TIE_M=418;
const int YY_AnalitzadorSintactic_CLASS::A_U_CEDILLA_M=419;
const int YY_AnalitzadorSintactic_CLASS::A_U_DOTUNDER_M=420;
const int YY_AnalitzadorSintactic_CLASS::A_U_BARUNDER_M=421;
const int YY_AnalitzadorSintactic_CLASS::A_C_TRENCADA=422;
const int YY_AnalitzadorSintactic_CLASS::A_C_TRENCADA_M=423;
const int YY_AnalitzadorSintactic_CLASS::A_N_CEDILLA=424;
const int YY_AnalitzadorSintactic_CLASS::A_N_CEDILLA_M=425;
const int YY_AnalitzadorSintactic_CLASS::D_TEXT_TINY=426;
const int YY_AnalitzadorSintactic_CLASS::D_TEXT_SCRIPTSIZE=427;
const int YY_AnalitzadorSintactic_CLASS::D_TEXT_FOOTNOTESIZE=428;
const int YY_AnalitzadorSintactic_CLASS::D_TEXT_SMALL=429;
const int YY_AnalitzadorSintactic_CLASS::D_TEXT_NORMALSIZE=430;
const int YY_AnalitzadorSintactic_CLASS::D_TEXT_LARGE=431;
const int YY_AnalitzadorSintactic_CLASS::D_TEXT_LLARGE=432;
const int YY_AnalitzadorSintactic_CLASS::D_TEXT_LLLARGE=433;
const int YY_AnalitzadorSintactic_CLASS::D_TEXT_HUGE=434;
const int YY_AnalitzadorSintactic_CLASS::D_TEXT_HHUGE=435;
const int YY_AnalitzadorSintactic_CLASS::D_TEXT_IT=436;
const int YY_AnalitzadorSintactic_CLASS::D_TEXT_BF=437;
const int YY_AnalitzadorSintactic_CLASS::D_TEXT_TT=438;
const int YY_AnalitzadorSintactic_CLASS::D_TEXT_EM=439;
const int YY_AnalitzadorSintactic_CLASS::M_PACKAGE=440;
const int YY_AnalitzadorSintactic_CLASS::M_DOC_CLASS=441;
const int YY_AnalitzadorSintactic_CLASS::M_SECCIO=442;
const int YY_AnalitzadorSintactic_CLASS::M_SUBSECCIO=443;
const int YY_AnalitzadorSintactic_CLASS::M_SUBSUBSECCIO=444;
const int YY_AnalitzadorSintactic_CLASS::M_TEXT_EMF=445;
const int YY_AnalitzadorSintactic_CLASS::M_TEXT_NORMAL=446;
const int YY_AnalitzadorSintactic_CLASS::M_TEXT_ITALICA=447;
const int YY_AnalitzadorSintactic_CLASS::M_TEXT_BOLD=448;
const int YY_AnalitzadorSintactic_CLASS::M_TEXT_SUBR=449;
const int YY_AnalitzadorSintactic_CLASS::M_TEXT_SUP=450;
const int YY_AnalitzadorSintactic_CLASS::M_TEXT_MECANOGRAFIC=451;
const int YY_AnalitzadorSintactic_CLASS::M_LLISTA_DE_FIGURES=452;
const int YY_AnalitzadorSintactic_CLASS::M_LLISTA_DE_TAULES=453;
const int YY_AnalitzadorSintactic_CLASS::M_TAULA_DE_CONTINGUTS=454;
const int YY_AnalitzadorSintactic_CLASS::M_CAPITOL=455;
const int YY_AnalitzadorSintactic_CLASS::M_TITOL=456;
const int YY_AnalitzadorSintactic_CLASS::M_AUTOR=457;
const int YY_AnalitzadorSintactic_CLASS::M_AND=458;
const int YY_AnalitzadorSintactic_CLASS::M_DATA=459;
const int YY_AnalitzadorSintactic_CLASS::M_THANKS=460;
const int YY_AnalitzadorSintactic_CLASS::M_FER_TITOL=461;
const int YY_AnalitzadorSintactic_CLASS::M_PART=462;
const int YY_AnalitzadorSintactic_CLASS::M_ITEM=463;
const int YY_AnalitzadorSintactic_CLASS::M_SUBITEM=464;
const int YY_AnalitzadorSintactic_CLASS::M_PEU_DE_PAGINA=465;
const int YY_AnalitzadorSintactic_CLASS::M_ETIQUETA=466;
const int YY_AnalitzadorSintactic_CLASS::M_REFERENCIA=467;
const int YY_AnalitzadorSintactic_CLASS::M_PARAGRAF=468;
const int YY_AnalitzadorSintactic_CLASS::M_SUBPARAGRAF=469;
const int YY_AnalitzadorSintactic_CLASS::M_APENDIX=470;
const int YY_AnalitzadorSintactic_CLASS::M_CAPTION=471;
const int YY_AnalitzadorSintactic_CLASS::M_CITACIO=472;
const int YY_AnalitzadorSintactic_CLASS::M_ITEM_BIBLIOGRAFIC=473;
const int YY_AnalitzadorSintactic_CLASS::M_LINK=474;
const int YY_AnalitzadorSintactic_CLASS::M_TARGET=475;
const int YY_AnalitzadorSintactic_CLASS::M_HREF=476;
const int YY_AnalitzadorSintactic_CLASS::S_DOLLAR=477;
const int YY_AnalitzadorSintactic_CLASS::S_AMPERSAND=478;
const int YY_AnalitzadorSintactic_CLASS::S_TANPERCENT=479;
const int YY_AnalitzadorSintactic_CLASS::S_GUIOINF=480;
const int YY_AnalitzadorSintactic_CLASS::S_CLAUOBERTA=481;
const int YY_AnalitzadorSintactic_CLASS::S_CLAUTANCADA=482;
const int YY_AnalitzadorSintactic_CLASS::S_MENORQUE=483;
const int YY_AnalitzadorSintactic_CLASS::S_MAJORQUE=484;
const int YY_AnalitzadorSintactic_CLASS::S_CONTRABARRA=485;
const int YY_AnalitzadorSintactic_CLASS::S_BARRA=486;
const int YY_AnalitzadorSintactic_CLASS::S_PUNT=487;
const int YY_AnalitzadorSintactic_CLASS::S_DOBLECREUETA=488;
const int YY_AnalitzadorSintactic_CLASS::S_CREUETA=489;
const int YY_AnalitzadorSintactic_CLASS::S_PARAGRAF=490;
const int YY_AnalitzadorSintactic_CLASS::S_SECCIO=491;
const int YY_AnalitzadorSintactic_CLASS::S_COPYRIGHT=492;
const int YY_AnalitzadorSintactic_CLASS::S_CIRCUM=493;
const int YY_AnalitzadorSintactic_CLASS::S_TILDE=494;
const int YY_AnalitzadorSintactic_CLASS::S_REGISTRAT=495;
const int YY_AnalitzadorSintactic_CLASS::S_TRADEMARK=496;
const int YY_AnalitzadorSintactic_CLASS::S_AFEM=497;
const int YY_AnalitzadorSintactic_CLASS::S_OMASC=498;
const int YY_AnalitzadorSintactic_CLASS::S_SHARP=499;
const int YY_AnalitzadorSintactic_CLASS::S_DIFERENT=500;
const int YY_AnalitzadorSintactic_CLASS::S_MENOR_IGUAL=501;
const int YY_AnalitzadorSintactic_CLASS::S_MAJOR_IGUAL=502;
const int YY_AnalitzadorSintactic_CLASS::S_APROXIMAT=503;
const int YY_AnalitzadorSintactic_CLASS::S_IDENTIC=504;
const int YY_AnalitzadorSintactic_CLASS::S_INFINIT=505;
const int YY_AnalitzadorSintactic_CLASS::S_INTERSECCIO=506;
const int YY_AnalitzadorSintactic_CLASS::S_INTEGRAL=507;
const int YY_AnalitzadorSintactic_CLASS::S_ARREL_QUADRADA=508;
const int YY_AnalitzadorSintactic_CLASS::S_SUMATORI=509;
const int YY_AnalitzadorSintactic_CLASS::S_PRODUCTORI=510;
const int YY_AnalitzadorSintactic_CLASS::S_INCREMENT=511;
const int YY_AnalitzadorSintactic_CLASS::S_DIFERENCIAL=512;
const int YY_AnalitzadorSintactic_CLASS::INICI_DOC=513;
const int YY_AnalitzadorSintactic_CLASS::FI_DOC=514;
const int YY_AnalitzadorSintactic_CLASS::INICI_TITOL=515;
const int YY_AnalitzadorSintactic_CLASS::FI_TITOL=516;
const int YY_AnalitzadorSintactic_CLASS::INICI_ENUMERAT=517;
const int YY_AnalitzadorSintactic_CLASS::FI_ENUMERAT=518;
const int YY_AnalitzadorSintactic_CLASS::INICI_BIBLIOGRAFIA=519;
const int YY_AnalitzadorSintactic_CLASS::FI_BIBLIOGRAFIA=520;
const int YY_AnalitzadorSintactic_CLASS::INICI_ABSTRACT=521;
const int YY_AnalitzadorSintactic_CLASS::FI_ABSTRACT=522;
const int YY_AnalitzadorSintactic_CLASS::INICI_FIGURA=523;
const int YY_AnalitzadorSintactic_CLASS::FI_FIGURA=524;
const int YY_AnalitzadorSintactic_CLASS::INICI_TAULA=525;
const int YY_AnalitzadorSintactic_CLASS::FI_TAULA=526;
const int YY_AnalitzadorSintactic_CLASS::INICI_TABULAR=527;
const int YY_AnalitzadorSintactic_CLASS::FI_TABULAR=528;
const int YY_AnalitzadorSintactic_CLASS::INICI_EQUACIO=529;
const int YY_AnalitzadorSintactic_CLASS::FI_EQUACIO=530;
const int YY_AnalitzadorSintactic_CLASS::INICI_ITEMIZE=531;
const int YY_AnalitzadorSintactic_CLASS::FI_ITEMIZE=532;
const int YY_AnalitzadorSintactic_CLASS::INICI_ARRAY=533;
const int YY_AnalitzadorSintactic_CLASS::FI_ARRAY=534;
const int YY_AnalitzadorSintactic_CLASS::INICI_EQARRAY=535;
const int YY_AnalitzadorSintactic_CLASS::FI_EQARRAY=536;
const int YY_AnalitzadorSintactic_CLASS::INICI_TEOREMA=537;
const int YY_AnalitzadorSintactic_CLASS::FI_TEOREMA=538;
const int YY_AnalitzadorSintactic_CLASS::INICI_TEXT_CENTRAT=539;
const int YY_AnalitzadorSintactic_CLASS::FI_TEXT_CENTRAT=540;
const int YY_AnalitzadorSintactic_CLASS::INICI_TEXT_ESQ=541;
const int YY_AnalitzadorSintactic_CLASS::FI_TEXT_ESQ=542;
const int YY_AnalitzadorSintactic_CLASS::INICI_TEXT_DRETA=543;
const int YY_AnalitzadorSintactic_CLASS::FI_TEXT_DRETA=544;
const int YY_AnalitzadorSintactic_CLASS::INICI_VERS=545;
const int YY_AnalitzadorSintactic_CLASS::FI_VERS=546;
const int YY_AnalitzadorSintactic_CLASS::INICI_TABBING=547;
const int YY_AnalitzadorSintactic_CLASS::FI_TABBING=548;
const int YY_AnalitzadorSintactic_CLASS::INICI_RAWHTML=549;
const int YY_AnalitzadorSintactic_CLASS::FI_RAWHTML=550;


#line 289 "/usr/local/lib/bison.cc"
 /* const YY_AnalitzadorSintactic_CLASS::token */
/*apres const  */
YY_AnalitzadorSintactic_CLASS::YY_AnalitzadorSintactic_CLASS(YY_AnalitzadorSintactic_CONSTRUCTOR_PARAM) YY_AnalitzadorSintactic_CONSTRUCTOR_INIT
{
#if YY_AnalitzadorSintactic_DEBUG != 0
YY_AnalitzadorSintactic_DEBUG_FLAG=0;
#endif
YY_AnalitzadorSintactic_CONSTRUCTOR_CODE;
};
#endif

/* #line 299 "/usr/local/lib/bison.cc" */


#define	YYFINAL		597
#define	YYFLAG		-32768
#define	YYNTBASE	296

#define YYTRANSLATE(x) ((unsigned)(x) <= 550 ? yytranslate[x] : 383)

static const short yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
    56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
    66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
    76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
    86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
    96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
   106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
   116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
   126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
   136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
   146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
   156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
   166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
   176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
   186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
   196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
   206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
   216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
   226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
   236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
   246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
   256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
   266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
   276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
   286,   287,   288,   289,   290,   291,   292,   293,   294,   295
};

#if YY_AnalitzadorSintactic_DEBUG != 0
static const short yyprhs[] = {     0,
     0,     3,     5,     8,    10,    18,    23,    26,    28,    30,
    32,    35,    37,    39,    40,    45,    46,    52,    53,    60,
    63,    65,    67,    69,    71,    73,    75,    78,    80,    82,
    84,    86,    88,    90,    92,    94,    96,    98,   100,   102,
   104,   106,   108,   110,   112,   114,   116,   118,   120,   122,
   124,   126,   128,   130,   132,   134,   136,   138,   140,   142,
   144,   146,   148,   150,   152,   154,   156,   158,   160,   163,
   172,   182,   188,   195,   199,   204,   207,   209,   211,   213,
   214,   219,   220,   229,   237,   245,   246,   251,   254,   260,
   267,   270,   272,   278,   285,   288,   290,   292,   296,   299,
   300,   305,   308,   309,   314,   318,   321,   324,   326,   330,
   333,   336,   338,   342,   345,   348,   350,   354,   357,   360,
   362,   365,   369,   373,   377,   381,   385,   389,   392,   394,
   399,   404,   408,   411,   414,   416,   419,   423,   427,   431,
   434,   437,   439,   442,   446,   450,   453,   455,   457,   462,
   470,   475,   480,   483,   487,   490,   494,   496,   498,   500,
   502,   504,   506,   508,   509,   513,   514,   520,   521,   527,
   528,   534,   535,   541,   542,   548,   549,   555,   563,   565,
   567,   569,   571,   573,   575,   577,   579,   581,   582,   587,
   590,   591,   596,   599,   600,   605,   608,   612,   615,   618,
   622,   625,   629,   632,   636,   639,   643,   646,   650,   658,
   663,   666,   669,   671,   673,   675,   680,   685,   690,   694,
   697,   699,   701,   706,   710,   712,   714,   716,   718,   720,
   722,   724,   726,   728,   730,   732,   734,   736,   738,   740,
   742,   744,   746,   748,   750,   752,   754,   756,   758,   760,
   762,   764,   766,   768,   770,   772,   774,   776,   778,   780,
   782,   784,   786,   788,   790,   792,   794,   796,   798,   800,
   802,   804,   806,   808,   810,   812,   814,   816,   818,   820,
   822,   824,   826,   828,   830,   832,   834,   836,   838,   840,
   842,   844,   846,   848,   850,   852,   854,   856,   858,   860,
   862,   864,   866,   868,   870,   872,   874,   876,   878,   880,
   882,   884,   886,   888,   890,   892,   894,   896,   898,   900,
   902,   904,   906,   908,   910,   912,   914,   916,   918,   920,
   922,   924,   926,   928,   930,   932,   934,   936,   938,   940,
   942,   944,   946,   948,   950,   952,   954,   956,   958,   960,
   962,   964,   966,   968,   970,   972,   974,   976,   978,   980,
   982,   984,   986,   988,   990,   992,   994,   996,   998,  1000,
  1002,  1004,  1006,  1008,  1010,  1012,  1014,  1016,  1018,  1020,
  1022,  1024,  1026,  1028,  1030,  1032,  1034,  1036,  1038,  1040,
  1042,  1044,  1046,  1048,  1050,  1052,  1054,  1056,  1058,  1060,
  1062,  1064,  1066,  1068,  1070,  1072,  1074,  1076,  1078,  1080,
  1082,  1084,  1086
};

static const short yyrhs[] = {   297,
   301,     0,   301,     0,   298,   300,     0,   298,     0,   186,
    11,   306,    10,     8,   306,     9,     0,   186,     8,   306,
     9,     0,   299,   299,     0,   377,     0,   378,     0,   380,
     0,   300,   300,     0,   299,     0,   374,     0,     0,   258,
   302,   305,   259,     0,     0,   258,   206,   303,   305,   259,
     0,     0,   258,   299,   206,   304,   305,   259,     0,   305,
   305,     0,   306,     0,   369,     0,   370,     0,   371,     0,
   372,     0,   373,     0,   306,   306,     0,     3,     0,     5,
     0,   382,     0,   345,     0,   362,     0,   364,     0,   366,
     0,   381,     0,   360,     0,   340,     0,   341,     0,   342,
     0,    12,     0,    13,     0,   332,     0,   320,     0,   330,
     0,   361,     0,   199,     0,   197,     0,   198,     0,   343,
     0,   344,     0,   331,     0,   335,     0,   338,     0,   329,
     0,   181,     0,   182,     0,   183,     0,   184,     0,   328,
     0,   322,     0,   368,     0,   319,     0,   316,     0,   314,
     0,   315,     0,   312,     0,   310,     0,   308,     0,   307,
   307,     0,   218,    11,   306,    10,     8,     3,     9,   306,
     0,   218,   306,    11,   306,    10,     8,     3,     9,   306,
     0,   218,     8,     3,     9,   306,     0,   218,   306,     8,
     3,     9,   306,     0,   264,   307,   265,     0,   264,   328,
   307,   265,     0,   309,   309,     0,    16,     0,    15,     0,
   306,     0,     0,   292,   311,   309,   293,     0,     0,   221,
   313,     8,     3,     9,     8,   306,     9,     0,   219,     8,
     3,     9,     8,   306,     9,     0,   220,     8,     3,     9,
     8,   306,     9,     0,     0,   294,   317,   306,   295,     0,
   318,   318,     0,   208,    11,   306,    10,   306,     0,   208,
   306,    11,   306,    10,   306,     0,   208,   306,     0,   208,
     0,   209,    11,   306,    10,   306,     0,   209,   306,    11,
   306,    10,   306,     0,   209,   306,     0,   209,     0,   306,
     0,   276,   318,   277,     0,   276,   277,     0,     0,   262,
   321,   318,   263,     0,   262,   263,     0,     0,   274,   323,
   306,   275,     0,   306,   181,   306,     0,   306,   181,     0,
   181,   306,     0,   181,     0,   306,   182,   306,     0,   306,
   182,     0,   182,   306,     0,   182,     0,   306,   183,   306,
     0,   306,   183,     0,   183,   306,     0,   183,     0,   306,
   184,   306,     0,   306,   184,     0,   184,   306,     0,   184,
     0,     8,     9,     0,     8,   306,     9,     0,     8,   324,
     9,     0,     8,   325,     9,     0,     8,   326,     9,     0,
     8,   327,     9,     0,   266,   306,   267,     0,   210,   328,
     0,     4,     0,     6,     8,   306,     9,     0,     7,     8,
   306,     9,     0,   306,   334,   306,     0,   334,   306,     0,
   306,   334,     0,   334,     0,   216,   328,     0,   268,   333,
   269,     0,   268,   306,   269,     0,   306,   337,   306,     0,
   337,   306,     0,   306,   337,     0,   337,     0,   216,   328,
     0,   270,   336,   271,     0,   270,   306,   271,     0,   339,
   339,     0,     5,     0,     3,     0,   217,     8,   339,     9,
     0,   217,    11,   306,    10,     8,   339,     9,     0,   211,
     8,   306,     9,     0,   212,     8,   306,     9,     0,   213,
   328,     0,   213,     8,     9,     0,   214,   328,     0,   214,
     8,     9,     0,   346,     0,   348,     0,   350,     0,   352,
     0,   356,     0,   358,     0,   354,     0,     0,   190,   347,
   328,     0,     0,   192,     8,   349,   306,     9,     0,     0,
   191,     8,   351,   306,     9,     0,     0,   193,     8,   353,
   306,     9,     0,     0,   196,     8,   355,   306,     9,     0,
     0,   194,     8,   357,   306,     9,     0,     0,   195,     8,
   359,   306,     9,     0,    14,     8,   306,     9,     8,   306,
     9,     0,   171,     0,   172,     0,   173,     0,   174,     0,
   175,     0,   176,     0,   177,     0,   179,     0,   180,     0,
     0,   284,   363,   306,   285,     0,   284,   285,     0,     0,
   286,   365,   306,   287,     0,   286,   287,     0,     0,   288,
   367,   306,   289,     0,   288,   289,     0,   260,   306,   261,
     0,   260,   261,     0,   207,   328,     0,   207,     8,     9,
     0,   200,   328,     0,   200,     8,     9,     0,   187,   328,
     0,   187,     8,     9,     0,   188,   328,     0,   188,     8,
     9,     0,   189,   328,     0,   189,     8,     9,     0,   185,
    11,   306,    10,     8,   306,     9,     0,   185,     8,   306,
     9,     0,   205,   328,     0,   376,   376,     0,   203,     0,
   375,     0,   306,     0,   202,     8,   376,     9,     0,   202,
     8,   376,     9,     0,   204,     8,   306,     9,     0,   204,
     8,     9,     0,   379,   379,     0,   375,     0,   306,     0,
   201,     8,   379,     9,     0,   201,     8,     9,     0,   222,
     0,   223,     0,   224,     0,   225,     0,   226,     0,   227,
     0,   228,     0,   229,     0,   245,     0,   246,     0,   247,
     0,   248,     0,   244,     0,   249,     0,   250,     0,   251,
     0,   252,     0,   253,     0,   254,     0,   255,     0,   256,
     0,   257,     0,   230,     0,   231,     0,   232,     0,   233,
     0,   234,     0,   235,     0,   236,     0,   237,     0,   238,
     0,   239,     0,   240,     0,   241,     0,   242,     0,   243,
     0,    18,     0,    19,     0,    20,     0,    21,     0,    22,
     0,    23,     0,    24,     0,    25,     0,    26,     0,    27,
     0,    28,     0,    31,     0,    32,     0,    33,     0,    34,
     0,    29,     0,    41,     0,    35,     0,    36,     0,    37,
     0,    38,     0,    39,     0,    42,     0,    43,     0,    44,
     0,    45,     0,    46,     0,    47,     0,    48,     0,    49,
     0,    50,     0,    40,     0,    30,     0,    51,     0,    52,
     0,    53,     0,    54,     0,    55,     0,    56,     0,    57,
     0,    58,     0,    59,     0,    60,     0,    61,     0,    62,
     0,    63,     0,    64,     0,    65,     0,    66,     0,    67,
     0,    68,     0,    69,     0,    70,     0,    71,     0,    72,
     0,    73,     0,    74,     0,    75,     0,    76,     0,    77,
     0,    78,     0,    79,     0,    80,     0,    81,     0,    82,
     0,    83,     0,    84,     0,    85,     0,    86,     0,    87,
     0,    88,     0,    89,     0,    90,     0,    91,     0,    92,
     0,    93,     0,    94,     0,    95,     0,    96,     0,    97,
     0,    98,     0,    99,     0,   100,     0,   101,     0,   102,
     0,   103,     0,   104,     0,   105,     0,   106,     0,   107,
     0,   108,     0,   109,     0,   110,     0,   111,     0,   112,
     0,   113,     0,   114,     0,   115,     0,   116,     0,   117,
     0,   118,     0,   119,     0,   120,     0,   121,     0,   122,
     0,   123,     0,   124,     0,   125,     0,   126,     0,   127,
     0,   128,     0,   129,     0,   130,     0,   131,     0,   132,
     0,   133,     0,   134,     0,   135,     0,   136,     0,   137,
     0,   138,     0,   139,     0,   140,     0,   141,     0,   142,
     0,   143,     0,   144,     0,   145,     0,   146,     0,   147,
     0,   148,     0,   149,     0,   150,     0,   151,     0,   152,
     0,   153,     0,   154,     0,   155,     0,   156,     0,   157,
     0,   158,     0,   159,     0,   160,     0,   161,     0,   162,
     0,   163,     0,   164,     0,   165,     0,   166,     0,   167,
     0,   168,     0,   169,     0,   170,     0
};

#endif

#if YY_AnalitzadorSintactic_DEBUG != 0
static const short yyrline[] = { 0,
   251,   252,   256,   257,   260,   266,   274,   275,   276,   277,
   280,   281,   282,   285,   285,   286,   290,   291,   295,   297,
   298,   299,   317,   335,   353,   371,   391,   392,   396,   397,
   398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
   411,   412,   413,   414,   415,   416,   417,   418,   419,   420,
   421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
   431,   432,   433,   434,   435,   436,   437,   438,   441,   442,
   455,   468,   483,   502,   508,   516,   517,   518,   530,   533,
   533,   543,   543,   549,   554,   566,   566,   568,   569,   570,
   571,   572,   573,   574,   575,   576,   577,   580,   584,   586,
   586,   597,   600,   613,   622,   623,   624,   625,   627,   628,
   629,   630,   632,   633,   634,   635,   637,   638,   639,   640,
   642,   643,   644,   645,   646,   647,   650,   656,   670,   678,
   689,   702,   703,   704,   705,   707,   724,   730,   736,   737,
   738,   739,   741,   758,   763,   769,   770,   771,   774,   780,
   785,   808,   813,   814,   817,   818,   821,   830,   839,   868,
   877,   886,   895,   906,   906,   908,   908,   910,   916,   919,
   919,   921,   921,   923,   923,   925,   925,   927,   938,   939,
   940,   941,   942,   943,   944,   945,   946,   949,   949,   955,
   958,   958,   964,   967,   967,   973,   976,   977,   979,   980,
   984,   985,   989,   990,   993,   994,   998,   999,  1002,  1003,
  1006,  1019,  1020,  1021,  1022,  1025,  1029,  1033,  1037,  1039,
  1040,  1041,  1044,  1048,  1053,  1054,  1055,  1056,  1057,  1058,
  1059,  1060,  1061,  1062,  1063,  1064,  1065,  1066,  1067,  1068,
  1069,  1070,  1071,  1072,  1073,  1074,  1075,  1076,  1077,  1078,
  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,
  1092,  1093,  1094,  1095,  1096,  1097,  1098,  1099,  1100,  1101,
  1102,  1103,  1104,  1105,  1106,  1107,  1108,  1109,  1110,  1111,
  1112,  1113,  1114,  1115,  1116,  1117,  1118,  1119,  1120,  1121,
  1122,  1123,  1124,  1126,  1127,  1128,  1129,  1130,  1131,  1132,
  1133,  1134,  1135,  1136,  1137,  1138,  1139,  1140,  1141,  1142,
  1143,  1144,  1145,  1146,  1147,  1148,  1149,  1150,  1151,  1152,
  1153,  1154,  1156,  1157,  1158,  1159,  1160,  1161,  1162,  1163,
  1164,  1165,  1166,  1167,  1168,  1169,  1170,  1171,  1172,  1173,
  1174,  1175,  1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,
  1184,  1186,  1187,  1188,  1189,  1190,  1191,  1192,  1193,  1194,
  1195,  1196,  1197,  1198,  1199,  1200,  1201,  1202,  1203,  1204,
  1205,  1206,  1207,  1208,  1209,  1210,  1211,  1212,  1213,  1214,
  1216,  1217,  1218,  1219,  1220,  1221,  1222,  1223,  1224,  1225,
  1226,  1227,  1228,  1229,  1230,  1231,  1232,  1233,  1234,  1235,
  1236,  1237,  1238,  1239,  1240,  1241,  1242,  1243,  1244,  1246,
  1247,  1248,  1249
};

static const char * const yytname[] = {   "$","error","$illegal.","TEXT_CONTINGUT",
"MATEMATIC","COMA","IMATGE","IMATGEFIG","PO","PT","CT","CO","FP","NL","LINIA",
"TAB","POS_TAB","HLINE","A_A_OBERT","A_A_TANCAT","A_A_CIRCUM","A_A_DIERESIS",
"A_A_TILDE","A_A_MACRON","A_A_DOT","A_A_BREVE","A_A_CHECK","A_A_HUNGARIAN","A_A_TIE",
"A_A_RING","A_A_RING_M","A_A_CEDILLA","A_A_DOTUNDER","A_A_BARUNDER","A_A_VECTOR",
"A_A_OBERT_M","A_A_TANCAT_M","A_A_CIRCUM_M","A_A_DIERESIS_M","A_A_TILDE_M","A_A_AE_DIFTONG_M",
"A_A_AE_DIFTONG","A_A_MACRON_M","A_A_DOT_M","A_A_BREVE_M","A_A_CHECK_M","A_A_HUNGARIAN_M",
"A_A_TIE_M","A_A_CEDILLA_M","A_A_DOTUNDER_M","A_A_BARUNDER_M","A_E_OBERT","A_E_TANCAT",
"A_E_CIRCUM","A_E_DIERESIS","A_E_TILDE","A_E_MACRON","A_E_DOT","A_E_BREVE","A_E_CHECK",
"A_E_HUNGARIAN","A_E_TIE","A_E_CEDILLA","A_E_DOTUNDER","A_E_BARUNDER","A_E_VECTOR",
"A_E_OBERT_M","A_E_TANCAT_M","A_E_CIRCUM_M","A_E_DIERESIS_M","A_E_TILDE_M","A_E_MACRON_M",
"A_E_DOT_M","A_E_BREVE_M","A_E_CHECK_M","A_E_HUNGARIAN_M","A_E_TIE_M","A_E_CEDILLA_M",
"A_E_DOTUNDER_M","A_E_BARUNDER_M","A_I_OBERT","A_I_TANCAT","A_I_CIRCUM","A_I_DIERESIS",
"A_I_TILDE","A_I_MACRON","A_I_DOT","A_I_BREVE","A_I_CHECK","A_I_HUNGARIAN","A_I_TIE",
"A_I_CEDILLA","A_I_DOTUNDER","A_I_BARUNDER","A_I_VECTOR","A_I_OBERT_M","A_I_TANCAT_M",
"A_I_CIRCUM_M","A_I_DIERESIS_M","A_I_TILDE_M","A_I_MACRON_M","A_I_DOT_M","A_I_BREVE_M",
"A_I_CHECK_M","A_I_HUNGARIAN_M","A_I_TIE_M","A_I_CEDILLA_M","A_I_DOTUNDER_M",
"A_I_BARUNDER_M","A_O_OBERT","A_O_TANCAT","A_O_CIRCUM","A_O_DIERESIS","A_O_TILDE",
"A_O_MACRON","A_O_DOT","A_O_BREVE","A_O_CHECK","A_O_HUNGARIAN","A_O_TIE","A_O_CEDILLA",
"A_O_DOTUNDER","A_O_BARUNDER","A_O_VECTOR","A_O_OBERT_M","A_O_TANCAT_M","A_O_CIRCUM_M",
"A_O_DIERESIS_M","A_O_TILDE_M","A_O_MACRON_M","A_O_DOT_M","A_O_BREVE_M","A_O_CHECK_M",
"A_O_HUNGARIAN_M","A_O_TIE_M","A_O_CEDILLA_M","A_O_DOTUNDER_M","A_O_BARUNDER_M",
"A_U_OBERT","A_U_TANCAT","A_U_CIRCUM","A_U_DIERESIS","A_U_TILDE","A_U_MACRON",
"A_U_DOT","A_U_BREVE","A_U_CHECK","A_U_HUNGARIAN","A_U_TIE","A_U_CEDILLA","A_U_DOTUNDER",
"A_U_BARUNDER","A_U_VECTOR","A_U_OBERT_M","A_U_TANCAT_M","A_U_CIRCUM_M","A_U_DIERESIS_M",
"A_U_TILDE_M","A_U_MACRON_M","A_U_DOT_M","A_U_BREVE_M","A_U_CHECK_M","A_U_HUNGARIAN_M",
"A_U_TIE_M","A_U_CEDILLA_M","A_U_DOTUNDER_M","A_U_BARUNDER_M","A_C_TRENCADA",
"A_C_TRENCADA_M","A_N_CEDILLA","A_N_CEDILLA_M","D_TEXT_TINY","D_TEXT_SCRIPTSIZE",
"D_TEXT_FOOTNOTESIZE","D_TEXT_SMALL","D_TEXT_NORMALSIZE","D_TEXT_LARGE","D_TEXT_LLARGE",
"D_TEXT_LLLARGE","D_TEXT_HUGE","D_TEXT_HHUGE","D_TEXT_IT","D_TEXT_BF","D_TEXT_TT",
"D_TEXT_EM","M_PACKAGE","M_DOC_CLASS","M_SECCIO","M_SUBSECCIO","M_SUBSUBSECCIO",
"M_TEXT_EMF","M_TEXT_NORMAL","M_TEXT_ITALICA","M_TEXT_BOLD","M_TEXT_SUBR","M_TEXT_SUP",
"M_TEXT_MECANOGRAFIC","M_LLISTA_DE_FIGURES","M_LLISTA_DE_TAULES","M_TAULA_DE_CONTINGUTS",
"M_CAPITOL","M_TITOL","M_AUTOR","M_AND","M_DATA","M_THANKS","M_FER_TITOL","M_PART",
"M_ITEM","M_SUBITEM","M_PEU_DE_PAGINA","M_ETIQUETA","M_REFERENCIA","M_PARAGRAF",
"M_SUBPARAGRAF","M_APENDIX","M_CAPTION","M_CITACIO","M_ITEM_BIBLIOGRAFIC","M_LINK",
"M_TARGET","M_HREF","S_DOLLAR","S_AMPERSAND","S_TANPERCENT","S_GUIOINF","S_CLAUOBERTA",
"S_CLAUTANCADA","S_MENORQUE","S_MAJORQUE","S_CONTRABARRA","S_BARRA","S_PUNT",
"S_DOBLECREUETA","S_CREUETA","S_PARAGRAF","S_SECCIO","S_COPYRIGHT","S_CIRCUM",
"S_TILDE","S_REGISTRAT","S_TRADEMARK","S_AFEM","S_OMASC","S_SHARP","S_DIFERENT",
"S_MENOR_IGUAL","S_MAJOR_IGUAL","S_APROXIMAT","S_IDENTIC","S_INFINIT","S_INTERSECCIO",
"S_INTEGRAL","S_ARREL_QUADRADA","S_SUMATORI","S_PRODUCTORI","S_INCREMENT","S_DIFERENCIAL",
"INICI_DOC","FI_DOC","INICI_TITOL","FI_TITOL","INICI_ENUMERAT","FI_ENUMERAT",
"INICI_BIBLIOGRAFIA","FI_BIBLIOGRAFIA","INICI_ABSTRACT","FI_ABSTRACT","INICI_FIGURA",
"FI_FIGURA","INICI_TAULA","FI_TAULA","INICI_TABULAR","FI_TABULAR","INICI_EQUACIO",
"FI_EQUACIO","INICI_ITEMIZE","FI_ITEMIZE","INICI_ARRAY","FI_ARRAY","INICI_EQARRAY",
"FI_EQARRAY","INICI_TEOREMA","FI_TEOREMA","INICI_TEXT_CENTRAT","FI_TEXT_CENTRAT",
"INICI_TEXT_ESQ","FI_TEXT_ESQ","INICI_TEXT_DRETA","FI_TEXT_DRETA","INICI_VERS",
"FI_VERS","INICI_TABBING","FI_TABBING","INICI_RAWHTML","FI_RAWHTML","document",
"preambul","inici_preambul","conjunt_titol","cos_preambul","cos_document","@1",
"@2","@3","cos","text","cos_bibliografia","bibliografia","cos_tabbing","tabbing",
"@4","hyperreferencia","@5","hyperlink","hypertarget","html","@6","cos_itemize",
"itemize","enumerat","@7","equacio","@8","cos_entorn_it","cos_entorn_bf","cos_entorn_tt",
"cos_entorn_em","entorn","abstract","nota_peu_pagina","fragment_matematic","grafic",
"cos_figura","caption_figura","figura","cos_taula","caption_taula","taula","cos_citacio",
"citacio","etiqueta","referencia","paragraf","subparagraf","text_fonts","text_emfatitzat",
"@9","text_italica","@10","text_normal","@11","text_negreta","@12","text_mecanografic",
"@13","text_subratllat","@14","text_super","@15","liniah","tamany_font","text_centrat",
"@16","text_esquerra","@17","text_dreta","@18","pagina_titol","part","capitol",
"seccio","subseccio","subsubseccio","paquets","thanks","cos_autor","autor","data",
"cos_titol","titol","simbol","lletra_accentuada",""
};
#endif

static const short yyr1[] = {     0,
   296,   296,   297,   297,   298,   298,   299,   299,   299,   299,
   300,   300,   300,   302,   301,   303,   301,   304,   301,   305,
   305,   305,   305,   305,   305,   305,   306,   306,   306,   306,
   306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
   306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
   306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
   306,   306,   306,   306,   306,   306,   306,   306,   307,   307,
   307,   307,   307,   308,   308,   309,   309,   309,   309,   311,
   310,   313,   312,   314,   315,   317,   316,   318,   318,   318,
   318,   318,   318,   318,   318,   318,   318,   319,   319,   321,
   320,   320,   323,   322,   324,   324,   324,   324,   325,   325,
   325,   325,   326,   326,   326,   326,   327,   327,   327,   327,
   328,   328,   328,   328,   328,   328,   329,   330,   331,   332,
   332,   333,   333,   333,   333,   334,   335,   335,   336,   336,
   336,   336,   337,   338,   338,   339,   339,   339,   340,   340,
   341,   342,   343,   343,   344,   344,   345,   345,   345,   345,
   345,   345,   345,   347,   346,   349,   348,   351,   350,   353,
   352,   355,   354,   357,   356,   359,   358,   360,   361,   361,
   361,   361,   361,   361,   361,   361,   361,   363,   362,   362,
   365,   364,   364,   367,   366,   366,   368,   368,   369,   369,
   370,   370,   371,   371,   372,   372,   373,   373,   374,   374,
   375,   376,   376,   376,   376,   377,   377,   378,   378,   379,
   379,   379,   380,   380,   381,   381,   381,   381,   381,   381,
   381,   381,   381,   381,   381,   381,   381,   381,   381,   381,
   381,   381,   381,   381,   381,   381,   381,   381,   381,   381,
   381,   381,   381,   381,   381,   381,   381,   381,   381,   381,
   382,   382,   382,   382,   382,   382,   382,   382,   382,   382,
   382,   382,   382,   382,   382,   382,   382,   382,   382,   382,
   382,   382,   382,   382,   382,   382,   382,   382,   382,   382,
   382,   382,   382,   382,   382,   382,   382,   382,   382,   382,
   382,   382,   382,   382,   382,   382,   382,   382,   382,   382,
   382,   382,   382,   382,   382,   382,   382,   382,   382,   382,
   382,   382,   382,   382,   382,   382,   382,   382,   382,   382,
   382,   382,   382,   382,   382,   382,   382,   382,   382,   382,
   382,   382,   382,   382,   382,   382,   382,   382,   382,   382,
   382,   382,   382,   382,   382,   382,   382,   382,   382,   382,
   382,   382,   382,   382,   382,   382,   382,   382,   382,   382,
   382,   382,   382,   382,   382,   382,   382,   382,   382,   382,
   382,   382,   382,   382,   382,   382,   382,   382,   382,   382,
   382,   382,   382,   382,   382,   382,   382,   382,   382,   382,
   382,   382,   382,   382,   382,   382,   382,   382,   382,   382,
   382,   382,   382
};

static const short yyr2[] = {     0,
     2,     1,     2,     1,     7,     4,     2,     1,     1,     1,
     2,     1,     1,     0,     4,     0,     5,     0,     6,     2,
     1,     1,     1,     1,     1,     1,     2,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     2,     8,
     9,     5,     6,     3,     4,     2,     1,     1,     1,     0,
     4,     0,     8,     7,     7,     0,     4,     2,     5,     6,
     2,     1,     5,     6,     2,     1,     1,     3,     2,     0,
     4,     2,     0,     4,     3,     2,     2,     1,     3,     2,
     2,     1,     3,     2,     2,     1,     3,     2,     2,     1,
     2,     3,     3,     3,     3,     3,     3,     2,     1,     4,
     4,     3,     2,     2,     1,     2,     3,     3,     3,     2,
     2,     1,     2,     3,     3,     2,     1,     1,     4,     7,
     4,     4,     2,     3,     2,     3,     1,     1,     1,     1,
     1,     1,     1,     0,     3,     0,     5,     0,     5,     0,
     5,     0,     5,     0,     5,     0,     5,     7,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     0,     4,     2,
     0,     4,     2,     0,     4,     2,     3,     2,     2,     3,
     2,     3,     2,     3,     2,     3,     2,     3,     7,     4,
     2,     2,     1,     1,     1,     4,     4,     4,     3,     2,
     1,     1,     4,     3,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1
};

static const short yydefact[] = {     0,
     0,    14,     0,     4,     2,     0,     0,     0,     0,     0,
    16,     0,     0,     8,     9,    10,     1,     0,    12,     3,
    13,    28,   129,    29,     0,     0,     0,    40,    41,     0,
   261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
   271,   276,   293,   272,   273,   274,   275,   278,   279,   280,
   281,   282,   292,   277,   283,   284,   285,   286,   287,   288,
   289,   290,   291,   294,   295,   296,   297,   298,   299,   300,
   301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
   311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
   321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
   331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
   341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
   351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
   361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
   371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
   381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
   391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
   401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
   411,   412,   413,   179,   180,   181,   182,   183,   184,   185,
   186,   187,    55,    56,    57,    58,   164,     0,     0,     0,
     0,     0,     0,    47,    48,    46,     0,     0,     0,     0,
     0,     0,     0,     0,    82,   225,   226,   227,   228,   229,
   230,   231,   232,   247,   248,   249,   250,   251,   252,   253,
   254,   255,   256,   257,   258,   259,   260,   237,   233,   234,
   235,   236,   238,   239,   240,   241,   242,   243,   244,   245,
   246,     0,   100,     0,     0,     0,     0,   103,     0,   188,
   191,   194,    80,    86,     0,    68,    67,    66,    64,    65,
    63,    62,    43,    60,    59,    54,    44,    51,    42,    52,
    53,    37,    38,    39,    49,    50,    31,   157,   158,   159,
   160,   163,   161,   162,    36,    45,    32,    33,    34,    61,
    35,    30,     0,     0,     0,     0,     0,    18,     7,     0,
     0,     0,     0,     0,     0,    21,    22,    23,    24,    25,
    26,     0,     0,    11,     0,     0,   121,    55,    56,    57,
    58,     0,     0,     0,     0,     0,     0,     0,   168,   166,
   170,   174,   176,   172,   128,     0,     0,     0,   153,     0,
   155,     0,     0,     0,     0,     0,   198,     0,   102,     0,
     0,     0,     0,     0,     0,     0,     0,   135,     0,     0,
     0,   142,     0,    92,    96,    99,    97,     0,   190,     0,
   193,     0,   196,     0,     0,     0,     6,    27,     0,   224,
     0,   222,   221,     0,   213,   215,   214,     0,   219,     0,
     0,     0,     0,   203,     0,   205,     0,   207,     0,   201,
     0,   199,    15,    20,     0,     0,     0,     0,   107,   111,
   115,   119,   122,    55,    56,    57,    58,   123,   124,   125,
   126,     0,   165,     0,     0,     0,     0,     0,     0,     0,
     0,   121,   121,   148,   147,     0,     0,     0,     0,     0,
   197,     0,     0,     0,     0,    74,    69,     0,   127,   136,
   138,   134,   137,   133,   143,   145,   141,   144,   140,     0,
     0,    91,     0,    95,    98,    88,     0,     0,     0,    78,
    77,    79,     0,     0,     0,   211,   223,   220,   216,   212,
   218,    17,     0,   121,   121,   121,   121,   121,   210,     0,
   130,   131,   105,   109,   113,   117,     0,     0,     0,     0,
     0,     0,     0,   151,   152,   149,   146,     0,     0,     0,
     0,   101,    28,     0,     0,     0,    75,   132,   139,   104,
     0,     0,     0,     0,   189,   192,   195,    81,    76,    87,
     0,    19,     0,     0,   169,   167,   171,   175,   177,   173,
     0,     0,     0,     0,     0,     0,    28,     0,     0,     0,
     0,     0,     5,     0,     0,     0,     0,     0,     0,    72,
     0,     0,     0,    89,     0,    93,     0,   209,   178,   150,
    84,    85,     0,     0,    73,     0,    90,    94,    83,     0,
     0,    70,     0,    71,     0,     0,     0
};

static const short yydefgoto[] = {   595,
     3,     4,    19,   324,     5,    13,   307,   402,   414,   388,
   457,   266,   539,   267,   385,   268,   356,   269,   270,   271,
   386,   476,   272,   273,   360,   274,   373,   333,   334,   335,
   336,   275,   276,   277,   278,   279,   367,   368,   280,   371,
   372,   281,   517,   282,   283,   284,   285,   286,   287,   288,
   338,   289,   435,   290,   434,   291,   436,   292,   439,   293,
   437,   294,   438,   295,   296,   297,   380,   298,   382,   299,
   384,   300,   317,   318,   319,   320,   321,    21,   393,   490,
    14,    15,   488,    16,   301,   302
};

static const short yypact[] = {  -176,
    24,  -164,  -240,  -168,-32768, 22194, 22194,    11,    18,    22,
-32768,  -158,  1754,-32768,-32768,-32768,-32768,    43,  -152,  -168,
-32768,-32768,-32768,-32768,    23,    37,  5550,-32768,-32768,    39,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,    49,    50,    51,
    52,    54,    56,-32768,-32768,-32768,    57,    58,    59,    60,
    61,    45,    62,    63,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,  5842,  -236,    -4, 22194,  6134,  6426,-32768,  2046,  -213,
  -214,  -215,-32768,-32768,  6718,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,  7010,  3506,  3798,  7302,  1754,-32768,  -152,    67,
    68,    69,    70,    71,   878, 22194,-32768,-32768,-32768,-32768,
-32768, 22194, 22194,  -168, 22194, 22194,-32768, 22194, 22194, 22194,
 22194,  7594,    72,    74,    75,    76, 22194,    57,-32768,-32768,
-32768,-32768,-32768,-32768,-32768, 22194, 22194,  7886,-32768,  8178,
-32768,    36, 22194,    77,    83,    79,-32768,  8470,-32768,  4090,
  8762,  -204,  -130,  9054,    57,  4382,  -180, 22194,    57,  4674,
  -181, 22194, 22194,  9346,  9638,-32768, 22194,  2338,-32768, 22194,
-32768, 22194,-32768, 22194,  4966, 22194,-32768, 22194,    84,-32768,
    57, 22194,-32768,  5258,-32768, 22194,-32768,  2630,-32768,  9930,
  1170,  1754, 10222,-32768, 10514,-32768, 10806,-32768, 11098,-32768,
 11390,-32768,-32768,  1754, 11682, 11974, 12266, 12558, 22194, 22194,
 22194, 22194,-32768, 22194, 22194, 22194, 22194,-32768,-32768,-32768,
-32768, 12850,-32768, 22194, 22194, 22194, 22194, 22194, 22194, 13142,
 13434,-32768,-32768,-32768,-32768,    19, 13726,    82,    85,    90,
-32768,  2922, 14018, 22194, 14310,-32768,  -130,  -202,-32768,-32768,
-32768, 22194,-32768, 22194,-32768,-32768, 22194,-32768, 22194, 14602,
 22194, 14894, 22194, 15186,-32768,  4090, 15478, 15770, 16062,-32768,
-32768, 22194,  3214,   585, 22194,-32768,-32768, 16354,-32768,  3798,
-32768,-32768,  1462,-32768,-32768,-32768,-32768,-32768,-32768,    87,
-32768,-32768, 22194, 22194, 22194, 22194,    88, 16646, 16938, 17230,
 17522, 17814, 18106,-32768,-32768,-32768,    36,    89,    92,    93,
    94,-32768,    95, 18398, 18690, 22194,-32768, 22194, 22194,-32768,
 18982, 22194, 19274, 22194,-32768,-32768,-32768,-32768,  4966,-32768,
 19566,-32768, 22194, 22194,-32768,-32768,-32768,-32768,-32768,-32768,
    36, 22194, 22194,    97, 22194,    98,    99, 19858, 22194, 20150,
 22194, 20442,-32768, 20734, 21026,    20, 21318, 21610, 22194, 22194,
   104, 22194,   101, 22194, 22194, 22194, 22194,-32768,-32768,-32768,
-32768,-32768, 21902,   108, 22194,   107, 22194, 22194,-32768, 22194,
   110, 22194, 22194, 22194,   102,   120,-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,     1,   117,   119,-32768,-32768,-32768,   -11,    -6,
  -245,-32768,  -287,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,  -244,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,  -199,-32768,-32768,-32768,-32768,-32768,  -243,-32768,-32768,
  -246,-32768,  -347,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,  -299,  -179,
-32768,-32768,  -177,-32768,-32768,-32768
};


#define	YYLAST		22488


static const short yytable[] = {   265,
   303,   315,    12,    27,   446,   397,   316,   345,   362,     1,
   349,   351,   309,   361,   378,   361,    18,     2,   304,   309,
   332,   444,   444,   445,   445,   305,   359,   516,   580,   306,
   325,     6,     8,     9,     7,    10,     8,     9,   444,    10,
   445,    11,     8,     9,   326,    10,   337,   308,     8,     9,
   322,    10,   352,   323,   363,   353,   339,   340,   341,   342,
   456,   343,   527,   344,    27,   346,   347,   348,   350,   354,
   355,   379,   381,   383,   403,   405,   407,   409,   411,   448,
   428,     2,   429,   430,   431,   449,   450,   361,   463,   468,
   519,   485,   521,   520,   543,   544,   551,   483,   397,   552,
   553,   596,   554,   555,   569,   571,   584,   572,   586,   591,
   404,   406,   408,   410,   412,   452,   590,   458,   593,   597,
    20,    17,   462,   467,     0,   398,   394,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,   433,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,   460,     0,     0,     0,   465,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
   397,   486,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,   566,     0,     0,     0,     0,     0,     0,
     0,     0,     0,   361,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,   358,     0,     0,   364,   366,
   370,     0,   377,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,   401,     0,   392,   396,   400,
   316,     0,     0,     0,     0,     0,     0,     0,   316,   309,
     0,     0,     0,     0,     0,   415,   416,     0,   417,   418,
     0,   419,   420,   421,   422,     0,     0,     0,     0,     0,
   432,     0,     0,     0,     0,     0,     0,     0,     0,   440,
   441,   332,     0,   332,     0,     0,   447,     0,     0,     0,
     0,     0,     0,   377,   455,     0,     0,     0,     0,     0,
     0,   464,     0,     0,     0,   469,   470,   472,   474,     0,
     0,   377,     0,   477,     0,   478,     0,   479,   482,   484,
     0,     0,     0,     0,     0,     0,     0,   392,     0,     0,
   493,   396,     0,     0,   316,   316,   332,     0,   332,     0,
   332,     0,   332,     0,   332,     0,     0,   316,     0,     0,
     0,     0,     0,     0,     0,     0,     0,   503,   504,   505,
   506,     0,     0,     0,     0,     0,     0,   508,   509,   510,
   511,   512,   513,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,   377,   332,   524,     0,     0,
     0,     0,     0,     0,     0,   528,     0,     0,     0,     0,
   529,     0,     0,     0,   531,     0,   533,     0,     0,   377,
     0,     0,     0,     0,     0,     0,   482,     0,   541,     0,
     0,   392,     0,   396,     0,     0,   316,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,   332,   558,
     0,     0,     0,     0,     0,   560,     0,   562,     0,     0,
     0,     0,   482,     0,     0,     0,   564,   565,     0,     0,
     0,     0,     0,     0,     0,   567,   568,     0,   570,     0,
     0,     0,   574,     0,   576,     0,     0,     0,     0,     0,
     0,     0,   583,     0,     0,   585,     0,     0,   587,     0,
   588,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,   592,     0,     0,   594,    22,    23,    24,
    25,    26,    27,     0,     0,     0,    28,    29,    30,     0,
     0,     0,    31,    32,    33,    34,    35,    36,    37,    38,
    39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
    49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
    59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
    69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
    79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
    89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
    99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
   109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
   119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
   129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
   139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
   149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
   159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
   169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
   179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
   189,   190,     0,   191,   192,   193,   194,   195,   196,     0,
     0,     0,     0,     0,   197,   198,   199,   200,   201,   202,
   203,   204,   205,   206,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,   207,   208,   209,   210,   211,     0,
     0,   212,     0,   213,   214,   215,   216,   217,   218,   219,
   220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
   230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
   240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
   250,   251,     0,     0,   252,     0,   253,     0,   254,     0,
   255,     0,   256,     0,   257,     0,     0,     0,   258,     0,
   259,     0,     0,     0,     0,     0,     0,     0,   260,     0,
   261,     0,   262,     0,     0,     0,   263,     0,   264,   540,
    22,    23,    24,    25,    26,    27,     0,     0,     0,    28,
    29,    30,     0,     0,     0,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
    56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
    66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
    76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
    86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
    96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
   106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
   116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
   126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
   136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
   146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
   156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
   166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
   176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
   186,   187,   188,   189,   190,     0,   191,   192,   193,   194,
   195,   196,     0,     0,   310,   311,   312,   197,   198,   199,
   200,   201,   202,   203,   204,   205,   206,   313,     0,     0,
     0,     0,     0,     0,   314,     0,     0,   207,   208,   209,
   210,   211,     0,     0,   212,     0,   213,   214,   215,   216,
   217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
   227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
   237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
   247,   248,   249,   250,   251,     0,   413,   252,     0,   253,
     0,   254,     0,   255,     0,   256,     0,   257,     0,     0,
     0,   258,     0,   259,     0,     0,     0,     0,     0,     0,
     0,   260,     0,   261,     0,   262,     0,     0,     0,   263,
     0,   264,    22,    23,    24,    25,    26,    27,     0,     0,
     0,    28,    29,    30,     0,     0,     0,    31,    32,    33,
    34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
    44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
    54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
    64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
    74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
    84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
    94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
   104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
   114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
   124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
   134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
   144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
   154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
   164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
   174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
   184,   185,   186,   187,   188,   189,   190,     0,   191,   192,
   193,   194,   195,   196,     0,     0,   310,   311,   312,   197,
   198,   199,   200,   201,   202,   203,   204,   205,   206,   313,
     0,     0,     0,     0,     0,     0,   314,     0,     0,   207,
   208,   209,   210,   211,     0,     0,   212,     0,   213,   214,
   215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
   225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
   235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
   245,   246,   247,   248,   249,   250,   251,     0,   492,   252,
     0,   253,     0,   254,     0,   255,     0,   256,     0,   257,
     0,     0,     0,   258,     0,   259,     0,     0,     0,     0,
     0,     0,     0,   260,     0,   261,     0,   262,     0,     0,
     0,   263,     0,   264,    22,    23,    24,    25,    26,    27,
     0,     0,     0,    28,    29,    30,     0,     0,     0,    31,
    32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
    42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
    52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
    62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
    72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
    82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
    92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
   102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
   112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
   122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
   132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
   142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
   152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
   162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
   172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
   182,   183,   184,   185,   186,   187,   188,   189,   190,     0,
   191,   192,   193,   194,   195,   196,     0,     0,   310,   311,
   312,   197,   198,   199,   200,   201,   202,   203,   204,   205,
   206,   313,     0,     0,     0,     0,     0,     0,   314,     0,
     0,   207,   208,   209,   210,   211,     0,     0,   212,     0,
   213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
   223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
   233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
   243,   244,   245,   246,   247,   248,   249,   250,   251,     0,
   542,   252,     0,   253,     0,   254,     0,   255,     0,   256,
     0,   257,     0,     0,     0,   258,     0,   259,     0,     0,
     0,     0,     0,     0,     0,   260,     0,   261,     0,   262,
     0,     0,     0,   263,     0,   264,    22,    23,    24,    25,
    26,    27,     0,     0,     0,    28,    29,    30,     0,     0,
     0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
    40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
    50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
    60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
    70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
    80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
    90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
   100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
   110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
   120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
   130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
   140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
   150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
   160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
   170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
   180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
   190,     0,   191,   192,   193,   194,   195,   196,     0,     0,
   310,   311,   312,   197,   198,   199,   200,   201,   202,   203,
   204,   205,   206,   313,     0,     0,     0,     0,     0,     0,
   314,     0,     0,   207,   208,   209,   210,   211,     0,     0,
   212,     0,   213,   214,   215,   216,   217,   218,   219,   220,
   221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
   231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
   241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
   251,     0,     0,   252,     0,   253,     0,   254,     0,   255,
     0,   256,     0,   257,     0,     0,     0,   258,     0,   259,
     0,     0,     0,     0,     0,     0,     0,   260,     0,   261,
     0,   262,     0,     0,     0,   263,     0,   264,    22,    23,
    24,    25,    26,    27,     0,     0,     0,    28,    29,    30,
     0,     0,     0,    31,    32,    33,    34,    35,    36,    37,
    38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
    48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
    58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
    68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
    78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
    88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
    98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
   108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
   118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
   128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
   138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
   148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
   158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
   168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
   178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
   188,   189,   190,     0,   191,   192,   193,   194,   195,   196,
     0,     0,     0,     0,     0,   197,   198,   199,   200,   201,
   202,   203,   204,   205,   206,     0,     0,     0,     0,     0,
     0,     0,     0,   374,   375,   207,   208,   209,   210,   211,
     0,     0,   212,     0,   213,   214,   215,   216,   217,   218,
   219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
   229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
   239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
   249,   250,   251,     0,     0,   252,     0,   253,     0,   254,
     0,   255,     0,   256,     0,   257,     0,     0,     0,   258,
     0,   259,   376,     0,     0,     0,     0,     0,     0,   260,
     0,   261,     0,   262,     0,     0,     0,   263,     0,   264,
    22,    23,    24,    25,    26,    27,     0,     0,     0,    28,
    29,    30,     0,     0,     0,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
    56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
    66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
    76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
    86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
    96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
   106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
   116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
   126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
   136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
   146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
   156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
   166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
   176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
   186,   187,   188,   189,   190,     0,   191,   192,   193,   194,
   195,   196,     0,     0,     0,     0,     0,   197,   198,   199,
   200,   201,   202,   203,   204,   205,   206,     0,     0,     0,
     0,     0,     0,     0,     0,   374,   375,   207,   208,   209,
   210,   211,     0,     0,   212,     0,   213,   214,   215,   216,
   217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
   227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
   237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
   247,   248,   249,   250,   251,     0,     0,   252,     0,   253,
     0,   254,     0,   255,     0,   256,     0,   257,     0,     0,
     0,   258,     0,   259,   475,     0,     0,     0,     0,     0,
     0,   260,     0,   261,     0,   262,     0,     0,     0,   263,
     0,   264,    22,    23,    24,    25,    26,    27,   489,     0,
     0,    28,    29,    30,     0,     0,     0,    31,    32,    33,
    34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
    44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
    54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
    64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
    74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
    84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
    94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
   104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
   114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
   124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
   134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
   144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
   154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
   164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
   174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
   184,   185,   186,   187,   188,   189,   190,     0,   191,   192,
   193,   194,   195,   196,     0,     0,     0,     0,     0,   197,
   198,   199,   200,   201,   202,   203,   204,   205,   206,     0,
     0,     0,   395,     0,   391,     0,     0,     0,     0,   207,
   208,   209,   210,   211,     0,     0,   212,     0,   213,   214,
   215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
   225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
   235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
   245,   246,   247,   248,   249,   250,   251,     0,     0,   252,
     0,   253,     0,   254,     0,   255,     0,   256,     0,   257,
     0,     0,     0,   258,     0,   259,     0,     0,     0,     0,
     0,     0,     0,   260,     0,   261,     0,   262,     0,     0,
     0,   263,     0,   264,    22,    23,    24,    25,    26,    27,
     0,     0,     0,    28,    29,    30,     0,     0,     0,    31,
    32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
    42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
    52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
    62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
    72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
    82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
    92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
   102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
   112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
   122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
   132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
   142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
   152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
   162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
   172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
   182,   183,   184,   185,   186,   187,   188,   189,   190,     0,
   191,   192,   193,   194,   195,   196,     0,     0,     0,     0,
     0,   197,   198,   199,   200,   201,   202,   203,   204,   205,
   206,     0,     0,     0,     0,     0,     0,     0,     0,   374,
   375,   207,   208,   209,   210,   211,     0,     0,   212,     0,
   213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
   223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
   233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
   243,   244,   245,   246,   247,   248,   249,   250,   251,     0,
     0,   252,     0,   253,   522,   254,     0,   255,     0,   256,
     0,   257,     0,     0,     0,   258,     0,   259,     0,     0,
     0,     0,     0,     0,     0,   260,     0,   261,     0,   262,
     0,     0,     0,   263,     0,   264,    22,    23,    24,    25,
    26,    27,     0,     0,     0,    28,    29,    30,   480,   481,
     0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
    40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
    50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
    60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
    70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
    80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
    90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
   100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
   110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
   120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
   130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
   140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
   150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
   160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
   170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
   180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
   190,     0,   191,   192,   193,   194,   195,   196,     0,     0,
     0,     0,     0,   197,   198,   199,   200,   201,   202,   203,
   204,   205,   206,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,   207,   208,   209,   210,   211,     0,     0,
   212,     0,   213,   214,   215,   216,   217,   218,   219,   220,
   221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
   231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
   241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
   251,     0,     0,   252,     0,   253,     0,   254,     0,   255,
     0,   256,     0,   257,     0,     0,     0,   258,     0,   259,
     0,     0,     0,     0,     0,     0,     0,   260,     0,   261,
     0,   262,     0,     0,     0,   263,   538,   264,    22,    23,
    24,    25,    26,    27,   390,     0,     0,    28,    29,    30,
     0,     0,     0,    31,    32,    33,    34,    35,    36,    37,
    38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
    48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
    58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
    68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
    78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
    88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
    98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
   108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
   118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
   128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
   138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
   148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
   158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
   168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
   178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
   188,   189,   190,     0,   191,   192,   193,   194,   195,   196,
     0,     0,     0,     0,     0,   197,   198,   199,   200,   201,
   202,   203,   204,   205,   206,     0,     0,     0,     0,     0,
   391,     0,     0,     0,     0,   207,   208,   209,   210,   211,
     0,     0,   212,     0,   213,   214,   215,   216,   217,   218,
   219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
   229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
   239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
   249,   250,   251,     0,     0,   252,     0,   253,     0,   254,
     0,   255,     0,   256,     0,   257,     0,     0,     0,   258,
     0,   259,     0,     0,     0,     0,     0,     0,     0,   260,
     0,   261,     0,   262,     0,     0,     0,   263,     0,   264,
    22,    23,    24,    25,    26,    27,     0,     0,     0,    28,
    29,    30,     0,     0,     0,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
    56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
    66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
    76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
    86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
    96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
   106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
   116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
   126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
   136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
   146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
   156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
   166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
   176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
   186,   187,   188,   189,   190,     0,   191,   192,   193,   194,
   195,   196,     0,     0,     0,     0,     0,   197,   198,   199,
   200,   201,   202,   203,   204,   205,   206,     0,     0,     0,
   395,     0,   391,     0,     0,     0,     0,   207,   208,   209,
   210,   211,     0,     0,   212,     0,   213,   214,   215,   216,
   217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
   227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
   237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
   247,   248,   249,   250,   251,     0,     0,   252,     0,   253,
     0,   254,     0,   255,     0,   256,     0,   257,     0,     0,
     0,   258,     0,   259,     0,     0,     0,     0,     0,     0,
     0,   260,     0,   261,     0,   262,     0,     0,     0,   263,
     0,   264,    22,    23,    24,    25,    26,    27,     0,     0,
     0,    28,    29,    30,     0,     0,     0,    31,    32,    33,
    34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
    44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
    54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
    64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
    74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
    84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
    94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
   104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
   114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
   124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
   134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
   144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
   154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
   164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
   174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
   184,   185,   186,   187,   188,   189,   190,     0,   191,   192,
   193,   194,   195,   196,     0,     0,     0,     0,     0,   197,
   198,   199,   200,   201,   202,   203,   204,   205,   206,     0,
     0,     0,     0,     0,     0,     0,     0,   374,   375,   207,
   208,   209,   210,   211,     0,     0,   212,     0,   213,   214,
   215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
   225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
   235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
   245,   246,   247,   248,   249,   250,   251,     0,     0,   252,
     0,   253,     0,   254,     0,   255,     0,   256,     0,   257,
     0,     0,     0,   258,     0,   259,     0,     0,     0,     0,
     0,     0,     0,   260,     0,   261,     0,   262,     0,     0,
     0,   263,     0,   264,    22,    23,    24,    25,    26,    27,
     0,     0,     0,    28,    29,    30,     0,     0,     0,    31,
    32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
    42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
    52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
    62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
    72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
    82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
    92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
   102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
   112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
   122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
   132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
   142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
   152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
   162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
   172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
   182,   183,   184,   185,   186,   187,   188,   189,   190,     0,
   191,   192,   193,   194,   195,   196,     0,     0,     0,     0,
     0,   197,   198,   199,   200,   201,   202,   203,   204,   205,
   206,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,   207,   208,   209,   210,   211,     0,   365,   212,     0,
   213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
   223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
   233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
   243,   244,   245,   246,   247,   248,   249,   250,   251,     0,
     0,   252,     0,   253,     0,   254,     0,   255,     0,   256,
   461,   257,     0,     0,     0,   258,     0,   259,     0,     0,
     0,     0,     0,     0,     0,   260,     0,   261,     0,   262,
     0,     0,     0,   263,     0,   264,    22,    23,    24,    25,
    26,    27,     0,     0,     0,    28,    29,    30,     0,     0,
     0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
    40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
    50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
    60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
    70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
    80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
    90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
   100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
   110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
   120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
   130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
   140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
   150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
   160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
   170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
   180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
   190,     0,   191,   192,   193,   194,   195,   196,     0,     0,
     0,     0,     0,   197,   198,   199,   200,   201,   202,   203,
   204,   205,   206,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,   207,   208,   209,   210,   211,     0,   369,
   212,     0,   213,   214,   215,   216,   217,   218,   219,   220,
   221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
   231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
   241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
   251,     0,     0,   252,     0,   253,     0,   254,     0,   255,
     0,   256,     0,   257,   466,     0,     0,   258,     0,   259,
     0,     0,     0,     0,     0,     0,     0,   260,     0,   261,
     0,   262,     0,     0,     0,   263,     0,   264,    22,    23,
    24,    25,    26,    27,     0,     0,     0,    28,    29,    30,
   480,   481,     0,    31,    32,    33,    34,    35,    36,    37,
    38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
    48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
    58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
    68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
    78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
    88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
    98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
   108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
   118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
   128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
   138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
   148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
   158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
   168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
   178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
   188,   189,   190,     0,   191,   192,   193,   194,   195,   196,
     0,     0,     0,     0,     0,   197,   198,   199,   200,   201,
   202,   203,   204,   205,   206,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,   207,   208,   209,   210,   211,
     0,     0,   212,     0,   213,   214,   215,   216,   217,   218,
   219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
   229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
   239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
   249,   250,   251,     0,     0,   252,     0,   253,     0,   254,
     0,   255,     0,   256,     0,   257,     0,     0,     0,   258,
     0,   259,     0,     0,     0,     0,     0,     0,     0,   260,
     0,   261,     0,   262,     0,     0,     0,   263,     0,   264,
    22,    23,    24,    25,    26,    27,   487,     0,     0,    28,
    29,    30,     0,     0,     0,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
    56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
    66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
    76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
    86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
    96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
   106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
   116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
   126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
   136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
   146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
   156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
   166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
   176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
   186,   187,   188,   189,   190,     0,   191,   192,   193,   194,
   195,   196,     0,     0,     0,     0,     0,   197,   198,   199,
   200,   201,   202,   203,   204,   205,   206,     0,     0,     0,
     0,     0,   391,     0,     0,     0,     0,   207,   208,   209,
   210,   211,     0,     0,   212,     0,   213,   214,   215,   216,
   217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
   227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
   237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
   247,   248,   249,   250,   251,     0,     0,   252,     0,   253,
     0,   254,     0,   255,     0,   256,     0,   257,     0,     0,
     0,   258,     0,   259,     0,     0,     0,     0,     0,     0,
     0,   260,     0,   261,     0,   262,     0,     0,     0,   263,
     0,   264,    22,    23,    24,    25,    26,    27,   327,     0,
     0,    28,    29,    30,     0,     0,     0,    31,    32,    33,
    34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
    44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
    54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
    64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
    74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
    84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
    94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
   104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
   114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
   124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
   134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
   144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
   154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
   164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
   174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
   184,   185,   186,   187,   188,   189,   190,     0,   191,   192,
   328,   329,   330,   331,     0,     0,     0,     0,     0,   197,
   198,   199,   200,   201,   202,   203,   204,   205,   206,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,   207,
   208,   209,   210,   211,     0,     0,   212,     0,   213,   214,
   215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
   225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
   235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
   245,   246,   247,   248,   249,   250,   251,     0,     0,   252,
     0,   253,     0,   254,     0,   255,     0,   256,     0,   257,
     0,     0,     0,   258,     0,   259,     0,     0,     0,     0,
     0,     0,     0,   260,     0,   261,     0,   262,     0,     0,
     0,   263,     0,   264,    22,    23,    24,    25,    26,    27,
     0,     0,     0,    28,    29,    30,     0,     0,     0,    31,
    32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
    42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
    52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
    62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
    72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
    82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
    92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
   102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
   112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
   122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
   132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
   142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
   152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
   162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
   172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
   182,   183,   184,   185,   186,   187,   188,   189,   190,     0,
   191,   192,   193,   194,   195,   196,     0,     0,     0,     0,
     0,   197,   198,   199,   200,   201,   202,   203,   204,   205,
   206,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,   207,   208,   209,   210,   211,     0,     0,   212,     0,
   213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
   223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
   233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
   243,   244,   245,   246,   247,   248,   249,   250,   251,     0,
     0,   252,   357,   253,     0,   254,     0,   255,     0,   256,
     0,   257,     0,     0,     0,   258,     0,   259,     0,     0,
     0,     0,     0,     0,     0,   260,     0,   261,     0,   262,
     0,     0,     0,   263,     0,   264,    22,    23,    24,    25,
    26,    27,     0,     0,     0,    28,    29,    30,     0,     0,
     0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
    40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
    50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
    60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
    70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
    80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
    90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
   100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
   110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
   120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
   130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
   140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
   150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
   160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
   170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
   180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
   190,     0,   191,   192,   193,   194,   195,   196,     0,     0,
     0,     0,     0,   197,   198,   199,   200,   201,   202,   203,
   204,   205,   206,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,   207,   208,   209,   210,   211,     0,   365,
   212,     0,   213,   214,   215,   216,   217,   218,   219,   220,
   221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
   231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
   241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
   251,     0,     0,   252,     0,   253,     0,   254,     0,   255,
     0,   256,     0,   257,     0,     0,     0,   258,     0,   259,
     0,     0,     0,     0,     0,     0,     0,   260,     0,   261,
     0,   262,     0,     0,     0,   263,     0,   264,    22,    23,
    24,    25,    26,    27,     0,     0,     0,    28,    29,    30,
     0,     0,     0,    31,    32,    33,    34,    35,    36,    37,
    38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
    48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
    58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
    68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
    78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
    88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
    98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
   108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
   118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
   128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
   138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
   148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
   158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
   168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
   178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
   188,   189,   190,     0,   191,   192,   193,   194,   195,   196,
     0,     0,     0,     0,     0,   197,   198,   199,   200,   201,
   202,   203,   204,   205,   206,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,   207,   208,   209,   210,   211,
     0,   369,   212,     0,   213,   214,   215,   216,   217,   218,
   219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
   229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
   239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
   249,   250,   251,     0,     0,   252,     0,   253,     0,   254,
     0,   255,     0,   256,     0,   257,     0,     0,     0,   258,
     0,   259,     0,     0,     0,     0,     0,     0,     0,   260,
     0,   261,     0,   262,     0,     0,     0,   263,     0,   264,
    22,    23,    24,    25,    26,    27,   387,     0,     0,    28,
    29,    30,     0,     0,     0,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
    56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
    66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
    76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
    86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
    96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
   106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
   116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
   126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
   136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
   146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
   156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
   166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
   176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
   186,   187,   188,   189,   190,     0,   191,   192,   193,   194,
   195,   196,     0,     0,     0,     0,     0,   197,   198,   199,
   200,   201,   202,   203,   204,   205,   206,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,   207,   208,   209,
   210,   211,     0,     0,   212,     0,   213,   214,   215,   216,
   217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
   227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
   237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
   247,   248,   249,   250,   251,     0,     0,   252,     0,   253,
     0,   254,     0,   255,     0,   256,     0,   257,     0,     0,
     0,   258,     0,   259,     0,     0,     0,     0,     0,     0,
     0,   260,     0,   261,     0,   262,     0,     0,     0,   263,
     0,   264,    22,    23,    24,    25,    26,    27,     0,   389,
     0,    28,    29,    30,     0,     0,     0,    31,    32,    33,
    34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
    44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
    54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
    64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
    74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
    84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
    94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
   104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
   114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
   124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
   134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
   144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
   154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
   164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
   174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
   184,   185,   186,   187,   188,   189,   190,     0,   191,   192,
   193,   194,   195,   196,     0,     0,     0,     0,     0,   197,
   198,   199,   200,   201,   202,   203,   204,   205,   206,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,   207,
   208,   209,   210,   211,     0,     0,   212,     0,   213,   214,
   215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
   225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
   235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
   245,   246,   247,   248,   249,   250,   251,     0,     0,   252,
     0,   253,     0,   254,     0,   255,     0,   256,     0,   257,
     0,     0,     0,   258,     0,   259,     0,     0,     0,     0,
     0,     0,     0,   260,     0,   261,     0,   262,     0,     0,
     0,   263,     0,   264,    22,    23,    24,    25,    26,    27,
   399,     0,     0,    28,    29,    30,     0,     0,     0,    31,
    32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
    42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
    52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
    62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
    72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
    82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
    92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
   102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
   112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
   122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
   132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
   142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
   152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
   162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
   172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
   182,   183,   184,   185,   186,   187,   188,   189,   190,     0,
   191,   192,   193,   194,   195,   196,     0,     0,     0,     0,
     0,   197,   198,   199,   200,   201,   202,   203,   204,   205,
   206,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,   207,   208,   209,   210,   211,     0,     0,   212,     0,
   213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
   223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
   233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
   243,   244,   245,   246,   247,   248,   249,   250,   251,     0,
     0,   252,     0,   253,     0,   254,     0,   255,     0,   256,
     0,   257,     0,     0,     0,   258,     0,   259,     0,     0,
     0,     0,     0,     0,     0,   260,     0,   261,     0,   262,
     0,     0,     0,   263,     0,   264,    22,    23,    24,    25,
    26,    27,   423,     0,     0,    28,    29,    30,     0,     0,
     0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
    40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
    50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
    60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
    70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
    80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
    90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
   100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
   110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
   120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
   130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
   140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
   150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
   160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
   170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
   180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
   190,     0,   191,   192,   424,   425,   426,   427,     0,     0,
     0,     0,     0,   197,   198,   199,   200,   201,   202,   203,
   204,   205,   206,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,   207,   208,   209,   210,   211,     0,     0,
   212,     0,   213,   214,   215,   216,   217,   218,   219,   220,
   221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
   231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
   241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
   251,     0,     0,   252,     0,   253,     0,   254,     0,   255,
     0,   256,     0,   257,     0,     0,     0,   258,     0,   259,
     0,     0,     0,     0,     0,     0,     0,   260,     0,   261,
     0,   262,     0,     0,     0,   263,     0,   264,    22,    23,
    24,    25,    26,    27,   442,     0,     0,    28,    29,    30,
     0,     0,     0,    31,    32,    33,    34,    35,    36,    37,
    38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
    48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
    58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
    68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
    78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
    88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
    98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
   108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
   118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
   128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
   138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
   148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
   158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
   168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
   178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
   188,   189,   190,     0,   191,   192,   328,   329,   330,   331,
     0,     0,     0,     0,     0,   197,   198,   199,   200,   201,
   202,   203,   204,   205,   206,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,   207,   208,   209,   210,   211,
     0,     0,   212,     0,   213,   214,   215,   216,   217,   218,
   219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
   229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
   239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
   249,   250,   251,     0,     0,   252,     0,   253,     0,   254,
     0,   255,     0,   256,     0,   257,     0,     0,     0,   258,
     0,   259,     0,     0,     0,     0,     0,     0,     0,   260,
     0,   261,     0,   262,     0,     0,     0,   263,     0,   264,
    22,    23,    24,    25,    26,    27,   443,     0,     0,    28,
    29,    30,     0,     0,     0,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
    56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
    66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
    76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
    86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
    96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
   106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
   116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
   126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
   136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
   146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
   156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
   166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
   176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
   186,   187,   188,   189,   190,     0,   191,   192,   328,   329,
   330,   331,     0,     0,     0,     0,     0,   197,   198,   199,
   200,   201,   202,   203,   204,   205,   206,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,   207,   208,   209,
   210,   211,     0,     0,   212,     0,   213,   214,   215,   216,
   217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
   227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
   237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
   247,   248,   249,   250,   251,     0,     0,   252,     0,   253,
     0,   254,     0,   255,     0,   256,     0,   257,     0,     0,
     0,   258,     0,   259,     0,     0,     0,     0,     0,     0,
     0,   260,     0,   261,     0,   262,     0,     0,     0,   263,
     0,   264,    22,    23,    24,    25,    26,    27,     0,     0,
     0,    28,    29,    30,     0,     0,     0,    31,    32,    33,
    34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
    44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
    54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
    64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
    74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
    84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
    94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
   104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
   114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
   124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
   134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
   144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
   154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
   164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
   174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
   184,   185,   186,   187,   188,   189,   190,     0,   191,   192,
   193,   194,   195,   196,     0,     0,     0,     0,     0,   197,
   198,   199,   200,   201,   202,   203,   204,   205,   206,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,   207,
   208,   209,   210,   211,     0,     0,   212,     0,   213,   214,
   215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
   225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
   235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
   245,   246,   247,   248,   249,   250,   251,     0,     0,   252,
   451,   253,     0,   254,     0,   255,     0,   256,     0,   257,
     0,     0,     0,   258,     0,   259,     0,     0,     0,     0,
     0,     0,     0,   260,     0,   261,     0,   262,     0,     0,
     0,   263,     0,   264,    22,    23,    24,    25,    26,   453,
     0,     0,   454,    28,    29,    30,     0,     0,     0,    31,
    32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
    42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
    52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
    62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
    72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
    82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
    92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
   102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
   112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
   122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
   132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
   142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
   152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
   162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
   172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
   182,   183,   184,   185,   186,   187,   188,   189,   190,     0,
   191,   192,   193,   194,   195,   196,     0,     0,     0,     0,
     0,   197,   198,   199,   200,   201,   202,   203,   204,   205,
   206,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,   207,   208,   209,   210,   211,     0,     0,   212,     0,
   213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
   223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
   233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
   243,   244,   245,   246,   247,   248,   249,   250,   251,     0,
     0,   252,     0,   253,     0,   254,     0,   255,     0,   256,
     0,   257,     0,     0,     0,   258,     0,   259,     0,     0,
     0,     0,     0,     0,     0,   260,     0,   261,     0,   262,
     0,     0,     0,   263,     0,   264,    22,    23,    24,    25,
    26,    27,     0,     0,     0,    28,    29,    30,     0,     0,
     0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
    40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
    50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
    60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
    70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
    80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
    90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
   100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
   110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
   120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
   130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
   140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
   150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
   160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
   170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
   180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
   190,     0,   191,   192,   193,   194,   195,   196,     0,     0,
     0,     0,     0,   197,   198,   199,   200,   201,   202,   203,
   204,   205,   206,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,   207,   208,   209,   210,   211,     0,     0,
   212,     0,   213,   214,   215,   216,   217,   218,   219,   220,
   221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
   231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
   241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
   251,     0,     0,   252,     0,   253,     0,   254,     0,   255,
   459,   256,     0,   257,     0,     0,     0,   258,     0,   259,
     0,     0,     0,     0,     0,     0,     0,   260,     0,   261,
     0,   262,     0,     0,     0,   263,     0,   264,    22,    23,
    24,    25,    26,    27,     0,     0,   471,    28,    29,    30,
     0,     0,     0,    31,    32,    33,    34,    35,    36,    37,
    38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
    48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
    58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
    68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
    78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
    88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
    98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
   108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
   118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
   128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
   138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
   148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
   158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
   168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
   178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
   188,   189,   190,     0,   191,   192,   193,   194,   195,   196,
     0,     0,     0,     0,     0,   197,   198,   199,   200,   201,
   202,   203,   204,   205,   206,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,   207,   208,   209,   210,   211,
     0,     0,   212,     0,   213,   214,   215,   216,   217,   218,
   219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
   229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
   239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
   249,   250,   251,     0,     0,   252,     0,   253,     0,   254,
     0,   255,     0,   256,     0,   257,     0,     0,     0,   258,
     0,   259,     0,     0,     0,     0,     0,     0,     0,   260,
     0,   261,     0,   262,     0,     0,     0,   263,     0,   264,
    22,    23,    24,    25,    26,    27,     0,     0,   473,    28,
    29,    30,     0,     0,     0,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
    56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
    66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
    76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
    86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
    96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
   106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
   116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
   126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
   136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
   146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
   156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
   166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
   176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
   186,   187,   188,   189,   190,     0,   191,   192,   193,   194,
   195,   196,     0,     0,     0,     0,     0,   197,   198,   199,
   200,   201,   202,   203,   204,   205,   206,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,   207,   208,   209,
   210,   211,     0,     0,   212,     0,   213,   214,   215,   216,
   217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
   227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
   237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
   247,   248,   249,   250,   251,     0,     0,   252,     0,   253,
     0,   254,     0,   255,     0,   256,     0,   257,     0,     0,
     0,   258,     0,   259,     0,     0,     0,     0,     0,     0,
     0,   260,     0,   261,     0,   262,     0,     0,     0,   263,
     0,   264,    22,    23,    24,    25,    26,    27,   491,     0,
     0,    28,    29,    30,     0,     0,     0,    31,    32,    33,
    34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
    44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
    54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
    64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
    74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
    84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
    94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
   104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
   114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
   124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
   134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
   144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
   154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
   164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
   174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
   184,   185,   186,   187,   188,   189,   190,     0,   191,   192,
   193,   194,   195,   196,     0,     0,     0,     0,     0,   197,
   198,   199,   200,   201,   202,   203,   204,   205,   206,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,   207,
   208,   209,   210,   211,     0,     0,   212,     0,   213,   214,
   215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
   225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
   235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
   245,   246,   247,   248,   249,   250,   251,     0,     0,   252,
     0,   253,     0,   254,     0,   255,     0,   256,     0,   257,
     0,     0,     0,   258,     0,   259,     0,     0,     0,     0,
     0,     0,     0,   260,     0,   261,     0,   262,     0,     0,
     0,   263,     0,   264,    22,    23,    24,    25,    26,    27,
   494,     0,     0,    28,    29,    30,     0,     0,     0,    31,
    32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
    42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
    52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
    62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
    72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
    82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
    92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
   102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
   112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
   122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
   132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
   142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
   152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
   162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
   172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
   182,   183,   184,   185,   186,   187,   188,   189,   190,     0,
   191,   192,   328,   329,   330,   331,     0,     0,     0,     0,
     0,   197,   198,   199,   200,   201,   202,   203,   204,   205,
   206,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,   207,   208,   209,   210,   211,     0,     0,   212,     0,
   213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
   223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
   233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
   243,   244,   245,   246,   247,   248,   249,   250,   251,     0,
     0,   252,     0,   253,     0,   254,     0,   255,     0,   256,
     0,   257,     0,     0,     0,   258,     0,   259,     0,     0,
     0,     0,     0,     0,     0,   260,     0,   261,     0,   262,
     0,     0,     0,   263,     0,   264,    22,    23,    24,    25,
    26,    27,   495,     0,     0,    28,    29,    30,     0,     0,
     0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
    40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
    50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
    60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
    70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
    80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
    90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
   100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
   110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
   120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
   130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
   140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
   150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
   160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
   170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
   180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
   190,     0,   191,   192,   328,   329,   330,   331,     0,     0,
     0,     0,     0,   197,   198,   199,   200,   201,   202,   203,
   204,   205,   206,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,   207,   208,   209,   210,   211,     0,     0,
   212,     0,   213,   214,   215,   216,   217,   218,   219,   220,
   221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
   231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
   241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
   251,     0,     0,   252,     0,   253,     0,   254,     0,   255,
     0,   256,     0,   257,     0,     0,     0,   258,     0,   259,
     0,     0,     0,     0,     0,     0,     0,   260,     0,   261,
     0,   262,     0,     0,     0,   263,     0,   264,    22,    23,
    24,    25,    26,    27,   496,     0,     0,    28,    29,    30,
     0,     0,     0,    31,    32,    33,    34,    35,    36,    37,
    38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
    48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
    58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
    68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
    78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
    88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
    98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
   108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
   118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
   128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
   138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
   148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
   158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
   168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
   178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
   188,   189,   190,     0,   191,   192,   328,   329,   330,   331,
     0,     0,     0,     0,     0,   197,   198,   199,   200,   201,
   202,   203,   204,   205,   206,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,   207,   208,   209,   210,   211,
     0,     0,   212,     0,   213,   214,   215,   216,   217,   218,
   219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
   229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
   239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
   249,   250,   251,     0,     0,   252,     0,   253,     0,   254,
     0,   255,     0,   256,     0,   257,     0,     0,     0,   258,
     0,   259,     0,     0,     0,     0,     0,     0,     0,   260,
     0,   261,     0,   262,     0,     0,     0,   263,     0,   264,
    22,    23,    24,    25,    26,    27,   497,     0,     0,    28,
    29,    30,     0,     0,     0,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
    56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
    66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
    76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
    86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
    96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
   106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
   116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
   126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
   136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
   146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
   156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
   166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
   176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
   186,   187,   188,   189,   190,     0,   191,   192,   328,   329,
   330,   331,     0,     0,     0,     0,     0,   197,   198,   199,
   200,   201,   202,   203,   204,   205,   206,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,   207,   208,   209,
   210,   211,     0,     0,   212,     0,   213,   214,   215,   216,
   217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
   227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
   237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
   247,   248,   249,   250,   251,     0,     0,   252,     0,   253,
     0,   254,     0,   255,     0,   256,     0,   257,     0,     0,
     0,   258,     0,   259,     0,     0,     0,     0,     0,     0,
     0,   260,     0,   261,     0,   262,     0,     0,     0,   263,
     0,   264,    22,    23,    24,    25,    26,    27,   498,     0,
     0,    28,    29,    30,     0,     0,     0,    31,    32,    33,
    34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
    44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
    54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
    64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
    74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
    84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
    94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
   104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
   114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
   124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
   134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
   144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
   154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
   164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
   174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
   184,   185,   186,   187,   188,   189,   190,     0,   191,   192,
   328,   329,   330,   331,     0,     0,     0,     0,     0,   197,
   198,   199,   200,   201,   202,   203,   204,   205,   206,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,   207,
   208,   209,   210,   211,     0,     0,   212,     0,   213,   214,
   215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
   225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
   235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
   245,   246,   247,   248,   249,   250,   251,     0,     0,   252,
     0,   253,     0,   254,     0,   255,     0,   256,     0,   257,
     0,     0,     0,   258,     0,   259,     0,     0,     0,     0,
     0,     0,     0,   260,     0,   261,     0,   262,     0,     0,
     0,   263,     0,   264,    22,    23,    24,    25,    26,    27,
   499,     0,     0,    28,    29,    30,     0,     0,     0,    31,
    32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
    42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
    52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
    62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
    72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
    82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
    92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
   102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
   112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
   122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
   132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
   142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
   152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
   162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
   172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
   182,   183,   184,   185,   186,   187,   188,   189,   190,     0,
   191,   192,   193,   194,   195,   196,     0,     0,     0,     0,
     0,   197,   198,   199,   200,   201,   202,   203,   204,   205,
   206,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,   207,   208,   209,   210,   211,     0,     0,   212,     0,
   213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
   223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
   233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
   243,   244,   245,   246,   247,   248,   249,   250,   251,     0,
     0,   252,     0,   253,     0,   254,     0,   255,     0,   256,
     0,   257,     0,     0,     0,   258,     0,   259,     0,     0,
     0,     0,     0,     0,     0,   260,     0,   261,     0,   262,
     0,     0,     0,   263,     0,   264,    22,    23,    24,    25,
    26,    27,     0,   500,     0,    28,    29,    30,     0,     0,
     0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
    40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
    50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
    60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
    70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
    80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
    90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
   100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
   110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
   120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
   130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
   140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
   150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
   160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
   170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
   180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
   190,     0,   191,   192,   193,   194,   195,   196,     0,     0,
     0,     0,     0,   197,   198,   199,   200,   201,   202,   203,
   204,   205,   206,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,   207,   208,   209,   210,   211,     0,     0,
   212,     0,   213,   214,   215,   216,   217,   218,   219,   220,
   221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
   231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
   241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
   251,     0,     0,   252,     0,   253,     0,   254,     0,   255,
     0,   256,     0,   257,     0,     0,     0,   258,     0,   259,
     0,     0,     0,     0,     0,     0,     0,   260,     0,   261,
     0,   262,     0,     0,     0,   263,     0,   264,    22,    23,
    24,    25,    26,    27,   501,     0,     0,    28,    29,    30,
     0,     0,     0,    31,    32,    33,    34,    35,    36,    37,
    38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
    48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
    58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
    68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
    78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
    88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
    98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
   108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
   118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
   128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
   138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
   148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
   158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
   168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
   178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
   188,   189,   190,     0,   191,   192,   193,   194,   195,   196,
     0,     0,     0,     0,     0,   197,   198,   199,   200,   201,
   202,   203,   204,   205,   206,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,   207,   208,   209,   210,   211,
     0,     0,   212,     0,   213,   214,   215,   216,   217,   218,
   219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
   229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
   239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
   249,   250,   251,     0,     0,   252,     0,   253,     0,   254,
     0,   255,     0,   256,     0,   257,     0,     0,     0,   258,
     0,   259,     0,     0,     0,     0,     0,     0,     0,   260,
     0,   261,     0,   262,     0,     0,     0,   263,     0,   264,
    22,    23,    24,    25,    26,    27,   502,     0,     0,    28,
    29,    30,     0,     0,     0,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
    56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
    66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
    76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
    86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
    96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
   106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
   116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
   126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
   136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
   146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
   156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
   166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
   176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
   186,   187,   188,   189,   190,     0,   191,   192,   193,   194,
   195,   196,     0,     0,     0,     0,     0,   197,   198,   199,
   200,   201,   202,   203,   204,   205,   206,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,   207,   208,   209,
   210,   211,     0,     0,   212,     0,   213,   214,   215,   216,
   217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
   227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
   237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
   247,   248,   249,   250,   251,     0,     0,   252,     0,   253,
     0,   254,     0,   255,     0,   256,     0,   257,     0,     0,
     0,   258,     0,   259,     0,     0,     0,     0,     0,     0,
     0,   260,     0,   261,     0,   262,     0,     0,     0,   263,
     0,   264,    22,    23,    24,    25,    26,    27,   507,     0,
     0,    28,    29,    30,     0,     0,     0,    31,    32,    33,
    34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
    44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
    54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
    64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
    74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
    84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
    94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
   104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
   114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
   124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
   134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
   144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
   154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
   164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
   174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
   184,   185,   186,   187,   188,   189,   190,     0,   191,   192,
   193,   194,   195,   196,     0,     0,     0,     0,     0,   197,
   198,   199,   200,   201,   202,   203,   204,   205,   206,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,   207,
   208,   209,   210,   211,     0,     0,   212,     0,   213,   214,
   215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
   225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
   235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
   245,   246,   247,   248,   249,   250,   251,     0,     0,   252,
     0,   253,     0,   254,     0,   255,     0,   256,     0,   257,
     0,     0,     0,   258,     0,   259,     0,     0,     0,     0,
     0,     0,     0,   260,     0,   261,     0,   262,     0,     0,
     0,   263,     0,   264,    22,    23,    24,    25,    26,    27,
   514,     0,     0,    28,    29,    30,     0,     0,     0,    31,
    32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
    42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
    52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
    62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
    72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
    82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
    92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
   102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
   112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
   122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
   132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
   142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
   152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
   162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
   172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
   182,   183,   184,   185,   186,   187,   188,   189,   190,     0,
   191,   192,   193,   194,   195,   196,     0,     0,     0,     0,
     0,   197,   198,   199,   200,   201,   202,   203,   204,   205,
   206,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,   207,   208,   209,   210,   211,     0,     0,   212,     0,
   213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
   223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
   233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
   243,   244,   245,   246,   247,   248,   249,   250,   251,     0,
     0,   252,     0,   253,     0,   254,     0,   255,     0,   256,
     0,   257,     0,     0,     0,   258,     0,   259,     0,     0,
     0,     0,     0,     0,     0,   260,     0,   261,     0,   262,
     0,     0,     0,   263,     0,   264,    22,    23,    24,    25,
    26,    27,   515,     0,     0,    28,    29,    30,     0,     0,
     0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
    40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
    50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
    60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
    70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
    80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
    90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
   100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
   110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
   120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
   130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
   140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
   150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
   160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
   170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
   180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
   190,     0,   191,   192,   193,   194,   195,   196,     0,     0,
     0,     0,     0,   197,   198,   199,   200,   201,   202,   203,
   204,   205,   206,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,   207,   208,   209,   210,   211,     0,     0,
   212,     0,   213,   214,   215,   216,   217,   218,   219,   220,
   221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
   231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
   241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
   251,     0,     0,   252,     0,   253,     0,   254,     0,   255,
     0,   256,     0,   257,     0,     0,     0,   258,     0,   259,
     0,     0,     0,     0,     0,     0,     0,   260,     0,   261,
     0,   262,     0,     0,     0,   263,     0,   264,    22,    23,
    24,    25,    26,    27,     0,   518,     0,    28,    29,    30,
     0,     0,     0,    31,    32,    33,    34,    35,    36,    37,
    38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
    48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
    58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
    68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
    78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
    88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
    98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
   108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
   118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
   128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
   138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
   148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
   158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
   168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
   178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
   188,   189,   190,     0,   191,   192,   193,   194,   195,   196,
     0,     0,     0,     0,     0,   197,   198,   199,   200,   201,
   202,   203,   204,   205,   206,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,   207,   208,   209,   210,   211,
     0,     0,   212,     0,   213,   214,   215,   216,   217,   218,
   219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
   229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
   239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
   249,   250,   251,     0,     0,   252,     0,   253,     0,   254,
     0,   255,     0,   256,     0,   257,     0,     0,     0,   258,
     0,   259,     0,     0,     0,     0,     0,     0,     0,   260,
     0,   261,     0,   262,     0,     0,     0,   263,     0,   264,
   523,    23,    24,    25,    26,    27,   327,     0,     0,    28,
    29,    30,     0,     0,     0,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
    56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
    66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
    76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
    86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
    96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
   106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
   116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
   126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
   136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
   146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
   156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
   166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
   176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
   186,   187,   188,   189,   190,     0,   191,   192,   328,   329,
   330,   331,     0,     0,     0,     0,     0,   197,   198,   199,
   200,   201,   202,   203,   204,   205,   206,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,   207,   208,   209,
   210,   211,     0,     0,   212,     0,   213,   214,   215,   216,
   217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
   227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
   237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
   247,   248,   249,   250,   251,     0,     0,   252,     0,   253,
     0,   254,     0,   255,     0,   256,     0,   257,     0,     0,
     0,   258,     0,   259,     0,     0,     0,     0,     0,     0,
     0,   260,     0,   261,     0,   262,     0,     0,     0,   263,
     0,   264,    22,    23,    24,    25,    26,   525,     0,     0,
   526,    28,    29,    30,     0,     0,     0,    31,    32,    33,
    34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
    44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
    54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
    64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
    74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
    84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
    94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
   104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
   114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
   124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
   134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
   144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
   154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
   164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
   174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
   184,   185,   186,   187,   188,   189,   190,     0,   191,   192,
   193,   194,   195,   196,     0,     0,     0,     0,     0,   197,
   198,   199,   200,   201,   202,   203,   204,   205,   206,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,   207,
   208,   209,   210,   211,     0,     0,   212,     0,   213,   214,
   215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
   225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
   235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
   245,   246,   247,   248,   249,   250,   251,     0,     0,   252,
     0,   253,     0,   254,     0,   255,     0,   256,     0,   257,
     0,     0,     0,   258,     0,   259,     0,     0,     0,     0,
     0,     0,     0,   260,     0,   261,     0,   262,     0,     0,
     0,   263,     0,   264,    22,    23,    24,    25,    26,    27,
     0,     0,     0,    28,    29,    30,     0,     0,     0,    31,
    32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
    42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
    52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
    62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
    72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
    82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
    92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
   102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
   112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
   122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
   132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
   142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
   152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
   162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
   172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
   182,   183,   184,   185,   186,   187,   188,   189,   190,     0,
   191,   192,   193,   194,   195,   196,     0,     0,     0,     0,
     0,   197,   198,   199,   200,   201,   202,   203,   204,   205,
   206,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,   207,   208,   209,   210,   211,     0,     0,   212,     0,
   213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
   223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
   233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
   243,   244,   245,   246,   247,   248,   249,   250,   251,     0,
     0,   252,     0,   253,     0,   254,     0,   255,     0,   256,
     0,   257,     0,     0,     0,   258,   530,   259,     0,     0,
     0,     0,     0,     0,     0,   260,     0,   261,     0,   262,
     0,     0,     0,   263,     0,   264,    22,    23,    24,    25,
    26,    27,     0,     0,   532,    28,    29,    30,     0,     0,
     0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
    40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
    50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
    60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
    70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
    80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
    90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
   100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
   110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
   120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
   130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
   140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
   150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
   160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
   170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
   180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
   190,     0,   191,   192,   193,   194,   195,   196,     0,     0,
     0,     0,     0,   197,   198,   199,   200,   201,   202,   203,
   204,   205,   206,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,   207,   208,   209,   210,   211,     0,     0,
   212,     0,   213,   214,   215,   216,   217,   218,   219,   220,
   221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
   231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
   241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
   251,     0,     0,   252,     0,   253,     0,   254,     0,   255,
     0,   256,     0,   257,     0,     0,     0,   258,     0,   259,
     0,     0,     0,     0,     0,     0,     0,   260,     0,   261,
     0,   262,     0,     0,     0,   263,     0,   264,    22,    23,
    24,    25,    26,    27,     0,     0,   534,    28,    29,    30,
     0,     0,     0,    31,    32,    33,    34,    35,    36,    37,
    38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
    48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
    58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
    68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
    78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
    88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
    98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
   108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
   118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
   128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
   138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
   148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
   158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
   168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
   178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
   188,   189,   190,     0,   191,   192,   193,   194,   195,   196,
     0,     0,     0,     0,     0,   197,   198,   199,   200,   201,
   202,   203,   204,   205,   206,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,   207,   208,   209,   210,   211,
     0,     0,   212,     0,   213,   214,   215,   216,   217,   218,
   219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
   229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
   239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
   249,   250,   251,     0,     0,   252,     0,   253,     0,   254,
     0,   255,     0,   256,     0,   257,     0,     0,     0,   258,
     0,   259,     0,     0,     0,     0,     0,     0,     0,   260,
     0,   261,     0,   262,     0,     0,     0,   263,     0,   264,
    22,    23,    24,    25,    26,    27,     0,     0,     0,    28,
    29,    30,     0,     0,     0,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
    56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
    66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
    76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
    86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
    96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
   106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
   116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
   126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
   136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
   146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
   156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
   166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
   176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
   186,   187,   188,   189,   190,     0,   191,   192,   193,   194,
   195,   196,     0,     0,     0,     0,     0,   197,   198,   199,
   200,   201,   202,   203,   204,   205,   206,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,   207,   208,   209,
   210,   211,     0,     0,   212,     0,   213,   214,   215,   216,
   217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
   227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
   237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
   247,   248,   249,   250,   251,     0,     0,   252,     0,   253,
     0,   254,     0,   255,     0,   256,     0,   257,     0,     0,
     0,   258,     0,   259,     0,     0,     0,     0,     0,     0,
     0,   260,   535,   261,     0,   262,     0,     0,     0,   263,
     0,   264,    22,    23,    24,    25,    26,    27,     0,     0,
     0,    28,    29,    30,     0,     0,     0,    31,    32,    33,
    34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
    44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
    54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
    64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
    74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
    84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
    94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
   104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
   114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
   124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
   134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
   144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
   154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
   164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
   174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
   184,   185,   186,   187,   188,   189,   190,     0,   191,   192,
   193,   194,   195,   196,     0,     0,     0,     0,     0,   197,
   198,   199,   200,   201,   202,   203,   204,   205,   206,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,   207,
   208,   209,   210,   211,     0,     0,   212,     0,   213,   214,
   215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
   225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
   235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
   245,   246,   247,   248,   249,   250,   251,     0,     0,   252,
     0,   253,     0,   254,     0,   255,     0,   256,     0,   257,
     0,     0,     0,   258,     0,   259,     0,     0,     0,     0,
     0,     0,     0,   260,     0,   261,   536,   262,     0,     0,
     0,   263,     0,   264,    22,    23,    24,    25,    26,    27,
     0,     0,     0,    28,    29,    30,     0,     0,     0,    31,
    32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
    42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
    52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
    62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
    72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
    82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
    92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
   102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
   112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
   122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
   132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
   142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
   152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
   162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
   172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
   182,   183,   184,   185,   186,   187,   188,   189,   190,     0,
   191,   192,   193,   194,   195,   196,     0,     0,     0,     0,
     0,   197,   198,   199,   200,   201,   202,   203,   204,   205,
   206,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,   207,   208,   209,   210,   211,     0,     0,   212,     0,
   213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
   223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
   233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
   243,   244,   245,   246,   247,   248,   249,   250,   251,     0,
     0,   252,     0,   253,     0,   254,     0,   255,     0,   256,
     0,   257,     0,     0,     0,   258,     0,   259,     0,     0,
     0,     0,     0,     0,     0,   260,     0,   261,     0,   262,
   537,     0,     0,   263,     0,   264,    22,    23,    24,    25,
    26,    27,     0,     0,     0,    28,    29,    30,     0,     0,
     0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
    40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
    50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
    60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
    70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
    80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
    90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
   100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
   110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
   120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
   130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
   140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
   150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
   160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
   170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
   180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
   190,     0,   191,   192,   193,   194,   195,   196,     0,     0,
     0,     0,     0,   197,   198,   199,   200,   201,   202,   203,
   204,   205,   206,     0,     0,     0,     0,     0,   391,     0,
     0,     0,     0,   207,   208,   209,   210,   211,     0,     0,
   212,     0,   213,   214,   215,   216,   217,   218,   219,   220,
   221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
   231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
   241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
   251,     0,     0,   252,     0,   253,     0,   254,     0,   255,
     0,   256,     0,   257,     0,     0,     0,   258,     0,   259,
     0,     0,     0,     0,     0,     0,     0,   260,     0,   261,
     0,   262,     0,     0,     0,   263,     0,   264,    22,    23,
    24,    25,    26,    27,   545,     0,     0,    28,    29,    30,
     0,     0,     0,    31,    32,    33,    34,    35,    36,    37,
    38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
    48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
    58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
    68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
    78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
    88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
    98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
   108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
   118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
   128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
   138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
   148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
   158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
   168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
   178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
   188,   189,   190,     0,   191,   192,   193,   194,   195,   196,
     0,     0,     0,     0,     0,   197,   198,   199,   200,   201,
   202,   203,   204,   205,   206,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,   207,   208,   209,   210,   211,
     0,     0,   212,     0,   213,   214,   215,   216,   217,   218,
   219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
   229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
   239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
   249,   250,   251,     0,     0,   252,     0,   253,     0,   254,
     0,   255,     0,   256,     0,   257,     0,     0,     0,   258,
     0,   259,     0,     0,     0,     0,     0,     0,     0,   260,
     0,   261,     0,   262,     0,     0,     0,   263,     0,   264,
    22,    23,    24,    25,    26,    27,   546,     0,     0,    28,
    29,    30,     0,     0,     0,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
    56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
    66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
    76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
    86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
    96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
   106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
   116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
   126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
   136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
   146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
   156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
   166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
   176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
   186,   187,   188,   189,   190,     0,   191,   192,   193,   194,
   195,   196,     0,     0,     0,     0,     0,   197,   198,   199,
   200,   201,   202,   203,   204,   205,   206,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,   207,   208,   209,
   210,   211,     0,     0,   212,     0,   213,   214,   215,   216,
   217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
   227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
   237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
   247,   248,   249,   250,   251,     0,     0,   252,     0,   253,
     0,   254,     0,   255,     0,   256,     0,   257,     0,     0,
     0,   258,     0,   259,     0,     0,     0,     0,     0,     0,
     0,   260,     0,   261,     0,   262,     0,     0,     0,   263,
     0,   264,    22,    23,    24,    25,    26,    27,   547,     0,
     0,    28,    29,    30,     0,     0,     0,    31,    32,    33,
    34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
    44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
    54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
    64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
    74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
    84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
    94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
   104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
   114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
   124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
   134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
   144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
   154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
   164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
   174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
   184,   185,   186,   187,   188,   189,   190,     0,   191,   192,
   193,   194,   195,   196,     0,     0,     0,     0,     0,   197,
   198,   199,   200,   201,   202,   203,   204,   205,   206,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,   207,
   208,   209,   210,   211,     0,     0,   212,     0,   213,   214,
   215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
   225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
   235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
   245,   246,   247,   248,   249,   250,   251,     0,     0,   252,
     0,   253,     0,   254,     0,   255,     0,   256,     0,   257,
     0,     0,     0,   258,     0,   259,     0,     0,     0,     0,
     0,     0,     0,   260,     0,   261,     0,   262,     0,     0,
     0,   263,     0,   264,    22,    23,    24,    25,    26,    27,
   548,     0,     0,    28,    29,    30,     0,     0,     0,    31,
    32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
    42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
    52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
    62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
    72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
    82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
    92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
   102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
   112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
   122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
   132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
   142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
   152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
   162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
   172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
   182,   183,   184,   185,   186,   187,   188,   189,   190,     0,
   191,   192,   193,   194,   195,   196,     0,     0,     0,     0,
     0,   197,   198,   199,   200,   201,   202,   203,   204,   205,
   206,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,   207,   208,   209,   210,   211,     0,     0,   212,     0,
   213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
   223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
   233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
   243,   244,   245,   246,   247,   248,   249,   250,   251,     0,
     0,   252,     0,   253,     0,   254,     0,   255,     0,   256,
     0,   257,     0,     0,     0,   258,     0,   259,     0,     0,
     0,     0,     0,     0,     0,   260,     0,   261,     0,   262,
     0,     0,     0,   263,     0,   264,    22,    23,    24,    25,
    26,    27,   549,     0,     0,    28,    29,    30,     0,     0,
     0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
    40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
    50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
    60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
    70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
    80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
    90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
   100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
   110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
   120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
   130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
   140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
   150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
   160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
   170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
   180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
   190,     0,   191,   192,   193,   194,   195,   196,     0,     0,
     0,     0,     0,   197,   198,   199,   200,   201,   202,   203,
   204,   205,   206,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,   207,   208,   209,   210,   211,     0,     0,
   212,     0,   213,   214,   215,   216,   217,   218,   219,   220,
   221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
   231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
   241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
   251,     0,     0,   252,     0,   253,     0,   254,     0,   255,
     0,   256,     0,   257,     0,     0,     0,   258,     0,   259,
     0,     0,     0,     0,     0,     0,     0,   260,     0,   261,
     0,   262,     0,     0,     0,   263,     0,   264,    22,    23,
    24,    25,    26,    27,   550,     0,     0,    28,    29,    30,
     0,     0,     0,    31,    32,    33,    34,    35,    36,    37,
    38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
    48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
    58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
    68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
    78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
    88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
    98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
   108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
   118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
   128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
   138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
   148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
   158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
   168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
   178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
   188,   189,   190,     0,   191,   192,   193,   194,   195,   196,
     0,     0,     0,     0,     0,   197,   198,   199,   200,   201,
   202,   203,   204,   205,   206,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,   207,   208,   209,   210,   211,
     0,     0,   212,     0,   213,   214,   215,   216,   217,   218,
   219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
   229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
   239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
   249,   250,   251,     0,     0,   252,     0,   253,     0,   254,
     0,   255,     0,   256,     0,   257,     0,     0,     0,   258,
     0,   259,     0,     0,     0,     0,     0,     0,     0,   260,
     0,   261,     0,   262,     0,     0,     0,   263,     0,   264,
    22,    23,    24,    25,    26,    27,     0,   556,     0,    28,
    29,    30,     0,     0,     0,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
    56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
    66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
    76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
    86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
    96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
   106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
   116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
   126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
   136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
   146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
   156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
   166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
   176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
   186,   187,   188,   189,   190,     0,   191,   192,   193,   194,
   195,   196,     0,     0,     0,     0,     0,   197,   198,   199,
   200,   201,   202,   203,   204,   205,   206,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,   207,   208,   209,
   210,   211,     0,     0,   212,     0,   213,   214,   215,   216,
   217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
   227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
   237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
   247,   248,   249,   250,   251,     0,     0,   252,     0,   253,
     0,   254,     0,   255,     0,   256,     0,   257,     0,     0,
     0,   258,     0,   259,     0,     0,     0,     0,     0,     0,
     0,   260,     0,   261,     0,   262,     0,     0,     0,   263,
     0,   264,   557,    23,    24,    25,    26,    27,   327,     0,
     0,    28,    29,    30,     0,     0,     0,    31,    32,    33,
    34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
    44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
    54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
    64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
    74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
    84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
    94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
   104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
   114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
   124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
   134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
   144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
   154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
   164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
   174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
   184,   185,   186,   187,   188,   189,   190,     0,   191,   192,
   328,   329,   330,   331,     0,     0,     0,     0,     0,   197,
   198,   199,   200,   201,   202,   203,   204,   205,   206,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,   207,
   208,   209,   210,   211,     0,     0,   212,     0,   213,   214,
   215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
   225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
   235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
   245,   246,   247,   248,   249,   250,   251,     0,     0,   252,
     0,   253,     0,   254,     0,   255,     0,   256,     0,   257,
     0,     0,     0,   258,     0,   259,     0,     0,     0,     0,
     0,     0,     0,   260,     0,   261,     0,   262,     0,     0,
     0,   263,     0,   264,    22,    23,    24,    25,    26,    27,
     0,   559,     0,    28,    29,    30,     0,     0,     0,    31,
    32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
    42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
    52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
    62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
    72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
    82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
    92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
   102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
   112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
   122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
   132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
   142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
   152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
   162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
   172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
   182,   183,   184,   185,   186,   187,   188,   189,   190,     0,
   191,   192,   193,   194,   195,   196,     0,     0,     0,     0,
     0,   197,   198,   199,   200,   201,   202,   203,   204,   205,
   206,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,   207,   208,   209,   210,   211,     0,     0,   212,     0,
   213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
   223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
   233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
   243,   244,   245,   246,   247,   248,   249,   250,   251,     0,
     0,   252,     0,   253,     0,   254,     0,   255,     0,   256,
     0,   257,     0,     0,     0,   258,     0,   259,     0,     0,
     0,     0,     0,     0,     0,   260,     0,   261,     0,   262,
     0,     0,     0,   263,     0,   264,    22,    23,    24,    25,
    26,    27,     0,   561,     0,    28,    29,    30,     0,     0,
     0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
    40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
    50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
    60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
    70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
    80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
    90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
   100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
   110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
   120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
   130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
   140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
   150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
   160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
   170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
   180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
   190,     0,   191,   192,   193,   194,   195,   196,     0,     0,
     0,     0,     0,   197,   198,   199,   200,   201,   202,   203,
   204,   205,   206,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,   207,   208,   209,   210,   211,     0,     0,
   212,     0,   213,   214,   215,   216,   217,   218,   219,   220,
   221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
   231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
   241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
   251,     0,     0,   252,     0,   253,     0,   254,     0,   255,
     0,   256,     0,   257,     0,     0,     0,   258,     0,   259,
     0,     0,     0,     0,     0,     0,     0,   260,     0,   261,
     0,   262,     0,     0,     0,   263,     0,   264,    22,    23,
    24,    25,    26,    27,   563,     0,     0,    28,    29,    30,
     0,     0,     0,    31,    32,    33,    34,    35,    36,    37,
    38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
    48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
    58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
    68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
    78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
    88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
    98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
   108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
   118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
   128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
   138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
   148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
   158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
   168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
   178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
   188,   189,   190,     0,   191,   192,   193,   194,   195,   196,
     0,     0,     0,     0,     0,   197,   198,   199,   200,   201,
   202,   203,   204,   205,   206,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,   207,   208,   209,   210,   211,
     0,     0,   212,     0,   213,   214,   215,   216,   217,   218,
   219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
   229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
   239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
   249,   250,   251,     0,     0,   252,     0,   253,     0,   254,
     0,   255,     0,   256,     0,   257,     0,     0,     0,   258,
     0,   259,     0,     0,     0,     0,     0,     0,     0,   260,
     0,   261,     0,   262,     0,     0,     0,   263,     0,   264,
    22,    23,    24,    25,    26,    27,     0,   573,     0,    28,
    29,    30,     0,     0,     0,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
    56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
    66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
    76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
    86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
    96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
   106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
   116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
   126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
   136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
   146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
   156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
   166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
   176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
   186,   187,   188,   189,   190,     0,   191,   192,   193,   194,
   195,   196,     0,     0,     0,     0,     0,   197,   198,   199,
   200,   201,   202,   203,   204,   205,   206,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,   207,   208,   209,
   210,   211,     0,     0,   212,     0,   213,   214,   215,   216,
   217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
   227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
   237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
   247,   248,   249,   250,   251,     0,     0,   252,     0,   253,
     0,   254,     0,   255,     0,   256,     0,   257,     0,     0,
     0,   258,     0,   259,     0,     0,     0,     0,     0,     0,
     0,   260,     0,   261,     0,   262,     0,     0,     0,   263,
     0,   264,    22,    23,    24,    25,    26,    27,     0,   575,
     0,    28,    29,    30,     0,     0,     0,    31,    32,    33,
    34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
    44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
    54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
    64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
    74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
    84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
    94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
   104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
   114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
   124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
   134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
   144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
   154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
   164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
   174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
   184,   185,   186,   187,   188,   189,   190,     0,   191,   192,
   193,   194,   195,   196,     0,     0,     0,     0,     0,   197,
   198,   199,   200,   201,   202,   203,   204,   205,   206,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,   207,
   208,   209,   210,   211,     0,     0,   212,     0,   213,   214,
   215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
   225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
   235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
   245,   246,   247,   248,   249,   250,   251,     0,     0,   252,
     0,   253,     0,   254,     0,   255,     0,   256,     0,   257,
     0,     0,     0,   258,     0,   259,     0,     0,     0,     0,
     0,     0,     0,   260,     0,   261,     0,   262,     0,     0,
     0,   263,     0,   264,    22,    23,    24,    25,    26,    27,
     0,   577,     0,    28,    29,    30,     0,     0,     0,    31,
    32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
    42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
    52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
    62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
    72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
    82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
    92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
   102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
   112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
   122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
   132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
   142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
   152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
   162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
   172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
   182,   183,   184,   185,   186,   187,   188,   189,   190,     0,
   191,   192,   193,   194,   195,   196,     0,     0,     0,     0,
     0,   197,   198,   199,   200,   201,   202,   203,   204,   205,
   206,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,   207,   208,   209,   210,   211,     0,     0,   212,     0,
   213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
   223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
   233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
   243,   244,   245,   246,   247,   248,   249,   250,   251,     0,
     0,   252,     0,   253,     0,   254,     0,   255,     0,   256,
     0,   257,     0,     0,     0,   258,     0,   259,     0,     0,
     0,     0,     0,     0,     0,   260,     0,   261,     0,   262,
     0,     0,     0,   263,     0,   264,    22,    23,    24,    25,
    26,    27,   578,     0,     0,    28,    29,    30,     0,     0,
     0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
    40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
    50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
    60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
    70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
    80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
    90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
   100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
   110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
   120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
   130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
   140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
   150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
   160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
   170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
   180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
   190,     0,   191,   192,   193,   194,   195,   196,     0,     0,
     0,     0,     0,   197,   198,   199,   200,   201,   202,   203,
   204,   205,   206,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,   207,   208,   209,   210,   211,     0,     0,
   212,     0,   213,   214,   215,   216,   217,   218,   219,   220,
   221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
   231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
   241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
   251,     0,     0,   252,     0,   253,     0,   254,     0,   255,
     0,   256,     0,   257,     0,     0,     0,   258,     0,   259,
     0,     0,     0,     0,     0,     0,     0,   260,     0,   261,
     0,   262,     0,     0,     0,   263,     0,   264,    22,    23,
    24,    25,    26,    27,   579,     0,     0,    28,    29,    30,
     0,     0,     0,    31,    32,    33,    34,    35,    36,    37,
    38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
    48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
    58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
    68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
    78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
    88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
    98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
   108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
   118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
   128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
   138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
   148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
   158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
   168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
   178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
   188,   189,   190,     0,   191,   192,   193,   194,   195,   196,
     0,     0,     0,     0,     0,   197,   198,   199,   200,   201,
   202,   203,   204,   205,   206,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,   207,   208,   209,   210,   211,
     0,     0,   212,     0,   213,   214,   215,   216,   217,   218,
   219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
   229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
   239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
   249,   250,   251,     0,     0,   252,     0,   253,     0,   254,
     0,   255,     0,   256,     0,   257,     0,     0,     0,   258,
     0,   259,     0,     0,     0,     0,     0,     0,     0,   260,
     0,   261,     0,   262,     0,     0,     0,   263,     0,   264,
    22,    23,    24,    25,    26,    27,   581,     0,     0,    28,
    29,    30,     0,     0,     0,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
    56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
    66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
    76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
    86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
    96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
   106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
   116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
   126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
   136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
   146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
   156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
   166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
   176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
   186,   187,   188,   189,   190,     0,   191,   192,   193,   194,
   195,   196,     0,     0,     0,     0,     0,   197,   198,   199,
   200,   201,   202,   203,   204,   205,   206,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,   207,   208,   209,
   210,   211,     0,     0,   212,     0,   213,   214,   215,   216,
   217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
   227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
   237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
   247,   248,   249,   250,   251,     0,     0,   252,     0,   253,
     0,   254,     0,   255,     0,   256,     0,   257,     0,     0,
     0,   258,     0,   259,     0,     0,     0,     0,     0,     0,
     0,   260,     0,   261,     0,   262,     0,     0,     0,   263,
     0,   264,    22,    23,    24,    25,    26,    27,   582,     0,
     0,    28,    29,    30,     0,     0,     0,    31,    32,    33,
    34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
    44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
    54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
    64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
    74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
    84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
    94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
   104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
   114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
   124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
   134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
   144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
   154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
   164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
   174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
   184,   185,   186,   187,   188,   189,   190,     0,   191,   192,
   193,   194,   195,   196,     0,     0,     0,     0,     0,   197,
   198,   199,   200,   201,   202,   203,   204,   205,   206,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,   207,
   208,   209,   210,   211,     0,     0,   212,     0,   213,   214,
   215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
   225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
   235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
   245,   246,   247,   248,   249,   250,   251,     0,     0,   252,
     0,   253,     0,   254,     0,   255,     0,   256,     0,   257,
     0,     0,     0,   258,     0,   259,     0,     0,     0,     0,
     0,     0,     0,   260,     0,   261,     0,   262,     0,     0,
     0,   263,     0,   264,    22,    23,    24,    25,    26,    27,
   589,     0,     0,    28,    29,    30,     0,     0,     0,    31,
    32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
    42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
    52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
    62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
    72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
    82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
    92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
   102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
   112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
   122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
   132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
   142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
   152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
   162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
   172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
   182,   183,   184,   185,   186,   187,   188,   189,   190,     0,
   191,   192,   193,   194,   195,   196,     0,     0,     0,     0,
     0,   197,   198,   199,   200,   201,   202,   203,   204,   205,
   206,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,   207,   208,   209,   210,   211,     0,     0,   212,     0,
   213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
   223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
   233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
   243,   244,   245,   246,   247,   248,   249,   250,   251,     0,
     0,   252,     0,   253,     0,   254,     0,   255,     0,   256,
     0,   257,     0,     0,     0,   258,     0,   259,     0,     0,
     0,     0,     0,     0,     0,   260,     0,   261,     0,   262,
     0,     0,     0,   263,     0,   264,    22,    23,    24,    25,
    26,    27,     0,     0,     0,    28,    29,    30,     0,     0,
     0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
    40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
    50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
    60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
    70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
    80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
    90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
   100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
   110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
   120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
   130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
   140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
   150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
   160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
   170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
   180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
   190,     0,   191,   192,   193,   194,   195,   196,     0,     0,
     0,     0,     0,   197,   198,   199,   200,   201,   202,   203,
   204,   205,   206,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,   207,   208,   209,   210,   211,     0,     0,
   212,     0,   213,   214,   215,   216,   217,   218,   219,   220,
   221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
   231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
   241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
   251,     0,     0,   252,     0,   253,     0,   254,     0,   255,
     0,   256,     0,   257,     0,     0,     0,   258,     0,   259,
     0,     0,     0,     0,     0,     0,     0,   260,     0,   261,
     0,   262,     0,     0,     0,   263,     0,   264
};

static const short yycheck[] = {     6,
     7,    13,     2,     8,   352,   305,    13,   207,   254,   186,
   210,   211,    12,   218,   259,   218,   185,   258,     8,    19,
    27,     3,     3,     5,     5,     8,   263,     9,     9,     8,
     8,     8,   201,   202,    11,   204,   201,   202,     3,   204,
     5,   206,   201,   202,     8,   204,     8,   206,   201,   202,
     8,   204,     8,    11,   254,    11,     8,     8,     8,     8,
   265,     8,   265,     8,     8,     8,     8,     8,     8,     8,
     8,   285,   287,   289,     8,     8,     8,     8,     8,     3,
     9,   258,     9,     9,     9,     3,     8,   218,   269,   271,
     9,     8,     3,     9,     8,     8,     8,   385,   398,     8,
     8,     0,     9,     9,     8,     8,     3,     9,     8,     3,
   310,   311,   312,   313,   314,   360,     9,   363,     9,     0,
     4,     3,   366,   370,    -1,   305,   304,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   338,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   365,    -1,    -1,    -1,   369,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   490,   391,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   551,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   252,    -1,    -1,   255,   256,
   257,    -1,   259,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   307,    -1,   304,   305,   306,
   307,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   315,   309,
    -1,    -1,    -1,    -1,    -1,   322,   323,    -1,   325,   326,
    -1,   328,   329,   330,   331,    -1,    -1,    -1,    -1,    -1,
   337,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   346,
   347,   348,    -1,   350,    -1,    -1,   353,    -1,    -1,    -1,
    -1,    -1,    -1,   360,   361,    -1,    -1,    -1,    -1,    -1,
    -1,   368,    -1,    -1,    -1,   372,   373,   374,   375,    -1,
    -1,   378,    -1,   380,    -1,   382,    -1,   384,   385,   386,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   394,    -1,    -1,
   402,   398,    -1,    -1,   401,   402,   403,    -1,   405,    -1,
   407,    -1,   409,    -1,   411,    -1,    -1,   414,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   424,   425,   426,
   427,    -1,    -1,    -1,    -1,    -1,    -1,   434,   435,   436,
   437,   438,   439,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   452,   453,   454,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   462,    -1,    -1,    -1,    -1,
   467,    -1,    -1,    -1,   471,    -1,   473,    -1,    -1,   476,
    -1,    -1,    -1,    -1,    -1,    -1,   483,    -1,   485,    -1,
    -1,   488,    -1,   490,    -1,    -1,   493,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   525,   526,
    -1,    -1,    -1,    -1,    -1,   532,    -1,   534,    -1,    -1,
    -1,    -1,   539,    -1,    -1,    -1,   543,   544,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   552,   553,    -1,   555,    -1,
    -1,    -1,   559,    -1,   561,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,   569,    -1,    -1,   572,    -1,    -1,   575,    -1,
   577,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   590,    -1,    -1,   593,     3,     4,     5,
     6,     7,     8,    -1,    -1,    -1,    12,    13,    14,    -1,
    -1,    -1,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
    56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
    66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
    76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
    86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
    96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
   106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
   116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
   126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
   136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
   146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
   156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
   166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
   176,   177,    -1,   179,   180,   181,   182,   183,   184,    -1,
    -1,    -1,    -1,    -1,   190,   191,   192,   193,   194,   195,
   196,   197,   198,   199,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,   210,   211,   212,   213,   214,    -1,
    -1,   217,    -1,   219,   220,   221,   222,   223,   224,   225,
   226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
   236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
   246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
   256,   257,    -1,    -1,   260,    -1,   262,    -1,   264,    -1,
   266,    -1,   268,    -1,   270,    -1,    -1,    -1,   274,    -1,
   276,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,    -1,
   286,    -1,   288,    -1,    -1,    -1,   292,    -1,   294,   295,
     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    12,
    13,    14,    -1,    -1,    -1,    18,    19,    20,    21,    22,
    23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
    33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
    43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
    53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
    63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
    73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
    83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
    93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
   103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
   113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
   123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
   133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
   143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
   153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
   163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
   173,   174,   175,   176,   177,    -1,   179,   180,   181,   182,
   183,   184,    -1,    -1,   187,   188,   189,   190,   191,   192,
   193,   194,   195,   196,   197,   198,   199,   200,    -1,    -1,
    -1,    -1,    -1,    -1,   207,    -1,    -1,   210,   211,   212,
   213,   214,    -1,    -1,   217,    -1,   219,   220,   221,   222,
   223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
   233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
   243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
   253,   254,   255,   256,   257,    -1,   259,   260,    -1,   262,
    -1,   264,    -1,   266,    -1,   268,    -1,   270,    -1,    -1,
    -1,   274,    -1,   276,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   284,    -1,   286,    -1,   288,    -1,    -1,    -1,   292,
    -1,   294,     3,     4,     5,     6,     7,     8,    -1,    -1,
    -1,    12,    13,    14,    -1,    -1,    -1,    18,    19,    20,
    21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
    31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
    41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
    51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
    61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
    71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
    81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
    91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
   101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
   111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
   121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
   131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
   141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
   151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
   161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
   171,   172,   173,   174,   175,   176,   177,    -1,   179,   180,
   181,   182,   183,   184,    -1,    -1,   187,   188,   189,   190,
   191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
    -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,    -1,   210,
   211,   212,   213,   214,    -1,    -1,   217,    -1,   219,   220,
   221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
   231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
   241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
   251,   252,   253,   254,   255,   256,   257,    -1,   259,   260,
    -1,   262,    -1,   264,    -1,   266,    -1,   268,    -1,   270,
    -1,    -1,    -1,   274,    -1,   276,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   284,    -1,   286,    -1,   288,    -1,    -1,
    -1,   292,    -1,   294,     3,     4,     5,     6,     7,     8,
    -1,    -1,    -1,    12,    13,    14,    -1,    -1,    -1,    18,
    19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
    29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
    39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
    49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
    59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
    69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
    79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
    89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
    99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
   109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
   119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
   129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
   139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
   149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
   159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
   169,   170,   171,   172,   173,   174,   175,   176,   177,    -1,
   179,   180,   181,   182,   183,   184,    -1,    -1,   187,   188,
   189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
   199,   200,    -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,
    -1,   210,   211,   212,   213,   214,    -1,    -1,   217,    -1,
   219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
   229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
   239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
   249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
   259,   260,    -1,   262,    -1,   264,    -1,   266,    -1,   268,
    -1,   270,    -1,    -1,    -1,   274,    -1,   276,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   284,    -1,   286,    -1,   288,
    -1,    -1,    -1,   292,    -1,   294,     3,     4,     5,     6,
     7,     8,    -1,    -1,    -1,    12,    13,    14,    -1,    -1,
    -1,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
    47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
    57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
    67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
    77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
    87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
    97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
   107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
   117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
   127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
   137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
   147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
   157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
   167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
   177,    -1,   179,   180,   181,   182,   183,   184,    -1,    -1,
   187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
   197,   198,   199,   200,    -1,    -1,    -1,    -1,    -1,    -1,
   207,    -1,    -1,   210,   211,   212,   213,   214,    -1,    -1,
   217,    -1,   219,   220,   221,   222,   223,   224,   225,   226,
   227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
   237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
   247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
   257,    -1,    -1,   260,    -1,   262,    -1,   264,    -1,   266,
    -1,   268,    -1,   270,    -1,    -1,    -1,   274,    -1,   276,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,    -1,   286,
    -1,   288,    -1,    -1,    -1,   292,    -1,   294,     3,     4,
     5,     6,     7,     8,    -1,    -1,    -1,    12,    13,    14,
    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,    24,
    25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
    35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
    45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
    55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
    65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
    75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
    85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
    95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
   105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
   115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
   125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
   135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
   145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
   155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
   165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
   175,   176,   177,    -1,   179,   180,   181,   182,   183,   184,
    -1,    -1,    -1,    -1,    -1,   190,   191,   192,   193,   194,
   195,   196,   197,   198,   199,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   208,   209,   210,   211,   212,   213,   214,
    -1,    -1,   217,    -1,   219,   220,   221,   222,   223,   224,
   225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
   235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
   245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
   255,   256,   257,    -1,    -1,   260,    -1,   262,    -1,   264,
    -1,   266,    -1,   268,    -1,   270,    -1,    -1,    -1,   274,
    -1,   276,   277,    -1,    -1,    -1,    -1,    -1,    -1,   284,
    -1,   286,    -1,   288,    -1,    -1,    -1,   292,    -1,   294,
     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    12,
    13,    14,    -1,    -1,    -1,    18,    19,    20,    21,    22,
    23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
    33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
    43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
    53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
    63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
    73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
    83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
    93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
   103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
   113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
   123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
   133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
   143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
   153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
   163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
   173,   174,   175,   176,   177,    -1,   179,   180,   181,   182,
   183,   184,    -1,    -1,    -1,    -1,    -1,   190,   191,   192,
   193,   194,   195,   196,   197,   198,   199,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   208,   209,   210,   211,   212,
   213,   214,    -1,    -1,   217,    -1,   219,   220,   221,   222,
   223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
   233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
   243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
   253,   254,   255,   256,   257,    -1,    -1,   260,    -1,   262,
    -1,   264,    -1,   266,    -1,   268,    -1,   270,    -1,    -1,
    -1,   274,    -1,   276,   277,    -1,    -1,    -1,    -1,    -1,
    -1,   284,    -1,   286,    -1,   288,    -1,    -1,    -1,   292,
    -1,   294,     3,     4,     5,     6,     7,     8,     9,    -1,
    -1,    12,    13,    14,    -1,    -1,    -1,    18,    19,    20,
    21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
    31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
    41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
    51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
    61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
    71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
    81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
    91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
   101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
   111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
   121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
   131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
   141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
   151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
   161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
   171,   172,   173,   174,   175,   176,   177,    -1,   179,   180,
   181,   182,   183,   184,    -1,    -1,    -1,    -1,    -1,   190,
   191,   192,   193,   194,   195,   196,   197,   198,   199,    -1,
    -1,    -1,   203,    -1,   205,    -1,    -1,    -1,    -1,   210,
   211,   212,   213,   214,    -1,    -1,   217,    -1,   219,   220,
   221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
   231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
   241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
   251,   252,   253,   254,   255,   256,   257,    -1,    -1,   260,
    -1,   262,    -1,   264,    -1,   266,    -1,   268,    -1,   270,
    -1,    -1,    -1,   274,    -1,   276,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   284,    -1,   286,    -1,   288,    -1,    -1,
    -1,   292,    -1,   294,     3,     4,     5,     6,     7,     8,
    -1,    -1,    -1,    12,    13,    14,    -1,    -1,    -1,    18,
    19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
    29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
    39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
    49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
    59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
    69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
    79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
    89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
    99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
   109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
   119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
   129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
   139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
   149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
   159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
   169,   170,   171,   172,   173,   174,   175,   176,   177,    -1,
   179,   180,   181,   182,   183,   184,    -1,    -1,    -1,    -1,
    -1,   190,   191,   192,   193,   194,   195,   196,   197,   198,
   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   208,
   209,   210,   211,   212,   213,   214,    -1,    -1,   217,    -1,
   219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
   229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
   239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
   249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
    -1,   260,    -1,   262,   263,   264,    -1,   266,    -1,   268,
    -1,   270,    -1,    -1,    -1,   274,    -1,   276,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   284,    -1,   286,    -1,   288,
    -1,    -1,    -1,   292,    -1,   294,     3,     4,     5,     6,
     7,     8,    -1,    -1,    -1,    12,    13,    14,    15,    16,
    -1,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
    47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
    57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
    67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
    77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
    87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
    97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
   107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
   117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
   127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
   137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
   147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
   157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
   167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
   177,    -1,   179,   180,   181,   182,   183,   184,    -1,    -1,
    -1,    -1,    -1,   190,   191,   192,   193,   194,   195,   196,
   197,   198,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   210,   211,   212,   213,   214,    -1,    -1,
   217,    -1,   219,   220,   221,   222,   223,   224,   225,   226,
   227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
   237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
   247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
   257,    -1,    -1,   260,    -1,   262,    -1,   264,    -1,   266,
    -1,   268,    -1,   270,    -1,    -1,    -1,   274,    -1,   276,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,    -1,   286,
    -1,   288,    -1,    -1,    -1,   292,   293,   294,     3,     4,
     5,     6,     7,     8,     9,    -1,    -1,    12,    13,    14,
    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,    24,
    25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
    35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
    45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
    55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
    65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
    75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
    85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
    95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
   105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
   115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
   125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
   135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
   145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
   155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
   165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
   175,   176,   177,    -1,   179,   180,   181,   182,   183,   184,
    -1,    -1,    -1,    -1,    -1,   190,   191,   192,   193,   194,
   195,   196,   197,   198,   199,    -1,    -1,    -1,    -1,    -1,
   205,    -1,    -1,    -1,    -1,   210,   211,   212,   213,   214,
    -1,    -1,   217,    -1,   219,   220,   221,   222,   223,   224,
   225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
   235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
   245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
   255,   256,   257,    -1,    -1,   260,    -1,   262,    -1,   264,
    -1,   266,    -1,   268,    -1,   270,    -1,    -1,    -1,   274,
    -1,   276,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,
    -1,   286,    -1,   288,    -1,    -1,    -1,   292,    -1,   294,
     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    12,
    13,    14,    -1,    -1,    -1,    18,    19,    20,    21,    22,
    23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
    33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
    43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
    53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
    63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
    73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
    83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
    93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
   103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
   113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
   123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
   133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
   143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
   153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
   163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
   173,   174,   175,   176,   177,    -1,   179,   180,   181,   182,
   183,   184,    -1,    -1,    -1,    -1,    -1,   190,   191,   192,
   193,   194,   195,   196,   197,   198,   199,    -1,    -1,    -1,
   203,    -1,   205,    -1,    -1,    -1,    -1,   210,   211,   212,
   213,   214,    -1,    -1,   217,    -1,   219,   220,   221,   222,
   223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
   233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
   243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
   253,   254,   255,   256,   257,    -1,    -1,   260,    -1,   262,
    -1,   264,    -1,   266,    -1,   268,    -1,   270,    -1,    -1,
    -1,   274,    -1,   276,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   284,    -1,   286,    -1,   288,    -1,    -1,    -1,   292,
    -1,   294,     3,     4,     5,     6,     7,     8,    -1,    -1,
    -1,    12,    13,    14,    -1,    -1,    -1,    18,    19,    20,
    21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
    31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
    41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
    51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
    61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
    71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
    81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
    91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
   101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
   111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
   121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
   131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
   141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
   151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
   161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
   171,   172,   173,   174,   175,   176,   177,    -1,   179,   180,
   181,   182,   183,   184,    -1,    -1,    -1,    -1,    -1,   190,
   191,   192,   193,   194,   195,   196,   197,   198,   199,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   208,   209,   210,
   211,   212,   213,   214,    -1,    -1,   217,    -1,   219,   220,
   221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
   231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
   241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
   251,   252,   253,   254,   255,   256,   257,    -1,    -1,   260,
    -1,   262,    -1,   264,    -1,   266,    -1,   268,    -1,   270,
    -1,    -1,    -1,   274,    -1,   276,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   284,    -1,   286,    -1,   288,    -1,    -1,
    -1,   292,    -1,   294,     3,     4,     5,     6,     7,     8,
    -1,    -1,    -1,    12,    13,    14,    -1,    -1,    -1,    18,
    19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
    29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
    39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
    49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
    59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
    69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
    79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
    89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
    99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
   109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
   119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
   129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
   139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
   149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
   159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
   169,   170,   171,   172,   173,   174,   175,   176,   177,    -1,
   179,   180,   181,   182,   183,   184,    -1,    -1,    -1,    -1,
    -1,   190,   191,   192,   193,   194,   195,   196,   197,   198,
   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   210,   211,   212,   213,   214,    -1,   216,   217,    -1,
   219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
   229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
   239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
   249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
    -1,   260,    -1,   262,    -1,   264,    -1,   266,    -1,   268,
   269,   270,    -1,    -1,    -1,   274,    -1,   276,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   284,    -1,   286,    -1,   288,
    -1,    -1,    -1,   292,    -1,   294,     3,     4,     5,     6,
     7,     8,    -1,    -1,    -1,    12,    13,    14,    -1,    -1,
    -1,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
    47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
    57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
    67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
    77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
    87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
    97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
   107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
   117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
   127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
   137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
   147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
   157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
   167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
   177,    -1,   179,   180,   181,   182,   183,   184,    -1,    -1,
    -1,    -1,    -1,   190,   191,   192,   193,   194,   195,   196,
   197,   198,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   210,   211,   212,   213,   214,    -1,   216,
   217,    -1,   219,   220,   221,   222,   223,   224,   225,   226,
   227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
   237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
   247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
   257,    -1,    -1,   260,    -1,   262,    -1,   264,    -1,   266,
    -1,   268,    -1,   270,   271,    -1,    -1,   274,    -1,   276,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,    -1,   286,
    -1,   288,    -1,    -1,    -1,   292,    -1,   294,     3,     4,
     5,     6,     7,     8,    -1,    -1,    -1,    12,    13,    14,
    15,    16,    -1,    18,    19,    20,    21,    22,    23,    24,
    25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
    35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
    45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
    55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
    65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
    75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
    85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
    95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
   105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
   115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
   125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
   135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
   145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
   155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
   165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
   175,   176,   177,    -1,   179,   180,   181,   182,   183,   184,
    -1,    -1,    -1,    -1,    -1,   190,   191,   192,   193,   194,
   195,   196,   197,   198,   199,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   210,   211,   212,   213,   214,
    -1,    -1,   217,    -1,   219,   220,   221,   222,   223,   224,
   225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
   235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
   245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
   255,   256,   257,    -1,    -1,   260,    -1,   262,    -1,   264,
    -1,   266,    -1,   268,    -1,   270,    -1,    -1,    -1,   274,
    -1,   276,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,
    -1,   286,    -1,   288,    -1,    -1,    -1,   292,    -1,   294,
     3,     4,     5,     6,     7,     8,     9,    -1,    -1,    12,
    13,    14,    -1,    -1,    -1,    18,    19,    20,    21,    22,
    23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
    33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
    43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
    53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
    63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
    73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
    83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
    93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
   103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
   113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
   123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
   133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
   143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
   153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
   163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
   173,   174,   175,   176,   177,    -1,   179,   180,   181,   182,
   183,   184,    -1,    -1,    -1,    -1,    -1,   190,   191,   192,
   193,   194,   195,   196,   197,   198,   199,    -1,    -1,    -1,
    -1,    -1,   205,    -1,    -1,    -1,    -1,   210,   211,   212,
   213,   214,    -1,    -1,   217,    -1,   219,   220,   221,   222,
   223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
   233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
   243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
   253,   254,   255,   256,   257,    -1,    -1,   260,    -1,   262,
    -1,   264,    -1,   266,    -1,   268,    -1,   270,    -1,    -1,
    -1,   274,    -1,   276,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   284,    -1,   286,    -1,   288,    -1,    -1,    -1,   292,
    -1,   294,     3,     4,     5,     6,     7,     8,     9,    -1,
    -1,    12,    13,    14,    -1,    -1,    -1,    18,    19,    20,
    21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
    31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
    41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
    51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
    61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
    71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
    81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
    91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
   101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
   111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
   121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
   131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
   141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
   151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
   161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
   171,   172,   173,   174,   175,   176,   177,    -1,   179,   180,
   181,   182,   183,   184,    -1,    -1,    -1,    -1,    -1,   190,
   191,   192,   193,   194,   195,   196,   197,   198,   199,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,
   211,   212,   213,   214,    -1,    -1,   217,    -1,   219,   220,
   221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
   231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
   241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
   251,   252,   253,   254,   255,   256,   257,    -1,    -1,   260,
    -1,   262,    -1,   264,    -1,   266,    -1,   268,    -1,   270,
    -1,    -1,    -1,   274,    -1,   276,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   284,    -1,   286,    -1,   288,    -1,    -1,
    -1,   292,    -1,   294,     3,     4,     5,     6,     7,     8,
    -1,    -1,    -1,    12,    13,    14,    -1,    -1,    -1,    18,
    19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
    29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
    39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
    49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
    59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
    69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
    79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
    89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
    99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
   109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
   119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
   129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
   139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
   149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
   159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
   169,   170,   171,   172,   173,   174,   175,   176,   177,    -1,
   179,   180,   181,   182,   183,   184,    -1,    -1,    -1,    -1,
    -1,   190,   191,   192,   193,   194,   195,   196,   197,   198,
   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   210,   211,   212,   213,   214,    -1,    -1,   217,    -1,
   219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
   229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
   239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
   249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
    -1,   260,   261,   262,    -1,   264,    -1,   266,    -1,   268,
    -1,   270,    -1,    -1,    -1,   274,    -1,   276,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   284,    -1,   286,    -1,   288,
    -1,    -1,    -1,   292,    -1,   294,     3,     4,     5,     6,
     7,     8,    -1,    -1,    -1,    12,    13,    14,    -1,    -1,
    -1,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
    47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
    57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
    67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
    77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
    87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
    97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
   107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
   117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
   127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
   137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
   147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
   157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
   167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
   177,    -1,   179,   180,   181,   182,   183,   184,    -1,    -1,
    -1,    -1,    -1,   190,   191,   192,   193,   194,   195,   196,
   197,   198,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   210,   211,   212,   213,   214,    -1,   216,
   217,    -1,   219,   220,   221,   222,   223,   224,   225,   226,
   227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
   237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
   247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
   257,    -1,    -1,   260,    -1,   262,    -1,   264,    -1,   266,
    -1,   268,    -1,   270,    -1,    -1,    -1,   274,    -1,   276,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,    -1,   286,
    -1,   288,    -1,    -1,    -1,   292,    -1,   294,     3,     4,
     5,     6,     7,     8,    -1,    -1,    -1,    12,    13,    14,
    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,    24,
    25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
    35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
    45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
    55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
    65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
    75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
    85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
    95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
   105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
   115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
   125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
   135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
   145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
   155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
   165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
   175,   176,   177,    -1,   179,   180,   181,   182,   183,   184,
    -1,    -1,    -1,    -1,    -1,   190,   191,   192,   193,   194,
   195,   196,   197,   198,   199,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   210,   211,   212,   213,   214,
    -1,   216,   217,    -1,   219,   220,   221,   222,   223,   224,
   225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
   235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
   245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
   255,   256,   257,    -1,    -1,   260,    -1,   262,    -1,   264,
    -1,   266,    -1,   268,    -1,   270,    -1,    -1,    -1,   274,
    -1,   276,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,
    -1,   286,    -1,   288,    -1,    -1,    -1,   292,    -1,   294,
     3,     4,     5,     6,     7,     8,     9,    -1,    -1,    12,
    13,    14,    -1,    -1,    -1,    18,    19,    20,    21,    22,
    23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
    33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
    43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
    53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
    63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
    73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
    83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
    93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
   103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
   113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
   123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
   133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
   143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
   153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
   163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
   173,   174,   175,   176,   177,    -1,   179,   180,   181,   182,
   183,   184,    -1,    -1,    -1,    -1,    -1,   190,   191,   192,
   193,   194,   195,   196,   197,   198,   199,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,   211,   212,
   213,   214,    -1,    -1,   217,    -1,   219,   220,   221,   222,
   223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
   233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
   243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
   253,   254,   255,   256,   257,    -1,    -1,   260,    -1,   262,
    -1,   264,    -1,   266,    -1,   268,    -1,   270,    -1,    -1,
    -1,   274,    -1,   276,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   284,    -1,   286,    -1,   288,    -1,    -1,    -1,   292,
    -1,   294,     3,     4,     5,     6,     7,     8,    -1,    10,
    -1,    12,    13,    14,    -1,    -1,    -1,    18,    19,    20,
    21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
    31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
    41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
    51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
    61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
    71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
    81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
    91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
   101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
   111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
   121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
   131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
   141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
   151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
   161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
   171,   172,   173,   174,   175,   176,   177,    -1,   179,   180,
   181,   182,   183,   184,    -1,    -1,    -1,    -1,    -1,   190,
   191,   192,   193,   194,   195,   196,   197,   198,   199,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,
   211,   212,   213,   214,    -1,    -1,   217,    -1,   219,   220,
   221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
   231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
   241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
   251,   252,   253,   254,   255,   256,   257,    -1,    -1,   260,
    -1,   262,    -1,   264,    -1,   266,    -1,   268,    -1,   270,
    -1,    -1,    -1,   274,    -1,   276,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   284,    -1,   286,    -1,   288,    -1,    -1,
    -1,   292,    -1,   294,     3,     4,     5,     6,     7,     8,
     9,    -1,    -1,    12,    13,    14,    -1,    -1,    -1,    18,
    19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
    29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
    39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
    49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
    59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
    69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
    79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
    89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
    99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
   109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
   119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
   129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
   139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
   149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
   159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
   169,   170,   171,   172,   173,   174,   175,   176,   177,    -1,
   179,   180,   181,   182,   183,   184,    -1,    -1,    -1,    -1,
    -1,   190,   191,   192,   193,   194,   195,   196,   197,   198,
   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   210,   211,   212,   213,   214,    -1,    -1,   217,    -1,
   219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
   229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
   239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
   249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
    -1,   260,    -1,   262,    -1,   264,    -1,   266,    -1,   268,
    -1,   270,    -1,    -1,    -1,   274,    -1,   276,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   284,    -1,   286,    -1,   288,
    -1,    -1,    -1,   292,    -1,   294,     3,     4,     5,     6,
     7,     8,     9,    -1,    -1,    12,    13,    14,    -1,    -1,
    -1,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
    47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
    57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
    67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
    77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
    87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
    97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
   107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
   117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
   127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
   137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
   147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
   157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
   167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
   177,    -1,   179,   180,   181,   182,   183,   184,    -1,    -1,
    -1,    -1,    -1,   190,   191,   192,   193,   194,   195,   196,
   197,   198,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   210,   211,   212,   213,   214,    -1,    -1,
   217,    -1,   219,   220,   221,   222,   223,   224,   225,   226,
   227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
   237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
   247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
   257,    -1,    -1,   260,    -1,   262,    -1,   264,    -1,   266,
    -1,   268,    -1,   270,    -1,    -1,    -1,   274,    -1,   276,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,    -1,   286,
    -1,   288,    -1,    -1,    -1,   292,    -1,   294,     3,     4,
     5,     6,     7,     8,     9,    -1,    -1,    12,    13,    14,
    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,    24,
    25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
    35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
    45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
    55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
    65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
    75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
    85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
    95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
   105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
   115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
   125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
   135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
   145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
   155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
   165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
   175,   176,   177,    -1,   179,   180,   181,   182,   183,   184,
    -1,    -1,    -1,    -1,    -1,   190,   191,   192,   193,   194,
   195,   196,   197,   198,   199,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   210,   211,   212,   213,   214,
    -1,    -1,   217,    -1,   219,   220,   221,   222,   223,   224,
   225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
   235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
   245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
   255,   256,   257,    -1,    -1,   260,    -1,   262,    -1,   264,
    -1,   266,    -1,   268,    -1,   270,    -1,    -1,    -1,   274,
    -1,   276,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,
    -1,   286,    -1,   288,    -1,    -1,    -1,   292,    -1,   294,
     3,     4,     5,     6,     7,     8,     9,    -1,    -1,    12,
    13,    14,    -1,    -1,    -1,    18,    19,    20,    21,    22,
    23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
    33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
    43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
    53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
    63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
    73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
    83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
    93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
   103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
   113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
   123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
   133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
   143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
   153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
   163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
   173,   174,   175,   176,   177,    -1,   179,   180,   181,   182,
   183,   184,    -1,    -1,    -1,    -1,    -1,   190,   191,   192,
   193,   194,   195,   196,   197,   198,   199,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,   211,   212,
   213,   214,    -1,    -1,   217,    -1,   219,   220,   221,   222,
   223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
   233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
   243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
   253,   254,   255,   256,   257,    -1,    -1,   260,    -1,   262,
    -1,   264,    -1,   266,    -1,   268,    -1,   270,    -1,    -1,
    -1,   274,    -1,   276,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   284,    -1,   286,    -1,   288,    -1,    -1,    -1,   292,
    -1,   294,     3,     4,     5,     6,     7,     8,    -1,    -1,
    -1,    12,    13,    14,    -1,    -1,    -1,    18,    19,    20,
    21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
    31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
    41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
    51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
    61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
    71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
    81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
    91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
   101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
   111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
   121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
   131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
   141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
   151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
   161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
   171,   172,   173,   174,   175,   176,   177,    -1,   179,   180,
   181,   182,   183,   184,    -1,    -1,    -1,    -1,    -1,   190,
   191,   192,   193,   194,   195,   196,   197,   198,   199,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,
   211,   212,   213,   214,    -1,    -1,   217,    -1,   219,   220,
   221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
   231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
   241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
   251,   252,   253,   254,   255,   256,   257,    -1,    -1,   260,
   261,   262,    -1,   264,    -1,   266,    -1,   268,    -1,   270,
    -1,    -1,    -1,   274,    -1,   276,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   284,    -1,   286,    -1,   288,    -1,    -1,
    -1,   292,    -1,   294,     3,     4,     5,     6,     7,     8,
    -1,    -1,    11,    12,    13,    14,    -1,    -1,    -1,    18,
    19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
    29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
    39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
    49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
    59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
    69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
    79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
    89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
    99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
   109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
   119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
   129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
   139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
   149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
   159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
   169,   170,   171,   172,   173,   174,   175,   176,   177,    -1,
   179,   180,   181,   182,   183,   184,    -1,    -1,    -1,    -1,
    -1,   190,   191,   192,   193,   194,   195,   196,   197,   198,
   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   210,   211,   212,   213,   214,    -1,    -1,   217,    -1,
   219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
   229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
   239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
   249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
    -1,   260,    -1,   262,    -1,   264,    -1,   266,    -1,   268,
    -1,   270,    -1,    -1,    -1,   274,    -1,   276,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   284,    -1,   286,    -1,   288,
    -1,    -1,    -1,   292,    -1,   294,     3,     4,     5,     6,
     7,     8,    -1,    -1,    -1,    12,    13,    14,    -1,    -1,
    -1,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
    47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
    57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
    67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
    77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
    87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
    97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
   107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
   117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
   127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
   137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
   147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
   157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
   167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
   177,    -1,   179,   180,   181,   182,   183,   184,    -1,    -1,
    -1,    -1,    -1,   190,   191,   192,   193,   194,   195,   196,
   197,   198,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   210,   211,   212,   213,   214,    -1,    -1,
   217,    -1,   219,   220,   221,   222,   223,   224,   225,   226,
   227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
   237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
   247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
   257,    -1,    -1,   260,    -1,   262,    -1,   264,    -1,   266,
   267,   268,    -1,   270,    -1,    -1,    -1,   274,    -1,   276,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,    -1,   286,
    -1,   288,    -1,    -1,    -1,   292,    -1,   294,     3,     4,
     5,     6,     7,     8,    -1,    -1,    11,    12,    13,    14,
    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,    24,
    25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
    35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
    45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
    55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
    65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
    75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
    85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
    95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
   105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
   115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
   125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
   135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
   145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
   155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
   165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
   175,   176,   177,    -1,   179,   180,   181,   182,   183,   184,
    -1,    -1,    -1,    -1,    -1,   190,   191,   192,   193,   194,
   195,   196,   197,   198,   199,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   210,   211,   212,   213,   214,
    -1,    -1,   217,    -1,   219,   220,   221,   222,   223,   224,
   225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
   235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
   245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
   255,   256,   257,    -1,    -1,   260,    -1,   262,    -1,   264,
    -1,   266,    -1,   268,    -1,   270,    -1,    -1,    -1,   274,
    -1,   276,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,
    -1,   286,    -1,   288,    -1,    -1,    -1,   292,    -1,   294,
     3,     4,     5,     6,     7,     8,    -1,    -1,    11,    12,
    13,    14,    -1,    -1,    -1,    18,    19,    20,    21,    22,
    23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
    33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
    43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
    53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
    63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
    73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
    83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
    93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
   103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
   113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
   123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
   133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
   143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
   153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
   163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
   173,   174,   175,   176,   177,    -1,   179,   180,   181,   182,
   183,   184,    -1,    -1,    -1,    -1,    -1,   190,   191,   192,
   193,   194,   195,   196,   197,   198,   199,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,   211,   212,
   213,   214,    -1,    -1,   217,    -1,   219,   220,   221,   222,
   223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
   233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
   243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
   253,   254,   255,   256,   257,    -1,    -1,   260,    -1,   262,
    -1,   264,    -1,   266,    -1,   268,    -1,   270,    -1,    -1,
    -1,   274,    -1,   276,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   284,    -1,   286,    -1,   288,    -1,    -1,    -1,   292,
    -1,   294,     3,     4,     5,     6,     7,     8,     9,    -1,
    -1,    12,    13,    14,    -1,    -1,    -1,    18,    19,    20,
    21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
    31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
    41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
    51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
    61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
    71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
    81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
    91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
   101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
   111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
   121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
   131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
   141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
   151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
   161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
   171,   172,   173,   174,   175,   176,   177,    -1,   179,   180,
   181,   182,   183,   184,    -1,    -1,    -1,    -1,    -1,   190,
   191,   192,   193,   194,   195,   196,   197,   198,   199,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,
   211,   212,   213,   214,    -1,    -1,   217,    -1,   219,   220,
   221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
   231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
   241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
   251,   252,   253,   254,   255,   256,   257,    -1,    -1,   260,
    -1,   262,    -1,   264,    -1,   266,    -1,   268,    -1,   270,
    -1,    -1,    -1,   274,    -1,   276,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   284,    -1,   286,    -1,   288,    -1,    -1,
    -1,   292,    -1,   294,     3,     4,     5,     6,     7,     8,
     9,    -1,    -1,    12,    13,    14,    -1,    -1,    -1,    18,
    19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
    29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
    39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
    49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
    59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
    69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
    79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
    89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
    99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
   109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
   119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
   129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
   139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
   149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
   159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
   169,   170,   171,   172,   173,   174,   175,   176,   177,    -1,
   179,   180,   181,   182,   183,   184,    -1,    -1,    -1,    -1,
    -1,   190,   191,   192,   193,   194,   195,   196,   197,   198,
   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   210,   211,   212,   213,   214,    -1,    -1,   217,    -1,
   219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
   229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
   239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
   249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
    -1,   260,    -1,   262,    -1,   264,    -1,   266,    -1,   268,
    -1,   270,    -1,    -1,    -1,   274,    -1,   276,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   284,    -1,   286,    -1,   288,
    -1,    -1,    -1,   292,    -1,   294,     3,     4,     5,     6,
     7,     8,     9,    -1,    -1,    12,    13,    14,    -1,    -1,
    -1,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
    47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
    57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
    67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
    77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
    87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
    97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
   107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
   117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
   127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
   137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
   147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
   157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
   167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
   177,    -1,   179,   180,   181,   182,   183,   184,    -1,    -1,
    -1,    -1,    -1,   190,   191,   192,   193,   194,   195,   196,
   197,   198,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   210,   211,   212,   213,   214,    -1,    -1,
   217,    -1,   219,   220,   221,   222,   223,   224,   225,   226,
   227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
   237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
   247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
   257,    -1,    -1,   260,    -1,   262,    -1,   264,    -1,   266,
    -1,   268,    -1,   270,    -1,    -1,    -1,   274,    -1,   276,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,    -1,   286,
    -1,   288,    -1,    -1,    -1,   292,    -1,   294,     3,     4,
     5,     6,     7,     8,     9,    -1,    -1,    12,    13,    14,
    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,    24,
    25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
    35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
    45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
    55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
    65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
    75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
    85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
    95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
   105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
   115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
   125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
   135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
   145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
   155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
   165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
   175,   176,   177,    -1,   179,   180,   181,   182,   183,   184,
    -1,    -1,    -1,    -1,    -1,   190,   191,   192,   193,   194,
   195,   196,   197,   198,   199,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   210,   211,   212,   213,   214,
    -1,    -1,   217,    -1,   219,   220,   221,   222,   223,   224,
   225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
   235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
   245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
   255,   256,   257,    -1,    -1,   260,    -1,   262,    -1,   264,
    -1,   266,    -1,   268,    -1,   270,    -1,    -1,    -1,   274,
    -1,   276,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,
    -1,   286,    -1,   288,    -1,    -1,    -1,   292,    -1,   294,
     3,     4,     5,     6,     7,     8,     9,    -1,    -1,    12,
    13,    14,    -1,    -1,    -1,    18,    19,    20,    21,    22,
    23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
    33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
    43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
    53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
    63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
    73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
    83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
    93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
   103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
   113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
   123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
   133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
   143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
   153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
   163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
   173,   174,   175,   176,   177,    -1,   179,   180,   181,   182,
   183,   184,    -1,    -1,    -1,    -1,    -1,   190,   191,   192,
   193,   194,   195,   196,   197,   198,   199,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,   211,   212,
   213,   214,    -1,    -1,   217,    -1,   219,   220,   221,   222,
   223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
   233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
   243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
   253,   254,   255,   256,   257,    -1,    -1,   260,    -1,   262,
    -1,   264,    -1,   266,    -1,   268,    -1,   270,    -1,    -1,
    -1,   274,    -1,   276,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   284,    -1,   286,    -1,   288,    -1,    -1,    -1,   292,
    -1,   294,     3,     4,     5,     6,     7,     8,     9,    -1,
    -1,    12,    13,    14,    -1,    -1,    -1,    18,    19,    20,
    21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
    31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
    41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
    51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
    61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
    71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
    81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
    91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
   101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
   111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
   121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
   131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
   141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
   151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
   161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
   171,   172,   173,   174,   175,   176,   177,    -1,   179,   180,
   181,   182,   183,   184,    -1,    -1,    -1,    -1,    -1,   190,
   191,   192,   193,   194,   195,   196,   197,   198,   199,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,
   211,   212,   213,   214,    -1,    -1,   217,    -1,   219,   220,
   221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
   231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
   241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
   251,   252,   253,   254,   255,   256,   257,    -1,    -1,   260,
    -1,   262,    -1,   264,    -1,   266,    -1,   268,    -1,   270,
    -1,    -1,    -1,   274,    -1,   276,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   284,    -1,   286,    -1,   288,    -1,    -1,
    -1,   292,    -1,   294,     3,     4,     5,     6,     7,     8,
     9,    -1,    -1,    12,    13,    14,    -1,    -1,    -1,    18,
    19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
    29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
    39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
    49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
    59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
    69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
    79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
    89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
    99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
   109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
   119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
   129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
   139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
   149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
   159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
   169,   170,   171,   172,   173,   174,   175,   176,   177,    -1,
   179,   180,   181,   182,   183,   184,    -1,    -1,    -1,    -1,
    -1,   190,   191,   192,   193,   194,   195,   196,   197,   198,
   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   210,   211,   212,   213,   214,    -1,    -1,   217,    -1,
   219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
   229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
   239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
   249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
    -1,   260,    -1,   262,    -1,   264,    -1,   266,    -1,   268,
    -1,   270,    -1,    -1,    -1,   274,    -1,   276,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   284,    -1,   286,    -1,   288,
    -1,    -1,    -1,   292,    -1,   294,     3,     4,     5,     6,
     7,     8,    -1,    10,    -1,    12,    13,    14,    -1,    -1,
    -1,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
    47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
    57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
    67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
    77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
    87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
    97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
   107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
   117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
   127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
   137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
   147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
   157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
   167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
   177,    -1,   179,   180,   181,   182,   183,   184,    -1,    -1,
    -1,    -1,    -1,   190,   191,   192,   193,   194,   195,   196,
   197,   198,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   210,   211,   212,   213,   214,    -1,    -1,
   217,    -1,   219,   220,   221,   222,   223,   224,   225,   226,
   227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
   237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
   247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
   257,    -1,    -1,   260,    -1,   262,    -1,   264,    -1,   266,
    -1,   268,    -1,   270,    -1,    -1,    -1,   274,    -1,   276,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,    -1,   286,
    -1,   288,    -1,    -1,    -1,   292,    -1,   294,     3,     4,
     5,     6,     7,     8,     9,    -1,    -1,    12,    13,    14,
    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,    24,
    25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
    35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
    45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
    55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
    65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
    75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
    85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
    95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
   105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
   115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
   125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
   135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
   145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
   155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
   165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
   175,   176,   177,    -1,   179,   180,   181,   182,   183,   184,
    -1,    -1,    -1,    -1,    -1,   190,   191,   192,   193,   194,
   195,   196,   197,   198,   199,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   210,   211,   212,   213,   214,
    -1,    -1,   217,    -1,   219,   220,   221,   222,   223,   224,
   225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
   235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
   245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
   255,   256,   257,    -1,    -1,   260,    -1,   262,    -1,   264,
    -1,   266,    -1,   268,    -1,   270,    -1,    -1,    -1,   274,
    -1,   276,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,
    -1,   286,    -1,   288,    -1,    -1,    -1,   292,    -1,   294,
     3,     4,     5,     6,     7,     8,     9,    -1,    -1,    12,
    13,    14,    -1,    -1,    -1,    18,    19,    20,    21,    22,
    23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
    33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
    43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
    53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
    63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
    73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
    83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
    93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
   103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
   113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
   123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
   133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
   143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
   153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
   163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
   173,   174,   175,   176,   177,    -1,   179,   180,   181,   182,
   183,   184,    -1,    -1,    -1,    -1,    -1,   190,   191,   192,
   193,   194,   195,   196,   197,   198,   199,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,   211,   212,
   213,   214,    -1,    -1,   217,    -1,   219,   220,   221,   222,
   223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
   233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
   243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
   253,   254,   255,   256,   257,    -1,    -1,   260,    -1,   262,
    -1,   264,    -1,   266,    -1,   268,    -1,   270,    -1,    -1,
    -1,   274,    -1,   276,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   284,    -1,   286,    -1,   288,    -1,    -1,    -1,   292,
    -1,   294,     3,     4,     5,     6,     7,     8,     9,    -1,
    -1,    12,    13,    14,    -1,    -1,    -1,    18,    19,    20,
    21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
    31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
    41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
    51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
    61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
    71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
    81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
    91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
   101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
   111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
   121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
   131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
   141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
   151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
   161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
   171,   172,   173,   174,   175,   176,   177,    -1,   179,   180,
   181,   182,   183,   184,    -1,    -1,    -1,    -1,    -1,   190,
   191,   192,   193,   194,   195,   196,   197,   198,   199,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,
   211,   212,   213,   214,    -1,    -1,   217,    -1,   219,   220,
   221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
   231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
   241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
   251,   252,   253,   254,   255,   256,   257,    -1,    -1,   260,
    -1,   262,    -1,   264,    -1,   266,    -1,   268,    -1,   270,
    -1,    -1,    -1,   274,    -1,   276,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   284,    -1,   286,    -1,   288,    -1,    -1,
    -1,   292,    -1,   294,     3,     4,     5,     6,     7,     8,
     9,    -1,    -1,    12,    13,    14,    -1,    -1,    -1,    18,
    19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
    29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
    39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
    49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
    59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
    69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
    79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
    89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
    99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
   109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
   119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
   129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
   139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
   149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
   159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
   169,   170,   171,   172,   173,   174,   175,   176,   177,    -1,
   179,   180,   181,   182,   183,   184,    -1,    -1,    -1,    -1,
    -1,   190,   191,   192,   193,   194,   195,   196,   197,   198,
   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   210,   211,   212,   213,   214,    -1,    -1,   217,    -1,
   219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
   229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
   239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
   249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
    -1,   260,    -1,   262,    -1,   264,    -1,   266,    -1,   268,
    -1,   270,    -1,    -1,    -1,   274,    -1,   276,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   284,    -1,   286,    -1,   288,
    -1,    -1,    -1,   292,    -1,   294,     3,     4,     5,     6,
     7,     8,     9,    -1,    -1,    12,    13,    14,    -1,    -1,
    -1,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
    47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
    57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
    67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
    77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
    87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
    97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
   107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
   117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
   127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
   137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
   147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
   157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
   167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
   177,    -1,   179,   180,   181,   182,   183,   184,    -1,    -1,
    -1,    -1,    -1,   190,   191,   192,   193,   194,   195,   196,
   197,   198,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   210,   211,   212,   213,   214,    -1,    -1,
   217,    -1,   219,   220,   221,   222,   223,   224,   225,   226,
   227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
   237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
   247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
   257,    -1,    -1,   260,    -1,   262,    -1,   264,    -1,   266,
    -1,   268,    -1,   270,    -1,    -1,    -1,   274,    -1,   276,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,    -1,   286,
    -1,   288,    -1,    -1,    -1,   292,    -1,   294,     3,     4,
     5,     6,     7,     8,    -1,    10,    -1,    12,    13,    14,
    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,    24,
    25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
    35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
    45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
    55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
    65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
    75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
    85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
    95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
   105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
   115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
   125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
   135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
   145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
   155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
   165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
   175,   176,   177,    -1,   179,   180,   181,   182,   183,   184,
    -1,    -1,    -1,    -1,    -1,   190,   191,   192,   193,   194,
   195,   196,   197,   198,   199,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   210,   211,   212,   213,   214,
    -1,    -1,   217,    -1,   219,   220,   221,   222,   223,   224,
   225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
   235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
   245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
   255,   256,   257,    -1,    -1,   260,    -1,   262,    -1,   264,
    -1,   266,    -1,   268,    -1,   270,    -1,    -1,    -1,   274,
    -1,   276,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,
    -1,   286,    -1,   288,    -1,    -1,    -1,   292,    -1,   294,
     3,     4,     5,     6,     7,     8,     9,    -1,    -1,    12,
    13,    14,    -1,    -1,    -1,    18,    19,    20,    21,    22,
    23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
    33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
    43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
    53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
    63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
    73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
    83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
    93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
   103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
   113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
   123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
   133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
   143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
   153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
   163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
   173,   174,   175,   176,   177,    -1,   179,   180,   181,   182,
   183,   184,    -1,    -1,    -1,    -1,    -1,   190,   191,   192,
   193,   194,   195,   196,   197,   198,   199,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,   211,   212,
   213,   214,    -1,    -1,   217,    -1,   219,   220,   221,   222,
   223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
   233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
   243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
   253,   254,   255,   256,   257,    -1,    -1,   260,    -1,   262,
    -1,   264,    -1,   266,    -1,   268,    -1,   270,    -1,    -1,
    -1,   274,    -1,   276,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   284,    -1,   286,    -1,   288,    -1,    -1,    -1,   292,
    -1,   294,     3,     4,     5,     6,     7,     8,    -1,    -1,
    11,    12,    13,    14,    -1,    -1,    -1,    18,    19,    20,
    21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
    31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
    41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
    51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
    61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
    71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
    81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
    91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
   101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
   111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
   121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
   131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
   141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
   151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
   161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
   171,   172,   173,   174,   175,   176,   177,    -1,   179,   180,
   181,   182,   183,   184,    -1,    -1,    -1,    -1,    -1,   190,
   191,   192,   193,   194,   195,   196,   197,   198,   199,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,
   211,   212,   213,   214,    -1,    -1,   217,    -1,   219,   220,
   221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
   231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
   241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
   251,   252,   253,   254,   255,   256,   257,    -1,    -1,   260,
    -1,   262,    -1,   264,    -1,   266,    -1,   268,    -1,   270,
    -1,    -1,    -1,   274,    -1,   276,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   284,    -1,   286,    -1,   288,    -1,    -1,
    -1,   292,    -1,   294,     3,     4,     5,     6,     7,     8,
    -1,    -1,    -1,    12,    13,    14,    -1,    -1,    -1,    18,
    19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
    29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
    39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
    49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
    59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
    69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
    79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
    89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
    99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
   109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
   119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
   129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
   139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
   149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
   159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
   169,   170,   171,   172,   173,   174,   175,   176,   177,    -1,
   179,   180,   181,   182,   183,   184,    -1,    -1,    -1,    -1,
    -1,   190,   191,   192,   193,   194,   195,   196,   197,   198,
   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   210,   211,   212,   213,   214,    -1,    -1,   217,    -1,
   219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
   229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
   239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
   249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
    -1,   260,    -1,   262,    -1,   264,    -1,   266,    -1,   268,
    -1,   270,    -1,    -1,    -1,   274,   275,   276,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   284,    -1,   286,    -1,   288,
    -1,    -1,    -1,   292,    -1,   294,     3,     4,     5,     6,
     7,     8,    -1,    -1,    11,    12,    13,    14,    -1,    -1,
    -1,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
    47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
    57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
    67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
    77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
    87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
    97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
   107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
   117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
   127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
   137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
   147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
   157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
   167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
   177,    -1,   179,   180,   181,   182,   183,   184,    -1,    -1,
    -1,    -1,    -1,   190,   191,   192,   193,   194,   195,   196,
   197,   198,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   210,   211,   212,   213,   214,    -1,    -1,
   217,    -1,   219,   220,   221,   222,   223,   224,   225,   226,
   227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
   237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
   247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
   257,    -1,    -1,   260,    -1,   262,    -1,   264,    -1,   266,
    -1,   268,    -1,   270,    -1,    -1,    -1,   274,    -1,   276,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,    -1,   286,
    -1,   288,    -1,    -1,    -1,   292,    -1,   294,     3,     4,
     5,     6,     7,     8,    -1,    -1,    11,    12,    13,    14,
    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,    24,
    25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
    35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
    45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
    55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
    65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
    75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
    85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
    95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
   105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
   115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
   125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
   135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
   145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
   155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
   165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
   175,   176,   177,    -1,   179,   180,   181,   182,   183,   184,
    -1,    -1,    -1,    -1,    -1,   190,   191,   192,   193,   194,
   195,   196,   197,   198,   199,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   210,   211,   212,   213,   214,
    -1,    -1,   217,    -1,   219,   220,   221,   222,   223,   224,
   225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
   235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
   245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
   255,   256,   257,    -1,    -1,   260,    -1,   262,    -1,   264,
    -1,   266,    -1,   268,    -1,   270,    -1,    -1,    -1,   274,
    -1,   276,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,
    -1,   286,    -1,   288,    -1,    -1,    -1,   292,    -1,   294,
     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    12,
    13,    14,    -1,    -1,    -1,    18,    19,    20,    21,    22,
    23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
    33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
    43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
    53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
    63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
    73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
    83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
    93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
   103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
   113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
   123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
   133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
   143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
   153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
   163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
   173,   174,   175,   176,   177,    -1,   179,   180,   181,   182,
   183,   184,    -1,    -1,    -1,    -1,    -1,   190,   191,   192,
   193,   194,   195,   196,   197,   198,   199,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,   211,   212,
   213,   214,    -1,    -1,   217,    -1,   219,   220,   221,   222,
   223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
   233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
   243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
   253,   254,   255,   256,   257,    -1,    -1,   260,    -1,   262,
    -1,   264,    -1,   266,    -1,   268,    -1,   270,    -1,    -1,
    -1,   274,    -1,   276,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   284,   285,   286,    -1,   288,    -1,    -1,    -1,   292,
    -1,   294,     3,     4,     5,     6,     7,     8,    -1,    -1,
    -1,    12,    13,    14,    -1,    -1,    -1,    18,    19,    20,
    21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
    31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
    41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
    51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
    61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
    71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
    81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
    91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
   101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
   111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
   121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
   131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
   141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
   151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
   161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
   171,   172,   173,   174,   175,   176,   177,    -1,   179,   180,
   181,   182,   183,   184,    -1,    -1,    -1,    -1,    -1,   190,
   191,   192,   193,   194,   195,   196,   197,   198,   199,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,
   211,   212,   213,   214,    -1,    -1,   217,    -1,   219,   220,
   221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
   231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
   241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
   251,   252,   253,   254,   255,   256,   257,    -1,    -1,   260,
    -1,   262,    -1,   264,    -1,   266,    -1,   268,    -1,   270,
    -1,    -1,    -1,   274,    -1,   276,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   284,    -1,   286,   287,   288,    -1,    -1,
    -1,   292,    -1,   294,     3,     4,     5,     6,     7,     8,
    -1,    -1,    -1,    12,    13,    14,    -1,    -1,    -1,    18,
    19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
    29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
    39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
    49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
    59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
    69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
    79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
    89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
    99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
   109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
   119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
   129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
   139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
   149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
   159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
   169,   170,   171,   172,   173,   174,   175,   176,   177,    -1,
   179,   180,   181,   182,   183,   184,    -1,    -1,    -1,    -1,
    -1,   190,   191,   192,   193,   194,   195,   196,   197,   198,
   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   210,   211,   212,   213,   214,    -1,    -1,   217,    -1,
   219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
   229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
   239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
   249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
    -1,   260,    -1,   262,    -1,   264,    -1,   266,    -1,   268,
    -1,   270,    -1,    -1,    -1,   274,    -1,   276,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   284,    -1,   286,    -1,   288,
   289,    -1,    -1,   292,    -1,   294,     3,     4,     5,     6,
     7,     8,    -1,    -1,    -1,    12,    13,    14,    -1,    -1,
    -1,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
    47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
    57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
    67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
    77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
    87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
    97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
   107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
   117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
   127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
   137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
   147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
   157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
   167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
   177,    -1,   179,   180,   181,   182,   183,   184,    -1,    -1,
    -1,    -1,    -1,   190,   191,   192,   193,   194,   195,   196,
   197,   198,   199,    -1,    -1,    -1,    -1,    -1,   205,    -1,
    -1,    -1,    -1,   210,   211,   212,   213,   214,    -1,    -1,
   217,    -1,   219,   220,   221,   222,   223,   224,   225,   226,
   227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
   237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
   247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
   257,    -1,    -1,   260,    -1,   262,    -1,   264,    -1,   266,
    -1,   268,    -1,   270,    -1,    -1,    -1,   274,    -1,   276,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,    -1,   286,
    -1,   288,    -1,    -1,    -1,   292,    -1,   294,     3,     4,
     5,     6,     7,     8,     9,    -1,    -1,    12,    13,    14,
    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,    24,
    25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
    35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
    45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
    55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
    65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
    75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
    85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
    95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
   105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
   115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
   125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
   135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
   145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
   155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
   165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
   175,   176,   177,    -1,   179,   180,   181,   182,   183,   184,
    -1,    -1,    -1,    -1,    -1,   190,   191,   192,   193,   194,
   195,   196,   197,   198,   199,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   210,   211,   212,   213,   214,
    -1,    -1,   217,    -1,   219,   220,   221,   222,   223,   224,
   225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
   235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
   245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
   255,   256,   257,    -1,    -1,   260,    -1,   262,    -1,   264,
    -1,   266,    -1,   268,    -1,   270,    -1,    -1,    -1,   274,
    -1,   276,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,
    -1,   286,    -1,   288,    -1,    -1,    -1,   292,    -1,   294,
     3,     4,     5,     6,     7,     8,     9,    -1,    -1,    12,
    13,    14,    -1,    -1,    -1,    18,    19,    20,    21,    22,
    23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
    33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
    43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
    53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
    63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
    73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
    83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
    93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
   103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
   113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
   123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
   133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
   143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
   153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
   163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
   173,   174,   175,   176,   177,    -1,   179,   180,   181,   182,
   183,   184,    -1,    -1,    -1,    -1,    -1,   190,   191,   192,
   193,   194,   195,   196,   197,   198,   199,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,   211,   212,
   213,   214,    -1,    -1,   217,    -1,   219,   220,   221,   222,
   223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
   233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
   243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
   253,   254,   255,   256,   257,    -1,    -1,   260,    -1,   262,
    -1,   264,    -1,   266,    -1,   268,    -1,   270,    -1,    -1,
    -1,   274,    -1,   276,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   284,    -1,   286,    -1,   288,    -1,    -1,    -1,   292,
    -1,   294,     3,     4,     5,     6,     7,     8,     9,    -1,
    -1,    12,    13,    14,    -1,    -1,    -1,    18,    19,    20,
    21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
    31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
    41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
    51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
    61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
    71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
    81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
    91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
   101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
   111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
   121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
   131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
   141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
   151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
   161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
   171,   172,   173,   174,   175,   176,   177,    -1,   179,   180,
   181,   182,   183,   184,    -1,    -1,    -1,    -1,    -1,   190,
   191,   192,   193,   194,   195,   196,   197,   198,   199,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,
   211,   212,   213,   214,    -1,    -1,   217,    -1,   219,   220,
   221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
   231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
   241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
   251,   252,   253,   254,   255,   256,   257,    -1,    -1,   260,
    -1,   262,    -1,   264,    -1,   266,    -1,   268,    -1,   270,
    -1,    -1,    -1,   274,    -1,   276,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   284,    -1,   286,    -1,   288,    -1,    -1,
    -1,   292,    -1,   294,     3,     4,     5,     6,     7,     8,
     9,    -1,    -1,    12,    13,    14,    -1,    -1,    -1,    18,
    19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
    29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
    39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
    49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
    59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
    69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
    79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
    89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
    99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
   109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
   119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
   129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
   139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
   149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
   159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
   169,   170,   171,   172,   173,   174,   175,   176,   177,    -1,
   179,   180,   181,   182,   183,   184,    -1,    -1,    -1,    -1,
    -1,   190,   191,   192,   193,   194,   195,   196,   197,   198,
   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   210,   211,   212,   213,   214,    -1,    -1,   217,    -1,
   219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
   229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
   239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
   249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
    -1,   260,    -1,   262,    -1,   264,    -1,   266,    -1,   268,
    -1,   270,    -1,    -1,    -1,   274,    -1,   276,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   284,    -1,   286,    -1,   288,
    -1,    -1,    -1,   292,    -1,   294,     3,     4,     5,     6,
     7,     8,     9,    -1,    -1,    12,    13,    14,    -1,    -1,
    -1,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
    47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
    57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
    67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
    77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
    87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
    97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
   107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
   117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
   127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
   137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
   147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
   157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
   167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
   177,    -1,   179,   180,   181,   182,   183,   184,    -1,    -1,
    -1,    -1,    -1,   190,   191,   192,   193,   194,   195,   196,
   197,   198,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   210,   211,   212,   213,   214,    -1,    -1,
   217,    -1,   219,   220,   221,   222,   223,   224,   225,   226,
   227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
   237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
   247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
   257,    -1,    -1,   260,    -1,   262,    -1,   264,    -1,   266,
    -1,   268,    -1,   270,    -1,    -1,    -1,   274,    -1,   276,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,    -1,   286,
    -1,   288,    -1,    -1,    -1,   292,    -1,   294,     3,     4,
     5,     6,     7,     8,     9,    -1,    -1,    12,    13,    14,
    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,    24,
    25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
    35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
    45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
    55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
    65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
    75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
    85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
    95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
   105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
   115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
   125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
   135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
   145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
   155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
   165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
   175,   176,   177,    -1,   179,   180,   181,   182,   183,   184,
    -1,    -1,    -1,    -1,    -1,   190,   191,   192,   193,   194,
   195,   196,   197,   198,   199,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   210,   211,   212,   213,   214,
    -1,    -1,   217,    -1,   219,   220,   221,   222,   223,   224,
   225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
   235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
   245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
   255,   256,   257,    -1,    -1,   260,    -1,   262,    -1,   264,
    -1,   266,    -1,   268,    -1,   270,    -1,    -1,    -1,   274,
    -1,   276,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,
    -1,   286,    -1,   288,    -1,    -1,    -1,   292,    -1,   294,
     3,     4,     5,     6,     7,     8,    -1,    10,    -1,    12,
    13,    14,    -1,    -1,    -1,    18,    19,    20,    21,    22,
    23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
    33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
    43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
    53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
    63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
    73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
    83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
    93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
   103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
   113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
   123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
   133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
   143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
   153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
   163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
   173,   174,   175,   176,   177,    -1,   179,   180,   181,   182,
   183,   184,    -1,    -1,    -1,    -1,    -1,   190,   191,   192,
   193,   194,   195,   196,   197,   198,   199,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,   211,   212,
   213,   214,    -1,    -1,   217,    -1,   219,   220,   221,   222,
   223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
   233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
   243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
   253,   254,   255,   256,   257,    -1,    -1,   260,    -1,   262,
    -1,   264,    -1,   266,    -1,   268,    -1,   270,    -1,    -1,
    -1,   274,    -1,   276,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   284,    -1,   286,    -1,   288,    -1,    -1,    -1,   292,
    -1,   294,     3,     4,     5,     6,     7,     8,     9,    -1,
    -1,    12,    13,    14,    -1,    -1,    -1,    18,    19,    20,
    21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
    31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
    41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
    51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
    61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
    71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
    81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
    91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
   101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
   111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
   121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
   131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
   141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
   151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
   161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
   171,   172,   173,   174,   175,   176,   177,    -1,   179,   180,
   181,   182,   183,   184,    -1,    -1,    -1,    -1,    -1,   190,
   191,   192,   193,   194,   195,   196,   197,   198,   199,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,
   211,   212,   213,   214,    -1,    -1,   217,    -1,   219,   220,
   221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
   231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
   241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
   251,   252,   253,   254,   255,   256,   257,    -1,    -1,   260,
    -1,   262,    -1,   264,    -1,   266,    -1,   268,    -1,   270,
    -1,    -1,    -1,   274,    -1,   276,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   284,    -1,   286,    -1,   288,    -1,    -1,
    -1,   292,    -1,   294,     3,     4,     5,     6,     7,     8,
    -1,    10,    -1,    12,    13,    14,    -1,    -1,    -1,    18,
    19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
    29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
    39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
    49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
    59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
    69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
    79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
    89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
    99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
   109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
   119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
   129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
   139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
   149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
   159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
   169,   170,   171,   172,   173,   174,   175,   176,   177,    -1,
   179,   180,   181,   182,   183,   184,    -1,    -1,    -1,    -1,
    -1,   190,   191,   192,   193,   194,   195,   196,   197,   198,
   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   210,   211,   212,   213,   214,    -1,    -1,   217,    -1,
   219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
   229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
   239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
   249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
    -1,   260,    -1,   262,    -1,   264,    -1,   266,    -1,   268,
    -1,   270,    -1,    -1,    -1,   274,    -1,   276,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   284,    -1,   286,    -1,   288,
    -1,    -1,    -1,   292,    -1,   294,     3,     4,     5,     6,
     7,     8,    -1,    10,    -1,    12,    13,    14,    -1,    -1,
    -1,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
    47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
    57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
    67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
    77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
    87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
    97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
   107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
   117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
   127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
   137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
   147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
   157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
   167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
   177,    -1,   179,   180,   181,   182,   183,   184,    -1,    -1,
    -1,    -1,    -1,   190,   191,   192,   193,   194,   195,   196,
   197,   198,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   210,   211,   212,   213,   214,    -1,    -1,
   217,    -1,   219,   220,   221,   222,   223,   224,   225,   226,
   227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
   237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
   247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
   257,    -1,    -1,   260,    -1,   262,    -1,   264,    -1,   266,
    -1,   268,    -1,   270,    -1,    -1,    -1,   274,    -1,   276,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,    -1,   286,
    -1,   288,    -1,    -1,    -1,   292,    -1,   294,     3,     4,
     5,     6,     7,     8,     9,    -1,    -1,    12,    13,    14,
    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,    24,
    25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
    35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
    45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
    55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
    65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
    75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
    85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
    95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
   105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
   115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
   125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
   135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
   145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
   155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
   165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
   175,   176,   177,    -1,   179,   180,   181,   182,   183,   184,
    -1,    -1,    -1,    -1,    -1,   190,   191,   192,   193,   194,
   195,   196,   197,   198,   199,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   210,   211,   212,   213,   214,
    -1,    -1,   217,    -1,   219,   220,   221,   222,   223,   224,
   225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
   235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
   245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
   255,   256,   257,    -1,    -1,   260,    -1,   262,    -1,   264,
    -1,   266,    -1,   268,    -1,   270,    -1,    -1,    -1,   274,
    -1,   276,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,
    -1,   286,    -1,   288,    -1,    -1,    -1,   292,    -1,   294,
     3,     4,     5,     6,     7,     8,    -1,    10,    -1,    12,
    13,    14,    -1,    -1,    -1,    18,    19,    20,    21,    22,
    23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
    33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
    43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
    53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
    63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
    73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
    83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
    93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
   103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
   113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
   123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
   133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
   143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
   153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
   163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
   173,   174,   175,   176,   177,    -1,   179,   180,   181,   182,
   183,   184,    -1,    -1,    -1,    -1,    -1,   190,   191,   192,
   193,   194,   195,   196,   197,   198,   199,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,   211,   212,
   213,   214,    -1,    -1,   217,    -1,   219,   220,   221,   222,
   223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
   233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
   243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
   253,   254,   255,   256,   257,    -1,    -1,   260,    -1,   262,
    -1,   264,    -1,   266,    -1,   268,    -1,   270,    -1,    -1,
    -1,   274,    -1,   276,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   284,    -1,   286,    -1,   288,    -1,    -1,    -1,   292,
    -1,   294,     3,     4,     5,     6,     7,     8,    -1,    10,
    -1,    12,    13,    14,    -1,    -1,    -1,    18,    19,    20,
    21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
    31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
    41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
    51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
    61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
    71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
    81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
    91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
   101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
   111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
   121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
   131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
   141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
   151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
   161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
   171,   172,   173,   174,   175,   176,   177,    -1,   179,   180,
   181,   182,   183,   184,    -1,    -1,    -1,    -1,    -1,   190,
   191,   192,   193,   194,   195,   196,   197,   198,   199,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,
   211,   212,   213,   214,    -1,    -1,   217,    -1,   219,   220,
   221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
   231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
   241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
   251,   252,   253,   254,   255,   256,   257,    -1,    -1,   260,
    -1,   262,    -1,   264,    -1,   266,    -1,   268,    -1,   270,
    -1,    -1,    -1,   274,    -1,   276,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   284,    -1,   286,    -1,   288,    -1,    -1,
    -1,   292,    -1,   294,     3,     4,     5,     6,     7,     8,
    -1,    10,    -1,    12,    13,    14,    -1,    -1,    -1,    18,
    19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
    29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
    39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
    49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
    59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
    69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
    79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
    89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
    99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
   109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
   119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
   129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
   139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
   149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
   159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
   169,   170,   171,   172,   173,   174,   175,   176,   177,    -1,
   179,   180,   181,   182,   183,   184,    -1,    -1,    -1,    -1,
    -1,   190,   191,   192,   193,   194,   195,   196,   197,   198,
   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   210,   211,   212,   213,   214,    -1,    -1,   217,    -1,
   219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
   229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
   239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
   249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
    -1,   260,    -1,   262,    -1,   264,    -1,   266,    -1,   268,
    -1,   270,    -1,    -1,    -1,   274,    -1,   276,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   284,    -1,   286,    -1,   288,
    -1,    -1,    -1,   292,    -1,   294,     3,     4,     5,     6,
     7,     8,     9,    -1,    -1,    12,    13,    14,    -1,    -1,
    -1,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
    47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
    57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
    67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
    77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
    87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
    97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
   107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
   117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
   127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
   137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
   147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
   157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
   167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
   177,    -1,   179,   180,   181,   182,   183,   184,    -1,    -1,
    -1,    -1,    -1,   190,   191,   192,   193,   194,   195,   196,
   197,   198,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   210,   211,   212,   213,   214,    -1,    -1,
   217,    -1,   219,   220,   221,   222,   223,   224,   225,   226,
   227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
   237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
   247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
   257,    -1,    -1,   260,    -1,   262,    -1,   264,    -1,   266,
    -1,   268,    -1,   270,    -1,    -1,    -1,   274,    -1,   276,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,    -1,   286,
    -1,   288,    -1,    -1,    -1,   292,    -1,   294,     3,     4,
     5,     6,     7,     8,     9,    -1,    -1,    12,    13,    14,
    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,    24,
    25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
    35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
    45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
    55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
    65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
    75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
    85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
    95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
   105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
   115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
   125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
   135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
   145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
   155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
   165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
   175,   176,   177,    -1,   179,   180,   181,   182,   183,   184,
    -1,    -1,    -1,    -1,    -1,   190,   191,   192,   193,   194,
   195,   196,   197,   198,   199,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   210,   211,   212,   213,   214,
    -1,    -1,   217,    -1,   219,   220,   221,   222,   223,   224,
   225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
   235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
   245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
   255,   256,   257,    -1,    -1,   260,    -1,   262,    -1,   264,
    -1,   266,    -1,   268,    -1,   270,    -1,    -1,    -1,   274,
    -1,   276,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,
    -1,   286,    -1,   288,    -1,    -1,    -1,   292,    -1,   294,
     3,     4,     5,     6,     7,     8,     9,    -1,    -1,    12,
    13,    14,    -1,    -1,    -1,    18,    19,    20,    21,    22,
    23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
    33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
    43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
    53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
    63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
    73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
    83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
    93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
   103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
   113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
   123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
   133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
   143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
   153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
   163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
   173,   174,   175,   176,   177,    -1,   179,   180,   181,   182,
   183,   184,    -1,    -1,    -1,    -1,    -1,   190,   191,   192,
   193,   194,   195,   196,   197,   198,   199,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,   211,   212,
   213,   214,    -1,    -1,   217,    -1,   219,   220,   221,   222,
   223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
   233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
   243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
   253,   254,   255,   256,   257,    -1,    -1,   260,    -1,   262,
    -1,   264,    -1,   266,    -1,   268,    -1,   270,    -1,    -1,
    -1,   274,    -1,   276,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   284,    -1,   286,    -1,   288,    -1,    -1,    -1,   292,
    -1,   294,     3,     4,     5,     6,     7,     8,     9,    -1,
    -1,    12,    13,    14,    -1,    -1,    -1,    18,    19,    20,
    21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
    31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
    41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
    51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
    61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
    71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
    81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
    91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
   101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
   111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
   121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
   131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
   141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
   151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
   161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
   171,   172,   173,   174,   175,   176,   177,    -1,   179,   180,
   181,   182,   183,   184,    -1,    -1,    -1,    -1,    -1,   190,
   191,   192,   193,   194,   195,   196,   197,   198,   199,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,
   211,   212,   213,   214,    -1,    -1,   217,    -1,   219,   220,
   221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
   231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
   241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
   251,   252,   253,   254,   255,   256,   257,    -1,    -1,   260,
    -1,   262,    -1,   264,    -1,   266,    -1,   268,    -1,   270,
    -1,    -1,    -1,   274,    -1,   276,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   284,    -1,   286,    -1,   288,    -1,    -1,
    -1,   292,    -1,   294,     3,     4,     5,     6,     7,     8,
     9,    -1,    -1,    12,    13,    14,    -1,    -1,    -1,    18,
    19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
    29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
    39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
    49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
    59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
    69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
    79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
    89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
    99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
   109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
   119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
   129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
   139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
   149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
   159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
   169,   170,   171,   172,   173,   174,   175,   176,   177,    -1,
   179,   180,   181,   182,   183,   184,    -1,    -1,    -1,    -1,
    -1,   190,   191,   192,   193,   194,   195,   196,   197,   198,
   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   210,   211,   212,   213,   214,    -1,    -1,   217,    -1,
   219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
   229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
   239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
   249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
    -1,   260,    -1,   262,    -1,   264,    -1,   266,    -1,   268,
    -1,   270,    -1,    -1,    -1,   274,    -1,   276,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   284,    -1,   286,    -1,   288,
    -1,    -1,    -1,   292,    -1,   294,     3,     4,     5,     6,
     7,     8,    -1,    -1,    -1,    12,    13,    14,    -1,    -1,
    -1,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
    47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
    57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
    67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
    77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
    87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
    97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
   107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
   117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
   127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
   137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
   147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
   157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
   167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
   177,    -1,   179,   180,   181,   182,   183,   184,    -1,    -1,
    -1,    -1,    -1,   190,   191,   192,   193,   194,   195,   196,
   197,   198,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   210,   211,   212,   213,   214,    -1,    -1,
   217,    -1,   219,   220,   221,   222,   223,   224,   225,   226,
   227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
   237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
   247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
   257,    -1,    -1,   260,    -1,   262,    -1,   264,    -1,   266,
    -1,   268,    -1,   270,    -1,    -1,    -1,   274,    -1,   276,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,    -1,   286,
    -1,   288,    -1,    -1,    -1,   292,    -1,   294
};

#line 299 "/usr/local/lib/bison.cc"
 /* fattrs + tables */

/* parser code folow  */


/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: dollar marks section change
   the next  is replaced by the list of actions, each action
   as one case of the switch.  */ 

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (YY_AnalitzadorSintactic_CHAR = YYEMPTY)
#define YYEMPTY         -2
#define YYEOF           0
#define YYACCEPT        return(0)
#define YYABORT         return(1)
#define YYERROR         goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL          goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do                                                              \
  if (YY_AnalitzadorSintactic_CHAR == YYEMPTY && yylen == 1)                               \
    { YY_AnalitzadorSintactic_CHAR = (token), YY_AnalitzadorSintactic_LVAL = (value);                 \
      yychar1 = YYTRANSLATE (YY_AnalitzadorSintactic_CHAR);                                \
      YYPOPSTACK;                                               \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    { YY_AnalitzadorSintactic_ERROR ("syntax error: cannot back up"); YYERROR; }   \
while (0)

#define YYTERROR        1
#define YYERRCODE       256

#ifndef YY_AnalitzadorSintactic_PURE
/* UNPURE */
#define YYLEX           YY_AnalitzadorSintactic_LEX()
#ifndef YY_USE_CLASS
/* If nonreentrant, and not class , generate the variables here */
int     YY_AnalitzadorSintactic_CHAR;                      /*  the lookahead symbol        */
YY_AnalitzadorSintactic_STYPE      YY_AnalitzadorSintactic_LVAL;              /*  the semantic value of the */
				/*  lookahead symbol    */
int YY_AnalitzadorSintactic_NERRS;                 /*  number of parse errors so far */
#ifdef YY_AnalitzadorSintactic_LSP_NEEDED
YY_AnalitzadorSintactic_LTYPE YY_AnalitzadorSintactic_LLOC;   /*  location data for the lookahead     */
			/*  symbol                              */
#endif
#endif


#else
/* PURE */
#ifdef YY_AnalitzadorSintactic_LSP_NEEDED
#define YYLEX           YY_AnalitzadorSintactic_LEX(&YY_AnalitzadorSintactic_LVAL, &YY_AnalitzadorSintactic_LLOC)
#else
#define YYLEX           YY_AnalitzadorSintactic_LEX(&YY_AnalitzadorSintactic_LVAL)
#endif
#endif
#ifndef YY_USE_CLASS
#if YY_AnalitzadorSintactic_DEBUG != 0
int YY_AnalitzadorSintactic_DEBUG_FLAG;                    /*  nonzero means print parse trace     */
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif
#endif



/*  YYINITDEPTH indicates the initial size of the parser's stacks       */

#ifndef YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif


#if __GNUC__ > 1                /* GNU C and GNU C++ define this.  */
#define __yy_bcopy(FROM,TO,COUNT)       __builtin_memcpy(TO,FROM,COUNT)
#else                           /* not GNU C or C++ */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */

#ifdef __cplusplus
static void __yy_bcopy (char *from, char *to, int count)
#else
#ifdef __STDC__
static void __yy_bcopy (char *from, char *to, int count)
#else
static void __yy_bcopy (from, to, count)
     char *from;
     char *to;
     int count;
#endif
#endif
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}
#endif

int
#ifdef YY_USE_CLASS
 YY_AnalitzadorSintactic_CLASS::
#endif
     YY_AnalitzadorSintactic_PARSE(YY_AnalitzadorSintactic_PARSE_PARAM)
#ifndef __STDC__
#ifndef __cplusplus
#ifndef YY_USE_CLASS
/* parameter definition without protypes */
YY_AnalitzadorSintactic_PARSE_PARAM_DEF
#endif
#endif
#endif
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YY_AnalitzadorSintactic_STYPE *yyvsp;
  int yyerrstatus;      /*  number of tokens to shift before error messages enabled */
  int yychar1=0;          /*  lookahead token as an internal (translated) token number */

  short yyssa[YYINITDEPTH];     /*  the state stack                     */
  YY_AnalitzadorSintactic_STYPE yyvsa[YYINITDEPTH];        /*  the semantic value stack            */

  short *yyss = yyssa;          /*  refer to the stacks thru separate pointers */
  YY_AnalitzadorSintactic_STYPE *yyvs = yyvsa;     /*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YY_AnalitzadorSintactic_LSP_NEEDED
  YY_AnalitzadorSintactic_LTYPE yylsa[YYINITDEPTH];        /*  the location stack                  */
  YY_AnalitzadorSintactic_LTYPE *yyls = yylsa;
  YY_AnalitzadorSintactic_LTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YY_AnalitzadorSintactic_PURE
  int YY_AnalitzadorSintactic_CHAR;
  YY_AnalitzadorSintactic_STYPE YY_AnalitzadorSintactic_LVAL;
  int YY_AnalitzadorSintactic_NERRS;
#ifdef YY_AnalitzadorSintactic_LSP_NEEDED
  YY_AnalitzadorSintactic_LTYPE YY_AnalitzadorSintactic_LLOC;
#endif
#endif

  YY_AnalitzadorSintactic_STYPE yyval;             /*  the variable used to return         */
				/*  semantic values from the action     */
				/*  routines                            */

  int yylen;

#if YY_AnalitzadorSintactic_DEBUG != 0
  if (YY_AnalitzadorSintactic_DEBUG_FLAG)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  YY_AnalitzadorSintactic_NERRS = 0;
  YY_AnalitzadorSintactic_CHAR = YYEMPTY;          /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YY_AnalitzadorSintactic_LSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YY_AnalitzadorSintactic_STYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YY_AnalitzadorSintactic_LSP_NEEDED
      YY_AnalitzadorSintactic_LTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YY_AnalitzadorSintactic_LSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YY_AnalitzadorSintactic_LSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  YY_AnalitzadorSintactic_ERROR("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_bcopy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YY_AnalitzadorSintactic_STYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_bcopy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YY_AnalitzadorSintactic_LSP_NEEDED
      yyls = (YY_AnalitzadorSintactic_LTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_bcopy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YY_AnalitzadorSintactic_LSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YY_AnalitzadorSintactic_DEBUG != 0
      if (YY_AnalitzadorSintactic_DEBUG_FLAG)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YY_AnalitzadorSintactic_DEBUG != 0
  if (YY_AnalitzadorSintactic_DEBUG_FLAG)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (YY_AnalitzadorSintactic_CHAR == YYEMPTY)
    {
#if YY_AnalitzadorSintactic_DEBUG != 0
      if (YY_AnalitzadorSintactic_DEBUG_FLAG)
	fprintf(stderr, "Reading a token: ");
#endif
      YY_AnalitzadorSintactic_CHAR = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (YY_AnalitzadorSintactic_CHAR <= 0)           /* This means end of input. */
    {
      yychar1 = 0;
      YY_AnalitzadorSintactic_CHAR = YYEOF;                /* Don't call YYLEX any more */

#if YY_AnalitzadorSintactic_DEBUG != 0
      if (YY_AnalitzadorSintactic_DEBUG_FLAG)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(YY_AnalitzadorSintactic_CHAR);

#if YY_AnalitzadorSintactic_DEBUG != 0
      if (YY_AnalitzadorSintactic_DEBUG_FLAG)
	{
	  fprintf (stderr, "Next token is %d (%s", YY_AnalitzadorSintactic_CHAR, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, YY_AnalitzadorSintactic_CHAR, YY_AnalitzadorSintactic_LVAL);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YY_AnalitzadorSintactic_DEBUG != 0
  if (YY_AnalitzadorSintactic_DEBUG_FLAG)
    fprintf(stderr, "Shifting token %d (%s), ", YY_AnalitzadorSintactic_CHAR, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (YY_AnalitzadorSintactic_CHAR != YYEOF)
    YY_AnalitzadorSintactic_CHAR = YYEMPTY;

  *++yyvsp = YY_AnalitzadorSintactic_LVAL;
#ifdef YY_AnalitzadorSintactic_LSP_NEEDED
  *++yylsp = YY_AnalitzadorSintactic_LLOC;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YY_AnalitzadorSintactic_DEBUG != 0
  if (YY_AnalitzadorSintactic_DEBUG_FLAG)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


/* #line 712 "/usr/local/lib/bison.cc" */

  switch (yyn) {

case 1:
#line 251 "sintaxis.y"
{inserirSeccioEnCurs();;
    break;}
case 2:
#line 252 "sintaxis.y"
{inserirSeccioEnCurs();;
    break;}
case 3:
#line 256 "sintaxis.y"
{;
    break;}
case 4:
#line 257 "sintaxis.y"
{;
    break;}
case 5:
#line 261 "sintaxis.y"
{
                    bool error = false;
                    classe = obtenir_classe(yyvsp[-1].valor, &error);
                    if (error) {warning(1);}
                 ;
    break;}
case 6:
#line 267 "sintaxis.y"
{
                    bool error = false;
                    classe = obtenir_classe(yyvsp[-1].valor, &error);
                    if (error) {warning(1);} 
                 ;
    break;}
case 7:
#line 274 "sintaxis.y"
{;
    break;}
case 8:
#line 275 "sintaxis.y"
{;
    break;}
case 9:
#line 276 "sintaxis.y"
{;
    break;}
case 10:
#line 277 "sintaxis.y"
{;
    break;}
case 11:
#line 280 "sintaxis.y"
{;
    break;}
case 12:
#line 281 "sintaxis.y"
{;
    break;}
case 13:
#line 282 "sintaxis.y"
{warning(2);;
    break;}
case 14:
#line 285 "sintaxis.y"
{notes_al_peu->buidar();;
    break;}
case 15:
#line 285 "sintaxis.y"
{;
    break;}
case 16:
#line 287 "sintaxis.y"
{  char* titol = concatenar(titol_document, autors_document, data_document,"","");
                  addCos(titol);
                  free(titol); 
               ;
    break;}
case 17:
#line 290 "sintaxis.y"
{;
    break;}
case 18:
#line 292 "sintaxis.y"
{  char* titol = concatenar(titol_document, autors_document, data_document,"","");
                  addCos(titol);
                  free(titol); 
               ;
    break;}
case 19:
#line 295 "sintaxis.y"
{;
    break;}
case 20:
#line 297 "sintaxis.y"
{;
    break;}
case 21:
#line 298 "sintaxis.y"
{addCos(yyvsp[0].valor); free(yyvsp[0].valor);;
    break;}
case 22:
#line 300 "sintaxis.y"
{
         char* aux;
         char* aux2;
         if(conf.nopart==false)
          {   novaSeccio(part, yyvsp[0].valor);
              addTitol(yyvsp[0].valor);
          }else {document->CompActual.novaPart();}
        
         compt->novaPart();      
         nom_en_curs = compt->obtenirNom();
         aux2 = compt->obtenirValorComptador();
         pila->desapilarEntorn();
         pila->apilarEntorn(nom_en_curs, aux2);
         aux = concatenar("<H1><A NAME=", nom_en_curs, ">", aux2, "<P>");
         addCos(aux); addCos(yyvsp[0].valor); addCos("</A></H1>\n");
         free(aux); free(aux2); free(yyvsp[0].valor);
      ;
    break;}
case 23:
#line 318 "sintaxis.y"
{
         char* aux;
         char* aux2;
         if(conf.nocapitol==false) 
          {   novaSeccio(capitol, yyvsp[0].valor);
              addTitol(yyvsp[0].valor);
          }else {document->CompActual.nouCapitol();}

         compt->nouCapitol();
         nom_en_curs = compt->obtenirNom();
         aux2 = compt->obtenirValorComptador();
         pila->desapilarEntorn();
         pila->apilarEntorn(nom_en_curs, aux2);
         aux = concatenar("<H2><A NAME=", nom_en_curs, ">", aux2, "<P>");
         addCos(aux); addCos(yyvsp[0].valor); addCos("</A></H2>\n");
         free(aux); free(aux2); free(yyvsp[0].valor);
      ;
    break;}
case 24:
#line 336 "sintaxis.y"
{
         char* aux;
         char* aux2;
         if(conf.nosec==false) 
          {   novaSeccio(seccio, yyvsp[0].valor);
              addTitol(yyvsp[0].valor);
          }else {document->CompActual.novaSeccio();}

         compt->novaSeccio();
         nom_en_curs = compt->obtenirNom();
         aux2 = compt->obtenirValorComptador();
         pila->desapilarEntorn();
         pila->apilarEntorn(nom_en_curs, aux2);
         aux = concatenar("<H2><A NAME=", nom_en_curs, ">", aux2, "   ");
         addCos(aux); addCos(yyvsp[0].valor); addCos("</A></H2>\n");
         free(aux); free(aux2); free(yyvsp[0].valor);
      ;
    break;}
case 25:
#line 354 "sintaxis.y"
{
         char* aux;
         char* aux2;
         if(conf.nosubsec==false) 
          {   novaSeccio(subseccio, yyvsp[0].valor);
              addTitol(yyvsp[0].valor);
          }else {document->CompActual.novaSubseccio();}

         compt->novaSubseccio();
         nom_en_curs = compt->obtenirNom();
         aux2 = compt->obtenirValorComptador();
         pila->desapilarEntorn();
         pila->apilarEntorn(nom_en_curs, aux2);
         aux = concatenar("<H3><A NAME=", nom_en_curs, ">", aux2, "   ");
         addCos(aux); addCos(yyvsp[0].valor); addCos("</A></H3>\n");
         free(aux); free(aux2); free(yyvsp[0].valor);
      ;
    break;}
case 26:
#line 372 "sintaxis.y"
{
         char* aux;
         char* aux2;
         if(conf.nosubsubsec==false) 
          {   novaSeccio(subsubseccio, yyvsp[0].valor);
              addTitol(yyvsp[0].valor);
          }else {document->CompActual.novaSubsubseccio();}

         compt->novaSubsubseccio();
         nom_en_curs = compt->obtenirNom();
         aux2 = compt->obtenirValorComptador();
         pila->desapilarEntorn();
         pila->apilarEntorn(nom_en_curs, aux2);
         aux = concatenar("<H4><A NAME=", nom_en_curs, ">", aux2, "   ");
         addCos(aux); addCos(yyvsp[0].valor); addCos("</A></H4>\n");
         free(aux); free(aux2); free(yyvsp[0].valor);
      ;
    break;}
case 27:
#line 391 "sintaxis.y"
{yyval.valor=concatenar(yyvsp[-1].valor,yyvsp[0].valor,"","",""); free(yyvsp[-1].valor); free(yyvsp[0].valor);;
    break;}
case 28:
#line 392 "sintaxis.y"
{
                               if(tabbing_flag){espais = espais + strlen(yyvsp[0].valor);}
                               if((!entorn_html)&&(!hyperref)) {yyval.valor=resaltarLinksUrl(yyvsp[0].valor); free(yyvsp[0].valor);} else {yyval.valor=yyvsp[0].valor;}
                              ;
    break;}
case 29:
#line 396 "sintaxis.y"
{yyval.valor=yyvsp[0].valor;;
    break;}
case 30:
#line 397 "sintaxis.y"
{yyval.valor=yyvsp[0].valor;;
    break;}
case 31:
#line 398 "sintaxis.y"
{yyval.valor=yyvsp[0].valor;;
    break;}
case 32:
#line 399 "sintaxis.y"
{yyval.valor=yyvsp[0].valor;;
    break;}
case 33:
#line 400 "sintaxis.y"
{yyval.valor=yyvsp[0].valor;;
    break;}
case 34:
#line 401 "sintaxis.y"
{yyval.valor=yyvsp[0].valor;;
    break;}
case 35:
#line 402 "sintaxis.y"
{yyval.valor=yyvsp[0].valor;;
    break;}
case 36:
#line 403 "sintaxis.y"
{yyval.valor=yyvsp[0].valor;;
    break;}
case 37:
#line 404 "sintaxis.y"
{yyval.valor=yyvsp[0].valor;;
    break;}
case 38:
#line 405 "sintaxis.y"
{yyval.valor=yyvsp[0].valor;;
    break;}
case 39:
#line 406 "sintaxis.y"
{yyval.valor=yyvsp[0].valor;;
    break;}
case 40:
#line 407 "sintaxis.y"
{
                               if(tabbing_flag){espais=0;tab_compt=0;yyval.valor=igual("<BR>\n");}
                               else {yyval.valor=igual("\n<P>");}
                              ;
    break;}
case 41:
#line 411 "sintaxis.y"
{yyval.valor=igual("<BR>\n");;
    break;}
case 42:
#line 412 "sintaxis.y"
{yyval.valor=yyvsp[0].valor;;
    break;}
case 43:
#line 413 "sintaxis.y"
{yyval.valor=yyvsp[0].valor;;
    break;}
case 44:
#line 414 "sintaxis.y"
{yyval.valor=yyvsp[0].valor;;
    break;}
case 45:
#line 415 "sintaxis.y"
{;
    break;}
case 46:
#line 416 "sintaxis.y"
{yyval.valor=igual("\n<P><H2>Taula de continguts</H2>\n<P>%C</P>\n");;
    break;}
case 47:
#line 417 "sintaxis.y"
{yyval.valor=igual("\n<P><H2>Llista de figures</H2>\n<P>%F</P>\n");;
    break;}
case 48:
#line 418 "sintaxis.y"
{yyval.valor=igual("\n<P><H2>Llista de taules</H2>\n<P>%T</P>\n");;
    break;}
case 49:
#line 419 "sintaxis.y"
{yyval.valor=yyvsp[0].valor;;
    break;}
case 50:
#line 420 "sintaxis.y"
{yyval.valor=yyvsp[0].valor;;
    break;}
case 51:
#line 421 "sintaxis.y"
{yyval.valor=yyvsp[0].valor;;
    break;}
case 52:
#line 422 "sintaxis.y"
{yyval.valor=yyvsp[0].valor;;
    break;}
case 53:
#line 423 "sintaxis.y"
{yyval.valor=yyvsp[0].valor;;
    break;}
case 54:
#line 424 "sintaxis.y"
{yyval.valor=yyvsp[0].valor;;
    break;}
case 55:
#line 425 "sintaxis.y"
{yyval.valor=igual("<I>");;
    break;}
case 56:
#line 426 "sintaxis.y"
{yyval.valor=igual("<B>");;
    break;}
case 57:
#line 427 "sintaxis.y"
{yyval.valor=igual("<TT>");;
    break;}
case 58:
#line 428 "sintaxis.y"
{yyval.valor=igual("<EM>");;
    break;}
case 59:
#line 429 "sintaxis.y"
{yyval.valor=yyvsp[0].valor;;
    break;}
case 60:
#line 430 "sintaxis.y"
{yyval.valor=yyvsp[0].valor;;
    break;}
case 61:
#line 431 "sintaxis.y"
{yyval.valor=yyvsp[0].valor;;
    break;}
case 62:
#line 432 "sintaxis.y"
{yyval.valor=yyvsp[0].valor;;
    break;}
case 63:
#line 433 "sintaxis.y"
{yyval.valor=yyvsp[0].valor;;
    break;}
case 64:
#line 434 "sintaxis.y"
{yyval.valor=yyvsp[0].valor;;
    break;}
case 65:
#line 435 "sintaxis.y"
{yyval.valor=yyvsp[0].valor;;
    break;}
case 66:
#line 436 "sintaxis.y"
{yyval.valor=yyvsp[0].valor;;
    break;}
case 67:
#line 437 "sintaxis.y"
{yyval.valor=yyvsp[0].valor;;
    break;}
case 68:
#line 438 "sintaxis.y"
{yyval.valor=yyvsp[0].valor;;
    break;}
case 69:
#line 441 "sintaxis.y"
{yyval.valor=concatenar(yyvsp[-1].valor,yyvsp[0].valor,"","",""); free(yyvsp[-1].valor); free(yyvsp[0].valor);;
    break;}
case 70:
#line 443 "sintaxis.y"
{
                     char* etiqueta;
                     char* aux=concatenar("&#91;",yyvsp[-5].valor,"&#93;","","");
                     char* fitxer = assignarFitxer();
 
                     etiqueta=concatenar("B",yyvsp[-2].valor,"","","");
                     ref_creuades->inserirEtiqueta(etiqueta, etiqueta, fitxer, aux);
                     yyval.valor=concatenar("<TABLE border=0 width=100%>\n<TR>\n<TD width=10% valign=top><A NAME=",etiqueta,">",aux,"</A></TD>\n<TD width=90%>");
                     free(aux); aux=yyval.valor;
                     yyval.valor=concatenar(yyval.valor,yyvsp[0].valor,"</TD>\n</TR>\n</TABLE>\n","","");
                     free(etiqueta); free(fitxer); free(yyvsp[-5].valor); free(yyvsp[-2].valor); free(aux); free(yyvsp[0].valor);
                   ;
    break;}
case 71:
#line 456 "sintaxis.y"
{
                     char* etiqueta;
                     char* aux=concatenar("[",yyvsp[-5].valor,"]","","");
                     char* fitxer = assignarFitxer();
 
                     etiqueta=concatenar("B",yyvsp[-2].valor,"","","");
                     ref_creuades->inserirEtiqueta(etiqueta, etiqueta, fitxer, aux);
                     yyval.valor=concatenar("<TABLE border=0 width=100%>\n<TR>\n<TD width=10% valign=top><A NAME=",etiqueta,">",aux,"</A></TD>\n<TD width=90%>");
                     free(aux); aux=yyval.valor;
                     yyval.valor=concatenar(yyval.valor,yyvsp[0].valor,"</TD>\n</TR>\n</TABLE>\n","","");
                     free(etiqueta); free(fitxer); free(yyvsp[-5].valor); free(yyvsp[-2].valor); free(aux); free(yyvsp[0].valor);
                   ;
    break;}
case 72:
#line 469 "sintaxis.y"
{
                     char* etiqueta;
                     char* numero=intToAsc(compt_bibliografia);
                     char* aux=concatenar("[",numero,"]","","");
                     char* fitxer = assignarFitxer();

                     compt_bibliografia++;
                     etiqueta=concatenar("B",yyvsp[-2].valor,"","","");
                     ref_creuades->inserirEtiqueta(etiqueta, etiqueta, fitxer, aux);
                     yyval.valor=concatenar("<TABLE border=0 width=100%>\n<TR>\n<TD width=10% valign=top><A NAME=",etiqueta,">",aux,"</A></TD>\n<TD width=90%>");
                     free(aux); aux=yyval.valor;
                     yyval.valor=concatenar(yyval.valor,yyvsp[0].valor,"</TD>\n</TR>\n</TABLE>\n","","");
                     free(etiqueta); free(fitxer); free(yyvsp[-2].valor); free(aux); free(numero);
                   ;
    break;}
case 73:
#line 484 "sintaxis.y"
{
                     char* etiqueta;
                     char* numero=intToAsc(compt_bibliografia);
                     char* aux=concatenar("[",numero,"]","","");
                     char* fitxer = assignarFitxer();

                     compt_bibliografia++;
                     etiqueta=concatenar("B",yyvsp[-2].valor,"","","");
                     ref_creuades->inserirEtiqueta(etiqueta, etiqueta, fitxer, aux);
                     yyval.valor=concatenar("<TABLE border=0 width=100%>\n<TR>\n<TD width=10% valign=top><A NAME=",etiqueta,">",aux,"</A></TD>\n<TD width=90%>");

                     free(aux); aux=yyval.valor;
                     yyval.valor=concatenar(yyval.valor,yyvsp[0].valor,"</TD>\n</TR>\n</TABLE>\n","","");
                     free(etiqueta); free(fitxer); free(yyvsp[-2].valor); free(aux); free(numero);

                   ;
    break;}
case 74:
#line 503 "sintaxis.y"
{
                yyval.valor=concatenar("\n<P><H2>Referències bibliogràfiques</H2>\n", yyvsp[-1].valor,"","","");
                compt_bibliografia=1;
                free(yyvsp[-1].valor);
              ;
    break;}
case 75:
#line 509 "sintaxis.y"
{
                yyval.valor=concatenar("\n<P><H2>Referències bibliogràfiques</H2>\n", yyvsp[-1].valor,"","","");
                compt_bibliografia=1;
                free(yyvsp[-1].valor); free(yyvsp[-2].valor);
              ;
    break;}
case 76:
#line 516 "sintaxis.y"
{yyval.valor=concatenar(yyvsp[-1].valor,yyvsp[0].valor,"","","");free(yyvsp[-1].valor);free(yyvsp[0].valor);;
    break;}
case 77:
#line 517 "sintaxis.y"
{tab_espais[tab]=espais; tab++; espais=0; yyval.valor=igual("");;
    break;}
case 78:
#line 519 "sintaxis.y"
{
                 char* aux=igual("");
                 char* aux2;
                 for(int e=0; e<tab_espais[tab_compt]; e++)
                  {
                     aux2=aux;
                     aux=concatenar(aux, "&nbsp;&nbsp;","","",""); free(aux2);
                  }
                 yyval.valor=aux;
                 if(tab_compt<tab){tab_compt++;}
              ;
    break;}
case 79:
#line 530 "sintaxis.y"
{yyval.valor=yyvsp[0].valor;;
    break;}
case 80:
#line 533 "sintaxis.y"
{tabbing_flag=true;;
    break;}
case 81:
#line 534 "sintaxis.y"
{
             tabbing_flag=false;
             espais=0;
             tab_compt=0;
             tab=0;
             tab_espais[0]=0;
             yyval.valor=concatenar("\n<P><TABLE border=0>\n<TR>\n<TD align=left>",yyvsp[-1].valor,"</TD>\n</TR>\n</TABLE></P>\n","",""); free(yyvsp[-1].valor);
          ;
    break;}
case 82:
#line 543 "sintaxis.y"
{hyperref=true;;
    break;}
case 83:
#line 544 "sintaxis.y"
{
                     yyval.valor=concatenar("<A HREF=",yyvsp[-4].valor,">",yyvsp[-1].valor,"</A>"); free(yyvsp[-4].valor); free(yyvsp[-1].valor);
                     hyperref=false;
                  ;
    break;}
case 84:
#line 550 "sintaxis.y"
{
               yyval.valor=concatenar("<A HREF={H",yyvsp[-4].valor,"}>",yyvsp[-1].valor,"</A>"); free(yyvsp[-4].valor); free(yyvsp[-1].valor);
            ;
    break;}
case 85:
#line 555 "sintaxis.y"
{
             char* aux = igual("");
             char* fitxer = assignarFitxer();
             char* etiqueta = new char[strlen(yyvsp[-4].valor) + 2];
             etiqueta = concatenar("H",yyvsp[-4].valor,"","","");

             ref_creuades->inserirEtiqueta(etiqueta, etiqueta, fitxer, aux);
             yyval.valor=concatenar("<A NAME=",etiqueta,">",yyvsp[-1].valor,"</A>");
             free(aux); free(fitxer); free(yyvsp[-4].valor);
          ;
    break;}
case 86:
#line 566 "sintaxis.y"
{entorn_html=true;;
    break;}
case 87:
#line 566 "sintaxis.y"
{yyval.valor=yyvsp[-1].valor; entorn_html=false;;
    break;}
case 88:
#line 568 "sintaxis.y"
{yyval.valor=concatenar(yyvsp[-1].valor,yyvsp[0].valor,"","",""); free(yyvsp[-1].valor); free(yyvsp[0].valor);;
    break;}
case 89:
#line 569 "sintaxis.y"
{yyval.valor=concatenar("<LI>",yyvsp[-2].valor,"&nbsp;&nbsp;&nbsp;",yyvsp[0].valor,"</LI>\n"); free(yyvsp[-2].valor); free(yyvsp[0].valor);;
    break;}
case 90:
#line 570 "sintaxis.y"
{yyval.valor=concatenar("<LI>",yyvsp[-2].valor,"&nbsp;&nbsp;&nbsp;",yyvsp[0].valor,"</LI>\n"); free(yyvsp[-2].valor); free(yyvsp[0].valor);;
    break;}
case 91:
#line 571 "sintaxis.y"
{yyval.valor=concatenar("<LI>",yyvsp[0].valor,"</LI>\n","",""); free(yyvsp[0].valor);;
    break;}
case 92:
#line 572 "sintaxis.y"
{yyval.valor=igual("");;
    break;}
case 93:
#line 573 "sintaxis.y"
{yyval.valor=concatenar("<LI>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;",yyvsp[-2].valor,"&nbsp;&nbsp;&nbsp;",yyvsp[0].valor,"</LI>\n"); free(yyvsp[-2].valor); free(yyvsp[0].valor);;
    break;}
case 94:
#line 574 "sintaxis.y"
{yyval.valor=concatenar("<LI>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;",yyvsp[-2].valor,"&nbsp;&nbsp;&nbsp;",yyvsp[0].valor,"</LI>\n"); free(yyvsp[-2].valor); free(yyvsp[0].valor);;
    break;}
case 95:
#line 575 "sintaxis.y"
{yyval.valor=concatenar("<LI>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;",yyvsp[0].valor,"</LI>\n","",""); free(yyvsp[0].valor);;
    break;}
case 96:
#line 576 "sintaxis.y"
{yyval.valor=igual("");;
    break;}
case 97:
#line 577 "sintaxis.y"
{yyval.valor=yyvsp[0].valor;;
    break;}
case 98:
#line 581 "sintaxis.y"
{
             yyval.valor=concatenar("\n<UL>\n",yyvsp[-1].valor,"\n</UL>\n","",""); free(yyvsp[-1].valor);
          ;
    break;}
case 99:
#line 584 "sintaxis.y"
{yyval.valor=igual("");;
    break;}
case 100:
#line 586 "sintaxis.y"
{nivell_enumerat++;;
    break;}
case 101:
#line 587 "sintaxis.y"
{
             nivell_enumerat--;
             switch(nivell_enumerat)
              {
                  case 0: yyval.valor=concatenar("\n<OL TYPE=1>\n",yyvsp[-1].valor,"</OL>\n","",""); break;
                  case 1: yyval.valor=concatenar("\n<OL TYPE=a>\n",yyvsp[-1].valor,"</OL>\n","",""); break;
                  case 2: yyval.valor=concatenar("\n<OL TYPE=i>\n",yyvsp[-1].valor,"</OL>\n","",""); break;
                  default: yyval.valor=concatenar("\n<OL TYPE=A>\n",yyvsp[-1].valor,"</OL>\n","","");
              }
          ;
    break;}
case 102:
#line 597 "sintaxis.y"
{yyval.valor=igual("");;
    break;}
case 103:
#line 601 "sintaxis.y"
{
             char* aux;
             char* fitxer = assignarFitxer();

             compt_equacions++;
             free(equacio_en_curs);
             equacio_en_curs = obtenirNomEquacio();

             aux = intToAsc(compt_equacions);
             pila->apilarEntorn(equacio_en_curs, aux);
             free(aux); free(fitxer);
          ;
    break;}
case 104:
#line 614 "sintaxis.y"
{
             pila->desapilarEntorn();

             char* num = intToAsc(compt_equacions);
             yyval.valor=concatenar("\n<DIV ALIGN=right>\n<TABLE BORDER=0 WIDTH=80% CELLSPACING=5>\n<TR>\n<TD WIDTH=70% ALIGN=center><EM>",yyvsp[-1].valor, "</EM></TD>\n<TD WIDTH=30%>(", num, ")</TD>\n</TR>\n</TABLE>\n</DIV><P>\n");
             free(num); free(yyvsp[-1].valor);
          ;
    break;}
case 105:
#line 622 "sintaxis.y"
{yyval.valor=concatenar(yyvsp[-2].valor,"<I>",yyvsp[0].valor,"",""); free(yyvsp[-2].valor); free(yyvsp[-1].valor); free(yyvsp[0].valor);;
    break;}
case 106:
#line 623 "sintaxis.y"
{yyval.valor=concatenar(yyvsp[-1].valor,"<I>","","",""); free(yyvsp[-1].valor); free(yyvsp[0].valor);;
    break;}
case 107:
#line 624 "sintaxis.y"
{yyval.valor=concatenar("<I>",yyvsp[0].valor,"","",""); free(yyvsp[-1].valor); free(yyvsp[0].valor);;
    break;}
case 108:
#line 625 "sintaxis.y"
{yyval.valor=igual("<I>");;;
    break;}
case 109:
#line 627 "sintaxis.y"
{yyval.valor=concatenar(yyvsp[-2].valor,"<B>",yyvsp[0].valor,"",""); free(yyvsp[-2].valor); free(yyvsp[-1].valor); free(yyvsp[0].valor);;
    break;}
case 110:
#line 628 "sintaxis.y"
{yyval.valor=concatenar(yyvsp[-1].valor,"<B>","","",""); free(yyvsp[-1].valor); free(yyvsp[0].valor);;
    break;}
case 111:
#line 629 "sintaxis.y"
{yyval.valor=concatenar("<B>",yyvsp[0].valor,"","",""); free(yyvsp[-1].valor); free(yyvsp[0].valor);;
    break;}
case 112:
#line 630 "sintaxis.y"
{yyval.valor=igual("<B>");;
    break;}
case 113:
#line 632 "sintaxis.y"
{yyval.valor=concatenar(yyvsp[-2].valor,"<TT>",yyvsp[0].valor,"",""); free(yyvsp[-2].valor); free(yyvsp[-1].valor); free(yyvsp[0].valor);;
    break;}
case 114:
#line 633 "sintaxis.y"
{yyval.valor=concatenar(yyvsp[-1].valor,"<TT>","","",""); free(yyvsp[-1].valor); free(yyvsp[0].valor);;
    break;}
case 115:
#line 634 "sintaxis.y"
{yyval.valor=concatenar("<TT>",yyvsp[0].valor,"","",""); free(yyvsp[-1].valor); free(yyvsp[0].valor);;
    break;}
case 116:
#line 635 "sintaxis.y"
{yyval.valor=igual("<TT>");;
    break;}
case 117:
#line 637 "sintaxis.y"
{yyval.valor=concatenar(yyvsp[-2].valor,"<EM>",yyvsp[0].valor,"",""); free(yyvsp[-2].valor); free(yyvsp[-1].valor); free(yyvsp[0].valor);;
    break;}
case 118:
#line 638 "sintaxis.y"
{yyval.valor=concatenar(yyvsp[-1].valor,"<EM>","","",""); free(yyvsp[-1].valor); free(yyvsp[0].valor);;
    break;}
case 119:
#line 639 "sintaxis.y"
{yyval.valor=concatenar("<EM>",yyvsp[0].valor,"","",""); free(yyvsp[-1].valor); free(yyvsp[0].valor);;
    break;}
case 120:
#line 640 "sintaxis.y"
{yyval.valor=igual("<EM>");;
    break;}
case 121:
#line 642 "sintaxis.y"
{yyval.valor=igual("");;
    break;}
case 122:
#line 643 "sintaxis.y"
{yyval.valor=yyvsp[-1].valor;;
    break;}
case 123:
#line 644 "sintaxis.y"
{yyval.valor=concatenar(yyvsp[-1].valor,"</I>","","",""); free(yyvsp[-1].valor);;
    break;}
case 124:
#line 645 "sintaxis.y"
{yyval.valor=concatenar(yyvsp[-1].valor,"</B>","","",""); free(yyvsp[-1].valor);;
    break;}
case 125:
#line 646 "sintaxis.y"
{yyval.valor=concatenar(yyvsp[-1].valor,"</TT>","","",""); free(yyvsp[-1].valor);;
    break;}
case 126:
#line 647 "sintaxis.y"
{yyval.valor=concatenar(yyvsp[-1].valor,"</EM>","","",""); free(yyvsp[-1].valor);;
    break;}
case 127:
#line 651 "sintaxis.y"
{
               yyval.valor=concatenar("\n<DIV ALIGN=center><CENTER>\n<TABLE BORDER=0 WIDTH=75%>\n<TR><TD WIDTH=100%><P ALIGN=center><B>Resum</B></P>\n<P>",yyvsp[-1].valor,"</TD>\n</TR></TABLE>\n</CENTER></DIV><P>\n","","");
               free(yyvsp[-1].valor);
           ;
    break;}
case 128:
#line 657 "sintaxis.y"
{
                      char* numero;
                      char* etiqueta_font;
                      char* etiqueta_nota;
                      char* aux; char* aux2;
                      char* num_node=intToAsc(compt_nodes);
                      notes_al_peu->guardarNota(yyvsp[0].valor, numero, etiqueta_font, etiqueta_nota);
                      aux = concatenar("<A NAME=", etiqueta_font, " HREF=node",num_node,".html#");
                      aux2 = aux; free(num_node);
                      yyval.valor = concatenar(aux,etiqueta_nota ,"><SUP>", numero, "</SUP></A>");
                      delete aux2; delete numero; delete etiqueta_font; delete etiqueta_nota;
                   ;
    break;}
case 129:
#line 671 "sintaxis.y"
{
                        char* aux;
                        aux = conversor->inserirFragmentMatematic(yyvsp[0].valor);
                        yyval.valor=concatenar("<img align=absmiddle src=",aux,">","","");
                        free(aux);
                    ;
    break;}
case 130:
#line 679 "sintaxis.y"
{
            if(fitxerExisteix(yyvsp[-1].valor))
             {
               char* aux = yyvsp[-1].valor;
               conversor->inserirImatge(yyvsp[-1].valor);
               yyvsp[-1].valor=canviarExtensioGrafica(yyvsp[-1].valor); free(aux);
               yyval.valor=concatenar("<img  align=absmiddle src=",yyvsp[-1].valor,">","","");
             }else {cout << "Avís-> No existeix el fitxer "<<yyvsp[-1].valor<<"\n";}
            free(yyvsp[-1].valor);
          ;
    break;}
case 131:
#line 690 "sintaxis.y"
{
            if(fitxerExisteix(yyvsp[-1].valor))
             {
               char* aux = yyvsp[-1].valor;
               conversor->inserirImatge(yyvsp[-1].valor);
               yyvsp[-1].valor=canviarExtensioGrafica(yyvsp[-1].valor); free(aux);
               yyval.valor=concatenar("<img  align=absmiddle src=",yyvsp[-1].valor,">","","");
             }else {cout << "Avís-> No existeix el fitxer "<<yyvsp[-1].valor<<"\n";}
            free(yyvsp[-1].valor);
          ;
    break;}
case 132:
#line 702 "sintaxis.y"
{yyval.valor=concatenar(yyvsp[-2].valor,yyvsp[-1].valor,yyvsp[0].valor,"",""); free(yyvsp[-2].valor); free(yyvsp[-1].valor); free(yyvsp[0].valor);;
    break;}
case 133:
#line 703 "sintaxis.y"
{yyval.valor=concatenar(yyvsp[-1].valor, yyvsp[0].valor, "","",""); free(yyvsp[-1].valor); free(yyvsp[0].valor);;
    break;}
case 134:
#line 704 "sintaxis.y"
{yyval.valor=concatenar(yyvsp[-1].valor, yyvsp[0].valor, "","",""); free(yyvsp[-1].valor); free(yyvsp[0].valor);;
    break;}
case 135:
#line 705 "sintaxis.y"
{yyval.valor=yyvsp[0].valor;;
    break;}
case 136:
#line 708 "sintaxis.y"
{
             char* aux;
             char* fitxer = assignarFitxer();

             compt_figures++;
             free(figura_en_curs);
             figura_en_curs = obtenirNomFigura();

             aux = intToAsc(compt_figures);
             pila->apilarEntorn(figura_en_curs, aux);
             yyval.valor=concatenar("\n<CENTER>Figura ",aux,": ",yyvsp[0].valor,"</CENTER>\n");

             document->inserirFigura(figura_en_curs, aux, yyvsp[0].valor, fitxer);
             free(aux); free(fitxer); free(yyvsp[0].valor);
          ;
    break;}
case 137:
#line 725 "sintaxis.y"
{
              pila->desapilarEntorn();
              yyval.valor=concatenar("\n<P><A NAME=", figura_en_curs,">", yyvsp[-1].valor,"</P>\n"); free(yyvsp[-1].valor);
           ;
    break;}
case 138:
#line 731 "sintaxis.y"
{
              yyval.valor=concatenar("\n<P>", yyvsp[-1].valor, "</P>\n","","");
              free(yyvsp[-1].valor);
           ;
    break;}
case 139:
#line 736 "sintaxis.y"
{yyval.valor=concatenar(yyvsp[-2].valor,yyvsp[-1].valor,yyvsp[0].valor,"",""); free(yyvsp[-2].valor); free(yyvsp[-1].valor); free(yyvsp[0].valor);;
    break;}
case 140:
#line 737 "sintaxis.y"
{yyval.valor=concatenar(yyvsp[-1].valor, yyvsp[0].valor, "","",""); free(yyvsp[-1].valor); free(yyvsp[0].valor);;
    break;}
case 141:
#line 738 "sintaxis.y"
{yyval.valor=concatenar(yyvsp[-1].valor, yyvsp[0].valor, "","",""); free(yyvsp[-1].valor); free(yyvsp[0].valor);;
    break;}
case 142:
#line 739 "sintaxis.y"
{yyval.valor=yyvsp[0].valor;;
    break;}
case 143:
#line 742 "sintaxis.y"
{
             char* aux;
             char* fitxer = assignarFitxer();

             compt_taules++;
             free(taula_en_curs);
             taula_en_curs = obtenirNomTaula();

             aux = intToAsc(compt_taules);
             pila->apilarEntorn(taula_en_curs, aux);
             yyval.valor=concatenar("\n<CENTER>Taula ",aux,": ",yyvsp[0].valor,"</CENTER>\n");

             document->inserirTaula(taula_en_curs, aux, yyvsp[0].valor, fitxer);
             free(aux); free(fitxer); free(yyvsp[0].valor);
          ;
    break;}
case 144:
#line 759 "sintaxis.y"
{
              pila->desapilarEntorn();
              yyval.valor=concatenar("\n<P><A NAME=", taula_en_curs,">", yyvsp[-1].valor,"</P>\n"); free(yyvsp[-1].valor);
           ;
    break;}
case 145:
#line 764 "sintaxis.y"
{
              yyval.valor=concatenar("\n<P>", yyvsp[-1].valor, "</P>\n","","");
              free(yyvsp[-1].valor);
           ;
    break;}
case 146:
#line 769 "sintaxis.y"
{yyval.valor=concatenar(yyvsp[-1].valor,yyvsp[0].valor,"","",""); free(yyvsp[-1].valor); free(yyvsp[0].valor);;
    break;}
case 147:
#line 770 "sintaxis.y"
{yyval.valor=igual("; "); free(yyvsp[0].valor); multi_bib=true;;
    break;}
case 148:
#line 771 "sintaxis.y"
{yyval.valor=concatenar("{B",yyvsp[0].valor,"}","",""); free(yyvsp[0].valor);;
    break;}
case 149:
#line 775 "sintaxis.y"
{
             if(!multi_bib) {yyval.valor=yyvsp[-1].valor;}
             else {yyval.valor=concatenar("(",yyvsp[-1].valor,")","",""); free(yyvsp[-1].valor);}
             multi_bib=false;
          ;
    break;}
case 150:
#line 781 "sintaxis.y"
{
               yyval.valor=concatenar("(",yyvsp[-1].valor,",",yyvsp[-4].valor,")"); free(yyvsp[-4].valor); free(yyvsp[-1].valor);
          ;
    break;}
case 151:
#line 786 "sintaxis.y"
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
             aux=concatenar("R",yyvsp[-1].valor,"","","");
             ref_creuades->inserirEtiqueta(aux, etiqueta, fitxer, comptador);
             yyval.valor=concatenar("<A NAME=",etiqueta,"></A>","","");
             free(etiqueta); free(comptador); free(fitxer); free(yyvsp[-1].valor); free(aux);
             compt_etiquetes++;
          ;
    break;}
case 152:
#line 809 "sintaxis.y"
{
               yyval.valor=concatenar("{R",yyvsp[-1].valor,"}","",""); free(yyvsp[-1].valor);
            ;
    break;}
case 153:
#line 813 "sintaxis.y"
{yyval.valor=concatenar("\n<P><B>",yyvsp[0].valor,"</B>&nbsp;&nbsp;&nbsp;","",""); free(yyvsp[0].valor);;
    break;}
case 154:
#line 814 "sintaxis.y"
{yyval.valor=igual("\n<P>&nbsp;&nbsp;&nbsp;");;
    break;}
case 155:
#line 817 "sintaxis.y"
{yyval.valor=concatenar("\n<P>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<B>",yyvsp[0].valor,"</B>&nbsp;&nbsp;&nbsp;","",""); free(yyvsp[0].valor);;
    break;}
case 156:
#line 818 "sintaxis.y"
{yyval.valor=igual("\n<P>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;");;
    break;}
case 157:
#line 822 "sintaxis.y"
{
                char* aux;

                if(emfasi) {aux = concatenar("</EM>",yyvsp[0].valor,"<EM>","","");}
                else {aux = concatenar("<EM>",yyvsp[0].valor,"</EM>","","");}

                yyval.valor=aux; free(yyvsp[0].valor);
             ;
    break;}
case 158:
#line 831 "sintaxis.y"
{
                char* aux;

                if(italica) aux = concatenar("</I>",yyvsp[0].valor,"<I>","","");
                else aux = concatenar("<I>",yyvsp[0].valor,"</I>","","");

                yyval.valor=aux; free(yyvsp[0].valor);
             ;
    break;}
case 159:
#line 840 "sintaxis.y"
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

                yyval.valor = concatenar(tancament,yyvsp[0].valor,obertura,"","");
                free(tancament); free(obertura); free(yyvsp[0].valor); free(it); free(nt); free(et);
                free(mt); free(io); free(no); free(eo); free(mo);
             ;
    break;}
case 160:
#line 869 "sintaxis.y"
{
                char* aux;

                if(negreta) aux = concatenar("</B>",yyvsp[0].valor,"<B>","","");
                else aux = concatenar("<B>",yyvsp[0].valor,"</B>","","");

                yyval.valor=aux; free(yyvsp[0].valor);
             ;
    break;}
case 161:
#line 878 "sintaxis.y"
{
                char* aux;

                if(subratllat) aux = concatenar("</U>",yyvsp[0].valor,"<U>","","");
                else aux = concatenar("<U>",yyvsp[0].valor,"</U>","","");

                yyval.valor=aux; free(yyvsp[0].valor);
             ;
    break;}
case 162:
#line 887 "sintaxis.y"
{
                char* aux;

                if(super) aux = concatenar("</SUP>",yyvsp[0].valor,"<SUP>","","");
                else aux = concatenar("<SUP>",yyvsp[0].valor,"</SUP>","","");

                yyval.valor=aux; free(yyvsp[0].valor);
             ;
    break;}
case 163:
#line 896 "sintaxis.y"
{
                char* aux;

                if(mecanografic) aux = concatenar("</TT>",yyvsp[0].valor,"<TT>","","");
                else aux = concatenar("<TT>",yyvsp[0].valor,"</TT>","","");

                yyval.valor=aux; free(yyvsp[0].valor);
             ;
    break;}
case 164:
#line 906 "sintaxis.y"
{emfasi=!emfasi;;
    break;}
case 165:
#line 906 "sintaxis.y"
{yyval.valor=yyvsp[0].valor; emfasi=!emfasi;;
    break;}
case 166:
#line 908 "sintaxis.y"
{italica=!italica;;
    break;}
case 167:
#line 908 "sintaxis.y"
{yyval.valor=yyvsp[-1].valor; italica=!italica;;
    break;}
case 168:
#line 911 "sintaxis.y"
{ 
                  if (italica) {italica=false; flag_italica=true;}
                  if (negreta) {negreta=false; flag_negreta=true;}
                  if (emfasi) {emfasi=false; flag_emfasi=true;}
                  if (mecanografic) {mecanografic=false; flag_mecanografic=true;}
                ;
    break;}
case 169:
#line 916 "sintaxis.y"
{yyval.valor=yyvsp[-1].valor;;
    break;}
case 170:
#line 919 "sintaxis.y"
{negreta=!negreta;;
    break;}
case 171:
#line 919 "sintaxis.y"
{yyval.valor=yyvsp[-1].valor; negreta=!negreta;;
    break;}
case 172:
#line 921 "sintaxis.y"
{mecanografic=!mecanografic;;
    break;}
case 173:
#line 921 "sintaxis.y"
{yyval.valor=yyvsp[-1].valor; mecanografic=!mecanografic;;
    break;}
case 174:
#line 923 "sintaxis.y"
{subratllat=!subratllat;;
    break;}
case 175:
#line 923 "sintaxis.y"
{yyval.valor=yyvsp[-1].valor; subratllat=!subratllat;;
    break;}
case 176:
#line 925 "sintaxis.y"
{super=!super;;
    break;}
case 177:
#line 925 "sintaxis.y"
{yyval.valor=yyvsp[-1].valor; super=!super;;
    break;}
case 178:
#line 928 "sintaxis.y"
{
             char* amplada = obtenirNumeros(yyvsp[-4].valor);
             char* gruix = obtenirNumeros(yyvsp[-1].valor);

             if(dreta) { yyval.valor=concatenar("\n<HR WIDTH=", amplada, " SIZE=", gruix, " ALIGN=right NOSHADE>\n"); }
             else if(esquerra) { yyval.valor=concatenar("\n<HR WIDTH=", amplada, " SIZE=", gruix, " ALIGN=left NOSHADE>\n"); }
             else { yyval.valor=concatenar("\n<HR WIDTH=", amplada, " SIZE=", gruix, " NOSHADE>\n"); }
             free(amplada); free(gruix); free(yyvsp[-4].valor); free(yyvsp[-1].valor);
         ;
    break;}
case 179:
#line 938 "sintaxis.y"
{;
    break;}
case 180:
#line 939 "sintaxis.y"
{;
    break;}
case 181:
#line 940 "sintaxis.y"
{;
    break;}
case 182:
#line 941 "sintaxis.y"
{;
    break;}
case 183:
#line 942 "sintaxis.y"
{;
    break;}
case 184:
#line 943 "sintaxis.y"
{;
    break;}
case 185:
#line 944 "sintaxis.y"
{;
    break;}
case 186:
#line 945 "sintaxis.y"
{;
    break;}
case 187:
#line 946 "sintaxis.y"
{;
    break;}
case 188:
#line 949 "sintaxis.y"
{centrat=true;;
    break;}
case 189:
#line 950 "sintaxis.y"
{
                  centrat=false;
                  yyval.valor=concatenar("<CENTER>",yyvsp[-1].valor,"</CENTER>","","");
                  free(yyvsp[-1].valor);
               ;
    break;}
case 190:
#line 955 "sintaxis.y"
{yyval.valor=igual("");;
    break;}
case 191:
#line 958 "sintaxis.y"
{esquerra=true;;
    break;}
case 192:
#line 959 "sintaxis.y"
{
                  esquerra=false;
                  yyval.valor=concatenar("<P ALIGN=left>",yyvsp[-1].valor,"</P>","","");
                  free(yyvsp[-1].valor);
               ;
    break;}
case 193:
#line 964 "sintaxis.y"
{yyval.valor=igual("");;
    break;}
case 194:
#line 967 "sintaxis.y"
{dreta=true;;
    break;}
case 195:
#line 968 "sintaxis.y"
{
                  dreta=false;
                  yyval.valor=concatenar("<P ALIGN=right>",yyvsp[-1].valor,"</P>","","");
                  free(yyvsp[-1].valor);
               ;
    break;}
case 196:
#line 973 "sintaxis.y"
{yyval.valor=igual("");;
    break;}
case 197:
#line 976 "sintaxis.y"
{yyval.valor=igual(yyvsp[-1].valor); free(yyvsp[-1].valor);;
    break;}
case 198:
#line 977 "sintaxis.y"
{yyval.valor=igual("");;
    break;}
case 199:
#line 979 "sintaxis.y"
{yyval.valor=yyvsp[0].valor;;
    break;}
case 200:
#line 980 "sintaxis.y"
{ yyval.valor=igual("");;
    break;}
case 201:
#line 984 "sintaxis.y"
{yyval.valor=yyvsp[0].valor;;
    break;}
case 202:
#line 985 "sintaxis.y"
{yyval.valor=igual("");;
    break;}
case 203:
#line 989 "sintaxis.y"
{yyval.valor=yyvsp[0].valor;;
    break;}
case 204:
#line 990 "sintaxis.y"
{yyval.valor=igual("");;
    break;}
case 205:
#line 993 "sintaxis.y"
{yyval.valor=yyvsp[0].valor;;
    break;}
case 206:
#line 994 "sintaxis.y"
{yyval.valor=igual("");;
    break;}
case 207:
#line 998 "sintaxis.y"
{yyval.valor=yyvsp[0].valor;;
    break;}
case 208:
#line 999 "sintaxis.y"
{yyval.valor=igual("");
    break;}
case 209:
#line 1002 "sintaxis.y"
{;
    break;}
case 210:
#line 1003 "sintaxis.y"
{;
    break;}
case 211:
#line 1007 "sintaxis.y"
{
           char* numero;
           char* etiqueta_font;
           char* etiqueta_nota;
           char* aux; char* aux2;
           notes_al_peu->guardarGracies(yyvsp[0].valor, numero, etiqueta_font, etiqueta_nota);
           aux = concatenar("<A NAME=", etiqueta_font, " HREF=#", etiqueta_nota, "><SUP>");
           aux2 = aux;
           yyval.valor = concatenar(aux, numero, "</SUP></A>", "", "");
           delete aux2; delete numero; delete etiqueta_font; delete etiqueta_nota;
         ;
    break;}
case 212:
#line 1019 "sintaxis.y"
{yyval.valor = concatenar(yyvsp[-1].valor, yyvsp[0].valor, "", "", ""); free(yyvsp[-1].valor); free(yyvsp[0].valor);;
    break;}
case 213:
#line 1020 "sintaxis.y"
{yyval.valor = igual("&nbsp;&nbsp;");;
    break;}
case 214:
#line 1021 "sintaxis.y"
{yyval.valor=yyvsp[0].valor;;
    break;}
case 215:
#line 1022 "sintaxis.y"
{yyval.valor=yyvsp[0].valor;;
    break;}
case 216:
#line 1026 "sintaxis.y"
{free(autors_document);
         autors_document = concatenar("<H3 align=center>",yyvsp[-1].valor,"</H3>\n","","");
         free(yyvsp[-1].valor);;
    break;}
case 217:
#line 1030 "sintaxis.y"
{free(autors_document);
         autors_document = concatenar("<H3 align=center>"," ","</H3>\n","","");;
    break;}
case 218:
#line 1034 "sintaxis.y"
{free(data_document);
        data_document = concatenar("<H4 align=center>",yyvsp[-1].valor,"</H4>\n","","");
        free(yyvsp[-1].valor);;
    break;}
case 219:
#line 1037 "sintaxis.y"
{;
    break;}
case 220:
#line 1039 "sintaxis.y"
{yyval.valor = concatenar(yyvsp[-1].valor, yyvsp[0].valor, "", "", ""); free(yyvsp[-1].valor); free(yyvsp[0].valor);;
    break;}
case 221:
#line 1040 "sintaxis.y"
{yyval.valor=yyvsp[0].valor;;
    break;}
case 222:
#line 1041 "sintaxis.y"
{yyval.valor=yyvsp[0].valor;;
    break;}
case 223:
#line 1045 "sintaxis.y"
{free(titol_document);
         titol_document = concatenar("<H1 align=center>",yyvsp[-1].valor,"</H1>\n","","");
         free(yyvsp[-1].valor);;
    break;}
case 224:
#line 1049 "sintaxis.y"
{free(titol_document);
         titol_document = concatenar("<H1 align=center>"," ","</H1>\n","","");;
    break;}
case 225:
#line 1053 "sintaxis.y"
{ yyval.valor = igual("&#36;"); ;
    break;}
case 226:
#line 1054 "sintaxis.y"
{ yyval.valor = igual("&#38;"); ;
    break;}
case 227:
#line 1055 "sintaxis.y"
{ yyval.valor = igual("&#37;"); ;
    break;}
case 228:
#line 1056 "sintaxis.y"
{ yyval.valor = igual("&#95;"); ;
    break;}
case 229:
#line 1057 "sintaxis.y"
{ yyval.valor = igual("&#123;"); ;
    break;}
case 230:
#line 1058 "sintaxis.y"
{ yyval.valor = igual("&#125;"); ;
    break;}
case 231:
#line 1059 "sintaxis.y"
{ yyval.valor = igual("&#60;"); ;
    break;}
case 232:
#line 1060 "sintaxis.y"
{ yyval.valor = igual("&#62;"); ;
    break;}
case 233:
#line 1061 "sintaxis.y"
{ yyval.valor = igual("&#8800;"); ;
    break;}
case 234:
#line 1062 "sintaxis.y"
{ yyval.valor = igual("&#8804;"); ;
    break;}
case 235:
#line 1063 "sintaxis.y"
{ yyval.valor = igual("&#8805;"); ;
    break;}
case 236:
#line 1064 "sintaxis.y"
{ yyval.valor = igual("&#8776;"); ;
    break;}
case 237:
#line 1065 "sintaxis.y"
{ yyval.valor = igual("&#223;"); ;
    break;}
case 238:
#line 1066 "sintaxis.y"
{ yyval.valor = igual("&#8801;"); ;
    break;}
case 239:
#line 1067 "sintaxis.y"
{ yyval.valor = igual("&#8734;"); ;
    break;}
case 240:
#line 1068 "sintaxis.y"
{ yyval.valor = igual("&#8745;"); ;
    break;}
case 241:
#line 1069 "sintaxis.y"
{ yyval.valor = igual("&#8747;"); ;
    break;}
case 242:
#line 1070 "sintaxis.y"
{ yyval.valor = igual("&#8730;"); ;
    break;}
case 243:
#line 1071 "sintaxis.y"
{ yyval.valor = igual("&#8721;"); ;
    break;}
case 244:
#line 1072 "sintaxis.y"
{ yyval.valor = igual("&#8719;"); ;
    break;}
case 245:
#line 1073 "sintaxis.y"
{ yyval.valor = igual("&#8710;"); ;
    break;}
case 246:
#line 1074 "sintaxis.y"
{ yyval.valor = igual("&#8706;"); ;
    break;}
case 247:
#line 1075 "sintaxis.y"
{ yyval.valor = igual("&#92;"); ;
    break;}
case 248:
#line 1076 "sintaxis.y"
{ yyval.valor = igual("&#124;"); ;
    break;}
case 249:
#line 1077 "sintaxis.y"
{ yyval.valor = igual("&#8226;"); ;
    break;}
case 250:
#line 1078 "sintaxis.y"
{ yyval.valor = igual("&#8225;"); ;
    break;}
case 251:
#line 1079 "sintaxis.y"
{ yyval.valor = igual("&#8224;"); ;
    break;}
case 252:
#line 1080 "sintaxis.y"
{ yyval.valor = igual("&#182;"); ;
    break;}
case 253:
#line 1081 "sintaxis.y"
{ yyval.valor = igual("&#167;"); ;
    break;}
case 254:
#line 1082 "sintaxis.y"
{ yyval.valor = igual("&#169;"); ;
    break;}
case 255:
#line 1083 "sintaxis.y"
{ yyval.valor = igual("&#94;"); ;
    break;}
case 256:
#line 1084 "sintaxis.y"
{ yyval.valor = igual("&#732;"); ;
    break;}
case 257:
#line 1085 "sintaxis.y"
{ yyval.valor = igual("&#174;"); ;
    break;}
case 258:
#line 1086 "sintaxis.y"
{ yyval.valor = igual("&#8482;"); ;
    break;}
case 259:
#line 1087 "sintaxis.y"
{ yyval.valor = igual("&#170;"); ;
    break;}
case 260:
#line 1088 "sintaxis.y"
{ yyval.valor = igual("&#186;"); ;
    break;}
case 261:
#line 1092 "sintaxis.y"
{ yyval.valor = igual("&#224;"); ;
    break;}
case 262:
#line 1093 "sintaxis.y"
{ yyval.valor = igual("&#225;"); ;
    break;}
case 263:
#line 1094 "sintaxis.y"
{ yyval.valor = igual("&#226;"); ;
    break;}
case 264:
#line 1095 "sintaxis.y"
{ yyval.valor = igual("&#228;"); ;
    break;}
case 265:
#line 1096 "sintaxis.y"
{ yyval.valor = igual("&#227;");;
    break;}
case 266:
#line 1097 "sintaxis.y"
{ yyval.valor = igual("&#257;");;
    break;}
case 267:
#line 1098 "sintaxis.y"
{;
    break;}
case 268:
#line 1099 "sintaxis.y"
{ yyval.valor = igual("&#259;");;
    break;}
case 269:
#line 1100 "sintaxis.y"
{;
    break;}
case 270:
#line 1101 "sintaxis.y"
{;
    break;}
case 271:
#line 1102 "sintaxis.y"
{;
    break;}
case 272:
#line 1103 "sintaxis.y"
{;
    break;}
case 273:
#line 1104 "sintaxis.y"
{;
    break;}
case 274:
#line 1105 "sintaxis.y"
{;
    break;}
case 275:
#line 1106 "sintaxis.y"
{;
    break;}
case 276:
#line 1107 "sintaxis.y"
{ yyval.valor = igual("&#229;");;
    break;}
case 277:
#line 1108 "sintaxis.y"
{ yyval.valor = igual("&#230;");;
    break;}
case 278:
#line 1109 "sintaxis.y"
{ yyval.valor = igual("&#192;"); ;
    break;}
case 279:
#line 1110 "sintaxis.y"
{ yyval.valor = igual("&#193;"); ;
    break;}
case 280:
#line 1111 "sintaxis.y"
{ yyval.valor = igual("&#194;"); ;
    break;}
case 281:
#line 1112 "sintaxis.y"
{ yyval.valor = igual("&#196;"); ;
    break;}
case 282:
#line 1113 "sintaxis.y"
{ yyval.valor = igual("&#195;");;
    break;}
case 283:
#line 1114 "sintaxis.y"
{ yyval.valor = igual("&#256;");;
    break;}
case 284:
#line 1115 "sintaxis.y"
{;
    break;}
case 285:
#line 1116 "sintaxis.y"
{ yyval.valor = igual("&#258;");;
    break;}
case 286:
#line 1117 "sintaxis.y"
{;
    break;}
case 287:
#line 1118 "sintaxis.y"
{;
    break;}
case 288:
#line 1119 "sintaxis.y"
{;
    break;}
case 289:
#line 1120 "sintaxis.y"
{;
    break;}
case 290:
#line 1121 "sintaxis.y"
{;
    break;}
case 291:
#line 1122 "sintaxis.y"
{;
    break;}
case 292:
#line 1123 "sintaxis.y"
{ yyval.valor = igual("&#198;");;
    break;}
case 293:
#line 1124 "sintaxis.y"
{ yyval.valor = igual("&#197;");;
    break;}
case 294:
#line 1126 "sintaxis.y"
{ yyval.valor = igual("&#232;"); ;
    break;}
case 295:
#line 1127 "sintaxis.y"
{ yyval.valor = igual("&#233;"); ;
    break;}
case 296:
#line 1128 "sintaxis.y"
{ yyval.valor = igual("&#234;"); ;
    break;}
case 297:
#line 1129 "sintaxis.y"
{ yyval.valor = igual("&#235;"); ;
    break;}
case 298:
#line 1130 "sintaxis.y"
{;
    break;}
case 299:
#line 1131 "sintaxis.y"
{ yyval.valor = igual("&#275;"); ;
    break;}
case 300:
#line 1132 "sintaxis.y"
{ yyval.valor = igual("&#279;"); ;
    break;}
case 301:
#line 1133 "sintaxis.y"
{ yyval.valor = igual("&#277;"); ;
    break;}
case 302:
#line 1134 "sintaxis.y"
{ yyval.valor = igual("&#283;"); ;
    break;}
case 303:
#line 1135 "sintaxis.y"
{;
    break;}
case 304:
#line 1136 "sintaxis.y"
{;
    break;}
case 305:
#line 1137 "sintaxis.y"
{;
    break;}
case 306:
#line 1138 "sintaxis.y"
{;
    break;}
case 307:
#line 1139 "sintaxis.y"
{;
    break;}
case 308:
#line 1140 "sintaxis.y"
{;
    break;}
case 309:
#line 1141 "sintaxis.y"
{ yyval.valor = igual("&#200;"); ;
    break;}
case 310:
#line 1142 "sintaxis.y"
{ yyval.valor = igual("&#201;"); ;
    break;}
case 311:
#line 1143 "sintaxis.y"
{ yyval.valor = igual("&#202;"); ;
    break;}
case 312:
#line 1144 "sintaxis.y"
{ yyval.valor = igual("&#203;"); ;
    break;}
case 313:
#line 1145 "sintaxis.y"
{;
    break;}
case 314:
#line 1146 "sintaxis.y"
{ yyval.valor = igual("&#274;"); ;
    break;}
case 315:
#line 1147 "sintaxis.y"
{ yyval.valor = igual("&#278;"); ;
    break;}
case 316:
#line 1148 "sintaxis.y"
{ yyval.valor = igual("&#276;"); ;
    break;}
case 317:
#line 1149 "sintaxis.y"
{ yyval.valor = igual("&#282;"); ;
    break;}
case 318:
#line 1150 "sintaxis.y"
{;
    break;}
case 319:
#line 1151 "sintaxis.y"
{;
    break;}
case 320:
#line 1152 "sintaxis.y"
{;
    break;}
case 321:
#line 1153 "sintaxis.y"
{;
    break;}
case 322:
#line 1154 "sintaxis.y"
{;
    break;}
case 323:
#line 1156 "sintaxis.y"
{ yyval.valor = igual("&#236;"); ;
    break;}
case 324:
#line 1157 "sintaxis.y"
{ yyval.valor = igual("&#237;"); ;
    break;}
case 325:
#line 1158 "sintaxis.y"
{ yyval.valor = igual("&#238;"); ;
    break;}
case 326:
#line 1159 "sintaxis.y"
{ yyval.valor = igual("&#239;"); ;
    break;}
case 327:
#line 1160 "sintaxis.y"
{ yyval.valor = igual("&#297;"); ;
    break;}
case 328:
#line 1161 "sintaxis.y"
{ yyval.valor = igual("&#299;"); ;
    break;}
case 329:
#line 1162 "sintaxis.y"
{;
    break;}
case 330:
#line 1163 "sintaxis.y"
{ yyval.valor = igual("&#301;"); ;
    break;}
case 331:
#line 1164 "sintaxis.y"
{;
    break;}
case 332:
#line 1165 "sintaxis.y"
{;
    break;}
case 333:
#line 1166 "sintaxis.y"
{;
    break;}
case 334:
#line 1167 "sintaxis.y"
{;
    break;}
case 335:
#line 1168 "sintaxis.y"
{;
    break;}
case 336:
#line 1169 "sintaxis.y"
{;
    break;}
case 337:
#line 1170 "sintaxis.y"
{;
    break;}
case 338:
#line 1171 "sintaxis.y"
{ yyval.valor = igual("&#204;"); ;
    break;}
case 339:
#line 1172 "sintaxis.y"
{ yyval.valor = igual("&#205;"); ;
    break;}
case 340:
#line 1173 "sintaxis.y"
{ yyval.valor = igual("&#206;"); ;
    break;}
case 341:
#line 1174 "sintaxis.y"
{ yyval.valor = igual("&#207;"); ;
    break;}
case 342:
#line 1175 "sintaxis.y"
{ yyval.valor = igual("&#296;"); ;
    break;}
case 343:
#line 1176 "sintaxis.y"
{ yyval.valor = igual("&#298;"); ;
    break;}
case 344:
#line 1177 "sintaxis.y"
{ yyval.valor = igual("&#304;"); ;
    break;}
case 345:
#line 1178 "sintaxis.y"
{ yyval.valor = igual("&#300;"); ;
    break;}
case 346:
#line 1179 "sintaxis.y"
{;
    break;}
case 347:
#line 1180 "sintaxis.y"
{;
    break;}
case 348:
#line 1181 "sintaxis.y"
{;
    break;}
case 349:
#line 1182 "sintaxis.y"
{;
    break;}
case 350:
#line 1183 "sintaxis.y"
{;
    break;}
case 351:
#line 1184 "sintaxis.y"
{;
    break;}
case 352:
#line 1186 "sintaxis.y"
{ yyval.valor = igual("&#242;"); ;
    break;}
case 353:
#line 1187 "sintaxis.y"
{ yyval.valor = igual("&#243;"); ;
    break;}
case 354:
#line 1188 "sintaxis.y"
{ yyval.valor = igual("&#244;"); ;
    break;}
case 355:
#line 1189 "sintaxis.y"
{ yyval.valor = igual("&#246;"); ;
    break;}
case 356:
#line 1190 "sintaxis.y"
{ yyval.valor = igual("&#245;"); ;
    break;}
case 357:
#line 1191 "sintaxis.y"
{ yyval.valor = igual("&#333;"); ;
    break;}
case 358:
#line 1192 "sintaxis.y"
{;
    break;}
case 359:
#line 1193 "sintaxis.y"
{ yyval.valor = igual("&#335;"); ;
    break;}
case 360:
#line 1194 "sintaxis.y"
{;
    break;}
case 361:
#line 1195 "sintaxis.y"
{ yyval.valor = igual("&#337;"); ;
    break;}
case 362:
#line 1196 "sintaxis.y"
{;
    break;}
case 363:
#line 1197 "sintaxis.y"
{;
    break;}
case 364:
#line 1198 "sintaxis.y"
{;
    break;}
case 365:
#line 1199 "sintaxis.y"
{;
    break;}
case 366:
#line 1200 "sintaxis.y"
{;
    break;}
case 367:
#line 1201 "sintaxis.y"
{ yyval.valor = igual("&#210;"); ;
    break;}
case 368:
#line 1202 "sintaxis.y"
{ yyval.valor = igual("&#211;"); ;
    break;}
case 369:
#line 1203 "sintaxis.y"
{ yyval.valor = igual("&#212;"); ;
    break;}
case 370:
#line 1204 "sintaxis.y"
{ yyval.valor = igual("&#214;"); ;
    break;}
case 371:
#line 1205 "sintaxis.y"
{ yyval.valor = igual("&#213;"); ;
    break;}
case 372:
#line 1206 "sintaxis.y"
{ yyval.valor = igual("&#332;"); ;
    break;}
case 373:
#line 1207 "sintaxis.y"
{;
    break;}
case 374:
#line 1208 "sintaxis.y"
{ yyval.valor = igual("&#334;"); ;
    break;}
case 375:
#line 1209 "sintaxis.y"
{;
    break;}
case 376:
#line 1210 "sintaxis.y"
{ yyval.valor = igual("&#336;"); ;
    break;}
case 377:
#line 1211 "sintaxis.y"
{;
    break;}
case 378:
#line 1212 "sintaxis.y"
{;
    break;}
case 379:
#line 1213 "sintaxis.y"
{;
    break;}
case 380:
#line 1214 "sintaxis.y"
{;
    break;}
case 381:
#line 1216 "sintaxis.y"
{ yyval.valor = igual("&#249;"); ;
    break;}
case 382:
#line 1217 "sintaxis.y"
{ yyval.valor = igual("&#250;"); ;
    break;}
case 383:
#line 1218 "sintaxis.y"
{ yyval.valor = igual("&#251;"); ;
    break;}
case 384:
#line 1219 "sintaxis.y"
{ yyval.valor = igual("&#252;"); ;
    break;}
case 385:
#line 1220 "sintaxis.y"
{ yyval.valor = igual("&#361;"); ;
    break;}
case 386:
#line 1221 "sintaxis.y"
{ yyval.valor = igual("&#363;"); ;
    break;}
case 387:
#line 1222 "sintaxis.y"
{;
    break;}
case 388:
#line 1223 "sintaxis.y"
{ yyval.valor = igual("&#365;"); ;
    break;}
case 389:
#line 1224 "sintaxis.y"
{;
    break;}
case 390:
#line 1225 "sintaxis.y"
{ yyval.valor = igual("&#369;"); ;
    break;}
case 391:
#line 1226 "sintaxis.y"
{;
    break;}
case 392:
#line 1227 "sintaxis.y"
{;
    break;}
case 393:
#line 1228 "sintaxis.y"
{;
    break;}
case 394:
#line 1229 "sintaxis.y"
{;
    break;}
case 395:
#line 1230 "sintaxis.y"
{;
    break;}
case 396:
#line 1231 "sintaxis.y"
{ yyval.valor = igual("&#217;"); ;
    break;}
case 397:
#line 1232 "sintaxis.y"
{ yyval.valor = igual("&#218;"); ;
    break;}
case 398:
#line 1233 "sintaxis.y"
{ yyval.valor = igual("&#219;"); ;
    break;}
case 399:
#line 1234 "sintaxis.y"
{ yyval.valor = igual("&#220;"); ;
    break;}
case 400:
#line 1235 "sintaxis.y"
{ yyval.valor = igual("&#360;"); ;
    break;}
case 401:
#line 1236 "sintaxis.y"
{ yyval.valor = igual("&#362;"); ;
    break;}
case 402:
#line 1237 "sintaxis.y"
{;
    break;}
case 403:
#line 1238 "sintaxis.y"
{ yyval.valor = igual("&#364;"); ;
    break;}
case 404:
#line 1239 "sintaxis.y"
{;
    break;}
case 405:
#line 1240 "sintaxis.y"
{ yyval.valor = igual("&#368;"); ;
    break;}
case 406:
#line 1241 "sintaxis.y"
{;
    break;}
case 407:
#line 1242 "sintaxis.y"
{;
    break;}
case 408:
#line 1243 "sintaxis.y"
{;
    break;}
case 409:
#line 1244 "sintaxis.y"
{;
    break;}
case 410:
#line 1246 "sintaxis.y"
{ yyval.valor = igual("&#231;"); ;
    break;}
case 411:
#line 1247 "sintaxis.y"
{ yyval.valor = igual("&#199;"); ;
    break;}
case 412:
#line 1248 "sintaxis.y"
{ yyval.valor = igual("&#241;"); ;
    break;}
case 413:
#line 1249 "sintaxis.y"
{ yyval.valor = igual("&#209;"); ;
    break;}
}

#line 712 "/usr/local/lib/bison.cc"
   /* the action file gets copied in in place of this dollarsign  */
  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YY_AnalitzadorSintactic_LSP_NEEDED
  yylsp -= yylen;
#endif

#if YY_AnalitzadorSintactic_DEBUG != 0
  if (YY_AnalitzadorSintactic_DEBUG_FLAG)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YY_AnalitzadorSintactic_LSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = YY_AnalitzadorSintactic_LLOC.first_line;
      yylsp->first_column = YY_AnalitzadorSintactic_LLOC.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++YY_AnalitzadorSintactic_NERRS;

#ifdef YY_AnalitzadorSintactic_ERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      YY_AnalitzadorSintactic_ERROR(msg);
	      free(msg);
	    }
	  else
	    YY_AnalitzadorSintactic_ERROR ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YY_AnalitzadorSintactic_ERROR_VERBOSE */
	YY_AnalitzadorSintactic_ERROR("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (YY_AnalitzadorSintactic_CHAR == YYEOF)
	YYABORT;

#if YY_AnalitzadorSintactic_DEBUG != 0
      if (YY_AnalitzadorSintactic_DEBUG_FLAG)
	fprintf(stderr, "Discarding token %d (%s).\n", YY_AnalitzadorSintactic_CHAR, yytname[yychar1]);
#endif

      YY_AnalitzadorSintactic_CHAR = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;              /* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YY_AnalitzadorSintactic_LSP_NEEDED
  yylsp--;
#endif

#if YY_AnalitzadorSintactic_DEBUG != 0
  if (YY_AnalitzadorSintactic_DEBUG_FLAG)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YY_AnalitzadorSintactic_DEBUG != 0
  if (YY_AnalitzadorSintactic_DEBUG_FLAG)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = YY_AnalitzadorSintactic_LVAL;
#ifdef YY_AnalitzadorSintactic_LSP_NEEDED
  *++yylsp = YY_AnalitzadorSintactic_LLOC;
#endif

  yystate = yyn;
  goto yynewstate;
}

/* END */

/* #line 909 "/usr/local/lib/bison.cc" */
#line 1251 "sintaxis.y"


extern "C" { int yywrap() {return 1;} }
















































