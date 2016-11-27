#include <iostream>
#include <string>
#include <stdexcept>  

using std::cin;
using std::cout;
using std::string;
using std::invalid_argument;

extern float eval(string);
extern float round_100(float);

int main()
{
  
  while (true)
    { 
      string in;
      cout << "Входное выражение: ";
      std::getline(cin,in);
      try 
	{
	//  cout << "Результат: "<< round_100(eval(in)) << "\n";
cout << "Результат: "<< eval(in) << "\n";
	}
      catch  (invalid_argument& ia)
	{
	 cout << "Результат: некорректный ввод, строка содержит недопустимое выражение " <<ia.what() <<"\n";
	}
      
    }

}
