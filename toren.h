/*
 * File:   toren.h
 * Author: Tom Mahieu
 *
 * Created on May 11, 2013, 12:54 PM
 */
#ifndef TOREN_H
#define	TOREN_H

#include "schaakstuk.h"
#include "spel.h"


/*
 * Class die de type informatie en kleur van een toren bevat.
 *
 * Author: Tom Mahieu
 */
class Toren : public Schaakstuk
{
public:
	Toren(Kleur kleur) : Schaakstuk(kleur, 'R'){};
	bool geldigeBeweging(int xS, int yS, int xP, int yP);
};


#endif /*TOREN_H*/