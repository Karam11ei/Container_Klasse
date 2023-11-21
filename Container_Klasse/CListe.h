#pragma once
#include"CWiderstand.h"
#include"CSpule.h"
#include"CKapatzität.h"
#include "BibKarkajieh.h"

//template <typename T>
//bool (*funcptr)(T gesucht, CBauelement* index);


class CListe {
private:
	CBauelement* start = NULL;
	//
	
protected:

	
public:
//	CListe();
	~CListe();

	CBauelement* getStart() const;
	CBauelement* getNext() const;
	void setStart(CBauelement& neue_element_Adresse);
	void setNext(CBauelement& temp);

	void AddObject(CBauelement& temp);
	void deleteallObject();
	CBauelement* DurchsuchenName(const string name_);
	template <typename T>
	CBauelement* Durchsuchen( T gesucht, bool (*funcptr)(T gesucht, CBauelement* index));
	void ImbedanuAnzeigenNachName(const string name_, double f) ;
//	CBauelement* deleteAObject();
	void deleteObjectName(string name_);
	void PrintAllElement();

	CKomplex GesamtImbedanzReihe(double f);

	//CKomplex ParallelSchaltung() const ;
	//CKomplex ReihenSchaltung() const ;
};

template <typename T>
CBauelement* CListe::Durchsuchen( T Gesuchte, bool (*funcptr) (T gesucht, CBauelement* index))
{
	CBauelement* index = this->getStart();
	do
	{
		bool Gefunden = funcptr(Gesuchte, index);
		if (Gefunden) {
			return index;
		}
		index = index->getNext();
	} while (index != NULL);
	return 0;
}