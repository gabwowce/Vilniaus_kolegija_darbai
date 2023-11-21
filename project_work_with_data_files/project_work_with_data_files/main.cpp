#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main() {

    int option;

    cout << "1 - Isvesti parduotu bilietu skaiciu ir bendra pardavimu suma.\n" << "2 - Isvesti duomenis formatu: vardas, pavardë, atnaujintas atlyginimas.\n";


    bool valid_choice = false;
    while (!valid_choice) {
        cout << "Choose the option: ";
        if (cin >> option) {
            if (option == 1 || option == 2) {
                valid_choice = true;
            }
            else {
                cout << "Invalid choice. Please enter 1 or 2." << endl;
            }
        }
        else {
            cout << "Invalid input. Please enter a number." << endl;

        }
    }


    if (option == 1) {
        ifstream file1;
        file1.open("file1.txt");
        if (file1.is_open()) {
            int num1, num2;
            int tickets = 0;
            double income = 0;
            while (file1 >> num1 >> num2) {
                income += num1 * num2;
                tickets += num2;
            }
            cout << fixed << setprecision(2);
            cout << "Parduotu bilietu skaicius: " << tickets << endl;
            cout << "Pelnas: " << income << endl;
        }
        else {
            cout << "Data file not found\n";
        }

    }

    if (option == 2) {
        ifstream file2;
        file2.open("file2.txt");
        if (file2.is_open()) {
            string first, second;
            float num1, num2;
            float new_salary = 0;
            ofstream new_file2;
            while (file2 >> first >> second >> num1 >> num2) {
                new_file2.open("new_file2");
                if (new_file2.is_open()) {
                    new_salary += num1 * (num2 + 100);
                    new_file2 << first << second << new_salary << endl;
                    new_file2.close();
                }
                else {
                    cout << "Data file not found\n";
                }
            }
        }
    }








    return 0;
}