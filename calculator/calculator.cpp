#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// Функция для вывода справки
void printHelp() {
    cout << "Использование калькулятора:" << endl;
    cout << "  calculator -o <операция> <операнд1> <операнд2> [<операнд3> [<операнд4>]]" << endl;
    cout << "  calculator -operation <операция> <операнд1> <операнд2> [<операнд3> [<операнд4>]]" << endl;
    cout << endl;
    cout << "Поддерживаемые операции:" << endl;
    cout << "  summa      - суммирование всех операндов (от 2 до 4)" << endl;
    cout << "  subtract   - вычитание (из первого операнда всех остальных)" << endl;
    cout << endl;
    cout << "Примеры:" << endl;
    cout << "  calculator -o summa 5 3 2" << endl;
    cout << "  calculator -operation subtract 10 3 2" << endl;
    cout << "  calculator -o summa 1 2 3 4" << endl;
}

// Функция для преобразования строки в число
bool parseNumber(const string& str, int& num) {
    try {
        num = stoi(str);
        return true;
    } catch (const exception& e) {
        return false;
    }
}

// Операция суммирования
int summa(const vector<int>& operands) {
    int result = 0;
    for (int num : operands) {
        result += num;
    }
    return result;
}

// Операция вычитания
int subtract(const vector<int>& operands) {
    if (operands.empty()) return 0;
    
    int result = operands[0];
    for (size_t i = 1; i < operands.size(); ++i) {
        result -= operands[i];
    }
    return result;
}

int main(int argc, char* argv[]) {
    // Если нет параметров - выводим справку
    if (argc == 1) {
        printHelp();
        return 0;
    }

    string operation;
    vector<int> operands;
    bool operationFound = false;

    // Парсинг аргументов командной строки
    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];
        
        if (arg == "-o" || arg == "-operation") {
            if (i + 1 < argc) {
                operation = argv[++i];
                operationFound = true;
            }
        } else {
            int num;
            if (parseNumber(arg, num)) {
                operands.push_back(num);
            } else {
                cerr << "Ошибка: неверный формат числа: " << arg << endl;
                return 1;
            }
        }
    }

    // Проверка наличия операции
    if (!operationFound) {
        cerr << "Ошибка: не указана операция. Используйте -o или -operation" << endl;
        printHelp();
        return 1;
    }

    // Проверка количества операндов
    if (operands.size() < 2 || operands.size() > 4) {
        cerr << "Ошибка: количество операндов должно быть от 2 до 4" << endl;
        printHelp();
        return 1;
    }

    // Выполнение операции
    int result;
    if (operation == "summa") {
        result = summa(operands);
        cout << "Результат суммирования: ";
        for (size_t i = 0; i < operands.size(); ++i) {
            cout << operands[i];
            if (i < operands.size() - 1) cout << " + ";
        }
        cout << " = " << result << endl;
    } else if (operation == "subtract") {
        result = subtract(operands);
        cout << "Результат вычитания: ";
        for (size_t i = 0; i < operands.size(); ++i) {
            cout << operands[i];
            if (i < operands.size() - 1) cout << " - ";
        }
        cout << " = " << result << endl;
    } else {
        cerr << "Ошибка: неизвестная операция: " << operation << endl;
        cout << "Доступные операции: summa, subtract" << endl;
        return 1;
    }

    return 0;
}
