#include "Chassis.h"
#include "Lidar.h"
#include <iostream>
#include <fstream>

using namespace std;

Chassis::Chassis() {
	// Constructor implementation
}

void Chassis::setId(const std::string& i) {
	m_id = i;
}

void Chassis::setModel(const std::string& m) {
	m_model = m;
}

void Chassis::setWheelbase(const std::string& wb) {
	m_wheelbase = wb;
}

void Chassis::setTrack(const std::string& t) {
	m_track = t;
}

void Chassis::setGroundClearance(const std::string& gc) {
	m_groundClearance = gc;
}

void Chassis::setTurningRadius(const std::string& tr) {
	m_turningRadius = tr;
}

void Chassis::setDriveType(const std::string& dt) {
	m_driveType = dt;
}

void Chassis::setMaxTravel(const std::string& mt) {
	m_maxTravel = mt;
}

void Chassis::setTireModel(const std::string& m) {
	m_tires.setModel(m);
}

void Chassis::setTireSize(const std::string& s) {
	m_tires.setSize(s);
}

// Implement getters
std::string Chassis::getId() const {
	return m_id;
}

std::string Chassis::getModel() const {
	return m_model;
}

std::string Chassis::getWheelbase() const {
	return m_wheelbase;
}

std::string Chassis::getTrack() const {
	return m_track;
}

std::string Chassis::getGroundClearance() const {
	return m_groundClearance;
}

std::string Chassis::getTurningRadius() const {
	return m_turningRadius;
}

std::string Chassis::getDriveType() const {
	return m_driveType;
}

std::string Chassis::getMaxTravel() const {
	return m_maxTravel;
}

std::string Chassis::getTireModel() const {
	return m_tires.getModel();
}

std::string Chassis::getTireSize() const {
	return m_tires.getSize();
}

void Chassis::print() const {
	std::cout << "底盘编号: " << m_id << std::endl;
	std::cout << "底盘型号: " << m_model << std::endl;
	std::cout << "轴距: " << m_wheelbase << std::endl;
	std::cout << "轮距: " << m_track << std::endl;
	std::cout << "最小离地间隙: " << m_groundClearance << std::endl;
	std::cout << "最小转弯半径: " << m_turningRadius << std::endl;
	std::cout << "驱动形式: " << m_driveType << std::endl;
	std::cout << "最大行程: " << m_maxTravel << std::endl;
	std::cout << "轮胎信息:" << std::endl;
	m_tires.print();
}

void Chassis::save(std::ofstream& outFile) const {
	outFile << "底盘编号: " << m_id << std::endl;
	outFile << "底盘型号: " << m_model << std::endl;
	outFile << "轴距: " << m_wheelbase << std::endl;
	outFile << "轮距: " << m_track << std::endl;
	outFile << "最小离地间隙: " << m_groundClearance << std::endl;
	outFile << "最小转弯半径: " << m_turningRadius << std::endl;
	outFile << "驱动形式: " << m_driveType << std::endl;
	outFile << "最大行程: " << m_maxTravel << std::endl;
	outFile << "轮胎信息:" << std::endl;
	m_tires.save(outFile);
}

void Chassis::attachLidar(Lidar* l)
{
	m_lidar = l;
	m_lidar->subscribe(this);
}

void Chassis::onObstacleStatusChange(ObstacleStatus status)
{
	switch (status) {
	case OBSTACLE_FRONT:
		std::cout << getId() << ": 障碍物在前方，后退\n";
		break;
	case OBSTACLE_LEFT_FRONT:
		std::cout << getId() << ": 障碍物在左前方，右转\n";
		break;
	case OBSTACLE_RIGHT_FRONT:
		std::cout << getId() << ": 障碍物在右前方，左转\n";
		break;
	default:
		std::cout << getId() << ": 没有障碍物，继续前进\n";
		break;
	}
}
