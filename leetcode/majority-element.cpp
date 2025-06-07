#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int majorityElements(vector<int>& nums) {

    unordered_map<int, int> di;

    for(int i = 0; i < nums.size(); ++i) {
        if(di.count(nums[i]) > 0) {
            di[nums[i]] += 1;
            continue;
        }

        di[nums[i]] = 1;
    }


    //for (const auto& pair : di) {
    //    std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    //}

    int maxNum = di.begin()->first;
    int maxVal = di.begin()->second;
    for(const pair<const int, int>& d : di) {
        if(d.second > maxVal) {
             maxNum = d.first;
             maxVal = d.second;
        }
    }

    return maxNum;
    //return 1;

}
int majorityElementss(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int s = nums.size();
    return nums[s/2];
    //for(int i = 0; i < nums.size(); ++i) {
    //
    //}
}

int majorityElement(vector<int>& nums) {
// Boyer-Moore Voting Algorithm

    int candidate = 0;
    int count = 0;

    for(int i = 0; i < nums.size(); ++i) {
        if (count == 0) {
            candidate = nums[i];
            count = 1;
        }
        else if (nums[i] == candidate) {
            count++;
        }
        else {
            count--;
        }
    }

    return candidate;

}

/*
1:
    nums[i] = 2
    ca = 2
    co = 1
2:
    nums[i] = 3
    ca = 2
    co = 0
3:
    nums[i] = 3
    ca = 3
    co = 1
4:
    nums[i] = 2
    ca = 3
    co = 0
5:
    nums[i] = 3
    ca = 3
    co = 1
 */

int main() {
    vector<int> nums = {2, 3, 3, 2, 3};
    int res = majorityElement(nums);
    cout << res << endl;

    nums = {1,2,2,2,2,1,1,1,2,2};
    res = majorityElement(nums);
    cout << res << endl;

    return 0;
}

