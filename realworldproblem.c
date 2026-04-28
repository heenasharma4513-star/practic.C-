#include <iostream>
using namespace std;
class stack
{ protected:
    int arr[100];
    int top;
    stack()
    {
        top=-1;
    }
    void push(int x)
    {
        arr[++top]=x;
    }
    void pop()
    {
        if (top==-1)
        {
            cout<<"underdefined";
            return-1;
        }
        void display()
        {
            for (int i =top;i >=0;i--0)
            {
                cout<<arr[i];
            }
        };
        //single inheitance
        class browserstock: public stack
        {
            public:
            void visitpage(int page){
                push(page);
            }
        };
        //multilevel
        class serverbrowserstack: public browserstack
        {
            public:
            void secure visit(int page)
            {
                visitpage(page);        
              }
        };
        // hierarchical
        class undostack:public stack
        {
            public:
            void undo()
            {
                pop();
            }
        };
        class redostack:public stack
        {
            public:
            void redo()
            {
                pop();
            }
        };
        class editorstack: public undostack, public redostack
        {
            v
        }
    }
}
// poly morphism-- more than one form or msny form thi property makes the same entity sucha s fxns and operators perform differnetky in diff senerio