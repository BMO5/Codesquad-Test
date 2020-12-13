# 2단계: 평면 큐브 구현하기

## 설명

---

- cube_print()

```
void cube_print(char cube_arr[][3])
{
    for (int i = 0; i < 3; i++)
        cout << cube_arr[i][0] << " " << cube_arr[i][1] << " " << cube_arr[i][2] << endl;
    cout << endl;
}
```

평면 큐브의 상태를 출력합니다.

---

- U_cw(), U_ccw() …

```
void U_cw(char cube_arr[][3])
{
    char temp = cube_arr[0][2];
    cube_arr[0][2] = cube_arr[0][1];
    cube_arr[0][1] = cube_arr[0][0];
    cube_arr[0][0] = temp;
}
```

선택한 줄을 시계방향으로 밀어냅니다.

```
void U_ccw(char cube_arr[][3])
{
    char temp = cube_arr[0][0];
    cube_arr[0][0] = cube_arr[0][1];
    cube_arr[0][1] = cube_arr[0][2];
    cube_arr[0][2] = temp;
}
```

선택한 줄을 반시계방향으로 밀어냅니다.  
위 함수들은 U, R, L, B로 방향을 정할 수 있습니다.

---

- main()

```
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
```

input으로 여러 문자를 입력받게 되면 연속으로 처리하기 위해  
문자의 길이만큼 반복합니다.  
여기서 문자가 " 문자 " 인지 " 문자 + ' " 인지 검출을 한 후,  
str_temp에 넣어줍니다.

```
            if (str_temp == "U")
                U_ccw(cube_arr);
            else if (str_temp == "U'")
                U_cw(cube_arr);
            else if (str_temp == "R")
                R_ccw(cube_arr);
            else if (str_temp == "R'")
                R_cw(cube_arr);
                ...
```

이제 str_temp를 확인하여 그에 맞는 방향으로 큐브를 회전시킵니다.

```
            else if (str_temp == "Q")
            {
                cout << "Bye~" << endl;
                return 0;
            }
```

'Q'를 입력 받으면 "Bye~"를 출력하고 종료합니다.
