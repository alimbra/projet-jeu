

#include <string.h>
#include <iostream>
#include "Chateau.h"
#include <math.h>   
//#include <QApplication>
//#include <DrawingWindow.h>

using namespace std;


Chateau::Chateau(const Coordonnee &c1,
				const Coordonnee &c2,
				const Coordonnee &cp1,
                const Coordonnee &cp2,
                float loc,float lac,
                float lap,float lop,
                const char * cc,const char * cp)
{  
  x=Coordonnee(c1);
  y=Coordonnee(c2);
  xp=Coordonnee(cp1);
  yp=Coordonnee(cp2);
  longueur=loc;
  largeur=lac;
  longeurPorte=lop;
  largeurPorte=lap;
  int taille=(strlen(cc)+1)*sizeof(char);
  CouleurCh=(char*)malloc(taille);
  int taille1=(strlen(cp)+1)*sizeof(char);
  CouleurP=(char*)malloc(taille1);
  strcpy(CouleurCh,cc);
  strcpy(CouleurP,cp);
}  

Coordonnee Chateau::getCoordonneX(){
	return this->x;
}

Coordonnee Chateau::getCoordonneY(){
	return this->y;
}

Coordonnee Chateau::getCoordonneXP(){
	return this->xp;
}
Coordonnee Chateau::getCoordonneYP(){
	return this->yp;
}
float Chateau::getlongueur(){
	return this->longueur;
}
float Chateau::getlargeur(){
	return this->largeur;
}
float Chateau::getlongueurPorte(){
	return this->longeurPorte;
}
float Chateau::getlargeurPorte(){
	return this->largeurPorte;
}
char* Chateau::getCouleurCh(){
	return this->CouleurCh;
}
char* Chateau::getCouleurP(){
	return this->CouleurP;
}
/*
 *dessiner le chateau 
 */
void Chateau::dessinerChateau(DrawingWindow &w){
    w.setColor(this->getCouleurCh());    
    w.fillRect(x.getX(),
            x.getY(),
            y.getX(),
            y.getY()
  );
    
  w.setColor(this->getCouleurP());
  w.fillRect(xp.getX()
    ,xp.getY()
    ,yp.getX()
    ,yp.getY()
  );

  w.setColor(this->getCouleurCh());   
  w.fillRect(
    x.getX(),
    x.getY()-largeur,
    xp.getX(),
    x.getY()
  );
  w.setColor(this->getCouleurCh());
  w.fillRect(
    yp.getX(),
    x.getY()-largeur,
    y.getX(),
    y.getY()
  );

  // contour de la porte
  w.setColor("black");
  w.drawLine(xp.getX(),xp.getY(),
    xp.getX(),yp.getY());
  
  w.drawLine(xp.getX(),xp.getY(),
    yp.getX(),xp.getY());
  w.drawLine(yp.getX(),xp.getY(),
    yp.getX(),yp.getY());
  w.drawLine(xp.getX()+3+longeurPorte/2,xp.getY(),
    xp.getX()+3+longeurPorte/2,yp.getY());  

} 


} 
  
