#include<iostream>
#include<string>
using namespace std;

/*класс пользователь*/
class User
{
private:
    string login_p; /*логин пользователя _p - у меня значат приват*/
	string password_p; /*пароль пользователя*/
	string name_p; /*имя пользователя*/

public:
	/*конструктор для этих полей по умолчанию*/
	User(const string& login, const string& password, const string& name) :login_p(login), password_p(password), name_p(name)
	{};

	/*для показа логина*/
	 string& getLogin()
	{
		return login_p; 
	};


	/*для показа пароля*/
	 string& getPassword() 
	{
		return password_p;
	};


	/*для показа имени*/
 string& getName() 
	{
		return name_p;
	};

	/*для установки имени*/
	void setName(const string& name) 
	{
		name_p = name;
	};

	/*для показа пароля*/
	void setPassword(const string& password)
	{
		password_p=password;

	};

};

/*класс сообщения*/
class Message
{
private:
	string from_p;
	string to_p;
	string text_p;

public:
	Message(const string& from, const string& to, const string& text) :from_p(from), to_p(to), text_p(text)
	{};

	string& getFrom()
	{
		return from_p;
	};

	string& getTo()
	{
		return to_p;
	};

	string& getText()
	{
		return text_p;
	}


};



int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Приветствую вас в консольном чате" << endl;
	User B( "Don",  "jfdajsdf",  "Даниил");


	return 0;
}