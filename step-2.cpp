#include <iostream>
#include <string>

using namespace std;

void cube_print(char cube_arr[][3])
{
    for (int i = 0; i < 3; i++)
        cout << cube_arr[i][0] << " " << cube_arr[i][1] << " " << cube_arr[i][2] << endl;
    cout << endl;
}

void U_ccw(char cube_arr[][3])
{
    char temp = cube_arr[0][0];
    cube_arr[0][0] = cube_arr[0][1];
    cube_arr[0][1] = cube_arr[0][2];
    cube_arr[0][2] = temp;
}

void U_cw(char cube_arr[][3])
{
    char temp = cube_arr[0][2];
    cube_arr[0][2] = cube_arr[0][1];
    cube_arr[0][1] = cube_arr[0][0];
    cube_arr[0][0] = temp;
}

void R_ccw(char cube_arr[][3])
{
    char temp = cube_arr[0][2];
    cube_arr[0][2] = cube_arr[1][2];
    cube_arr[1][2] = cube_arr[2][2];
    cube_arr[2][2] = temp;
}

void R_cw(char cube_arr[][3])
{
    char temp = cube_arr[2][2];
    cube_arr[2][2] = cube_arr[1][2];
    cube_arr[1][2] = cube_arr[0][2];
    cube_arr[0][2] = temp;
}

void L_ccw(char cube_arr[][3])
{
    char temp = cube_arr[2][0];
    cube_arr[2][0] = cube_arr[1][0];
    cube_arr[1][0] = cube_arr[0][0];
    cube_arr[0][0] = temp;
}

void L_cw(char cube_arr[][3])
{
    char temp = cube_arr[0][0];
    cube_arr[0][0] = cube_arr[1][0];
    cube_arr[1][0] = cube_arr[2][0];
    cube_arr[2][0] = temp;
}

void B_ccw(char cube_arr[][3])
{
    char temp = cube_arr[2][2];
    cube_arr[2][2] = cube_arr[2][1];
    cube_arr[2][1] = cube_arr[2][0];
    cube_arr[2][0] = temp;
}

void B_cw(char cube_arr[][3])
{
    char temp = cube_arr[2][0];
    cube_arr[2][0] = cube_arr[2][1];
    cube_arr[2][1] = cube_arr[2][2];
    cube_arr[2][2] = temp;
}

int main()
{
    char cube_arr[3][3] = {{'R', 'R', 'W'}, {'G', 'C', 'W'}, {'G', 'B', 'B'}};
    cube_print(cube_arr);

    string input = "";
    string str_temp = "";
    while (1)
    {
        cout << "CUBE> ";
        cin >> input;

        for (int i = 0; i < input.length(); i++)
        {
            str_temp = input[i];
            if (i != input.length() - 1)
            {
                if (input[i + 1] == '\'')
                {
                    str_temp += '\'';
                    i++;
                }
            }

            if (str_temp == "U")
                U_ccw(cube_arr);
            else if (str_temp == "U'")
                U_cw(cube_arr);
            else if (str_temp == "R")
                R_ccw(cube_arr);
            else if (str_temp == "R'")
                R_cw(cube_arr);
            else if (str_temp == "L")
                L_ccw(cube_arr);
            else if (str_temp == "L'")
                L_cw(cube_arr);
            else if (str_temp == "B")
                B_ccw(cube_arr);
            else if (str_temp == "B'")
                B_cw(cube_arr);
            else if (str_temp == "Q")
            {
                cout << "Bye~" << endl;
                return 0;
            }

            cout << str_temp << endl;
            cube_print(cube_arr);
        }
    }

    return 0;
}
