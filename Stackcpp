/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

template <typename T>
class Stack 
{
    public:
        Stack() : size(1), buffer(new T[size]) {}
        ~Stack() { delete [] buffer; }
    
    public:
        void push(T);
        void pop();
        T& top();
        int Size();
        bool empty();
        
    private:
        int size;
        T* buffer;
};

template <typename T>
void Stack<T>::push(T data)
{
    if(size % 2 == 0)
    {
        T* tmp = buffer;
        buffer = new T[size + 1];
         for(int i = 0; i < size - 1; ++i)
         {
             buffer[i] = tmp[i];
         }
         buffer[size - 1] = data;
         ++size;
          delete [] tmp;
    }
    else {
    buffer[size - 1] = data;
    ++size;
    }
}

template <typename T>
void Stack<T>::pop()
{
    if(size == 1) 
    {
        throw std::logic_error("Stack is empty");
    }
    
    else {
        
    T* tmp = buffer;
    buffer = new T[size - 1];
     for(int i = 0; i < size - 2; ++i)
     {
         buffer[i] = tmp[i];
     }
     --size;
     delete [] tmp;
    }
}

template <typename T>
bool Stack<T>::empty()
{
    return size - 1;
}

template <typename T>
int Stack<T>::Size()
{
    return size - 1;
}

template <typename T>
T& Stack<T>::top()
{
    return buffer[size - 2];
}

int main()
{
    Stack<int> st;
    return 0;
}
