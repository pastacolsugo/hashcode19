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

vector<vector<pair, pair> > graph;

struct Image {
    int index;
    bool isVertical;
    unordered_set <string> tags;
};

typedef struct Node {
    vector<int> name; // "0", "1", "2 3", "4"
    unordered_set<string> tags;
    priority_queue<pair<int, int> > edges; //edgeValue, to
    int links;
}Node;

int calcEdgeValue(Node node1, Node node2){
    int commons = 0, node2t = 0, node1t = 0;
    for(string s : node2.tags) {
    	if(node1.tags.find(s) != node1.tags.end()) {
    		commons++;
    	} else {
    		node2t++;
    	}
    }
    node1t = node1.tags.size() - commons;

    if(node1t < commons) {
    	if(node1t < node2t) {
    		return node1t;
    	} else {
    		return node2t;
    	}
    } else {
    	if(commons < node2t) {
    		return commons;
    	} else {
    		return node2t;
    	}
    }
}

vector<Image> input(){
    int n;

    cin >> n;

    vector<Image> images(n);

    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        cin >> orientation;
        cin >> nTag;

        images[i].index = i;
        images[i].isVertical = (orientation == 'V');
        
        for (int j = 0; j < nTag; j++) {
            string tag;
            cin >> tag;
            images[i].tags.insert(tag);
        }
    }
    return images;
}

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

int main(){

    /*input*/
    vector<Image> inp = input();
    vector<Image> vert;
    vector<Image> oriz;
    for(auto i : inp){
        if(i.isVertical()){
            vert.push_back(i);
        } else {
            oriz.push_back(i);
        }
    }

    vector<Node> allOriz = pairVerticalImages(vert);
    for(auto i : oriz) allOriz.push_back({{i.index}, i.tags, {}, 0});

    graph.resize(allOriz.size());
    vector<pair<int, pair<int, int> > >edges; // weight, {from, to}
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int edgeValue = calcEdgeValue(allOriz[i], allOriz[j]);
            graph[i].edges.push_back({edgeValue, j});
            graph[j].edges.push_back({edgeValue, i});
            edges.push_back({edgeValue, {i, j}});
        }
    }
    sort(edges.rbegin(), edges.rend());

    int nVisited = 0;
    int currNode = 0;
    unordered_set<int> visited;
    vector<int> solution;
    int solWeight;


    while(nVisited < allOriz.size()){
        nVisited++;
        visited.insert(currNode);
        solution.push_back(currNode);

        while(visited.find(allOriz[currNode].edges.top().second) != visited.end()){
            allOriz[currNode].edges.pop();
        }

        currNode = allOriz[currNode].edges.top().second;

    }

    cout << solution.size();

    for(auto indNode : solution) {
        for(int name : allOriz[indNode].name){
            cout << name << ' ';
        }
        cout << endl;
    }


    return 0;
}