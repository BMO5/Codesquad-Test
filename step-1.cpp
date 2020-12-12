#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string word;
    int rotate_num;
    char direction;

    cout << "> ";
    while (1)
    {
        cin >> word >> rotate_num >> direction;
        if (-100 <= rotate_num && rotate_num < 100)
            break;
        else
            cout << "정수는 -100 <= N < 100 으로 입력해 주세요." << endl;
    }

    if (direction == 'L' || direction == 'l' || (direction == 'R' && rotate_num < 0) || (direction == 'r' && rotate_num < 0))
    {
        rotate_num = abs(rotate_num) % word.length();
        rotate(word.begin(), word.begin() + rotate_num, word.end());
    }
    else
    {
        rotate_num = abs(rotate_num) % word.length();
        rotate(word.rbegin(), word.rbegin() + rotate_num, word.rend());
    }

    cout << word;

    return 0;
}
