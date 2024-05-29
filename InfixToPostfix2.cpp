#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

vector<string> strToInfix(string &inputString)
{
    vector<string> ekspresi;
    string angka = "";
    int panjang = inputString.length();

    for (int i = 0; i < panjang; i++)
    {
        char now = inputString[i];

        if ((now >= '0' && now <= '9') || (now == '-' && (i == 0 || inputString[i - 1] == '(')))
        {
            angka += now;
            while (i + 1 < panjang && inputString[i + 1] >= '0' && inputString[i + 1] <= '9')
            {
                angka += inputString[++i];
            }
            ekspresi.push_back(angka);
            angka = "";
        }
        else if (now == '+' || now == '-' || now == '*' || now == '/' || now == '%' || now == '(' || now == ')')
        {
            ekspresi.push_back(string(1, now));
        }
    }
    return ekspresi;
}

vector<string> negatif(vector<string> &ekspresi)
{
    vector<string> hasil;
    int panjang = ekspresi.size();

    for (int i = 0; i < panjang; i++)
    {
        if (ekspresi[i] == "-" && (i == 0 || ekspresi[i - 1] == "(" || ekspresi[i - 1] == "+" || ekspresi[i - 1] == "-" || ekspresi[i - 1] == "*" || ekspresi[i - 1] == "/" || ekspresi[i - 1] == "%"))
        {
            hasil.push_back("-1");
            hasil.push_back("*");
        }
        else
        {
            hasil.push_back(ekspresi[i]);
        }
    }
    return hasil;
}

int prioritas(string op)
{
    if (op == "+" || op == "-")
        return 1;
    if (op == "*" || op == "/")
        return 2;
    return 0;
}

vector<string> infixToPostfix(vector<string> &infixArray)
{
    vector<string> postfix;
    stack<string> stackOperator;

    for (auto &token : infixArray)
    {
        if ((token[0] >= '0' && token[0] <= '9') || (token[0] == '-' && token.length() > 1))
        {
            postfix.push_back(token);
        }
        else if (token == "(")
        {
            stackOperator.push(token);
        }
        else if (token == ")")
        {
            while (!stackOperator.empty() && stackOperator.top() != "(")
            {
                postfix.push_back(stackOperator.top());
                stackOperator.pop();
            }
            stackOperator.pop();
        }
        else
        {
            while (!stackOperator.empty() && prioritas(stackOperator.top()) >= prioritas(token))
            {
                postfix.push_back(stackOperator.top());
                stackOperator.pop();
            }
            stackOperator.push(token);
        }
    }
    while (!stackOperator.empty())
    {
        postfix.push_back(stackOperator.top());
        stackOperator.pop();
    }
    return postfix;
}

void printEkspr(vector<string> &ekspresi)
{
    for (auto &token : ekspresi)
    {
        cout << token << " ";
    }
    cout << endl;
}

int main()
{
    string inputString;
    getline(cin, inputString);

    vector<string> ekspresi = strToInfix(inputString);
    vector<string> ekspresiAkhir = negatif(ekspresi);
    vector<string> ekspresiPostfix = infixToPostfix(ekspresiAkhir);

    printEkspr(ekspresiPostfix);

    return 0;
}