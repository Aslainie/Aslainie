#include <iostream>
using namespace std;

void displayMainMenu();
void listFiles();
void createNewDirectory();
void changeDirectory();

int main() {
	int number;
	
	while (true) {
		displayMainMenu();
		cout << "Enter the Number: ";
		cin  >> number;	
		
		switch (number) {
			case 1:
				listFiles();
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			default:
				cout << "Invalid number. Please try again! \n"; 					
		}
	}
	return 0;
}

void displayMainMenu() {
	cout << "\t MAIN MENU \n";
	cout << "---------------------------- \n";
	cout << "1. To Display List of Files \n";
	cout << "2. Create New Directory \n";
	cout << "3. To Change the Working Directory \n";
	cout << "4. Exit \n";	
}

void listFiles() {
	int myNumber;
	cout << "\n\t LIST FILE DETAIL \n";
	cout << "---------------------------- \n";
	cout << "1. List All Files \n";
	cout << "2. List of Extension Files \n";
	cout << "3. List of Name Wise \n";
	cout << "Enter the Number: ";
	cin  >>  myNumber;
}
