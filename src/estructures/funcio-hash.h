#ifndef _FUNCIO_HASH_
#define _FUNCIO_HASH_

/******************************************************************

    Funcio de hash per prova-hash.cc

    Esta feta pel cas del hash obert. Si feu hash tancat, heu de
    canviar-la per:

    template<unsigned int B>
    class FH{
    public:
    unsigned int operator()(char* k, int j)
    {
    unsigned int i=0, sum=0;
    while(k[i]!='\0')
      {
        sum=sum+k[i]; i++;}
        return (sum+j*j) % B;
      }
    };

*******************************************************************/


    template<unsigned int B>
    class FH{
    public:
    unsigned  int operator()(char* k, int j)
    {
    unsigned int i=0, sum=0;
    while(k[i]!='\0')
      {
        sum=sum+k[i]; i++;}
        return (sum+j*j) % B;
      }
    };

#endif


