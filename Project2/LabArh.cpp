#include <iostream>
#include <windows.h>
#include <iomanip>
#include <ctime>

void test_float() {
    Sleep(1000);
    cout << "Повторный запуск программы с типом float" << endl;
    int a;
    cout << "Введите размер матрицы и вектора: ";
    cin >> a;

    // Проверка на корректный размер
    if (a < 0) {
        cout << "Ошибка: размер должен быть неотрицательным!" << endl;
        return;
    }

    float* Vector, * RezultMV, * RezultVM, * RezultVMopt;
    float** Matrix;

    // Выделение памяти
    Vector = new float[a];
    RezultMV = new float[a];
    RezultVM = new float[a];
    RezultVMopt = new float[a];

    Matrix = new float* [a];
    for (int i = 0; i < a; i++) {
        Matrix[i] = new float[a];
    }

    // Заполнение вектора и матрицы случайными значениями
    cout << "Инициализация данных..." << endl;
    for (int i = 0; i < a; i++)
    {
        RezultMV[i] = 0;
        RezultVM[i] = 0;
        RezultVMopt[i] = 0;
        Vector[i] = (rand() % 199 - 99) * 0.01f;
    }

    for (int i = 0; i < a; i++)
        for (int j = 0; j < a; j++)
            Matrix[i][j] = (rand() % 199 - 99) * 0.01f;

    // Умножение матрицы на вектор
    for (int i = 0; i < a; i++)
        RezultMV[i] = 0;

    int t2 = clock();
    for (int i = 0; i < a; i++)
        for (int j = 0; j < a; j++)
            RezultMV[i] = RezultMV[i] + Matrix[i][j] * Vector[j];
    cout << "M * V = " << clock() - t2 << " мс" << endl;

    // Умножение вектора на матрицу
    for (int i = 0; i < a; i++)
        RezultVM[i] = 0;

    t2 = clock();
    for (int i = 0; i < a; i++)
        for (int j = 0; j < a; j++)
            RezultVM[i] = RezultVM[i] + Matrix[j][i] * Vector[j];
    cout << "V * M = " << clock() - t2 << " мс" << endl;

    // Умножение вектора на матрицу (оптимизированный вариант)
    for (int i = 0; i < a; i++)
        RezultVMopt[i] = 0;

    t2 = clock();
    for (int i = 0; i < a; i++)
        for (int j = 0; j < a; j++)
            RezultVMopt[j] = RezultVMopt[j] + Matrix[i][j] * Vector[i];
    cout << "V * M opt = " << clock() - t2 << " мс" << endl;

    // Демонстрация результата для маленьких размеров
    if (a <= 10) {
        cout << "\nВектор V: ";
        for (int i = 0; i < a; i++)
            cout << setw(6) << Vector[i];

        cout << "\n\nМатрица M:\n";
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < a; j++)
                cout << setw(6) << Matrix[i][j];
            cout << endl;
        }

        cout << "\n\nРезультат M*V: ";
        for (int i = 0; i < a; i++)
            cout << setw(8) << RezultMV[i];
        cout << "\nM * V = " << clock() - t2 << " мс" << endl;
        cout << endl;

        cout << "\n\nРезультат V*M: ";
        for (int i = 0; i < a; i++)
            cout << setw(8) << RezultVM[i];
        cout << "\nV * M = " << clock() - t2 << " мс" << endl;
        cout << endl;

        cout << "\n\nРезультат V*M opt: ";
        for (int i = 0; i < a; i++)
            cout << setw(8) << RezultVMopt[i];
        cout << "\nV * M opt = " << clock() - t2 << " мс" << endl;
        cout << endl;
    }

    // Освобождение памяти
    delete[] Vector;
    delete[] RezultMV;
    delete[] RezultVM;
    delete[] RezultVMopt;
    for (int i = 0; i < a; i++) {
        delete[] Matrix[i];
    }
    delete[] Matrix;

    cout << "\nПамять очищена. Программа завершена." << endl;
}

