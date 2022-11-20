#include "list_.h"

List::List()
{
	Head = Tail = NULL;
	Count = 0;
}

List::~List()
{
	Del_All();
}

void List::Add(char _data)
{
	Element* temp = new Element;
	temp->data = _data;
	temp->Next = NULL;
	if (Head != NULL)
	{
		Tail->Next = temp;
		Tail = temp;
	}
	else
	{
		Head = Tail = temp;
	}
	Count++;
}

void List::Del()
{
	Element* temp = Head;
	Head = Head->Next;
	delete temp;
	Count--;
}

void List::Del(int pos)
{
	if (pos < 0 || pos > Count)
	{
		cout << "Ошибка!!! Некоррктные данные!!!" << endl;
	}
	else
	{
		Element* prev_temp = new Element;
		int i = 1;
		Element* del = Head;
		while (i < pos)
		{
			prev_temp = del;
			del = del->Next;
			i++;
		}

		Element* AfterDel = del->Next;
		if (prev_temp != 0 && Count != 1)
		{
			prev_temp->Next = AfterDel;
		}
		if (pos == 1)
		{
			Head = AfterDel;
		}
		if (pos == Count)
		{
			Tail = prev_temp;
		}
		delete del;
		Count--;
		Print();
	}
	
}

void List::Del_All()
{
	while (Head != NULL)
	{
		Del();
	}
	Count = 0;
}


void List::Print()
{
	Element* tmp = Head;
	while (tmp != NULL)
	{
		cout << tmp->data << " ";
		tmp = tmp->Next;
	}
	cout << endl << endl;
}

void List::Print(int pos)
{
	Element* temp;
	if (pos < 0 || pos > Count)
	{
		cout << "Ошибка!!! Некоррктные данные!!!" << endl;
	}
	else
	{
		temp = Head;
		int i = 1;
		while (i < pos)
		{
			temp = temp->Next;
			i++;
		}
		cout << "Position: " << pos << " -> " << temp->data << endl;
		Print();
	}
	
}

int List::GetCount()
{
	return Count;
}

void List::Insert(int pos)
{
	Element* prev_temp = new Element;

	if (pos < 1 || pos > Count+1)
	{
		cout << "Ошибка!!! Некоррктные данные!!!" << endl;
	}
	else
	{
		char c;
		cout << "Enter simbol: "; cin >> c; cout << endl;
		Element* temp1 = new Element;
		Element* prev = Head;
		for (int i = 1; i < pos-1; i++)
		{
			prev = prev->Next;
		}
		Element *new_e = new Element((char)c,prev->Next);
		if (pos!=1)
		{
			prev->Next = new_e;
		}
		else if (pos==1)
		{
			Head = new Element((char)c, Head);
		}
		Count++;
		Print();		
	}	
}

void menu()
{
	cout << "Домашнее задание № 11:" << endl << endl;
	cout << "Для класса List (односвязного списка), " << endl;
	cout << "выполненного на уроке добавить функционал:" << endl;
	cout << "- распечатать, вставить, удалить  элемент по заданной позиции;" << endl << endl;

	cout << "1 - Распечатать;" << endl;
	cout << "2 - Распечатать по позиции;" << endl;
	cout << "3 - Вставить по позиции; " << endl;
	cout << "4 - Удалить по позиции;" << endl;
	cout << "5 - Удалить все;" << endl;
	cout << "0 - Выход;" << endl;
}
