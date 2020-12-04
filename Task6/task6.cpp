#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void initialise(vector<string>* temp) {

	int choice;
	cout << "Are you sure you want to initialise database?" << endl;
	cout << "This will clear the data base" << endl;
	cout << "1. Yes\n2. No" << endl;
	cin >> choice;

	system("cls");

	switch (choice) {
	case 1:
		temp->clear();
		cout << "Initialisation complete" << endl;
		break;
	case 2:
		cout << "Initialisation cancelled" << endl;
		break;
	}

}

void insert(vector<string>* temp) {

	while (true) {

		string namein;
		cout << "(Write \"q\" to quit)" << endl;
		cout << "Insert name: ";
		cin >> namein;
		if (namein == "q" || namein == "Q") {
			break;
		}
		else if ((count(temp->begin(), temp->end(), namein)) == false) {
			temp->push_back(namein);
			cout << "\n\"" << namein << "\" has been added to database\n" << endl;
		}
		else {
			cout << "\n\"" << namein << "\" already exists in database\n" << endl;
		}
		system("pause");
		system("cls");

	}

}

void search(const vector<string>* temp) {

	string key;
	cout << "Search: ";
	cin >> key;

	bool results = false;
	cout << "\n" << endl;
	for (int i = 0; i < temp->size(); i++) {
		string x = temp->at(i);
		if (x.find(key) != string::npos) {
			cout << " \"" << temp->at(i) << "\" ";
			results = true;
		}
	}
	if (results == false) {
		cout << "No results";
	}
	cout << "\n\n" << endl;
}

void del(vector<string>* temp) {

	while (true) {

		string delname;
		cout << "(Write \"q\" to quit)" << endl;
		cout << "Delete name: ";
		cin >> delname;

		if (delname == "q" || delname == "Q") {
			break;
		}
		else if (count(temp->begin(), temp->end(), delname)) {
			temp->erase(remove(temp->begin(), temp->end(), delname));
			cout << "\n\"" << delname << "\" has been removed from database\n" << endl;
		}
		else {
			cout << "\n\"" << delname << "\" does not exist in database\n" << endl;
		}
		system("pause");
		system("cls");

	}

}

void print(const vector<string>* temp) {

	cout << "Names in database: \n" << endl;

	for (int i = 0; i < temp->size(); i++) {
		cout << " \"" << temp->at(i) << "\" ";
	}
	cout << "\n" << endl;

}

void quit(bool& mquit) {
	mquit = false;
}

int save(const vector<string>* temp)
{
	string fname;
	ofstream f;
	cout << "Save (write \"q\" to quit)" << endl;
	cout << "Filename: ";
	cin >> fname;
	if (fname != "q")
	{
		fname += ".txt";
		f.open(fname);
		for (int i = 0; i < temp->size(); i++)
		{
			f << temp->at(i) << endl;
		}
		f.close();
		cout << "File saved" << endl;
	}
	else
	{
		return 0;
	}
	return 0;
}

int load(vector<string>* temp)
{
	string fname;
	ifstream f;
	cout << "Load (write \"q\" to quit)" << endl;
	cout << "Filename: ";
	cin >> fname;
	if (fname != "q")
	{
		temp->clear();
		fname += ".txt";
		f.open(fname);
		string data;
		getline(f, data);
		if (data == "")
		{
			cout << "File does not exist or is empty" << endl;
			return 0;
		}
		f.clear();
		f.seekg(0);
		while (getline(f, data))
		{
			temp->push_back(data);
		}
		f.close();
		cout << "File loaded" << endl;
	}
	else
	{
		return 0;
	}
	
	return 0;
}

int main() {

	vector<string> names;
	vector<string>* p = &names;

	bool menu = true;

	while (menu) {

		int choice;

		cout << "MENU (choose by number)\n" << endl;
		cout << "1. Initialise database\n2. Insert\n3. Search\n4. Delete\n5. Print\n6. Save\n7. Load\n8. Quit" << endl;
		cin >> choice;

		if (1 <= choice <= 6) {
			system("cls");
		}
		switch (choice) {
		case 1:
			initialise(p);
			break;
		case 2:
			insert(p);
			break;
		case 3:
			search(p);
			break;
		case 4:
			del(p);
			break;
		case 5:
			print(p);
			break;
		case 6:
			save(p);
			break;
		case 7:
			load(p);
			break;
		case 8:
			quit(menu);
			break;
		default:
			cout << "That is not an option." << endl;
		}

		if (choice != 8) {
			system("pause");
		}
		system("cls");
	}

	return 0;
}