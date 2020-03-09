#include <iostream>
#include <time.h>
using namespace std;

class List
{
public:
	struct Elem
	{
		int data;
		Elem* next;
		Elem* prev;
	};

private:
	Elem* Head, * Tail;
	int length;

public:
	List();
	~List();
	int GetLength();
	void AddTail(int n);
	void AddHead(int n);
	void Del(int pos);
	void DelAll();
	Elem* GetElem(int);
};

List::List()
{
	Head = Tail = nullptr;
	length = 0;
}

void List::AddHead(int n)
{
	Elem* temp = new Elem();
	temp->prev = nullptr;
	temp->data = n;
	temp->next = Head;

	// если в списке уже есть элементы
	if (Head != nullptr) Head->prev = temp;

	// если элементов не было
	if (length == 0) Head = Tail = temp;
	else Head = temp;

	length++;
}

void List::AddTail(int n)
{
	Elem* temp = new Elem();
	temp->next = nullptr;
	temp->data = n;
	temp->prev = Tail;

	// если в списке уже есть элементы
	if (Tail != nullptr) Tail->next = temp;

	// если элементов не было
	if (length == 0) Head = Tail = temp;
	else Tail = temp;

	length++;
}

void List::Del(int pos)
{
	if (pos < 1 || pos > length)
		throw "Incorrect position";

	int i = 1;
	Elem* Del = Head;
	while (i < pos)
	{
		Del = Del->next;
		i++;
	}

	Elem* PrevDel = Del->prev;
	Elem* AfterDel = Del->next;

	// если удаляется не голова
	if (PrevDel != nullptr && length != 1)
		PrevDel->next = AfterDel;
	// если удаляется не хвост
	if (AfterDel != nullptr && length != 1)
		AfterDel->prev = PrevDel;

	// удаление крайних элементов
	if (pos == 1) Head = AfterDel;
	if (pos == length) Tail = PrevDel;

	delete Del;

	length--;
}

void List::DelAll()
{
	while (length != 0) Del(1);
}

List::~List()
{
	DelAll();
}

int List::GetLength()
{
	return length;
}

List::Elem* List::GetElem(int pos)
{
	if (pos < 1 || pos > length)
		throw "Incorrect position";

	Elem* temp = Head;

	int i = 1;
	while (i < pos && temp != nullptr)
	{
		temp = temp->next;
		i++;
	}

	if (temp == nullptr) return nullptr; // ничего не найдено :(
	return temp;
}

////////////////////////////////////////////////////////////////////////////////////////

//class Queue
//{
//	List l;
//	int max_count;
//	int count = 0;
//
//public:
//	Queue(int m)
//	{
//		max_count = m;
//	}
//
//	~Queue()
//	{
//		l.DelAll();
//	}
//
//	void Clear()
//	{
//		l.DelAll();
//		count = 0;
//	}
//
//	bool IsEmpty()
//	{
//		return count == 0;
//	}
//
//	bool IsFull()
//	{
//		return count == max_count;
//	}
//
//	int GetCount()
//	{
//		return count;
//	}
//
//	void Enqueue(int number)
//	{
//		l.AddTail(number);
//		count++;
//	}
//
//	int Dequeue()
//	{
//		if (!IsEmpty())
//		{
//			int first = l.GetElem(1)->data;
//			l.Del(1);
//			count--;
//			return first;
//		}
//		else throw "Queue is empty!";
//	}
//
//	void Show()
//	{
//		// l.Print();
//		cout << "-----------------------------------------------------\n";
//		for (int i = 0; i < count; i++)
//			cout << l.GetElem(i + 1)->data << "  ";
//		cout << "\n";
//		cout << "-----------------------------------------------------\n";
//	}
//};
//
//void main()
//{
//	system("title Пользовательский адаптер Queue (двусвязный список)");
//	srand(time(0));
//	rand();
//
//	Queue q(25);
//
//	for (int i = 0; i < 5; i++)
//		q.Enqueue(rand() % 90 + 10);
//
//	q.Show();
//
//	q.Dequeue();
//
//	q.Show();
//
//	for (int i = 0; i < 2; i++)
//		q.Enqueue(rand() % 90 + 10);
//
//	q.Show();
//
//	for (int i = 0; i < 3; i++)
//		q.Dequeue();
//
//	q.Show();
//};