void test_double(){
    cout << "Повторной запуск программы с типом double." << endl;
    Sleep(1000);

    int n;
    cout << "Введите размер матрицы и вектора: ";
    cin >> n;

    // Проверка на корректный размер
    if (n <= 0) {
        cout << "Ошибка: размер должен быть положительным!" << endl;
        return;
    }

    double* Vect, * RezMV, * RezVM, * RezVMopt;
    double** Matr;

    // Выделение памяти
    Vect = new double[n];
    RezMV = new double[n];
    RezVM = new double[n];
    RezVMopt = new double[n];

    Matr = new double* [n];
    for (int i = 0; i < n; i++) {
        Matr[i] = new double[n];
    }

    // Заполнение вектора и матрицы случайными значениями
    cout << "Инициализация данных..." << endl;
    for (int i = 0; i < n; i++)
    {
        RezMV[i] = 0;
        RezVM[i] = 0;
        RezVMopt[i] = 0;
        Vect[i] = (rand() % 199 - 99) * 0.01;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            Matr[i][j] = (rand() % 199 - 99) * 0.01;

    // Умножение матрицы на вектор
    for (int i = 0; i < n; i++)
        RezMV[i] = 0;

    int t1 = clock();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            RezMV[i] = RezMV[i] + Matr[i][j] * Vect[j];
    cout << "M * V = " << clock() - t1 << " мс" << endl;

    // Умножение вектора на матрицу
    for (int i = 0; i < n; i++)
        RezVM[i] = 0;

    t1 = clock();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            RezVM[i] = RezVM[i] + Matr[j][i] * Vect[j];
    cout << "V * M = " << clock() - t1 << " мс" << endl;

    // Умножение вектора на матрицу (оптимизированный вариант)
    for (int i = 0; i < n; i++)
        RezVMopt[i] = 0;

    t1 = clock();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            RezVMopt[j] = RezVMopt[j] + Matr[i][j] * Vect[i];
    cout << "V * M opt = " << clock() - t1 << " мс" << endl;

    // Результата для матриц и векторов малой размерности
    if (n <= 10) {
        cout << "\nВектор V: ";
        for (int i = 0; i < n; i++)
            cout << setw(6) << Vect[i];

        cout << "\n\nМатрица M:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << setw(6) << Matr[i][j];
            cout << endl;
        }

        cout << "\n\nРезультат M*V: ";
        for (int i = 0; i < n; i++)
            cout << setw(8) << RezMV[i];
        cout << "\nM * V = " << clock() - t1 << " мс" << endl;
        cout << endl;

        cout << "\n\nРезультат V*M: ";
        for (int i = 0; i < n; i++)
            cout << setw(8) << RezVM[i];
        cout << "\nV * M = " << clock() - t1 << " мс" << endl;
        cout << endl;

        cout << "\n\nРезультат V*M opt: ";
        for (int i = 0; i < n; i++)
            cout << setw(8) << RezVMopt[i];
        cout << "\nV * M opt = " << clock() - t1 << " мс" << endl;
        cout << endl;
    }

    // Освобождение памяти
    delete[] Vect;
    delete[] RezMV;
    delete[] RezVM;
    delete[] RezVMopt;
    for (int i = 0; i < n; i++) {
        delete[] Matr[i];
    }
    delete[] Matr;

    cout << "\nПамять очищенна. Программа завершена." << endl;
}

void test_int(){
    cout << "Программа для умножения матрицы на вектор и наоборот." << endl;
    Sleep(1000);
    cout << "Запуск программы с типом int." << endl;

    int n;
    cout << "Введите размер матрицы и вектора: ";
    cin >> n;

    // Проверка на корректный размер
    if (n < 0) {
        cout << "Ошибка: размер должен быть неотрицательным!" << endl;
        return;
    }

    int* Vect, * RezMV, * RezVM, * RezVMopt;
    int** Matr;

    // Выделение памяти
    Vect = new int[n];
    RezMV = new int[n];
    RezVM = new int[n];
    RezVMopt = new int[n];

    Matr = new int* [n];
    for (int i = 0; i < n; i++) {
        Matr[i] = new int[n];
    }

    // Заполнение вектора и матрицы случайными значениями
    cout << "Инициализация данных..." << endl;
    for (int i = 0; i < n; i++)
    {
        RezMV[i] = 0;
        RezVM[i] = 0;
        RezVMopt[i] = 0;
        Vect[i] = rand() % 300 - 99;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            Matr[i][j] = rand() % 300 - 99;

    // Умножение матрицы на вектор
    for (int i = 0; i < n; i++)
        RezMV[i] = 0;

    int t1 = clock();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            RezMV[i] = RezMV[i] + Matr[i][j] * Vect[j];
    cout << "M * V = " << clock() - t1 << " мс" << endl;

    // Умножение вектора на матрицу
    for (int i = 0; i < n; i++)
        RezVM[i] = 0;

    t1 = clock();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            RezVM[i] = RezVM[i] + Matr[j][i] * Vect[j];
    cout << "V * M = " << clock() - t1 << " мс" << endl;

    // Умножение вектора на матрицу (оптимизированный вариант)
    for (int i = 0; i < n; i++)
        RezVMopt[i] = 0;

    t1 = clock();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            RezVMopt[j] = RezVMopt[j] + Matr[i][j] * Vect[i];
    cout << "V * M opt = " << clock() - t1 << " мс" << endl;

    // Результата для матриц и векторов малой размерности
    if (n <= 10) {
        cout << "\nВектор V: ";
        for (int i = 0; i < n; i++)
            cout << setw(6) << Vect[i];

        cout << "\n\nМатрица M:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << setw(6) << Matr[i][j];
            cout << endl;
        }

        cout << "\n\nРезультат M*V: ";
        for (int i = 0; i < n; i++)
            cout << setw(8) << RezMV[i];
        cout << "\nM * V = " << clock() - t1 << " мс" << endl;
        cout << endl;

        cout << "\n\nРезультат V*M: ";
        for (int i = 0; i < n; i++)
            cout << setw(8) << RezVM[i];
        cout << "\nV * M = " << clock() - t1 << " мс" << endl;
        cout << endl;

        cout << "\n\nРезультат V*M opt: ";
        for (int i = 0; i < n; i++)
            cout << setw(8) << RezVMopt[i];
        cout << "\nV * M opt = " << clock() - t1 << " мс" << endl;
        cout << endl;
    }

    // Освобождение памяти
    delete[] Vect;
    delete[] RezMV;
    delete[] RezVM;
    delete[] RezVMopt;
    for (int i = 0; i < n; i++) {
        delete[] Matr[i];
    }
    delete[] Matr;

    cout << "\nПамять очищенна. Программа завершена." << endl;
}

int main()
{
    srand(time(0));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	test_int();
	test_float();
	test_double();
    return 0;
}