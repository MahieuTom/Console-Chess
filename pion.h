/*
 * File:   pion.h
 * Author: Tom Mahieu
 *
 * Created on April 11, 2013, 10:47 AM
 */
#ifndef PION_H
#define	PION_H

#include "schaakstuk.h"
#include "spel.h"


/*
 * Class die de type informatie en kleur van een pion bevat.
 *
 * Author: Tom Mahieu
 */
class Pion : public Schaakstuk
{
private:
	static const int startPosZwart = 1;
	static const int startPosWit = 6;
public:
	Pion(Kleur kleur) : Schaakstuk(kleur, 'P'){};
	bool geldigeBeweging(int xS, int yS, int xP, int yP);
	static int startPositie(Kleur kleur);
};


#endif /*PION_H*/