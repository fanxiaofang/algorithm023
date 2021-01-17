#include <iostream>
//质数相乘法
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res; //存储结果
        unordered_map <double,vector<string> > m;//hash表，key为质数成绩
       //质数，按顺序对应字母
       double a[26]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
        for(string& s : strs)
        {
            //记录质数成绩 t
            double t = 1;
            for(char c : s)
                t *= a[c - 'a'];
            m[t].emplace_back(s);          //t为单词对应的质数乘积，m[t]则为该单词的异位词构成的vector
        }
        for(auto& n : m)                //遍历hash表 m
            res.emplace_back(n.second);
        return res;
    }
};