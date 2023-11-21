#pragma once
#include"CPunkt.h"
#include"CKomplex.h"
#include "BibKarkajieh.h"
//#include"CListe.h"
class CBauelement 
{
private:

protected:
    CPunkt position;
    std::string name;
    double kosten;
    CBauelement* next = nullptr;

    virtual void setName(string _name);

public:
    CBauelement();
    virtual ~CBauelement();
    CBauelement(double _Preis, double _x, double _y); // Parameterkonstruktor Cbauelement
    CBauelement(const CBauelement& _A);                             // Koppieren Konstuktor

    //Diklarerern
    virtual void Ausgabe() const;
    virtual void Eingabe(double _Preis, double _x, double _y);

    //Eigene Methoden  virtual 
    virtual std::string getName() const;
    virtual double getKosten() const;
    virtual double getPosition_x() const;
    virtual double getPosition_y() const;
    virtual CBauelement* getNext();


    virtual void setKosten(double _Preis);
    virtual void setPosition_x(double _x);
    virtual void setPosition_y(double _y);
    virtual void setNext(CBauelement& nextObjekt);


    
    //reine virtual 
    virtual CKomplex getKomplexeImpedanz(double _f) const = 0;
    virtual double getImpedanzBetrag(double _f) const = 0;
    virtual double getRealteil() const = 0;
    virtual double getImaginaerteil(double _f) const = 0;
    virtual double getPhasenwinkel() const = 0;





    //    virtual void setnext( Cbauelement& nextObjekt) =0;
    //   virtual Cbauelement *getnext() =0;
};
