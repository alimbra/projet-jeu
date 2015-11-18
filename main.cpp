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
}