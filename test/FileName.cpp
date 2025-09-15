//Калькулятор CGPA.
#include <iostream>
#include <string>
#include <windows.h>    
using namespace std;
double percentToPoint(int p) {
    if (p >= 90) return 4.0;
    if (p >= 85) return 3.7;
    if (p >= 80) return 3.3;
    if (p >= 75) return 3.0;
    if (p >= 70) return 2.7;
    if (p >= 65) return 2.3;
    if (p >= 60) return 2.0;
    if (p >= 55) return 1.7;
    if (p >= 50) return 1.0;
    return 0.0;
}



struct Predmet {
    string name;   
    int credit;    
    int grade;     
};

int main() {
	SetConsoleOutputCP(1251);
    const int K = 5;
    Predmet subjects[K] = {
        {"Математика", 3, 95},
        {"Физика", 2, 88},
        {"Химия", 2, 76},
        {"История", 1, 82},
        {"Программирование", 4, 100}
    };

    for (int i = 0; i < K; ++i) {
        cout << subjects[i].name
            << " | кредиты: " << subjects[i].credit
            << " | оценка: " << subjects[i].grade << '\n';
    }

    int totalCredits = 0;
    int weightedSum = 0;
    for (int i = 0; i < K; ++i) {
        totalCredits += subjects[i].credit;
        weightedSum += subjects[i].grade * subjects[i].credit;
    }

    cout << "Всего кредитов: " << totalCredits << '\n';
    double avg = totalCredits ? (double)weightedSum / totalCredits : 0.0;
    cout << "Средний балл (взвешенный по кредитам): " << avg << '\n';
    
    double ptsSum = 0.0;
    int crSum = 0;
    for (int i = 0; i < K; ++i) {
        ptsSum += percentToPoint(subjects[i].grade) * subjects[i].credit;
        crSum += subjects[i].credit;
    }
    double cgpa = crSum ? ptsSum / crSum : 0.0;
    cout << "CGPA (0..4): " << cgpa << '\n';
    return 0;
}
