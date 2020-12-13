#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include <random>

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

void rotateF_cw()
{
    char temp[3] = {};

    for (int i = 0; i < 3; i++)
    {
        temp[i] = cubeU[2][i];
        cubeU[2][i] = cubeM1[2 - i][2];
        cubeM1[2 - i][2] = cubeL[0][2 - i];
        cubeL[0][2 - i] = cubeM3[i][0];
        cubeM3[i][0] = temp[i];
    }
    for (int j = 0; j < 2; j++)
    {
        temp[j] = cubeM2[0][j];
        cubeM2[0][j] = cubeM2[2 - j][0];
        cubeM2[2 - j][0] = cubeM2[2][2 - j];
        cubeM2[2][2 - j] = cubeM2[j][2];
        cubeM2[j][2] = temp[j];
    }
}

void rotateF_ccw()
{
    char temp[3] = {};

    for (int i = 0; i < 3; i++)
    {
        temp[i] = cubeU[2][i];
        cubeU[2][i] = cubeM3[i][0];
        cubeM3[i][0] = cubeL[0][2 - i];
        cubeL[0][2 - i] = cubeM1[2 - i][2];
        cubeM1[2 - i][2] = temp[i];
    }
    for (int j = 0; j < 2; j++)
    {
        temp[j] = cubeM2[0][j];
        cubeM2[0][j] = cubeM2[j][2];
        cubeM2[j][2] = cubeM2[2][2 - j];
        cubeM2[2][2 - j] = cubeM2[2 - j][0];
        cubeM2[2 - j][0] = temp[j];
    }
}

void rotateR_cw()
{
    char temp[3] = {};

    for (int i = 0; i < 3; i++)
    {
        temp[i] = cubeU[i][2];
        cubeU[i][2] = cubeM2[i][2];
        cubeM2[i][2] = cubeL[i][2];
        cubeL[i][2] = cubeM4[2 - i][0];
        cubeM4[2 - i][0] = temp[i];
    }
    for (int j = 0; j < 2; j++)
    {
        temp[j] = cubeM3[0][j];
        cubeM3[0][j] = cubeM3[2 - j][0];
        cubeM3[2 - j][0] = cubeM3[2][2 - j];
        cubeM3[2][2 - j] = cubeM3[j][2];
        cubeM3[j][2] = temp[j];
    }
}

void rotateR_ccw()
{
    char temp[3] = {};

    for (int i = 0; i < 3; i++)
    {
        temp[i] = cubeU[i][2];
        cubeU[i][2] = cubeM4[2 - i][0];
        cubeM4[2 - i][0] = cubeL[i][2];
        cubeL[i][2] = cubeM2[i][2];
        cubeM2[i][2] = temp[i];
    }
    for (int j = 0; j < 2; j++)
    {
        temp[j] = cubeM3[0][j];
        cubeM3[0][j] = cubeM3[j][2];
        cubeM3[j][2] = cubeM3[2][2 - j];
        cubeM3[2][2 - j] = cubeM3[2 - j][0];
        cubeM3[2 - j][0] = temp[j];
    }
}

void rotateU_cw()
{
    char temp[3] = {};

    for (int i = 0; i < 3; i++)
    {
        temp[i] = cubeM1[0][i];
        cubeM1[0][i] = cubeM2[0][i];
        cubeM2[0][i] = cubeM3[0][i];
        cubeM3[0][i] = cubeM4[0][i];
        cubeM4[0][i] = temp[i];
    }
    for (int j = 0; j < 2; j++)
    {
        temp[j] = cubeU[0][j];
        cubeU[0][j] = cubeU[2 - j][0];
        cubeU[2 - j][0] = cubeU[2][2 - j];
        cubeU[2][2 - j] = cubeU[j][2];
        cubeU[j][2] = temp[j];
    }
}

void rotateU_ccw()
{
    char temp[3] = {};

    for (int i = 0; i < 3; i++)
    {
        temp[i] = cubeM1[0][i];
        cubeM1[0][i] = cubeM4[0][i];
        cubeM4[0][i] = cubeM3[0][i];
        cubeM3[0][i] = cubeM2[0][i];
        cubeM2[0][i] = temp[i];
    }
    for (int j = 0; j < 2; j++)
    {
        temp[j] = cubeU[0][j];
        cubeU[0][j] = cubeU[j][2];
        cubeU[j][2] = cubeU[2][2 - j];
        cubeU[2][2 - j] = cubeU[2 - j][0];
        cubeU[2 - j][0] = temp[j];
    }
}

