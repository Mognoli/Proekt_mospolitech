#include "Task5.h"

using namespace std;
#define OUT true

Task5::Task5(string func) {
    f = func;
    n = 3;
    sdnf = {};
    sknf = {};
    monoms = {};
    matrixSet = {};
    polinom = {};
    table = {};
    groups = {};
}

Task5::Task5(const Task5& copy) {
    f = copy.f;
    n = copy.n;
    sdnf = copy.sdnf;
    sknf = copy.sknf;
    monoms = copy.monoms;
    matrixSet = copy.matrixSet;
    polinom = copy.polinom;
    table = copy.table;
    groups = copy.groups;
}

Task5::~Task5() {
    
}

void Task5::generateTask(const int n) {
    std::random_device rd;
    std::default_random_engine engine(rd());
    std::uniform_int_distribution<int> distr(128, 255);

    this->f = (bitset<8> (distr(engine))).to_string();
    cout << "Function: " << f << endl;
}

void Task5::solveTask() {
    calcSdnfSknf();
    setBuilder();
    monomsBuilder();
    reduce();
    tableBuilder();
    printTable();
    groupsBuilder();

    polinomBuilder();
    assignAndPrintPolinom();
}

void Task5::calcSdnfSknf() { //1
    for (unsigned int i = 0; i < f.length(); i++) {
        if (f[i] == '1') {
            bitset<3> b { i };
            sdnf.push_back(b.to_string());
        } else if (f[i] == '0') {
            bitset<3> b { i };
            string bs = b.to_string(), s;
            for (auto e : bs) {
                s.push_back((e == '1') ? '0' : '1');
            }
            sknf.push_back(s);
        }
    }
}

void Task5::setBuilder() { //2
    int depth = sknf.size();
    vector<string> matrixSet(pow(n, depth), string(depth, '1'));

    for (int i = 1; i < pow(n, depth); i++) {
        bool hasNoN = false;
        matrixSet[i] = matrixSet[i-1];
        for (int j = depth-1; j >= 0; j--) {
            if ((matrixSet[i-1][j]-'0' != n) && !hasNoN) {
                matrixSet[i][j] = to_string(matrixSet[i-1][j]- '0' + 1)[0];
                hasNoN = true;
            }
            else if (!hasNoN && j != depth-1) {
                matrixSet[i][j-1] = to_string(matrixSet[i][j-1] - '0' + 1)[0];
                for (int g = j; g < depth; g++) {
                    matrixSet[i][g] = '1';
                }       
            }
            else if (j == depth-1) matrixSet[i][j] = '1';
        }
        hasNoN = false;
    }

    vector<string> result = {};
    for (int iter = 0; iter < matrixSet.size(); iter++) {
        vector<int> memory(n, -1);
        string s = matrixSet[iter];
        bool valid = true;
        for (int i = 0; i < depth; i++) {
            if (memory[s[i] - '1'] == -1) memory[s[i] - '1'] = sknf[i][s[i] - '1'] - '0';
            else if (memory[s[i] - '1'] != sknf[i][s[i] - '1'] - '0') {
                valid = false;
                break;
            }
        }
        if (valid) result.push_back(s);
    }

    this->matrixSet = result;
}

string Task5::toMonom(const string str) { //3.5
    string res = "xyz";

    for (int i = 0; i < str.length(); i++) {
        for (int j = i + 1; j < str.length(); j++) {
            if (str[i] == str[j]) {
                if (sknf.at(i)[int(str[i] - '0') - 1] != sknf.at(j)[int(str[j] - '0') - 1]) {
                    res[int(str[i] - '0') - 1] = '-';
                }
            }
        }

        if (res[int(str[i] - '0') - 1] != '-') {
            res[int(str[i] - '0') - 1] = sknf.at(i)[int(str[i] - '0') - 1];
        }
    }

    for (int i = 0; i < n; i++) {
        if (res[i] != '0' && res[i] != '1') {
            res[i] = '-';
        }
    }
    return res;
}

void Task5::monomsBuilder() {
    for (auto el : matrixSet) {
        string answer = toMonom(el);
        if (OUT) cout << answer << "\t";
        monoms.push_back(answer);
    }
}

void Task5::eraseEmpty(vector<string>& res) {
    res.erase (
        std::remove_if (
            res.begin(),
            res.end(),
            [](std::string const& s) { return s.find_first_not_of(" \t") == std::string::npos; }
        ),
        res.end()
    );
}

