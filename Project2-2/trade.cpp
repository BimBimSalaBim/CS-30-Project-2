#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;


vector<string> ThreeDay( vector<vector<string>> &a) {
	vector<vector<string>> days;
	vector<string> results;

	//put all the price changes into one vector for ease of access
	for (int i = 0; i < a.size(); i++) {
		if (a[i].size() == 2) {
			days.push_back(a[i]);
		}
	}

	//put all the trades into one vector for ease of access
	vector<vector<string>> trades;
	for (int i = 0; i < a.size(); i++) {
		if (a[i].size() > 2) {
			trades.push_back(a[i]);
		}
	}

	//check if the stock was baught within 3 days of a price increase
	for (int l = 0; l < days.size(); l++) {
		for (int i = 0; i < trades.size(); i++) {
			int tradesAfter = stoi(days[l][0]) - stoi(trades[i][0]);
			if (0 <= tradesAfter && tradesAfter <= 3) {
				if (tradesAfter > 0) {

					//check if the trade made goes over the thrushold
					int sell = stoi(trades[i][3]) * (stoi(days[l - 1][1]) - stoi(days[l][1]));
					int buy = stoi(trades[i][3]) * (stoi(days[l][1]) - stoi(days[l - 1][1]));

					//check if profit gained or loss prevented is over the thrushold
					if ((trades[i][2] == "BUY" && buy >= 500000) || (trades[i][2] == "SELL" && sell >= 500000) ){

						// check if the trade is already in the list
						bool isInList = false;
						for (int r = 0; r < results.size(); r++) {
							if (results[r] == trades[i][0]+"|"+trades[i][1]) {
								isInList = true;
								break;
							}
						}

						// if not in list then add it to the list
						if (!isInList) {
							cout << trades[i][1] << " " << sell << endl;;
							results.push_back(trades[i][0] + "|" + trades[i][1]);
						}
					}
				}
			}
		}
	}

	return results;


}

vector<string> findPotentialBadTraders(vector<string> &s) {
	vector <vector<string>> a;

	for (int i = 0; i < s.size(); i++) {
		string line = s[i];
		vector<string> word;
		//End of Last
		int EOL = 0;
		int place = 0;
		string splitter = "|";

		// itterate through each char of the line
		for (int j = 0; j < s[i].length(); j++) {

			//check if the char at i is the same as the deliminator
			if (string(1,line[j]) == splitter) {

				// if it is then add it to vector and move the End of Last word to one more than what it is
				word.push_back(line.substr(EOL,j-EOL));
				EOL = j + 1;
				place++;
			}

			//if there are no more deliminators and then add the last part of the line to the vector
			if (place == 3 || (line.length() < 6 && place == 1)) {
				word.push_back(line.substr(EOL));
				place++;
			}
		}

		//put the words vecto into the 2d vector of a 
		a.push_back(word);
		
	}
	

	return ThreeDay(a);
}


int main() {
	ifstream in("input.txt");
	string str;
	if (!in) {
		cerr << "No input file" << endl;
		exit (0);    
	}    
	vector<string> inputVec;
	while (getline(in,str)) {
		inputVec.push_back(str);
	}   
	vector<string> resV = findPotentialBadTraders(inputVec);
	for (const string& r : resV) {
		cout << r << endl;   
	}   
	return 0;
}