

// leetcode zigzag string
// runtime 0ms on leetcode
string zigzag ( string &a, int numrows)
{
    int i, j;
    string result = "";
    if( a.size() <=1 || numrows == 1||  numrows == 0)
        return a;
    int step = ( 2*numrows - 2);
    for(i = 0; i<numrows; i++)
    {
        if(i <a.size())
            result+=a[i];
        j = step;
        while( (j-i) < a.size())
        {
            if( i == 0)
            {
                if( j <a.size())
                result+=a[j];
            }
            else if ( i == numrows-1)
            {
                if( j+i <a.size())
                    result+=a[j+i];
            }
            else
            {
                result+=a[j-i];
                if( j+i <a.size())
                    result+=a[j+i];

            }
            j+=step;
        }


    }
    return result;
}



// leetcode zogzag string optimized version implementation
string zigzag1 ( string s , int numRows)
{
    //vector<string> rows( std::min( numRows, int(s.size())));
    string result;
    int cycleLen = (2*numRows - 2);
    for(int i = 0; i<numRows; i++)
    {
        for(int j = 0;j+i < s.size(); j+=cycleLen)
        {
            result+= s[j+i];
            if( i!= 0 && i!= numRows-1 && j + cycleLen - i < s.size())
                result+= s[j+cycleLen - i];
        }
    }
    return result;

}

int main(int argc, const char * argv[]) {
    string a = "PAYPALISHIRING";
    string result = zigzag(a, 4);
    cout<<result<<endl;





}
