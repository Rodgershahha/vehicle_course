#pragma once
#include <string>
#include <fstream>

class Student {
public:
	Student();

	void setName(const std::string& name);
	void setStudentID(const std::string& studentID);

	std::string getName() const;
	std::string getStudentID() const;

	void print() const;
	void save(std::ofstream& outFile) const;

private:
	std::string m_name;
	std::string m_studentID;
};
