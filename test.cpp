#include <bits/stdc++.h>
using namespace std;

void twoSum(vector<int> &nums, int target)
{
    vector<int> ans;
    sort(nums.begin(), nums.end());

    int i = 0;
    int j = nums.size() - 1;

    while (j >= i)
    {
        int sum = nums[i] + nums[j];
        if (sum == target)
        {
            break;
        }
        else if (sum > target)
        {
            j--;
        }
        else if (sum < target)
        {
            i++;
        }
    }
    cout << i << " " << j << " " << endl;
    // ans.insert(ans.begin(), i);
    // ans.insert(ans.begin() + 1, j);
    // return ans;
}

int main()
{
    vector<int> vtr;
    for (int i = 0; i < 3; i++)
    {
        int a;
        cin >> a;
        vtr.insert(vtr.begin() + i, a);
    }
    // vector<int> ans =
    twoSum(vtr, 6);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << ' ';
    // }
    // return 0;
}