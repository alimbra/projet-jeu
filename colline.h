#ifndef COLLINE_H_INCLUDED
#define COLLINE_H_INCLUDED
#include <string.h>
#include <iostream>
#include <QApplication>
#include <DrawingWindow.h>
using namespace std;
class Colline
{
public:

  // Constructeur
  Colline(int longueur,int hauteur,int repereX,int repereY);

  // Prototype de fonction
  int getlongueur();

  int gethauteur();

  void dessinerColline(DrawingWindow &w);

  float courbe(int x,int l,int h);

//Attribut TOUJOURS en private
private:

  int longueur,hauteur,repereX,repereY;

};



#endif // COLLINE_H_INCLUDED
