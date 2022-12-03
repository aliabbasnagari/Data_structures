/*
Ali Abbas - 21I-2503
Adnan Hayat
Muhammad Wissam - 21I-0709
*/


#include "../Data_structures/AVL.h"
#include "../Data_structures/BTree.h"

#include "../Data_structures/Utils.h"
#include "../Data_structures/RedBlackTree.h"
#include "../Data_structures/BinarySearchTree.h"

#include "AVL.h"
#include "Header.h"
#include "Utils.h"

using namespace std;

int main() {
	string path = "datafiles/test2.csv";
	Queue<Entry>* q;
	q= readCSV(path);
	AVLTree<DataNode> avl;
	int len = q->Size();
	for (int i = 0; i < len; i++)
	{
		DataNode node;
		node.filepath = path;
		node.id = q->Front().getId();
		node.line = (i + 1);
		avl.insert(node);
		q->dequeue();
	}

	//C:/user/4star/source/repos/Data_Structures/
	BTree<int> bree;
		bree.traverse();
	cout << endl;
	q = readCSV("datafiles/test_data.csv");
	q->show();

	avl.LevelOrderTreversal(avl.root);
	avl.getQuery("get <state> with # id=11");

	return 0;
}