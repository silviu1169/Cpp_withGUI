#include "ProductRepository.h"



ProductRepository::ProductRepository()
{
}

bool ProductRepository::exist(const Product p) const{
	for (const auto& p1 : store) {
		if (p.getName() == p1.getName()) {
			return true;
		}
	}
	return false;
}

int ProductRepository::findPositionByName(const string n)const{
	int iterator{ -1 }, position{ -1 };

	//int dimensionStore = store.size();
	for (const auto& element : store) {
		iterator += 1;
		if (element.getName() == n) {
			position = iterator;
		}
	}
	if (position == -1)
		throw RepositoryExceptions("There is no product with the name: " + n);
	return position;
}

int ProductRepository::findPositionByType(const string t) const
{	int iterator{ -1 }, position{ -1 };

	//int dimensionStore = store.size();
	for (const auto& element : store) {
		iterator += 1;
		if (element.getType() == t) {
			position = iterator;
		}
	}
	if (position == -1)
		throw RepositoryExceptions("There is no product with the type: " + t);
	return position;
}

int ProductRepository::findPositionByProducer(const string p) const
{
	int iterator{ -1 }, position{ -1 };

	//int dimensionStore = store.size();
	for (const auto& element : store) {
		iterator += 1;
		if (element.getProducer() == p) {
			position = iterator;
		}
	}
	if (position == -1)
		throw RepositoryExceptions("There is no product with the producer: " + p);
	return position;
}

void ProductRepository::addRepo(const Product p){
	if (exist(p))
		throw RepositoryExceptions("The Product with name: " + p.getName() + " exist in store!\n");
	
	this->store.push_back(p);

}

void ProductRepository::modifyRepo(const Product p){
	if (!exist(p))
		throw RepositoryExceptions("This product is not in store!\n");
	for (auto& pr:store)
		if (p.getName() == pr.getName()) {
			pr.setName(p.getName());
			pr.setPrice(p.getPrice());
			pr.setType(p.getType());
			pr.setProducer(p.getProducer());
		}
}

void ProductRepository::deleteR(int iterator) {
	size_t dimensionStore = store.size();
	if (iterator != dimensionStore - 1) {
		for (iterator; iterator < dimensionStore - 1; iterator++)
			store[iterator] = store[iterator + 1];
		store.pop_back();

	}
	else {
		store.pop_back();
	}
}






 const vector<Product>& ProductRepository::getAllR() const noexcept{
	return this->store;
}

 const Product ProductRepository::findProductByPosition(int position)
 {
	 int iterator{ -1 };
	 for (const auto& element : store) {
		 iterator += 1;
		 if (iterator == position) {
			 return element;
		 }
	 }
	throw RepositoryExceptions("There is no product on position " + position);
	 
 }



ProductRepository::~ProductRepository()
{
}

ostream & operator<<(ostream & out, const RepositoryExceptions & ex){
	for (const auto& m : ex.mesage)
		out << m;
	return out;
}

void ProductRepositoryFile::loadfromfile() {
		std::ifstream in(fName);
		if (!in.is_open()) { //verify if the stream is opened		
			throw RepositoryExceptions("Unable to open file:" + fName);
		}
		while (!in.eof()) {
			string name;
			in >> name;
			int price;
			in >> price;
			string type;
			in >> type;
			string producer;
			in >> producer;

			if (in.eof()) {	//nu am reusit sa citesc numarul
				break;
			}
			Product p{name, price, type, producer };
			ProductRepository::addRepo(p);
		}
		in.close();
	}

	void ProductRepositoryFile::savetofile() {
		std::ofstream out(fName);
		if (!out.is_open()) { //verify if the stream is opened
			std::string msg("Unable to open file:");
			throw RepositoryExceptions(msg);
		}
		for (auto& p : ProductRepository::getAllR()) {
			out << p.getName();
			out << endl;
			out << p.getPrice();
			out << endl;
			out << p.getType();
			out << endl;
			out << p.getProducer();
			out << endl;
		}
		out.close();
	}

