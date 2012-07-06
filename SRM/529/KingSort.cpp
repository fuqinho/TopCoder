#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define dump(x)  cerr << #x << " = " << (x) << endl;

class Container {
public:
    string name;
    int number;
    Container(string name, int number) : name(name), number(number) {}
};

class LessContainer {
public:
    bool operator()(const Container& lhs, const Container& rhs) const {
        return lhs.name < rhs.name || (lhs.name == rhs.name && lhs.number < rhs.number);
    }
};
    
class KingSort {
public:
    vector <string> getSortedList(vector <string> kings) {
        vector<string> numeral(51);
        for (int i = 1; i <= 50; i++) {
            string temp = "";
            switch (i / 10) {
                case 1: temp += "X"; break;
                case 2: temp += "XX"; break;
                case 3: temp += "XXX"; break;
                case 4: temp += "XL"; break;
                case 5: temp += "L"; break;
                default: break;
            }
            switch (i % 10) {
                case 1: temp += "I"; break;
                case 2: temp += "II"; break;
                case 3: temp += "III"; break;
                case 4: temp += "IV"; break;
                case 5: temp += "V"; break;
                case 6: temp += "VI"; break;
                case 7: temp += "VII"; break;
                case 8: temp += "VIII"; break;
                case 9: temp += "IX"; break;
                default: break;
            }
            numeral[i] = temp;
        }

        vector<Container> containers;
        for (int i = 0; i < kings.size(); i++) {
            int spacePos = kings[i].find(' ');
            string name = kings[i].substr(0, spacePos);
            string numer = kings[i].substr(spacePos+1);
            int number = 0;
            for (int j = 1; j <= 50; j++) if(numeral[j] == numer) number = j;
            Container cnt(name, number);
            containers.push_back(cnt);
        }
        sort(containers.begin(), containers.end(), LessContainer());

        vector <string> res;
        for (int i = 0; i < containers.size(); i++) {
            res.push_back(containers[i].name + " " + numeral[containers[i].number]);
        }

        return res;
    }
};



// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
