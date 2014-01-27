#include "schaakstuk.h"


/*
 * Functie die de de grafische representatie doorgeeft.
 *
 * Author: Tom Mahieu
 */
char Schaakstuk::geefSymbool ()
{
	return Schaakstuk::symbool; //TODO: ERR
}

/*
 * Functie die de kleur terug geeft van een Schaalstuk.
 *
 * Author: Tom Mahieu
 */
Kleur Schaakstuk::geefKleur ()
{
	return Schaakstuk::wOFz;
}

/*
 * Standard functie die enkel een foute beweging terug geeft.
 *
 * Author: Tom Mahieu
 */
bool Schaakstuk::geldigeBeweging (int xS, int yS, int xP, int yP)
{
	return false;
}