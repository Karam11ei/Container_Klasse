#include "CKapatzitšt.h"

int CKapatzitšt::anzahl = 0;

CKapatzitšt::CKapatzitšt() :C(0)
{
	anzahl++;
	name = "C";
	string temp = to_string(anzahl);
	name += temp;
}

CKapatzitšt::~CKapatzitšt()
{
}

CKapatzitšt::CKapatzitšt(double _C,double _Preis, double _x, double _y)
	: C(_C),
	CBauelement( _Preis, _x, _y)
{
	anzahl++;
	name = "C";
	string temp = to_string(anzahl);
	name += temp;
}


void CKapatzitšt::Ausgabe() const
{
	std::cout << "C = " << this->C << std::endl;
	std::cout << "Name:" << this->getName() << std::endl;
	std::cout << "Kosten: " << this->getKosten() << "$$$" << std::endl;
	std::cout << "Position ( " << this->getPosition_x() << "," << this->getPosition_y() << " )\n" << std::endl;
}

void CKapatzitšt::Eingabe(double _C,  double _Preis, double _x, double _y)
{
	this->C = _C;
	this->setKosten(_Preis);
	this->setPosition_x(_x);
	this->setPosition_y(_y);

}

///////// Aus Die abstrakte Klasse
CKomplex CKapatzitšt::getKomplexeImpedanz(double _f) const
{
	CKomplex temp;
	temp.setRe(0);
	temp.setIm(-1 / ((2 * 3.141 * _f) * this->C));
	return temp;
}


double CKapatzitšt::getImpedanzBetrag(double _f) const
{
	double temp;

	temp = (1 / ((2 * 3.141 * _f) * this->C)) * (1 / ((2 * 3.141 * _f) * this->C));
	temp = sqrt(temp);
	return temp;
}

double CKapatzitšt::getRealteil() const
{
	return 0;
}

double CKapatzitšt::getImaginaerteil(double _f) const
{
	return  (-1 / ((2 * 3.141 * _f) * this->C));
}

double CKapatzitšt::getPhasenwinkel() const
{
	//Difintion
	return -90;
}


/*
std::string CKapatzitšt::getName() const
{
	return this->name;
}

double CKapatzitšt::getKosten() const
{
	return this->kosten;
}

double CKapatzitšt::getPosition_x() const
{
	return this->position.getPunkt_x();
}

double CKapatzitšt::getPosition_y() const
{
	return this->position.getPunkt_y();
}

CBauelement* CKapatzitšt::getNext()
{
	return this->next;
}


void CKapatzitšt::setname(std::string _name)
{
	this->name = _name;
}

void CKapatzitšt::setKosten(double _Preis)
{
	this->kosten = _Preis;
}

void CKapatzitšt::setPosition_x(double _x)
{
	this->position.setPunkt_x(_x);
}

void CKapatzitšt::setPosition_y(double _y)
{
	this->position.setPunkt_y(_y);
}

void CKapatzitšt::setNext(CBauelement& nextObjekt)
{
	this->next = &nextObjekt;
}
*/
