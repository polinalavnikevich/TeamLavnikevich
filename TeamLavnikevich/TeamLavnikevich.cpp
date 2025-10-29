#include "sort_algorithms.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <random>
#include <iomanip>

using namespace std;

void setRussianLocale() {
    setlocale(LC_ALL, "Russian");
}

template<typename T>
void printArray(const vector<T>& arr) {
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << endl;
}

template<typename T>
vector<T> readFromFile(const string& filename) {
    vector<T> result;
    ifstream file(filename);
    T value;
    while (file >> value) {
        result.push_back(value);
    }
    return result;
}

vector<int> generateBigArray(int size) {
    vector<int> result;
    random_device rd;
    result.reserve(size);
    for (int i = 0; i < size; i++) {
        result.push_back(rd() % 10000 + 1);
    }
    return result;
}

template<typename T>
void testWithTime(const vector<T>& testData, const string& testName) {
    cout << "\n=== " << testName << " ===" << endl;
    cout << "Элементов: " << testData.size() << endl;

    if (testData.size() <= 10) {
        cout << "Данные: ";
        printArray(testData);
    }

    // Новые сортировки
    NaturalMergeSort<T> nms;
    ListInsertionSort<T> lis;
    StrandSort<T> ss;
    PolyphaseMergeSort<T> pms;

    SortAlgorithm<T>* algorithms[] = { &nms, &lis, &ss, &pms };
    string names[] = {
        "Natural Merge Sort",
        "List Insertion Sort",
        "Strand Sort",
        "Polyphase Merge Sort"
    };

    for (int i = 0; i < 4; i++) {
        vector<T> dataCopy = testData;

        auto start = chrono::high_resolution_clock::now();
        algorithms[i]->sort(dataCopy);
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double> total_time = end - start;
        double microseconds = total_time.count() * 1e6;

        cout << names[i] << ": " << fixed << setprecision(2)
            << microseconds << " мкс" << endl;
    }
}

void showMenu() {
    cout << "\n=== ТЕСТИРОВАНИЕ ПОСЛЕДОВАТЕЛЬНЫХ СОРТИРОВОК ===" << endl;
    cout << "1. Маленький массив чисел" << endl;
    cout << "2. Сортировка слов" << endl;
    cout << "3. Большой массив (2000 чисел)" << endl;
    cout << "4. Данные из файла (числа)" << endl;
    cout << "5. Слова из файла" << endl;
    cout << "0. Выход" << endl;
    cout << "Выберите: ";
}

int main() {
    setRussianLocale();

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> smallNumbers = { 5, 2, 8, 1, 9, 3, 7, 4, 6 };
    vector<string> words = { "яблоко", "банан", "апельсин", "виноград", "киви" };
    vector<int> bigNumbers = generateBigArray(2000);

    int choice;
    do {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1: testWithTime(smallNumbers, "МАЛЕНЬКИЙ МАССИВ"); break;
        case 2: testWithTime(words, "СЛОВА"); break;
        case 3: testWithTime(bigNumbers, "БОЛЬШОЙ МАССИВ"); break;
        case 4: {
            string filename;
            cout << "Имя файла: ";
            cin >> filename;
            vector<int> data = readFromFile<int>(filename);
            if (!data.empty()) testWithTime(data, "ФАЙЛ: " + filename);
            break;
        }
        case 5: {
            string filename;
            cout << "Имя файла: ";
            cin >> filename;
            vector<string> data = readFromFile<string>(filename);
            if (!data.empty()) testWithTime(data, "СЛОВА ИЗ ФАЙЛА");
            break;
        }
        }
    } while (choice != 0);

    return 0;
}
