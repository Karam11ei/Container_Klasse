#include "CWiderstand.h"

int CWiderstand::anzahl = 0;

CWiderstand::CWiderstand()
	: r(0)
{
	anzahl++;
	name = "R";
	string temp = to_string(anzahl);
	name += temp;
}

CWiderstand::~CWiderstand() {

}

CWiderstand::CWiderstand(double _wertR,  double _Preis, double _x, double _y)
	:r(_wertR)
	,CBauelement( _Preis, _x, _y)
{
	anzahl++;
	name = "R";
	string temp = to_string(anzahl);
	name += temp;
}

// Implementieren 
void CWiderstand::Ausgabe() const
{
	std::cout << "R=  " << this->r << std::endl;
	CBauelement::Ausgabe();
	//std::cout << "Name:" << this->getName() << std::endl;
	//std::cout << "Kosten: " << this->getKosten() << "$$$" << std::endl;
	//std::cout << "Position ( " << this->getPosition_x() << "," << this->getPosition_y() << " )\n" << std::endl;
}

void  CWiderstand::Eingabe(double _wertR, double _Preis, double _x, double _y)
{
	this->r = _wertR;
	CBauelement::Eingabe( _Preis, _x, _y);

}

///////// Aus Die abstrakte Klasse
CKomplex CWiderstand::getKomplexeImpedanz(double _f) const
{
	CKomplex temp;
	temp.setRe(r);
	temp.setIm(0);
	return temp;
}

double CWiderstand::getImpedanzBetrag(double _f) const
{
	return CWiderstand::getRealteil();
}

double CWiderstand::getRealteil() const
{
	return this->r;
}

double CWiderstand::getImaginaerteil(double _f) const
{
	return 0;
}

double CWiderstand::getPhasenwinkel() const
{
	//Defintion
	return 0;
}


/*abstrakte Klasse muss mindestens eine reine virtuelle Funktion deklarieren.
Eine reine virtuelle Funktion ist eine virtuelle Funktion, die mit der
Syntax des reinen Bezeichners (= 0) deklariert wird. Klassen, die von der
abstrakten Klasse abgeleitet sind, müssen die rein virtuelle Funktion
implementieren, um nicht selbst als abstrakte Klasse angesehen zu werden*/

/*
std::string CWiderstand::getName() const
{
	return this->name;
}

double CWiderstand::getKosten() const
{
	return this->kosten;
}

double CWiderstand::getPosition_x() const
{
	return this->position.getPunkt_x();
}

double CWiderstand::getPosition_y() const
{
	return this->position.getPunkt_y();
}

CBauelement* CWiderstand::getNext()
{
	return this->next;
}

void CWiderstand::setName(std::string _name)
{
	this->name = _name;
}

void CWiderstand::setKosten(double _Preis)
{
	this->kosten = _Preis;
}

void CWiderstand::setPosition_x(double _x)
{
	this->position.setPunkt_x(_x);
}

void CWiderstand::setPosition_y(double _y)
{
	this->position.setPunkt_y(_y);
}

void CWiderstand::setNext(CBauelement& nextObjekt)
{
	this->next = &nextObjekt;
}

*/




/*
Cbauelement* CWiderstand::AddObject() {

	// Neue Opjekt erzeugen
	CWiderstand* newObject = new CWiderstand();
	// Alte start Adresse wird als Next gespeichert
	newObject->setnext(getstart());

	// start zeigt auf die  Adresse der neue Opjekt
	CListe::setstart((double*)newObject);
	// Opjekt Adresse zuruckgeben
	return getstart();
}

CWiderstand* CListe::AddObject(double _r, std::string _name, double _Preis, double _x, double _y) {

	// Neue Opjekt erzeugen
	CWiderstand* newObject = new CWiderstand();
	// Alte start Adresse wird als Next gespeichert
	newObject->setnext(getstart());
	newObject->Eingabe(_r, _name, _Preis, _x, _y);
	std::cout << "Adresse des alten Objekts: " <<  << std::endl;
	// start zeigt auf die  Adresse der neue Opjekt
	CListe::setstart((double*)newObject);
	// Opjekt Adresse zuruckgeben
	return CListe::getstart();
}

void CListe::deleteOldObject() {
	CListe* currentObject = this; // CListe::geststart()
	while (currentObject != nullptr) {
		CListe* nextObject = currentObject->next;
		delete currentObject;
		currentObject = nextObject;
	}
}
*/