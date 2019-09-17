/*************************************************
** Դ�ļ�   : score.c
** ����˵�� : Function Definitions
** �����汾 : V1.0
/**************************************************/

/*----------------ͷ�ļ�--------------*/
#define  _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "SCORE.h"

/*----------------��������-------------*/

//1.1�ֶ�����ѧ����������
void readData(SS stu[], int N)
{

	printf("�밴�����¸�ʽ����ѧ����Ϣ��ѧ��,����,ƽʱ�ɼ�,��ĩ�ɼ�\n");

	for (int i = 0; i < N; i++)
	{
		printf("��%d��ѧ��:", i + 1);
		scanf("%s %s %f %f", &stu[i].number, &stu[i].name, &stu[i].dailyScore, &stu[i].finalScore);
		printf("\n");
	}

	printf("------�ɼ�¼�����!--------\n");

}

//1.2���ļ����ȡѧ����������
SS* readDataFromFile(int *N)
{

	printf("\n\n------��һ��: ���ļ���ȡѧ���ĳɼ���Ϣ--------\n\n");

	SS *stu;// �����¿ռ�,��ȡ�ļ��е�ÿ��ѧ����Ϣ

	FILE *fp = NULL;
	int count = 0;
	int index = 0;

	fp = fopen("data.txt", "r");

	//1.��ȡѧ����Ŀ
	if (fp != NULL)
	{
		fscanf(fp, "%d", &count);
		*N = count;
	}
	else
	{
		printf("failed to open the info file\n");
		getchar();
	}

	printf("ѧ����ĿΪ:%d\n", count);


	//2.������ѧ������洢�ռ�
	stu = (SS*)malloc(count * sizeof(SS));


	//3.��ȡÿ��ѧ������Ϣ
	while ((!feof(fp)))
	{

		//�����ļ����ݵ��ڴ�	
		fscanf(fp, "%s%s%f%f\n", (stu[index].number), (stu[index].name), &stu[index].dailyScore, &stu[index].finalScore);

		//���������ѧ����Ϣ
		printf("* ѧ�ţ�%s	����:%s		ƽʱ�ɼ���%4.2f��		��ĩ�ɼ�:%4.2f��\n", (stu[index].number), (stu[index].name), stu[index].dailyScore, stu[index].finalScore);

		index++;
	}

	getchar();

	fclose(fp);

	return stu;
}

//2.����N��ѧ�����Ե������ɼ�
void calcuScore(SS stu[], int N)
{


	printf("\n\n------�ڶ���: ����ÿ��ѧ���������ɼ�--------\n\n");

	for (int i = 0; i < N; i++)
	{

		stu[i].generalScore = 0.2*stu[i].dailyScore + 0.8*stu[i].finalScore;
		printf("* ѧ�ţ�%s	����:%s		�ܳɼ�:%4.2f��\n", (stu[i].number), (stu[i].name), stu[i].generalScore);

	}

	getchar();
}


//3.���������ɼ�����
int cmpBigtoSmall(const void *a, const void *b)
{

	SS *aa = (SS *)(a);
	SS *bb = (SS *)(b);



	if ((*aa).generalScore < (*bb).generalScore)  return 1;

	else if ((*aa).generalScore > (*bb).generalScore)  return -1;

	else
		return 0;

}

void sortScore(SS stu[], int N)
{

	qsort(&(stu[0]), N, sizeof(stu[0]), cmpBigtoSmall);

}

//4.����һ���ĸ�ʽ���N��ѧ������Ϣ
void printOut(SS stu[], int N)
{

	printf("\n------������: �����ܳɼ����ѧ��������Ϣ!------\n\n");

	for (int i = 0; i < N; i++)
	{

		printf("��%d����Ϣ ѧ�ţ�%s	����:%s		�ܳɼ�:%4.2f��\n", i + 1, &(stu[i].number[0]), &(stu[i].name[0]), stu[i].generalScore);
	}

	getchar();

}
//5.��ѯ������ѧ�ſ��Բ�ѯĳ��ѧ���ĳɼ���Ϣ
void search(SS stu[],int N);
{
	printf("\n------���Ĳ�������ѧ�Ų�ѯĳ��ѧ���ĳɼ���Ϣ��-----\n");
	int i, k = -1;
	int index = 0;
	char c[6];
	printf("������Ҫ��ѯ��ѧ�ţ�");
	scanf("%s",c);
	for (int i = 0; i < N;i++);
	{
		if (stu[i].number == c)
		{
			printf("��ѧ������ϢΪ��%s %s %4.2f �� %4.2f �� %4.2f �� \n",(stu[i].number),(stu[i].name),(stu[i].dailyScore),stu[i].experimentalScore,stu[i].finalScore);
		}
	}
}
//6.ͳ��ȫ��ѧ���ɼ��ľ�ֵ�ͱ�׼������Գɼ��ֲ���Ҫ����
void analysis(SS stu[],int N);
{
	float mean;
	float variance;
	for (int i = 0; i < N; i++)
	{
		mean += stu[i].generalScore;
	}
	mean = 1.0*mean / N;
	for (int i = 0; i < N; i++)
	{
		variance += (stu[i].generalScore - mean) * (stu[i].generalScore - mean);
	}
	variance = 1.0 * variance / N;
	if (mean >= 80)
		printf("ȫ��ͬѧ�ľ�ֵΪ:%4.4f��  ����ˮƽ���㣡\n", mean);
	else if (mean >= 60)
		printf("ȫ��ͬѧ�ľ�ֵΪ:%4.4f��  ����ˮƽ�Ƚϲ\n", mean);
	else
		printf("ȫ��ͬѧ�ľ�ֵΪ:%4.4f��  ����ˮƽ�ǳ��\n", mean);

	if (variance <= 10)
		printf("ȫ��ͬѧ�ķ���Ϊ:%4.4f�� �ɼ�������С��", variance);
	else if (variance <= 20)
		printf("ȫ��ͬѧ�ķ���Ϊ:%4.4f�� �ɼ������е��", variance);
	else
		printf("ȫ��ͬѧ�ķ���Ϊ:%4.4f�� �ɼ������ǳ���", variance);
	printf("ȫ��ͬѧ�ľ�ֵΪ:%4.4f \n ����Ϊ:%4.4f\n", mean, variance);
	getchar();
}