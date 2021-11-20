#ifndef FUNCTIONS_H
#define FUNCTIONS_H

# include <iostream>
# include <string>
# include <math.h>
# include <iomanip>
# include <stdio.h>      
# include <stdlib.h>     
# include <time.h>       
# include <chrono>
# include <thread>
# include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::fixed;
using std::setprecision;
using std::vector;

void sleep(int ms);

void startScreen();

struct Company {
	string company_name;
	string abbreviation;
	int purchase_level;
	double price;
	double profit;
	double purchase_price;
	double inflation_rate;
	double deflation_rate;
	bool canPurchase;
	bool playerOwned;
};

struct Player {
	string player_username;
	string player_password;
	int player_level;
	double net_worth;
	double profit_margin;
	int player_rounds;
	vector <Company> ownedCompanies;
};

string isPurchaseable (Player player, Company& a);

string volatileScale(Company a);

void loadScreen(Player& p, Company a, Company b, Company c, vector <Company> comp);

void fileRead(string filename);

void enterInfo(Player player);

void purchaseFit(Player& player, Company& a);

void fitInventory(Player p);

void displayStats(Player p);

double spendableMoney(Player& player);

double netWorthCalc(Player& player);

void randomizeFits(Player p, int& a, int& b, int&c);

void fitTrends(Player& p, vector <Company>& comp);

/*struct Company {
	string company_name;
	string abbreviation;
	int id;
	int purchase_level;
	double price;
	double inflation_rate;
	double deflation_rate;
	std::regex("^.*(,.*)*$");
};

*/

#endif