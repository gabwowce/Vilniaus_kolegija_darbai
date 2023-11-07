#include <iostream>
#include <cctype>
#include <limits>
using namespace std;


//Check if the entered number is a palindrome
void palindrome(int number) {
    int originalNumber = number;
    int reversedNumber = 0;

    while (number > 0) {
        int digit = number % 10;
        reversedNumber = reversedNumber * 10 + digit;
        number /= 10;
    }
    if (originalNumber == reversedNumber) {
        cout << originalNumber << " is a palindrome.\n";
    }
    else {
        cout << originalNumber << " is not a palindrome.\n";
    }
}

//Check if the entered letter is a vowel
bool check_letter(char letter) {
    letter = tolower(letter);
    return letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u';
}


//Find the greatest common divisor between two entered digits.
int greatest_common_divisor(int num1, int num2) {

    num1 = abs(num1);
    num2 = abs(num2);

    while (num2 != 0) {
        int temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }
    return num1;

}





int main() {
    int option;
    int number;
    char letter;
    int num1, num2;
    cout << "1 - Check if the entered number is a palindrome\n" << "2 - Check if the entered letter is a vowel\n" << "3 - Find the greatest common divisor between two entered digits.\n" << "0 - close the program\n\n";

    bool game_on = true;
    while (game_on) {
        bool valid_choice = false;
        while (!valid_choice) {
            cout << "Choose the option: ";
            if (cin >> option) {
                if (option == 1 || option == 2 || option == 3 || option == 0) {
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

        if (option == 1) {
            bool valid_choice = false;
            while (!valid_choice) {
                cout << "Enter the number : ";
                if (cin >> number) {
                    if (number > 0) {
                        valid_choice = true;
                    }
                    else {
                        cout << "Invalid input.Please enter a number bigger then 0.\n";
                    }
                }

                else {
                    cout << "Invalid input. Please enter a full number." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            palindrome(number);

        }
        if (option == 2) {
            bool valid_choice = false;
            while (!valid_choice) {
                cout << "Enter the letter: ";
                cin >> letter;
                if (isalpha(letter)) {
                    valid_choice = true;
                }

                else {
                    cout << "Invalid input. Please enter a letter." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            if (check_letter(letter)) {
                cout << "It's a vowel!\n";
            }
            else {
                cout << "It's not a vowel.\n";
            }

        }

        if (option == 3) {
            bool valid_choice = false;
            while (!valid_choice) {
                cout << "Enter the first number: ";
                if (cin >> num1) {
                    if (num1 != 0) {
                        valid_choice = true;
                    }
                    else {
                        cout << "Invalid input. Please enter a number not equal to 0.\n";
                    }
                }

                else {
                    cout << "Invalid input. Please enter a full number." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

            }
            bool choice = false;
            while (!choice) {
                cout << "Enter the second number: ";
                if (cin >> num2) {
                    if (num2 != 0) {
                        choice = true;
                    }
                    else {
                        cout << "Invalid input. Please enter a number not equal to 0.\n";
                    }
                }

                else {
                    cout << "Invalid input. Please enter a full number." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }

            cout << "The greatest common divisor between two entered digits is " << greatest_common_divisor(num1, num2) << endl << endl;
        }

        if (option == 0) {

            game_on = false;
        }





    }
    return 0;

}
