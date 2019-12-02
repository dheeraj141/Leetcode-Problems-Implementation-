#include<iostream>

using namespace std;


template <typename T>
void display_vector(vector<T> A)
{
    for(int j = 0; j<A.size(); j++)
        cout<<A[j]<<" ";
    cout<<endl;
}

void helper_fn( vector<string> &res, string str, int l, int r)
{
    if( l == 0 && r == 0)
    {
         res.push_back(str);
        return;

    }
    if (l >0) helper_fn(res, str+"(", l-1, r);
    if( r >l )helper_fn(res, str+")", l, r-1);
}
vector<string> generate_parenthesis( int n)
{
    vector<string> res;
    helper_fn( res, "", n,n);
    return res;
}

int main(int argc, const char * argv[])
{
  vector<string> res;
  res = generate_parenthesis( 3);
  display_vector( res);




    return 0;


}
