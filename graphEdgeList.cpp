#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Edge{
        char src, dest;
        int weight;
};

int main (){
        vector<char> vertices = {'a','b','c','d'};
        vector<Edge> edges = {
            {'a','b', 7},
            {'a','c', 11},
            {'a','d', 4},
            {'b','a', 6},
            {'b','c', 9},
            {'c','a', 3},
            {'c','d', 5},
            {'d','a', 5},
            {'d','b', -4},
            {'d','c', 9},
        };
        cout << "Edge list Respresentation:" << endl;
        for (const auto edge : edges) {
                cout << edge.src << "->" << edge.dest << " (weight; " << edge.weight << ")" << endl;
                if (&edge != &edges.back()){
                        cout << "," << endl;
                }
        }
        cout << endl;
        return 0;
}