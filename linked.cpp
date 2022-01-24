#include<iostream>
using namespace std; 
class linkedList {
private:
	struct Node 
	{
		int info; 
		Node* next; 

	};

	Node* front;
	Node* back;
	int length; 

public:
	linkedList(){
		back = front = NULL;
		length = 0; 
	}

	bool isEmpty() 
	{
		return length == 0; 
	}

	void Infront(int item) {
		Node* newNede = new Node;
		newNede->info = item;
		if (length == 0)
		{
			front = back = newNede;
			newNede->next = NULL;
		}
		else {
			newNede->next = front; 
			front = newNede;//     
		}

		length++;
	}

	void Inback(int item) {
		Node* newNede = new Node;
		newNede->info = item;
		if (length == 0)
		{
			front = back = newNede;
			newNede->next = NULL;
		}
		else {

			back->next = newNede;
			newNede->next = NULL;
			back= newNede;
		
		}


		length++;
	}
	void insertAtPos(int pos ,  int item  ) {
		if (pos > length || pos < 0) {
			cout << "out of the renge . ";
		}

		else {
			Node* newnode = new Node;
			newnode->info = item;
			if (pos == 0) { Infront(item); }
			else if (pos == length) { Inback(item); }
			else
			{
				Node* curr = front;
				for (int i = 1; i < pos; i++)
					curr = curr->next;
				newnode = curr->next;
				curr->next = newnode;
				length++;
			}
		}

	}

	void Print() {
	
		Node* cur = new Node;
		cur = front ; 
		while (cur != NULL )
		{
			cout << cur->info << " ";
			cur = cur->next; 
		}

	}

	void removeBack() {
		// if (isEmpty) { cout << "isEmpty"; return; }
		
 
		if (length == 0) {
			delete front;
			front = back = NULL;
			length--;
		}
		else {

			Node* cur=front;
			Node* before=front;

			while (cur!=back  )
			{
				before = cur;
				cur = cur->next;
			}
			back = before;
			before->next = NULL; // ==   back ->next =NULL ;
			length--;

			delete cur;
		}


	
	} 

	void removeItem (int item )
	{
		//if (isEmpty) { cout << "isEmpty"; return; }
		
		if (front->info == item) {
			Node*cur = front;
			front = front->next;
			length--; 
			delete cur;

		
		}
		else if (back->info == item) { removeBack(); }

		else
		{
			Node* cur = front->next;
			Node* Before = front;
			bool l = true;
			while (l && cur!= NULL)
			{
				if (cur->info == item) {
					Before->next = cur->next;
					l = false; 
				     
				}
				else
				{
					cur=cur->next;
					Before = Before->next;
					  //  mean ::   continue ;
				}
			}


		}

	
	}












	
};

int main() {



	linkedList k; 
	k.Inback(5);
	k.Infront(12);
	k.Infront(155);
	k.Inback(0);
	 
	k.removeItem(12);
	k.removeItem(0);
	k.Print();







}
