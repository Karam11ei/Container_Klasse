#pragma once

class CKomplex {
private:
	//Attribute Diklarien
	double re, im;

public:
	//Deklartion
	//Standardkonstruktor
	CKomplex();
	~CKomplex();
	CKomplex(double r, double i);		//Parameterkonstruktor
	CKomplex(const CKomplex& _A);		// Koppieren Konstuktor
	
	void AusgabeKarteisisch() const;
	void AusgabeEulische() const;


	CKomplex getKarteisisch() const;
	double getBertag() const;
	double getPhasen() const;

	double getRi() const;
	double getIm() const;

	void setIm(double _im);
	void setRe(double _re);



	//um die re_ssourcen fre_izugeben, wenn ein CKomplex-Objekt am Ende seines Lebenszyklus ist.
	//Operatorüberladungsfunktionen
	CKomplex operator*(const CKomplex& temp) const;
	CKomplex operator+(const CKomplex& temp) const;
	CKomplex operator-(const CKomplex& temp) const;
	CKomplex operator/(const CKomplex& temp) const;


};