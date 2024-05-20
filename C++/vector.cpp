#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(4);
    nums.push_back(2);
    nums.push_back(3);

    // for (int i = 0; i < nums.size(); i++)
    // {
    //     cout << nums.at(i) << " ";
    // }

    // cout << endl;
    // cout << nums.at(1) << endl;
    // nums.at(1) = 4;
    // cout << nums.at(1) << endl;

    // nums.pop_back();
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums.at(i) << " ";
    }
    cout << endl;

    cout << nums.size() << endl;
    cout << nums.front() << endl;
    cout << nums.back() << endl;

    nums.clear();
    cout << nums.size() << endl;
    cout << nums.empty() << endl;

    return 0;
}