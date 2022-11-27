#include "tree.h"
#include <iostream>
#include <time.h>

using namespace std;
void testTemplateInt()
{
	treeNodeTP<int> *rootPtr = NULL;
	// insert random values between 1 and 15 in the tree
	printf("The numbers being placed in the tree are:\n");
	for (int i = 1; i <= 15; i++)
	{
		int item = rand() % 15;
		cout << item << "  ";
		insertNodeTP(rootPtr, item);
	}
	//traverse the tree preOrder
	printf("\n\nThe preOrder traversal is:\n");
	preOrderTP(rootPtr);
	// traverse the tree inOrder
	printf("\n\nThe inOrder traversal is:\n");
	inOrderTP(rootPtr);
	//traverse the tree postOrder
	printf("\n\nThe postOrder traversal is:\n");
	postOrderTP(rootPtr);
	cout << "\n\n";
}
void testTemplateFloat()
{
	treeNodeTP<float> *rootPtr = NULL;
	/* insert random values between 1 and 15 in the tree */
	printf("The numbers being placed in the tree are:\n");
	for (int i = 1; i <= 15; i++)
	{
		float item = 1.0 + (float)(rand() % 8) * 0.01f;
		std::cout << item << "  ";
		insertNodeTP(rootPtr, item);
	}
	/* traverse the tree preOrder */
	printf("\n\nThe preOrder traversal is:\n");
	preOrderTP(rootPtr);
	/* traverse the tree inOrder */
	printf("\n\nThe inOrder traversal is:\n");
	inOrderTP(rootPtr);
	/* traverse the tree postOrder */
	printf("\n\nThe postOrder traversal is:\n");
	postOrderTP(rootPtr);
	cout << "\n\n";
}
void testTemplateBoot()
{
	treeNodeTP<book> *rootPtr = NULL;
	book item;
	/* insert random values between 1 and 15 in the tree */
	printf("The books being placed in the tree are:\n");

	setBookData(item, "��q���ǿ��ѧ޳N�G����ABBYY FineReader 11 OCR", "�����q", 371);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "VISUAL FORTRAN�{���]�p�P�}�o", "�i�űj�B���E��", 400);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "�{���]�p�Шϥ�C++", "���خx", 420);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "��Ʈw�t�Ρ�MTA�{�Ҽv���о�", "���K��", 336);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "���P�d�wGoogle���ݧ޳N�GMaps.Android.App Engine.Cloud SQL�P�q�l�Ӱ�API��ҸѪR", "���@��", 560);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "�H�u���z�G���z���t�ξɽ�(�ĤT��) ", "���p�� ��ҹ�w �¬F��", 590);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "�q����������(�ĤG��)", "�����s", 420);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "���ں����P�q�l�Ӱ�(�ĤT��)", "������", 450);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "��Ʈw�t�βz�סШϥ�SQL Server 2008", "���K��", 650);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "�ʵe�ϸѸ�Ʈw�t�βz�סШϥ�Access 2010��@(�ĤG��)", "���K��", 600);
	printFun(item);
	insertNodeTP(rootPtr, item);

	////////////////////
	// test duplicate data
	setBookData(item, "��q���ǿ��ѧ޳N�G����ABBYY FineReader 11 OCR", "�����q", 371);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "VISUAL FORTRAN�{���]�p�P�}�o", "�i�űj�B���E��", 400);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "�{���]�p�Шϥ�C++", "���خx", 420);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "��Ʈw�t�Ρ�MTA�{�Ҽv���о�", "���K��", 336);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "���P�d�wGoogle���ݧ޳N�GMaps.Android.App Engine.Cloud SQL�P�q�l�Ӱ�API��ҸѪR", "���@��", 560);
	printFun(item);
	insertNodeTP(rootPtr, item);

	/* traverse the tree preOrder */
	printf("\n\nThe preOrder traversal is:\n");
	preOrderTP(rootPtr);
	/* traverse the tree inOrder */
	printf("\n\nThe inOrder traversal is:\n");
	inOrderTP(rootPtr);
	/* traverse the tree postOrder */
	printf("\n\nThe postOrder traversal is:\n");
	postOrderTP(rootPtr);
	std::cout << endl
			  << endl;
}
int main()
{

	testTemplateInt();
	testTemplateFloat();

	testTemplateBoot();
	/*	book a, b;
	setBookData(a, "abcdaaa", "?????q", 371);
	setBookData(b, "abch", "?????q", 371);
	cout << compareFun(a, b);	*/

	system("pause");
	return 0;
}
