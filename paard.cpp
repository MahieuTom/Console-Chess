#include "paard.h"


/*
 * Functie die test of de beweging geldig is.
 * Return 'true' bij een geldige beweging.
 *
 * Author: Tom Mahieu
 */
bool Paard::geldigeBeweging (int xS, int yS, int xP, int yP)
{
	// Controleren of 1 van de geldige zetten is.
	if ((xP == xS + 2 || xP == xS - 2) && (yP == yS + 1 || yP == yS - 1))
		return true;
	if ((yP == yS + 2 || yP == yS - 2) && (xP == xS + 1 || xP == xS - 1))
		return true;
	else
		return false;
}