#include <iostream>
#include <vector>
using namespace std;
bool sublista_bt(int *a, int tam,int soma){
    int r;
    if(soma  == 0){
        return true;
    }
    if(soma < 0 || tam == 0){
        return false;
    }
    r = sublista_bt(a,tam - 1, soma - a[tam - 1]);
    r = r || sublista_bt(a, tam - 1, soma);
    return r;
}
void dfs(int i, vector<int> &nums, vector<int>& subset, vector<vector<int>> &res){
    if(i >= nums.size()){
        res.push_back(subset);
        return;
    }
    subset.push_back(nums[i]);
    dfs(i + 1,nums,subset,res);
    subset.pop_back();
    dfs(i + 1, nums,subset,res);
}
vector<vector<int>> subsets(vector<int> nums){
    vector<vector<int>> res;
    vector<int> subset;

    dfs(0,nums,subset,res);
    return res;
}




