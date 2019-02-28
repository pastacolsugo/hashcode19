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
	int index;
	bool isVertical;
	unordered_set <string> tags;
};

typedef Slide Image;

vector <Slide> solution;

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

		images[i].index = i;
		images[i].isVertical = (orientation == 'V');
		images[i].tags.resize(nTag);

		for (int j = 0; j < nTag; j++) {
			string tag;
			cin >> tag;
			images[i].tags.insert(tag);
		}
	}

	// adding horizontal slide
	for (int i = 0; i < n; i++) {
		if (images[i].isVertical) {
			continue;
		}

		if (rand()%2) {
			Slide temp;
			temp.isVertical = false;
			temp.first = images[i];	
			solution.push_back(temp);
		}
	}

	vector <Image> vertical;

	// select random vertical images
	for (int i = 0; i < n; i++) {
		if (images[i].isVertical && rand()%2) {
			vertical.push_back(images[i]);
		}
	}

	// check that vertcal is even
	if (vertical.size() % 2 == 1) {
		vertical.pop_back();
	}

	// shuffle vertical
	random_shuffle(vertical.begin(), vertical.end());

	solution.resize(vertical.size() / 2);

	// merge vertical into slides
	for (int i = 0; i < vertical.size(); i += 2) {
		Slide temp = vertical[i];
	}


}