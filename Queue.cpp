#include <iostream>

template <typename T>
class Queue {

public:
    Queue() {front = 0; back = -1;}
    void enqueue(const T& value);
    void dequeue();
    bool IsEmpty() {return front > back;}
    T ret_front();
    T ret_back();

private:
    static const int MAX_SIZE = 50;
    int back;
    int front;
    T arr[MAX_SIZE];


};

template <typename T>
T Queue<T>::ret_back()
{
    if(!IsEmpty())
    {
        return arr[back];
    }
   
   else {
    throw std::logic_error("Queue is empty!");
}
}

template <typename T>
T Queue<T>::ret_front()
{
    if(!IsEmpty())
    {
        return arr[front];
    }
   
   else {
    throw std::logic_error("Queue is empty!");
   }
}

template<typename T>
void Queue<T>::enqueue(const T& value)
{
    back++;
   
    if(back < MAX_SIZE)
    {
        arr[back] = value;
    }
}

template<typename T>
void Queue<T>::dequeue()
{
    if(!IsEmpty())
    {
        front++;
    }
}

int main()
{
  Queue<int> que;
  return 0;
}
