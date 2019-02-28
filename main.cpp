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

typedef struct Node {
    string name; // "0", "1", "2 3", "4"
    vector<string> tags;
    vector<pair<int, int> > edges;
}Node;

int calcEdgeValue(Node node1, Node node2){
    return 0;
}

int main(){

    return 0;
}