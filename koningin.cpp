#include "koningin.h"

/*
 * Functie die test of de beweging geldig is.
 * 'true' wanneer de doorgang niet geblokeerd is door een schaakstuk.
 *
 * Author: Tom Mahieu
 */
bool Koningin::geldigeBeweging (int xS, int yS, int xP, int yP)
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
	} else if ((xP - xS == yP - yS) || (xP - xS == yS - yP)) { // Schuin bewogen
		int verplX, verplY;

		if (xP > xS)
			verplX = 1;
		else
			verplX = -1;
		if (yP > yS)
			verplY = 1;
		else
			verplY = -1;

		for (yS += verplY, xS += verplX; yS != yP; yS += verplY, xS += verplX) {
			if (Spel::spelbord->vindtStuk(xS, yS))
				return false;
		}
	} else { // Als verkeerd bewogen:
		return false;
	}

	return true;
}