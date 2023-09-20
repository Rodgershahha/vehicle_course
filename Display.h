#pragma once
#include <string>
#include <fstream>

class Display {
public:
	Display();

	void setSize(const std::string& s);
	void setModel(const std::string& m);

	std::string getSize() const;
	std::string getModel() const;

	void print() const;
	void save(std::ofstream& outFile) const;

private:
	std::string m_size;
	std::string m_model;
};
