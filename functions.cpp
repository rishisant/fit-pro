# include <iostream>
# include <string>
# include <math.h>
# include <iomanip>
# include <stdio.h>      
# include <stdlib.h>    
# include <time.h>       
# include <chrono>
# include <thread>
# include "functions.h"
# include <vector>
# include <regex>
# include <fstream>
# include <sstream>
# include <locale>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::fixed;
using std::setprecision;
using std::vector;
using std::ifstream;

void sleep(int ms) {
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

void fileRead(string filename) {
	ifstream file(filename);
	vector <Company> comp;

	if (file.is_open()) {
		// cout << "File is opened" << endl;
	}

	string inpText;
	std::regex re("^.*(,.*)*$");

	while (getline(file, inpText)) {

		vector <string> companyVec;
		Company company;
		std::smatch cm;

		if (std::regex_match(inpText, cm, re)) {
			std::stringstream SS(cm[0]);

			while (SS.good()) {

				string txtInput;
				getline(SS, txtInput, ',');
				companyVec.push_back(txtInput);

				}

				company.company_name = companyVec[0];
				company.abbreviation = companyVec[1];
				company.purchase_level = stoi(companyVec[2]);
				company.price = stod(companyVec[3]);
				company.inflation_rate = stod(companyVec[4]);
				company.deflation_rate = stod(companyVec[5]);
				}

				comp.push_back(company);
			}

}

void enterInfo(Player player) {
	string userName;
	bool upperIn = false;
	int flag = 0;
	string passWord;
	string ageinput;
	int age;
	sleep(1300);

	while (flag != 1) {
		cout << "\n\nUsername (3+ characters, lowercase only): ";
		cin >> userName;

		for (unsigned int i = 0; i < userName.length(); i++) {
			if (isupper(userName.at(i))) {
				upperIn = true;
			}
		}

		if (userName.length() < 3 || upperIn == true) {
			cout << "Invalid username. Please input a valid username.";
			upperIn = false;
		}

		else {
			flag = 1;
		}

	}

	while (flag != 2) {
		cout << "\n\nPassword (6+ characters): ";
		cin >> passWord;

		if (passWord.length() < 6) {
			cout << "Invalid password. Please input a valid password.";
		}

		else {
			flag = 2;
		}

	}

	while (flag != 3) {
		cout << "\nInput your age: ";
		cin >> ageinput;
		age = std::stoi(ageinput);
		srand(time(NULL));
		int cchoice;
		cchoice = rand() % 30 + 1;

		if (!(age >= 18)) {
			
			if (cchoice == 14) {
				for (unsigned int i = 0; i < 15; i++) {
					cout << "You will be terminated." << endl;
					sleep(100);
					cout << "You will be terminate." << endl;
					sleep(140);
					cout << "Termination occuring." << endl;
					sleep(110);
					cout << "Termnia ucuri" << endl;
					sleep(400);
					cout << "Tma rui" << endl;
					cout << "T" << endl;
				}
				break;
			}
			else {
				cout << "You are not old enough to play.\n" << endl;
				break;
			}
			
		}

		else {
			flag = 3;
		}
	}

	cout << endl << "Welcome to FitPro, " << userName << "!" << endl;

	player.player_username = userName;
	player.player_password = passWord;

}

void startScreen() {
	string userName;
	Player player;
	cout << "Welcome to FitPro!" << endl;
	sleep(2500);
	cout << "FitPro is an applcation that allows you to venture into the world of fits.\n";
	sleep(4500);
	cout << "Fits are entities which you can purchase to gain profit.\n" <<
	"However, fits may be volatile, and prices are not meant to be constant.\n\n";
	sleep(6000);
	cout << "Let us introduce you to the world of fits! Please enter your information within the following fields.\n(Note: You must be 18 or older to purchase fits.)";

}

string isPurchaseable(Player player, Company& a) {

	a.canPurchase = false;

	if (player.player_level >= a.purchase_level) {
		a.canPurchase = true;
	}

	else if (player.profit_margin > a.price && a.playerOwned == false) {
		a.canPurchase = true;
	}

	if (player.profit_margin < a.price) {
		a.canPurchase = false;
	}

	else if (a.playerOwned == true) {
		a.canPurchase = false;
	}
	
	if (a.canPurchase == true) {
		return "▸ PURCHASEABLE";
	}

	else {
		return "▸ CANNOT PURCHASE";
	}
}

string volatileScale(Company a) {
	// VOLATILE, SLIGHTLY VOLATILE, NOT VOLATILE
	// Kash Cows,KSH,1,75,1.10,0.95
	string volStatus;

	if (a.inflation_rate < 1.05 && a.deflation_rate > 0.95) {
		volStatus = "STATIC";
	}

	else if (a.inflation_rate < 1.15 && a.inflation_rate >= 1.05 && a.deflation_rate > 0.85 && a.deflation_rate <= 0.95) {
		volStatus = "SLIGHTLY VOLATILE";
	}

	else {
		volStatus = "VOLATILE";
	}

	return volStatus;
}

/*Puckett Industries, PCK, 1, $75, 1.03, 0.85
Kash Cows, KSH, 1, $50, 1.22, 0.76
Separators, SEP, 1, $25, 1.54, 0.53
Larkin Incorporated, LAR, 1, $100, 1.05, 0.95
Aerofay, AER, 1, $175, 1.11, 0.87
Damunostras, DNS, 1, $200, 1.08, 0.78
Fiddler, FID, 1, $205, 1.44, 0.57
Pic*/

void loadScreen(Player& p, Company a, Company b, Company c, vector <Company> comp) {
	int r1, r2, r3;
	string user_input;

	if (system("CLS")) {
		(system("clear"));
	}
	
	cout << p.player_username << "'s FitPro:" << endl;
	cout << "Current Net Worth: $" << fixed << setprecision(2) << netWorthCalc(p) << endl
	<< "Spendable Money: $" << fixed << setprecision(2) << spendableMoney(p) << endl << endl;
	cout << endl << "✧ Fits of the Day ✧" << endl << endl;

	cout << "[1] " << a.company_name << " " << "(" << a.abbreviation << ")" << endl << fixed << setprecision(2)
	<< "$" << a.price << " " << isPurchaseable(p, a) << endl
	<< endl;
	cout << "[2] " << b.company_name << " " << "(" << b.abbreviation << ")" << endl << fixed << setprecision(2)
	<< "$" << b.price << " " << isPurchaseable(p, b) << endl
	<< endl;
	cout << "[3] " << c.company_name << " " << "(" << c.abbreviation << ")" << endl << fixed << setprecision(2)
	<< "$" << c.price << " " << isPurchaseable(p, c) << endl
	<< endl;

	sleep(1300);
	bool nextDay = false;
	
	if (p.player_rounds <= 3) {
		cout << "Type the number corresponding to the company which you would like to purchase, type s to access the item shop, type i to view your current fit inventory, or type n to forward to the next day." << endl;
		cout << "Input here: ";
		cin >> user_input;
	}

	else {
		cout << "Type h for help, or type a valid input here: ";
		cin >> user_input;
		
	}

	while (nextDay != true) {

		if (user_input == "h") {
			cout << endl << "KEY: " <<
			endl << "TYPE 1, 2, or 3 for the corresponding fit to purchase it"
			<< endl << "TYPE s to access the item shop"
			<< endl << "TYPE n to forward to the next day"
			<< endl;
			cout << "Input here: ";
			cin >> user_input;
		}

		if (user_input == "1") {
			// something
			purchaseFit(p, a);
			cout << endl << "If you would like to make another action, please input an entry." << endl << "Input here: ";
			cin >> user_input;
		}

		else if (user_input == "2") {
			// something
			purchaseFit(p, b);
			cout << endl << "If you would like to make another action, please input an entry." << endl << "Input here: ";
			cin >> user_input;
		}

		else if (user_input == "3") {
			// something
			purchaseFit(p, c);
			cout << endl << "If you would like to make another action, please input an entry." << endl << "Input here: ";
			cin >> user_input;
		}

		else if (user_input == "n" || user_input == "N") {
			// something
			nextDay = true;
		}

		else if (user_input == "s" || user_input == "S") {
			// something
			displayStats(p);
			cout << endl << "If you would like to make another action, please input an entry." << endl << "Input here: ";
			cin >> user_input;
			
		}

		else if (user_input == "i" || user_input == "I") {
			// something
			fitInventory(p);
			cout << endl << "If you would like to make another action, please input an entry." << endl << "Input here: ";
			cin >> user_input;
		}

		else {
			cout << "Please give a valid input." << endl;
			cout << "Input here: ";
			cin >> user_input;
		}

	}

	sleep(750);
	fitTrends(p, comp);
	randomizeFits(p, r1, r2, r3);
	loadScreen(p, comp[r1], comp[r2], comp[r3], comp);
	
}

void randomizeFits(Player p, int& a, int& b, int& c) {
	// bounds for level 1 companies
	// comp0 >> comp15
	// only have level 1 companies so far
	srand(time(NULL));
	if (p.player_level == 1) {
		a = rand() % 15;
		b = rand() % 15;
		c = rand() % 15;
		sleep(100);

		if (a == b || a == c || b == c || a == b == c) {
			srand(time(NULL));
			a = rand() % 15;
			b = rand() % 15;
			
			if (a == b || a == c || b == c || a == b == c) {
				sleep(100);
				srand(time(NULL));
				a = rand() % 15;

				if (a == b || a == c || b == c || a == b == c) {
					sleep(100);
					srand(time(NULL));
					c = rand() % 15;
				}
			}

		}
	}
	
}

void fitTrends(Player& p, vector <Company>& comp) {
	// bounds for level 1 companies are comp0>>comp15
	int a;
	srand(time(NULL));
	a = rand() % 20;
	unsigned int vec_size;
	unsigned int pvec_size = p.ownedCompanies.size();
	unsigned int i;

	if (p.player_level == 1) {
		// only affect the companies to 15
		vec_size = 16;
		for (i = 0; i < vec_size; i++) {

			if (a == 0) {
				comp[i].price *= comp[i].inflation_rate;
			}

			else if (a == 1) {
				comp[i].price *= (comp[i].inflation_rate * 1.02);
			}

			else if (a == 2) {
				comp[i].price *= (comp[i].inflation_rate * 1.05);
			}

			else if (a == 3) {
				comp[i].price *= (comp[i].inflation_rate * 1.1);
			}

			else if (a == 4) {
				comp[i].price *= (comp[i].deflation_rate);
			}

			else if (a == 5) {
				comp[i].price *= (comp[i].deflation_rate * 0.95);
			}

			else if (a == 6) {
				comp[i].price *= (comp[i].deflation_rate * 0.90);
			}
		
			else if (a == 7) {
				comp[i].price *= (comp[i].deflation_rate * 0.88);
			}

			else if (a == 8) {
				comp[i].price *= (comp[i].deflation_rate * 0.80);
			}

			else if (a == 9) {
				comp[i].price *= (comp[i].inflation_rate * 1.3);
			}

			else if (a == 10) {
				comp[i].price *= (comp[i].inflation_rate * 1.23);
			}

			else if (a == 11) {
				comp[i].price *= (comp[i].inflation_rate * 1.24);
			}

			else if (a == 12) {
				comp[i].price *= (comp[i].inflation_rate * 1.15);
			}

			else if (a == 13) {
				comp[i].price *= (comp[i].deflation_rate * 0.98);
			}

			else if (a == 14) {
				comp[i].price *= (comp[i].inflation_rate);
			}

			else if (a == 15) {
				comp[i].price *= (comp[i].inflation_rate);
			}

			else if (a == 16) {
				comp[i].price *= (comp[i].deflation_rate * 0.6);
			}

			else if (a == 17) {
				comp[i].price *= (comp[i].inflation_rate * 1.03);
			}

			else if (a == 18) {
				comp[i].price *= (comp[i].deflation_rate * 0.44);
			}

			else if (a == 19) {
				comp[i].price *= (comp[i].inflation_rate * 1.66);
			}

			else {
				comp[i].price *= (comp[i].inflation_rate * 1.93);
			}
		
		}

		// now affect the player owned ones
		for (i = 0; i < pvec_size; i++) {
			if (a == 0) {
				p.ownedCompanies[i].price *= p.ownedCompanies[i].inflation_rate;
			}

			else if (a == 1) {
				p.ownedCompanies[i].price *= (p.ownedCompanies[i].inflation_rate * 1.02);
			}

			else if (a == 2) {
				p.ownedCompanies[i].price *= (p.ownedCompanies[i].inflation_rate * 1.05);
			}

			else if (a == 3) {
				p.ownedCompanies[i].price *= (p.ownedCompanies[i].inflation_rate * 1.1);
			}

			else if (a == 4) {
				p.ownedCompanies[i].price *= (p.ownedCompanies[i].deflation_rate);
			}

			else if (a == 5) {
				p.ownedCompanies[i].price *= (p.ownedCompanies[i].deflation_rate * 0.95);
			}

			else if (a == 6) {
				p.ownedCompanies[i].price *= (p.ownedCompanies[i].deflation_rate * 0.90);
			}
		
			else if (a == 7) {
				p.ownedCompanies[i].price *= (p.ownedCompanies[i].deflation_rate * 0.88);
			}

			else if (a == 8) {
				p.ownedCompanies[i].price *= (p.ownedCompanies[i].deflation_rate * 0.80);
			}

			else if (a == 9) {
				p.ownedCompanies[i].price *= (p.ownedCompanies[i].inflation_rate * 1.3);
			}

			else if (a == 10) {
				p.ownedCompanies[i].price *= (p.ownedCompanies[i].inflation_rate * 1.23);
			}

			else if (a == 11) {
				p.ownedCompanies[i].price *= (p.ownedCompanies[i].inflation_rate * 1.24);
			}

			else if (a == 12) {
				p.ownedCompanies[i].price *= (p.ownedCompanies[i].inflation_rate * 1.15);
			}

			else if (a == 13) {
				p.ownedCompanies[i].price *= (p.ownedCompanies[i].deflation_rate * 0.98);
			}

			else if (a == 14) {
				p.ownedCompanies[i].price *= (p.ownedCompanies[i].inflation_rate);
			}

			else if (a == 15) {
				p.ownedCompanies[i].price *= (p.ownedCompanies[i].inflation_rate);
			}

			else if (a == 16) {
				p.ownedCompanies[i].price *= (p.ownedCompanies[i].deflation_rate * 0.6);
			}

			else if (a == 17) {
				p.ownedCompanies[i].price *= (p.ownedCompanies[i].inflation_rate * 1.03);
			}

			else if (a == 18) {
				p.ownedCompanies[i].price *= (p.ownedCompanies[i].deflation_rate * 0.44);
			}

			else if (a == 19) {
				p.ownedCompanies[i].price *= (p.ownedCompanies[i].inflation_rate * 1.66);
			}

			else {
				p.ownedCompanies[i].price *= (p.ownedCompanies[i].inflation_rate * 1.93);
			}
		}
	}
}

void fitInventory(Player p) {
	cout << endl << p.player_username << "'s Fit Inventory:" << endl;
	unsigned int i;
	unsigned int vec_size = p.ownedCompanies.size();

	if (vec_size == 0) {
		cout << "You do not currently own any fits." << endl;
	}

	else {
		for (i = 0; i < vec_size; i++) {
			cout << p.ownedCompanies[i].company_name << " " << "(" << p.ownedCompanies[i].abbreviation << ")" << " " << "$" << fixed << setprecision(2) << p.ownedCompanies[i].price << endl;
	}
	}
	
	return;
}

void displayStats(Player p) {
	cout << endl << p.player_username << "'s Statistics:" << endl;
	unsigned int vec_size = p.ownedCompanies.size();
	cout << "Net worth: $" << fixed << setprecision(2) << p.net_worth << endl;
	cout << "Spendable cash: $" << fixed << setprecision(2) << p.profit_margin << endl;
	cout << "Total fits owned: " << vec_size << " fits" << endl;
}

void purchaseFit(Player& player, Company& pC) {
	string user_input;

	if (pC.canPurchase == true) {
		player.profit_margin -= pC.price;
		player.ownedCompanies.push_back(pC);
		cout << endl << pC.company_name << " (" << pC.abbreviation << ")" << " has been purchased for a price of " << fixed << setprecision(2) << "$" << pC.price << "." << endl;
		pC.purchase_price = pC.price;
		pC.playerOwned = true;
		sleep(800);
		return;
	}

	else {
		cout << "This fit cannot be purchased." << endl;
		return;
	}
}

double netWorthCalc(Player& player) {
	int vec_size = player.ownedCompanies.size();
	unsigned int i;
	double netWorth = player.profit_margin;

	for (i = 0; i < vec_size; i++) {
		netWorth += player.ownedCompanies[i].price;
	}

	return netWorth;
}

double spendableMoney(Player& player) {
	int vec_size = player.ownedCompanies.size();
	double totalProfitITE;
	double currentSpendable = player.profit_margin;
	unsigned int i;
	
	for (i = 0; i < vec_size; i++) {
		totalProfitITE = player.ownedCompanies[i].price - player.ownedCompanies[i].purchase_price;

		currentSpendable += totalProfitITE;
	}

	currentSpendable = player.profit_margin;
	return currentSpendable;
}