#include <iostream>
using namespace std;

class Node
{
private:
	int data;
	Node *next;
public:
	Node(int d = 0)
	{
		data = d;
		next = NULL;
	}
	friend class LinkedList;
};

class LinkedList
{
private:
	Node *head;
public:
	LinkedList()
	{
		head = NULL;
	}
	~LinkedList()
	{
		Node *tmp = head;
		while(head != NULL)
		{
			tmp = head;
			head = head->next;
			delete tmp;
		}
	}
	void InsertatEnd(int d)
	{
		Node *nn = new Node(d);
		if(head == NULL)
		{
			head = nn;
			return;
		}
		Node *tmp = head;
		while(tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = nn;
	}
	void Print()
	{
		Node *tmp = head;
		while(tmp != NULL)
		{
			cout << tmp->data <<' ';
			tmp = tmp->next;
		}
		cout << endl;
	}
	
	void InsertionSort(Node *h)
	{
		if(h == NULL || h->next == NULL) return;
		Node *ptr = h, *ptrprev;
		while(ptr != NULL)
		{
			Node *tmp = h, tmpprev;
			while(tmp != ptr)
			{
				if(ptr->data < tmp->data)
				{
					if(tmp != h)
					{
						ptrprev->next = ptr->next;
					    ptr->next = tmp;
					    tmpprev->next = ptr;
					}
					if(tmp == h)
					{
						ptrprev->next = ptr->next;
						ptr->next = tmp;
						h = ptr;
					}
					
				}
				tmpprev = tmp;
				tmp = tmp->next;
			}
		}
	}
	
	void InsertionSort()
	{
		InsertionSort(head);
	}
};

int main()
{
	int n, num;
	cin >> n;
	LinkedList l;
	for(int i = 0; i < n; i++)
	{
		cin >> num;
		l.InsertatEnd(num);
	}
	l.InsertionSort();
	l.Print();
	return 0;
}