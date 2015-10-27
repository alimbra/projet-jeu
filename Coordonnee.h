
#include <string.h>
#include <iostream>
class Coordonnee
{
public:

	Coordonnee(float xx,float yy);
	
	Coordonnee (const Coordonnee &);

	float getX(int o);

	float getY(int o);

	int posX(int o,float x);
	
	int posY(int o,float y);
	
	void setX(float xx);

	void setY(float yy);

private:
	float x,y;		
};
