#include<iostream>
#include<string>
using namespace std;
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
	  string elem; 
	  SNode* next; 
	friend class SLinkedList; // provides SLinkedList access to SNode
};


class SLinkedList { 
	/*   			
	objective: Create a Single LInked List class 
	input parameters: none
	output value: none
	side effects: Class SlinkedList defines Single Linked LIst class
	approach: Class definition
	*/	
	
	private:
  	    SNode* head; 							// pointer to the head of list					
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
		const string& front() const 			// get front element
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
		void addFront(const string& e) 		// add to front of list
		{
			SNode *newNode = new SNode;
			newNode->elem=e;
			newNode->next=head;
			head=newNode;
		};
		
		void addBack(const string& e) 			// add to back of list
		{
			SNode *temp = new SNode;
			SNode *newNode = new SNode;
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
		
		void removeFront()			 			// remove from front
		{
			SNode *temp = new SNode; 
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
		void removeBack()						// remove from end
		{
			SNode *temp = new SNode;
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
		void print() 							// prints the SLL
		{
			SNode *temp = new SNode;
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
		};
};

int main()
{
	SLinkedList sll;
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
