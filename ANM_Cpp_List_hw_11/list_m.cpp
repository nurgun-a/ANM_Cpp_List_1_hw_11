#include "list_.h"

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");

	List l1;
	char s[] = "Hello C++ !!!";
	cout << s << endl;
	int len = strlen(s);
	bool key = 1;
	int key_1=0;
	int pos_ = 0;
	for (int i = 0; i < len; i++)
	{
		l1.Add(s[i]);
	}

	do
	{
		system("cls");
		menu();
		cout << "Enter: "; cin >> key_1; cout << endl;
		switch (key_1)
		{
		case 1:
		{
			l1.Print();
			_getch();
		}break;
		case 2:
		{
			cout << "Input position: "; cin >> pos_; cout << endl;
			l1.Print(pos_);
			_getch();
		}break;
		case 3:
		{
			cout << "Input position: "; cin >> pos_; cout << endl;
			l1.Insert(pos_);			
			_getch();
		}break;
		case 4:
		{
			cout << "Input position: "; cin >> pos_; cout << endl;
			l1.Del(pos_);
			_getch();
		}break;
		case 5:
		{
			l1.Del_All();
		}break;
		case 0:
		{
			key = 0;
		}break;
		default:
			break;
		}
	} while (key);
	cout << "\n\n\t\t\t\tThe End!" << endl;
}