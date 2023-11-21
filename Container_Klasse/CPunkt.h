#pragma once

// CLASS DIFIREREN
class CPunkt 
{
private:
    //Attribute
    double x, y;

public:
    CPunkt();                             // Konstruktor
    ~CPunkt();                            // dekonstruktor
    CPunkt(double _x, double _y);    
    CPunkt(const CPunkt& _A);             // Koppieren Konstuktor

    // Methode
    void setPosition(double _x, double _y);
    void setPunkt_x(double _x);
    void setPunkt_y(double _y);
    double getPunkt_x() const;
    double getPunkt_y() const;
    double Abstand(CPunkt& bezug) const;
};


