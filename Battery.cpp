#include "Battery.h"
#include <iostream>

Battery::Battery() : m_parameters("24V/15Ah"), m_externalPower("24V"),
m_chargingDuration("2H") {}

void Battery::setParameters(const std::string& p) {
	m_parameters = p;
}

void Battery::setExternalPower(const std::string& ep) {
	m_externalPower = ep;
}

void Battery::setChargingDuration(const std::string& cd) {
	m_chargingDuration = cd;
}

void Battery::print() const {
	std::cout << "电池参数: " << m_parameters << std::endl;
	std::cout << "外部电源: " << m_externalPower << std::endl;
	std::cout << "充电时长: " << m_chargingDuration << std::endl;
}

void Battery::save(std::ofstream& outFile) const {
	outFile << "电池参数: " << m_parameters << std::endl;
	outFile << "外部电源: " << m_externalPower << std::endl;
	outFile << "充电时长: " << m_chargingDuration << std::endl;
}

std::string Battery::getParameters() const {
	return m_parameters;
}

std::string Battery::getExternalPower() const {
	return m_externalPower;
}

std::string Battery::getChargingDuration() const {
	return m_chargingDuration;
}
