#include <string.h>
#include <iostream>
#include "Coordonnee.h"

using namespace std;

Coordonnee::Coordonnee(float xx,float yy):
	x(xx),y(yy){}

Coordonnee::Coordonnee(const Coordonnee &c):
	x(c.x),y(c.y){}

float Coordonnee::getX(int o){
	return this->x;
}

float Coordonnee::getY(int o){
	return this->y;
}
	

int Coordonnee::posX(int o,float x)
{
	return o+this->x;
}

int Coordonnee::posY(int o,float y)
{
	return o-this->y;
}

void Coordonnee::setX(float xx)
{
	this->x=xx;
}

void Coordonnee::setY(float yy)
{
	this->y=yy;
}
