#pragma once
#include <string>
#include "Chassis.h"
#include "AGXKit.h"
#include "Camera.h"
#include "Lidar.h"
#include "Gyroscope.h"
#include "Display.h"
#include "Battery.h"
#include "Student.h"

class SmartCar {
public:
	SmartCar();

	void setId(const std::string& carID);
	void setChassis(const Chassis& c);
	void setAGXKit(const AGXKit& a);
	void setCamera(const Camera& c);
	void setLidar(const Lidar& l);
	void setGyroscope(const Gyroscope& g);
	void setDisplay(const Display& d);
	void setBattery(const Battery& b);
	void setStudentInfo(const Student& si);

	std::string getId() const;
	Chassis getChassis() const;
	AGXKit getAGXKit() const;
	Camera getCamera() const;
	Lidar getLidar() const;
	Gyroscope getGyroscope() const;
	Display getDisplay() const;
	Battery getBattery() const;
	Student getStudentInfo() const;

	void print() const;
	void save(std::ofstream& outFile) const;
	
private:
	std::string m_id;
	Chassis m_chassis;
	AGXKit m_agxKit;
	Camera m_camera;
	Lidar m_lidar;
	Gyroscope m_gyroscope;
	Display m_display;
	Battery m_battery;
	Student m_studentInfo;
};