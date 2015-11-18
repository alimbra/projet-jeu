#include "Colline.h"

#include <iostream>
#include <QApplication>
#include <DrawingWindow.h>
using namespace std;


Colline::Colline(int longeurC,int hauteurC,int repereXF,int repereYF):
 longueur(longeurC),hauteur(hauteurC),repereX(repereXF),repereY(repereYF){}

int Colline::getlongueur(){
	return this->longeur;
}

int Colline::gethauteur(){
	return this->hauteur;
}

void Colline::dessinerColline(DrawingWindow &w){
	int cx=this->repereX;
	int cy=this->repereY;
	w.setColor("green");
	int h = this->hauteur;
	int l = this->longueur;

	/* 2 boucle for
	* Pour la partie gauche et la partie droite
	* de la colline
	*/
	for(int i=0;i<l/2;i++)
	{
	    // on travaille sur un repère orthonormé
		w.drawLine(cx/2+i,cy-cy/8,
		cx/2+i,cy-cy/8-courbe(i,l*l,h));
	}
	for(int i=0;i>-l/2;i--)
	{
		w.drawLine(cx/2+i,cy-cy/8
		,cx/2+i,cy-cy/8-courbe(i,l*l,h));
	}
}

float Colline::courbe(int x,int h,int l){
	return h*(1-4*x*x/l);
}
