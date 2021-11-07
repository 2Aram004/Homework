#include <iostream>
#include <cstring>

class Utility
{

 public:
 Utility() {}
 static bool is_Number(std::string);
 static bool is_Integer(std::string);
 static bool is_Float(std::string);
 static bool is_Bool(std::string);
 static bool is_email(std::string);
 static bool is_url(std::string);
 static bool is_URL(std::string);
};

bool Utility::is_Bool(std::string str)
{
 if(str == "true" || str == "false")
  return true;

 else
   return false;
}
bool Utility::is_Float(std::string str)
{

  int k = 0;	
  char arr[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  int check = 0;

  if(k > 1 || str[0] == '.' || str[str.size() - 1] == '.')  return false;

	
 for(int i = 0; i < str.size(); ++i)
 {

  if(str[i] == '.' && k == 0)
  {
	  ++check;
	  ++k;
  }
  else if(str[i] == '.' && k > 1)
  {
	  return false;
  }  
  for(int j = 0; j < 10; ++j )
{  
  if(str[i] == arr[j])
{ 
  ++check;
}
}
 }

 if(check == str.size() && k == 1)
 {
  return true;

 }
else 
 return false;

}
bool Utility::is_Integer(std::string str)
{
  char arr[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  int check = 0;

 for(int i = 0; i < str.size(); ++i)
 {
 	 
  for(int j = 0; j < 10; ++j )
{
 
  if(str[i] ==  arr[j])
{
  
  ++check;
} 
}
 }
 if(check == str.size())
 {
  return true;

 }
else 
 return false;
}

bool Utility::is_Number(std::string str)
{
	if(is_Integer(str) || is_Float(str))
		return true;
	else 
		return false;
}

bool Utility::is_URL(std::string str)
{
	std::string res;
	std::string res2;


	if(str[8] ==  '.'){
		 res = str.substr(0, 8);
	}	
	if(res != "https://"){
	
	
	 if(str[3] == '.'){
		res = str.substr(0, 3);}
	if(res != "www"){
        return false;}}       
		
if((str[str.size() - 3] == '.') || (str[str.size() - 2] == '.')){
		
res2 = str.substr(str.size() - 2);
if(res != "com"){
 res2 = str.substr(str.size() - 1);
 
  if(res != "ru" || res != "am")
  {
  return false;
  }
}
	}
return true;
}

bool Utility::is_email(std::string str)
{
bool b = false;
if(str.size() > 256){return false;}

if(str[0] == '@'){return false;}

for(int i = 1; i < str.size(); ++i)
{
 if(str[i] == '@'){
	 break;
 }
	else if(i == str.size())
		return false;

}
if(str[0] == '.')
{return false;}
 
for(int i = 0; i < str.size(); ++i) 
{
 if (str[i] == '#'){
	
   return false;
 }
}


for(int i = 0; i < str.size(); ++i)
{
 
  if(str[i] == '.' || str[i] == '-' )
{
    if(str[i + 1] >= 'A' && str[i + 1] <= 'z') 
          b = true;
     
         
} 

}
if(b == false)
{

 return false;
}
if(str[str.size() - 3] == '.'){
std::string nres = str.substr(str.size() - 3);
std::cout << nres << std::endl;
if(nres != "com" && nres != "gov" && nres != "edu" && nres != "net" && nres != "net"){return false;}
}
return true;
}



int main()
{
std::cout << Utility::is_Integer("23777777777777");
//std::cout <<  Utility::is_email("aram.vard@mail.n
}
