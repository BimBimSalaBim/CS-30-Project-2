#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;


void ThreeDay(vector<vector<string>> &a, int d) {
	vector<vector<string>> days;
	//put all the price changes into one vector for ease of access
	for (int i = 0; i < a.size(); i++) {
		if (a[i].size() == 2) {
			days.push_back(a[i]);
		}
	}
	vector<vector<string>> trades;
	for (int i = 0; i < a.size(); i++) {
		if (a[i].size() > 2) {
			trades.push_back(a[i]);
		}
	}
	//check if the stock was baught within 3 days of a price increase
	for (int l = 0; l < days.size(); l++) {
		for (int i = 0; i < trades.size(); i++) {
			int daysBefore = stoi(trades[i][0]) - stoi(days[l][0]);
			int daysAfter = stoi(days[l][0]) - stoi(trades[i][0]);
			if (0 <= daysBefore && daysBefore <= 3 || 0 <= daysAfter && daysAfter <= 3) {
				cout << trades[i][0] << "   ----   " << trades[i][1] << "   ----   " << days[l][0] << " ++++ " << daysAfter << " ++++ " << daysBefore << endl;
				if (daysBefore > 0) {
					//check the prev if it is a sell
				}
			}
		}
	}



	//if (d == 3) {
	//
	//	// get all from past 3 and next 3

	//}
	//else if (d == 0) {
	//	//get 0-3
	//}


	//for (int q = 0; q < a.size(); q++)
	//{
	//	for (int k = 0; k < a[q].size(); k++)
	//	{
	//		cout << a[q][k] << endl;
	//	}
	//}


}

vector<string> findPotentialBadTraders(vector<string> &s) {
	vector <vector<string>> a;

	for (int i = 0; i < s.size(); i++) {
		string line = s[i];
		vector<string> word;
		int EOL = 0;
		int place = 0;
		string splitter = "|";

		// itterate through each char of the lin
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
	
	ThreeDay(a, 3);

	//for (int q = 0; q < a.size(); q++)
	//{
	//	for (int k = 0; k < a[q].size(); k++)
	//	{
	//		cout << a[q][k] << endl;
	//	}
	//}

	return s;
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