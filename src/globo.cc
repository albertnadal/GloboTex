#include <iostream>
#include "globotex.h"

int main(int argc, char *argv[])
{

if(argc!=2)
{
  cout << argv[0] << ":nombre incorrecte d'arguments\nProva <<" << argv[0] << " --ajuda>> per obtenir més informació.\n" ;
  exit(0);
}

GloboTex tex;

if (strcmp(argv[1], "-c")==0) {tex.mostrarTitol(); tex.configurar();}
else if (strcmp(argv[1], "-v")==0) {cout << "globoTeX versió 1.0\n";}
else if (strcmp(argv[1], "--ajuda")==0)
 {
    cout << "Per traduïr usa:           " << argv[0] << " nom_fitxer.tex\n";
    cout << "Per configurar usa:        " << argv[0] << " -c\n";
    cout << "Per mostrar la versió usa: " << argv[0] << " -v\n";
 }
else 
 {
    tex.mostrarTitol();
    tex.carregarFitxer(argv[1]);
    tex.Iniciar();
 }
};


