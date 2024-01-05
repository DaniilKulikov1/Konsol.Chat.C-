#pragma once

#include<iostream>
#include<string>

using namespace std;

// ����� ������� �� �������� ������� ��������� ��������� �� ������������, ����� ������ ������ ���� 
// ��������� ��������� � ��������� �������. ������ ��������� � ������ �������������
//      ������������  ������ ���������    ���������
template <typename T, typename M , typename S>
void registrVerification(T& user, M& sms, S& message) {
	if (user.username == "") { // ��������� ��� ��� ������������ �� ������
		cout << "�� �� ����� � ���� �������" << endl;
	}
	else {
		cout << "���� �� ������ ������� ������?(������� ��� ���)" << endl;
		string To;
		cin >> To;

		cout << "������� ���� ���������" << endl;
		string Text;
		cin.ignore();
		getline(cin, Text);// ������� ������� ������������ � ������� �� �����

		S message(user.username, To, Text);
		sms.addSms(message);
	}
}
