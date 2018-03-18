#ifndef _THASH_H
#define _THASH_H

#include "ed.h"
#include "taula.h"
#include "itethash.h"
#include <iostream>
#include <string.h>

using namespace std;

// Depenent de si feu hash obert o tancat fareu servir llistes o no
// i, per tant, en el cas obert, haureu de fer:
// #include "llista.h"
// #include "itellis.h"

template <class T, class FH, unsigned int B>
class IteradorTHash;

template <class T>
class hnode
{ //Definim una parella de Clau-Valor amb una marca
 public:
  T valor;
  char* clau;
  char marca;
};

template <class T, class FH,unsigned int B>
class THash :public Taula<T>{

   hnode<T> v[B]; //consta de B nodes i...
   FH h; // ... una funció hash

 public:

 class noMem{};
 class noExist{};

 THash();
 ~THash();
 void inserir(char* k, T& x);
 void consulta(char* k, T& x, bool& noexist);
 void consulta(char* k, IteradorTHash<T,FH,B>& it, bool& noexist);
 void consulta(IteradorTHash<T,FH,B>& it, T& x);
 void eliminar(char* k);
 void eliminar(IteradorTHash<T,FH,B>& it);
 void buidar();
 //void operator=(THash<T,FH,B>& t);

 friend ostream& operator<< <T,FH,B>(ostream& ,THash<T,FH,B>&);
 friend class IteradorTHash<T,FH,B>;
};

template<class T,class FH,unsigned int B>
THash<T,FH,B>::~THash()
{
 unsigned int e;
 e=0;
 while(e<B)
  {
   if(v[e].marca=='o'){delete [] v[e].clau;}
   e++;
  }
}
template<class T,class FH,unsigned int B>
THash<T,FH,B>:: THash()
{
 unsigned int i=0 ;
 while(i<B)
  {
   v[i].marca='l';
   i++;
  }
}

template<class T,class FH, int B>
void THash<T,FH,B>::inserir(char* k, T&x)
{
 bool lliure=false;
 bool trobat=false;
 bool eliminat=false;
 unsigned int i, PosTrobada, posicio;

 i=0;
 while((i<B)&&(!lliure)&&(!trobat))
    {
      posicio=h(k,i);
      if (v[posicio].marca=='l'){ lliure=true;}
      else if(v[posicio].marca=='e')
        {
         eliminat=true;
         PosTrobada=posicio;
        }
      else if(strcmp( v[posicio].clau,k)==0){ trobat=true;}
      i++;
    }

 if(trobat)
    {
      v[posicio].valor=x;
    }

 else if(eliminat==true)
    {
      delete []  v[PosTrobada].clau;
      v[PosTrobada].clau = new char [strlen(k)+1];
      strcpy(v[PosTrobada].clau,k);
      v[PosTrobada].valor=x;
      v[PosTrobada].marca='o';
    }
 else if(lliure)
    {
      v[posicio].clau=new char [strlen(k)+1];
      strcpy(v[posicio].clau,k);
      v[posicio].valor=x;
      v[posicio].marca='o';
    }
 else { throw  noMem(); }

}

template<class T,class FH,unsigned int B>
void THash<T,FH,B>:: consulta (char* k, T & valor,bool & noexist )
{

 bool trobat=false;
 bool lliure=false;
 unsigned int i=0;
 int posicio;

 while((i<B)&&(!lliure)&&(!trobat))
  {
    posicio=h(k,i);
    if(v[posicio].marca=='l'){lliure=true;}
    else if((strcmp(v[posicio].clau,k)==0)&&(v[posicio].marca=='o')){ trobat=true;}
    else{ i++;}
  }
 if(trobat)
  {
    valor=v[posicio].valor;
    noexist=false;
  }
 else{noexist=true;}
}

template<class T,class FH,unsigned int B>
void THash<T,FH,B>:: consulta( IteradorTHash<T,FH,B>& it,T&x)
{ x=*it; }


template< class T,class FH,unsigned int B>
void THash<T,FH,B>:: consulta( char* k, IteradorTHash<T,FH,B> &it,bool &noexist)
{
 bool trobat=false;
 bool lliure=false;
 unsigned int i=0;
 int posicio;

 while( (i<B)&&(lliure)&&(!trobat))
  {
    posicio=h(k,i);
    if(v[posicio].marca=='l'){lliure=true;}
    else if((strcmp(v[posicio].clau,k)==0)&&(v[posicio].marca=='o')){ trobat=true;}
    else{ i++;}
  }
 if(trobat)
  {
   it.ed=posicio;
   it.ref=this;
  }
 else {noexist=true;}
}


template<class T, class FH,unsigned int B>
void THash<T,FH,B> :: eliminar( char* k)
{
 bool trobat=false;
 bool lliure=false;
 int posicio;
 unsigned int i=0;

 while((i<B)&&(!lliure)&&(!trobat))
  {
   posicio=h(k,i);
   if( v[posicio].marca=='l'){lliure=true;}
   else if((strcmp(v[posicio].clau,k)==0)&&(v[posicio].marca=='o')){trobat=true;}
   else{ i++;}
  }
 if(trobat){ v[posicio].marca='e';}
 else{throw noExist();}

}


template< class T,class FH,unsigned int B>
void THash<T,FH,B>:: eliminar( IteradorTHash<T,FH,B> & it)
{
  delete [] v[it.ed].clau;
  v[it.ed].marca='e';
}


template<class T, class FH,unsigned  int B>
void THash<T,FH,B>:: buidar()
{
 IteradorTHash<T,FH,B> aux(*this);
 aux.SituarInici();
 while(!(aux.fi))
  {
   *(this).eliminar(aux);
   aux++;
  }
}


template<class T,class FH,unsigned int B>
ostream& operator<<(ostream& c,THash<T,FH,B>& t)
{
 for(unsigned int i=0;i<B;i++) { if(t.v[i].marca=='o') c<<t.v[i].valor<<"\n"; }
 return c;
}

#endif /*_THASH_H*/



