/*
Ali Abbas - 21I-2503
Adnan Hayat
Muhammad Wissam - 21I-0709
*/

#include<chrono>
#include<thread>
#include<iostream>
#include "AVL.h"
#include "BTree.h"
#include "Header.h"
#include "Utils.h"
#include "Menus.h"
#include "Interface.h"
using namespace std;

void readLogs(LinkedList<AVLTree<DataNode>>* avl, LinkedList<BTree<DataNode>>* btree, LinkedList<RedBlackTree<DataNode>>* rnbtree)
{
	string val = "";
	string root = "database/";
	// File Handling
	fstream data_file;
	data_file.open(root + "logs.txt", ios::in);
	if (data_file.good()) {
		while (!data_file.eof()) {
			val = "";
			data_file >> val;
			if (val != "") {
				if (val == "AVL_ID") {
					createAVL("ID", avl);
				} else if (val == "AVL_CAUSE") {
					createAVL("CAUSE", avl);
				} else if (val == "AVL_STATE") {
					createAVL("STATE", avl);
				} else if (val == "AVL_YEAR") {
					createAVL("YEAR", avl);
				} else if (val == "AVL_DEATHS") {
					createAVL("DEATHS", avl);
				} else if (val == "AVL_AGE") {
					cin >> val >> val >> val;
					createAVL("AGE-ADJUSTED DEATH RATE", avl);
				} else if (val == "B_ID") {
					int m;
					data_file >> m;
					createBTree("ID", m, btree);
				} else if (val == "B_CAUSE") {
					int m;
					data_file >> m;
					createBTree("CAUSE", m, btree);
				} else if (val == "B_STATE") {
					int m;
					data_file >> m;
					createBTree("STATE", m, btree);
				} else if (val == "B_YEAR") {
					int m;
					data_file >> m;
					createBTree("YEAR", m, btree);
				} else if (val == "B_DEATHS") {
					int m;
					data_file >> m;
					createBTree("DEATHS", m, btree);
				} else if (val == "B_AGE") {
					cin >> val >> val >> val;
					int m;
					data_file >> m;
					createBTree("AGE-ADJUSTED DEATH RATE", m, btree);
				} else if (val == "RNB_ID") {
					createRBTree("ID", rnbtree);
				} else if (val == "RNB_CAUSE") {
					createRBTree("CAUSE", rnbtree);
				} else if (val == "RNB_STATE") {
					createRBTree("STATE", rnbtree);
				} else if (val == "RNB_YEAR") {
					createRBTree("YEAR", rnbtree);
				} else if (val == "RNB_DEATHS") {
					createRBTree("DEATHS", rnbtree);
				} else if (val == "RNB_AGE") {
					cin >> val >> val >> val;
					createRBTree("AGE-ADJUSTED DEATH RATE", rnbtree);
				}
			}
		}
	}
}

int main() 
{
	/*
	string path = "datafiles/test2.csv";
	Queue<Entry>* q;
	q= readCSV(path);
	AVLTree<DataNode> avl;
	AVLTree<DataNode> avlname;
	BTree<DataNode> btree(4);
	avl.key = "ID";
	avlname.key = "STATE";
	btree.key = "ID";
	int len = q->Size();
	for (int i = 0; i < len; i++)
	{
		DataNode node;
		node.filepath = path;
		node.id = q->Front().getId();
		node.line = (i + 1);
		btree.insert(node);
		avl.insert(node);
		node.filepath = path;
		node.id = int_of_str(q->Front().state);
		node.line = (i + 1);
		avlname.insert(node);
		q->dequeue();
	}
	cout << endl << endl;
	// avl.LevelOrderTreversal(avl.root);
	cout << "Range Search: \n";
	//avl.getQueryrange("get <year,state,deaths> where # id=15-20");
	cout << "Single Search: \n";
	avl.getQuery("get <state> where # id=18");
	cout << "\nString Search: \n";
	avlname.getQuery("get <id> where # state=Indiana");


	//Testing for B-Tree
	cout << endl << "B-Tree: " << endl;
	btree.traverse();
	*/

	LinkedList<AVLTree<DataNode>>* avl_list = new LinkedList<AVLTree<DataNode>>;
	LinkedList<BTree<DataNode>>* btree_list = new LinkedList<BTree<DataNode>>;
	LinkedList<RedBlackTree<DataNode>>* rbtree_list = new LinkedList<RedBlackTree<DataNode>>;

	readLogs(avl_list, btree_list, rbtree_list);

	system("color 5F");

	Interface I(avl_list, btree_list, rbtree_list);

	I.MainInterface();
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "                                         *******************************************" << endl;
	cout << "                                         *                                         *" << endl;
	cout << "                                         *        THANK YOU FOR USING DSDB         *" << endl;
	cout << "                                         *                                         *" << endl;
	cout << "                                         *                GOODBYE!                 *" << endl;
	cout << "                                         *                                         *" << endl;
	cout << "                                         *******************************************" << endl;
	cout << endl;
	cout << endl;
	cout << endl;


	cout << "\n\nFOR DEBUG PURPOSES ONLY: " << endl;

	cout << "AVL" << endl;
	for (int i = 0; i < avl_list->Size(); i++) {
		avl_list->atIndex(i)->getValue().LevelOrderTreversal(avl_list->atIndex(i)->getValue().root);
	}

	cout << "BTREE" << endl;
	for (int i = 0; i < btree_list->Size(); i++) {
		btree_list->atIndex(i)->getValue().traverse();
	}

	cout << "RED BLACK" << endl;
	for (int i = 0; i < btree_list->Size(); i++) {
		btree_list->atIndex(i)->getValue().traverse();
	}

	cin.get();
	
	return 0;
}
