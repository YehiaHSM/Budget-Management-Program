#include<iostream>
using namespace std;
#define slots 50

struct income {
	char Iname[25];
	int Iamount = { 0 };
};

struct expenses {
	char Ename[25];
	int Eamount = { 0 };
};

struct recurring {
	char Rname[25];
	int Ramount = { 0 };
};

int main() {
	int I = 0, E = 0, R = 0, totalE = 0, totalR = 0, totalI = 0, total = 0;
	char Eflag, Iflag, Rflag, Iedit, Eedit, Redit;
	int z;

	expenses exp[slots];
	income inc[slots];
	recurring rec[slots];

	do {
		cout << "Enter Income Name : ";
		cin >> inc[I].Iname;
		cout << "Enter Income Amount in $ : ";
		cin >> inc[I].Iamount;
		I++;
		cout << "Do You Want To Add More Incomes (y|n) : ";
		cin >> Iflag;
	} while (Iflag=='y');

	do {
		cout << "Enter expense Name : ";
		cin >> exp[E].Ename;
		cout << "Enter expense Amount in $ : ";
		cin >> exp[E].Eamount;
		E++;
		cout << "Do You Want To Add More expense (y|n) : ";
		cin >> Eflag;
	} while (Eflag == 'y');
	
	do{
		cout << "Enter Recurring cost Name : ";
		cin >> rec[R].Rname;
		cout << "Enter Recurring cost Amount in $ : ";
		cin >> rec[R].Ramount;
		R++;
		cout << "Do You Want To Add More Recurring cost (y|n) : ";
		cin >> Rflag;
	}while (Rflag == 'y');

	cout << "income : " << endl;
	int cI = 1;
	for (int i = 0; i < I; i++) {
		cout << cI <<"- "<< inc[i].Iname << " : " << inc[i].Iamount << endl;
		cI++;
	}

	do{
		cout << "Do you want to edit a value (e),delete a value (d),leave in as it is (n) : ";
		cin >> Iedit;
		if (Iedit == 'n') {
			for (int i = 0; i < I; i++)
				totalI += inc[i].Iamount;
			break;
		}
		switch (Iedit) {
		case 'e':
			cout << "Choose the value you want to edit : ";
			cin >> z;
			z -= 1;
			cout << "Enter the new name : ";
			cin >> inc[z].Iname;
			cout << "Enter the new amount : ";
			cin >> inc[z].Iamount;
			break;
		case'd':
			cout << "Choose the value you want to edit : ";
			cin >> z;
			z -= 1;
			for (int i=z; i <= I; i++) {
				inc[i]=inc[i+1];
			}
			I--;
			break;
		}

		cout << "Income : " << endl;
		int cI = 1;
		for (int i = 0; i < I; i++) {
			cout << cI << "- " << inc[i].Iname << " : " << inc[i].Iamount << endl;
			cI++;
			totalI += inc[i].Iamount;
		}

		cout << "Do you want to edit or delete any more values (y|n) : ";
		cin >> Iflag;
	}while (Iflag == 'y');

	cout << "Expenses : " << endl;
	int cE = 1;
	for (int i = 0; i < E; i++) {
		cout << cE<<"- " << exp[i].Ename << " : " << exp[i].Eamount << endl;
		cE++;
	}

	do {
		cout << "Do you want to edit a value (e),delete a value (d),leave in as it is (n) : ";
		cin >> Eedit;
		if (Eedit == 'n') {
			for (int i = 0; i < E; i++)
				totalE += exp[i].Eamount;
			break;
		}
		switch (Eedit) {
		case 'e':
			cout << "Choose the value you want to edit : ";
			cin >> z;
			z -= 1;
			cout << "Enter the new name : ";
			cin >> exp[z].Ename;
			cout << "Enter the new amount : ";
			cin >> exp[z].Eamount;
			break;
		case'd':
			cout << "Choose the value you want to edit : ";
			cin >> z;
			z -= 1;
			for (int i = z; i <= I; i++) {
				exp[i] = exp[i + 1];
			}
			E--;
			break;
		}


		cout << "Expenses : " << endl;
		int cE = 1;
		for (int i = 0; i < R; i++) {
			cout << cE << "- " << exp[i].Ename << " : " << exp[i].Eamount << endl;
			cE++;
			totalE += exp[i].Eamount;
		}
		cout << "Do you want to edit or delete any more values (y|n) : ";
		cin >> Eflag;
	} while (Eflag == 'y');

	cout << "Recurring costs : " << endl;
	int cR = 1;
	for (int i = 0; i < R; i++) {
		cout << cR<< "- " << rec[i].Rname << " : " << rec[i].Ramount << endl;
		cR++;
	}

	do {
		cout << "Do you want to edit a value (e),delete a value (d),leave in as it is (n) : ";
		cin >> Redit;
		if (Redit == 'n') {
			for (int i = 0; i < R; i++)
			totalR += rec[i].Ramount;
			break;
		}
		switch (Redit) {
		case 'e':
			cout << "Choose the value you want to edit : ";
			cin >> z;
			z -= 1;
			cout << "Enter the new name : ";
			cin >> rec[z].Rname;
			cout << "Enter the new amount : ";
			cin >> rec[z].Ramount;
			break;
		case'd':
			cout << "Choose the value you want to edit : ";
			cin >> z;
			z -= 1;
			for (int i = z; i <= R; i++) {
				rec[i] = rec[i + 1];
			}
			R--;
			break;
		}

		cout << "Recurring costs : " << endl;
		int cR = 1;
		for (int i = 0; i < R; i++) {
			cout << cR << "- " << rec[i].Rname << " : " << rec[i].Ramount << endl;
			cR++;
			totalR += rec[i].Ramount;
		}

		cout << "Do you want to edit or delete any more values (y|n) : ";
		cin >> Iflag;
	} while (Iflag == 'y');

	total = totalI - totalE - totalR;
	cout << "Your net total is : " << total << endl;
	if (total < 0) {
		cout << "You must decrase your Expences and recurring cost or increase your income." << endl;
	}
	cout << "your total income is : " << totalI << endl;
	cout << "your total Expenses is : " << totalE << endl;
	cout << "your total Recurring cost is : " << totalR << endl;
	cout << "Your net total is : " << total << endl;
	system("pause");
	return 0;
}
