#include <iostream>
#include <string>

using namespace std;

char cubeU[3][3] = {{'B', 'B', 'B'}, {'B', 'B', 'B'}, {'B', 'B', 'B'}};
char cubeM1[3][3] = {{'W', 'W', 'W'}, {'W', 'W', 'W'}, {'W', 'W', 'W'}};
char cubeM2[3][3] = {{'O', 'O', 'O'}, {'O', 'O', 'O'}, {'O', 'O', 'O'}};
char cubeM3[3][3] = {{'G', 'G', 'G'}, {'G', 'G', 'G'}, {'G', 'G', 'G'}};
char cubeM4[3][3] = {{'Y', 'Y', 'Y'}, {'Y', 'Y', 'Y'}, {'Y', 'Y', 'Y'}};
char cubeL[3][3] = {{'R', 'R', 'R'}, {'R', 'R', 'R'}, {'R', 'R', 'R'}};

void printCube()
{
    for (int i = 0; i < 3; i++)
        cout << "\t" << cubeU[i][0] << " " << cubeU[i][1] << " " << cubeU[i][2] << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << cubeM1[i][0] << " " << cubeM1[i][1] << " " << cubeM1[i][2] << "\t";
        cout << cubeM2[i][0] << " " << cubeM2[i][1] << " " << cubeM2[i][2] << "\t";
        cout << cubeM3[i][0] << " " << cubeM3[i][1] << " " << cubeM3[i][2] << "\t";
        cout << cubeM4[i][0] << " " << cubeM4[i][1] << " " << cubeM4[i][2] << "\t" << endl;
    }
    for (int i = 0; i < 3; i++)
        cout << "\t" << cubeL[i][0] << " " << cubeL[i][1] << " " << cubeL[i][2] << endl;
}

void rotateF(string direction)
{
    char temp[3] = {};
    if (direction == "F")
        for (int i = 0; i < 3; i++)
        {
            temp[i] = cubeU[2][i];
            cubeU[2][i] = cubeM1[2 - i][2];
            cubeM1[2 - i][2] = cubeL[0][2 - i];
            cubeL[0][2 - i] = cubeM3[i][0];
            cubeM3[i][0] = temp[i];
        }
    else
        for (int i = 0; i < 3; i++)
        {
            temp[i] = cubeU[2][i];
            cubeU[2][i] = cubeM3[i][0];
            cubeM3[i][0] = cubeL[0][2 - i];
            cubeL[0][2 - i] = cubeM1[2 - i][2];
            cubeM1[2 - i][2] = temp[i];
        }
}

void rotateR(string direction)
{
    char temp[3] = {};
    if (direction == "R")
        for (int i = 0; i < 3; i++)
        {
            temp[i] = cubeU[i][2];
            cubeU[i][2] = cubeM2[i][2];
            cubeM2[i][2] = cubeL[i][2];
            cubeL[i][2] = cubeM4[2 - i][0];
            cubeM4[2 - i][0] = temp[i];
        }
    else
        for (int i = 0; i < 3; i++)
        {
            temp[i] = cubeU[i][2];
            cubeU[i][2] = cubeM4[2 - i][0];
            cubeM4[2 - i][0] = cubeL[i][2];
            cubeL[i][2] = cubeM2[i][2];
            cubeM2[i][2] = temp[i];
        }
}

void rotateU(string direction)
{
    char temp[3] = {};
    if (direction == "U")
        for (int i = 0; i < 3; i++)
        {
            temp[i] = cubeM1[0][i];
            cubeM1[0][i] = cubeM2[0][i];
            cubeM2[0][i] = cubeM3[0][i];
            cubeM3[0][i] = cubeM4[0][i];
            cubeM4[0][i] = temp[i];
        }
    else
        for (int i = 0; i < 3; i++)
        {
            temp[i] = cubeM1[0][i];
            cubeM1[0][i] = cubeM4[0][i];
            cubeM4[0][i] = cubeM3[0][i];
            cubeM3[0][i] = cubeM2[0][i];
            cubeM2[0][i] = temp[i];
        }
}

void rotateB(string direction)
{
    char temp[3] = {};
    if (direction == "B")
        for (int i = 0; i < 3; i++)
        {
            temp[i] = cubeU[0][i];
            cubeU[0][i] = cubeM3[i][2];
            cubeM3[i][2] = cubeL[2][2 - i];
            cubeL[2][2 - i] = cubeM1[2 - i][0];
            cubeM1[2 - i][0] = temp[i];
        }
    else
        for (int i = 0; i < 3; i++)
        {
            temp[i] = cubeU[0][i];
            cubeU[0][i] = cubeM1[2 - i][0];
            cubeM1[2 - i][0] = cubeL[2][2 - i];
            cubeL[2][2 - i] = cubeM3[i][2];
            cubeM3[i][2] = temp[i];
        }
}

void rotateL(string direction)
{
    char temp[3] = {};
    if (direction == "L")
        for (int i = 0; i < 3; i++)
        {
            temp[i] = cubeU[2 - i][0];
            cubeU[2 - i][0] = cubeM4[i][2];
            cubeM4[i][2] = cubeL[2 - i][0];
            cubeL[2 - i][0] = cubeM2[2 - i][0];
            cubeM2[2 - i][0] = temp[i];
        }
    else
        for (int i = 0; i < 3; i++)
        {
            temp[i] = cubeU[2 - i][0];
            cubeU[2 - i][0] = cubeM2[2 - i][0];
            cubeM2[2 - i][0] = cubeL[2 - i][0];
            cubeL[2 - i][0] = cubeM4[i][2];
            cubeM4[i][2] = temp[i];
        }
}

void rotateD(string direction)
{
    char temp[3] = {};
    if (direction == "D")
        for (int i = 0; i < 3; i++)
        {
            temp[i] = cubeM1[2][i];
            cubeM1[2][i] = cubeM4[2][i];
            cubeM4[2][i] = cubeM3[2][i];
            cubeM3[2][i] = cubeM2[2][i];
            cubeM2[2][i] = temp[i];
        }
    else
        for (int i = 0; i < 3; i++)
        {
            temp[i] = cubeM1[2][i];
            cubeM1[2][i] = cubeM2[2][i];
            cubeM2[2][i] = cubeM3[2][i];
            cubeM3[2][i] = cubeM4[2][i];
            cubeM4[2][i] = temp[i];
        }
}

int main()
{
    printCube();
    return 0;
}