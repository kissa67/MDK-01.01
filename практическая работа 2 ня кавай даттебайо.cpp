#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;

void zadanie1()
{
    cout << "ЗАДАНИЕ 1: ПАРОЛЬ\n";

    string pass;
    cin >> pass;

    if (pass.size() < 4 || pass.size() > 8) {
        cout << "NO\n";
        return;
    }

    for (int i = 0; i < pass.size(); i++) {
        if (pass[i] < 33 || pass[i] > 126) {
            cout << "NO\n";
            return;
        }
    }

    int lower = 0, upper = 0, digit = 0, other = 0;

    for (int i = 0; i < pass.size(); i++) {
        char c = pass[i];
        if (c >= 'a' && c <= 'z') lower = 1;
        else if (c >= 'A' && c <= 'Z') upper = 1;
        else if (c >= '0' && c <= '9') digit = 1;
        else other = 1;
    }

    int types = lower + upper + digit + other;

    if (types >= 3) cout << "YES\n";
    else cout << "NO\n";
}

void zadanie2()
{
    cout << "ЗАДАНИЕ 2: SOUNDEX\n";

    string word;
    cin >> word;

    string result = "";
    result += toupper(word[0]);

    char prev = '0';

    for (int i = 1; i < word.size(); i++) {
        char c = tolower(word[i]);
        char code = '0';

        if (c == 'b' || c == 'f' || c == 'p' || c == 'v') code = '1';
        else if (c == 'c' || c == 'g' || c == 'j' || c == 'k' ||
            c == 'q' || c == 's' || c == 'x' || c == 'z') code = '2';
        else if (c == 'd' || c == 't') code = '3';
        else if (c == 'l') code = '4';
        else if (c == 'm' || c == 'n') code = '5';
        else if (c == 'r') code = '6';

        if (code == '0') {
            prev = '0';
            continue;
        }

        if (code == prev) continue;

        result += code;
        prev = code;

        if (result.size() == 4) break;
    }

    while (result.size() < 4) result += '0';

    cout << result << "\n";
}

void zadanie3()
{
    cout << "ЗАДАНИЕ 3: ОБРАТНАЯ ПЕРЕСТАНОВКА\n";

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> b(n, 0);

    for (int i = 0; i < n; i++) {
        if (a[i] >= 1 && a[i] <= n) {
            b[a[i] - 1] = i + 1;
        }
    }

    for (int i = 0; i < n; i++) cout << b[i] << " ";
    cout << "\n";
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    zadanie1();
    cout << "\n";
    zadanie2();
    cout << "\n";
    zadanie3();
    return 0;
}