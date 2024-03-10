#include <iostream>
#include <regex>

using namespace std;

void rail_fence_cipher(){
    string message;
    cout << "Enter  the Message : ";
    getline(cin , message);
    cin.ignore();

    // ommiting  white space from message
    message = regex_replace(message, regex("\\s+"), "");

    cout << "Enter key(number of rails): ";
    int rails;
    cin >> rails;
    cin.ignore();

    // creating empty matrix
    char matrix_rails[rails][message.length()];
    for (int x = 0; x < rails; x++){
        for (int y = 0; y < message.length(); y++){
            matrix_rails[x][y] = '.';
        }
    }

    // testing newly created matrix
//    for (int i = 0; i < rails; i++){
//        for (int j = 0; j < message.length(); j++){
//            cout << railMatrix[i][j];
//        }
//        cout << endl;
//    }

    // putting message letters one by one in rail matrix in zig-zag
    int row = 0;
    int check = 0;
    for (int x = 0; x < message.length(); x++){
        if (check == 0){
            matrix_rails[row][x] = message[x];
            row++;
            if(row == rails){
                check = 1;
                row--;
            }
        } else if (check == 1){
            row--;
            matrix_rails[row][x] = message[x];
            
            if (row == 0){
                check = 0;
                row = 1;
            }
        } // if-else
    } // for

    // creating encrypted text
    string text_encryption = "";
    for (int x = 0; i < rails; x++){
        for (int y = 0; y < message.length(); y++){
//            cout << railMatrix[i][j];
            text_encryption += Matrix_rails[x][y];
        }
//        cout << endl;
    }

    // removing '.' from encrypted Text
    text_encryption = regex_replace(text_encryption, regex("\\."), "");
    cout << " An Encrypted Message : " << text_encryption;
}

void ciphe_tDecryption(){
    string message;
    cout << "Enter message: ";
    getline(cin , message);
    cin.ignore();

    // removing white space from message
    message = regex_replace(message, regex("\\s+"), "");

    cout << "Enter key(number of rails): ";
    int rails;
    cin >> rails;
    cin.ignore();

    // creating empty matrix
    char matrix_rails[rails][message.length()];
    for (int x = 0; x < rails; x++){
        for (int y = 0; y < message.length(); y++){
            matrix_rails[x][y] = '.';
        }
    }

    // testing newly created matrix
//    for (int i = 0; i < rails; i++){
//        for (int j = 0; j < message.length(); j++){
//            cout << railMatrix[i][j];
//        }
//        cout << endl;
//    }

    // putting message letters one by one in rail matrix in zig-zag
    int row = 0;
    int test = 0;
    for (int x = 0; x < message.length(); x++){
        if (test == 0){
            matrix_rails[row][x] = message[x];
            row++;
            if(row == rails){
                test = 1;
                row--;
            }
        } else if (test == 1){
            row--;
            matrix_rails[row][x] = message[x];
            if (row == 0){
                test = 0;
                row = 1;
            }
        } // if-else
    } // for

    // reordering rails
    int ordr = 0;
    for (int x = 0; x < rails; x++){
        for (int y = 0; y < message.length(); y++){
            string temp = "";
            temp += matrix_rails[x][i];
            if(regex_match(temp, regex("\\."))){
                // skipping '.'
                continue;
            } else {
                // adding cipher letters one by one diagonally
                matrix_rails[x][y] = message[ordr];
                ordr++;
            } // if-else
        } // inner for
    } // for

    // testing reordering
//    for (int i = 0; i < rails; i++){
//        for (int j = 0; j < message.length(); j++){
//            cout << railMatrix[i][j];
//        }
//        cout << endl;
//    }

    // converting rows back into a message of single line
    string text_decryption = "";
    test = 0;
    row = 0;
    for (int x = 0; x < message.length(); x++){
        if (test == 0){
            text_decryption += railMatrix[row][i];
            row++;
            if (row == rails){
                test = 1;
                row--;
            }
        } else if (test == 1){
            row--;
            text_decryption += matrix_rails[row][x];
            if (row == 0){
                test = 0;
                row = 1;
            }
        } // if else
    } // for

    // removing '.' from decrypted text
    text_decryption = regex_replace(text_decryption, regex("\\.+"), "");
    cout << "Decrypted Text: " << text_decryption;
}

int main()
{
    cout << "1. Encryption\n2. Decryption\nChoose(1,2): ";
    int choice;
    cin >> choice;
    cin.ignore();

    if (choice == 1){
        cout << endl << "Encryption" << endl;
        rail_fence_cipher();

    } else if (choice == 2) {
        cout << endl << "Decryption" << endl;
        cipher_Decryption();

    } else {
        cout << endl << "Invalid Choice" << endl;
    }

    return 0;
}
