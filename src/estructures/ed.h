#ifndef _ED_H
#define _ED_H

/************************************************************************
CLASSE ED:

- Classe base que compta el nombre d'elements que conte una estructura.
*************************************************************************/


class ED{

 protected:

  int nElems;

 public:

 int mida(){return nElems;} 
 bool buida() { return nElems==0; }

};

#endif


