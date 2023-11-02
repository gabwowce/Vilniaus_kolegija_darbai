#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

int main() {

	cout << "WELCOME TO VIGENERE CHIPER ENCODER/DECODER!" << endl;

    string key_word;
    string message;
    int chosen_option;
    int chosen_alph;

    char alphabet[26] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
    };

    //ASCII alphabet
    int asciiArray[96];
    for (int i = 32; i <= 127; ++i) {
        asciiArray[i - 32] = i;
    }

    bool restart = true;

    while (restart) {

        cout << "Which alphabet do you want to use: " << endl;
        cout << "1 - ASCII,\n2 - English Alphabet;" <<endl;
        
        do {
            cout << "Choose option: ";
            cin >> chosen_alph;
            if (chosen_alph != 1 && chosen_alph != 2) {
                cout << "Invalid choice. Please enter 1 or 2." << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }

        } while (chosen_alph != 1 && chosen_alph != 2);


        cout << "1 - Encode,\n2 - Decode;\n";

        do {
            cout << "Choose option: ";
            cin >> chosen_option;
            if (chosen_option != 1 && chosen_option != 2) {
                cout << "Invalid choice. Please enter 1 or 2." << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }

        } while (chosen_option != 1 && chosen_option != 2);


        if (chosen_alph == 2) {
            bool is_key = false;
            cin.ignore();
            do {
                cout << "Enter keyword: ";
                getline(cin, key_word);
                is_key = true;
                for (char c : key_word) {
                    if (!isalpha(c)) {
                        is_key = false;
                        cout << "Invalid input. Please enter a valid key-word." << endl;
                        break;
                    }
                }
            } while (!is_key);
        }
        else {
            cin.ignore();
            cout << "Enter keyword: ";
            getline(cin, key_word);
        }

        
        if (chosen_alph == 2) {
            bool valid_message = false;
            do {
                cout << "Enter message: ";
                getline(cin, message);
                bool is_valid = true;
                for (char c : message) {
                    if (!isalpha(c) && c != ' ') {
                        is_valid = false;
                        cout << "Invalid input. Please enter a message consisting of letters and spaces only." << endl;
                        break;
                    }
                }
                if (is_valid) {
                    valid_message = true;
                }
            } while (!valid_message);
        }
        else {
            cout << "Enter message: ";
            getline(cin, message);
        }

        vector<int> key_indexes;
        vector<int> message_indexes;

        if (chosen_alph == 2) {

            for (char& c : key_word) {
                c = toupper(c);
            }
            for (char& c : message) {
                c = toupper(c);
            }
        }

        while (key_word.length() < message.length()) {
            key_word += key_word;
        }
        if (key_word.length() > message.length()) {
            key_word = key_word.substr(0, message.length());
        }



        if (chosen_alph == 1) {


            for (char& c : key_word) {
                for (int i = 0; i < 96; i++) {
                    if (c == static_cast<char>(asciiArray[i])) {
                        key_indexes.push_back(asciiArray[i]);
                        break;
                        
                    }
                }
            }

            for (char& c : message) {
                for (int i = 0; i < 96; i++) {
                    if (c == static_cast<char>(asciiArray[i])) {
                        message_indexes.push_back(asciiArray[i]);
                        break;
                    }
                }
            }



        }

        if (chosen_alph == 2) {


            for (char& c : key_word) {
                for (int i = 0; i < 26; i++) {
                    if (alphabet[i] == c) {
                        key_indexes.push_back(i);
                        break;
                    }
                }
            }

            for (char& c : message) {
                for (int i = 0; i < 26; i++) {
                    if (alphabet[i] == c) {
                        message_indexes.push_back(i);
                        break;
                    }
                }
            }




        }

        if (chosen_alph == 1) {
            if (chosen_option == 1) {

                string encrypted_message = "";

                for (size_t i = 0; i < message.length(); ++i) {
                    int key_index = key_indexes[i];
                    int message_index = message_indexes[i];

                    int encrypted_word_index = (message_index + key_index) % 96;
                    encrypted_message.push_back(asciiArray[encrypted_word_index]);
                }

                cout << "The encoded message: " << encrypted_message << endl;
            }
            else if (chosen_option == 2) {

                string decrypted_message = "";

                for (size_t i = 0; i < message.length(); ++i) {
                    int key_index = key_indexes[i];
                    int message_index = message_indexes[i];
                    int decrypted_word_index = (message_index - key_index + 128) % 96;
                    decrypted_message.push_back(asciiArray[decrypted_word_index]);
                }

                cout << "The decoded message: " << decrypted_message << endl;


            }

        }

        if (chosen_alph == 2) {
            if (chosen_option == 1) {

                string encrypted_message = "";

                for (size_t i = 0; i < message.length(); ++i) {
                    int key_index = key_indexes[i];
                    int message_index = message_indexes[i];

                    int encrypted_word_index = (message_index + key_index) % 26;
                    encrypted_message.push_back(alphabet[encrypted_word_index]);
                }

                cout << "The encoded message: " << encrypted_message << endl;
            }
            else if (chosen_option == 2) {

                string decrypted_message = "";

                for (size_t i = 0; i < message.length(); ++i) {
                    int key_index = key_indexes[i];
                    int message_index = message_indexes[i];
                    int decrypted_word_index = (message_index - key_index + 26) % 26;
                    decrypted_message.push_back(alphabet[decrypted_word_index]);
                }

                cout << "The decoded message: " << decrypted_message << endl;


            }

        }








        cout <<endl<< "Do you want to restart? (1 for yes, 0 for no): ";
        cin >> restart;



    }
    
 
    return 0;
}