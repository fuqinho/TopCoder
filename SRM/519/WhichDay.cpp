#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string WEEKDAYS[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

class WhichDay {
public:
    string getDay( vector <string> notOnThisDay ) {
        for (int i = 0; i < 7; i++) {
            vector<string>::iterator pos = find(notOnThisDay.begin(), notOnThisDay.end(), WEEKDAYS[i]);
            if (pos == notOnThisDay.end()) return WEEKDAYS[i];
        }
        return "not fownd";
    }
};



// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
