#include<iostream>
using namespace std;

// interview bit count and say
string count_say_utility( string result)
{

    char m; int j;
    m = result[0];
    j = 1;

    string temp ="";
    while( j < result.size())
    {

        if ( result[j] !=m )
        {
            temp.push_back('1');
            temp.push_back(m );
            m = result[j];
            j++;

        }
        else
        {
            int count =1;
            while(  j < result.size() && result[j] == m)
            {
                count++; j++;

            }
            char number  = count +'0';
            temp.push_back(number);
            temp.push_back(m );
            if( j >= result.size())
                return temp;
            else
            {
                m = result[j];
                j++;
            }


        }

    }
    temp.push_back('1');
    temp.push_back(m );
    return temp;

}
string count_say( int A)
{
    string result = "";
    // base case

    if ( A == 0)
        return result ;
    if (A == 1)
        return "1" ;

    int i; result = "1";
    for(i =1; i<A; i++)
    {
        result = count_say_utility(result);


    }
    return result;
}
int main(int argc, const char * argv[]) {
    int A = 5;
    cout<<count_say(A)<<endl;





}
