#include "Camera.h"
#include <iostream>

Camera::Camera() : m_model("RealSense D435i"), m_cameraType("D430"),
m_resolution("1920x1080"), m_frameRate("30"),
m_fov("87.58"), m_depthFrameRate("90") {}

void Camera::setModel(const std::string& m) {
	m_model = m;
}

void Camera::setCameraType(const std::string& ct) {
	m_cameraType = ct;
}

void Camera::setResolution(const std::string& r) {
	m_resolution = r;
}

void Camera::setFrameRate(const std::string& fr) {
	m_frameRate = fr;
}

void Camera::setFOV(const std::string& f) {
	m_fov = f;
}

void Camera::setDepthFrameRate(const std::string& dfr) {
	m_depthFrameRate = dfr;
}

void Camera::print() const {
	std::cout << "双目摄像头型号: " << m_model << std::endl;
	std::cout << "摄像头类型: " << m_cameraType << std::endl;
	std::cout << "RGB帧分辨率: " << m_resolution << std::endl;
	std::cout << "RGB帧率: " << m_frameRate << std::endl;
	std::cout << "FOV: " << m_fov << std::endl;
	std::cout << "深度帧率: " << m_depthFrameRate << std::endl;
}

void Camera::save(std::ofstream& outFile) const {
	outFile << "双目摄像头型号: " << m_model << std::endl;
	outFile << "摄像头类型: " << m_cameraType << std::endl;
	outFile << "RGB帧分辨率: " << m_resolution << std::endl;
	outFile << "RGB帧率: " << m_frameRate << std::endl;
	outFile << "FOV: " << m_fov << std::endl;
	outFile << "深度帧率: " << m_depthFrameRate << std::endl;
}


std::string Camera::getModel() const {
	return m_model;
}

std::string Camera::getCameraType() const {
	return m_cameraType;
}

std::string Camera::getResolution() const {
	return m_resolution;
}

std::string Camera::getFrameRate() const {
	return m_frameRate;
}

std::string Camera::getFOV() const {
	return m_fov;
}

std::string Camera::getDepthFrameRate() const {
	return m_depthFrameRate;
}