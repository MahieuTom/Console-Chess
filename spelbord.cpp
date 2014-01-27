#include "spelbord.h"


/*
 * Construeerd het spelbord.
 *
 * Author: Tom Mahieu
 */
Spelbord::Spelbord ()
{
	int x, y;
	// Eerst alles op 'NULL' zetten.
	for (y = 0; y < vakken; y++) {
		for (int x = 0; x < vakken; x++) {
			schaakstukken[y][x] = NULL;
		}
	}

	y = Pion::startPositie(zwart);
	for (x = 0; x < vakken; x++) {
		schaakstukken[y][x] = new Pion (zwart);
	}
	y--;
	schaakstukken[y][0] = new Toren (zwart);
	schaakstukken[y][1] = new Paard (zwart);
	schaakstukken[y][2] = new Loper (zwart);
	schaakstukken[y][3] = new Koningin (zwart);
	schaakstukken[y][4] = new Koning (zwart);
	schaakstukken[y][5] = new Loper (zwart);
	schaakstukken[y][6] = new Paard (zwart);
	schaakstukken[y][7] = new Toren (zwart);

	y = Pion::startPositie(wit);
	for (x = 0; x < vakken; x++) {
		schaakstukken[y][x] = new Pion (wit);
	}
	y++;
	schaakstukken[y][0] = new Toren (wit);
	schaakstukken[y][1] = new Paard (wit);
	schaakstukken[y][2] = new Loper (wit);
	schaakstukken[y][3] = new Koningin (wit);
	schaakstukken[y][4] = new Koning (wit);
	schaakstukken[y][5] = new Loper (wit);
	schaakstukken[y][6] = new Paard (wit);
	schaakstukken[y][7] = new Toren (wit);
}

/*
 * Construeerd het spelbord via een bepaalde file.
 *
 * Author: Tom Mahieu
 *
 * Niet gebeurt de laatste aan zet moet wit zijn, geen tijd gehad voor dat te veranderen.
 */
Spelbord::Spelbord (char* bestand)
{
	char stuk[2];
	Kleur kleur;
	string ingelezen;
	ifstream lees (bestand);

	if (lees.is_open()) {
		for (unsigned int lijn = 0; !lees.eof(); lijn++) { // Zolang nog niet op het einde van de file
			getline(lees, ingelezen); // iedere 2 letters afgaan: KLEUR - TYPE vb. 'WK' || '--'
			std::cout << ingelezen << endl;

			for (unsigned int i=2; i < ingelezen.length(); i+=2) {
				stuk[i-1] = ingelezen[i-1];
				stuk[i] = ingelezen[i];

				if (stuk[i-1] == 'W')
					kleur = wit;
				else
					kleur = zwart;

				switch (stuk[i]) {
					case 'P':
						schaakstukken[lijn][i/2] = new Pion (kleur);
						break;
					case 'R':
						schaakstukken[lijn][i/2] = new Toren (kleur);
						break;
					case 'H':
						schaakstukken[lijn][i/2] = new Paard (kleur);
						break;
					case 'B':
						schaakstukken[lijn][i/2] = new Loper (kleur);
						break;
					case 'K':
						schaakstukken[lijn][i/2] = new Koning (kleur);
						break;
					case 'Q':
						schaakstukken[lijn][i/2] = new Koningin (kleur);
						break;
					case '-':
						schaakstukken[lijn][i/2] = NULL;
						break;
				}
			}
		}

		lees.close();
	}
	else
		std::cerr << "Kon bestand niet inlezen!"; 
}

/*
 * Destructor die de overgebleven stukken van het spelbord verwijderd.
 *
 * Author: Tom Mahieu
 */
Spelbord::~Spelbord ()
{
	opslaan("spel.txt");

	for (int x = 0; x < vakken; x++) {
		for (int y = 0; y < vakken; y++) {
			delete schaakstukken[y][x];
		}
	}

	delete &this->vakken;
}

/*
 * Een bestand opslaan als het wordt afgesloten.
 *
 * Author: Tom Mahieu
 */
void Spelbord::opslaan (char* bestand)
{
	Schaakstuk* stuk;
	string ingelezen;
	ofstream opslaan (bestand);

	if (opslaan.is_open()) {
		for (int y = 0; y < vakken; y++) {
			for (int x = 0; x < vakken; x++) {
				stuk = schaakstukken[y][x];

				if (stuk != NULL) { 
					if (stuk->geefKleur() == wit)
						opslaan << 'W';
					else
						opslaan << 'Z';
					opslaan << stuk->geefSymbool();
				}
				else
					opslaan << "--";
			}
			opslaan << '\n';
		}
		//opslaan << spel.geefBeurt() << '\n';
		opslaan.close();
	}
	else
		std::cerr << "Kon bestand niet opslaan!"; 
}

/*
 * Print het speelbord af.
 * 
 * Author: Tom Mahieu
 */
