#include <iostream>
#include <direct.h>

using namespace std;

void listFiles();
void createNewDirectory();
void changeDirectory();
void displayMainMenu();

int main() {
	int number;
	
	while (true) {
		displayMainMenu();
		cout << "Enter the Number: ";
		cin  >> number;	
		
		switch (number) {
			case 1:
				listFiles();
				break;
			case 2:
				createNewDirectory();
				break;
			case 3:
				changeDirectory();
				break;
			case 4:
				cout << "\nThank you for using my program. \n";
				return 0;
				break;
			default:
				cout << "Invalid number. Please try again! \n"; 					
		}
	}
	return 0;
}

void listFiles() {
    int myNumber;
    string myPattern;
    
    cout << "\n\t LIST FILE DETAILS \n";
    cout << "------------------------------ \n";
    cout << "1. List All Files \n";
    cout << "2. List Files by Extension \n";
    cout << "3. List Files by Name Pattern \n";
    cout << "Enter the Number: ";
    cin >> myNumber;

    struct _finddata_t fileinfo;
    long data;

    switch (myNumber) {
        case 1:
            myPattern = "*.*";
            cout << "\nListing All Files (*.*):\n";
            break;
        case 2: {
            string fileExtension;
            cout << "Enter the file extension: ";
            cin >> fileExtension;
            
            if (fileExtension[0] != '.') {
                fileExtension = "." + fileExtension;
            }
            myPattern = "*" + fileExtension;
            cout << "\nListing Files with Extension: " << fileExtension << "\n";
            break;
        }
        case 3: {
            string namePattern;
            cout << "Enter the name pattern: ";
            cin >> namePattern;
            myPattern = namePattern;
            cout << "\nListing Files with Pattern: " << namePattern << "\n";
            break;
        }
        default:
            cout << "\nInvalid Input! Returning to the main menu.\n";
            system("pause");
            system("cls"); 
    }

    data = _findfirst(myPattern.c_str(), &fileinfo);
    if (data == -1) {
        cout << "\nNo files found matching the pattern: " << myPattern << "\n";
        system("pause");
        system("cls");
        return;
    }

    int fileCount = 0;
    do {
        if (!(fileinfo.attrib & _A_SUBDIR)) { 
            cout << fileinfo.name << endl;
            fileCount++;
        }
    } while (_findnext(data, &fileinfo) == 0);

    _findclose(data);

    if (fileCount == 0) {
        cout << "\nNo files found.\n";
    } 
	else {
        cout << "\nTotal Files Found: " << fileCount << endl;
    }

    system("pause");
    system("cls");
}


void createNewDirectory() {

    string directoryName;
    char currentDirectory[FILENAME_MAX];
    
    cout << "Enter the directory name: ";
    cin >> directoryName;

	    if (_mkdir(directoryName.c_str()) == 0) {
	        cout << endl << directoryName << " Directory Successfully Created.\n\n";
	    } 
		else {
	        cout << "Directory exists already.\n\n";
	    }

	    if (_getcwd(currentDirectory, sizeof(currentDirectory)) != NULL) {
	        cout << "Current Directory: " << currentDirectory << "\\" << directoryName << "\n\n";
	    }
	    system("pause");
	    system("cls");
}

void changeDirectory() {
    int option;
    string directoryName;

    char currentDirectory[FILENAME_MAX];
    if (_getcwd(currentDirectory, sizeof(currentDirectory)) != NULL) {
        cout << "\nCurrent Directory: " << currentDirectory << "\n";
    } 

    cout << "\tChange Directory \n";
    cout << "------------------------------ \n";
    cout << "1. Move to Parent Directory \n";
    cout << "2. Move to Root Directory \n";
    cout << "3. Move to a Specific Directory \n";
    cout << "Enter your choice: ";
    cin >> option;

    switch (option) {
        case 1:
            if (_chdir("..") == 0) {
                if (_getcwd(currentDirectory, sizeof(currentDirectory)) != NULL) {
                    cout << "\nMoved to Parent Directory.\n";
                    cout << "Current Directory: " << currentDirectory << "\n";
                } 
				else {
                    cout << "\nFailed to retrieve the current directory after moving.\n";
                }
            } 
			else {
                cout << "\nFailed to move to Parent Directory.\n";
            }
            break;
        case 2:
            if (_chdir("/") == 0) {
                if (_getcwd(currentDirectory, sizeof(currentDirectory)) != NULL) {
                    cout << "\nMoved to Root Directory.\n";
                    cout << "Current Directory: " << currentDirectory << "\n";
                } 
				else {
                    cout << "\nFailed to retrieve the current directory after moving.\n";
                }
            } 
			else {
                cout << "\nFailed to move to Root Directory.\n";
            }
            break;
        case 3:
            cout << "\nEnter the path of the directory: ";
            cin >> directoryName;

            if (_chdir(directoryName.c_str()) == 0) {
                if (_getcwd(currentDirectory, sizeof(currentDirectory)) != NULL) {
                    cout << "\nChanged to Directory: " << currentDirectory << "\n";
                } 
				else {
                    cout << "\nFailed to retrieve the current directory after moving.\n";
                }
            } 
			else {
                cout << "\nDirectory does not exist or failed to change directory.\n";
            }
            break;
        default:
            cout << "\nInvalid choice. Please try again.\n";
    }
    system("pause");
    system("cls");
}

void displayMainMenu() {
	cout << "\t MAIN MENU \n";
	cout << "---------------------------- \n";
	cout << "1. To Display List of Files \n";
	cout << "2. Create New Directory \n";
	cout << "3. To Change the Working Directory \n";
	cout << "4. Exit \n";	
}
