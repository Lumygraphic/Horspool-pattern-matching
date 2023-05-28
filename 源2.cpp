#include<cstdio>
#include<cmath>
#include<algorithm>
#include<stack>
#include<iostream>
#include<iomanip>
#include<cstring>
#include <unordered_map>

using namespace std;

char mode[1000];//����ģʽ�ַ���
char text[1000];//�����ı��ַ���
int table[128];//�����

void Shift_table(int size)//Ϊģʽ�ַ���ÿһ���ַ������ƶ���
{
	for (int i = 0; i < 128; i++)
	{
		table[i] = size;
	}

	for (int j = 0; j < size - 1; j++)
	{
		table[mode[j]] = size - 1 - j;
	}

}

int HorspoolMatching(int size1, int size2)
{
	int i = size1 - 1;
	while (i < size2)
	{
		//cout << endl << "β��Ԫ�ش�����λ�ã�" << i + 1 << endl;
		int k = 0;
		//ͨ���������ж��ַ���ƥ�� 
		while (k <= size1 - 1 && mode[size1 - 1 - k] == text[i - k]) {
			k++;
		}
		if (k == size1) return i - size1 + 2;
		//���ƥ�����ˣ���ֱ�ӷ��ز����ַ������ı�����ƥ�䵽�ĵ�һ��λ�� ʵ������i-(size_m-1) +1 
		else i = i + table[text[i]];
		//���û��ƥ�䵽ȫ�� �����ƶ����������ƶ� 

	}
	return -1;//ƥ����δ�ҵ�
}

int main()
{
	string ch1, ch2;
	cout << "�������ı��ַ���" << endl;
	gets_s(text);
	
	cout << "������ģʽ�ַ�����" << endl;
	gets_s(mode);
	
	Shift_table(strlen(mode));//�����ƶ���

	int index = HorspoolMatching(strlen(mode), strlen(text));//����ƥ��λ��

	//cout << "ģʽƥ����λΪ" << index << endl;
	cout << text << endl;
	cout << mode << endl;

	//���ģʽ�ַ���ÿ���ַ����ƶ���
	for (int k = 0; k < strlen(mode) - 1; k++)
	{
		cout << mode[k] << ":" << table[mode[k]] << endl;
	}
	cout << "else:" << strlen(mode) << endl;//δ������ģʽ�ַ�������ַ��ƶ���

	cout << index << endl;//���ģʽƥ�䵽��λ��
	return 0;
}