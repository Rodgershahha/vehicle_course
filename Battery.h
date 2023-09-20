#pragma once
#include <string>
#include <fstream>

class Battery {
public:
	Battery();

	void setParameters(const std::string& p);
	void setExternalPower(const std::string& ep);
	void setChargingDuration(const std::string& cd);

	std::string getParameters() const; // 添加获取参数的getter
	std::string getExternalPower() const; // 添加获取外部电源的getter
	std::string getChargingDuration() const; // 添加获取充电时长的getter

	void print() const;
	void save(std::ofstream& outFile) const;

private:
	std::string m_parameters;
	std::string m_externalPower;
	std::string m_chargingDuration;
};
