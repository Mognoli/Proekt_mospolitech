#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <iostream>
#include <iterator>
#include <cstring>
#include <math.h>
#include <random>
#include <map>
#include <list>
#include <set>

class Task5 {

    private:
        std::string f;
        int n;
        std::vector<std::string> sdnf;
        std::vector<std::string> sknf;
        std::vector<std::string> monoms;
        std::vector<std::string> matrixSet;
        std::vector<std::string> polinom;
        std::vector<std::vector<int>> table;
        std::vector<std::vector<std::string>> groups;
        std::set<std::set<std::string>> answer;

    public:
        Task5(std::string func);
        Task5(const Task5& copy);
        ~Task5();

        void generateTask(const int n);
        void solveTask();
        void assignAndPrintPolinom();
        std::set<std::set<std::string>> getAnswer();

    private:
        void calcSdnfSknf();
        void setBuilder();
        std::string toMonom(const std::string str);
        void monomsBuilder();
        void reduce();
        void tableBuilder();
        void groupsBuilder();
        void printTable();
        void polinomBuilder();
        void eraseEmpty(std::vector<std::string>& res);
        std::vector<std::string> multiplyGroups(const std::vector<std::string> groups, const std::vector<std::string> group2);
};