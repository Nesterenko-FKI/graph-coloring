#include <iostream>
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Parser {
    
private:
    string filename;
    ifstream fin;
    
public:
    vector <vector <int>> Graph;
    int V;
    int E;
    Parser(const string& path) {
        fin.open(path);
        if (!fin.is_open()) {
            cout<<"error!"<<endl;
        }
        else {
            string str;
            fin >> str;
            V = stoi(str);
            fin >> str;
            E = stoi(str);
            for(int i = 0; i < E; i++) {
                Graph.push_back(vector<int>());
                for(int j = 0; j < 2; j++) {
                    str = "";
                    fin >> str;
                    Graph.back().push_back(stoi(str));
                }
            }
        }
        fin.close();
    };
};