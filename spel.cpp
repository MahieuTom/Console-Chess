#include "spel.h"

/*
 * Constructor om een spel op te starten.
 *
 * Author: Tom Mahieu
 */
Spel::Spel () : winnaar(false), beurt(wit){}

/*
 * Constructor om een spel op te starten met een file.
 *
 * Author: Tom Mahieu
 */
Spel::Spel (char* bestand) : winnaar(false), beurt(wit)
{
	Spel::spelbord = new Spelbord(bestand);
}

/*
 * Destructor om een spel te verwijderen.
 *
 * Author: Tom Mahieu
 *
 * TODO: foutje.
 */
Spel::~Spel ()
{
	delete spelbord;
}

/*
 * Schaakstuk verplaatsten op het veld.
 *
 * Author: Tom Mahieu
 */
void Spel::omBeurt ()
{
	if (Spel::beurt == wit) { // Wit aan zet geweest
		cout << "Zwart is aan zet.\n\n";
		beurt = zwart; // Dan zwart.
	} else {
		cout << "Wit is aan zet.\n\n";
		beurt = wit;
	}
}

/*
 * Deze functie start het spel en blijft het uitvoeren.
 * Vraagt naar input van de gebruiker.
 * 
 * Author: Tom Mahieu
 */
void Spel::uitvoeren ()
{
	int doeZet;
	// Laat het spel beginnen
	cout << "Wit mag beginnen.\n\n";
	do {
		Spel::spelbord->printVeld();
		do {
			cout << "\n\nWilt u zetten? [1=Ja/0=Nee]: ";
			cin >> doeZet;
		} while (doeZet > 2 && doeZet > -1);

		if (doeZet == 1) {
			Spel::invoer(); // Vraag naar invoer.
			Spel::omBeurt(); // Andere aan zet.
		}
		system("cls"); // Veld terug schoonmaken.
	} while (!Spel::winnaar && doeZet != 0); // Doorgaan tot er een winaar is. Of opslaan voor volgende keer

	Spel::~Spel();
}

/*
 * Vraag de gebruiker om invoer en roep dan functie op om te verplaatsen.
 * 
 * Author: Tom Mahieu
 */
void Spel::invoer()
{
	int xS, yS, xP, yP; // S = geselecteerd, P = nieuwe plaats.
	do {
		cout << "\n\nSelecteer een schaakstuk:\nx-as: ";
		cin >> xS;
		cout << "y-as: ";
		cin >> yS;

		cout << "\n\nPlaats het schaakstuk:\nx-as: ";
		cin >> xP;
		cout << "y-as: ";
		cin >> yP;
	} while ( !Spel::spelbord->controle(xS, yS, xP, yP, beurt) ); // Controle niet doorstaan == opnieuw.

	Spel::spelbord->schaakstukVerplaatsen(xS, yS, xP, yP);
}

/*
 * Geef de gene aan die aan zet is.
 *
 * Author: Tom Mahieu
 */
Kleur Spel::geefBeurt ()
{
	return beurt;
}