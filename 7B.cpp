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
		  	    cout<<"Empty Queue\n";
	 		}	
	 		else
	 		{
	 			cout<<"Front Element is \t" <<head->elem<<"\n";
	 		}
		};
		const string& back() const 			// get back element
		{
		 	if(head==NULL)
	 		{
		  	    cout<<"Empty Queue\n";
	 		}	
	 		else
	   		{
	   			SNode *temp= new SNode;
	   			temp=head;  
      			if (temp->next==NULL)
           			return temp->elem;
	   			else
	    		while(temp->next!=NULL)
	      		{
		  			temp=temp->next;
	     		};
	      		return temp->elem;
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
			temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
				temp->next=newNode;
			}
		};
		void removeFront()			 			// remove from front
		{
			SNode *temp = new SNode; 
			if(head==NULL)
			   cout<<"Queue Empty:\n";
            else if(head->next==NULL)
            {
				  cout<<"Element removed is "<<head->elem<<"\n";
				  head==NULL;
			}
 		    else
		 	{
		 		cout<<"Element removed is "<<head->elem<<"\n";
			 	head = head->next;
			}
 		}; 
 		void removeEnd()						// remove from end
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
	            cout<<"Empty Queue \n";
			if(head->next==NULL)
			    cout<<"Element in the queue is  "<<head->elem<<"\n";
			while(temp->next!=NULL)
			{
				cout<<"Elements in the queue are "<<temp->elem<<" ";
				temp=temp->next;
			}
		};
};

int main()
{
	SLinkedList st;
	string str;
	char ch;
	do
	{
		cout<<"---------------MENU-------------\n";
		cout<<"1.Enqueue\n";
		cout<<"2.Dequeue\n";
		cout<<"3.Show Front\n";
		cout<<"4.Show Rear\n";
		cout<<"5.Display Queue\n";
		cout<<"Enter e or E to exit\n";
		cin>>ch;
		switch(ch)
		{
			case '1':
				cout<<"Enter element to push\t";
				cin>>str;
				st.addFront(str);
				break;
			case '2':
				st.removeFront();
				break;
			case '3':
				st.front();
				break;
			case '4':
				st.back();
			case '5':
				st.print();
				break;	
			default:
				if(ch!='e')
					cout<<"INVALID! OPTION\n";
				break;
		};
	}
	while(ch!='e');
} 
