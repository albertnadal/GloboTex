#ifndef _ITERADOR_H
#define _ITERADOR_H


/*****************************************************************
CLASSE Iterador<T>

Implementa la classe dels objectes Iterador sobre una classe 
contenidor qualsevol amb elements components de classe T.
*****************************************************************/

template<class T>
class Iterador{

public:
  // Totes les funcion són virtuals pures.

 virtual void situarInici()=0;
 virtual void situarFinal()=0;
 virtual Iterador<T>& operator++()=0;
 virtual Iterador<T>& operator++(int)=0;
 virtual T& operator*()=0;
 virtual bool fi()=0;
 virtual bool inici()=0;
};


#endif

