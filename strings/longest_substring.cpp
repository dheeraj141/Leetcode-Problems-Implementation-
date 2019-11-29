// longest substring leetcode without repeating characters
int longest_substring( string &text)
{
    if( text.size()<=1)
        return (int)text.size();
    int i ; i = 0;
    unordered_map<char,int> characters;
    int max_len = 0;
    int size = (int)text.size();
    while( i <size)
    {
        auto x = characters.find(text[i]);
        if( x == characters.end())
        {
            characters.insert(make_pair(text[i], i));
            i++;

        }
        else
        {
            if(max_len< characters.size())
                max_len = (int)characters.size();
            i = characters[text[i]] +1;
            characters.clear();

        }

    }
    if ( max_len < characters.size())
        max_len =(int) characters.size();
    return max_len;

}
// longest substring leetcode
/* function returns the length of the longest substring
found without repeating characters
*/
int longest_substring_leetcode( string &text)
{
    int start, max_len;
    start = -1; max_len = 0;
    int i;
    map <char,int> charmap;
    for(i = 0; i<text.size(); i++)
    {
        if(charmap.count(text[i])!= 0 )
        {
            start = std::max( start, charmap[text[i]]);

        }
        charmap[text[i]] = i;
        max_len = std::max(max_len, i-start);

    }
    return max_len;
}
int main(int argc, const char * argv[]) {
    string a = "PAYPALISHIRING";
    int result = longest_substring(a);
    cout<<result<<endl;





}
