# 2�ܰ�: ��� ť�� �����ϱ�

## ����

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

��� ť���� ���¸� ����մϴ�.

---

- U_cw(), U_ccw() ��

```
void U_cw(char cube_arr[][3])
{
    char temp = cube_arr[0][2];
    cube_arr[0][2] = cube_arr[0][1];
    cube_arr[0][1] = cube_arr[0][0];
    cube_arr[0][0] = temp;
}
```

������ ���� �ð�������� �о���ϴ�.

```
void U_ccw(char cube_arr[][3])
{
    char temp = cube_arr[0][0];
    cube_arr[0][0] = cube_arr[0][1];
    cube_arr[0][1] = cube_arr[0][2];
    cube_arr[0][2] = temp;
}
```

������ ���� �ݽð�������� �о���ϴ�.  
�� �Լ����� U, R, L, B�� ������ ���� �� �ֽ��ϴ�.

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

input���� ���� ���ڸ� �Է¹ް� �Ǹ� �������� ó���ϱ� ����  
������ ���̸�ŭ �ݺ��մϴ�.  
���⼭ ���ڰ� " ���� " ���� " ���� + ' " ���� ������ �� ��,  
str_temp�� �־��ݴϴ�.

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

���� str_temp�� Ȯ���Ͽ� �׿� �´� �������� ť�긦 ȸ����ŵ�ϴ�.

```
            else if (str_temp == "Q")
            {
                cout << "Bye~" << endl;
                return 0;
            }
```

'Q'�� �Է� ������ "Bye~"�� ����ϰ� �����մϴ�.
