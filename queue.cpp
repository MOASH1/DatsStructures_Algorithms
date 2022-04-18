#include<iostream>
#include<cassert>

using namespace std;

class arryQueueType
{
    private:
    int rear;
    int front;
    int lenght;
    int *arr;
    int maxSize;
public:
arryQueueType(int size){
if(size <=0)
maxSize = 100;
else 
maxSize =size ;


front = 0;
arr = new int[maxSize];
rear =maxSize -1;
lenght =0 ;
}

int isempty()
{
    return lenght == 0;
}

bool isfull()
{
    return lenght == maxSize;
}

void EnQueue(int element)
{
    if(isfull())
    {
        cout<<"queue is full sorry about thaht";
    }
    else{
        rear = (rear + 1)%maxSize;
        arr[rear]=element;
        lenght++;
    }
}

void DeQueue()
{
    if(isempty())
    {
        cout<<"queue is empty ";
    }
    else
    {
        front = (front +1)%maxSize;
        --lenght;
    }
}

int frontqueue()
{
    assert(!isempty());
    return arr[front];
}

int rearqueue()
{
    assert(!isempty());
    return arr[rear];
}

void PrintQueue()
{
   if(!isempty())
   {
       for(size_t i = front; i!= rear;i=(i+1)%maxSize)
       {
           cout<<arr[i]<<" ";
       }
        cout<<arr[rear];
   }
   else
        cout<<"empty queue";

}

int queueSearch(int element){
int pos = -1;
if(!isempty())
{
    for(int i =front;i!=rear;i=(i+1)%maxSize)
        if(arr[i]==element)
       {
            pos =i;
            break;
        }
        if(pos == -1)
        {
            if(arr[rear]==element)
            pos =rear;
        }
}
else
cout<<"queue is empty"<<endl;
return pos;
}

~arryQueueType() {
		delete[]arr;
	}


};





int main(){
    int n ; 
    cin>>n ;
    cout<<n;
arryQueueType q1(8);
q1.EnQueue(100);
q1.EnQueue(56);
q1.EnQueue(1);
q1.EnQueue(89);
q1.DeQueue();
q1.PrintQueue();
q1.frontqueue();

}