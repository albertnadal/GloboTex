#ifndef _LLISTA_H
#define _LLISTA_H

#include <stdlib.h>
#include <iostream>
#include "ed.h"

using namespace std;

/************************************************************************
CLASSE Llista:
L'iterador apunta a l'anterior. 
**************************************************************************/

template <class T> class IteradorLlista;

template <class T>
class node{
  public:
    T valor;
    node<T>* seg;
    node<T>* ant;

    ~node() {if(seg!=ant) delete valor;}
  };


template <class T>
class Llista :public ED {

  node<T>* primer;

 public:

  void buidar();

  friend class IteradorLlista<T>;
  friend class footnotes;
  friend class conversorGrafic;

  class noMem{};

  Llista();
  Llista(Llista<T>&);

  ~Llista();

  void operator=(Llista<T>&);

  void inserirCap(T&);
  void inserir(T&, IteradorLlista<T>&);
  void inserirFi(T&);

  void eliminarCap();
  void eliminar(IteradorLlista<T>&);
  void eliminarFi();

  void consultarCap(T& t); 
  void consultarFi(T& t);
  void consultar(T& t, IteradorLlista<T>&);

  void esBuida(bool& b) { b = (nElems==0); };
  friend bool operator==<T>(Llista<T>&, Llista<T>&);
  friend ostream& operator<<<T>(ostream&, Llista<T>&);
  
};

template<class T>
void Llista<T>::buidar(){
  // Esborra els elements de la llista i la deixa buida
   node<T>* aux;
   while (primer->seg!=primer) {
     aux=primer->seg; 
     primer->seg=primer->seg->seg; 
     delete aux;
   }
   primer->ant=primer;
   nElems=0;
 }



template<class T> Llista<T>::Llista() 
{  
  primer=new node<T>; 
  if (primer==NULL) throw noMem();
  primer->seg=primer;
  primer->ant=primer;
  nElems=0;
}


template<class T> Llista<T>::Llista(Llista<T>& l2) 
{   
   primer=new node<T>; 
   if (primer==NULL) throw noMem();
   primer->seg=primer;
   primer->ant=primer;
   nElems=0;
   *(this)=l2;
}

template<class T> Llista<T>::~Llista()
{
  // Esborra tots els nodes dels que consta la llista.
  node<T>* aux;

  while (primer->seg!=primer) {
    aux=primer->seg; 
    primer->seg=primer->seg->seg;
    delete aux;
  }  
  delete primer;
}


template<class T> void Llista<T>::inserirCap(T& t)
{
 node<T>* aux;

 aux=new node<T>;
 if (aux==NULL) throw noMem();
 aux->valor=t;
 aux->seg=primer->seg;
 aux->ant=primer;
 primer->seg->ant=aux;
 primer->seg=aux;
 nElems++;
}

template<class T> void Llista<T>::inserirFi(T& t)
{
 node<T>* aux;

 aux=new node<T>;
 if (aux==NULL) throw noMem();
 aux->valor=t;
 aux->ant=primer->ant;
 aux->seg=primer;
 primer->ant->seg=aux;
 primer->ant=aux;
 nElems++;
}


template <class T> void Llista<T>::inserir(T& t, IteradorLlista<T>& ite){

 node<T>* aux;

 aux=new node<T>;
 if (aux==NULL) throw noMem();
 aux->valor=t;
 aux->seg=ite.ed->seg;
 aux->ant=ite.ed;
 ite.ed->seg->ant=aux;
 ite.ed->seg=aux;
 ite.ed=aux;
 nElems++;

}


template <class T> void Llista<T>::eliminar(IteradorLlista<T>& ite){

 node<T>* aux;

 aux=ite.ed->seg;
 ite.ed->seg->seg->ant=ite.ed;
 ite.ed->seg=ite.ed->seg->seg;
 nElems--;
 delete aux;
}

template <class T> void Llista<T>::eliminarCap(){

 node<T>* aux;

 aux = primer->seg;
 if(aux!=primer)
  {
     primer->seg = aux->seg;
     aux->seg->ant = primer;
     nElems--;
     delete aux;
  }
}

template<class T> void Llista<T>::consultarCap(T& t){

 t=primer->seg->valor;
}

template<class T> void Llista<T>::consultarFi(T& t){

 t=primer->ant->valor;
}

template<class T> void Llista<T>::consultar(T& t, IteradorLlista<T>& ite){

 t=ite.ed->seg->valor;
}


template<class T> void Llista<T>::operator=(Llista<T>& l2){

  IteradorLlista<T> ite1(*this), ite2(l2);
  T t;

  buidar();   
 
  ite1.situarInici();
  ite2.situarInici();
  while (!ite2.fi()){
   t=*ite2;  
   inserir(t,ite1);
   ite2++;
  }
}

template<class T> bool operator==(Llista<T>& l1, Llista<T>& l2){
  bool iguals=true;
  node<T>* node1=l1.primer;
  node<T>* node2=l2.primer;
  while (iguals && node1!=NULL && node2!=NULL) {
    iguals=(node1->valor==node2->valor);
    node1=node1->seg;
    node2=node2->seg;
  }
  return iguals && node1==node2;
}

template<class T> ostream& operator<<(ostream& s, Llista<T>& p){
 
  T x;
  node<T>* aux;
  
  aux=p.primer->seg;
  while (aux != p.primer)
  {
	 s<<aux->valor<<"\n";
         aux=aux->seg;
  }
  s<<"-----------\n";
  return s;
}  

#endif









