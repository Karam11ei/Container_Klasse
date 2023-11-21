#pragma once
#include "Cbauelement.h"
#include "BibKarkajieh.h"

class CSpule : public CBauelement
{
private:
	double l;
	static int anzahl;
public:
	CSpule();
	~CSpule();
	CSpule(double _wertL, double _Preis, double _x, double _y);

	void Ausgabe() const;
	void Eingabe(double _wertL, double _Preis, double _x, double _y);
	/*
	std::string getName() const;
	double getKosten() const;
	double getPosition_x() const;
	double getPosition_y() const;
	CBauelement* getNext();

	void setName(string _name);
	void setKosten(double _Preis);
	void setPosition_x(double _x);
	void setPosition_y(double _y);
	void setNext(CBauelement& nextObjekt);
	*/

	//abstrakte Klasse
	CKomplex getKomplexeImpedanz(double _f) const;
	double getImpedanzBetrag(double _f) const;
	double getRealteil() const;
	double getImaginaerteil(double _f) const;
	double getPhasenwinkel() const;
};

