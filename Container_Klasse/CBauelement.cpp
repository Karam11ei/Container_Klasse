#include"CBauelement.h"

// Das Attribut anzahl initialisieren


CBauelement::CBauelement() : kosten(0)
{
	position.setPosition(0, 0);

}

CBauelement::~CBauelement()
{
}

CBauelement::CBauelement(const CBauelement& _A) :  kosten(_A.getKosten())
{
	this->position.setPosition(_A.position.getPunkt_x(), _A.position.getPunkt_y());
}

CBauelement::CBauelement( double _Preis, double _x, double _y) : kosten(_Preis)
{
	this->position.setPosition(_x, _y);
}

// Diklarerern
void CBauelement::Ausgabe() const
{
	std::cout << "Name:" << this->getName() << std::endl;
	std::cout << "Kosten: " << this->getKosten() << "$$$" << std::endl;
	std::cout << "Position ( " << this->getPosition_x() << "," << this->getPosition_y() << " )\n" << std::endl;
}

void CBauelement::Eingabe( double _Preis, double _x, double _y)
{

	this->setKosten(_Preis);
	this->setPosition_x(_x);
	this->setPosition_y(_y);
}


// Eigene Methoden
std::string CBauelement::getName() const
{
	return this->name;
}

double CBauelement::getKosten() const
{
	return this->kosten;
}

double CBauelement::getPosition_x() const
{
	return this->position.getPunkt_x();
}

double CBauelement::getPosition_y() const
{
	return this->position.getPunkt_y();
}

CBauelement* CBauelement::getNext()
{
	return this->next;
}

void CBauelement::setName(string _name)
{
	this->name = _name;
}

void CBauelement::setKosten(double _Preis)
{
	this->kosten = _Preis;
}

void CBauelement::setPosition_x(double _x)
{
	this->position.setPunkt_x(_x);
}

void CBauelement::setPosition_y(double _y)
{
	this->position.setPunkt_y(_y);
}

void CBauelement::setNext(CBauelement& nextObjekt)
{
	this->next = &nextObjekt;
}

// reine virtual 

/*
double* CListe::AddObject() {

	// Neue Opjekt erzeugen
	Cbauelement* newObject = new Cbauelement();
	// Alte start Adresse wird als Next gespeichert
	newObject->next = (Cbauelement*)this->getstart();
	// start zeigt auf die  Adresse der neue Opjekt
	CListe::setstart((double*)newObject);
	// Opjekt Adresse zuruckgeben
	return  (double*)newObject;
}


double* Cbauelement::AddObject( std::string _name, double _Preis, double _x, double _y) {

	// Neue Opjekt erzeugen
	Cbauelement* newObject = new Cbauelement();
	// Alte start Adresse wird als Next gespeichert
	newObject->next = (Cbauelement*)this->getstart();
	newObject->Eingabe( _name, _Preis, _x, _y);
	std::cout << "Adresse des alten Objekts: " << next << std::endl;
	// start zeigt auf die  Adresse der neue Opjekt
	CListe::setstart((double*)newObject);
	// Opjekt Adresse zuruckgeben
	return (double*)newObject;
}

void Cbauelement::deleteOldObject() {
	Cbauelement* currentObject = this; // CListe::geststart()
	while (currentObject != nullptr) {
		Cbauelement* nextObject = currentObject->next;
		delete currentObject;
		currentObject = nextObject;
	}
}
*/


