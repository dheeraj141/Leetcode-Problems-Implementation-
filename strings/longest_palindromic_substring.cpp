// interview bit longest palindrome using DP
string longest_palindrome_DP( string &a)
{
    int start, max_length; string result= "";
    start = 0; max_length=0;
    if( a.size() == 0)
        return result;
    vector<vector<int>> table( a.size(), vector<int>( a.size(), 0));
    for(int i = 0; i<a.size(); i++)
        table[i][i] = 1;
    for(int i = 0; i<a.size() -1; i++)
    {
        if( a[i] == a[i+1])
        {
            start = i;
            table[i][i+1] =1;
            max_length = 2;

        }


    }
    for(int k = 3; k<=a.size(); k++)
    {
        for(int i = 0; i<a.size() -k+1; i++ )
        {
            int j = i+k-1;
            if( table[i+1][j-1] && a[i] == a[j])
            {
                table[i][j] =1;
                if(k >max_length)
                {
                    start = i;
                    max_length = k;
                }
            }
        }


    }

    if(max_length == 0)
        result.push_back(a[0]);
    else
    {
        for(int i = start; i<start+ max_length; i++)
            result.push_back(a[i]);

    }


    return result;
}
// interview bit longest palindrome Normal method
string longest_palindrome( string &a)
{
    int i; string result = "";
    if( a.size() == 0)
        return result;
    i = 0;
    int start, max_length;
    start = max_length = 0;
    while( i <a.size())
    {
        int j , k;
        j= i-1; k = i+1;

        int count = 0;
        while( j >=0 && k <a.size() && a[j] == a[k])
        {
            j--;
            k++;
            count++;

        }
        if ( max_length < ( 2*count + 1))
        {
            max_length = 2*count+1;
            start = i-count;
        }
        i++;




    }
    i = 1;
    while( i <a.size())
    {
        if( a[i] == a[i-1])
        {
            int j , k;
             j= i-2; k = i+1;

             int count = 0;
             while( j >=0 && k <a.size() && a[j] == a[k])
             {
                 j--;
                 k++;
                 count++;

             }
             if ( max_length < ( 2*count + 2))
             {
                 max_length = 2*count+2;
                 start = i-count-1;
             }



        }
        i++;




    }

    if(max_length == 0)
        result.push_back(a[0]);
    else
    {
        for(int i = start; i<start+ max_length; i++)
        result.push_back(a[i]);

    }
    return result;


}




int main(int argc, const char * argv[]) {
    string text = "forgeeksskeegfor";

    cout<<longest_palindrome(text)<<endl;





}
