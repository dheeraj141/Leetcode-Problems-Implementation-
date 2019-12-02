vector<string> phone_combination ( string &nums)
{
   vector<vector<string>> digits {  {"a","b","c"},
                                    {"d","e","f"},
                                    {"g","h","i"},
                                    {"j","k","l"},
                                    {"m","n","o"},
                                    {"p","q","r", "s"},
                                    {"t","u","v"},
                                    {"w","x","y","z"},

                                            };
    vector<string> result = {};
    if( nums.empty())
        return result;
    else if(nums.size() ==1)
        return digits[stoi(nums) - 2];
    result = digits[ nums[0] - '2'];

    for( int i =1; i<nums.size(); i++)
    {
        int x =  nums[i] - '2';
        vector<string > temp = digits[x];
        vector<string> temp_result;
        for(int j = 0; j<result.size(); j++)
        {
            for(int k = 0; k < temp.size(); k++)
                temp_result.push_back( result[j]+temp[k] );

        }
        result = temp_result;
    }
    return result;



}


template <typename T>
void display_vector(vector<T> A)
{
    for(int j = 0; j<A.size(); j++)
        cout<<A[j]<<" ";
    cout<<endl;
}



int main(int argc, const char * argv[])
{
    string nums = "23";
    vector<string> res = phone_combination( nums);
    display_vector( res);



    return 0;


}
