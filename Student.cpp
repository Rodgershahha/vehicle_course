#include "Student.h"
#include <iostream>

Student::Student() : m_name(""), m_studentID(""){}

void Student::setName(const std::string& name) {
	m_name = name;
}

void Student::setStudentID(const std::string& studentID) {
	m_studentID = studentID;
}

void Student::print() const {
	std::cout << "学生姓名: " << m_name << std::endl;
	std::cout << "学号: " << m_studentID << std::endl;
}

void Student::save(std::ofstream& outFile) const {
	outFile << "学生姓名: " << m_name << std::endl;
	outFile << "学号: " << m_studentID << std::endl;
}

std::string Student::getName() const {
	return m_name;
}

std::string Student::getStudentID() const {
	return m_studentID;
}
