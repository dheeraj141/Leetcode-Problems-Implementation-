
#include<iostream>
using namespace std;

bool isValid(string s) {
    stack<char> parenthesis;
    if ( s.empty())
        return true;
    for(int i = 0; i<s.length(); i++)
    {
       switch ( s[i])
       {
           case ')':
               if ( parenthesis.empty() || parenthesis.top() != '(')
                   return false;
               parenthesis.pop();
               break;
           case '}':
               if ( parenthesis.empty() || parenthesis.top() != '{')
                   return false;
               parenthesis.pop();
               break;
          case ']':
              if ( parenthesis.empty() || parenthesis.top() != '[')
                   return false;
               parenthesis.pop();
               break;
          default:
               parenthesis.push( s[i]);
               break;




       }
    }
    if( parenthesis.empty())
    return true;
    else
        return false;

}

int main(int argc, const char * argv[])
{
  string str = "(())(((())))";
  cout<<isValid( str)<<endl;



    return 0;


}
