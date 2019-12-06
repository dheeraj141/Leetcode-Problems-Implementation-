

/* this algorithm finds the next permutation just greater than the given and
if it is the last ( meaning there is no greater permutation) then it returns
null.*/


// reference for the algorithm
//https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order



string next_permutation1( string num )
    {
        int n = ( int)num.size();
        int k, l; k = l = -1;
        for(int  i =n-1; i>=0; i--)
        {
            if( num[i] < num[i+1])
            {
                k = i;
                break;
            }

        }
        if( k == -1)
            return "";
        for( int i =k+1; i<n; i++)
        {
            if( num[i] > num[k])
            {
                l = i;

            }

        }
        swap( num[k], num[l]);
        reverse( num.begin()+ k+1, num.end());
        return num;


    }







/* Approach find for the next permutation in the string and convert it to digit
and return the digit if it is under the INT range else return -1;
*/

int nextGreaterElement(int n)
    {
        string num = to_string( n);
        string greater = next_permutation1(num);
        if( greater == "")
            return -1;
        else
        {
            auto res = stoll( greater);
            if ( res > INT_MAX || res == n)
                return -1;
            else
                return ( int)res;

        }
    }
