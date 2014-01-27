#include "koning.h"


/*
 * Functie die test of de beweging geldig is.
 * Return 'true' bij een geldige beweging.
 *
 * Author: Tom Mahieu
 */
bool Koning::geldigeBeweging (int xS, int yS, int xP, int yP)
{
	return (xP >= xS-1 && xP <= xS+1 && yP >= yS-1 && yP <= yS+1);
}