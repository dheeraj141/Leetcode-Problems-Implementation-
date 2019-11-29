// interview bit add binary string
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


int main(int argc, const char * argv[]) {
    string a = "1111";
    string b = "1213";
    string result = binary_sum(a, b);
    cout<<result<<endl;





}
