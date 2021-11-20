# include <iostream>
# include <string>
# include <regex>
# include <fstream>     
# include <vector>
# include "functions.h"

using namespace std;

int main () {
	Player player;
	player.player_level = 1;
	player.profit_margin = 300;
	player.player_rounds = 0;
	
	// load file
    vector<Company> cms;

    ifstream file("companylist.txt");
    if (file.is_open()) {
		//	cout << "file open" << endl;
		}
    
    string myText;
    regex re("^.*(,.*)*$");

    while (getline(file, myText)) 
    {
				vector<string> compVec;
        Company company;
        smatch cm;       // same as std::match_results<const char*>
        //cout << myText << endl;

        if (regex_match(myText, cm, re)) 
        {
            // Company Name, Abbreviation, Purchase Level, Price, Inflation Rate, Deflation Rate
						// cout << cm[0] << endl;
						stringstream SS(cm[0]);

						while (SS.good()) {
							
							string input;
							getline(SS, input, ',');
							//cout << input << endl;
							compVec.push_back(input);
						}

						// assigning the company to vector
						company.company_name = compVec[0];
						company.abbreviation = compVec[1];
						company.purchase_level = stoi(compVec[2]);
						company.price = stod(compVec[3]);
						company.profit = stod(compVec[3]);
						company.inflation_rate = stod(compVec[4]);
						company.deflation_rate = stod(compVec[5]);

        }

        cms.push_back(company);
       
    }

		// lebron jameulus
		// now the game begins
		startScreen();
		enterInfo(player);

		sleep(4000);

		/*unsigned int i;
		for (i = 0; i < cms.size(); i++) {
			cout << cms[i].company_name << endl;
		}*/

		loadScreen(player, cms[0], cms[1], cms[2], cms);

		// cms[n].property;

    return 0;
}