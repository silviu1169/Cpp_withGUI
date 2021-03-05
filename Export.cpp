#include "Export.h"

void exportToCSV(string fileName,const vector<Product>& all){
	ofstream out(fileName, ios::trunc);
	if (!out.is_open()) {
		throw RepositoryExceptions("Cannot open the file " + fileName);
	}

	for (const auto& product : all) {
		out<< product.getName() << "," << product.getPrice() << "," << product.getType() << "," << product.getProducer() << endl;
	}
	out.close();
}

void exportToHTLM(string fileName, const vector<Product>& all){
	ofstream out(fileName);
	if (!out.is_open()) {
		throw RepositoryExceptions("Cannot create the file with the name: " + fileName);
	}
	out << "<html><body>" << endl;
	out << "<table border=\"1\" style=\"width:100 % \">" << endl;
	for (const auto& product : all) {
		out << "<tr>" << endl;
		out << "<td>" << product.getName() << "</td>" << endl;
		out << "<td>" << product.getPrice() << "</td>" << endl;
		out << "<td>" << product.getType() << "</td>" << endl;
		out << "<td>" << product.getProducer() << "</td>" << endl;
		out << "</tr>" << endl;
	}
	out << "</table>" << endl;
	out << "</body></html>" << endl;
	out.close();
}
