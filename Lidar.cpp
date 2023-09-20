#include "Lidar.h"
#include "Chassis.h"
#include <iostream>

Lidar::Lidar() : m_model("RS-Helios-16p"), m_channels("16"),
m_range("100m"), m_powerConsumption("8W") {}

void Lidar::setModel(const std::string& m) {
	m_model = m;
}

void Lidar::setChannels(const std::string& c) {
	m_channels = c;
}

void Lidar::setRange(const std::string& r) {
	m_range = r;
}

void Lidar::setPowerConsumption(const std::string& pc) {
	m_powerConsumption = pc;
}

void Lidar::print() const {
	std::cout << "多线激光雷达型号: " << m_model << std::endl;
	std::cout << "通道数: " << m_channels << std::endl;
	std::cout << "测试范围: " << m_range << std::endl;
	std::cout << "功耗: " << m_powerConsumption << std::endl;
}

void Lidar::save(std::ofstream& outFile) const {
	outFile << "多线激光雷达型号: " << m_model << std::endl;
	outFile << "通道数: " << m_channels << std::endl;
	outFile << "测试范围: " << m_range << std::endl;
	outFile << "功耗: " << m_powerConsumption << std::endl;
}

void Lidar::subscribe(Chassis* chassis)
{
	m_subscribers.push_back(chassis);
}
void Lidar::updateObstacleStatus(ObstacleStatus status)
{
	m_obstacleStatus = status;
	notifySubscribers();
}

void Lidar::notifySubscribers()
{
	for (Chassis* subscriber : m_subscribers) {
		subscriber->onObstacleStatusChange(m_obstacleStatus);
	}
}

std::string Lidar::getModel() const {
	return m_model;
}

std::string Lidar::getChannels() const {
	return m_channels;
}

std::string Lidar::getRange() const {
	return m_range;
}

std::string Lidar::getPowerConsumption() const {
	return m_powerConsumption;
}