#include <iostream>
#include <fstream>
#include <string>
#include "x64/qol.h"
using namespace std;


int main()
{
	string SiteName{}, User{}, Pw{}; 
	char Exkey{ 'y' };

	ofstream file1;
	file1.open("Passwords.txt", ios::out | ios::app);
	if (file1.is_open()) {
		while (Exkey == 'y') {
			cout << "Enter Site Name: ";
			cin >> SiteName;
			cout << "Enter User: ";
			cin >> User;
			cout << "[1] For Randomly Generated Password | [0] Use Preexisting Password";
			char x;
			cin >> x;
			if (x == '1') {                                         
				Pw = PasswordGen();
				if (setClipboardText(Pw)) {	//save to clipboard
					cout << "Password Copied To Clipboard!\n";
			}
				else {
					cerr << "Failed To Copy Password To Clipboard\n";
				}
			}
			else {
				cout << "Enter Password: ";
				cin >> Pw;
			}

			file1 << SiteName << "\n" << "-------------\n" << "User: " << User << "\n" << "Pw: " << Pw << "\n" << endl;
			
			cout << "Continue[Y/N] ";
			cin >> Exkey;

		}
		file1.close();
	}
	else {
		cerr << "UNABLE TO OPEN FILE";
	}
	return 0;
}


