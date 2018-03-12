//#include <iostream>         
#include <string> 
///#include <cstdlib>
//#include <exception>
#include <iostream>
#include <string>
#include <vector>
//#include <unistd.h>
using namespace std;
using wordvec = vector<string>;
wordvec split (const string& line, const string& delimiters) {
   wordvec words;
   size_t end = 0;

   // loop over the string, splitting out words on delims. for each word append it to the output wordvec
   for (;;) {
      size_t start = line.find_first_not_of (delimiters, end);
      if (start == string::npos) break;
      end = line.find_first_of (delimiters, start);
      words.push_back (line.substr (start, end - start));
   }
   return words;
}
