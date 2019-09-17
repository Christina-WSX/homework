#define  _CRT_SECURE_NO_WARNINGS

/*************************************************
**  学生成绩管理系统
**  GNU General Public License(GNU GPL)
/**************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "score.h"

/*----------------------------------*
		Main Function
*-----------------------------------*/

int main()
{

	printf("******************************\n");
	printf("       学生成绩管理分析系统        \n");
	printf("        wangshuxian            \n");
	printf("******************************\n\n");

	/*-1.变量初始化-*/
	int N = 0;            //学生总数
	SS  *pstu = NULL;    //学生数组-结构体数组指针实现

	//2.读取学生信息
	pstu = readDataFromFile(&N);

	/*-3.计算学生总成绩（总成绩 = 0.3*平时成绩 + 0.8*期末成绩)--*/
	calcuScore(pstu, N);

	/*-4.根据学生成绩排名-*/
	sortScore(pstu, N);

	/*-5.按照排名输出学生信息-*/
	printOut(pstu, N);

	//*6.  查询：输入学号可查询某个学生的成绩信息。
	searchInformation(pstu, N);


	//*7. 分析：统计全班学生成绩的均值和标准方差，并对成绩分布简要分析
	analysisScore(pstu, N);

	/*-8.释放动态内存空间-*/
	free(pstu);


	system("pause");
	return 0;
}
