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
		Node *tmp = head, *a = tmp;
		while(tmp != NULL)
		{
			a = tmp;
			tmp = tmp->next;
			delete a;
		}
	}
	/*~LinkedList()
	{
		Node *tmp = head;
		while(tmp != NULL)
		{
			tmp = head;
			head = head->next;
			delete tmp;
		}
	}*/

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

	Node* InsertionSort(Node *h)
	{
		if(h == NULL || h->next == NULL) return h;
		Node *nh = InsertionSort(h->next);
		h->next = nh;
		if(h->data < h->next->data) return h;
		Node *cur = h;
		while(cur->next != NULL)
		{
			if(h->data < cur->next->data)
			{
				Node *tmp = h->next;
				h->next = cur->next;
				cur->next = h;
				h = tmp;
				return h;
			}
			cur=cur->next;
		}
		///cur = cur->next;
		Node *tmp = h->next;
		h->next = NULL;
		cur->next = h;
		h = tmp;
		return tmp;
	}

	void InsertionSort()
	{
		head = InsertionSort(head);
	}
};

int main()
{
	int n, num;
	LinkedList l;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> num;
		l.InsertatEnd(num);
	}
	l.InsertionSort();
	l.Print();
	return 0;
}
