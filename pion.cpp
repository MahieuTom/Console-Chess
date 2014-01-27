#include "pion.h"


/*
 * Functie die test of de beweging geldig is.
 * Return 'true' bij een geldige beweging.
 *
 * Author: Tom Mahieu
 */
bool Pion::geldigeBeweging (int xS, int yS, int xP, int yP)
{
	if (Schaakstuk::wOFz == wit)
	{
		// Als naar voren verschoven, normaal 1, bij start 2.
		if (xP == xS && (yP == yS - 1 || (yS == startPosWit && yP == yS - 2)))
			return true;
		// Als 1 naar voren en opzij (enkel om een stuk te pakken)
		else if (xP == xS + 1 && yP == yS - 1 && Spel::spelbord->vindtStuk(xP,yP))
			return true;
		else if (xP == xS - 1 && yP == yS - 1 && Spel::spelbord->vindtStuk(xP,yP))
			return true;
		else
			return false;
	}
	else
	{
		// Als naar voren verschoven, normaal 1, bij start 2.
		if (xP == xS && (yP == yS + 1 || (yS == startPosZwart && yP == yS + 2)))
			return true;
		// Als 1 naar voren en opzij (enkel om een stuk te pakken)
		else if (xP == xS + 1 && yP == yS + 1 && Spel::spelbord->vindtStuk(xP,yP))
			return true;
		else if (xP == xS - 1 && yP == yS + 1 && Spel::spelbord->vindtStuk(xP,yP))
			return true;
		else
			return false;
	}
}

/*
 * Functie die de startpositie geeft voor een kleur.
 *
 * Author: Tom Mahieu
 */
int Pion::startPositie (Kleur kleur)
{
	if (kleur == wit)
		return startPosWit;
	else
		return startPosZwart;
}