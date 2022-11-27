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

	setBookData(item, "精通光學辨識技術：應用ABBYY FineReader 11 OCR", "黃敦義", 371);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "VISUAL FORTRAN程式設計與開發", "張嘉強、陳鴻智", 400);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "程式設計－使用C++", "黃建庭", 420);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "資料庫系統－MTA認證影音教學", "李春雄", 336);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "輕鬆搞定Google雲端技術：Maps.Android.App Engine.Cloud SQL與電子商務API實例解析", "陳世興", 560);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "人工智慧：智慧型系統導論(第三版) ", "李聯旺 廖珗洲 謝政勳", 590);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "電腦網路概論(第二版)", "陳雲龍", 420);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "網際網路與電子商務(第三版)", "朱正忠", 450);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "資料庫系統理論－使用SQL Server 2008", "李春雄", 650);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "動畫圖解資料庫系統理論－使用Access 2010實作(第二版)", "李春雄", 600);
	printFun(item);
	insertNodeTP(rootPtr, item);

	////////////////////
	// test duplicate data
	setBookData(item, "精通光學辨識技術：應用ABBYY FineReader 11 OCR", "黃敦義", 371);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "VISUAL FORTRAN程式設計與開發", "張嘉強、陳鴻智", 400);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "程式設計－使用C++", "黃建庭", 420);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "資料庫系統－MTA認證影音教學", "李春雄", 336);
	printFun(item);
	insertNodeTP(rootPtr, item);

	setBookData(item, "輕鬆搞定Google雲端技術：Maps.Android.App Engine.Cloud SQL與電子商務API實例解析", "陳世興", 560);
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
