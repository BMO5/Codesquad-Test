# 1�ܰ�: �ܾ� �о�� �����ϱ�

## ����

```
while (1)
{
cin >> word >> rotate_num >> direction;
if (-100 <= rotate_num && rotate_num < 100)
break;
else
cout << "������ -100 <= N < 100 ���� �Է��� �ּ���." << endl;
}
```

������ ������ �����ؾ� �ܾ �о���ϴ�.

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

������ 2���� �������� ���ϰ� �˴ϴ�.

1. �������� �б�: L�� ���� ������ �Է� �ްų�, R�� ���� ������ �Է� ���� ��
2. ���������� �б�: R�� ���� ������ �Է¹ްų�, L�� ���� ������ �Է� ���� ��

������ ���ߴٸ� �ܾ��� ���̷� ���� �������� ���ϰ�, ������ ��ŭ ȸ���� �ϰ� �˴ϴ�.
