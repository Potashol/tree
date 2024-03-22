#include <iostream>
using namespace std;

int tabs = 0;  //Для вывода дерева
int kol_vo = 0;

struct brach
{
	int Data;
	brach* left_brach;
	brach* right_brach;
};



void insert(int aData, brach*& abrach)
{
	if (!abrach)
	{
		abrach = new brach;
		abrach->Data = aData;
		abrach->left_brach = 0;
		abrach->right_brach = 0;
		return;
	}
	else
		if (abrach->Data > aData)
		{
			insert(aData, abrach->left_brach);
		}
		else
		{
			insert(aData, abrach->right_brach);
		};
}

void print(brach* abrach)
{
	if (!abrach) return;
	tabs += 5;
	print(abrach->left_brach);
	for (int i = 0; i < tabs; i++) cout << " ";
	cout << abrach->Data << endl;
	print(abrach->right_brach);
	tabs -= 5;
	return;
}

void pr_obh(brach*& abrach)
{
	int a;
	if (NULL == abrach)
		return;
	pr_obh(abrach->left_brach);
	a = abrach->Data;
	verni_a(a);
	pr_obh(abrach->right_brach);
	a = abrach->Data;
	verni_a(a);
}

int verni_a(int a)
{
	return a;
}

void insert_elem(int aData, brach*& abrach)
{
	if (!abrach)
	{
		abrach = new brach;
		abrach->Data = aData;
		abrach->left_brach = 0;
		abrach->right_brach = 0;
		return;
	}
	else
	{
		if (aData < abrach->Data) {
			insert_elem(aData, abrach->left_brach);
		}
		else if (aData > abrach->Data) {
			insert_elem(aData, abrach->right_brach);
		}
	}
}


void del_tree(brach* abrach)
{
	if (!abrach) return;
	del_tree(abrach->left_brach);
	del_tree(abrach->right_brach);
	delete abrach;
	return;
}

brach* del_elem(brach*& abrach, int aData) {
	if (abrach == NULL)
		return abrach;

	if (aData == abrach->Data) {

		brach* tmp;
		if (abrach->right_brach == NULL)
			tmp = abrach->left_brach;
		else {

			brach* ptr = abrach->right_brach;
			if (ptr->left_brach == NULL) {
				ptr->left_brach = abrach->left_brach;
				tmp = ptr;
			}
			else {

				brach* pmin = ptr->left_brach;
				while (pmin->left_brach != NULL) {
					ptr = pmin;
					pmin = ptr->left_brach;
				}
				ptr->left_brach = pmin->right_brach;
				pmin->left_brach = abrach->left_brach;
				pmin->right_brach = abrach->right_brach;
				tmp = pmin;
			}
		}

		delete abrach;
		return tmp;
	}
	else if (aData < abrach->Data)
		abrach->left_brach = del_elem(abrach->left_brach, aData);
	else
		abrach->right_brach = del_elem(abrach->right_brach, aData);
	return abrach;
}

int main()
{
	setlocale(LC_ALL, "rus");
	brach* Root = 0;
	int vel;
	int element;
	int k;

	cout << "Введите кол-во элементов для дерева: ";
	cin >> vel;
	cout << endl;
	int a;
	for (int i = 0; i < vel; i++)
	{
		cout << "введите элемент дерева" << endl;
		cin >> a;
		insert(a, Root);
	}
	print(Root);
	cout << endl;

	cout << "Прямой обход бинарного дерева: " << endl;
	pr_obh(Root);
	cout << endl;

	del_tree(Root);

}