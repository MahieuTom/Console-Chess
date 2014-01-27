/*
 * File:   spel.h
 * Author: Tom Mahieu
 *
 * Created on April 11, 2013, 10:47 AM
 */
#ifndef SPEL_H
#define	SPEL_H

#include <windows.h>
#include <iostream>
using namespace std;
#include "spelbord.h"


class Spelbord;

/*
 * Class die het spelbord omvat en zegt wie aan de beurt is.
 *
 * Author: Tom Mahieu
 */
class Spel
{
private:
	Kleur beurt;
	bool winnaar;
	void invoer();
	void omBeurt();
public:
	Spel();
	Spel(char* bestand);
	~Spel();
	static Spelbord* spelbord; //TODO:!
	void uitvoeren();
	Kleur geefBeurt();
};

#endif /*SPEL_H*/