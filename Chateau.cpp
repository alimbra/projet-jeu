

#include <string.h>
#include <iostream>
#include "Chateau.h"

//#include <QApplication>
//#include <DrawingWindow.h>


using namespace std;



Chateau::Chateau(Coordonnee c1,Coordonnee c2,Coordonnee cp1,Coordonnee cp2,float loc,float lac,float lap,float lop,string cc,string cp){  
  x.setX(c1.getX());
  X.setY(c1.getY());

  y=new Coordonnee(c2);
  xp=new Coordonnee(cp1);
  yp=new Coordonnee(cp2);
  longueur=loc;
  largeur=lac;
  longeurPorte=lop;
  largeurPorte=lap;
  CouleurCh=cc;
  CouleurP=cp;
}  

Coordonnee Chateau::getCoordonneX(){
	return x;
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
string Chateau::getCouleurCh(){
	return this->CouleurCh;
}
string Chateau::getCouleurP(){
	return this->CouleurP;
}

/*void Coordonne::dessiner(Chateau c,DrawingWindow w,int o){
 	w.setColor(c.getCouleurCh);
	w.fillRect(c.getCoordonneX().getX(o),c.getCoordonneX().getY(o),
	       c.getCoordonneY().getX(o),c.getCoordonneY().getY(o));

	int i=0;	
	while(i<=100){
	w.fillRect(c.getCoordonneX().getX(o)+i,c.getCoordonneX().getY(o),
	       c.getCoordonneY().getX(o)+i,c.getCoordonneY().getY(o));
		i=i+10;
	}
	w.setColor(c.getCouleurP());
	w.fillRect(c.getCoordonneXP().getX(o),
		c.getCoordonneXP().getY(o),
		c.getCoordonneYP().getX(o),
		c.getCoordonneYP().getY(o)
	);
/*	w.fillRect(posX(cx/2,-310),posY(cy/2,-160),
		posX(cx/2,-275),posY(cy/2,-240));
	w.setColor("brown");
/*	w.fillRect(posX(cx/2,-340),posY(cy/2,-205)
		,posX(cx/2,-315),posY(cy/2,-240));
 	w.setColor("black");*/
	//w.drawText(posX(cx/2,-360),posY(cy/2,-260),"le joueur 1");
//} 
  
