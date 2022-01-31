#include <iostream>
 
namespace Utility
{
struct Default {
Default() = delete;
 };

struct Array {
Array() = delete;
 };

};

template <typename T, class K = Utility::Default>
class SmartPointer
{
public:
SmartPointer() {}
~SmartPointer();
SmartPointer(T* ptr) : ptr_(ptr) {}
SmartPointer(const SmartPointer&) = delete;
SmartPointer& operator=(const SmartPointer&) = delete;
SmartPointer(SmartPointer&&);
SmartPointer& operator=(SmartPointer&&);

public:
T& operator*() {return *ptr_;}
friend std::ostream& operator<<(std::ostream& os, const SmartPointer& obj); // otherwise it would be cast to bool

operator bool() {return (ptr_ != nullptr);}
T* operator->() {return this -> ptr_;}
T& operator[](const int index) const {return this -> ptr_[index];}
void reset();
void Swap(SmartPointer&);
T* get() {return this -> ptr_;}
void release() { this -> ptr_ = nullptr; }


private:
T* ptr_ {};
std::string tmp {};
};

template <typename T, typename K>
SmartPointer<T, K>::SmartPointer(SmartPointer&& obj)
{
	this -> ptr_ = obj.ptr_;
	this -> tmp =  obj.tmp;
	obj.ptr_ = nullptr;
	obj.tmp = {};
}

template <typename T, typename K>
SmartPointer<T, K>& SmartPointer<T, K>::operator=(SmartPointer&& rhs)
{
	if(this == &rhs)
		{
 			return *this;
		}
	else {
		if(this -> ptr_) {
		delete this -> ptr_; 
	}	
		this -> ptr_ = rhs.ptr_;
		this -> tmp = rhs.tmp;
		rhs.ptr_ = nullptr;
		tmp = {};
	     
	return *this; 
 }
}

template <typename T, class K>
std::ostream& operator<<(std::ostream& os, const SmartPointer<T, K>& obj)
{
std::cout << obj.ptr_;
return os;
}


template <typename T, class K>
SmartPointer<T, K>::~SmartPointer()
 {
if(ptr_ != nullptr)
{
tmp = typeid(K).name();

 if(tmp == "7Default") {
 delete ptr_; }
 
else  delete [] ptr_;
}
}

template <typename T, class K>
void SmartPointer<T, K>::Swap(SmartPointer& rhs)
{
SmartPointer<T, K> tmp(std::move(rhs));
rhs = std::move(*this);
*this = std::move(tmp);
}

template <typename T, class K>
void SmartPointer<T, K>::reset()
{
delete this -> ptr_; 
this -> ptr_ = nullptr;
}

int main()
{
SmartPointer<int, Utility::Array> Sm(new int[2]);
}
