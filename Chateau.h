
#include <string.h>
#include "Coordonnee.h"
#include <iostream>
//#include <QApplication>
//#include <DrawingWindow.h>
using namespace std;
class Chateau
{
public:
  
  Chateau(Coordonnee c1,Coordonnee c2,Coordonnee cp1,Coordonnee cp2,float loc,float lac,float lap,float lop,string cc,string cp);
  Coordonnee getCoordonneX();
  Coordonnee getCoordonneY();
  Coordonnee getCoordonneXP();
  Coordonnee getCoordonneYP();
  float getlongueur();
  float getlargeur();
  float getlongueurPorte();
  float getlargeurPorte();
  string getCouleurCh();
  string getCouleurP();
  //void dessinerChateau(Chateau c,DrawingWindow w,int o); 

private:
  
  Coordonnee *x,*y,*xp,*yp;

  float longueur,largeur,longeurPorte,largeurPorte;
  string CouleurCh,CouleurP;
};
