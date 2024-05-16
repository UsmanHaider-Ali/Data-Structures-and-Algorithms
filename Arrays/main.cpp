#include <iostream>
using namespace std;

class UnsortedArray
{
public:
    int insertAtEnd(int nums[], int size, int capacity, int element)
    {
        if (size >= capacity)
            return size;
        nums[size] = element;
        return ++size;
    }

public:
    int insertAtSpeceficPosition(int nums[], int size, int capacity, int element, int position)
    {
        if (size >= capacity)
            return size;

        int i = 0;
        for (i = size - 1; i >= position; i--)
            nums[i + 1] = nums[i];

        nums[i + 1] = element;

        return ++size;
    }

public:
    int searchElement(int nums[], int size, int element)
    {
        for (int i = 0; i < size; i++)
            if (nums[i] == element)
                return i;
        return -1;
    }

public:
    int deleteElement(
        int nums[], int size, int capacity, int element)
    {
        int index = searchElement(nums, size, element);
        if (index == -1)
            return size;

        for (int i = index; i < size; i++)
            nums[i] = nums[i + 1];

        return --size;
    }

public:
    void printArray(int nums[], int size)
    {
        for (int i = 0; i < size; i++)
            cout << nums[i] << " ";
        cout << "\nSize: " << size << endl;
    }
};

class SortedArray
{
public:
    int insert(int nums[], int size, int capacity, int element)
    {
        if (size >= capacity)
            return size;

        int i = size - 1;
        while (i >= 0 && nums[i] > element)
        {
            nums[i + 1] = nums[i];
            i--;
        }

        nums[i + 1] = element;
        return ++size;
    }

public:
    int searchElement(int nums[], int size, int element, int start, int end)
    {

        if (start > end)
            return -1;

        int mid = (start + end) / 2;
        if (element == nums[mid])
            return mid;
        if (element > nums[mid])
            return searchElement(nums, size, element, mid + 1, end);
        return searchElement(nums, size, element, start, mid - 1);
    }

public:
    int deleteElement(int nums[], int size, int element)
    {
        int index = searchElement(nums, size, element, 0, size - 1);
        if (index == -1)
            return size;

        for (int i = index; i < size; i++)
            nums[i] = nums[i + 1];

        return --size;
    }

public:
    void
    printArray(int nums[], int size)
    {
        for (int i = 0; i < size; i++)
            cout << nums[i] << " ";
        cout << "\nSize: " << size << endl;
    }
};

int main()
{

    // Array Operations

    // Unsorted Array
    UnsortedArray unsortedArray;

    int nums[20] = {4, 6, 3, 7, 5, 8, 2};
    int capacity = sizeof(nums) / sizeof(nums[0]);
    int size = 7;

    // Insertion
    int element = 1;
    size = unsortedArray.insertAtEnd(nums, size, capacity, element);
    unsortedArray.printArray(nums, size);

    // Insertion at Specific Index
    int index = 1;
    element = 9;
    size = unsortedArray.insertAtSpeceficPosition(nums, size, capacity, element, index);
    unsortedArray.printArray(nums, size);

    // Search Element
    element = 3;
    index = unsortedArray.searchElement(nums, size, element);
    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found" << endl;

    // Deletion
    element = 3;
    size = unsortedArray.deleteElement(nums, size, capacity, element);
    element = 9;
    size = unsortedArray.deleteElement(nums, size, capacity, element);
    element = 11;
    size = unsortedArray.deleteElement(nums, size, capacity, element);
    unsortedArray.printArray(nums, size);

    // Sorted Array
    int sortedNums[20] = {2, 4, 6, 9, 12, 15, 16, 19};
    capacity = sizeof(sortedNums) / sizeof(sortedNums[0]);
    size = 8;

    // Insertion in Sorted Array
    SortedArray sortedArray;
    element = 1;

    size = sortedArray.insert(sortedNums, size, capacity, element);
    sortedArray.printArray(sortedNums, size);

    element = 11;
    size = sortedArray.insert(sortedNums, size, capacity, element);
    sortedArray.printArray(sortedNums, size);

    element = 20;
    size = sortedArray.insert(sortedNums, size, capacity, element);
    sortedArray.printArray(sortedNums, size);

    // Search Element
    element = 20;
    index = sortedArray.searchElement(sortedNums, size, element, 0, size - 1);
    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found" << endl;

    // Deletion
    element = 20;
    size = sortedArray.deleteElement(sortedNums, size, element);
    sortedArray.printArray(sortedNums, size);

    element = 9;
    size = sortedArray.deleteElement(sortedNums, size, element);
    sortedArray.printArray(sortedNums, size);

    element = 1;
    size = sortedArray.deleteElement(sortedNums, size, element);
    sortedArray.printArray(sortedNums, size);

    element = 21;
    size = sortedArray.deleteElement(sortedNums, size, element);
    sortedArray.printArray(sortedNums, size);

    return 0;
}