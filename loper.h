/*
 * File:   loper.h
 * Author: Tom Mahieu
 *
 * Created on May 11, 2013, 13:05 PM
 */
#ifndef LOPER_H
#define	LOPER_H

#include "schaakstuk.h"
#include "spel.h"


/*
 * Class die de type informatie en kleur van een toren bevat.
 *
 * Author: Tom Mahieu
 */
class Loper : public Schaakstuk
{
public:
	Loper(Kleur kleur) : Schaakstuk(kleur, 'B'){};
	bool geldigeBeweging(int xS, int yS, int xP, int yP);
};

/*
	// TODO: Check of destinatie klopt

	// Controleer of geen schaakstuk in de weg staat naar destinatie
	for (checkX = xS, checkY = yS; checkX !=  xP && checkY != yP; checkX++, checkY++) {
		if (spel.spelbord.vindtStuk(checkX, checkY))
			return false;
	}
	for (checkX = xS, checkY = yS; checkX !=  xP && checkY != yP; checkX--, checkY++) {
		if (spel.spelbord.vindtStuk(checkX, checkY))
			return false;
	}
	for (checkX = xS, checkY = yS; checkX !=  xP && checkY != yP; checkX++, checkY--) {
		if (spel.spelbord.vindtStuk(checkX, checkY))
			return false;
	}
	for (checkX = xS, checkY = yS; checkX !=  xP && checkY != yP; checkX--, checkY--) {
		if (spel.spelbord.vindtStuk(checkX, checkY))
			return false;
	}
*/

#endif /*LOPER_H*/