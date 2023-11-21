#include "CKapatzität.h"

int CKapatzität::anzahl = 0;

CKapatzität::CKapatzität() :C(0)
{
	anzahl++;
	name = "C";
	string temp = to_string(anzahl);
	name += temp;
}

CKapatzität::~CKapatzität()
{
}

CKapatzität::CKapatzität(double _C,double _Preis, double _x, double _y)
	: C(_C),
	CBauelement( _Preis, _x, _y)
{
	anzahl++;
	name = "C";
	string temp = to_string(anzahl);
	name += temp;
}


void CKapatzität::Ausgabe() const
{
	std::cout << "C = " << this->C << std::endl;
	std::cout << "Name:" << this->getName() << std::endl;
	std::cout << "Kosten: " << this->getKosten() << "$$$" << std::endl;
	std::cout << "Position ( " << this->getPosition_x() << "," << this->getPosition_y() << " )\n" << std::endl;
}

void CKapatzität::Eingabe(double _C,  double _Preis, double _x, double _y)
{
	this->C = _C;
	this->setKosten(_Preis);
	this->setPosition_x(_x);
	this->setPosition_y(_y);

}

///////// Aus Die abstrakte Klasse
CKomplex CKapatzität::getKomplexeImpedanz(double _f) const
{
	CKomplex temp;
	temp.setRe(0);
	temp.setIm(-1 / ((2 * 3.141 * _f) * this->C));
	return temp;
}


double CKapatzität::getImpedanzBetrag(double _f) const
{
	double temp;

	temp = (1 / ((2 * 3.141 * _f) * this->C)) * (1 / ((2 * 3.141 * _f) * this->C));
	temp = sqrt(temp);
	return temp;
}

double CKapatzität::getRealteil() const
{
	return 0;
}

double CKapatzität::getImaginaerteil(double _f) const
{
	return  (-1 / ((2 * 3.141 * _f) * this->C));
}

double CKapatzität::getPhasenwinkel() const
{
	//Difintion
	return -90;
}


/*
std::string CKapatzität::getName() const
{
	return this->name;
}

double CKapatzität::getKosten() const
{
	return this->kosten;
}

double CKapatzität::getPosition_x() const
{
	return this->position.getPunkt_x();
}

double CKapatzität::getPosition_y() const
{
	return this->position.getPunkt_y();
}

CBauelement* CKapatzität::getNext()
{
	return this->next;
}


void CKapatzität::setname(std::string _name)
{
	this->name = _name;
}

void CKapatzität::setKosten(double _Preis)
{
	this->kosten = _Preis;
}

void CKapatzität::setPosition_x(double _x)
{
	this->position.setPunkt_x(_x);
}

void CKapatzität::setPosition_y(double _y)
{
	this->position.setPunkt_y(_y);
}

void CKapatzität::setNext(CBauelement& nextObjekt)
{
	this->next = &nextObjekt;
}
*/
