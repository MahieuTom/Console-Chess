/*
 * File:   paard.h
 * Author: Tom Mahieu
 *
 * Created on May 11, 2013, 12:57 PM
 */
#ifndef PAARD_H
#define	PAARD_H

#include "schaakstuk.h"


/*
 * Class die de type informatie en kleur van een toren bevat.
 *
 * Author: Tom Mahieu
 */
class Paard : public Schaakstuk
{
public:
	Paard(Kleur kleur) : Schaakstuk(kleur, 'H'){};
	bool geldigeBeweging(int xS, int yS, int xP, int yP);
};


#endif /*PAARD_H*/