#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(7);

    int k = 3;

    vector<int> result;
    int p = 0;

    for (int i = k; i < nums.size(); i++)
    {
        result.push_back(nums.at(i));
        p++;
    }

    for (int i = 0; i < k; i++)
    {
        result.push_back(nums.at(i));
    }

    for (int i = 0; i < result.size(); i++)
    {
        cout << result.at(i) << " ";
    }

    // add element at specific position
    result.insert(result.begin(), 1);
    cout << endl;
    for (int i = 0; i < result.size(); i++)
    {
        cout << result.at(i) << " ";
    }

    return 0;
}
