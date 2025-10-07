#include <iostream>
#include <windows.h>
#include <iomanip>
#include <ctime>
#include <fstream>
using namespace std;

int main()
{
    srand(time(0));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

	cout << "��������� ��� ��������� ������� �� ������ � ��������." << endl;
	Sleep(1000);
	cout << "������ ��������� � ����� int." << endl;

    int n;
    cout << "������� ������ ������� � �������: ";
    cin >> n;

    // �������� �� ���������� ������
    if (n < 0) {
        cout << "������: ������ ������ ���� ���������������!" << endl;
        return 1;
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

    return 0;
}