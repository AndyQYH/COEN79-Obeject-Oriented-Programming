#include "mystring.h"
#include <cstring>
#include <cassert>
#include <cctype>

using std :: cout;
using std :: cin;
using std :: endl;

/*invariant:
1.the space allocated for the string is stored in the variable allocated
2.the length of the characters in the string is stored n the variable current_length
3.characters of the string are stored in a char array pointed by characters from
  characters[index = 0] to chracters[current_length - 1] in order
*/
namespace coen79_lab5
{

  // CONSTRUCTOR, COPY CONSTRUCTOR, and DESTRUCTOR

  //default/parameterized constructor with char[]
  //allocate memory for char pointer characters to the size of the length of str
  string :: string(const char str[])
  {
    current_length = strlen(str);
    allocated = current_length;
    characters = new char[allocated];
    strncpy(characters, str, strlen(str));

  }

  //parameterized constructor with char
  //allocate memory for char pointer characters to the size of the length of c
  string :: string(char c)
  {
    current_length = 1;
    allocated = current_length;
    characters = new char[allocated];
    characters[0] = c;
    //strncpy(characters, &c, 1);
    //characters[current_length] = '\0';

  }

  //copy constructor
  //allocate memory for char pointer characters to the size of the length of the source
  string :: string(const string& source)
  {
    current_length = source.current_length;
    allocated = source.allocated;
    characters = new char[allocated];
    strncpy(characters, source.characters, source.current_length);
    //characters[current_length] = '\0';

  }

  //destructor of string CLASS
  //reset current_length, allocated;
  //free memory pointed by characters
  string :: ~string()
  {
    delete [] characters;
    current_length = 0;
    allocated = 0;
  }

  // MODIFICATION MEMBER FUNCTIONS
  void string :: operator +=(const string& addend)
  {
    if(current_length + addend.current_length > allocated)
    {
      reserve(current_length + addend.current_length);
    }
      //copy addend to the end of the char array pointed by characters
      strncpy(characters + current_length, addend.characters, addend.current_length);
      current_length += addend.current_length;

  }

  void string :: operator +=(const char addend[])
  {
    if(current_length + strlen(addend) > allocated)
    {
      reserve(current_length + strlen(addend));
    }

    //copy addend to the end of the char array pointed by characters
    strncpy(characters + current_length, addend, strlen(addend));
    current_length += strlen(addend);
  }

  void string :: operator +=(char addend)
  {
    if(current_length + 1 > allocated)
    {
      reserve(current_length + 1);
    }

    //copy addend to the end of the char array pointed by characters
    strncpy(characters + current_length, &addend, 1);
    current_length += 1;
  }

  void string :: reserve(size_t n)
  {
    char* larger_string;

    //no need to allocate
    if(n == allocated)
    {
      return;
    }

    //have to allocate enough for the string that alreadt exists
    if(n < current_length)
    {
      n = current_length;//n has to be at least the size of current_length
    }

    //allocate a new char array of size n
    //copy original data in characters into the larger array
    //delete the original data
    //set allocated to n
    larger_string = new char[n];
    strncpy(larger_string, characters, current_length);
    delete[] characters;
    characters = larger_string;
    allocated = n;
    //characters[current_length] = '\0';

  }

  //assignment operator
  //set a string object to another string object
  //copy all data in the other string to the current one
  //return the object that is using this function
  string& string :: operator =(const string& source)
  {
    char* new_string;

    if(this == &source)
    {
      return *this;
    }

    if(current_length != source.current_length)
    {

      new_string = new char[source.current_length];
      delete [] characters;

      characters = new_string;
      current_length = source.current_length;
      allocated = source.allocated;
    }

      strncpy(characters, source.characters, source.current_length);

      return *this;

  }

  //copy all characters of source to the current string at index position
  //shift characters after position in the originalo array to index position + source.current_length
  void string :: insert(const string& source, unsigned int position)
  {
    assert(position <= source.length());

    string copy = *this;

    reserve(current_length + source.current_length);

    characters[position] = '\0';

    strncpy(characters + position, source.characters, source.current_length);

    strncpy(characters + position + source.current_length, copy.characters + position, copy.current_length - position);

    current_length += source.current_length;


  }

