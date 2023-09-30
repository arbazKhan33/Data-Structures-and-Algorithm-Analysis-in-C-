#include <iostream>
#include <string>

using namespace std;


int recursiveSumPositiveEven(int arr[], int start, int size) 
{
    if (start == size) 
    {
        return 0;
    }

    if (arr[start] % 2 == 0 && arr[start] > 0) 
    {
        return arr[start] + recursiveSumPositiveEven(arr, start + 1, size);
    }

    return recursiveSumPositiveEven(arr, start + 1, size);
}


int countDigit(string str) 
{
    if (str.length() == 0) 
    {
        return 0;
    }

    char c = str.back();
    str.pop_back();

    if (c >= '0' && c <= '9') 
    {
        return 1 + countDigit(str);
    }

    return countDigit(str);
}



int main() 
{

    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    cout << recursiveSumPositiveEven(arr, 0, 10) << endl;

    string str = "Abc12.@0K";
    cout << countDigit(str) << endl;

    return 0;
}

