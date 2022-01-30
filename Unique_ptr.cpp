#include <iostream>

struct Default {};
struct Array {};

template <typename T, class K = Default>
class SmartPointer
{
public:
SmartPointer() {}
~SmartPointer()
 {
if(ptr_ != nullptr)
{
tmp = typeid(K).name();

 if(tmp == "7Default") {
 delete ptr_; }
 
else  delete [] ptr_;

}
}

SmartPointer(T* ptr) : ptr_(ptr) {}
SmartPointer(const SmartPointer&) = delete;
SmartPointer& operator=(const SmartPointer&) = delete;
SmartPointer(SmartPointer&&);
SmartPointer& operator=(SmartPointer&&);

public:
T& operator*() {return *ptr_;}
friend std::ostream& operator<<(std::ostream& os, const SmartPointer& obj) // otherwise it would be cast to bool
{
std::cout << obj.ptr_;
return os;
}
operator bool() {return (ptr_ != nullptr);}
T* operator->() {return this -> ptr_;}

private:
T* ptr_ {};
std::string tmp {};
};

template <typename T, typename K>
SmartPointer<T, K>::SmartPointer(SmartPointer&& obj)
{
	obj.ptr_ = this -> ptr_;
	this -> ptr_ = nullptr;
}

template <typename T, typename K>
SmartPointer<T, K>& SmartPointer<T, K>::operator=(SmartPointer&& rhs)
{
	if(this == &rhs)
		{
 			return *this;
		}
	else {
		delete this -> ptr_;

		this -> ptr_ = rhs.ptr_;
		rhs.ptr_ = nullptr;
	     }
	return *this;
}


int main()
{
SmartPointer<int, Array> sm(new int[5]);
}
