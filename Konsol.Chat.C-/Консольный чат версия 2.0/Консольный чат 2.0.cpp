#include<iostream>
#include<string>
using namespace std;





//Этот класс будет в свой обьект записывать сообщение, и кому и от кого его посылает
class Message
{private:

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
	Message( const string& from, const string& to, const  string& text)
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
			cout << "======>"<<data[j].getText() << "<=========" << endl;
		}

	};


};



int main()
{
	int a = 15;

	setlocale(LC_ALL, "ru");
	system("chcp 1251");
	//Message First("Даниила", "Николаю", "Пожалуйста протестируй на своём ПК"); // Протестировано

	cout << "Ваша подпись письма (введите своё имя)" << endl;
	string From;
	cin >> From;

	cout << "Кому вы хотите послать письмо?(введите его имя)" << endl;
	string To;
	cin >> To;

	cout << "Введите ваше сообщение" << endl;
	string Text;
	cin.ignore();
	getline(cin, Text);// функция которая подхватывает и пробелы во фразе
	Message First(From, To, Text);// заполнили с клавиатуры наше сообщение у указали кому и от кого

	cout << " " << endl;
	
	Memory <Message> Sms(a);//Создали блок памяти для сообщений
	Sms.addSms(First);//добавили туда наше сообщение и то что связано с 
	Sms.Display();


	return 0;
}