// interview bit Atoi
int atoi_leetcode ( string &a)
{
    int i ;
    i = 0;
   while( a[i] == ' ')
       i++;
    if(  i==a.size())
        return 0;
    else if( a[i] == '-' || a[i] == '+' || ( a[i] >='0' && a[i]<='9'))
    {
        int flag = 1;
        if ( a[i]== '-')
        {
            flag = 0;
            i++;
        }
        else if( a[i] == '+')
        {
            flag = 1;
            i++;
        }
       long long int result = 0;
        while(  i<a.size() && a[i] >='0' && a[i] <= '9')
        {
            result = result*10 + a[i]-'0';
            if ( result > INT_MAX)
            {
                if ( flag == 0)
                    return (INT_MIN);
                else
                    return INT_MAX;
            }
            i++;
        }


            if( flag == 0)
                return (-(int)result);
            else
                return (int)result;

    }
    else
        return 0;
}
int main(int argc, const char * argv[]) {
    string a = "11221";
    int result = atoi_leetcode(a);
    cout<<result<<endl;





}
