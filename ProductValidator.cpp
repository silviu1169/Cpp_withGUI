#include "ProductValidator.h"



void ProductValidator::validation(const Product& p){

	vector <string> msg;
	if (p.getName().size() <= 0) msg.push_back("Incorrect Name! ");
	if (p.getPrice() <= 0) msg.push_back("Incorrect Price! ");
	if (p.getType().size() <= 0) msg.push_back("Incorrect Type! ");
	if (p.getProducer().size() <= 0) msg.push_back("Incorrect Producer! ");
	if (msg.size() > 0) {
		msg.push_back("\n");
		throw ValidationExceptions(msg);
	}
}

ostream& operator<<(ostream& out, const ValidationExceptions& ex) {
	for (const auto& msg : ex.mesage) {
		out << msg << " ";
	}
	return out;
}
