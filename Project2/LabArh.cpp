#include <iostream>
#include <windows.h>
#include <iomanip>
#include <ctime>

void test_float() {
    Sleep(1000);
    cout << "��������� ������ ��������� � ����� float" << endl;
    int a;
    cout << "������� ������ ������� � �������: ";
    cin >> a;

    // �������� �� ���������� ������
    if (a < 0) {
        cout << "������: ������ ������ ���� ���������������!" << endl;
        return;
    }

    float* Vector, * RezultMV, * RezultVM, * RezultVMopt;
    float** Matrix;

    // ��������� ������
    Vector = new float[a];
    RezultMV = new float[a];
    RezultVM = new float[a];
    RezultVMopt = new float[a];

    Matrix = new float* [a];
    for (int i = 0; i < a; i++) {
        Matrix[i] = new float[a];
    }

    // ���������� ������� � ������� ���������� ����������
    cout << "������������� ������..." << endl;
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

    // ��������� ������� �� ������
    for (int i = 0; i < a; i++)
        RezultMV[i] = 0;

    int t2 = clock();
    for (int i = 0; i < a; i++)
        for (int j = 0; j < a; j++)
            RezultMV[i] = RezultMV[i] + Matrix[i][j] * Vector[j];
    cout << "M * V = " << clock() - t2 << " ��" << endl;

    // ��������� ������� �� �������
    for (int i = 0; i < a; i++)
        RezultVM[i] = 0;

    t2 = clock();
    for (int i = 0; i < a; i++)
        for (int j = 0; j < a; j++)
            RezultVM[i] = RezultVM[i] + Matrix[j][i] * Vector[j];
    cout << "V * M = " << clock() - t2 << " ��" << endl;

    // ��������� ������� �� ������� (���������������� �������)
    for (int i = 0; i < a; i++)
        RezultVMopt[i] = 0;

    t2 = clock();
    for (int i = 0; i < a; i++)
        for (int j = 0; j < a; j++)
            RezultVMopt[j] = RezultVMopt[j] + Matrix[i][j] * Vector[i];
    cout << "V * M opt = " << clock() - t2 << " ��" << endl;

    // ������������ ���������� ��� ��������� ��������
    if (a <= 10) {
        cout << "\n������ V: ";
        for (int i = 0; i < a; i++)
            cout << setw(6) << Vector[i];

        cout << "\n\n������� M:\n";
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < a; j++)
                cout << setw(6) << Matrix[i][j];
            cout << endl;
        }

        cout << "\n\n��������� M*V: ";
        for (int i = 0; i < a; i++)
            cout << setw(8) << RezultMV[i];
        cout << "\nM * V = " << clock() - t2 << " ��" << endl;
        cout << endl;

        cout << "\n\n��������� V*M: ";
        for (int i = 0; i < a; i++)
            cout << setw(8) << RezultVM[i];
        cout << "\nV * M = " << clock() - t2 << " ��" << endl;
        cout << endl;

        cout << "\n\n��������� V*M opt: ";
        for (int i = 0; i < a; i++)
            cout << setw(8) << RezultVMopt[i];
        cout << "\nV * M opt = " << clock() - t2 << " ��" << endl;
        cout << endl;
    }

    // ������������ ������
    delete[] Vector;
    delete[] RezultMV;
    delete[] RezultVM;
    delete[] RezultVMopt;
    for (int i = 0; i < a; i++) {
        delete[] Matrix[i];
    }
    delete[] Matrix;

    cout << "\n������ �������. ��������� ���������." << endl;
}

