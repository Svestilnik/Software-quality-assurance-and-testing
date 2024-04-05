#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>

using namespace std;

// Функція для генерування випадкового символу з заданого набору
char getRandomChar(bool useUpperCase, bool useDigits, bool useSpecialChars) {
    const string upperCaseChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string lowerCaseChars = "abcdefghijklmnopqrstuvwxyz";
    const string digits = "0123456789";
    const string specialChars = "!@#$%^&*()-_=+";

    string allChars = lowerCaseChars;
    if (useUpperCase)
        allChars += upperCaseChars;
    if (useDigits)
        allChars += digits;
    if (useSpecialChars)
        allChars += specialChars;

    return allChars[rand() % allChars.length()];
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Встановлення seed для генератора випадкових чисел
    srand(time(0));

    // Введення параметрів від користувача
    int length;
    bool useUpperCase, useDigits, useSpecialChars;

    cout << "Введіть довжину паролю: ";
    cin >> length;

    cout << "Використовувати великі літери? (Так/Ні): ";
    string upperCaseChoice;
    cin >> upperCaseChoice;
    useUpperCase = (upperCaseChoice == "Так");

    cout << "Використовувати цифри? (Так/Ні): ";
    string digitsChoice;
    cin >> digitsChoice;
    useDigits = (digitsChoice == "Так");

    cout << "Використовувати спеціальні знаки? (Так/Ні): ";
    string specialCharsChoice;
    cin >> specialCharsChoice;
    useSpecialChars = (specialCharsChoice == "Так");

    // Генерація паролю
    string password;
    for (int i = 0; i < length; ++i) {
        password += getRandomChar(useUpperCase, useDigits, useSpecialChars);
    }

    // Виведення результату на екран
    cout << "Згенерований пароль: " << password << endl;

    // Запис результату у файл за бажанням користувача
    cout << "Бажаєте зберегти пароль у файл? (Так/Ні): ";
    string saveToFileChoice;
    cin >> saveToFileChoice;
    if (saveToFileChoice == "Так") {
        string filename;
        cout << "Введіть назву файлу: ";
        cin >> filename;

        ofstream file(filename);
        if (file.is_open()) {
            file << password << endl;
            cout << "Пароль успішно збережено у файл " << filename << endl;
            file.close();
        }
        else {
            cout << "Помилка: не вдалося відкрити файл для запису." << endl;
        }
    }

    return 0;
}
