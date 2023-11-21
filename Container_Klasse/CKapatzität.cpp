#include "CKapatzit�t.h"

int CKapatzit�t::anzahl = 0;

CKapatzit�t::CKapatzit�t() :C(0)
{
	anzahl++;
	name = "C";
	string temp = to_string(anzahl);
	name += temp;
}

CKapatzit�t::~CKapatzit�t()
{
}

CKapatzit�t::CKapatzit�t(double _C,double _Preis, double _x, double _y)
	: C(_C),
	CBauelement( _Preis, _x, _y)
{
	anzahl++;
	name = "C";
	string temp = to_string(anzahl);
	name += temp;
}


void CKapatzit�t::Ausgabe() const
{
	std::cout << "C = " << this->C << std::endl;
	std::cout << "Name:" << this->getName() << std::endl;
	std::cout << "Kosten: " << this->getKosten() << "$$$" << std::endl;
	std::cout << "Position ( " << this->getPosition_x() << "," << this->getPosition_y() << " )\n" << std::endl;
}

void CKapatzit�t::Eingabe(double _C,  double _Preis, double _x, double _y)
{
	this->C = _C;
	this->setKosten(_Preis);
	this->setPosition_x(_x);
	this->setPosition_y(_y);

}

///////// Aus Die abstrakte Klasse
CKomplex CKapatzit�t::getKomplexeImpedanz(double _f) const
{
	CKomplex temp;
	temp.setRe(0);
	temp.setIm(-1 / ((2 * 3.141 * _f) * this->C));
	return temp;
}


double CKapatzit�t::getImpedanzBetrag(double _f) const
{
	double temp;

	temp = (1 / ((2 * 3.141 * _f) * this->C)) * (1 / ((2 * 3.141 * _f) * this->C));
	temp = sqrt(temp);
	return temp;
}

double CKapatzit�t::getRealteil() const
{
	return 0;
}

double CKapatzit�t::getImaginaerteil(double _f) const
{
	return  (-1 / ((2 * 3.141 * _f) * this->C));
}

double CKapatzit�t::getPhasenwinkel() const
{
	//Difintion
	return -90;
}


/*
std::string CKapatzit�t::getName() const
{
	return this->name;
}

double CKapatzit�t::getKosten() const
{
	return this->kosten;
}

double CKapatzit�t::getPosition_x() const
{
	return this->position.getPunkt_x();
}

double CKapatzit�t::getPosition_y() const
{
	return this->position.getPunkt_y();
}

CBauelement* CKapatzit�t::getNext()
{
	return this->next;
}


void CKapatzit�t::setname(std::string _name)
{
	this->name = _name;
}

void CKapatzit�t::setKosten(double _Preis)
{
	this->kosten = _Preis;
}

void CKapatzit�t::setPosition_x(double _x)
{
	this->position.setPunkt_x(_x);
}

void CKapatzit�t::setPosition_y(double _y)
{
	this->position.setPunkt_y(_y);
}

void CKapatzit�t::setNext(CBauelement& nextObjekt)
{
	this->next = &nextObjekt;
}
*/
