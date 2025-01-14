#include<iostream>  //for cin cout
#include<cstdlib>   // for generating random number 
#include<ctime>      // for time
#include<string>    // string type data
using namespace std;
 string getpassword(int length)
{
    string password="";
    string character="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890_+-)(-@#%^&*";
    int charsize=character.size();
    srand(time(0));
    int randomindex;
    for(int i=0;i<length;i++)
    {
         randomindex=rand()%charsize;
         password=password+character[randomindex];
    }
    return password;
}
int main()
{
    int length;
    cout<<"\n Enter the length of the password :";
    cin>>length;
    string password=getpassword(length);
    cout<<"\n Generated password is :"<<password;
    return 0;
}
