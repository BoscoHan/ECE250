#include <string>
#include <sstream>
#include <vector>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

class DisjointSet {
private:
    int V, E;

public:
    struct node {
        int parent;
        int rank;
    };
    struct Edge {
        int src;
        int dst;
        int weight;
    };
    
    vector<node> dsuf;
    vector<Edge> adjList;

    // maps encoded "src+dest" as key to weight
    // map<string, int> map; 

    DisjointSet (int vertices) {
        this->V = vertices;
        dsuf.clear();
        adjList.clear();

        dsuf.resize(vertices);
        for (int i = 0; i < vertices; i++) {
            dsuf[i].parent = -1;
            dsuf[i].rank = 0;
        }
            
    }

    int getV() {
        return V;
    }

    int getE() {
        return V;
    }

    // void buildMap(int from, int to, int weight) {
    //     Edge edge;
    //     edge.src = from;
    //     edge.dst = to;
    //     edge.weight = weight;

    //     string key = to_string(from) + "|" + to_string(to);
    //     map[key] = weight; //replace if already exists
    // }

    void kruskal () {
        //sort on increasing weight
        sort(adjList.begin(), adjList.end(), [](const Edge& e1, const Edge& e2) {
            return e1.weight < e2.weight;
        });



    }

    int find(int v)
    {
        if(dsuf[v].parent==-1)
            return v;
        return dsuf[v].parent=find(dsuf[v].parent);	//using path compression
    }

    void addWeightedEdge (int from, int to, int weight) {
        Edge edge;
        edge.src = from;
        edge.dst = to;
        edge.weight = weight;

        adjList.push_back(edge);
        E++;
    }
    
    void printDsuf() {
        for (auto n : dsuf) 
            cout << n.parent << " " << n.rank <<endl;
    }

    void printAdjList() {
        for (auto e : adjList) 
            cout << e.src <<"-"<< e.dst <<":"<< e.weight <<endl;
    }
    
    // void printMap() {
    //     for (auto const& entry : map)
    //     {
    //         std::cout << entry.first  // key
    //                 << ':' 
    //                 << entry.second // value
    //                 << std::endl ;
    //     }
    // }
};