#include <iostream>

#include <vector>

#include <string>

#include <algorithm>

#include <iomanip>

using namespace std;



struct Piesa {

    string denumire;

    double pret;

};



struct TipUlei {

    string vascozitate;

    double pret;

};



string toLower(string text) {

    transform(text.begin(), text.end(), text.begin(), ::tolower);

    return text;

}



int main() {

    vector<Piesa> stoc = {

        {"Ulei Motor", 150.0},

        {"Placute Frana", 200.0},

        {"Filtru Aer", 80.0},

        {"Baterie Auto", 450.0},

        {"Filtru polen", 120.00},

        {"Disc frana", 699.99},

        {"Volanta + kit ambreaj", 2789.99}

    };



    vector<TipUlei> tipuriUlei = {

        {"5w30", 160.0},

        {"5w40", 140.0},

        {"10w40", 110.0},

        {"0w20", 190.0}

    };



    cout << fixed << setprecision(2);

    cout << "--- Sistemul Automobil de Verificare a Stocului (SA-VS) ---\n\n";



    string piesaCautata;

    cout << "---Piese Disponibile in stok---" << endl;
    cout << "Ulei Motor: 5w30, 5w40, 10w40, 0w20." << endl;
    cout << "Placute Frana." << endl << "Filtru aer." << endl << "Filtru Aer." << endl << "Baterie Auto." << endl << "Filtru Polen." << endl << "Disc Frana." << endl << "Volanta + kit ambreiaj." << endl << endl;



    cout << "Introduceti numele piesei pe care o cautati: ";

    getline(cin, piesaCautata);



    bool gasit = false;



    for (size_t i = 0; i < stoc.size(); i++) {

        if (toLower(stoc[i].denumire).find(toLower(piesaCautata)) != string::npos) {

            gasit = true;

            double pretPiesa_curenta = stoc[i].pret;

            string denumireAfisata = stoc[i].denumire;





            if (toLower(stoc[i].denumire) == "ulei motor") {

                cout << "\nAplicatia a detectat cautarea pentru Ulei Motor.\n";

                cout << "Tipurile de ulei disponibile sunt:\n";

                for (size_t j = 0; j < tipuriUlei.size(); j++) {

                    cout << j + 1 << ". " << tipuriUlei[j].vascozitate << " - " << tipuriUlei[j].pret << " lei\n";

                }



                string optiuneUleiStr;

                cout << "Alegeti numarul sau introduceti vascozitatea: ";

                cin >> optiuneUleiStr;

                optiuneUleiStr = toLower(optiuneUleiStr);



                bool uleiGasit = false;





                for (size_t j = 0; j < tipuriUlei.size(); j++) {

                    string indexStr = to_string(j + 1);



                    if (optiuneUleiStr == toLower(tipuriUlei[j].vascozitate) || optiuneUleiStr == indexStr) {

                        pretPiesa_curenta = tipuriUlei[j].pret;

                        denumireAfisata = "Ulei Motor " + tipuriUlei[j].vascozitate;

                        uleiGasit = true;

                        break;

                    }

                }



                if (!uleiGasit) {

                    cout << "\nOptiune invalida. Se va folosi pretul standard de baza.\n";

                }

            }



            else if (toLower(stoc[i].denumire) == "volanta + kit ambreaj") {

                cout << "\nAti selectat piesa: Volanta + kit ambreaj (Pret pachet complet: " << stoc[i].pret << " lei)\n";

                cout << "De ce anume aveti nevoie?\n";

                cout << "1. Doar Volanta (1500.00 lei)\n";

                cout << "2. Doar Kit Ambreiaj (1289.99 lei)\n";

                cout << "3. Ambele (Pachet complet)\n";



                string optiuneAmbreiajStr;

                cout << "Introduceti optiunea (1/2/3): ";

                cin >> optiuneAmbreiajStr;



                if (optiuneAmbreiajStr == "1") {

                    pretPiesa_curenta = 1500.00;

                    denumireAfisata = "Volanta auto";

                }

                else if (optiuneAmbreiajStr == "2") {

                    pretPiesa_curenta = 1289.99;

                    denumireAfisata = "Kit ambreiaj";

                }

            }

            cout << "\nPiesa selectata: " << denumireAfisata << ". Pret: " << pretPiesa_curenta << " lei.\n";

            cout << "Doriti sa cumparati? (Da/Nu): ";



            string raspuns;

            cin >> raspuns;



            if (toLower(raspuns) == "da") {

                double pretFinal = pretPiesa_curenta * 0.90;

                cout << "\nComanda plasata pentru [" << denumireAfisata << "]!\n";

                cout << "Pret final cu reducere (10%): " << pretFinal << " lei.\n";

            }

            else {

                cout << "\nComanda a fost anulata. Va mai asteptam!\n";

            }



            break;

        }

    }



    if (!gasit) {

        cout << "\nNe pare rau, piesa \"" << piesaCautata << "\" nu este disponibila.\n";

    }



    return 0;

}
