# 3단계: 루빅스 큐브 구현하기

## 설명

---

## 전역변수

```
char cubeU[3][3] = {{'B', 'B', 'B'}, {'B', 'B', 'B'}, {'B', 'B', 'B'}};
char cubeM1[3][3] = {{'W', 'W', 'W'}, {'W', 'W', 'W'}, {'W', 'W', 'W'}};
char cubeM2[3][3] = {{'O', 'O', 'O'}, {'O', 'O', 'O'}, {'O', 'O', 'O'}};
char cubeM3[3][3] = {{'G', 'G', 'G'}, {'G', 'G', 'G'}, {'G', 'G', 'G'}};
char cubeM4[3][3] = {{'Y', 'Y', 'Y'}, {'Y', 'Y', 'Y'}, {'Y', 'Y', 'Y'}};
char cubeL[3][3] = {{'R', 'R', 'R'}, {'R', 'R', 'R'}, {'R', 'R', 'R'}};
```

큐브의 면을 기준으로 3x3 배열을 전역변수로 생성하였습니다.

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

큐브의 각 면을 출력합니다. 출력 화면은 아래와 같습니다.

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

큐브의 F, R, U, B, L, D 부분을 시계방향으로 회전합니다.

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

큐브의 F, R, U, B, L, D 부분을 반시계방향으로 회전합니다.

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

main 함수에서 조작을 한 줄로 input에 입력 받으면  
현재 index에 있는 조작이 무엇인지 판단하여 반환합니다.

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

조작 방향이 들어있는 direction 변수가 무엇인지 판단하여 그 방향으로 회전하는 함수를 실행합니다.  
조작갯수를 카운트하기 위해 count변수는 이 함수가 실행될때마다 증가합니다.

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

rotateCube_cw와 반대로, 반시계 방향으로 회전하는 함수를 실행합니다.  
다른 점이 있다면 이 함수는 조작 방향을 나타내는 direction의 길이가 2이면 실행합니다.

```
ex) R', R2
```

따라서 direction[1]을 검사하여 `'` 이라면 repeatNum은 0이 되어 반시계방향으로 1번 회전하지만,  
direction[1]이 `2` 라면 repeatNum은 1이 되어 반시계방향으로 2번 회전시켜 위의 `R2`와 같은  
2번 회전하는 커맨드를 실행합니다.

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

    cout << "경과시간: " << setw(2) << setfill('0') << min60 << ":";
    cout << setw(2) << setfill('0') << sec60 << endl;
}
```

경과시간을 나타내기 위한 함수입니다.  
`00:00 `로 나타내기 위해 조정자를 사용하고 공백을 0으로 채웠습니다.

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

큐브를 무작위로 섞는 함수입니다.  
난수를 통해 생성된 무작위 수에 따라 100번 섞습니다.

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

큐브가 다 맞추어 졌는지 확인하는 함수입니다.  
다 맞추어 졌다면 `YES` 를 반환하여 main 함수에서 확인하고 종료합니다.  
2중 for문을 통해 각 면이 맞추어 졌는지 확인하기 때문에 들여쓰기가 4줄이 되었습니다.

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

처음에 main함수에서 초기화 하는 변수입니다.  
`endFlag`는 `NO`로 시작하여 처음 큐브가 다 맞추어진 상태에서 시작할 때, 종료됨을 방지합니다.  
`count`는 `0`으로 시작하여 종료 시점에서 조작갯수를 나타냅니다.

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
            cout << "             축하드립니다! 큐브를 완성하셨습니다!" << endl;
            cout << "*****************************************************************" << endl;
        }

        if (input == "Q" || endFlag == "YES")
        {
            printTime(startTime);
            cout << "조작갯수: " << count << endl;
            cout << "이용해주셔서 감사합니다. 뚜뚜뚜." << endl;
            return 0;
        }
        ...
```

처음 시점에는 `endFlag = NO`이기에 큐브의 조작을 입력받고 시작하게 됩니다.  
그 후에는 `Q`를 입력하거나, 큐브가 다 완성되었을 시  
`printTime(startTime)`을 통해 경과 시간을 출력하고, `count`를 통해 조작갯수를 출력합니다.  
그 후 프로그램을 종료하게 됩니다.

```
        ...
        if (input == "shuffle")
        {
            cout << "큐브를 섞습니다." << endl;
            cout << "잠시만 기다려주세요." << endl;
            shuffleCube();
            printCube();
            continue;
        }
        ...
```

`shuffle`이 입력되면 큐브를 섞은 후 큐브의 상태를 출력하고 반복문의 처음으로 돌아갑니다.

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

`Q`와 `shuffle`이 아닌 조작법이 입력이 되면 `checkDirection`을 통해 `direction`에 조작 방향을  
입력하게 되고, 단순 조작`(F,R,U,B,L,D)`이라면 `rotateCube_cw`를 통해 시계방향 회전을,  
특수 조작`(F', F2 ...)`이라면 `rotateCube_ccw`를 통해 명령어에 따른 회전을 합니다.  
그 후 `printCube`를 통해 큐브의 상태를 출력하고  
`endFlagCheck`를 통해 큐브가 다 맞추어 졌는지를 판단하게 됩니다.
