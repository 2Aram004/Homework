#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <regex>
#include <string>

std::ifstream fin;




class Cpu
{
public:
Cpu(){}
~Cpu(){}
void read();

private:
std::streampos oldpos;
std::ofstream fout;
std::vector<std::string> vec;
void CR_jump();
double decide(std::string);
};


double Cpu::decide(std::string str)
{
std::regex number ("^[1-9][0-9]+$");
std::regex flot ("^[0-9]+\.[0-9]+$");
std::regex address ("^0+[0-9]+$");

if(std::regex_search(str, flot)){return std::stof(str);}


else if(std::regex_search(str, number)) {return std::stoi(str);  }
}


void Cpu::read()
{
fin.open("text.txt");
if(!fin.is_open()) {
std::cout << "Could not open file";
exit(0);
}
else{
std::string str;
getline(fin, str);
std::istringstream s(str);

while(!s.eof())
{
s >> str;
vec.push_back(str);

}


for(int i = 0; i < vec.size(); ++i){
if(vec[i] == "OMAEVA"){OMAEVA(decide(vec[2]));}

else if(vec[i] == "MO"){MO(decide(vec[2]));}

else if(vec[i] == "SHIM") {SHIM(decide(vec[2]));}

else if(vec[i] == "DEYRU") {DEYRU(decide(vec[2]));}

else if(vec[i] == "NANI") {NANI(decide(vec[2])); }

else if(vec[i] == "JUCU") {JUCU(decide(vec[2]));}

else if(vec[i] == "NOCU") {NOCU(decide(vec[2])); }

else if(vec[i] == "KIA") {KIA(decide(vec[2]));}

else if(vec[i] == "JUMPO>") {JUMPO>(decide(vec[2]));}

else if(vec[i] == "JUMPO<") {JUMPO<(decide(vec[2]));}

else if(vec[i] == "JUMPO=") {JUMPO=(decide(vec[2]));}

else if(vec[i] == "JUMPO!") {JUMP!(decide(vec[2]));}
}
std::cout << "\nERROR\n";
vec.clear();
exit(0);

}
}

void Cpu::CR_jump()
{
for(int i = 0; i < vec.size(); ++i){
if(vec[0] == ":")
oldpos = fin.tellg();

if(vec[0] == "jump")
{
 fin.seekg(oldpos);
  read();
}

}
}
int main()
{
Cpu obj;
while(!fin.eof()){
obj.read();
}

}
