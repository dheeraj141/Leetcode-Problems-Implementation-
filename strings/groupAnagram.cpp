#include<iostream>
#include <unordered_map>
using namespace std;

vector<vector<string>> groupAnagrams_optimized(vector<string>& strs)
{
    vector<vector<string>> res;
    unordered_map<string, vector<string>> store_anagrams;

    for (string& s : strs) {
        string t = s;
        sort(t.begin(), t.end());
        store_anagrams[t].push_back(s);
    }

    for (auto& e : store_anagrams) {
        res.push_back(e.second);
    }

    return res;
}


int main(int argc, const char * argv[])
{
    vector<string> str{"cat","act", "bat","tab", "eat","ate"};
    vector<vector<string>> res;
    res = groupAnagrams_optimized(str);
    display_vector_2d(res);



    return 0;


}
