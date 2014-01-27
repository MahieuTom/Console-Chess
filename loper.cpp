#include "loper.h"


/*
 * Functie die test of de beweging geldig is.
 * 'true' wanneer de doorgang niet geblokeerd is door een schaakstuk en schuin bewogen.
 *
 * Author: Tom Mahieu
 */
bool Loper::geldigeBeweging (int xS, int yS, int xP, int yP)
{
	if ((xP - xS == yP - yS) || (xP - xS == yS - yP)) {
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
	} else {
		return false;
	}

	return true;
}