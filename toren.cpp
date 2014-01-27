#include "toren.h"


/*
 * Functie die test of de beweging geldig is.
 * 'true' wanneer de doorgang niet geblokeerd is door een schaakstuk en horizontaal of verticaal bewogen is.
 *
 * Author: Tom Mahieu
 */
bool Toren::geldigeBeweging (int xS, int yS, int xP, int yP)
{
	if (yS == yP) { // Verticaal bewogen
		int verplX;

		if (xP > xS)
			verplX = 1;
		else
			verplX = -1;

		for (xS += verplX; xS !=  xP; xS += verplX) {
			if (Spel::spelbord->vindtStuk(xS, yS))
				return false;
		}
	} else if (xP == xS) { // Horizontaal bewogen
		int verplY;

		if (yP > yS)
			verplY = 1;
		else
			verplY = -1;

		for (yS += verplY; yS !=  yP; yS += verplY) {
			if (Spel::spelbord->vindtStuk(xS, yS))
				return false;
		}
	} else { // Als geen van beide, is het fout.
		return false;
	}

	return true;
}