#include<iostream>
#include<stack>
#include<fstream>
using namespace std;

template<typename T>
class stack{
    private:
           std::stack<T> s;   
    public:
           void push(T value){
            s.push(value);    
           }  

           void pop(){
            if(!s.empty())    
                s.pop();
            else
                cout<<"stack is empty\n";
           }     

           T top(){
            if(!s.empty())    
               return s.top();
            throw runtime_error("stack empty");   
           }

           bool isEmpty(){    
            return s.empty(); 
           }
};

class logger{
    public:
           void log(string action){
            ofstream file("log.txt", ios::app);  
            file<<action<<endl;
            file.close();                        
           }
};

class Editor{
    private:
           stack<string> undoStack;   
           stack<string> redoStack;   
           logger loggerObj;          

    public:
           void performAction(string action){
            undoStack.push(action);

            while(!redoStack.isEmpty()){   
                redoStack.pop();           
            }   

            loggerObj.log("performed: " + action);
            cout<<"Action performed: " << action << endl;
           }

    void undo(){
         if (!undoStack.isEmpty()){
            string action = undoStack.top();
            undoStack.pop();
            redoStack.push(action);

            loggerObj.log("undo: " + action);
            cout<<"undo: "<< action << endl;

         } else{
            cout<<"Nothing to undo\n";
         }
    }

    void redo(){
        if(!redoStack.isEmpty()){
            string action = redoStack.top();   
            redoStack.pop();
            undoStack.push(action);

            loggerObj.log("redo: " + action);
            cout<<"redo: "<< action << endl;
        } else{
            cout<<"Nothing to redo\n";
        }
    }
};