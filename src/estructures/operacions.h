/***** Llibreria d'operacions comuns *****/
#ifndef _OPERACIONS_H
#define _OPERACIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

char* igual(char* cadena)
 {
     char* aux = new char[strlen(cadena) + 1];
     strcpy(aux,cadena);
     return aux;
 }

char* concatenar(char* a, char* b, char* c, char* d, char* e)
 {
     char* aux = (char*)malloc(strlen(a) + strlen(b) + strlen(c) + strlen(d) + strlen(e) + 1);
     strcpy(aux, a);
     strcat(aux, b);
     strcat(aux, c);
     strcat(aux, d);
     strcat(aux, e);
     return aux;
 }

char* resaltarLinksUrl(char* c)
 {
   int i=0;
   int e=0;
   int o=0;
   bool www;
   bool http;
   bool ftp;
   char* aux = new char[strlen(c)+1]; aux[0]='\0';
   char* aux2;

   while(c[i]!='\0')
    {
       http = ((c[i]=='h')&&(c[i+1]=='t')&&(c[i+2]=='t')&&(c[i+3]=='p')&&(c[i+4]==':')&&(c[i+5]=='/')&&(c[i+6]=='/'));
       www = ((c[i]=='w')&&(c[i+1]=='w')&&(c[i+2]=='w')&&(c[i+3]=='.'));
       ftp = ((c[i]=='f')&&(c[i+1]=='t')&&(c[i+2]=='p')&&(c[i+3]==':')&&(c[i+4]=='/')&&(c[i+5]=='/'));
       if(((http)&&(i+7<strlen(c))) || ((www)&&(i+4<strlen(c))) || ((ftp)&&(i+6<strlen(c))))
        {
            aux2 = aux; 
            aux = new char[strlen(aux)+ (2 * strlen(c)) + strlen("<A HREF=></A>") + 1];
            strcpy(aux, aux2); strcat(aux, "<A HREF="); free(aux2);
            
            aux2 = new char[strlen(c) + 1];
            o=0;
            while((c[i]!=' ')&&(c[i]!='\0'))
             {
                 aux2[o]=c[i];
                 i++;
                 o++;
             }
            aux2[o]='\0';
            strcat(aux, aux2); strcat(aux,">"); strcat(aux, aux2); strcat(aux, "</A>");
            e=strlen(aux);
            free(aux2);
        }
       else
        {
            aux[e]=c[i];
            i++;
            e++;
            aux[e]='\0';
        }
    }
   return aux;
 }

void copiarFitxer(char* ruta_desti, char* fitxer)
 {
     char comanda_copiar[200];
     strcpy(comanda_copiar, "cp ");     
     strcat(comanda_copiar, fitxer);
     strcat(comanda_copiar, " ");
     strcat(comanda_copiar, ruta_desti);
     system(comanda_copiar);
 }

bool fitxerExisteix(char* fitxer)
 {
     FILE* f;
     f = fopen(fitxer, "r");
     if (f==NULL) {return false;}
     else {fclose(f); return true;}
 }

char* intToAsc(int numero)
 {
     char* num = new char[20];
     sprintf(num, "%d", numero);
     return num;
 }

char* canviarExtensioGrafica(char* fitxer)
 {
     char* aux = new char[strlen(fitxer)+5];
     int e=0;

     while((fitxer[e]!='.')&&(e<=strlen(fitxer)))
      {
         aux[e] = fitxer[e];
         e++;
      }
     aux[e]='.'; aux[e+1]='g'; aux[e+2]='i';
     aux[e+3]='f'; aux[e+4] = '\0';
     return aux;
 }

char* obtenirNumeros(char* numero)
 {
     int e = 0;
     bool fi=false;
     char* aux = new char[strlen(numero) + 1];
     strcpy(aux, numero);
     while(!fi)
      {
         if(aux[e]=='0') {e++;}
         else if(aux[e]=='1') {e++;}
         else if(aux[e]=='2') {e++;}
         else if(aux[e]=='3') {e++;}
         else if(aux[e]=='4') {e++;}
         else if(aux[e]=='5') {e++;}
         else if(aux[e]=='6') {e++;}
         else if(aux[e]=='7') {e++;}
         else if(aux[e]=='8') {e++;}
         else if(aux[e]=='9') {e++;}
         else fi=true;
      }
     aux[e] = '\0';
     return aux;
 }

void psToGif(char* fitxer_ps, char* fitxer_gif, int ressolucio)
 {
     char* comanda_ps_to_gif;
     char* res = intToAsc(ressolucio);
     char* aux;

     if(fitxerExisteix(fitxer_ps))
      {
         comanda_ps_to_gif=concatenar("./ps2gif ", fitxer_ps, " ", fitxer_gif," ");
         aux=comanda_ps_to_gif;
         comanda_ps_to_gif=concatenar(comanda_ps_to_gif, res, "","",""); free(aux);
         system(comanda_ps_to_gif);
         free(comanda_ps_to_gif);
      }else {cout << "Avís-> No existeix el fitxer "<<fitxer_ps<<"\n";}
     free(res);
 }

void latexToGif(char* fragment_mat, char* nom, char* fitxer_gif)
 {
     char* codi_latex;
     char* comanda_latex_to_gif;
     char* fitxer_tex;
     FILE* f;

     codi_latex=concatenar("\\begin{document}\n$", fragment_mat, "$\n\\end{document}","","");
     fitxer_tex=new char[strlen(nom) + strlen(".tex") + 1];
     strcpy(fitxer_tex, nom);
     strcat(fitxer_tex, ".tex");
     f = fopen(fitxer_tex, "w");
     fputs(codi_latex, f);    
     fclose(f);
     comanda_latex_to_gif=concatenar("./latex2gif ", nom," ",fitxer_gif,"");
     system(comanda_latex_to_gif);
     free(fitxer_tex); free(comanda_latex_to_gif); free(codi_latex);
 }  
#endif





