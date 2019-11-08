#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXRESULTS = 20;    // Max matches that can be found
const int MAXDICTWORDS = 30000; // Max words that can be read in

int loadDictionary(istream &dictfile, vector<string>& dict) {
	//Places each string in dictfile into the vector dict. Returns the number of words loadedinto dict.
	dict.erase(dict.begin(), dict.end());
	string str;
	while (getline(dictfile, str))
		dict.push_back(str);

	return dict.size();
}

int permute(string word, vector<string>& dict, vector<string>& results) {
	//Places all the permutations of word, which are found in dict into results.Returns the number of matched words found.
	int s = dict.size();
	results.erase(results.begin(), results.end());
	for (int i = 0; i < dict.size(); i++) {
		if (word.length() == dict[i].length()) {
			string dictWord = dict[i];
			string inWord = word;
			sort(inWord.begin(), inWord.end());
			sort(dictWord.begin(), dictWord.end());
			if (inWord == dictWord) {
				bool inList = false;
				for (int j = 0; j < results.size(); j++) {
					if (results[j] == dict[i])
						inList = true;
				}
				if (!inList)
					results.push_back(dict[i]);
			}
		}
	}
	return results.size();
}

void display(vector<string>& results) {
	//Displays size number of strings from results.The results can be printed in any order.
	for (int i = 0; i < results.size(); i++) 
		cout << "Matching word " << results[i] << endl;

}

int main()
{
	vector<string> results(MAXRESULTS);
	vector<string> dict(MAXDICTWORDS);
	ifstream dictfile;
	// file containing the list of words
	int nwords;               
	// number of words read from dictionary    
	string word;   
	dictfile.open("words.txt");
	if (!dictfile) {
		cout << "File not found!" << endl;
		return (1);
	}    
	nwords = loadDictionary(dictfile, dict);
	dictfile.close();
	cout << "Please enter a string for an anagram: ";
	cin >> word;    
	int numMatches = permute(word, dict, results);
	if (!numMatches)
		cout << "No matches found" << endl;
	else        
		display(results);
	return 0;

}
