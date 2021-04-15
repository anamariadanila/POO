#include<queue>
#include<string>
#include<map>
#include<iostream>
#include<fstream>

using namespace std;

class Compare {
public:
	bool operator()(const std::pair<std::string, unsigned int>& a, const std::pair<std::string, unsigned int>& b) {
		if (a.second != b.second) {
			return a.second < b.second;
		}
		return a.first > b.first;
	}
};
int main()
{
	ifstream fin("Text.txt");

	string sentence;
	getline(fin, sentence);
	string separators = " .,!?";
	size_t begin;
	size_t position = 0;

	map<string, int> counter;
	while ((begin = sentence.find_first_not_of(separators, position)) != string::npos) {

		position = sentence.find_first_of(separators, begin + 1);
		string word = sentence.substr(begin, position - begin);
		transform(word.begin(), word.end(), word.begin(), ::tolower);
		counter[word]++;
	}

	priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> queueWord;
	map<string, int>::iterator it;
	for (it = counter.begin(); it != counter.end(); it++) {
		queueWord.push(make_pair(it->first, it->second));
	}

	while (queueWord.empty() == false) {
		pair<string, int>top = queueWord.top();
		cout << top.first << " : " << top.second;
		cout << "\n";
		queueWord.pop();

	}



}