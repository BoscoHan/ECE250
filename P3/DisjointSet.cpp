#include <string>
#include <stdlib.h> 
#include <vector>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <list>
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
        double weight;
    };

    vector<node> dsuf; //disjoinSet unionfind holds the parents and ranks of all vertices, for easy manipulation
    list<int> *adjList;  // this list won't hold weights, although the edge it holds is in sync with adjEdgeList, its sole purpose is for easy DFS/BFS
    vector<Edge> adjEdgeList;
    vector<Edge> mst; //holds the min spanning tree

    DisjointSet (int vertices) {
        this->V = vertices;
        this->E = 0;
        dsuf.clear();
        adjEdgeList.clear();
        adjList = new list<int>[vertices]; 

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
        return E;
    }

    void kruskal () {
        //sort on increasing weight
        sort(adjEdgeList.begin(), adjEdgeList.end(), [](const Edge& e1, const Edge& e2) {
            return e1.weight < e2.weight;
        });

        int vertices = 0, edges = 0;
        //need at least V-1 edges to form MST
        while (vertices < V-1 && edges < E) {
            /*union find*/
            //find absolute parent of src and destination           
            int absSrc = find(adjEdgeList[edges].src);
            int absDest = find(adjEdgeList[edges].dst);
            //if absSrc!=absDest, then src and dest are guranteed to be in diff sets, thus I can add edge from src->dest, by calling union
            //if absSrc==absDest, they're in the same set, adding an edge will form cycle
            if (absSrc == absDest) {
                edges++;
                continue;
            }

            union_set(absSrc, absDest);
            mst.push_back(adjEdgeList[edges]); //append edge to mst list
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

    /*BFS to see if we can get to every vertex, used to see if graph is 1 tree or a forest*/
    void BFS(int v, vector<bool> &visited) {       
        list<int> queue;
        //assume graph has at least one vertex of 0
        visited[0] = true; 
        queue.push_back(0);

        list<int>::iterator i; 

        while (!queue.empty()) {
            int curr = queue.front();
            queue.pop_front(); 

            for (i = adjList[curr].begin(); i != adjList[curr].end(); ++i) 
            { 
                if (!visited[*i]) 
                { 
                    visited[*i] = true; 
                    queue.push_back(*i); 
                } 
            } 
        }
    }

    void addWeightedEdge (int from, int to, double weight) {
        Edge edge;
        edge.src = from;
        edge.dst = to;
        edge.weight = weight;
        adjEdgeList.push_back(edge);

        //interpret as directed graph where edge goes to both directions
        adjList[from].push_back(to);
        adjList[to].push_back(from);
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

    void clearGraph () {
        this->E = 0; //vertices still exist
        vector<Edge>().swap(adjEdgeList);
        adjList->clear();
    }

    bool deleteEdge (int from, int to) {
        //delete from both adjList and adjEdgeLists
        //I'm treating these edges like directed edges, thus we must add an edge going both directions:
        adjList[from].remove(to); //remove specific value
        adjList[to].remove(from);

        auto old_size = adjEdgeList.size();

        auto new_end = adjEdgeList.erase(std::remove_if( adjEdgeList.begin(), adjEdgeList.end(),
            [&from, &to](const Edge& e) { 
                return (from == e.src && to == e.dst) || (from == e.dst && to == e.src);      
            }), adjEdgeList.end());

        adjEdgeList.erase(new_end, adjEdgeList.end()); //actually erasing them here: removeIf doesn't erase elements
        
        //check if adjEdgeList's size changed after deleting
        auto new_size = adjEdgeList.size();
        int deletions = old_size - new_size;
        
        this->E -= deletions;
        return deletions > 0;
    }

    //count all the edge weights from the mst list
    double getMSTWeight(vector<Edge> &list) {
        double weight = 0.0;
        for (auto e : list) 
            weight += e.weight;
        return weight;
    }  

    //by the nature of my Edge class, gotta check for cases where v is a src or a dst
    int degreeOfVertex(int v) {
        int degree = 0;
        for (auto e : adjEdgeList) {
            if (e.src == v || e.dst == v)
                degree++;
        }
        return degree;
    }  
};