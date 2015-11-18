#include "Chateau.h"
#include "string.h"

#include "Colline.h"

#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <fstream>
using namespace std;

std::vector<int> lireFichier() {

    ifstream monFlux("monFichier.txt",std::ifstream::in);
    vector<int> tab(0);
    if(monFlux) {

        string ligne;
        int nombre; // on stocke le nombre

        monFlux >> nombre;
        tab.push_back(nombre);
        //cout << nombre << endl;

        while(getline(monFlux, ligne)) { //Tant qu'on n'est pas à la fin, on lit

                monFlux >> nombre;
                tab.push_back(nombre);
               // cout << nombre << endl;
                //Et on l'affiche dans la console
                //Ou alors on fait quelque chose avec cette ligne
                //À vous de voir
       }
    } else {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }
    return tab;
}


void dessiner(DrawingWindow &w){

    vector<int> valeurs = lireFichier();
    int long_colline = valeurs[0];
    int larg_colline = valeurs[1];
    int abs_prem_chateau = valeurs[2];
    int long_prem_chateau = valeurs[3];
    int larg_prem_chateau = valeurs[4];
    int abs_sec_chateau = valeurs[5];
    int long_sec_chateau = valeurs[6];
    int larg_sec_chateau = valeurs[7];
    int abs_prem_porte = valeurs[8];
    int long_prem_porte = valeurs[9];
    int larg_prem_porte = valeurs[10];
    int abs_sec_porte = valeurs[11];
    int long_sec_porte = valeurs[12];
    int larg_sec_porte = valeurs[13];


	const int cx=w.width;
	const int cy=w.height;

	//dessiner la Terre

	w.setColor("dodgerblue");
	w.fillRect(0,0,cx,cy);
	w.setColor("saddlebrown");
	w.fillRect(0,cy-cy/8,cx,cy);

//	dessinerChateaux(w);



	int y1=cy/8-cy/2;
	Coordonnee b=Coordonnee(abs_prem_chateau,y1+larg_prem_chateau,cx/2,cy/2);
	Coordonnee c=Coordonnee(abs_prem_chateau+long_prem_chateau,y1,cx/2,cy/2);
	Coordonnee bb=Coordonnee(abs_prem_porte,y1+larg_prem_porte,cx/2,cy/2);
	Coordonnee cc=Coordonnee(abs_prem_porte+long_prem_porte,y1,cx/2,cy/2);
	Chateau chateau1=Chateau(b,c,bb,cc,long_prem_chateau,larg_prem_chateau,long_prem_porte,larg_prem_porte,"darkslategrey","dimgray");

	Coordonnee b2=Coordonnee(abs_sec_chateau,y1+larg_sec_chateau,cx/2,cy/2);
	Coordonnee c2=Coordonnee(abs_sec_chateau+long_sec_chateau,y1,cx/2,cy/2);
	Coordonnee bb2=Coordonnee(abs_sec_porte,y1+larg_sec_porte,cx/2,cy/2);
	Coordonnee cc2=Coordonnee(abs_sec_porte+long_sec_porte,y1,cx/2,cy/2);
	Chateau chateau=Chateau(b2,c2,bb2,cc2,long_sec_chateau,larg_sec_chateau,long_sec_porte,larg_sec_porte,"darkslategrey","dimgray");

	chateau.dessinerChateau(w);
	chateau1.dessinerChateau(w);


	Colline colline=Colline(long_colline,larg_colline,cx,cy);
	colline.dessinerColline(w);
	w.setColor("black");
	w.drawText(cx/12,cy-cy/10,"joueur 1 ");
	w.drawText(cx-cx/6,cy-cy/10,"joueur 2");

	//dessiner la fleche
	int wind=20-rand()%40;
	w.setColor("black");
	w.fillRect(
		cx/2+wind-40,cy/2-320
		,wind+cx/2+40,cy/2-310);
	if(wind>0){
		w.fillTriangle(cx/2+wind+40,cy/2-330,
		cx/2+wind+40,cy/2-300,
		wind+cx/2+60,cy/2-315);
	}
	else
	{
	    w.fillTriangle(
	    cx/2+wind-40,cy/2-330,
		cx/2+wind-40,cy/2-300,
		wind+cx/2-60,cy/2-315);
	}
	//creation du jeu

	// Définition des variables et des constantes
	float vx, vy , ax, ay, vr, xt, yt, angle, force;
  	const float  k=0.005;
  	const float g=9.81;
  	bool victoire=false;

	//le joueur 1 commence
	bool joueur1=true;
	int scorejoueur1=0;
	int scorejoueur2=0;
	// la position du boulet est calculee toutes les 0.0005 secondes
  	float dt=0.0005;

 	//le vent est entre -20 et 20 et les dimensions de la colline sont aleatoires
 	int h=10;
	int vrai_hauteur=h;
	w.setColor("black");

	//Affichage des dimensions de la colline, de la vitesse du vent dans la console
  	cout<<endl<<"Hauteur de colline : "<<vrai_hauteur<<endl;
  	cout<<"Largeur de la colline : "<<colline.getlongueur()<<endl;
  	cout<<"Vitesse du vent : "<<wind<<endl;
	while(victoire==false)
	{

	// Le joueur 1 joue

	 if(joueur1==true)
	 {

	 // Lecture de la force et de l'angle de trajectoire du boulet

   	  cout<<endl<<"Joueur 1 - Entrez une force : ";
      cin>>force;
      cout<<"Joueur 1 - Entrez un angle : ";
      cin>>angle;
      cout<<endl;
	  angle =angle/180*M_PI;

	  // Calcul de la vitesse initiale du boulet
	  vx=ceil(force*cos(angle));
      vy=ceil(force*sin(angle));

	  // Coordonnées initiales du boulet
      xt=chateau1.getCoordonneY().getX();
      yt=chateau1.getCoordonneX().getY()-cy/2;
      //yt=110;

	  // Affichage du boulet à ses coordonées initiales
 	  w.setColor("black");
  	  w.fillCircle(xt, (int)-yt+cy, 3);

	  // Calcul et affichage de la trajectoire du boulet
	  while((yt>0)&&(xt<cx+4))
	  {
  	   w.setColor("dodgerblue");
  	   w.fillCircle((int)sqrt(xt*xt), (int)-yt+cy, 3);
       vr=sqrt((vx-wind)*(vx-wind)+vy*vy);
       ax=-k*vr*(vx-wind);
  	   ay=-k*vr*vy-g;
  	   vx=vx+ax*dt;
   	   vy=vy+ay*dt;
       xt=(xt+vx*dt);
       yt=(yt+vy*dt);
	   w.setColor("black");
	   w.fillCircle((int)sqrt(xt*xt), (int)-yt+cy, 3);
	   w.usleep(100);

	   // Détection de la terre

       if ((int)-yt+cy==cy-cy/8)
	   {
	    w.setColor("dodgerblue");
	    w.fillCircle((int)sqrt(xt*xt), (int)-yt+cy, 10);
	    yt=0;
	   }

	   //Detection de la colline
       if(((w.getPointColor((int)sqrt(xt*xt)+5,
		(int)-yt+cy+5)))==0xff008000)
	   {
	    w.setColor("dodgerblue");
   	    w.fillCircle((int)sqrt(xt*xt),(int)-yt+cy,15);
	    yt=0;
	   }

	   //Detection de la couleur darkslategrey des 2 chateaux
	   if(((w.getPointColor((int)sqrt(xt*xt)+3,
		(int)-yt+cy+3)))==0xff2f4f4f)
	   {
	     w.setColor("yellow");
	     for(int k12=1;k12<=20;k12++){
	      w.fillCircle((int)sqrt(xt*xt),(int)-yt+cy,k12);
    	  w.msleep(100);
	     }
	     w.setColor("dodgerblue");
	     w.fillCircle((int)sqrt(xt*xt),(int)-yt+cy,20);
	     yt=0;
	    if((int)sqrt(xt*xt)<cx/2)
	    {
	     w.setColor("black");
	     w.drawText(cx/2-40,cy/2-280,"Suicide !");
	     joueur1=false;
	     victoire=true;
	     int nombreR=0;
	     cout<<"cliquez sur 1 pour recommencer ?";
	     cin>>nombreR;
	     if (nombreR==1)
	     {
	      dessiner(w);
	     }
	    }
	    else
	    {
	     w.setColor("black");
	     w.drawText(cx/2-40,cy/2-280,
		"joueur 1 vous avez gagne!");
	     victoire=true;
	     int nombreR=0;
	      cout<<"cliquez sur 1 pour recommencer ?";
	      cin>>nombreR;
	      if (nombreR==1)
	      {
	      	dessiner(w);
	      }
	    }
	   }

	   //Detection du mur du chateau
	   if (((int)sqrt(xt*xt)+3==cx/2-275)&&
		((int)-yt+3+cy>=cy-190))
	   {
	    w.setColor("yellow");
	    for(int i3=1;i3<=20;i3++)
	    {
	     w.fillCircle((int)sqrt(xt*xt),
	     (int)-yt+cy,i3);
	     w.msleep(100);
	    }
	    w.setColor("dodgerblue");
	    w.fillCircle((int)sqrt(xt*xt),
	    (int)-yt+cy, 20);
	    yt=0;

	    if((int)sqrt(xt*xt)<cx/2)
	    {
	     w.setColor("black");
	     w.drawText(cx/2-40,cy/2-280,"Suicide !");
	     joueur1=false;
         victoire=true;
          int nombreR=0;
	      cout<<"cliquez sur 1 pour recommencer ?";
	      cin>>nombreR;
	      if (nombreR==1)
	      {
	      	dessiner(w);
	      }
	    }
	    else
	    {
	     w.drawText(cx/2-40,cy/2-280,
		"joueur 1vous avez gagne !");
	     joueur1=false;
	     victoire=true;
	     int nombreR=0;
	      cout<<"cliquez sur 1 pour recommencer ?";
	      cin>>nombreR;
	      if (nombreR==1)
	      {
	      	dessiner(w);
	      }}
	    }

	   //detection de la couleur dimgray des 2 chateaux
	    if(((w.getPointColor((int)sqrt(xt*xt)+3,
		(int)-yt+cy+3)))==0xff696969)
	    {
	     w.setColor("yellow");
	     for(int i=1;i<=20;i++)
	     {
	      w.fillCircle((int)sqrt(xt*xt), (int)-yt+cy, i);
	      w.msleep(100);
	     }
	     w.setColor("dodgerblue");
	     w.fillCircle((int)sqrt(xt*xt), (int)-yt+cy, 20);
	     yt=0;
	   //detection de la couleur dimgray du chateau 1
	     if((int)sqrt(xt*xt)<cx/2)
	     {
	      w.setColor("black");
	      w.drawText(cx/2-20,cy/2-280,"Suicide !");
	      joueur1=false;
	      victoire=true;
	      int nombreR=0;
	      cout<<"cliquez sur 1 pour recommencer ?";
	      cin>>nombreR;
	      if (nombreR==1)
	      {
	      	dessiner(w);
	      }
	     }
	     else
	     {
	      w.setColor("black");
	      w.drawText(cx/2-40,cy/2-280,
			"joueur 1 vous avez gagné");
	      victoire=true;
	       int nombreR=0;
	      cout<<"cliquez sur 1 pour recommencer ?";
	      cin>>nombreR;
	      if (nombreR==1)
	      {
	      	dessiner(w);
	      }
	     }
	    }
	   }
	  }
 else
	  {
	  	// Lecture de la force et de l'angle de trajectoire du boulet
      	   cout<<endl<<"Joueur 2 - Entrez une force : ";
           cin>>force;
           cout<<"Joueur 2 - Entrez un angle : ";
           cin>>angle;
           cout<<endl;

	   // Conversion de l'angle en radians
           angle=angle/180*M_PI;

	   // Coordonnées initiales du boulet
   
           xt=chateau.getCoordonneX().getX()-cx/2;
     	   yt=chateau.getCoordonneX().getY()-cy/2;
      	   // Calcul de la vitesse initiale du boulet
      	   vx=ceil(force*cos(angle));
           vy=ceil(force*sin(angle));

     	   // Affichage du boulet à ses coordonées initiales
      	   w.setColor("black");
      	   w.fillCircle(cx-(int)sqrt(xt*xt), (int)-yt+cy, 3);

	   // Calcul et affichage de la trajectoire du boulet
      	   while((yt>0)&&(xt<cx+4))
           {
            w.setColor("dodgerblue");
            w.fillCircle(cx-(int)sqrt(xt*xt), (int)-yt+cy, 3);
            vr=sqrt((vx+wind)*(vx+wind)+vy*vy);
            ax=-k*vr*(vx+wind);
            ay=-k*vr*vy-g;
            vx=vx+ax*dt;
            vy=vy+ay*dt;
            xt=(xt+vx*dt);
            yt=(yt+vy*dt);
            w.setColor("black");
            w.fillCircle(cx-(int)sqrt(xt*xt), (int)-yt+cy, 3);
            w.usleep(100);
            // Détection de la terre
            if ((int)-yt+cy==cy-cy/8 )
	   	 	{
	    	 w.setColor("dodgerblue");
	    	 w.fillCircle(cx-(int)sqrt(xt*xt), (int)-yt+cy, 15);
	     	 yt=0;
	    	}

	   //Detection de la colline
            if(((w.getPointColor((int)sqrt(xt*xt)+3
		,(int)-yt+cy+3)))==0xff008000)
	    {
	     w.setColor("dodgerblue");
   	     w.fillCircle(cx-(int)sqrt(xt*xt), (int)-yt+cy, 15);
	     yt=0;
	    }
	   //Detection de la couleur darkslategray du  chateau
             if(((w.getPointColor(cx-(int)sqrt(xt*xt)+3,
	    (int)-yt+cy+3)))==0xff2f4f4f)
	    {
	     w.setColor("yellow");
	     for(int ka=1;ka<=30;ka++)
	     {
	      w.fillCircle(cx-(int)sqrt(xt*xt), (int)-yt+cy,ka);
	      w.msleep(70);
	     }
	     w.setColor("dodgerblue");
	     w.fillCircle(cx-(int)sqrt(xt*xt), (int)-yt+cy, 50);
	     yt=0;
 	     w.setColor("black");
	     if(cx-(int)sqrt(xt*xt)>cx/2)
	     {
	     w.drawText(cx/2-40,cy/2-280,"Suicide !");
	     joueur1=false;
	     victoire=true;
	      int nombreR=0;
	      cout<<"cliquez sur 1 pour recommencer ?";
	      cin>>nombreR;
	      if (nombreR==1)
	      {
	      	dessiner(w);
	      }
	     }
	     else
	     {
	      w.drawText(cx/2-40,cy/2-280,
		"joueur 2 vous avez gagne !");
	      joueur1=false;
	      victoire=true;
	      int nombreR=0;
	     cout<<"cliquez sur 1 pour recommencer ?";
	     cin>>nombreR;
	     if (nombreR==1)
	     {
	      dessiner(w);
	     }
	     }
	    }
	    //detection de la couleur dimgray des 2 chateaux
	    if(((w.getPointColor(cx-(int)sqrt(xt*xt)+3,
		(int)-yt+cy+3)))==0xff696969)
	    {
	     w.setColor("yellow");
	     for(int wi4=1;wi4<=20;wi4++)
	     {
	      w.fillCircle(cx-(int)sqrt(xt*xt), (int)-yt+cy, wi4);
	      w.msleep(100);
	     }
             w.setColor("dodgerblue");
	     w.fillCircle(cx-(int)sqrt(xt*xt), (int)-yt+cy, 20);
	     yt=0;
	     if(cx-(int)sqrt(xt*xt)>cx/2)
	     {
	      w.setColor("black");
	      w.drawText(cx/2-40,cy/2-280,"Suicide !");
	      joueur1=false;
	      victoire=true;
	       int nombreR=0;
	      cout<<"cliquez sur 1 pour recommencer ?";
	      cin>>nombreR;
	      if (nombreR==1)
	      {
	      	dessiner(w);
	      }
	     }
	     else
	     {
	      w.setColor("black");
	      w.drawText(cx/2-40,cy/2-280,
		"joueur 2 vous avez gagne !");
	      victoire=true;
	         int nombreR=0;
	     cout<<"cliquez sur 1 pour recommencer ?";
	     cin>>nombreR;
	     if (nombreR==1)
	     {
	      dessiner(w);
	     }
	      }
	     }
	    }
           }

     //le tour de role
	   if (joueur1==true)
	   {
	    joueur1=false;
	   }
	   else
	   {
	    joueur1=true;
	   }
	  }
}

int main(int argc, char *argv[])
{
	QApplication application (argc, argv);
	DrawingWindow ismail(dessiner, 800, 680);
	srand(time(NULL));
	ismail.setWindowTitle("jeu ");
	ismail.show();
	return application.exec();
}