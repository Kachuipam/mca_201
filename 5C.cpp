// Program to implement QUEUE using STACK
#include<iostream>
#include<stack>

using namespace std;

class queue
{
    int last;
    stack<int>st;
    public:
        void enQueue(int elem);
        int deQueue();
        bool isEmpty();
        int front();
        int rear();
        void displayQueue();
};

bool queue::isEmpty()
{
    if(st.empty())
        return true;
    else
        return false;
}

int queue::front()
{   stack<int> st1;
    int temp;
    if(st.empty())
        return -1;
    else{
	
     while(!st.empty())
      {
      	st1.push(st.top());
      	st.pop();
	  };
	  temp=st1.top();
	  while(!st1.empty())
      {
      	st.push(st1.top());
      	st1.pop();
	  }
	  return temp;
     }
};

int queue::rear()
{
	if(st.empty())
		return -1;
	else
		return st.top();
}
void queue::enQueue(int elem)
{
    st.push(elem);    
};
int queue::deQueue()
{   stack<int>st1;
    int temp,temp1;
    if(st.empty())
        cout<<"Queue is Empty!\n";
    else
        while(!st.empty())
        {
            temp = st.top();
            st.pop();
            st1.push(temp);
        }
        temp1 = st1.top();
        //cout<<"element popped is : "<<temp1<<endl;
        st1.pop(); 
        //cout<<"after popping top is : "<<st1.top();
        while(!st1.empty()) 
           {
               temp = st1.top();
               st1.pop();
            st.push(temp);
           }
        return temp1;
};

int main()
{
    queue Q;
    Q.enQueue(4);
    Q.enQueue(5);
    Q.enQueue(6);
    cout<<"front is "<<Q.front()<<endl;
    
    Q.deQueue();
    cout<<"after dequeing front is :"<<Q.front();
}
