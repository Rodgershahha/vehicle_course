#pragma once
#include <string>
#include <iostream>
#include "Tire.h"
#include "ObstacleStatus.h"

class Lidar;
class Chassis {
public:
	Chassis();

	// Setters
	void setId(const std::string& i);
	void setModel(const std::string& m);
	void setWheelbase(const std::string& wb);
	void setTrack(const std::string& t);
	void setGroundClearance(const std::string& gc);
	void setTurningRadius(const std::string& tr);
	void setDriveType(const std::string& dt);
	void setMaxTravel(const std::string& mt);
	void setTireModel(const std::string& m);
	void setTireSize(const std::string& s);

	// Getters
	std::string getId() const;
	std::string getModel() const;
	std::string getWheelbase() const;
	std::string getTrack() const;
	std::string getGroundClearance() const;
	std::string getTurningRadius() const;
	std::string getDriveType() const;
	std::string getMaxTravel() const;
	std::string getTireModel() const;
	std::string getTireSize() const;

	void print() const;
	void save(std::ofstream& outFile) const;

	void attachLidar(Lidar* l);
	void onObstacleStatusChange(ObstacleStatus status);

private:
	std::string m_id;
	std::string m_model;
	std::string m_wheelbase;
	std::string m_track;
	std::string m_groundClearance;
	std::string m_turningRadius;
	std::string m_driveType;
	std::string m_maxTravel;
	Tire m_tires;
	Lidar* m_lidar;
};

