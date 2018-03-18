#ifndef _ITETHASH_H
#define _ITETHASH_H

#include <iostream>
#include "itetaula.h"
#include "thash.h"

using namespace std;

// Depenent del si el hash l'heu fet obert o tancat us caldra
// incloure:
// #include "llista.h"
// #include "itellis.h"

template<class T, class FH,unsigned  int B>
class THash;

template <class T>
  class node;

template<class T, class FH,unsigned  int B>
class IteradorTHash :public IteradorTaula<T>{

  // Representació del Iterador Taula

  THash<T,FH,B>* ref;
  unsigned int ed;

 public:

 friend class THash<T,FH,B>;
 IteradorTHash();
 IteradorTHash<T,FH,B>(THash<T,FH,B>& t);
 void situarInici();
 void situarFinal();
 IteradorTHash& operator++();      //++it;
 IteradorTHash& operator++(int);   //it++;
 IteradorTHash& operator--();      //--it;
 IteradorTHash& operator--(int i); //it--;
 void operator=(IteradorTHash<T,FH,B>& i);
 T& operator*();
 bool fi();
 bool inici();
 friend bool operator==<T>(IteradorTHash<T,FH,B>&, IteradorTHash<T,FH,B>&);
 friend bool operator<=<T>(IteradorTHash<T,FH,B>&, IteradorTHash<T,FH,B>&);
};

template<class T,class FH,unsigned int B>
IteradorTHash<T,FH,B>::IteradorTHash( )
{/*Procediment Constructor*/}

template<class T,class FH,unsigned int B>
IteradorTHash<T,FH,B>:: IteradorTHash( THash<T,FH,B>& t)
{
 ref=&t;
 ed=0;
}

template<class T,class FH,unsigned int B>
void IteradorTHash<T,FH,B>:: situarInici()
{
 ed=0;
 while(( ref->v[ed].marca!='o')&&(ed<B))
  {
   ed++;
  }
}

template<class T,class FH,unsigned int B>
void IteradorTHash<T,FH,B>:: situarFinal()
{ed = B;}

template<class T,class FH,unsigned int B>
IteradorTHash<T,FH,B>& IteradorTHash<T,FH,B>::operator++()
{
 bool trobat=false;
 IteradorTHash<T,FH,B>* aux;
 aux=new IteradorTHash<T,FH,B> (*ref);
 ed++;
 while ((!trobat)&&(!(fi())))
  {
    if( ref->v[ed].marca=='o'){ trobat = true; }
    else{ed++;}
  }
 *aux=*this;
 return *aux;
}

template<class T,class FH,unsigned int B>
IteradorTHash<T,FH,B>& IteradorTHash<T,FH,B>::operator++(int i)
{
 bool trobat=false;
 IteradorTHash<T,FH,B>* aux;
 aux = new IteradorTHash<T,FH,B> (*ref);
 *aux = *this;
 ed++;
 while((!trobat)&&(!(fi())))
  {
   if(ref->v[ed].marca=='o'){ trobat = true;}
   else{ ed++;}
  }
 return *aux;
}
template<class T,class FH,unsigned int B>
IteradorTHash<T,FH,B>& IteradorTHash<T,FH,B>::operator--()
{
 IteradorTHash<T,FH,B>* aux;
 aux = new IteradorTHash<T,FH,B> (*ref);
 ed--;
 while((ref->v[ed].marca!='o')&&(!(inici())))
  {ed--;}
 *aux = *this;
 return *aux;
}

template<class T,class FH,unsigned int B>
IteradorTHash<T,FH,B>& IteradorTHash<T,FH,B>::operator--(int i)
{
 IteradorTHash<T,FH,B>* aux;
 aux = new IteradorTHash<T,FH,B> (*ref);
 *aux = *this;
 ed--;
 while(ref->v[ed].marca!='o') {ed--;}
 return *aux;
}

template<class T,class FH,unsigned int B>
void IteradorTHash<T,FH,B>::operator=(IteradorTHash<T,FH,B> & it)
{
 ed=it.ed;
 ref=it.ref;
}

template<class T,class FH,unsigned  int B>
T& IteradorTHash<T,FH,B>:: operator*()
{return ref->v[ed].valor;}

template<class T,class FH,unsigned int B>
bool IteradorTHash<T,FH,B>::inici()
{
 IteradorTHash<T,FH,B> aux (*ref);
 aux.situarInici();
 return aux == *this;
}

template<class T,class FH,unsigned int B>
bool IteradorTHash<T,FH,B>::fi()
{return ed==B;}

template<class T,class FH,unsigned int B>
bool operator <=(IteradorTHash<T,FH,B> &it,IteradorTHash<T,FH,B>& it2)
{return(it.ref==it2.ref)&&(it.ed<=it2.ed);}

template<class T,class FH,unsigned int B>
bool operator==( IteradorTHash<T,FH,B> &it, IteradorTHash<T,FH,B>& it2)
{return( it.ref==it2.ref)&&( it.ed==it2.ed);}

#endif

