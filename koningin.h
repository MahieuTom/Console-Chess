/*
 * File:   koning.h
 * Author: Tom Mahieu
 *
 * Created on May 11, 2013, 13:15 PM
 */
#ifndef KONINGIN_H
#define	KONINGIN_H

#include "schaakstuk.h"
#include "spel.h"


/*
 * Class die de type informatie en kleur van een toren bevat.
 *
 * Author: Tom Mahieu
 */
class Koningin : public Schaakstuk
{
public:
	Koningin(Kleur kleur) : Schaakstuk(kleur, 'Q'){};
	bool geldigeBeweging(int xS, int yS, int xP, int yP);
};


#endif /*KONINGIN_H*/