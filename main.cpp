#include <iostream>
using namespace std;
//valiutos kursas
const float GBP_Bendras   = 0.8729;
const float GBP_Pirkti    = 0.8600;
const float GBP_Parduoti  = 0.9220;
const float USD_Bendras   = 1.1793;
const float USD_Pirkti    = 1.1460;
const float USD_Parduoti  = 1.2340;
const float INR_Bendras   = 104.6918;
const float INR_Pirkti    = 101.3862;
const float INR_Parduoti  = 107.8546;
int main () {
    int pasiriknkimas = 1;
    while (pasiriknkimas == 1) {
        string pavadinimas;
        float bendras,pirkti,parduoti,vnt,sum;
        int valiuta , veiksmas;
        cout << "prasau ivesti valiuta" << endl;
        cout << "1 GBP \n "  << "2 USD \n " << "3 INR" << endl;
        cin >> valiuta;

        cout << " Norimi veiksmai " << endl;
        cout << "1 valiutos kursas \n" << "2 nusipirkti valiutos \n " << "3 parduot valiutos" << endl;
        cin >> veiksmas;
        switch (valiuta) {
            case 1 :
                pavadinimas = "GBP";
                bendras = GBP_Bendras;
                pirkti = GBP_Pirkti;
                parduoti = GBP_Parduoti;
                break;
            case 2 :
                pavadinimas = "USD";
                bendras = USD_Bendras;
                pirkti = USD_Pirkti;
                parduoti = USD_Parduoti;
                break;
            case 3 :
                pavadinimas = "INR";
                bendras = INR_Bendras;
                pirkti = INR_Pirkti;
                parduoti = INR_Parduoti;
                break;
            default :
                cout << " Neteisingas ivedimas" << endl;
                return 0;
        }
        if (veiksmas == 1) {
            cout << "valiutos" << pavadinimas << " kursas : \n";
            cout << "bendras kursas " << bendras << endl;
            cout << "pirkti kursas " << pirkti << endl;
            cout << "parduoti kursas " << parduoti << endl;
        }
        else if (veiksmas == 2 ) {
            cout << "keik norit pakeist ";
            cin >> vnt;
            sum = pirkti * vnt;
            cout << "Jus Gausit " << sum << endl;
        }
        else if (veiksmas == 3 ) {
            cout << "Kiek norit parduot " << pavadinimas << endl;
            cout << pavadinimas;
            cin >> vnt;
            sum = vnt *1. / parduoti;
            // klaida
            cout << "Gausit " << sum << " eur" <<  endl;
        }
        else {
            cout << " tokios paslaugos neturim " << endl;
        }

        cout << " \n1 - grizti i pradzia" << endl;
        cout << " 0 - baigti programa" << endl;
        cin >> pasiriknkimas;
    }
    return 0;
}

