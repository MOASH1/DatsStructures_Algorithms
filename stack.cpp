#include<iostream>
#include<string>
#include<sstream>
using namespace std;
 const int MAX_SIZE = 5 ;
 template<class t>

 class stack{
     private:
     int top ; 
     t item [MAX_SIZE];


public:
stack():top(-1){};

bool isEmpty()
{
return top<0 ;
}

void push(t Element)
{
    if(top>=MAX_SIZE-1)
    {
        cout<<"stack is full";
    }
    else
    {
        top++;
        item[top]=Element ;
    }

}

void pop()
{
  if(isEmpty())
  cout<<"stack empty";
  else 
  top--;

}

int Top(){
    return top;
}
void getTop(t&stacktop)
{
    if(isEmpty())
    cout<<"stack empty";

else{
    stacktop = item[top];
    cout<<stacktop<<endl;

}
}
void printstack(){
cout<<"[ ";
for (int i = top; i >= 0; --i)
{
    cout<<item[i]<<" ";
}
cout<<"]";
cout<<endl;

}

};



int main(){
    


    int n;
    cin>>n;
    string word;
    while (n--)
    {
        cin>>word;
        if(word.length()<=10)
        {
            cout<<word<<endl;
        }
        else{
            cout<<word[0]<<word.length()-2<<word[word.length()-1]<<endl;
        }
    }
    
   

    
    return 0;
}