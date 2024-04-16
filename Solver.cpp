#include "Parser.cpp"
#include <iostream>
#include <vector>

using namespace std;

class Solver {
    Parser *parser;
    vector <vector <int>> g;
    vector <int> col;

public:
  Solver (Parser * parser) {
    g.resize(parser->V);
    col.resize(parser->V);
    for(int i = 0; i < parser->E; i++) {
        g[parser->Graph[i][0]].push_back(parser->Graph[i][1]);
        g[parser->Graph[i][1]].push_back(parser->Graph[i][0]);
    }
    col[0] = 0;
    for(int i = 1; i < parser->V; i++) {
        col[i] = -1;
    }
    bool unuse[parser->V];
    for (int i = 0; i < parser->V; i++) {
        unuse[i] = false;
    }
    for (int i = 1; i < parser->V; i++) {
        for (int j = 0; j < g[i].size(); j++) {
            if (col[g[i][j]] != -1) {
                unuse[col[g[i][j]]] = true;
            }
        }
        int curr = 0;
        while(unuse[curr] != false) {
            curr++;
        }
        col[i] = curr;
        for (int j = 0; j < g[i].size(); j++) {
            if (col[g[i][j]] != -1) {
                unuse[col[g[i][j]]] = false;
            }
        }
    }
    for (int i = 0; i < parser->V; i++){
       cout<<col[i]<<" ";
    }
    cout<<endl;
  };
};
