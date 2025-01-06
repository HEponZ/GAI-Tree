#include "GAI.h"

int main()
{
	setlocale(LC_ALL, "rus");
	GAI base;
	string offence;
	int number, choise, end, begin;
	enum MENU {
		EXIT = 0,
		ADD,
		PRINT,
		SEARCH,
		PRINT_RANGE
	};

	cout << "1 - Добавить\n2 - Вывод все базы ГАИ\n3 - Поиск по базе\n4 - Вывод в диапазоне\n";

	do
	{
		try
		{
			cin >> choise;
			switch (choise)
			{
			case ADD:
				cout << "Введите номер авто: ";
				cin >> number;
				cout << "Введите правонарушение: ";
				cin >> offence;
				base.Add(number, offence);
				break;
			case PRINT:
				cout << "\nБАЗА ДАННЫХ ГАИ\n\n";
				base.print(base.getRoot());
				cout << "---------------\n";
				break;
			case SEARCH:
				cout << "Введите номер для поиска: ";
				cin >> number;
				cout << *base.Search(base.getRoot(), number);
				break;
			case PRINT_RANGE:
				cout << "Введите начало для поисков: ";
				cin >> begin;
				cout << "Введите конец для поисков: ";
				cin >> end;
				base.print_range(base.getRoot(), begin, end);
				break;
			}
		}
		catch (const underflow_error& exc)
		{
			cout << exc.what();
		}
	} while (choise != 0);

	return 0;
}