/*
 * File:   spelbord.h
 * Author: Tom Mahieu
 *
 * Created on April 11, 2013, 10:47 AM
 */
#ifndef SPELBORD_H
#define	SPELBORD_H

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "pion.h"
#include "toren.h"
#include "paard.h"
#include "loper.h"
#include "koning.h"
#include "koningin.h"


/*
 * Class die telkens het huidige speelveld bijhoud.
 *
 * Author: Tom Mahieu
 */
class Spelbord
{
private:
	static const int vakken = 8;
	Schaakstuk* schaakstukken[vakken][vakken];
	void vakKleuren(Schaakstuk* stuk, int tegels);
	void schaakstukVerwijderen(int x, int y);
	bool inVeld(int x, int y);
public:
	Spelbord();
	Spelbord(char* bestand);
	~Spelbord();
	void opslaan(char* bestand);
	void printVeld();
	int aantalVakken();
	bool vindtStuk(int x, int y);
	bool controle(int xS, int yS, int xP, int yP, Kleur beurt);
	void schaakstukVerplaatsen(int xS, int yS, int xP, int yP);
};

#endif /*SPELBORD_H*/