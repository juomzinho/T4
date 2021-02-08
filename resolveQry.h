#ifndef _RESOLVEQRY_H_
#define _RESOLVEQRY_H_
#include "cidade.h"

/*Esta funcao retorna o y de um elemento
 passado como parametro*/
double getYQRY(Info elemento);

/*Esta funcao retorna o numero armazenado de um elemento
 passado como parametro*/
int getNQRY(Info elemento);

/*Esta funcao retorna o x de um elemento
 passado como parametro*/
double getXQRY(Info elemento);

/*Esta funcao retorna o x2 de um elemento
 passado como parametro*/
double getX2QRY(Info elemento);

/*Esta funcao retorna o y2 de um elemento
 passado como parametro*/
double getY2QRY(Info elemento);

/*Esta funcao retorna o de um elemento
 passado como parametro*/
double getWQRY(Info elemento);

/*Esta funcao retorna o h de um elemento
 passado como parametro*/
double getHQRY(Info elemento);

/*Esta funcao retorna a area de um elemento
 passado como parametro*/
double getAreaQRY(Info elemento);

/*Esta funcao retorna o raio de um elemento
 passado como parametro*/
double getRaioQRY(Info elemento);

/*Esta funcao retorna o cep de uma quadra
 passado como parametro*/
char *getCepQRY(Info elemento);

/*Esta funcao retorna o tipo de um elemento
 passado como parametro*/
char getTipoQRY(Info elemento);

/*Esta funcao retorna o largura da borda de um elemento
 passado como parametro*/
char *getSWQRY(Info elemento);

/* esta funcao aloca memoria e armazena os dados de um circulo
ela recebe dos dados do circulo e a lista por parametro 
no fim ela insere o circulo na lista*/
void criaCirculo(Lista l, double raio, double x, double y);

/* esta funcao aloca memoria e armazena os dados de uma linha
ela recebe dos dados da linha e a lista por parametro 
no fim ela insere a linha na lista*/
void criaLinha(double x, double y, char cep[], Cidade listas);

/* esta funcao aloca memoria e armazena os dados da area de um cep
ela recebe dos dados da area e a lista por parametro 
no fim ela insere a linha na lista*/
void criaArea(double w, double h, double x, double y, Lista l);

/* esta funcao aloca memoria e armazena os dados de um retangulo
ela recebe dos dados do retangulo e a lista por parametro 
no fim ela insere o retangulo na lista*/
void criaRetanguloQry(double x, double y, double w, double h, char sw[], Lista lista);

/* esta funcao aloca memoria e armazena os dados de um retangulo com a borda tracejada ou linha cheia
ela recebe dos dados do retangulo e a lista por parametro 
no fim ela insere o retangulo na lista*/
void criaRetFormasQry(double x, double y, double w, double h, char sw[], Lista lista, char forma);

/* esta funcao resolve o comando car
ela recebe como parametro a lista que contem as listas, os dados lidos do comando car
e o nome arquivo do txt junto ao seu diretório*/
void car(Cidade listas, double x, double y, double w, double h, char txtArq[]);

/* esta funcao resolve o comando crd
ela recebe como parametro a lista que contem as listas, os dados lidos do comando crd
e o nome arquivo do txt junto ao seu diretório*/
void crd(Cidade listas, char id[], char txtArq[]);

/* esta funcao resolve o comando cbq
ela recebe como parametro a lista que contem as listas, os dados lidos do comando cbq
e o nome arquivo do txt junto ao seu diretório*/
void cbq(Cidade listas, double x, double y, double raio, char cstrk[], char txtarq[]);

/* esta funcao resolve o comando del
ela recebe como parametro a lista que contem as listas, os dados lidos do comando del
e o nome arquivo do txt junto ao seu diretório*/
void del(Cidade listas, char id[], char txtarq[]);

/* esta funcao resolve o comando dq
ela recebe como parametro a lista que contem as listas, os dados lidos do comando dq
e o nome arquivo do txt junto ao seu diretório*/
void dq(Cidade listas, char id[], double r, bool verifica, char txtarq[]);

/* esta funcao retorna o maior valor, recebido
ele rebece dois valores double por paremetro*/
double max(double x1, double x2);

/* esta funcao retorna o menor valor, recebido
ele rebece dois valores double por paremetro*/
double min(double x1, double x2);

/* esta funcao retorna a distancia entre dois pontos,
ele rebece os dados dos pontos por paremetro*/
double dist(double x1, double y1, double x2, double y2);

/* esta funcao retorna se um ponto é ou nao interno de um circulo,
ele rebece os dados do ponto e do circulo por paremetro*/
bool PontoInterno(double x1, double y1, double x2, double y2, double raio);

/* esta funcao retorna se um ponto é ou nao interno de um retangulo,
ele rebece os dados do ponto e do retangulo por paremetro*/
bool PontoInternoRet(double px, double py, double x, double y, double h, double w);

/* esta funcao resolve o comando o?
ela recebe como parametro a lista, os dados lidos do comando o?
e o nome arquivo do txt junto ao seu diretório*/
void oFormas(int j, int k, Lista lista, char txt[]);

/* esta funcao resolve o comando i?
ela recebe como parametro a lista, os dados lidos do comando i?
e o nome arquivo do txt junto ao seu diretório*/
void iFormas(int j, double x, double y, Lista lista, char txt[]);

/* esta funcao resolve o comando pnt
ela recebe como parametro a lista, os dados lidos do comando pnt
e o nome arquivo do txt junto ao seu diretório*/
void pnt(int j, char stroke[], char fill[], Lista lista, char txt[]);

/* esta funcao resolve o comando pnt*
ela recebe como parametro a lista, os dados lidos do comando pnt*
e o nome arquivo do txt junto ao seu diretório*/
void pntplus(int j, int k, char stroke[], char fill[], Lista lista, char txt[]);

/* esta funcao resolve o comando delf
ela recebe como parametro a lista, os dados lidos do comando delf
e o nome arquivo do txt junto ao seu diretório*/
void delf(int j, Lista lista, char txt[]);

/* esta funcao resolve o comando delf*
ela recebe como parametro a lista, os dados lidos do comando delf*
e o nome arquivo do txt junto ao seu diretório*/
void delfplus(int j, int k, Lista lista, char txt[]);

#endif