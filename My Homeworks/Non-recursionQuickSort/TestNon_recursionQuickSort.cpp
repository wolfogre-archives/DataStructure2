#include "Non_recursionQuickSort.h"	
//�����Ŀǰû����ȫ�������⣬��Ū�������Ŀ�����ʲô��˼���Ժ����
int main(void)
{
	int a[] = {55, 63, 38, 21, 63, 92, 16, 46, 87, 72};
	int n = 10;
	cout << "����ǰ:";
	Display(a, n);				 
	Non_recursionQuickSort(a, n);	
	cout << "�����:";
	Display(a, n);				

	system("PAUSE");			
	return 0;					
}