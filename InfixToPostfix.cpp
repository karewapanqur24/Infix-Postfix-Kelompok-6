#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

vector<string> strToInfix(string& inputString){
    vector<string> ekspresi;
    string angka ="";
    int panjang = inputString.length();
    
    for(int i = 0; i < panjang; i++){
        char now = inputString[i];
        
        if((now >= '0' && now <= '9') || (now == '-' && (i == 0 || inputString[i-1] == '('))){
            angka += now;
            while(i + 1 < panjang && inputString[i + 1] >= '0' && inputString[i + 1] <= '9'){
                angka += inputString[++i];
            }
            ekspresi.push_back(angka);
            angka = "";
        }else if(now == '+' || now == '-' || now == '*' || now == '/' || now == '%' || now == '(' || now == ')'){
            ekspresi.push_back(string(1,now));
        }
    }
    return ekspresi;
}

vector<string> negatif(vector<string>& ekspresi){
    vector<string> hasil;
    int panjang = ekspresi.size();
    
    for(int i = 0; i < panjang; i++){
        if(ekspresi[i] == "-" && (i == 0 || ekspresi [ i - 1] == "(" || ekspresi [i - 1] == "+" || ekspresi [i - 1] == "-" || ekspresi [i - 1] == "*" || ekspresi [i - 1] == "/" || ekspresi [i - 1] == "&")){
            hasil.push_back("-1");
            hasil.push_back("*");
        }else{
            hasil.push_back(ekspresi[i]);
        }
    }
    return hasil;
}

int prioritas(string op){
    if(op == "+" || op == "-") return 1;
    if(op == "*" || op == "/") return 2;
    return 0;
}

int main() {
    
}
