#include <iostream>
#include <fstream>
#include <string>
#include<array>
#include<cstdlib>
#include<ctime>
using namespace std;

string PasswordGen();

int main()
{
	string SiteName{}, User{}, Pw{};
	char Exkey{ 'y'};

	ofstream file1; 
	file1.open("test.txt", ios::out | ios::app);
	if(file1.is_open()){
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
			}
			else {
				cout << "Enter Password: ";
				cin >> Pw;
			}
			
			file1 << SiteName << "\n" << "-------------\n" << "User: " << User << "\n" << "Pw: " << Pw <<  "\n" <<endl;

			cout << "Continue[Y/N] ";
			cin >> Exkey;

		}
	file1.close();
	}
	else {
		cout << "UNABLE TO OPEN FILE";
	}
	return 0;
}


string PasswordGen() {

	//simple password generator 
	string RandPassword;

		//Used characters
		string Decyph[73] = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j","k", "l", "m", "n", "o", "p", "q", "r", "s","t", "u", "v", "w", "x", "y", "z", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J","K", "L", "M", "N", "O", "P", "Q", "R","S", "T", "U", "V", "W", "X", "Y", "Z","!","@","#","$","%","^","&","*","(",")","?","1","2","3","4","5","6","7","8","9","0" };

		//Random seed(seed is time on computer)
		srand(static_cast<unsigned int>(time(0)));


		//Undecypherable Randomness
		for (int i = rand() % 73; i < 73; i++) {
			Decyph[rand() % 73] = Decyph[i];
		}

		//Create 20 Character Password
		for (int i = 0; i < 20; i++) {
			RandPassword.append(Decyph[rand() % 73]);
		}
		return RandPassword;
}