void rotateB_cw()
{
    char temp[3] = {};

    for (int i = 0; i < 3; i++)
    {
        temp[i] = cubeU[0][i];
        cubeU[0][i] = cubeM3[i][2];
        cubeM3[i][2] = cubeL[2][2 - i];
        cubeL[2][2 - i] = cubeM1[2 - i][0];
        cubeM1[2 - i][0] = temp[i];
    }
    for (int j = 0; j < 2; j++)
    {
        temp[j] = cubeM4[0][j];
        cubeM4[0][j] = cubeM4[2 - j][0];
        cubeM4[2 - j][0] = cubeM4[2][2 - j];
        cubeM4[2][2 - j] = cubeM4[j][2];
        cubeM4[j][2] = temp[j];
    }
}

void rotateB_ccw()
{
    char temp[3] = {};

    for (int i = 0; i < 3; i++)
    {
        temp[i] = cubeU[0][i];
        cubeU[0][i] = cubeM1[2 - i][0];
        cubeM1[2 - i][0] = cubeL[2][2 - i];
        cubeL[2][2 - i] = cubeM3[i][2];
        cubeM3[i][2] = temp[i];
    }
    for (int j = 0; j < 2; j++)
    {
        temp[j] = cubeM4[0][j];
        cubeM4[0][j] = cubeM4[j][2];
        cubeM4[j][2] = cubeM4[2][2 - j];
        cubeM4[2][2 - j] = cubeM4[2 - j][0];
        cubeM4[2 - j][0] = temp[j];
    }
}

void rotateL_cw()
{
    char temp[3] = {};

    for (int i = 0; i < 3; i++)
    {
        temp[i] = cubeU[2 - i][0];
        cubeU[2 - i][0] = cubeM4[i][2];
        cubeM4[i][2] = cubeL[2 - i][0];
        cubeL[2 - i][0] = cubeM2[2 - i][0];
        cubeM2[2 - i][0] = temp[i];
    }
    for (int j = 0; j < 2; j++)
    {
        temp[j] = cubeM1[0][j];
        cubeM1[0][j] = cubeM1[2 - j][0];
        cubeM1[2 - j][0] = cubeM1[2][2 - j];
        cubeM1[2][2 - j] = cubeM1[j][2];
        cubeM1[j][2] = temp[j];
    }
}

void rotateL_ccw()
{
    char temp[3] = {};

    for (int i = 0; i < 3; i++)
    {
        temp[i] = cubeU[2 - i][0];
        cubeU[2 - i][0] = cubeM2[2 - i][0];
        cubeM2[2 - i][0] = cubeL[2 - i][0];
        cubeL[2 - i][0] = cubeM4[i][2];
        cubeM4[i][2] = temp[i];
    }
    for (int j = 0; j < 2; j++)
    {
        temp[j] = cubeM1[0][j];
        cubeM1[0][j] = cubeM1[j][2];
        cubeM1[j][2] = cubeM1[2][2 - j];
        cubeM1[2][2 - j] = cubeM1[2 - j][0];
        cubeM1[2 - j][0] = temp[j];
    }
}

void rotateD_cw()
{
    char temp[3] = {};

    for (int i = 0; i < 3; i++)
    {
        temp[i] = cubeM1[2][i];
        cubeM1[2][i] = cubeM4[2][i];
        cubeM4[2][i] = cubeM3[2][i];
        cubeM3[2][i] = cubeM2[2][i];
        cubeM2[2][i] = temp[i];
    }
    for (int j = 0; j < 2; j++)
    {
        temp[j] = cubeL[0][j];
        cubeL[0][j] = cubeL[2 - j][0];
        cubeL[2 - j][0] = cubeL[2][2 - j];
        cubeL[2][2 - j] = cubeL[j][2];
        cubeL[j][2] = temp[j];
    }
}

void rotateD_ccw()
{
    char temp[3] = {};

    for (int i = 0; i < 3; i++)
    {
        temp[i] = cubeM1[2][i];
        cubeM1[2][i] = cubeM2[2][i];
        cubeM2[2][i] = cubeM3[2][i];
        cubeM3[2][i] = cubeM4[2][i];
        cubeM4[2][i] = temp[i];
    }
    for (int j = 0; j < 2; j++)
    {
        temp[j] = cubeL[0][j];
        cubeL[0][j] = cubeL[j][2];
        cubeL[j][2] = cubeL[2][2 - j];
        cubeL[2][2 - j] = cubeL[2 - j][0];
        cubeL[2 - j][0] = temp[j];
    }
}

