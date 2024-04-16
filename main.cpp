#include "Solver.cpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    Parser parser("gc_20_1.txt");
    Solver solver(&parser);
    return 0;
}