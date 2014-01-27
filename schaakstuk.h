/*
 * File:   schaakstuk.h
 * Author: Tom Mahieu
 *
 * Created on May 10, 2013, 14:22 AM
 */
#ifndef SCHAAKSTUK_H
#define	SCHAAKSTUK_H


// Een constante definiëren voor de 2 kleuren in het spel.
static const enum Kleur { wit, zwart };

/*
 * Class die de kleur van een schaakstuk bevat.
 *
 * Author: Tom Mahieu
 */
class Schaakstuk			
{
private:
	char symbool;
protected:
	Kleur wOFz;
public:
	Schaakstuk(Kleur kleur, char symbool) : wOFz(kleur), symbool(symbool){};
	char geefSymbool();
	Kleur geefKleur();
	virtual bool geldigeBeweging(int xS, int yS, int xP, int yP);
};


#endif /*SCHAAKSTUK_H*/