string checkDirection(string input, int &index)
{
    if (index != input.length() - 1)
    {
        if (input[index + 1] == '2' || input[index + 1] == '\'')
        {
            index++;
            return input.substr(index - 1, 2);
        }
    }
    return input.substr(index, 1);
}
////////////////////////////////////////
void rotateCube_cw(string direction, int &count)
{
    if (direction[0] == 'F')
        rotateF_cw();
    else if (direction[0] == 'R')
        rotateR_cw();
    else if (direction[0] == 'U')
        rotateU_cw();
    else if (direction[0] == 'B')
        rotateB_cw();
    else if (direction[0] == 'L')
        rotateL_cw();
    else if (direction[0] == 'D')
        rotateD_cw();
    count++;
}

void rotateCube_ccw(string direction, int &count)
{
    int repeatNum = 0;
    if (direction[1] == '2')
        repeatNum++;

    for (int i = 0; i <= repeatNum; i++)
    {
        if (direction[0] == 'F')
            rotateF_ccw();
        else if (direction[0] == 'R')
            rotateR_ccw();
        else if (direction[0] == 'U')
            rotateU_ccw();
        else if (direction[0] == 'B')
            rotateB_ccw();
        else if (direction[0] == 'L')
            rotateL_ccw();
        else if (direction[0] == 'D')
            rotateD_ccw();
        count++;
    }
}

void printTime(chrono::system_clock::time_point startTime)
{
    chrono::system_clock::time_point endTime = chrono::system_clock::now();
    chrono::minutes min = chrono::duration_cast<chrono::minutes>(endTime - startTime);
    chrono::seconds sec = chrono::duration_cast<chrono::seconds>(endTime - startTime);
    int min60 = min.count() % 60;
    int sec60 = sec.count() % 60;

    cout << "����ð�: " << setw(2) << setfill('0') << min60 << ":";
    cout << setw(2) << setfill('0') << sec60 << endl;
}

void shuffleCube()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 5);

    for (int i = 0; i < 100; i++)
    {
        if (dis(gen) == 0)
            rotateF_cw();
        else if (dis(gen) == 1)
            rotateR_cw();
        else if (dis(gen) == 2)
            rotateU_cw();
        else if (dis(gen) == 3)
            rotateB_cw();
        else if (dis(gen) == 4)
            rotateL_cw();
        else if (dis(gen) == 5)
            rotateD_cw();
    }
}

string endFlagCheck(int &index, string input)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (cubeU[1][1] != cubeU[i][j] || cubeM1[1][1] != cubeM1[i][j] ||
                cubeM2[1][1] != cubeM2[i][j] || cubeM3[1][1] != cubeM3[i][j] ||
                cubeM4[1][1] != cubeM4[i][j] || cubeL[1][1] != cubeL[i][j])
                return "NO";
        }
    }
    index = input.length();
    return "YES";
}

int main()
{
    chrono::system_clock::time_point startTime = chrono::system_clock::now();

    string input = "";
    string direction = "";
    string endFlag = "NO";
    int count = 0;

    cout << "*****************************************************************" << endl;
    cout << "  ���ĺ� F, R, U, B, L, D�� �Է��ϸ� �ð�������� ȸ���մϴ�." << endl;
    cout << "      ���ĺ� �ڿ� \'�� ���̸� �ݽð� �������� ȸ���մϴ�." << endl;
    cout << "      2�� ȸ���Ϸ��� ���ĺ� �ڿ� '2'�� �Է��ϼŵ� �˴ϴ�." << endl;
    cout << "    ť�긦 �������� �������� 'shuffle'�� �Է��Ͻø� �˴ϴ�." << endl;
    cout << "            �����Ͻ÷��� 'Q'�� �Է��Ͻø� �˴ϴ�." << endl;
    cout << "*****************************************************************" << endl;

    printCube();
    while (1)
    {
        if (endFlag == "NO")
        {
            cout << "CUBE> ";
            cin >> input;
        }
        else
        {
            cout << "*****************************************************************" << endl;
            cout << "             ���ϵ帳�ϴ�! ť�긦 �ϼ��ϼ̽��ϴ�!" << endl;
            cout << "*****************************************************************" << endl;
        }

        if (input == "Q" || endFlag == "YES")
        {
            printTime(startTime);
            cout << "���۰���: " << count << endl;
            cout << "�̿����ּż� �����մϴ�. �ѶѶ�." << endl;
            return 0;
        }

        if (input == "shuffle")
        {
            cout << "ť�긦 �����ϴ�." << endl;
            cout << "��ø� ��ٷ��ּ���." << endl;
            shuffleCube();
            printCube();
            continue;
        }

        for (int index = 0; index < input.length(); index++)
        {
            direction = checkDirection(input, index);
            cout << direction << endl;
            if (direction.length() == 1)
                rotateCube_cw(direction, count);
            else
                rotateCube_ccw(direction, count);
            printCube();
            endFlag = endFlagCheck(index, input);
        }
    }

    return 0;
}