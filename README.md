# 3�ܰ�: ��� ť�� �����ϱ�

## ����

---

## ��������

```
char cubeU[3][3] = {{'B', 'B', 'B'}, {'B', 'B', 'B'}, {'B', 'B', 'B'}};
char cubeM1[3][3] = {{'W', 'W', 'W'}, {'W', 'W', 'W'}, {'W', 'W', 'W'}};
char cubeM2[3][3] = {{'O', 'O', 'O'}, {'O', 'O', 'O'}, {'O', 'O', 'O'}};
char cubeM3[3][3] = {{'G', 'G', 'G'}, {'G', 'G', 'G'}, {'G', 'G', 'G'}};
char cubeM4[3][3] = {{'Y', 'Y', 'Y'}, {'Y', 'Y', 'Y'}, {'Y', 'Y', 'Y'}};
char cubeL[3][3] = {{'R', 'R', 'R'}, {'R', 'R', 'R'}, {'R', 'R', 'R'}};
```

ť���� ���� �������� 3x3 �迭�� ���������� �����Ͽ����ϴ�.

---

## printCube()

```
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
```

ť���� �� ���� ����մϴ�. ��� ȭ���� �Ʒ��� �����ϴ�.

```
        B B B
        B B B
        B B B
W W W   O O O   G G G   Y Y Y
W W W   O O O   G G G   Y Y Y
W W W   O O O   G G G   Y Y Y
        R R R
        R R R
        R R R
```

---

## rotateF_cw(), rotateR_cw() ...

```
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
```

ť���� F, R, U, B, L, D �κ��� �ð�������� ȸ���մϴ�.

---

## rotateF_ccw(), rotateR_ccw() ...

```
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
```

ť���� F, R, U, B, L, D �κ��� �ݽð�������� ȸ���մϴ�.

---

## string checkDirection(string int, int &index)

```
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
```

main �Լ����� ������ �� �ٷ� input�� �Է� ������  
���� index�� �ִ� ������ �������� �Ǵ��Ͽ� ��ȯ�մϴ�.

---

## rotateCube_cw(string direction, int &count)

```
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
```

���� ������ ����ִ� direction ������ �������� �Ǵ��Ͽ� �� �������� ȸ���ϴ� �Լ��� �����մϴ�.  
���۰����� ī��Ʈ�ϱ� ���� count������ �� �Լ��� ����ɶ����� �����մϴ�.

---

## rotateCube_ccw(string direction, int &count)

```
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
```

rotateCube_cw�� �ݴ��, �ݽð� �������� ȸ���ϴ� �Լ��� �����մϴ�.  
�ٸ� ���� �ִٸ� �� �Լ��� ���� ������ ��Ÿ���� direction�� ���̰� 2�̸� �����մϴ�.

```
ex) R', R2
```

���� direction[1]�� �˻��Ͽ� `'` �̶�� repeatNum�� 0�� �Ǿ� �ݽð�������� 1�� ȸ��������,  
direction[1]�� `2` ��� repeatNum�� 1�� �Ǿ� �ݽð�������� 2�� ȸ������ ���� `R2`�� ����  
2�� ȸ���ϴ� Ŀ�ǵ带 �����մϴ�.

---

## printTime(chrono::system_clock::time_point startTime)

```
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
```

����ð��� ��Ÿ���� ���� �Լ��Դϴ�.  
`00:00 `�� ��Ÿ���� ���� �����ڸ� ����ϰ� ������ 0���� ä�����ϴ�.

---

## shuffleCube()

```
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
```

ť�긦 �������� ���� �Լ��Դϴ�.  
������ ���� ������ ������ ���� ���� 100�� �����ϴ�.

---

## string endFlagCheck(int &index, string input)

```
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
```

ť�갡 �� ���߾� ������ Ȯ���ϴ� �Լ��Դϴ�.  
�� ���߾� ���ٸ� `YES` �� ��ȯ�Ͽ� main �Լ����� Ȯ���ϰ� �����մϴ�.  
2�� for���� ���� �� ���� ���߾� ������ Ȯ���ϱ� ������ �鿩���Ⱑ 4���� �Ǿ����ϴ�.

---

## main()

```
int main()
{
    chrono::system_clock::time_point startTime = chrono::system_clock::now();

    string input = "";
    string direction = "";
    string endFlag = "NO";
    int count = 0;
    ...
```

ó���� main�Լ����� �ʱ�ȭ �ϴ� �����Դϴ�.  
`endFlag`�� `NO`�� �����Ͽ� ó�� ť�갡 �� ���߾��� ���¿��� ������ ��, ������� �����մϴ�.  
`count`�� `0`���� �����Ͽ� ���� �������� ���۰����� ��Ÿ���ϴ�.

```
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
        ...
```

ó�� �������� `endFlag = NO`�̱⿡ ť���� ������ �Է¹ް� �����ϰ� �˴ϴ�.  
�� �Ŀ��� `Q`�� �Է��ϰų�, ť�갡 �� �ϼ��Ǿ��� ��  
`printTime(startTime)`�� ���� ��� �ð��� ����ϰ�, `count`�� ���� ���۰����� ����մϴ�.  
�� �� ���α׷��� �����ϰ� �˴ϴ�.

```
        ...
        if (input == "shuffle")
        {
            cout << "ť�긦 �����ϴ�." << endl;
            cout << "��ø� ��ٷ��ּ���." << endl;
            shuffleCube();
            printCube();
            continue;
        }
        ...
```

`shuffle`�� �ԷµǸ� ť�긦 ���� �� ť���� ���¸� ����ϰ� �ݺ����� ó������ ���ư��ϴ�.

```
        ...
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
    ...
```

`Q`�� `shuffle`�� �ƴ� ���۹��� �Է��� �Ǹ� `checkDirection`�� ���� `direction`�� ���� ������  
�Է��ϰ� �ǰ�, �ܼ� ����`(F,R,U,B,L,D)`�̶�� `rotateCube_cw`�� ���� �ð���� ȸ����,  
Ư�� ����`(F', F2 ...)`�̶�� `rotateCube_ccw`�� ���� ��ɾ ���� ȸ���� �մϴ�.  
�� �� `printCube`�� ���� ť���� ���¸� ����ϰ�  
`endFlagCheck`�� ���� ť�갡 �� ���߾� �������� �Ǵ��ϰ� �˴ϴ�.
