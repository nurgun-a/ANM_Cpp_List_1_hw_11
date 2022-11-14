#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <conio.h>
using namespace std;

struct Element
{
	char data;
	Element* Next;
};
class List
{
	Element* Head, * Tail;
	int Count;

public:
	List();
	~List();
	void Add(char _data);	
	void Del();
	void Del(int pos);
	void Del_All();
	void Print();
	void Print(int pos);
	int GetCount();
	void Insert(int pos);
};
void menu();
