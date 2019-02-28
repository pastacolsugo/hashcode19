#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <time.h>
#include <stdlib.h>
#include <unordered_set>

using namespace std;

struct Image {
	vector <int> index;
	bool isVertical;
	unordered_set <string> tags;
};

typedef Image Slide;

vector <Slide> solution;
vector <Slide> horizontal;
vector <Image> vertical;

int n, k, nTag;
vector <Image> images;
char orientation;

int main() {
	cin >> n;

	images.resize(n);

	srand(time(NULL));

	for (int i = 0; i < n; i++) {
		cin >> orientation;
		cin >> nTag;

		images[i].index.push_back(i);
		images[i].isVertical = (orientation == 'V');

		for (int j = 0; j < nTag; j++) {
			string tag;
			cin >> tag;
			images[i].tags.insert(tag);
		}
	}

	// adding horizontal slide
	for (int i = 0; i < n; i++) {
		if ((not images[i].isVertical) && rand()%10 <= 8) {
			horizontal.push_back(images[i]);
		}
	}

	// select random vertical images
	for (int i = 0; i < n; i++) {
		if (images[i].isVertical && rand()%10 <= 8) {
			vertical.push_back(images[i]);
		}
	}

	if (vertical.size() != 0) {
		// check that vertical is even
		if (vertical.size() % 2 == 1) {
			vertical.pop_back();
		}

		// shuffle vertical
		random_shuffle(vertical.begin(), vertical.end());

		solution.resize(vertical.size() / 2);

		// merge vertical into slides
		for (int i = 0; i < vertical.size(); i += 2) {
			solution[i].tags = vertical[i].tags;
			solution[i].index = vertical[i].index;


			solution[i].tags.insert(vertical[i+1].tags.begin(), vertical[i+1].tags.end());
			solution[i].index.push_back(vertical[i].index[0]);
		}
	}

	int verticalNumber = solution.size();

	solution.resize(solution.size() + horizontal.size());

	for (int i=verticalNumber; i<solution.size(); i++) {
		solution[i] = horizontal[i - verticalNumber];
	}

	random_shuffle(solution.begin(), solution.end());

	cout << solution.size() << endl;

	for (int i = 0; i < solution.size(); i++) {
		cout << solution[i].index[0];

		if (solution[i].index.size() == 2) {
			cout << ' ' << solution[i].index[1];
		}

		cout << endl;
	}

}



