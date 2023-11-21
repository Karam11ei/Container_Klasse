#include "CListe.h"



CListe::~CListe() {
	cout << "Liste wird zestört " << endl;

	CListe::deleteallObject();
}

CBauelement* CListe::getStart() const {
	return start;


}

CBauelement* CListe::getNext() const {
	return start->getNext();
}

void CListe::setStart(CBauelement & neue_element_Adresse) {
	this->start = &neue_element_Adresse;

}

void CListe::setNext(CBauelement & temp) {
		start->setNext(temp);
}

void CListe::AddObject(CBauelement & temp) {
	// Alte start Adresse wird als Next gespeichert
	if (start)
	{
			temp.setNext(*start);
			std::cout << "Adresse des alten Objekts:  " << temp.getNext() << std::endl;
	}
	
	// start zeigt auf die  Adresse der neue Opjekt
	this->setStart(temp);
	// Opjekt Adresse zuruckgeben
	std::cout << "Adresse des Neuen Objekts:  " << this->getStart() << "\n*********************************\n\n" << std::endl;
}

void CListe::deleteallObject() {
	CBauelement* currentObject = this->getStart(); // CListe::geststart()
		while (currentObject != nullptr) {
			cout << "Opjekt wird zestört " << currentObject->getName() << endl;
			CBauelement* nextObject = currentObject->getNext();
			delete currentObject;
			currentObject = nextObject;
		}
}


//
//template <typename T>
//CBauelement* CListe::Durchsuchen(const T Gesuchte, bool (*funcptr) (T gesucht, CBauelement* index))
//{
//	CBauelement* index = this->getStart();
//	do
//	{
//		bool Gefunden = funcptr(Gesuchte, index );
//		if (Gefunden) {
//			return index;
//		}
//		index = index->getNext();
//	} while (index != NULL);
//	return 0;
//}




CBauelement* CListe::DurchsuchenName(const string name_)
{
	CBauelement* index = this->getStart();
	do
	{
	
		if (index->getName() == name_) {
			return index;
		}
		index = index->getNext();
	} while (index != NULL);
	return 0;
}


void CListe::ImbedanuAnzeigenNachName(const string name_, double f)
{

	CBauelement* DerGesuchteObjekt = DurchsuchenName(name_);
	if (DerGesuchteObjekt != 0) {
		cout << "Der wert " << DerGesuchteObjekt->getRealteil() << "+ j" << DerGesuchteObjekt->getImaginaerteil(f) << endl;
	}
	
}


// Druchsuchen Templet 
/*
template <typename T>
CBauelement* CListe::Durchsuchen(const T name_, bool(*funcptr)(const T name_, CBauelement* index) )
{
	CBauelement* index = this->getStart();
	do
	{
		bool temp = funcptr(name_, index);
		if (temp) {
			return index;
		}
		index = index->getNext();
	    } while (index != NULL);
		return 0;
}
*/

void CListe::deleteObjectName(string name_)
{
	bool nichtGefunden = true;
	CBauelement* toDelet = nullptr;
	CBauelement* beforObjekt = nullptr;
	CBauelement* index = nullptr;

	//Suchen 
	for (index = this->getStart(); index != nullptr; index->getNext()) {

		if (index->getName() == name_) {
			// wenn das Objekt gefunden wurde der zu löschen ist
			toDelet = index;
			nichtGefunden = false;
		}
		// ADresse von VorObjekt zwischen zu speichern
		if (nichtGefunden) {
			beforObjekt = index;
		}
		//zeiger anpassen 
		CBauelement* nechstObjekt = toDelet->getNext();
		beforObjekt->setNext(*nechstObjekt);
		// der gewuschte Objekt löschen in Heep 
		delete index;
	}
}

void CListe::PrintAllElement()
{
	CBauelement* index;
	index = this->getStart();
	do {
		cout << index->getName() << ": Preis:" << index->getKosten() << "€  Position: (" << index->getPosition_x() << ", " << index->getPosition_y() << ")" << endl;
		index = index->getNext();
	} while (index != NULL);
}

CKomplex CListe::GesamtImbedanzReihe(double f)
{
	CBauelement* BauelementTemp = this->getStart();
	CKomplex Summe(0,0);
	while (BauelementTemp != NULL)
	{
		CKomplex temp2(BauelementTemp->getRealteil(), BauelementTemp->getImaginaerteil(f));
		Summe = Summe + temp2; // Überladte Oprator

		BauelementTemp = BauelementTemp->getNext();
	}
	return Summe;
}


//CKomplex CListe::ParallelSchaltung() const 
//{
//
//}
//CKomplex CListe::ReihenSchaltung() const {
//
//}