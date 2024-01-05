#pragma once

#include<iostream>
#include<string>

using namespace std;

// после нажатия на отправку функция проверяет залогинен ли пользователь, после просит ввести кому 
// отправить сообщение и загружает динамич. массив переписки с данным пользователем
//      пользователь  массив сообщений    сообщение
template <typename T, typename M , typename S>
void registrVerification(T& user, M& sms, S& message) {
	if (user.username == "") { // проверяем что имя пользователя не задано
		cout << "Вы не вошли в свой аккаунт" << endl;
	}
	else {
		cout << "Кому вы хотите послать письмо?(введите его имя)" << endl;
		string To;
		cin >> To;

		cout << "Введите ваше сообщение" << endl;
		string Text;
		cin.ignore();
		getline(cin, Text);// функция которая подхватывает и пробелы во фразе

		S message(user.username, To, Text);
		sms.addSms(message);
	}
}
