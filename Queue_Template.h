/************************************************************************
 * AUTHOR			: James Davis
 ************************************************************************/
#ifndef QUEUE_TEMPLATE_H_
#define QUEUE_TEMPLATE_H_

#include<iostream>
#include<iomanip>
using namespace std;

template <class object>
class Queue
{
public:
	Queue();
	~Queue();

	void   Enqueue(const object& item);
	object Dequeue();
	object Front();
	int    Size(){return size;};
	bool   IsEmpty(){return head == NULL;};
	void   ClearQueue();
	bool   CheckExistingEmail(string compareEmail);

	struct node
	{
		object data;
		node* prev;
		node* next;
	};

private:
	node* head;
	node* tail;
	int size;
};

template <class object>
Queue<object>::Queue()
: head(NULL), tail(NULL), size(0)
{	}

template <class object>
Queue<object>::~Queue()
{
	delete head;
	delete tail;
}

template <class object>
void Queue<object>::Enqueue(const object& item)
{
	node* dataPtr = new node;
	node* sortPtr = new node;
	dataPtr->data = item;
	dataPtr->next = NULL;
	dataPtr->prev = NULL;
	sortPtr->next = NULL;
	sortPtr->prev = NULL;

	if(IsEmpty())
	{
		// Link the list to the node
		head = dataPtr;
		tail = dataPtr;
	}
	else if(head->data.GetName() > dataPtr->data.GetName())
	{
		// link the node to the list
		dataPtr->next = head;

		// link the list to the node
		head->prev = dataPtr;
		head       = dataPtr;
	}
	else
	{
		// Starts sorting the new node at the front
		sortPtr = head;

		// Finds the location of the new node by
		//  running the sort pointer through the list
		while(sortPtr->next != NULL &&
			  dataPtr->data.GetName() > sortPtr->data.GetName())
		{
			sortPtr = sortPtr->next;
		}

		/********************************************
		 * Checks if the new node should be added to
		 * the end of the list and adds it. If the
		 * new node needs to be added somewhere in
		 * the center of the list, the sort ptr will
		 * be pointing to the node just after where
		 * the new node should be placed in the list
		 * and adds accordingly.
		 *******************************************/
		if(dataPtr->data.GetName() < sortPtr->data.GetName())
		{

			// Link the node to the list.
			dataPtr->next = sortPtr;
			dataPtr->prev = sortPtr->prev;

			// Link the list to the node
			sortPtr->prev->next = dataPtr;
			sortPtr->prev       = dataPtr;
		}
		else
		{
			// link the node to the list
			dataPtr->prev  = sortPtr;

			// link the list to the node
			sortPtr->next = dataPtr;
			tail          = dataPtr;

		} // END if(sortPtr->next == NULL)

		sortPtr = NULL;

	} // END if(head->name > dataPtr...)

	dataPtr = NULL;
	size++;
}

template <class object>
object Queue<object>::Dequeue()
{
	object item;

	if(!IsEmpty())
	{
		node* dataPtr = head;

		if(head == tail)
		{
			head = NULL;
			tail = NULL;
		}
		else
		{
			head = head->next;
			head->prev = NULL;
		}
		item = dataPtr->data;
		delete dataPtr;
		dataPtr = NULL;
		size--;
		return item;
	}
	else
	{
		std::cout << "The Queue is empty, cannot dequeue!";
	}
}

template <class object>
object Queue<object>::Front()
{
	if(!IsEmpty())
	{
		return head->data;
	}
	else
	{
		std::cout << "Nobody in FRONT, the queue is empty!!";
	}
}

template <class object>
void Queue<object>::ClearQueue()
{
	while(!IsEmpty())
	{
		Dequeue();
	}
}

template <class object>
bool Queue<object>::CheckExistingEmail(string compareEmail)
{
	bool found = false;
	node *srcPtr;
	srcPtr = head;
	while(srcPtr != NULL && !found)
	{
		if(srcPtr->data.email == compareEmail)
		{
			found = true;
		}
		else
		{
			srcPtr = srcPtr->next;
		}
	}
	srcPtr = NULL;
	return found;
}

#endif /* QUEUE_TEMPLATE_H_ */
