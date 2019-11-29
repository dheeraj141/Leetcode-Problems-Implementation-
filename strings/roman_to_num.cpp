int roman_utility( char a)
{
    switch( a)
    {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;

    }
}
// inyerview bit roman to number
int roman_num( string &a)
{
    int i = 0;
    int result = 0;
    while( i<a.size())
    {
       if( i+1 < a.size())
       {
           int x,y;
           x = roman_utility(a[i+1]);
           y = roman_utility(a[i]);
           if (x >y)
           {
               result += ( x-y);
               i+=2;
           }
           else
           {
               result+= y;
               i++;
           }



       }
        else
        {
            result += roman_utility(a[i]);
            i++;

        }

    }
    return result;

}
int main(int argc, const char * argv[]) {
    string a = "MM" ;
    int result = roman_num(a);
    cout<<result<<endl;





}
