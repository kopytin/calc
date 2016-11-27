#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>      
#include <stdexcept>      

#include <math.h>
using std::cin;
using std::cout;
using std::cerr;
using std::string;
using std::invalid_argument;

template <class T> bool from_string(T& t, const string& s, std::ios_base& (*f)(std::ios_base&))
    {
      std::istringstream iss(s);
      return !(iss >> f >> t).fail();
    }

size_t closing_braket(string s)
{
  // given a string, which starts with an opening braket, return position of its matching closing braket, or npos in case of failure
  int counter = 0;
  for (string::iterator it = s.begin(); it !=s.end(); ++it)
    {
      if (!string(it, it+1).compare("(")) counter++;
      if (!string(it, it+1).compare(")")) counter--;
      if (counter==0) return it-s.begin();
    }
  return string::npos;
}


float eval(string s)
{

remove_if(s.begin(), s.end(), isspace);

  float r = 0;
  string ss;
  string e = "0";
  for (string::iterator it = s.begin(); it !=s.end(); ++it)
    {
      string ee(it,it+1);
      if (!ee.compare(",")) ee = ".";
      if (std::isalpha(*it)) { throw invalid_argument(string(it,s.end())); }
      bool is_digit = std::isdigit(*it) || !ee.compare(".");
      if (is_digit)  ss += ee; 
      if (!is_digit || it == s.end()-1)
	{
	  float r_next =0;
	  from_string<float>(r_next,ss,std::dec); 
	  ss.clear();

	  if (!ee.compare("("))  
	    {
	      size_t exit_pos = closing_braket(string(it,s.end())); 
	      r_next = eval(string(it+1, it+exit_pos)); 
	      it += exit_pos;
	    }

	  if (!e.compare("0")) {r = r_next;}
	  else if (!e.compare("+")) {r += r_next;}
	  else if (!e.compare("-")) {r -= r_next;}
	  else if (!e.compare("*")) {r *= r_next;}
	  else if (!e.compare("/")) {r /= r_next;}
    
	  e = *it;  
	}  
    }
    return r;
}


float round_100(float r)
{
return roundf(r*100)/100.;
}


