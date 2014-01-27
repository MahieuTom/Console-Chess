#include "spel.h"

Spelbord* Spel::spelbord = new Spelbord();

void main ()
{
	Spel spel;
	spel.uitvoeren();
	spel.~Spel();
}