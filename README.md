GloboTex
========

GloboTex és un compilador de documents LaTeX a HTML desenvolupant en C++ emprant els analitzadors lèxics i sintàctics Flex++-2.3.8-6 i Bison++-1.21-5. Es tracta del meu projecte de final de carrera d'enginyeria tècnica en informàtica de gestió desenvolupat durant el mesos de maig i juny de 2003.


Dependencies
============

El correcte funcionament del compilador requereix tenir instal·lat GhostScript i les pbmnet tools al sistema.


Install
=======


```
g++ globo.cc -o globo
```

Copiar el fitxer binari generat en alguna carpeta del sistema i finalment copiar la carpeta de les icones dins d'aquesta.


Usage
=====

El traductor admet tres tipus de paràmetres:

```
globo -c

```
Arranca un intèrpret de comandes per configurar les opcions del traductor.


```
globo fitxer.tex
```

Tradueix el fitxer a HTML i guarda el resultat en un directori amb el mateix nom.

```
globo -v
```

Mostra la versió actual del traductor.
