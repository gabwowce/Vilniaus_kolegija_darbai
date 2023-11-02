#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {

    int pasirinkta_funkcija;
    string pasirinkta_valiuta;
    int pasirinkta_suma;
    float GBP_Bendras = 0.8593;
    float GBP_Pirkti = 0.8450;
    float GBP_Parduoti = 0.9060;
    float USD_Bendras = 1.0713;
    float USD_Pirkti = 1.0547;
    float USD_Parduoti = 1.1309;
    float INR_Bendras = 88.8260;
    float INR_Pirkti = 85.2614;
    float INR_Parduoti = 92.8334;

    bool restart = true;

    while (restart) {
        cout << "VALIUTU KURSU SKAICIUOKLE" << endl << endl;
        cout << "Funkcijos: " << endl << endl;
        cout << "Valiutos kurso palyginimas su kita valiuta. (Iveskite - 1)" << endl;
        cout << "Galimybe isigyti valiutos (t.y pirkti valiuta). (Iveskite - 2)" << endl;
        cout << "Galimybe parduoti valiuta (t.y parduoti valiuta). (Iveskite - 3)" << endl << endl;
        bool valid_choice = false;
        while (!valid_choice) {
            cout << "Iveskite funkcija kuria norite atlikti: ";
            if (cin >> pasirinkta_funkcija) {
                if (pasirinkta_funkcija == 1 || pasirinkta_funkcija == 2 || pasirinkta_funkcija == 3) {
                    valid_choice = true;
                }
                else {
                    cout << "Invalid choice. Please enter 1, 2, or 3." << endl;
                }
            }
            else {
                cout << "Invalid input. Please enter a number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        if (pasirinkta_funkcija == 1) {

            bool valid_suma = false;
            while (!valid_suma) {
                cout << endl << "Pasirinkite kokia suma EUR norite palyginti: ";

                if (cin >> pasirinkta_suma) {
                    valid_suma = true;
                }
                else {
                    cout << "Invalid choice. Please enter a valid amount of money." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            double GBP_result = GBP_Bendras * pasirinkta_suma;
            double USD_result = USD_Bendras * pasirinkta_suma;
            double INT_result = INR_Bendras * pasirinkta_suma;
            cout << endl << GBP_result << " GBP";
            cout << endl << USD_result << " USD";
            cout << endl << INT_result << " INR" << endl;
        }
        else if (pasirinkta_funkcija == 2) {
            bool valid_choice = false;
            while (!valid_choice) {
                cout << "Pasirinkite valiuta kuria norite isigyti (USD, GBP, INR): ";
                cin >> pasirinkta_valiuta;

                if (pasirinkta_valiuta == "USD" || pasirinkta_valiuta == "GBP" || pasirinkta_valiuta == "INR") {
                    valid_choice = true;
                }
                else {
                    cout << "Invalid choice. Please enter USD, GBP, or INR." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            bool valid_suma = false;
            while (!valid_suma) {
                cout << endl << "Iveskite perkama suma: ";

                if (cin >> pasirinkta_suma) {
                    valid_suma = true;
                }
                else {
                    cout << "Invalid choice. Please enter a valid amount of money." << endl;
                    cin.clear();
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }


            if (pasirinkta_valiuta == "USD") {
                double eurAmount = pasirinkta_suma / USD_Pirkti;
                printf("\nUz %d %s Jus sumokejote %.2f EUR, Jusu saskaitoje %d %s\n", pasirinkta_suma, pasirinkta_valiuta.c_str(), eurAmount, pasirinkta_suma, pasirinkta_valiuta.c_str());
            }
            else if (pasirinkta_valiuta == "GBP") {
                double eurAmount = pasirinkta_suma / GBP_Pirkti;
                printf("\nUz %d %s Jus sumokejote %.2f EUR, Jusu saskaitoje %d %s\n", pasirinkta_suma, pasirinkta_valiuta.c_str(), eurAmount, pasirinkta_suma, pasirinkta_valiuta.c_str());
            }
            else if (pasirinkta_valiuta == "INR") {
                double eurAmount = pasirinkta_suma / INR_Pirkti;
                printf("\nUz %d %s Jus sumokejote %.2f EUR, Jusu saskaitoje %d %s\n", pasirinkta_suma, pasirinkta_valiuta.c_str(), eurAmount, pasirinkta_suma, pasirinkta_valiuta.c_str());
            }
            else {

                cout << "Invalid choice. Please enter USD, GBP or INR." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

        }
        else if (pasirinkta_funkcija == 3) {

            bool valid_choice = false;
            while (!valid_choice) {
                cout << "Pasirinkite valiuta kuria norite parduoti (USD, GBP, INR): ";
                cin >> pasirinkta_valiuta;

                if (pasirinkta_valiuta == "USD" || pasirinkta_valiuta == "GBP" || pasirinkta_valiuta == "INR") {
                    valid_choice = true;
                }
                else {
                    cout << "Invalid choice. Please enter USD, GBP, or INR." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }

            bool valid_suma = false;
            while (!valid_suma) {
                cout << endl << "Pasirinkite suma kuria norite parduoti: ";

                if (cin >> pasirinkta_suma) {
                    valid_suma = true;
                }
                else {
                    cout << "Invalid choice. Please enter a valid amount of money." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }



            if (pasirinkta_valiuta == "USD") {
                double result = pasirinkta_suma / USD_Parduoti;
                printf("Jusu saskaitoje %.2f EUR\n", result);
            }
            else if (pasirinkta_valiuta == "GBP") {
                double result = pasirinkta_suma / GBP_Parduoti;
                printf("Jusu saskaitoje %.2f EUR\n", result);
            }
            else if (pasirinkta_valiuta == "INR") {
                double result = pasirinkta_suma / INR_Parduoti;
                printf("Jusu saskaitoje %.2f EUR\n", result);
            }
            else {
                cout << "Invalid choice. Please enter USD, GBP or INR." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        cout << "Do you want to restart? (1 for yes, 0 for no): ";
        cin >> restart;
    }

    return 0;
}