  //delete num number of elements strating from index position
  //shift the characters after position + num to index position
  void string :: dlt(unsigned int position, unsigned int num)
  {
    assert((position + num) <= length());
    string copy = *this;

    strncpy(characters + position, copy.characters + position + num, length() - (position + num) );
    current_length -= num;
  }

  //switch the character at index postion to c
  void string :: replace(char c, unsigned int position)
  {
    assert(position < length());

    characters[position] = c;

  }

  //switch the original sequences from position to position + source.current_length
  //to all characters of source, one by one
  void string :: replace(const string& source, unsigned int position)
  {
    assert(position + source.length() <= length());
    size_t j = 0;

    for(int i = position; i <= position + source.current_length; i++)
    {
      characters[i] = source.characters[j];
      j++;
    }
  }

  // CONSTANT MEMBER FUNCTIONS
  size_t string :: length( ) const
  {
    return current_length;
  }

  //work the same as getting the character at index position
  char string :: operator [](size_t position) const
  {
    assert(position < length());
    return characters[position];
  }

  //compare character at each index with char c
  //if they are the same, return the index
  int string :: search(char c) const
  {
    for(int i = 0; i < current_length; i++)
    {
      if(characters[i] == c)
      {
        return i;
      }
    }

    return -1;
  }

  //return the index of the first index of the first instance where
  //substring is found in the string
  int string :: search(const string& substring) const
  {
    size_t i = 0;
    size_t j = 0;
    int matched_char = 0;

    if(substring.current_length > current_length)
    {
      return -1;
    }

    while(i < current_length && j < substring.current_length)
    {
      //i is for looping through characters
      //j is for looping through substring
      //j will only advance when the character at current j is matched with
      //a character from the string
      //continue comparison of index i + 1 and j + 1 and so on
      //if difference is seen before the looping for substring.current_length times
      //we have to redo the process again
      //else we know substring is contained in the string
      if(characters[i] == substring.characters[j])
      {

        matched_char++;
        i++;
        j++;

        if(matched_char == substring.current_length)
        {
          return i - substring.current_length;
        }
      }
      else
      {
        j = 0;
        i++;
        matched_char = 0;
      }


    }

    return -1;
  }

  //everytime we see a char c we incrment the count by 1
  //return the final count
  unsigned int string :: count(char c) const
  {
    size_t count = 0;
    for(int i = 0; i <= current_length; i++)
    {
      if(characters[i] == c)
      {
        count++;
      }
    }

    return count;
  }

  // FRIEND FUNCTIONS
   std::ostream& operator <<(std::ostream& outs, const string& source)
  {

    for(int i = 0; i < source.current_length; i++)
    {
      outs << source.characters[i];
    }

    return outs;
  }
  bool operator ==(const string& s1, const string& s2)
  {
    return (strcmp(s1.characters, s2.characters) == 0);
  }
  bool operator !=(const string& s1, const string& s2)
  {
    return (strcmp(s1.characters, s2.characters) != 0);
  }
  bool operator > (const string& s1, const string& s2)
  {
    return (strcmp(s1.characters, s2.characters) > 0);
  }
  bool operator < (const string& s1, const string& s2)
  {
    return (strcmp(s1.characters, s2.characters) < 0);
  }
  bool operator >=(const string& s1, const string& s2)
  {
    return (strcmp(s1.characters, s2.characters) >= 0);
  }
  bool operator <=(const string& s1, const string& s2)
  {
    return (strcmp(s1.characters, s2.characters) <= 0);
  }

  // NON-MEMBER FUNCTIONS for the string class
  string operator +(const string& s1, const string& s2)
  {
    string combined;
    combined += s1;
    combined += s2;

    return combined;
  }

  string operator +(const string& s1, const char addend[])
  {
    string combined;
    combined += s1;
    combined += addend;

    return combined;
  }

  //ignore white space before input
  //take in the line of input
  //add them to a string object
  std::istream& operator >> (std::istream& ins, string& target)
  {
    char b;
    char c[50];
    while (ins && (isspace(ins.peek())))
    {
      ins.ignore();
    }
	
     
    ins >> c;
    target = "";
    target += c;

    return ins;
  }
}
