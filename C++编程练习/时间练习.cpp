#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <utility>
#include <time.h> 
#include <stdio.h> 
using namespace std;
int main (void){

	time_t t = time(0); 
	char tmp[64],second[4]; 
	strftime( tmp, sizeof(tmp), "%Y/%m/%d %X %A %S �����%j�� %z",localtime(&t) ); 
	puts( tmp ); 
	strftime( second, sizeof(second), "%S",localtime(&t) ); 
	int second_time=(int)second;
	cout<< 
	return 0; 
	
	}
/*
size_t strftime(char *strDest, size_t maxsize, const char *format, const struct tm *timeptr); 
���ݸ�ʽ�ַ��������ַ����� 
struct tm *localtime(const time_t *timer); 
ȡ�õ���ʱ�䣬localtime��ȡ�Ľ���ɽṹtm���� 
���ص��ַ������������еĸ�ʽ������ 
%a ���ڼ�����д��Eg:Tue 
%A ���ڼ���ȫ���� Eg: Tuesday 
%b �·����Ƶ���д�� 
%B �·����Ƶ�ȫ���� 
%c ���ض�����ʱ��ϼѱ�ʾ�ַ����� 
%d �����ֱ�ʾ���µĵڼ��� (��ΧΪ 00 �� 31)������ 
%H �� 24 Сʱ�����ֱ�ʾСʱ�� (��ΧΪ 00 �� 23)�� 
%I �� 12 Сʱ�����ֱ�ʾСʱ�� (��ΧΪ 01 �� 12)�� 
%j �����ֱ�ʾ����ȵĵڼ��� (��ΧΪ 001 �� 366)�� 
%m �·ݵ����� (��Χ�� 1 �� 12)�� 
%M ���ӡ� 
%p �� ''AM'' �� ''PM'' ��ʾ���ض�ʱ�䡣 
%S ������ 
%U ���ֱ�ʾΪ����ȵĵڼ��ܣ���һ�������ɵ�һ�����տ�ʼ�� 
%W ���ֱ�ʾΪ����ȵĵڼ��ܣ���һ�������ɵ�һ����һ��ʼ�� 
%w �����ֱ�ʾ���ܵĵڼ��� ( 0 Ϊ����)�� 
%x ����ʱ������ڱ�ʾ���� 
%X �������ڵ�ʱ���ʾ���� Eg: 15:26:30 
%y ��λ���ֱ�ʾ��� (��Χ�� 00 �� 99)�� 
%Y ������������ֱ�ʾ������λ���� Eg:2008 
%Z(%z) ʱ����������д��Eg:�й���׼ʱ�� 
%% % �ַ��� 

*/
  

