#include <string.h>
#include <iostream>
#include "Coordonnee.h"

using namespace std;

Coordonnee::Coordonnee():x(0),y(0),repereX(0),repereY(0){
}

Coordonnee::Coordonnee(int xx,int yy,int rx,int ry):
	x(xx+rx),y(ry-yy),repereX(rx),repereY(ry){}

Coordonnee::Coordonnee(const Coordonnee &c){
	x=c.x;
	y=c.y;
	repereX=c.repereX;
	repereY=c.repereY;
}



int Coordonnee::getX(){
	return this->x;
}

int Coordonnee::getY(){
	return this->y;
}
	

void Coordonnee::setX(int xx)
{
	this->x=xx;
}

void Coordonnee::setY(int yy)
{
	this->y=yy;
}

void Coordonnee::setRepereX(int rpx)
{
	this->repereX=rpx;
}

void Coordonnee::setRepereY(int rpy)
{
	this->repereY=rpy;
}
