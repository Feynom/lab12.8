#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

typedef string Info;
struct Elem
{
	Elem* next,
		* prev;
	Info info;
};

void Enqueue(Elem*& first, Elem*& last, Info value);
void Read_File(Elem*& first, Elem*& last);
void Print(Elem* L);
void Print_Next_Even(Elem* L);
void Print_Prev_Non_Even(Elem* L);
int Count(Elem* L);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Elem* first = NULL,
		* last = NULL;


	Read_File(first, last);
	cout << "Список: "; Print(first); cout << endl;
	cout << "Парні номери елементів(в праву сторону): "; Print_Next_Even(first); cout << endl;
	cout << "Непарні номери елементів(в ліву сторону сторону): "; Print_Prev_Non_Even(last); cout << endl;

	return 0;
}
void Enqueue(Elem*& first, Elem*& last, Info value)
{
	Elem* tmp = new Elem;
	tmp->info = value;
	tmp->next = NULL;
	if (last != NULL)
		last->next = tmp;
	tmp->prev = last;
	last = tmp;
	if (first == NULL)
		first = tmp;
}
void Print(Elem* L)
{
	while (L != NULL)
	{
		cout << L->info << " ";
		L = L->next;
	}
}
void Read_File(Elem*& first, Elem*& last)
{
	ifstream f("list.txt", ios::in);

	if (!f.is_open())
	{
		cout << "Помилка!Файл не відкрито." << endl;
		exit(1);
	}
	string line;
	while (!f.eof())
	{
		getline(f, line);
		Enqueue(first, last, line);
	}
}
void Print_Next_Even(Elem* L)
{
	int count = 1;
	while (L != NULL)
	{
		if (count % 2 == 0)
			cout << L->info << " ";
		count++;
		L = L->next;
	}
}
void Print_Prev_Non_Even(Elem* L)
{
	int count = Count(L) - 1;
	while (L != NULL)
	{
		if (count % 2 != 0)
			cout << L->info << " ";
		count--;
		L = L->prev;
	}
}
int Count(Elem* L)
{
	int count = 0; 
	while (L != NULL)
	{
		count++;
		L = L->next;
	}
	return count;
}