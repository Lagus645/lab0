#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
using namespace std;

// Функция для проверки, содержит ли строка только одно слово
bool isSingleWord(const string& line) {
    return line.find(' ') == string::npos; // Если пробел не найден, это одно слово
}

// Функция для поиска самого длинного слова в файле
string findLongestWord(const string& filename) {
    ifstream file(filename);
    string word, longestWord;
    while (file >> word) { // Читаем слова по одному
        if (word.length() > longestWord.length()) {
            longestWord = word;
        }
    }
    return longestWord;
}

int main() {
    setlocale(LC_ALL, "russian");
    // Шаг 1: Чтение из F1 и запись строк с одним словом в F2
    ifstream f1("F1.txt");
    ofstream f2("F2.txt");

    if (!f1.is_open() || !f2.is_open()) {
        cerr << "Ошибка открытия файла!" << endl;
        return 1;
    }

    string line;
    while (getline(f1, line)) {
        if (isSingleWord(line)) {
            f2 << line << endl; // Записываем строку в F2, если она содержит одно слово
        }
    }

    f1.close();
    f2.close();

    // Шаг 2: Поиск самого длинного слова в F2
    string longestWord = findLongestWord("F2.txt");
    cout << "Самое длинное слово в файле F2: " << longestWord << endl;

    return 0;
}