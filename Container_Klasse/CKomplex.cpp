#include"CKomplex.h"
#include "BibKarkajieh.h"


CKomplex::CKomplex() : re(0), im(0) 
{
}
CKomplex::~CKomplex() 
{
}
CKomplex::CKomplex(double _re, double _im) : re(_re), im(_im)
{
    //  cout<<"Hallo"<<endl;
}
CKomplex::CKomplex(const CKomplex& _A)
{
    this->re = _A.re;
    this->im = _A.im;
}

void CKomplex::AusgabeKarteisisch() const
{
    std::cout << "der Karteisisch darstellung" << this->re << " + j" << this->im << std::endl;
}
void CKomplex::AusgabeEulische() const
{
    std::cout << "der Eulische darstellung" << this->getBertag() << ".e^" << this->getPhasen() << std::endl;
}


CKomplex CKomplex::getKarteisisch() const {
    CKomplex temp(re, im);
    return temp;
}

double CKomplex::getBertag() const
{
    double temp;

    temp = (this->re * this->re) + (this->im * this->im);
    temp = sqrt(temp);
    return temp;
}
double CKomplex::getPhasen() const
{
    double temp;
    temp = atan(this->im / this->re);
    temp = ((temp * 360) / (2 * PI));
    return temp;
}

double CKomplex::getRi() const
{
    return this->re;
}
double CKomplex::getIm() const
{
    return this->im;
}

void CKomplex::setIm(double _im)
{
    this->im = _im;
}
void CKomplex::setRe(double _re)
{
    this->re = _re;
}


//Operatorüberladungsfunktionen
// Operator overloaded using a member function
CKomplex CKomplex::operator+(const CKomplex& temp) const
{
    return CKomplex(re + temp.re, im + temp.im);
}

CKomplex CKomplex::operator*(const CKomplex& temp) const
{
    return CKomplex(re * temp.re - im * temp.im, re * temp.im + im * temp.re);
}

CKomplex CKomplex::operator-(const CKomplex& temp) const
{
    return CKomplex(re - temp.re, im - temp.im);
}

CKomplex CKomplex::operator/(const CKomplex& temp) const
{
    double denominator = temp.re * temp.re + temp.im * temp.im;
    return CKomplex((re * temp.re + im * temp.im) / denominator, (im * temp.re - re * temp.im) / denominator);
}
