#include <iostream>

struct Person
{
std::string name;
std::string surname;
std::string adress;
};

void Person_def_ctor(Person* This);
void Person_param_ctor(Person* This, const char*, const char*, const char*);
void Person_copy_ctor(Person* This, const Person&);
Person& Person_op_as(Person* This, const Person&);
void Person_set_name(Person* This, const char* str){This -> name = str;}
void Person_set_surname(Person* This, const char* str){This -> surname = str;}
void Person_set_adress(Person* This, const char* str){This -> adress = str;}
void Person_print_name(Person* This){std::cout <<  This -> name;}
void Person_print_surname(Person* This){std::cout << This -> surname;}
void Person_print_adress(Person* This){std::cout << This -> adress;}

int main()
{

}
void Person_def_ctor(Person* This)
{
This -> name = "none";
This -> surname = "none";
This -> adress = "none";
}

void Person_param_ctor(Person* This, const char* str1, const char* str2, const char* str3)
{
This -> name = str1;
This -> surname = str2;
This -> adress = str3;
}

void Person_copy_ctor(Person* This, const Person& rhs)
{
This -> name = rhs.name;
This -> surname = rhs.surname;
This -> adress = rhs.adress;
}

Person& Person_op_as(Person* This, const Person& rhs)
{
if(This == &rhs)
{
return *This;
}

This -> name = rhs.name;
This -> surname = rhs.surname;
This -> adress = rhs.adress;

return *This;
}
