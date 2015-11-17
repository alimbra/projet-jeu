
#include <string.h>
#include "Coordonnee.h"
#include <iostream>
#include <QApplication>
#include <DrawingWindow.h>
using namespace std;
class Chateau
{
public:
  
  Chateau(const Coordonnee &c1,const Coordonnee &c2,
         const Coordonnee &cp1,const Coordonnee &cp2,
        float loc,float lac,float lap,
        float lop,const char* cc,const char* cp);

  Coordonnee getCoordonneX();
  Coordonnee getCoordonneY();
  Coordonnee getCoordonneXP();
  Coordonnee getCoordonneYP();
  float getlongueur();
  float getlargeur();
  float getlongueurPorte();
  float getlargeurPorte();
  char* getCouleurCh();
  char* getCouleurP();
  void dessinerChateau(DrawingWindow &w); 

private:
  
  Coordonnee x,y,xp,yp;
  float longueur,largeur,longeurPorte,largeurPorte;
  char * CouleurCh;
  char * CouleurP;
};
