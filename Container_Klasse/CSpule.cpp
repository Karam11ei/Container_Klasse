#include "CSpule.h"
#include "BibKarkajieh.h"

int CSpule::anzahl = 0;

CSpule::CSpule()
	: l(0)
	//	, StuckAnzahl(1)
{
	//	static unsigned int StuckAnzahl = 1;
	//	StuckAnzahl++;
	anzahl++;
	name = "L";
	string temp = to_string(anzahl);
	name += temp;
}

CSpule::~CSpule() { }

CSpule::CSpule(double _l, double _Preis, double _x, double _y)
	: l(_l)
	, CBauelement( _Preis, _x, _y)
{
	anzahl++;
	name = "L";
	string temp = to_string(anzahl);
	name += temp;
//	this->setName("L" + (char)anzahl);
}

void CSpule::Ausgabe() const
{
	std::cout << "L =" << this->l << std::endl;
	CBauelement::Ausgabe();
	//std::cout << "Name:" << this->getName() << std::endl;
	//std::cout << "Kosten: " << this->getKosten() << "$$$" << std::endl;
	//std::cout << "Position ( " << this->getPosition_x() << "," << this->getPosition_y() << " )\n" << std::endl;
}

void CSpule::Eingabe(double _wert, double _Preis, double _x, double _y)
{
	this->l = _wert;
	// barcht kein Eingaben & Ausgabe mehr für bauelement sonderen wird hier direk gemacht
	CBauelement::Eingabe( _Preis, _x, _y);
}

//abstrakte Klasse
CKomplex CSpule::getKomplexeImpedanz(double _f) const
{
	CKomplex temp;
	temp.setRe(0);
	temp.setIm((2 * 3.141 * _f) * this->l);
	return temp;
}

double CSpule::getImpedanzBetrag(double _f) const
{
	double temp;
	temp = ((2 * 3.141 * _f) * this->l) * ((2 * 3.141 * _f) * this->l);
	temp = sqrt(temp);
	return temp;
}

double CSpule::getRealteil() const
{
	return 0;
}

double CSpule::getImaginaerteil(double _f) const
{
	return   ((2 * 3.141 * _f) * this->l);
}

double CSpule::getPhasenwinkel() const
{
	//Difintion
	return 90;
}



/*
std::string CSpule::getName() const 
{
	return this->name;
}

double CSpule::getKosten() const
{
	return this->kosten;
}

double CSpule::getPosition_x() const
{
	return this->position.getPunkt_x();
}

double CSpule::getPosition_y() const
{
	return this->position.getPunkt_y();
}

void CSpule::setName(string _name)
{
	this->name = _name;
}

void CSpule::setKosten(double _Preis)
{
	this->kosten = _Preis;
}

void CSpule::setPosition_x(double _x)
{
	this->position.setPunkt_x(_x);
}

void CSpule::setPosition_y(double _y)
{
	this->position.setPunkt_y(_y);
}

void CSpule::setNext(CBauelement& nextObjekt) 
{
	this->next = &nextObjekt;
}

CBauelement* CSpule::getNext() 
{
	return this->next;
}
*/

/*
double* CSpule::AddObject() {

	// Neue Opjekt erzeugen
	CSpule* newObject = new CSpule();
	// Alte start Adresse wird als Next gespeichert
	newObject->next = (CSpule*)this->getstart();
	// start zeigt auf die  Adresse der neue Opjekt
	CListe::setstart((double*)newObject);
	// Opjekt Adresse zuruckgeben
	return CListe::getstart();
}


double* CSpule::AddObject(double _r, std::string _name, double _Preis, double _x, double _y) {

	// Neue Opjekt erzeugen
	CSpule* newObject = new CSpule();
	// Alte start Adresse wird als Next gespeichert
	newObject->next = (CSpule*)this->getstart();
	newObject->Eingabe(_r, _name, _Preis, _x, _y);
	std::cout << "Adresse des alten Objekts: " << next << std::endl;
	// start zeigt auf die  Adresse der neue Opjekt
	CListe::setstart((double*)newObject);
	// Opjekt Adresse zuruckgeben
	return CListe::getstart();
}

void CWiderstand::deleteOldObject() {
	CWiderstand* currentObject = this; // CListe::geststart()
	while (currentObject != nullptr) {
		CWiderstand* nextObject = currentObject->next;
		delete currentObject;
		currentObject = nextObject;
	}
}
*/

/*
Spule & Spule::oprator=(Cspule x){
int i;
delet this->pt;


}




Spule :: Spule(Cspule x){
int i;
delet this->pt;
pt = new spule

*/