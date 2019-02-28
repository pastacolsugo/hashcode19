#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <time.h>
#include <stdlib.h>

using namespace std;

struct Image {
	int index;
	bool isVertical;
	vector <string> tags;
};

struct Slide {
	bool isSingle;
	Image first, second;
}

vector <Image> solution;

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
			cin >> images[i].tags[j];
		}
	}

	for (int i = 0; i < n; i++) {
		if (images[i].isVertical) {
			continue;
		}

		if (rand()%2) {
			solution.push_back(images[i]);
		}
	}

	vector <Image> vertical;

	for (int i = 0; i < n; i++) {
		if (images[i].isVertical && rand()%2) {
			vertical.push_back(images[i]);
		}
	}

	if (vertical.size() % 2 == 1) {
		vertical.pop_back();
	}

	random_shuffle(vertical.begin(), vertical.end());

	vector <Slide> verticalSlide(vertical.size()/2);

	for (int i = 0; i < vertical.size(); i += 2) {
		verticalSlide[i].first
	}
}