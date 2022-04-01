#include<iostream>
#include<string>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
   //variable decalarations
    string str1, str2; //one for original , one for reverse
    int max_size = 10; //max length for the entered string

    //prompt user to enter a string of number with length <= 10
	  cout << "Input string of 10 digits(no space): " << endl;
    getline(cin, str1);
    cout<< endl;

    //continue asking user to enter the correct string if they did not
    while(!cin || str1.length() != max_size || str1.find(" ") != string::npos)
    {
      if(str1.length() < max_size)
      {
        cout << "format wrong, please try again (entered number smaller than 10 digits or contained spaces)"<<endl;
      }
      if(str1.length() > max_size)
      {

        cout << "format wrong, please try again (entered number larger than 10 digits or contained spaces)"<<endl;
      }

      cout << "Input string of 10 digits(no space): " << endl;
      getline(cin, str1);
      cout<< endl;
    }

    //copy stored string
    str2 = str1;
    //reverse it and store in str2
    reverse(str1.begin(), str1.end());

    //Print the original and the reversed string with specified space in between
     cout << setw (14) << str1 << setw (20) << str2 << endl;
     cout << setw (16) << str1 << setw (20) << str2 << endl;
     cout << setw (18) << str1 << setw (20) << str2 << endl;
     cout << setw (20) << str1 << setw (20) << str2 << endl;

     return 0;
}
