// KMP pattern searching algorithm
vector<int> calculate_lps ( string & pattern)
{
    vector<int> lps( pattern.size(), 0);
    int i , j;
    i = 0; j =1;
    while( j < pattern.size() )
    {
        if ( pattern[i] == pattern[j] )
        {
            lps[j] = i+1;
            i++;
            j++;

        }
        else
        {
            if ( i >0)
            {
                i = lps[i-1];
            }
            else
            {
                lps[j] = 0;
                j++;
            }
        }



    }
    return lps;

}

int KMP_string_search( string &text, string &pattern)
{
     vector<int > lps = calculate_lps(pattern);
       int i , j;
       i = 0; j = 0;
       if( pattern.size() == 0 || text.size() == 0)
       return -1;
       while( i < text.size() && j < pattern.size())
       {
           if( text[i] == pattern[j])
           {
               i++; j++;

           }
           else
           {
               if( j != 0)
                   j = lps[j-1];
               else i++;
           }
       }
       if( j==pattern.size())
           return (i-j);
       else
           return -1;


}
int main(int argc, const char * argv[]) {
    string text = "ababcddef";
    string pattern = "aba";
    int starting_index;
    starting_index = KMP_string_search(text, pattern);
    cout<<starting_index<<endl;





}
