#include <iostream>
#include <string>

using std::cout;
using std::string;

extern float eval(string);
extern size_t closing_braket(string);

int main()
{
if ((int)eval("-1+5-3")==1) {cout << "test 1: passed\n";} else {cout << "test 1: failed\n";}
if ((int)eval("-10+(8*2.5)-(3/1,5)")==8) {cout << "test 2: passed\n";} else {cout << "test 2: failed\n";}
if ((int)eval("1+(2*(2.5+2.5+(3-2)))-(3/1.5)")==11) {cout << "test 3: passed\n";} else {cout << "test 3: failed\n";}

 if (closing_braket("(()()(()))")==9) {cout << "test 4: passed\n";} else {cout << "test 4: failed\n";}
}