void Spelbord::printVeld ()
{
	int tegels = 0;
	Schaakstuk* schaakstuk;

	for (int y = 0; y < vakken; y++) {
		cout << y << "  "; // Y-coord links plaatsen.

		for (int x = 0; x < vakken; x++) {
			if ((schaakstuk = Spelbord::schaakstukken[y][x]) != NULL) {
				// Vakjes kleuren.
				Spelbord::vakKleuren(schaakstuk, tegels);
				// Schaakstuk erop plaatsten
				cout << schaakstuk->geefSymbool() << " ";
			} else {
				Spelbord::vakKleuren(NULL, tegels);
				cout << "  ";
			}

			tegels++;
		}

		// Kleuren omwisselen
		if (tegels == vakken)
			tegels = 1; // Met even (zwart) beginnen.
		else
			tegels = 0; // Met oneven (wit) beginnen.

		cout << "\n";
		SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 ); // Standaard console kleuren terugzetten.
	}

	// X-coord onder schrijven.
	cout << "\n   ";
	for (int x = 0; x < vakken; x++) {
		cout << x << " ";
	}
}

/*
 * De vakken op het spelbord een kleur geven.
 * 
 * Author: Tom Mahieu
 */
void Spelbord::vakKleuren (Schaakstuk* stuk, int tegels)
{
	// Ieder volgend getal anders kleuren
	if (tegels % 2 == 0) {
		if (stuk == NULL)
			SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x77 );// Grijs.
		else {
			switch (stuk->geefKleur())
			{
			case wit:
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x7F );// Grijs, Wit.
				break;
			case zwart:
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x70 );// Grijs, Zwart.
				break;
			}
		}
	} else {
		if (stuk == NULL)
			SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x66 );// Kaki.
		else {
			switch (stuk->geefKleur())
			{
			case wit:
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x6F );// Kaki, Wit.
				break;
			case zwart:
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x60 );// Kaki, Zwart.
				break;
			}
		}
	}
}

/*
 * Controleer of de zet geldig is.
 * Return 'false' als de selectie niet kan gemaakt worden of dat het niet kan geplaatst worden.
 *
 * Author: Tom Mahieu
 *
 * xS = x-coordinaat geselecteerde schaakstuk
 * yS = y-coordinaat geselecteerde schaakstuk
 * xP = x-coordinaat nieuwe plaats schaakstuk
 * yP = y-coordinaat nieuwe plaats schaakstuk
 */
bool Spelbord::controle (int xS, int yS, int xP, int yP, Kleur beurt)
{
	// Controleren of de coordinaten zich op het veld bevinden. En niet 2 keer dezelfde cooordinaat
	// Controleer of de kleur dezelfde is. Dan dat het schaakstuk waarop het geplaatst wordt niet dezelfde kleur heeft.
	if ( Spelbord::inVeld(xS, yS) && Spelbord::inVeld(xP, yP) &&
		 schaakstukken[yS][xS] != NULL && schaakstukken[yS][xS]->geefKleur() == beurt &&
		 (schaakstukken[yP][xP] == NULL || schaakstukken[yP][xP]->geefKleur() != beurt) && !(xS == xP && yS == yP))
	{
		if ( schaakstukken[yS][xS]->geldigeBeweging(xS, yS, xP, yP) )
			return true;
		else {
			cerr << "Het schaakstuk kan niet naar de nieuwe locatie worden verplaatst!" << endl;
			return false;
		}
	}
	else
	{
		cerr << "De gemaakte selectie is ongeldig!" << endl;
		return false;
	}
}

/*
 * Controleer of de cooordinaten zich binnen het speelveld bevinden.
 * Return 'false' als de selectie niet b.
 *
 * Author: Tom Mahieu
 *
 * x = x-coordinaat
 * y = y-coordinaat
 */
bool Spelbord::inVeld(int x, int y)
{
	return x >=0 && y >= 0 && x < vakken && y < vakken;
}

/*
 * Vindt een schaakstuk op het veld.
 * Return 'true' als er 1 gevonden is.
 *
 * Author: Tom Mahieu
 *
 * x = x-coordinaat
 * y = y-coordinaat
 */
bool Spelbord::vindtStuk (int x, int y)
{
	return schaakstukken[y][x] != NULL;
}

/*
 * Schaakstuk verplaatsten op het veld.
 *
 * Author: Tom Mahieu
 *
 * xS = x-coordinaat van geselecteerde pion
 * yS = y-coordinaat van geselecteerde pion
 * xP = x-coordinaat van nieuwe positie
 * yP = y-coordinaat van nieuwe positie
 */
void Spelbord::schaakstukVerplaatsen (int xS, int yS, int xP, int yP)
{
	if (Spelbord::vindtStuk(xP, yP)) // Als stuk geslagen wordt, het stuk verwijderen.
		delete schaakstukken[yP][xP];
	schaakstukken[yP][xP] = schaakstukken[yS][xS];
	Spelbord::schaakstukVerwijderen(xS, yS); // Oude plaats verwijderen.
}

/*
 * Schaakstuk verwijderen van het veld.
 *
 * Author: Tom Mahieu
 *
 * x = x-coordinaat
 * y = y-coordinaat
 */
void Spelbord::schaakstukVerwijderen (int x, int y)
{
	schaakstukken[y][x] = NULL;
}

/*
 * Geef een copy van het aantal vakken van een speelveld.
 *
 * Author: Tom Mahieu
 */
int Spelbord::aantalVakken ()
{
	return vakken;
}