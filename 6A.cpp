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
		bool empty() const; 					// is list empty?
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
		  	    return -1;
	 		}	
	 		else
	 		{
	 			return head->elem;
	 		}
		};
		void addFront(const string& e); 		// add to front of list
		{
			SNode newNode = new SNode;
			newNode->elem=e;
			newNode->next=head;
			head=newNode;
		}
		void addBack(const string& e); 			// add to back of list
		{
			SNode temp = new SNode;
			Snode newNode = new SNode;
			newNode->elem=e;
			newNode->next=NULL;
			temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
				temp->next=newNode;
			}
		};
		void removeFront();			 			// remove from front
		{
			SNode temp = new SNode; 
			if(head==NULL)
			   return;
            if(head!=NULL&&next==NULL)
				  cout<<"Element removed is "<<head;
				  head==NULL;
 		    else
		 	{
		 		cout<<"Element removed is "<<head->elem;
			 	head = head->next;
			}
 		}; 
		void removeEnd();						// remove from end
		{
			SNode newNode = new SNode;
			temp=head;
			if(head==NULL)
		        return;
			if(head!=NULL&&next=NULL)
		 	    head==NULL;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=NULL;
		};
		void print(); 							// prints the SLL
};
