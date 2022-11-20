//Вариант-18 ПР6 "Деревья"

// Вставить в дерево узлы со значениями вида 
// X / A, 2 * X / A, 3 * X / A, …, A* X / A, где X – среднее геометрическое элементов дерева,
// А – заданное пользователем значение.

#include <iostream>
#include <fstream>
#include <chrono>
#include <clocale>
#include <vector>    
#include <algorithm>  
#include <xtree>
#include <set>
#include <map>


using namespace std;
using namespace chrono;

enum color
{
    black = 0,
    red = 1
};

struct node {
    node* right, * left, *p;
    int info;
    color col;
};

void inorderTreeWalk(node* tree) // обход ЛКП
{
    if (tree != NULL)
    {    
        cout << "\n";
        inorderTreeWalk(tree->left);
        cout << "----" << tree->info << "\n";
        cout << '\t';
        inorderTreeWalk(tree->right);
        //cout << '\t';
    }
    cout << "\t";
}

void printTree(const string& prefix, const node* tree, bool isLeft)
{
    if (tree != nullptr)
    {
        cout << prefix;

       if (isLeft) { cout << "|--"; }
        else cout << "|__";

        cout << tree->info << '\n';


        if (isLeft) { printTree(prefix + "|   ", tree->left, true); } 
            else { printTree(prefix + "    ", tree->left, true); }

        if (isLeft) { printTree(prefix + "|   ", tree->right, false); }
            else { printTree(prefix + "    ", tree->right, false); }
    }
}

void printTree(const node* tree)
{
    printTree("", tree, false);
}

node* addNodeBinaryTree(node* tree, int a)
{
    if (tree == NULL) { 
        tree = new node; 
        tree->info = a;   
        tree->left = NULL;
        tree->right = NULL; 
    }
    else  
        if (a < tree->info) 
        { 
            tree->left = addNodeBinaryTree(tree->left, a); 
            tree->left->p = tree; 
        }
         else
         {
              tree->right = addNodeBinaryTree(tree->right, a); 
              tree->right->p = tree; 
         }
    return(tree);
}

node* createBinaryTree(ifstream &in)
{
    in.seekg(1);
    node* root = NULL;
    int a;
    while (!in.eof())
    {
        in >> a;
        root = addNodeBinaryTree(root, a);
    }
    return root;
}

float averageGeometric(int arr[], int N)
{
    float Multi = 1;
    for (int i = 0; i < N; i++)
        Multi *= arr[i];
    return sqrt(Multi);
}

int* fromTxtToArray(ifstream& in, int N)
{
    int i = 0;
    int* arr = new int[N];
    while (!in.eof())
    {
        in >> arr[i];
        i++;
    }
    return arr;
}

node* insertOwnElements(node* root, ifstream &in)
{
    in.seekg(0);
    int N;
    in >> N;
    int x = averageGeometric(fromTxtToArray(in,N), N);
    
    int a;
    cout << "\nВведите число для добавления элементов в дерево : ";
    cin >> a;
    cout << '\n';

    for (int i = 1; i <= a; i++)
    {
        root = addNodeBinaryTree(root, ((i * x) / a));
    }
    return root;
}

set<int> insertOwnElementsRBTree(set<int> root, ifstream& in)
{
    in.seekg(0);
    int N;
    in >> N;
    int x = averageGeometric(fromTxtToArray(in, N), N);

    int a;
    cout << "\nВведите число для добавления элементов в дерево : ";
    cin >> a;
    cout << '\n';

    for (int i = 1; i <= a; i++)
    {
        root.insert(((i * x) / a));
    }
    return root;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    ifstream in("tests/first.txt");
 
    node* tree = createBinaryTree(in);

    //inorderTreeWalk(tree);
    printTree(tree);

    tree = insertOwnElements(tree, in);
    
    //inorderTreeWalk(tree);
    printTree(tree);

    cout << endl;

    in.seekg(1);
    
    set<int> rBTree;
    
    int elem = 0;
    
    while (!in.eof())
    {
        in >> elem;
        rBTree.insert(elem);
    }
  
    rBTree = insertOwnElementsRBTree(rBTree, in);

    for (auto i: rBTree)
    {
        cout << i << ' ';
    }



    

 





}