#include "Display.h"
#include <iostream>

Display::Display() : m_size("11.6"), m_model("super") {}

void Display::setSize(const std::string& s) {
	m_size = s;
}

void Display::setModel(const std::string& m) {
	m_model = m;
}

void Display::print() const {
	std::cout << "Òº¾§ÏÔÊ¾ÆÁ³ß´ç: " << m_size << "Ó¢´ç" << std::endl;
	std::cout << "Òº¾§ÏÔÊ¾ÆÁÐÍºÅ: " << m_model << std::endl;
}

void Display::save(std::ofstream& outFile) const {
	outFile << "Òº¾§ÏÔÊ¾ÆÁ³ß´ç: " << m_size << "Ó¢´ç" << std::endl;
	outFile << "Òº¾§ÏÔÊ¾ÆÁÐÍºÅ: " << m_model << std::endl;
}

std::string Display::getSize() const {
	return m_size;
}

std::string Display::getModel() const {
	return m_model;
}
