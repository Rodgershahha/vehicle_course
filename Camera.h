#pragma once
#include <string>
#include <fstream>

class Camera {
public:
	Camera();

	void setModel(const std::string& m);
	void setCameraType(const std::string& ct);
	void setResolution(const std::string& r);
	void setFrameRate(const std::string& fr);
	void setFOV(const std::string& f);
	void setDepthFrameRate(const std::string& dfr);

	std::string getModel() const;
	std::string getCameraType() const;
	std::string getResolution() const;
	std::string getFrameRate() const;
	std::string getFOV() const;
	std::string getDepthFrameRate() const;

	void print() const;
	void save(std::ofstream& outFile) const;

private:
	std::string m_model;
	std::string m_cameraType;
	std::string m_resolution;
	std::string m_frameRate;
	std::string m_fov;
	std::string m_depthFrameRate;
};