void test_double(){
    cout << "��������� ������ ��������� � ����� double." << endl;
    Sleep(1000);

    int n;
    cout << "������� ������ ������� � �������: ";
    cin >> n;

    // �������� �� ���������� ������
    if (n <= 0) {
        cout << "������: ������ ������ ���� �������������!" << endl;
        return;
    }

    double* Vect, * RezMV, * RezVM, * RezVMopt;
    double** Matr;

    // ��������� ������
    Vect = new double[n];
    RezMV = new double[n];
    RezVM = new double[n];
    RezVMopt = new double[n];

    Matr = new double* [n];
    for (int i = 0; i < n; i++) {
        Matr[i] = new double[n];
    }

    // ���������� ������� � ������� ���������� ����������
    cout << "������������� ������..." << endl;
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

    // ��������� ������� �� ������
    for (int i = 0; i < n; i++)
        RezMV[i] = 0;

    int t1 = clock();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            RezMV[i] = RezMV[i] + Matr[i][j] * Vect[j];
    cout << "M * V = " << clock() - t1 << " ��" << endl;

    // ��������� ������� �� �������
    for (int i = 0; i < n; i++)
        RezVM[i] = 0;

    t1 = clock();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            RezVM[i] = RezVM[i] + Matr[j][i] * Vect[j];
    cout << "V * M = " << clock() - t1 << " ��" << endl;

    // ��������� ������� �� ������� (���������������� �������)
    for (int i = 0; i < n; i++)
        RezVMopt[i] = 0;

    t1 = clock();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            RezVMopt[j] = RezVMopt[j] + Matr[i][j] * Vect[i];
    cout << "V * M opt = " << clock() - t1 << " ��" << endl;

    // ���������� ��� ������ � �������� ����� �����������
    if (n <= 10) {
        cout << "\n������ V: ";
        for (int i = 0; i < n; i++)
            cout << setw(6) << Vect[i];

        cout << "\n\n������� M:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << setw(6) << Matr[i][j];
            cout << endl;
        }

        cout << "\n\n��������� M*V: ";
        for (int i = 0; i < n; i++)
            cout << setw(8) << RezMV[i];
        cout << "\nM * V = " << clock() - t1 << " ��" << endl;
        cout << endl;

        cout << "\n\n��������� V*M: ";
        for (int i = 0; i < n; i++)
            cout << setw(8) << RezVM[i];
        cout << "\nV * M = " << clock() - t1 << " ��" << endl;
        cout << endl;

        cout << "\n\n��������� V*M opt: ";
        for (int i = 0; i < n; i++)
            cout << setw(8) << RezVMopt[i];
        cout << "\nV * M opt = " << clock() - t1 << " ��" << endl;
        cout << endl;
    }

    // ������������ ������
    delete[] Vect;
    delete[] RezMV;
    delete[] RezVM;
    delete[] RezVMopt;
    for (int i = 0; i < n; i++) {
        delete[] Matr[i];
    }
    delete[] Matr;

    cout << "\n������ ��������. ��������� ���������." << endl;
}

void test_int(){
    cout << "��������� ��� ��������� ������� �� ������ � ��������." << endl;
    Sleep(1000);
    cout << "������ ��������� � ����� int." << endl;

    int n;
    cout << "������� ������ ������� � �������: ";
    cin >> n;

    // �������� �� ���������� ������
    if (n < 0) {
        cout << "������: ������ ������ ���� ���������������!" << endl;
        return;
    }

    int* Vect, * RezMV, * RezVM, * RezVMopt;
    int** Matr;

    // ��������� ������
    Vect = new int[n];
    RezMV = new int[n];
    RezVM = new int[n];
    RezVMopt = new int[n];

    Matr = new int* [n];
    for (int i = 0; i < n; i++) {
        Matr[i] = new int[n];
    }

    // ���������� ������� � ������� ���������� ����������
    cout << "������������� ������..." << endl;
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

    // ��������� ������� �� ������
    for (int i = 0; i < n; i++)
        RezMV[i] = 0;

    int t1 = clock();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            RezMV[i] = RezMV[i] + Matr[i][j] * Vect[j];
    cout << "M * V = " << clock() - t1 << " ��" << endl;

    // ��������� ������� �� �������
    for (int i = 0; i < n; i++)
        RezVM[i] = 0;

    t1 = clock();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            RezVM[i] = RezVM[i] + Matr[j][i] * Vect[j];
    cout << "V * M = " << clock() - t1 << " ��" << endl;

    // ��������� ������� �� ������� (���������������� �������)
    for (int i = 0; i < n; i++)
        RezVMopt[i] = 0;

    t1 = clock();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            RezVMopt[j] = RezVMopt[j] + Matr[i][j] * Vect[i];
    cout << "V * M opt = " << clock() - t1 << " ��" << endl;

    // ���������� ��� ������ � �������� ����� �����������
    if (n <= 10) {
        cout << "\n������ V: ";
        for (int i = 0; i < n; i++)
            cout << setw(6) << Vect[i];

        cout << "\n\n������� M:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << setw(6) << Matr[i][j];
            cout << endl;
        }

        cout << "\n\n��������� M*V: ";
        for (int i = 0; i < n; i++)
            cout << setw(8) << RezMV[i];
        cout << "\nM * V = " << clock() - t1 << " ��" << endl;
        cout << endl;

        cout << "\n\n��������� V*M: ";
        for (int i = 0; i < n; i++)
            cout << setw(8) << RezVM[i];
        cout << "\nV * M = " << clock() - t1 << " ��" << endl;
        cout << endl;

        cout << "\n\n��������� V*M opt: ";
        for (int i = 0; i < n; i++)
            cout << setw(8) << RezVMopt[i];
        cout << "\nV * M opt = " << clock() - t1 << " ��" << endl;
        cout << endl;
    }

    // ������������ ������
    delete[] Vect;
    delete[] RezMV;
    delete[] RezVM;
    delete[] RezVMopt;
    for (int i = 0; i < n; i++) {
        delete[] Matr[i];
    }
    delete[] Matr;

    cout << "\n������ ��������. ��������� ���������." << endl;
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