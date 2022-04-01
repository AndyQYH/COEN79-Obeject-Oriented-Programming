#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char * argv[])
{

  //initialize file reader and other variables
  int i;
  ifstream fileReader;
  string textin;
  fileReader.open(argv[1]);


  //check if the reader reads a file correctly
  if (fileReader.is_open())
  {
    while(fileReader >> textin)
    {
      i = 0;

      //check every character of a string and remove non-alphabets
      while(i < textin.length())
      {
        if(!isalpha(textin[i]))
        {
          textin.erase(i,1);
          i--; //adjust the index to array shifting forward after removal.
        }
          i++;
      }


      //if string still larger than 10 in length, change all letters to uppercase
      if(textin.length() >= 10)
      {
        transform(textin.begin(), textin.end(), textin.begin(), ::toupper);
        cout<<textin<<endl;
      }

    }
    fileReader.close();
  }
  else
  {
     cout << "Unable to open file";
  }

  return 0;


}
