
#include <string.h>
#include <iostream>
class Coordonnee
{
public:

	Coordonnee();

	Coordonnee(int xx,int yy,int repereX,int repereY);

	Coordonnee (const Coordonnee &);
	
	int getX();

	int getY();
	
	void setX(int xx);

	void setY(int yy);

	void setRepereX(int rpx);

	void setRepereY(int rpy);
private:
	int x,y,repereX,repereY;		
};
