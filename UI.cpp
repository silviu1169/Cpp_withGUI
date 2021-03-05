#include "UI.h"
#include <string>
#include "ProductStore.h"

int UI::readInt()
{
	int variable;
	int i{ 0 };
	while (i == 0) {
		cin >> variable;
		if (!cin) {
			cout << "Not an integer value! Give me another one:";
			cin.clear();
			cin.ignore(256, '\n');
		}
		else {
			i = 1;
		}

	}
	return variable;
}

string UI::readStr(string msg){
	string str;
	cout << endl << msg;
	cin >> str;
	cout << endl;
	return str;
}



void UI::uiAdd(){
	string name;
	int price;
	string type, producer;
	cout << "Name:";
	cin >> name;

	cout << "Price:"; 
	price = readInt();
	

	cout << "Type:"; 
	cin >> type;
	
	cout << "Producer:"; 
	cin >> producer;
	st.addProduct(name, price, type, producer);
	cout << "Product added with succes!\n";


}

void UI::uiPrint(const vector <Product>& store1){
	
	for (const auto& p:store1) {
		cout << p.getName() << ' ' << p.getPrice() << ' '  << p.getType() << ' ' << p.getProducer() << '\n';
	}

	cout << " Printed with succes\n";

}

void UI::uiModify(){
	string name, type, producer;
	cout << "Product name to be modified:";
	cin >> name;
	cout << "New information: \n";
	cout << "New Price:";
	int price = readInt();

	cout << "New Type:";
	cin >> type;
	cout << "New Producer:";
	cin >> producer;
	st.modifyProduct(name, price, type, producer);
	cout << "The Product has been modified succesfully!\n";



}

void UI::uiDelete(){
	string name;
	cout << "Product name to be deleted: ";
	cin >> name;
	st.deleteProduct(name);// to do the rest. from ui to backend

	cout << "The product has beed deleted succesfully!\n";

}

void UI::uiSearch(){
	cout << "For what to search:" << '\n';
	cout << " 1-Name\n 2-Type\n 3-Producer";
	int cmd1 = readInt();
	if (cmd1 == 1) {
		cout << "Give the name you are searching for it:";
		string name;
		cin >> name;
		Product p = st.searchByName(name);
		cout << p.getName() << ' ' << p.getPrice() << ' ' << p.getType() << ' ' << p.getProducer() << '\n';
	}
	if (cmd1 == 2) {
		cout << "Give the type you are searching for it:";
		string type;
		cin >> type;
		Product p = st.searchByType(type);
		cout << p.getName() << ' ' << p.getPrice() << ' ' << p.getType() << ' ' << p.getProducer() << '\n';
	}
	if (cmd1 == 3) {
		cout << "Give the producer you are searching for it:";
		string producer;
		cin >> producer;
		Product p = st.searchByProducer(producer);
		cout << p.getName() << ' ' << p.getPrice() << ' ' << p.getType() << ' ' << p.getProducer() << '\n';
	}

}

void UI::uiSort(){
	int choice{ 0 };
	cout << "1-Sort by name\n2-Sort by price\n3-Sort by name+type\n";
	choice = readInt();
	vector <Product> all = st.sorting(choice);
	uiPrint(all);

}

void UI::uiFilter(){

	cout << "1-Sort by name\n2-Sort by price\n3-Sort by producer\n";
	int choice = readInt();
	if (choice == 1) {
		string name;
		cout << "name:"; cin >> name;
		uiPrint(st.filterName(name));

	}
	else if (choice == 2) {
		cout << "More than price:" << endl;
		int price = readInt();
		uiPrint(st.filterPrice(price));
	}
	else if (choice == 3) {
		string producer;
		cout << "producer:"; cin >> producer;
		uiPrint(st.filterProducer(producer));
		
	}
	else {
		cout << "Wrong value.\n";
	}


}

void UI::uiUndo() {
	st.storeUndo();
}

void UI::start() {

	while (true) {
		cout << "Menu:\n";
		cout << "   0 - exit\n   1 - add Product\n   2 - print Products\n   3 - modify Product\n   4 - delete Product\n   5 - search\n   6 - sort\n   7 - filter\n   8 - undo\n";
		cout << "   9 - addProductToCart\n   10 - randomCart\n   11 - clearCart\n   12 - printCart\n   13 - exportToCSV\n   14 - exportToHTML\n";
		//try catch pe value error


		int cmd = readInt();
		

		try {
			switch (cmd) {
			case 0:
				return;
			case 1:
				uiAdd();
				break;
			case 2:
				uiPrint(st.getAll());
				break;
			case 3:
				uiModify();
				break;
			case 4:
				uiDelete();
				break;
			case 5:
				uiSearch();
				break;
			case 6:
				uiSort();
				break;

			case 7:
				uiFilter();
				break;
			case 8:
				uiUndo();
				break;
			case 9:
				uiPrint(st.addToCartS(readStr("Give the name of product you want to add in cart:")));
				break;
			case 10:
				cout << "Give me the number of product you want to add in cart:";
				uiPrint(st.fillRandom(readInt()));
				break;
			
			case 11:
				uiPrint(st.clearCartS());
				break;
			
			case 12:
				uiPrint(st.getAllfromCart());
				break;
			case 13:
				exportToCSV(readStr("Give me the name of file:"), st.getAll());
				break;
			case 14:
				exportToHTLM(readStr("Give me the name of the file: "), st.getAll());
				break;
			default:
				cout << "Invalid Command\n";
			}
		cout << '\n';
		}
		catch (ValidationExceptions& ve) {
			cout << ve << '\n';
		}
		catch (RepositoryExceptions& re) {
			cout << re << '\n';
		}

	
	}

}




