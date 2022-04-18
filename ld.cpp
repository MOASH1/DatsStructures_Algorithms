#include<iostream>
using namespace std ;

struct DLLNode{
    int data ;
    DLLNode* next ;
    DLLNode* prev;
};

class linkedlist
{
private:
   DLLNode* head;
   DLLNode* tail;
   int count ; 
public:
    linkedlist(){
        head = NULL;
        tail = NULL;
        count = 0;
    }

    bool isempty()
    {
        return(head==NULL);
    }

    void destroy()
    {
        DLLNode *temp;

        while (head != NULL)
        {
            temp =head ;
            head =head->next;
            delete temp;
        }
        tail = NULL;
        count =0;
    }
    void insertLast(int val);
    void insertFirst(int val);
    void insertAt(int val , int pos);
    void removeFirst();
    void removeLast();
    ~linkedlist();
};

void linkedlist::insertLast(int val){
   DLLNode* newnode = new DLLNode;
   newnode->data= val;
   if(count==0)                      //الاضافة في اخر الاست
   {
       head = tail = newnode ;
       newnode->next =newnode->prev = NULL;
   }
    else{
        newnode->next = NULL; //النود الجديدة النكست تؤشر الي نل
        newnode->prev = tail;//و البريفيز تؤشر الي اخر نود
        tail->next=newnode;//و النود الاخيرة تؤشر الي النود الجديدة 
        tail = newnode;//الان نغير النود الاخيرة لتصبح النود الجديدة
    }
count++;
}

void linkedlist::insertFirst(int val){

      DLLNode* newnode = new DLLNode ;
      newnode->data = val;              //الاضافة في لامام

      if (count == 0 )
      {
          head = tail = newnode ; 
          newnode->next = newnode->prev = NULL;
      }
        else{
              newnode->next = head ;     //نضع النود الجديدة في الامام 
              newnode->prev = NULL ;     //نضع مؤشر البريفيز الي النل 
              head->prev=newnode;        //نضع البريفيز النود الاولي يؤشر علي النود الجديدة
              head = newnode ;           //نضع النود الجديدة في الامام
                        
        }
    count++;
        
}

void linkedlist::insertAt(int val , int pos){

    if(pos<0||pos >count)
          cout<<"out of range...."<<endl ;
          else
          {
              DLLNode *newnode = new DLLNode;
              newnode->data = val ;
              if(pos == 0)
              insertFirst(val);
              else if(pos == count)
              insertLast(val);
              else
              {
                DLLNode *current = head ;
                for(int i = 1 ; i<pos ; i++)
                {
                    current =current->next;
                }
                newnode->next = current->prev;
                newnode->prev=current ; 
                current->next->prev=newnode;
                current->next = newnode;
                count++;
              }
          }
}

void linkedlist::removeFirst(){
    if(count == 0)
    cout<<"empty list!!!!!"<<endl ; 
    else if(count == 1)
    {
        delete head ;
        tail =head =NULL;
    }
    else
    {
        DLLNode* currnet = head ; // النود الحالي يؤشر علي اول نود
        head = head->next;        //نغير اوا نود لتؤشر علي النود التي تليها
        head->prev = NULL ;       // البريفيز للنود الاول نجعلها نل  
        delete currnet ;          // نمسح النود الاول
    }
count--;
}

void linkedlist::removeLast(){
    if(count == 0 )
    cout<<"empty list"<<endl ;
    else if (count ==1){
    delete head ;
    tail = head = NULL ;
    count--;
    }
    else
    {
        DLLNode *current = tail ;
        tail = tail->prev ; 
        tail->next =NULL;
        delete current ;
        count--;
    }

   

}







int main(){


}