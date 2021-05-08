#include<iostream>
#include<ctype.h>

/**************************************************************
*             Implementation of the Ceasar Cipher             *
*             Encryption and Decryption Algorithm             * 
*                  By Njoh Noh Prince Junior                  *
***************************************************************/

using namespace std;

void encryptText() {
	string alphabetsLowerCase = "abcdefghijklmnopqrstuvwxyz";
	string alphabetsUpperCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string plainText;
	string cipherText = "";
	int key, pos = 0;
	cout << "\nEnter the text: ";
	cin >> plainText;
	cout << "Enter the key for encryption: ";
	cin >> key;
	for(int i=0; i<plainText.size(); i++) {
		/**** Check f current character is upper case or lower case letter ****/
		if(isupper(plainText[i])) {
			cipherText += alphabetsUpperCase[(alphabetsUpperCase.find(plainText[i]) + key) % 26]; 
		} else if(islower(plainText[i])) {
			cipherText += alphabetsLowerCase[(alphabetsLowerCase.find(plainText[i]) + key) % 26]; 
		}
	}
	cout <<"\nAfter encryption, " << plainText << " became: " << cipherText << "\n\n";
}

int main(void){
	int choice = 1;
	cout << "\t\t\t\tImplmentation of the Ceasar Cipher Algorithm\n";
	cout << "\t\t\t\t--------------------------------------------\n\n";
	do {
		cout << "Select an option below:\n";
		cout << "----------------------\n\n";
		cout << "0. Exit program\n";
		cout << "1. To Encrypt a plain text\n";
		cout << "2. To Decrypt a cipher text\n\n";
		
		cout << "Enter your choice: ";
		cin >> choice;
		
		switch(choice) {
			case 0:
				exit(0);
				break;
			case 1:
				encryptText();
				break;
			case 2:
				decryptCipher();
				break;
			default:
				cout << "\nInvalid Input... Please choose from the option provided.\n\n";
		}
	} while (choice != 0);
	return 0;
}
