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
    vector<Edge> mst; //holds the min spanning tree

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

        int vertices = 0, edges = 0;
        while (vertices < V-1 && edges < E) {
            /*union find*/
            //find absolute src and destination           
            int absSrc = find(adjList[edges].src);
            int absDest = find(adjList[edges].dst);

            //if absSrc == absDest, they're in the same set, adding an edge will form cycle
            if (absSrc == absDest) {
                edges++;
                continue;
            }

            union_set(absSrc, absDest);
            mst.push_back(adjList[edges]);
            vertices++;
        }        
    }

    int find(int v)
    {
        if(dsuf[v].parent==-1)
            return v;
        return dsuf[v].parent=find(dsuf[v].parent);	//using path compression
    }

    void union_set(int absSrc,int absDest)
    {
        //UNION by RANK
        if(dsuf[absSrc].rank > dsuf[absDest].rank)	//if src has higher rank
            dsuf[absDest].parent = absSrc;

        else if(dsuf[absSrc].rank < dsuf[absDest].rank)	//toP has higher rank
            dsuf[absSrc].parent = absDest;

        else
        {
            //if Both have same rank then anyone can be made as parent
            dsuf[absSrc].parent = absDest;
            dsuf[absDest].rank +=1;	//parent's rank++
        }
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

    void printList(vector<Edge> &list) {
        for (auto e : list) 
            cout << e.src <<"-"<< e.dst <<":"<< e.weight <<endl;
    }
    
};