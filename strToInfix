#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> strToInfix(string& inputString) {
    vector<string> ekspresi;
    string angka = "";
    int panjang = inputString.length();

    for (int i = 0; i < panjang; ++i) {
        char now = inputString[i];


        if (isdigit(now) || (now == '-' && (i == 0 || inputString[i - 1] == '('))) {
            angka += now;
            while (i + 1 < panjang && isdigit(inputString[i + 1])) {
                angka += inputString[++i];
            }
            ekspresi.push_back(angka);
            angka = "";
        } else if (now == '+' || now == '-' || now == '*' ||
                   now == '/' || now == '%' || now == '(' || now == ')') {
            ekspresi.push_back(string(1, now));
        }
    }
    return ekspresi;
}

vector<string> negatif(vector<string>& ekspresi) {
    vector<string> hasil;
    int panjang = ekspresi.size();

    for (int i = 0; i < panjang; ++i) {
        if (ekspresi[i] == "-" && (i == 0 || ekspresi[i - 1] == "(" || 
                                   ekspresi[i - 1] == "+" || ekspresi[i - 1] == "-" || 
                                   ekspresi[i - 1] == "*" || ekspresi[i - 1] == "/" || 
                                   ekspresi[i - 1] == "%")) {
            hasil.push_back("-1");
            hasil.push_back("*");
        } else {
            hasil.push_back(ekspresi[i]);
        }
    }

    return hasil;
}


void printEkspr(vector<string>& ekspresi) {
    for (auto& token : ekspresi) {
        cout << token << " ";
    }
    cout << endl;
}

int main() {
    string inputString;
    getline(cin, inputString);

    vector<string> ekspresi = strToInfix(inputString);
    vector<string> ekspresiAkhir = negatif(ekspresi);
    printEkspr(ekspresiAkhir);

    return 0;
}
