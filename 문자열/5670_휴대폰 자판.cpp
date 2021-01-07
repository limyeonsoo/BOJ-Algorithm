#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Trie {
	bool isEnd;
	int hasNext;
	Trie* next[26];

	Trie() {
		fill(next, next + 26, nullptr);
		isEnd = false;
		hasNext = 0;
	}

	~Trie() {
		for (int i = 0; i < 26; i++) if (next[i]) delete next[i];
	}

	void insert(const char* key) {
		if (*key == '\0') {
			isEnd = true;
			return;
		}
		int curr = *key - 'a';
		if (!next[curr]) {
			next[curr] = new Trie;
			hasNext++;
		}
		next[curr]->insert(key + 1);
	}

	int find(const char* key, int sum) {
		if (*key == '\0') {
			return sum;
		}
		int curr = *key - 'a';

		if (next[curr]->hasNext == 1 && !next[curr]->isEnd) {
			return next[curr]->find(key + 1, sum);
		}
		else {
			return next[curr]->find(key + 1, sum + 1);
		}
	}

};

void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int testCase;
	string word;
	vector <string> words;
	while (cin>>testCase) {
		Trie* root = new Trie;
		words.clear();
		double answer = 0;
		for (int i = 0; i < testCase; i++) {
			cin >> word;
			words.push_back(word);
			root->insert(word.c_str());
		}
		for (auto& word : words) {
			answer += root->find(word.c_str(), 0);
		}
		cout << fixed << setprecision(2) << answer/testCase << '\n';
		delete root;
	}
}
int main() {
	input();
}