#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

struct Image {
    int index;
    bool isVertical;
    unordered_set <string> tags;
};

typedef struct Node {
    // string name; // "0", "1", "2 3", "4"
	vector <int> name;
    unordered_set <string> tags;
    vector<pair<int, int> > edges;
} Node;

vector <Node> pairVerticalImages (vector <Image> v) {
	if (v.size() % 2 == 1) {
		v.pop_back();
	}

	random_shuffle(v.begin(), v.end());

	vector <Node> res(v.size() / 2);

	for (int i = 0; i < v.size(); i += 2) {
		res[i].name.push_back(v[i].index);
		res[i].name.push_back(v[i+1].index);

		res[i].tags = v[i].tags;
		res[i].tags.insert(v[i+1].tags.begin(), v[i+1].tags.end());
	}
	return move(res);
}

int main () {
	vector <Image> v(2);
	v[0].index = 0;
	v[0].isVertical = true;
	v[0].tags.insert("banana");
	v[0].tags.insert("gatto");
	// v[0].tags.insert("gobbees");

	v[1].index = 1;
	v[1].isVertical = true;
	v[1].tags.insert("flower");
	v[1].tags.insert("banana");

	vector <Node> solution = pairVerticalImages(v);

	Node sol = solution[0];
	
	cout << "name: ";

	for (int i = 0; i < sol.name.size(); i++) {
		cout << sol.name[i] << ", ";
	}
	cout << endl << "set: ";

	for (auto it = sol.tags.begin(); it != sol.tags.end(); it++) {
		cout << *it << ", ";
	}
	cout << endl;
}