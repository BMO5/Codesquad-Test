# 1단계: 단어 밀어내기 구현하기

## 설명

```
while (1)
{
cin >> word >> rotate_num >> direction;
if (-100 <= rotate_num && rotate_num < 100)
break;
else
cout << "정수는 -100 <= N < 100 으로 입력해 주세요." << endl;
}
```

정수의 범위를 만족해야 단어를 밀어냅니다.

---

```
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
```

방향은 2가지 기준으로 정하게 됩니다.

1. 왼쪽으로 밀기: L과 양의 정수를 입력 받거나, R과 음의 정수를 입력 받을 때
2. 오른쪽으로 밀기: R과 양의 정수를 입력받거나, L과 음의 정수를 입력 받을 때

방향을 정했다면 단어의 길이로 나눈 나머지를 구하고, 나머지 만큼 회전을 하게 됩니다.
