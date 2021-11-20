// # include <iostream>
// # include <string>
// # include <math.h>
// # include <iomanip>
// # include <stdio.h>      
// # include <stdlib.h>    
// # include <time.h>       
// # include <chrono>
// # include <thread>
// # include "functions.h"
// # include <vector>
// # include <regex>
// # include <fstream>
// # include <sstream>
// # include <locale>

// using std::cout;
// using std::cin;
// using std::endl;
// using std::string;
// using std::fixed;
// using std::setprecision;
// using std::vector;
// using std::ifstream;

// void fitTrends(Player& p, vector <Company>& comp) {
// 	// bounds for level 1 companies are comp0>>comp15
// 	int a;
// 	srand(time(NULL));
// 	a = rand() % 20;
// 	unsigned int vec_size;
// 	unsigned int pvec_size = p.ownedCompanies.size();
// 	unsigned int i;

// 	if (p.player_level == 1) {
// 		// only affect the companies to 15
// 		vec_size = 16;
// 		for (i = 0; i < vec_size; i++) {

// 			if (a == 0) {
// 				comp[i].price *= comp[i].inflation_rate;
// 			}

// 			else if (a == 1) {
// 				comp[i].price *= (comp[i].inflation_rate * 1.02);
// 			}

// 			else if (a == 2) {
// 				comp[i].price *= (comp[i].inflation_rate * 1.05);
// 			}

// 			else if (a == 3) {
// 				comp[i].price *= (comp[i].inflation_rate * 1.1);
// 			}

// 			else if (a == 4) {
// 				comp[i].price *= (comp[i].deflation_rate);
// 			}

// 			else if (a == 5) {
// 				comp[i].price *= (comp[i].deflation_rate * 0.95);
// 			}

// 			else if (a == 6) {
// 				comp[i].price *= (comp[i].deflation_rate * 0.90);
// 			}
		
// 			else if (a == 7) {
// 				comp[i].price *= (comp[i].deflation_rate * 0.88);
// 			}

// 			else if (a == 8) {
// 				comp[i].price *= (comp[i].deflation_rate * 0.80);
// 			}

// 			else if (a == 9) {
// 				comp[i].price *= (comp[i].inflation_rate * 1.3);
// 			}

// 			else if (a == 10) {
// 				comp[i].price *= (comp[i].inflation_rate * 1.23);
// 			}

// 			else if (a == 11) {
// 				comp[i].price *= (comp[i].inflation_rate * 1.24);
// 			}

// 			else if (a == 12) {
// 				comp[i].price *= (comp[i].inflation_rate * 1.15);
// 			}

// 			else if (a == 13) {
// 				comp[i].price *= (comp[i].deflation_rate * 0.98);
// 			}

// 			else if (a == 14) {
// 				comp[i].price *= (comp[i].inflation_rate);
// 			}

// 			else if (a == 15) {
// 				comp[i].price *= (comp[i].inflation_rate);
// 			}

// 			else if (a == 16) {
// 				comp[i].price *= (comp[i].deflation_rate * 0.6);
// 			}

// 			else if (a == 17) {
// 				comp[i].price *= (comp[i].inflation_rate * 1.03);
// 			}

// 			else if (a == 18) {
// 				comp[i].price *= (comp[i].deflation_rate * 0.44);
// 			}

// 			else if (a == 19) {
// 				comp[i].price *= (comp[i].inflation_rate * 1.66);
// 			}

// 			else {
// 				comp[i].price *= (comp[i].inflation_rate * 1.93);
// 			}
		
// 		}

// 		// now affect the player owned ones
// 		for (i = 0; i < pvec_size; i++) {
// 			if (a == 0) {
// 				p.ownedCompanies[i].price *= p.ownedCompanies[i].inflation_rate;
// 			}

// 			else if (a == 1) {
// 				p.ownedCompanies[i].price *= (p.ownedCompanies[i].inflation_rate * 1.02);
// 			}

// 			else if (a == 2) {
// 				p.ownedCompanies[i].price *= (p.ownedCompanies[i].inflation_rate * 1.05);
// 			}

// 			else if (a == 3) {
// 				p.ownedCompanies[i].price *= (p.ownedCompanies[i].inflation_rate * 1.1);
// 			}

// 			else if (a == 4) {
// 				p.ownedCompanies[i].price *= (p.ownedCompanies[i].deflation_rate);
// 			}

// 			else if (a == 5) {
// 				p.ownedCompanies[i].price *= (p.ownedCompanies[i].deflation_rate * 0.95);
// 			}

// 			else if (a == 6) {
// 				p.ownedCompanies[i].price *= (p.ownedCompanies[i].deflation_rate * 0.90);
// 			}
		
// 			else if (a == 7) {
// 				p.ownedCompanies[i].price *= (p.ownedCompanies[i].deflation_rate * 0.88);
// 			}

// 			else if (a == 8) {
// 				p.ownedCompanies[i].price *= (p.ownedCompanies[i].deflation_rate * 0.80);
// 			}

// 			else if (a == 9) {
// 				p.ownedCompanies[i].price *= (p.ownedCompanies[i].inflation_rate * 1.3);
// 			}

// 			else if (a == 10) {
// 				p.ownedCompanies[i].price *= (p.ownedCompanies[i].inflation_rate * 1.23);
// 			}

// 			else if (a == 11) {
// 				p.ownedCompanies[i].price *= (p.ownedCompanies[i].inflation_rate * 1.24);
// 			}

// 			else if (a == 12) {
// 				p.ownedCompanies[i].price *= (p.ownedCompanies[i].inflation_rate * 1.15);
// 			}

// 			else if (a == 13) {
// 				p.ownedCompanies[i].price *= (p.ownedCompanies[i].deflation_rate * 0.98);
// 			}

// 			else if (a == 14) {
// 				p.ownedCompanies[i].price *= (p.ownedCompanies[i].inflation_rate);
// 			}

// 			else if (a == 15) {
// 				p.ownedCompanies[i].price *= (p.ownedCompanies[i].inflation_rate);
// 			}

// 			else if (a == 16) {
// 				p.ownedCompanies[i].price *= (p.ownedCompanies[i].deflation_rate * 0.6);
// 			}

// 			else if (a == 17) {
// 				p.ownedCompanies[i].price *= (p.ownedCompanies[i].inflation_rate * 1.03);
// 			}

// 			else if (a == 18) {
// 				p.ownedCompanies[i].price *= (p.ownedCompanies[i].deflation_rate * 0.44);
// 			}

// 			else if (a == 19) {
// 				p.ownedCompanies[i].price *= (p.ownedCompanies[i].inflation_rate * 1.66);
// 			}

// 			else {
// 				p.ownedCompanies[i].price *= (p.ownedCompanies[i].inflation_rate * 1.93);
// 			}
// 		}
// 	}
// }