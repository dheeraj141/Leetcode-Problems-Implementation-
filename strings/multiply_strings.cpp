#include <iostream>
#include <vector>



// interview bit add binary string
/* function to add two numbers represented in a string format
*/
string binary_sum( string a, string b)
{
    int i, j ,carry;
    i = ( int)a.size()- 1;
    j = ( int)b.size() -1;
    carry = 0;
    int sum = 0;
    string result= "";
    while( i>=0 || j >=0|| carry)
    {
        sum = carry;
        if( i>=0) sum+=( a[i] - '0');
        if( j >=0) sum+=( b[j] - '0');
        carry = sum/10;
        result.push_back(char( sum%10 + '0'));
        i--;
        j--;


    }
    reverse( result.begin(), result.end());
    return result;

}

string single_digit_multiply( string a, int b)
{
    int carry = 0;
    string result = "";
    int size_a = (int)a.size()-1;
    int sum = 0;
    while( size_a >=0)
    {
        sum = carry;
        sum+= ( a[size_a]- '0')*b;
        result+= sum%10 +'0';
        carry = sum/10;
        size_a--;

    }
    if( carry)
        result+=(carry+'0');
    reverse( result.begin(), result.end());
    return result;
}
// leetcode multiply strings
string multiply_strings ( string a, string b)
{
    if( a == "0" || b == "0")
        return "0";
    string x, y;
    if( a.size() > b.size())
    {
        x = a;
        y = b;
    }
    else
    {
        x = b;
        y=a;
    }
    string result, zeros, temp;
    zeros = result = temp = "";
    int size_y = (int)y.size() -1;
    while( size_y >=0)
    {
        temp = single_digit_multiply(x, y[size_y]-'0');
        temp.append(zeros);
        result = binary_sum(result, temp);
        zeros+="0";
        size_y--;

    }
    return result;

}



/* optimized version of the same problem
*/
// leetcode string multiply optimized solution
string multiply_strings_optimized( string num1, string num2)
{
    if ( num1 == "0" || num2 =="0")
        return "0";
    int l1,l2;
    l1 = (int)num1.size();
    l2 = (int)num2.size();
    vector<int> v(l1+l2, 0 );
    int carry, sum,n1,n2;
    carry = sum =n1 = n2 =  0;
    for(int i = 0; i<l1; i++)
    {
        carry = 0;
        n1 = (num1 [ l1-i-1] - '0');
        for(int j = 0; j<l2; j++)
        {

            n2 = (num2[l2-j-1]- '0');
            sum = carry+ (n1*n2)+ v[i+j];
            carry = sum/10;
            v[i+j] = sum%10;




        }
        if( carry >0)
            v[i+l2] += carry;
    }
    int start = l1+l2-1;
    while( v[start] == 0)
        start--;
    if( start == -1)
        return "0";
    string result = "";
    for( int i = start; i>=0; i--)
        result+=( char)(v[i]+'0');
    return result;

}

int main(int argc, const char * argv[]) {
    string a = "0";
    string b = "0";
    string result;
    result = multiply_strings_optimized(a, b);
    cout<<result<<endl;




}
