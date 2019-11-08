#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

vector<string> findPotentialBadTraders(vector<string> &s) {
	vector <vector<string>> a;
	for (int i = 0; i < s.size(); i++) {
		string line = s[i];
		vector<string> word;
		int EOL = 0;
		int place = 0;
		string splitter = "|";
		for (int j = 0; j < s[i].length(); j++) {
			if (string(1,line[j]) == splitter) {
				word.push_back(line.substr(EOL,j-EOL));
				EOL = j + 1;
				place++;
			}
			if (place == 3 || (line.length() < 5 && place == 1))
				word.push_back(line.substr(EOL));
		}
		
		a.push_back(word);
		
	}
	
	cout << a[1][1] << endl;

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