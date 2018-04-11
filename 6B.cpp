#include<iostream>
#include<string>
using namespace std;
template <class T> class SLinkedList;
template <class T>
class SNode { 
	/*   			
	objective: Create a class for a Node for Single Linked list
	input parameters: none
	output value: none
	description: SNode class defines the node structure 
	approach: Class defines data item is names element with datatype string 
			and link is named next pf snode type
	*/
	private:
	  T elem; 
	  SNode<T>* next; 
	friend class SLinkedList<T>; // provides SLinkedList access to SNode
};

template <class T>
class SLinkedList { 
	/*   			
	objective: Create a Single LInked List class 
	input parameters: none
	output value: none
	side effects: Class SlinkedList defines Single Linked LIst class
	approach: Class definition
	*/	
	
	private:
  	    SNode<T>* head; 							// pointer to the head of list					
	public:
		SLinkedList()							// empty list constructor
		{
			head=NULL;	
		};
		~SLinkedList()							// destructor
		{
			delete head;
		};
		bool empty() const 					// is list empty?
		{
	        if(head==NULL)
			  	return true;
			else 
		        return false;	
		};
		const T& front() const;
		void addBack(const T& e);
		void addFront(const T& e);
		void removeFront();
		void removeBack();
		void print();
};
template <class T>
const T & SLinkedList <T> :: front() const 			// get front element
		{
		 	if(head==NULL)
	 		{
		  	    return NULL;
			}	
			else
	 		{
				return head->elem;
			}
};
template <class T>
void SlinkedList <T>::addFront(const T & e) 		// add to front of list
{
			SNode<T> *newNode = new SNode;
			newNode->elem=e;
			newNode->next=head;
			head=newNode;
};
template <class T>		
void SlinkedList <T> :: addBack(const T& e) 			// add to back of list
		{
			SNode<T> *temp = new SNode<T>;
			SNode<T> *newNode = new SNode<T>;
			newNode->elem=e;
			newNode->next=NULL;
			if(head==NULL)
			{
				head=newNode;
			}
			else
			{
				temp=head;
				while(temp->next!=NULL)
				{
					temp=temp->next;
					temp->next=newNode;
				}
			}
		};
template <class T>		
void SlinkedList<T>::removeFront()			 			// remove from front
{
			SNode<T> *temp = new SNode<T>; 
			if(head==NULL)
			   return;
            else if(head->next==NULL)
            {
				  cout<<"Element removed is "<<head->elem;
				  head==NULL;
			}
 		    else
		 	{
		 		cout<<"Element removed is "<<head->elem<<"\n";
			 	head = head->next;
			}
}; 
template <class T>		
void SlinkedList<T>::removeBack()						// remove from end
		{
			SNode<T> *temp = new SNode<T>;
			temp=head;
			if(head==NULL)
		        return;
			if(head->next=NULL)
		 	    head==NULL;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=NULL;
		};
template <class T>
void SlinkedList<T>::print() 							// prints the SLL
		{
			SNode<T> *temp = new SNode<T>;
			temp=head;
			if(head==NULL)
	            cout<<"Empty list \n";
			if(head->next==NULL)
			    cout<<"Element in the list is  "<<head->elem<<"\n";
			while(temp->next!=NULL)
			{
				cout<<"Elements in the list are "<<temp->elem;
				temp=temp->next;
			}
			if (temp!=NULL)
   				cout<<" "<<temp->elem<<"\n";
		}
};

int main()
{
	SLinkedList <string>sll;
	string elem;
	char ch;
	do
	{
		cout<<"-----------------MENU-----------------\n";
		cout<<"1.Add Front\n";
		cout<<"2.Add Back\n";
		cout<<"3.Remove Front\n";
		cout<<"4.Remove Back\n";
		cout<<"5.Print List\n";
		cout<<"6.Print Front\n";
		cout<<"----------------Enter E to exit----------------\n";
		cout<<"-->>\t";
		cin>>ch;
		switch(ch)
		{
			case '1' :
				cout<<"Enter element to add\t\n";
				cin>>elem;
				sll.addFront(elem);
				break;
			case '2' :
				cout<<"Enter element to add in back\t\n";
				cin>>elem;
				sll.addBack(elem);
				break;
			case '3' :
				sll.removeFront();
				break;
			case '4' :
				sll.removeBack();
				break;
			case '5' :
				sll.print();
				break;
			case '6' :
				cout<<"Front element is \t"<<sll.front()<<"\n";
				break;
			default :
				if(ch!='e')
				{
					cout<<"Invalid Option! \n";
				}
				break;
		};
	}
	while(ch!='e');
} 