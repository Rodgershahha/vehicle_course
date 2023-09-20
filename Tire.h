#pragma once
#include <string>

class Tire {
public:
	Tire();

	void setModel(const std::string& m);
	void setSize(const std::string& s);
	std::string getModel() const; // Getter 方法
	std::string getSize() const;  // Getter 方法
	void print() const;
	void save(std::ofstream& outFile) const;

private:
	std::string m_model;
	std::string m_size;
};