void Task5::reduce() {
    auto compare = [](string a, string b) {
        return count(a.begin(), a.end(), '-') > count(b.begin(), b.end(), '-');
    };

    auto containsPart = [](const string str, const string substr) {
        if (str == substr) return true;
        if ((count(str.begin(), str.end(), '-') == count(substr.begin(), substr.end(), '-')) && str != substr && count(substr.begin(), substr.end(), '-') != 0) return false;
        for (int i = 0; i < str.size(); i++) {
            if ((str[i] != substr[i]) && substr[i] != '-') return false;
        }
        return true;
    };

    sort(monoms.begin(), monoms.end(), compare);
    for (int i = 0; i < monoms.size()-1; i++) {
        string monom = monoms[i];
        for (int j = i+1; j < monoms.size(); j++) {
            if (containsPart(monoms[j], monoms[i])) monoms[j] = "";
        }
    }
    eraseEmpty(monoms);
}

vector<string> Task5::multiplyGroups(const vector<string> groups, const vector<string> group2) {
    auto contains = [](const string str, const string substr) {
    if (substr == "") return false;
    for (auto el : substr) {
        if (str.find(el) == std::string::npos) return false;
    }
    return true;
    };
    
    vector<string> res = {};
    for (int i = 0; i < groups.size(); i++) {
        for (int j = 0; j < group2.size(); j++) {
            res.push_back(groups[i] + group2[j]);
        }
    }

    for (int i = 0; i < res.size(); i++) {
        sort(res[i].begin(), res[i].end());
        string temp = res[i];
        temp.erase(std::unique(temp.begin(), temp.end()), temp.end());
        res[i] = temp;
    }

    sort(res.begin(), res.end(), [](string a, string b) {
        return a.size() < b.size();
    });

    for (int i = 0; i < res.size()-1; i++) {
        for (int j = i + 1; j < res.size(); j++) {
            if (contains(res[j], res[i])) res[j] = "";
        }
    }

    eraseEmpty(res);
    return res;
}

void Task5::tableBuilder() {
    auto containMonom = [](const string monom, const string sdnf) {
    for (int i = 0; i < sdnf.size(); i++) {
        if ((monom[i] != sdnf[i]) && (monom[i] != '-')) {
            return 0;
        }
    }
    return 1;
    };

    int rows = monoms.size(), columns = sdnf.size();
    vector<vector<int>> temptable(rows);                            //          [---------->
    for (int i = 0; i < rows; i++) {                            //  monoms  |
        temptable[i] = vector<int>(columns);                        //          |
    };

    for (int i = 0; i < rows; i++) {                            // rows > monoms
        for (int j = 0; j < columns; j++) {                     // columns > sdnf
            temptable[i][j] = containMonom(monoms[i], sdnf[j]);
        }
    }
    this->table = temptable;
}

void Task5::printTable() {
    int idx = 0;
    cout << endl << "Coverage matrix:" << endl << "\t";
    for (auto el : sdnf) {
        cout << el << "\t";
    }
    cout << endl;

    for (const auto& v : table) {
        cout << monoms[idx] << "\t";
        for (auto i : v) {
            cout << i << "\t";
        }
        cout << endl;
        idx++;
    }
}

void Task5::polinomBuilder() {
    vector<string> res = groups[0];

    for (int i = 1; i < groups.size(); i++) {
        res = multiplyGroups(res, groups[i]);
    }

    polinom = res;
}

void Task5::groupsBuilder() {
    for (int i = 0; i < sdnf.size(); i++) {
        vector<string> temp;
        for (int j = 0; j < monoms.size(); j++) {
            if (table[j][i] == 1) {
                temp.push_back(to_string(j));
            }
        }
        groups.push_back(temp);
    }
}

void Task5::assignAndPrintPolinom() {
    map<int, char> prs;
    prs[0] = 'x';
    prs[1] = 'y';
    prs[2] = 'z';
    map<int, string> nrs;
    nrs[0] = "-x";
    nrs[1] = "-y";
    nrs[2] = "-z";
    string pretty = "";
    for (auto el : polinom) {
        int counter = 0;
        for (auto e : el) {
            // cout << monoms[e-'0'] << '\t';
            string m = monoms[e-'0'];
            
            for (int i = 0; i < m.size(); i++) {
                switch (m[i]) {
                    case '0':
                        // cout << nrs[i];
                        pretty.append(nrs[i]);
                        break;
                    case '1':
                        // cout << prs[i];
                        pretty += prs[i];
                        break;
                    default:
                        break;
                }
            }
            // cout << " v ";
            pretty.append(" v ");
        }
        pretty.erase(pretty.end()-3, pretty.end());
        cout << pretty;
        this->answer.push_back(pretty);
        cout << endl;
    }
}