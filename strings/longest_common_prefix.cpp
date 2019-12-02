string match_strings (string a,string b )
{
    int i = 0;
    while( i <a.size() && i<b.size() && a[i]==b[i] )
        i++;
    string result = a.substr(0, i);
    return result;
}
string longest_common_prefix( vector<string> &strs)
{
    string lcp = strs[0];
    for(int i = 1; i<strs.size(); i++)
    {
        lcp = match_strings(lcp, strs[i]);
        if( lcp =="")
            return lcp;
    }
    return lcp;


}
int main(int argc, const char * argv[])
{
    vector<string> str{"flower","flow","flight"};
    cout<<longest_common_prefix( str)<<endl;



    return 0;


}
