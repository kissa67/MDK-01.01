#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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

    if (word.size() > 20) {
        cout << "ERROR: слово слишком длинное\n";
        return;
    }

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
    cout << "Введите n: ";

    int n;
    cin >> n;

    if (n <= 0 || n > 20000) {
        cout << "NO: n должно быть от 1 до 20000\n";
        return;
    }

    vector<int> a(n);
    cout << "Введите " << n << " чисел: ";
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        if (a[i] < 1 || a[i] > n) {
            cout << "NO: числа должны быть от 1 до " << n << "\n";
            return;
        }
    }

    vector<int> check(n + 1, 0);
    for (int i = 0; i < n; i++) check[a[i]]++;

    for (int i = 1; i <= n; i++) {
        if (check[i] != 1) {
            cout << "NO: числа должны быть уникальными\n";
            return;
        }
    }

    vector<int> b(n, 0);
    for (int i = 0; i < n; i++) {
        b[a[i] - 1] = i + 1;
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) cout << b[i] << " ";
    cout << "\n";
}

void zadanie4()
{
    cout << "ЗАДАНИЕ 4: СОРТИРОВКА ПО УБЫВАНИЮ\n";
    cout << "Введите количество строк: ";

    int n;
    cin >> n;

    if (n <= 0 || n > 1000) {
        cout << "ERROR: n должно быть от 1 до 1000\n";
        cin.ignore(); 
        return;
    }

    cin.ignore(); 

    vector<string> lines;
    string line;

    for (int i = 0; i < n; i++) {
        getline(cin, line);

        if (line.size() > 100) {
            cout << "ERROR: строка слишком длинная\n";
            return;
        }

        lines.push_back(line);
    }

    sort(lines.begin(), lines.end());
    reverse(lines.begin(), lines.end());

    for (int i = 0; i < lines.size(); i++) {
        cout << lines[i] << "\n";
    }
}

void zadanie5()
{
    cout << "ЗАДАНИЕ 5: ПАЛИНДРОМ\n";
    cout << "Введите строку: ";

    string s;
    getline(cin, s);

    if (s.size() > 100) {
        cout << "ERROR: строка слишком длинная\n";
        return;
    }

    string clean = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ' ') {
            clean += s[i];
        }
    }

    bool is_palindrome = true;
    int len = clean.size();

    for (int i = 0; i < len / 2; i++) {
        if (clean[i] != clean[len - 1 - i]) {
            is_palindrome = false;
            break;
        }
    }

    if (is_palindrome) cout << "YES\n";
    else cout << "NO\n";
}

void zadanie6()
{
    cout << "ЗАДАНИЕ 6: САПЁР\n";
    cout << "Введите n m k: ";

    int n, m, k;
    cin >> n >> m >> k;

    if (n <= 0 || n > 100 || m <= 0 || m > 100 || k < 0 || k > n * m) {
        cout << "ERROR: неверные размеры поля или количество мин\n";
        return;
    }

    vector<vector<int>> field(n, vector<int>(m, 0));

    for (int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;

        if (r < 1 || r > n || c < 1 || c > m) {
            cout << "ERROR: координаты мины вне поля\n";
            return;
        }

        if (field[r - 1][c - 1] == -1) {
            cout << "ERROR: мина уже стоит в этой клетке\n";
            return;
        }

        field[r - 1][c - 1] = -1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j] == -1) continue;

            int count = 0;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    if (di == 0 && dj == 0) continue;
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        if (field[ni][nj] == -1) count++;
                    }
                }
            }
            field[i][j] = count;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j] == -1) cout << "*";
            else cout << field[i][j];
        }
        cout << "\n";
    }
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
    cout << "\n";
    zadanie4();
    cout << "\n";
    zadanie5();
    cout << "\n";
    zadanie6();
    return 0;
}