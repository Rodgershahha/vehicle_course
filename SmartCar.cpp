#include "SmartCar.h"
#include <iostream>

SmartCar::SmartCar() : m_id(""), m_chassis(Chassis()), m_agxKit(AGXKit()),
m_camera(Camera()), m_lidar(Lidar()),
m_gyroscope(Gyroscope()), m_display(Display()),
m_battery(Battery()), m_studentInfo(Student()) {}

void SmartCar::setId(const std::string& carID)
{
	m_id = carID;
}

void SmartCar::setChassis(const Chassis& chassis) {
	m_chassis = chassis;
}

void SmartCar::setAGXKit(const AGXKit& agxKit) {
	m_agxKit = agxKit;
}

void SmartCar::setCamera(const Camera& camera) {
	m_camera = camera;
}

void SmartCar::setLidar(const Lidar& lidar) {
	m_lidar = lidar;
}

void SmartCar::setGyroscope(const Gyroscope& gyroscope) {
	m_gyroscope = gyroscope;
}

void SmartCar::setDisplay(const Display& display) {
	m_display = display;
}

void SmartCar::setBattery(const Battery& battery) {
	m_battery = battery;
}

void SmartCar::setStudentInfo(const Student& studentInfo) {
	m_studentInfo = studentInfo;
}

void SmartCar::print() const {
	std::cout << "智能小车编号: " << m_id << std::endl;
	m_chassis.print();
	m_agxKit.print();
	m_camera.print();
	m_lidar.print();
	m_gyroscope.print();
	m_display.print();
	m_battery.print();
	m_studentInfo.print();
}

void SmartCar::save(std::ofstream& outFile) const {
	outFile << "智能小车编号: " << m_id << std::endl;
	m_chassis.save(outFile);
	m_agxKit.save(outFile);
	m_camera.save(outFile);
	m_lidar.save(outFile);
	m_gyroscope.save(outFile);
	m_display.save(outFile);
	m_battery.save(outFile);
	m_studentInfo.save(outFile);
}

std::string SmartCar::getId() const {
	return m_id;
}

Chassis SmartCar::getChassis() const {
	return m_chassis;
}

AGXKit SmartCar::getAGXKit() const {
	return m_agxKit;
}

Camera SmartCar::getCamera() const {
	return m_camera;
}

Lidar SmartCar::getLidar() const {
	return m_lidar;
}

Gyroscope SmartCar::getGyroscope() const {
	return m_gyroscope;
}

Display SmartCar::getDisplay() const {
	return m_display;
}

Battery SmartCar::getBattery() const {
	return m_battery;
}

Student SmartCar::getStudentInfo() const {
	return m_studentInfo;
}
