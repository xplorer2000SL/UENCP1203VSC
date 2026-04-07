#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Edge{
        char src, dest;
        int weight;
};

int main (){
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

    map<char, int> vertexIndex;
    int index = 0;
    for (const auto& edge : edgeList) {
        if (vertexIndex.find(edge.src) == vertexIndex.end()){
            vertexIndex[edge.src] = index++;
        }
        if (vertexIndex.find(edge.dest) == vertexIndex.end()) {
            vertexIndex[edge.dest] = index++;
        }

        int n = vertexIndex.size();
        vector<vector<int>> adjMatrix(n, vector<int>(n,0));

        for (const auto& edge : edgeList) {
            int u = vertexIndex[edge.src];
            int v = vertexIndex [ edge.dest];
            adjMatrix[u][v] = edge.weight;
        }

        vector<char> vertices(n);
        for (const auto& pair : vertexIndex){
            vertices[pair.second] = pair.first;
        }

        cout << "";
        for (char vertex : vertices) {
            cout << vertex << "";
        }
        cout << endl;

        for (int i = 0; i < n; ++i){
            cout << vertices[i] << "";
            for (int j = 0; j < n; ++j){
                cout << adjMatrix[i][j] << "";
            }
            cout <<endl;
    }
    return 0;
}