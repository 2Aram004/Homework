#include <iostream>

class Person
{
public:
Person() : name("none"), surname("none"), adress("none"){ }
~Person(){ }
Person(const char*, const char*, const char*);
Person(const Person&);
Person& operator=(const Person&);
std::string get_name(){return name;}
std::string get_surname(){return surname;}
std::string get_adress(){return adress;}
void set_name(std::string n_str){name = n_str;}
void set_surname(std::string s_str){surname = s_str;}
void set_adress(std::string a_str){adress = a_str;}

private:
std::string name;
std::string surname;
std::string adress;
};

Person::Person(const char* str1, const char* str2, const char* str3)
{
name = str1;
surname = str2;
adress = str3;
}

Person::Person(const Person& rhs)
{
 name = rhs.name;
 surname = rhs.surname;
 adress = rhs.adress;
}

Person& Person::operator=(const Person& rhs)
{
if(this == &rhs)
{
 return *this;
}
name = rhs.name;
surname = rhs.surname;
adress = rhs.adress;

return *this;
}
int main()
{
Person obj;
Person obj2(obj);

}
