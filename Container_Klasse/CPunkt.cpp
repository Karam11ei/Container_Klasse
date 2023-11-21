#include"CPunkt.h"
#include "BibKarkajieh.h"


//IMPLEMENTIEREN
CPunkt::CPunkt()
{
	this->x = 0;
	this->y = 0;
}

CPunkt::~CPunkt()
{
}

CPunkt::CPunkt(double _x, double _y) :x(_x), y(_y) 
{
}

CPunkt::CPunkt(const CPunkt& _A)
{
	this->x = _A.getPunkt_x();
	this->y = _A.getPunkt_y();
}

void CPunkt::setPosition(double _x, double _y)
{
	this->x = _x;
	this->y = _y;
}

void CPunkt::setPunkt_x(double _x)
{
	this->x = _x;
}

void CPunkt::setPunkt_y(double _y)
{
	this->y = _y;
}

double CPunkt::getPunkt_x() const
{
	return this->x;
}

double CPunkt::getPunkt_y() const
{
	return this->y;
}


double CPunkt::Abstand(CPunkt& Beug) const 
{

	double temp = ((this->x - Beug.getPunkt_x()) * (this->x - Beug.getPunkt_x())) + ((this->y - Beug.getPunkt_y()) * (this->y - Beug.getPunkt_y()));
	temp = sqrt(temp);
	return temp;
}