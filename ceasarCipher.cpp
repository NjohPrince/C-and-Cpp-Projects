#include<iostream>
#include<ctype.h>

/**************************************************************
*             Implementation of the Ceasar Cipher             *
*             Encryption and Decryption Algorithm             * 
*                  By Njoh Noh Prince Junior                  *
***************************************************************/

using namespace std;

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
