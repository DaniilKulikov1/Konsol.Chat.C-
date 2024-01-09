#include "funcVerifRegistr.cpp";



//Этот класс будет в свой обьект записывать сообщение, и кому и от кого его посылает
class Message
{
private:

	string from_p;// поле от кого
	string to_p;// поле кому
	string text_p;// поле сообщение

public:
	Message()//Без этого конструктора на стаботает некоторая часть кода
	{
		from_p = "От Системы";
		to_p = "Пользователю";
		text_p = "Привет пользователь!";
	};

	//важно - когда передаём стринговое значение в функцию или конструктор обязательно нужно писать const
	Message(const string& from, const string& to, const  string& text)
	{
		from_p = from;
		to_p = to;
		text_p = text;
	};

	const string& getFrom()
	{
		return from_p;
	};

	const string& getTo()
	{
		return to_p;
	};

	const string& getText()
	{
		return text_p;
	};

};




template<typename T>
class Memory
{
private:
	int size; // это размер массива памяти
	T* data; //Это указатель на динамический массив
	int i = 0;// Это ячейка массива первая, туда и запишем первое смс

public:

	// создание блока памяти (динамического массива)
	Memory(int a)
	{
		size = a;
		data = new T[size];
	};

	//очистка после всех работ
	~Memory()
	{
		delete[] data;
	};


	//способ заполнение динамического массива
	void addSms(const T& value)
	{
		if (i < size)
		{
			data[i] = value;
			++i;
		}
		else
		{
			cout << "В памяти нет места!";
		}
	}


	void Display()
	{
		for (int j = 0; j < i; ++j)
		{
			cout << "От кого: " << data[j].getFrom() << " кому: " << data[j].getTo() << endl;
			cout << "======>" << data[j].getText() << "<=========" << endl;
		}

	};


};

class User // класс где хранится Логин и Пароль
{
public:
	string username;
	string password;
};
bool registerUser(User& user) // Регристрация пользователя
{
	cout << "Введите Логин" << endl;
	cin >> user.username;
	cout << "Введите Пароль" << endl;
	cin >> user.password;
	cout << "Регристрация успешно завершена!" << endl;
	return true;
}
bool loginUser(const User& user) // Вход в аккаунт 
{
	string enteredUsername, enteredPassword;
	cout << "Введите Логин" << endl;
	cin >> enteredUsername;
	cout << "Введите Пароль" << endl;
	cin >> enteredPassword;
	if (enteredUsername == user.username && enteredPassword == user.password) // Проверка на правильность ввода данных.
	{
		cout << "Вход выполнен успешно" << endl;
		return true;
	}
	else
	{
		cout << "Неправильно введено Логин или Пароль" << endl;
		return false;
	}
}


int main() {
    cout << R"(
                 _   _      _ _       _ 
                | | | | ___| | | ___ | |
                | |_| |/ _ \ | |/ _ \| |
                |  _  |  __/ | | (_) |_|
                |_| |_|\___|_|_|\___/(_)
                                        
)" << endl;
    cout << R"(

                 ___====-_  _-====___
           _--^^^#####//      \\#####^^^--_
        _-^##########// (    ) \\##########^-_
       -############//  |\^^/|  \\############-
     _/############//   (@::@)   \\############\_
    /#############((     \\//     ))#############\
   -###############\\    (oo)    //###############-
  -#################\\  / VV \  //#################-
 -###################\\/      \//###################-
_#/|##########/\######(   /\   )######/\##########|\#_
|/ |#/\#/\#/\/  \#/\##\  |  |  /##/\#/  \/\#/\#/\#| \|
`  |/  V  V  `   V  \#\| |  | |/#/  V   '  V  V  \|  '
   `   `  `      `   / | |  | | \   '      '  '   '
                    (  | |  | |  )
                   __\ | |  | | /__
                  (vvv(VVV)(VVV)vvv)

 )";





	setlocale(LC_ALL, "Rus");


	Memory <Message> Sms(5);//Создали блок памяти для сообщений

	Message message;


	User newUser; // вызов регристрации. newUser - тоже самое что мы вводили в начале при регристрации.
	int choice;
	do // вызывает выбор ниже пока не будет выполнен while.
	{
		cout << "Выберите действие:" << endl;
		cout << "1. Регистрация" << endl;
		cout << "2. Вход" << endl;
		cout << "3. Сообщения или отправка" << endl; // Пока что не работает
		cout << "4. Выйти" << endl; // Теперь пользователь если захочет выйти нажмёт 4.
		cin >> choice;
		switch (choice)
		{
		case 1:
			registerUser(newUser);
			break;
		case 2:
			cout << "У вас есть 3 попытки" << endl;
			for (int i = 0; i < 3; ++i) {
				if (loginUser(newUser)) {
					break;
				}
			}
			break;
		case 3:
			registrVerification(newUser, Sms, message);
			Sms.Display();
			break;
		case 4:
			cout << "До свидания!" << endl;
			break;
		default: // Любой другой выбор вне 1-4 привидёт к этому.
			cout << "Некорректный выбор" << endl;
			break;
		}
	} while (choice != 4); // Чтобы выйти нужно обязательно нажать 4 иначе будет постоянно возращать к начальному выбору.

	return 0;

}