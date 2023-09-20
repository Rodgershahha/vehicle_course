#pragma once
#include <string>
#include <fstream>

class Gyroscope {
public:
	Gyroscope();

	void setModel(const std::string& m);
	void setManufacturer(const std::string& mf);
	std::string getModel() const; 
	std::string getManufacturer() const; 
	void print() const;
	void save(std::ofstream& outFile) const;

private:
	std::string m_model;
	std::string m_manufacturer;
};
