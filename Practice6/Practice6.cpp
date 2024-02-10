// Practice6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstring>
#include <cctype> // Для функции isdigit() и isalpha()

char* removeEvenWords(char* input) {
    char* context;
    char* word = strtok_s(input, " ,.*:/#", &context);
    int count = 0;
    char result[1000] = "";

    while (word != NULL) {
        bool hasDigits = false;
        bool hasNonAlpha = false;
        for (int i = 0; word[i] != '\0'; ++i) {
            if (isdigit(word[i])) {
                hasDigits = true;
                break;
            }
            else if (!isalpha(word[i])) {
                hasNonAlpha = true;
                break;
            }
        }
        if (!hasDigits && !hasNonAlpha && count % 2 == 0) {
            strcat_s(result, sizeof(result), word);
            strcat_s(result, sizeof(result), " ");
        }
        word = strtok_s(NULL, " ,.*:/#", &context);
        count++;
    }
    char* finalResult = new char[strlen(result) + 1];
    strcpy_s(finalResult, strlen(result) + 1, result);
    return finalResult;
}

int main() {
    setlocale(LC_ALL, "Russian");
    char input[1000];
    std::cout << "Введите строку: ";
    gets_s(input);
    char* result = removeEvenWords(input);
    std::cout << "Результат: " << result << std::endl;
    delete[] result;
    return 0;
}
