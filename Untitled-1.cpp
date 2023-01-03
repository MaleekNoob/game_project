#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "\nEnter num: ";
    cin >> num;

    // num *= 2;

    for (int i = 0; i < num ; i+=2)
    {
        for (int j = num; j > i /* +1 */; j--)
        {
            cout << '*';
        }
    cout << endl;
    }
    return 0;
}