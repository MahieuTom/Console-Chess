/*
 * File:   koning.h
 * Author: Tom Mahieu
 *
 * Created on May 11, 2013, 13:15 PM
 */
#ifndef KONING_H
#define	KONING_H

#include "schaakstuk.h"


/*
 * Class die de type informatie en kleur van een toren bevat.
 *
 * Author: Tom Mahieu
 */
class Koning : public Schaakstuk
{
public:
	Koning(Kleur kleur) : Schaakstuk(kleur, 'K'){};
	bool geldigeBeweging(int xS, int yS, int xP, int yP);
};


#endif /*KONING_H*/