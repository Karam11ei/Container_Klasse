#include"BibKarkajieh.h"
#include "CListe.h"

bool suchNachName( string name_,  CBauelement* index)
{
    if (index->getName() == name_) return true;
    return false;
}

bool suchNachPreis(double Preis_,CBauelement* index)
{
    if (index->getKosten() == Preis_)  return true;
    return false;
}

//bool (*funcptr)(const T M, CBauelement const& Opjekt);


/*In C++ gibt es verschiedene Öffnungsmodi, die beim Öffnen von Dateien verwendet werden können. Diese Modi geben an, wie die Datei geöffnet und wie mit ihr interagiert werden soll. Hier sind einige der häufigsten Öffnungsmodi:

1. **std::ios::in**: Öffnet die Datei zum Lesen.

2. **std::ios::out**: Öffnet die Datei zum Schreiben. Falls die Datei bereits existiert, werden die vorhandenen Daten gelöscht.

3. **std::ios::app**: Öffnet die Datei zum Schreiben im Appenden-Modus. Neue Daten werden am Ende der Datei hinzugefügt, ohne die vorhandenen Daten zu löschen.

4. **std::ios::ate**: Öffnet die Datei und setzt den Dateizeiger (Position in der Datei) ans Ende der Datei.

5. **std::ios::binary**: Öffnet die Datei im binären Modus statt im Textmodus. Dies ist wichtig, wenn du mit Binärdaten arbeitest.

Beim Öffnen von Dateien können diese Modi kombiniert werden. Zum Beispiel:

- **std::ios::in | std::ios::binary**: Öffnet die Datei im binären Lesemodus.
- **std::ios::out | std::ios::app**: Öffnet die Datei im Appenden-Modus zum Schreiben.

Im Beispiel habe ich `std::ios::app` verwendet, um die Datei im Appenden-Modus zu öffnen. Dadurch werden neue Daten am Ende der Datei hinzugefügt, ohne die vorhandenen Daten zu löschen.*/


int CSVDatei(const CListe& Liste1_){

    string pfad;
    cout << "Geben Sie den Pfad ein, an dem die Datei erstellt werden soll: ";
   // getline(cin, pfad);

    // Öffnen Sie die CSV-Datei zum Schreiben im Appenden-Modus
    std::ofstream csvFile("text.csv", std::ios::app);

    // Überprüfen, ob die Datei erfolgreich geöffnet wurde
    if (!csvFile.is_open()) {
        std::cerr << "Fehler beim Öffnen der Datei!" << std::endl;
        return 1; // Beenden Sie das Programm mit einem Fehlercode
    }

    // Überprüfen, ob die Datei leer ist
    if (csvFile.tellp() == 0) {
        // Datei ist leer, schreibe in die erste Zeile
        csvFile << "Bauteil ; Wert ; Kosten; X Position ; Y Position" << std::endl;
    }

    CBauelement* index = Liste1_.getStart();
    do
    {
      csvFile << index->getName() << ";" << index->getImpedanzBetrag(120)<< ";" << index->getKosten() << ";" << index->getPosition_x() << ";" << index->getPosition_y() << std::endl;
      index = index->getNext();
    } while (index != NULL);

    // Die Datei schließen
    csvFile.close();
    cout << "Die Datei wurde erfolgreich erstellt. Der Pfad lautet: " << endl;
    return 0;
}




int main()
{
     CListe Liste1;
     CBauelement* ptr;

     ptr = new CWiderstand(1.5, 0.35, 3, 15);
     Liste1.AddObject(*ptr);
     ptr = new CSpule(0.15,3.1, 17, 4);
     Liste1.AddObject(*ptr);
     ptr = new CWiderstand(22, 55, 77, 99);
     Liste1.AddObject(*ptr);
     ptr = new CSpule(0.0003, 0.15, 2, 5);
     Liste1.AddObject(*ptr);
     ptr = new CKapatzität(0.15,3.1, 17, 7);
     Liste1.AddObject(*ptr);
     ptr = new CWiderstand(0.15, 44, 17, 8);
     Liste1.AddObject(*ptr);


     Liste1.PrintAllElement();

     /*
     CKomplex Summe = Liste1.GesamtImbedanzReihe(120);
     Summe.AusgabeKarteisisch();
     */

     bool (*funcptrString)( string gesucht,   CBauelement * index);
     /*
     bool (*funcptrKosten)( double gesucht,  CBauelement * index);
     bool (*funcptrPosition)( CPunkt gesucht,  CBauelement * index);*/


     funcptrString = suchNachName;
     string X1 = "R2";
     CBauelement *B1 = Liste1.Durchsuchen(X1, funcptrString);
     B1->Ausgabe();
    
     //Liste1.ImbedanuAnzeigenNachName("R1", 120);


  /*   funcptrKosten = suchNachPreis;
     CBauelement* B2 = Liste1.Durchsuchen(0.15, funcptrKosten);
     B2->Ausgabe();*/

//    CSVDatei(Liste1);

     return 0;
}