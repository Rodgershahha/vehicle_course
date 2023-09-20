#include "AGXKit.h"
#include <iostream>

AGXKit::AGXKit() : m_model("AGX Xavier"), m_aiPerformance("32 TOPS"), m_cudaCores("512"),
m_tensorCores("64"), m_memory("32G"), m_storage("32G") {}

void AGXKit::setModel(const std::string& m) {
	m_model = m;
}

void AGXKit::setAIPerformance(const std::string& a) {
	m_aiPerformance = a;
}

void AGXKit::setCudaCores(const std::string& cc) {
	m_cudaCores = cc;
}

void AGXKit::setTensorCores(const std::string& tc) {
	m_tensorCores = tc;
}

void AGXKit::setMemory(const std::string& m) {
	m_memory = m;
}

void AGXKit::setStorage(const std::string& s) {
	m_storage = s;
}

void AGXKit::print() const {
	std::cout << "AGX套件型号: " << m_model << std::endl;
	std::cout << "AI性能: " << m_aiPerformance << std::endl;
	std::cout << "CUDA核心数: " << m_cudaCores << std::endl;
	std::cout << "Tensor CORE数: " << m_tensorCores << std::endl;
	std::cout << "显存: " << m_memory << std::endl;
	std::cout << "存储: " << m_storage << std::endl;
}

void AGXKit::save(std::ofstream& outFile) const {
	outFile << "AGX套件型号: " << m_model << std::endl;
	outFile << "AI性能: " << m_aiPerformance << std::endl;
	outFile << "CUDA核心数: " << m_cudaCores << std::endl;
	outFile << "Tensor CORE数: " << m_tensorCores << std::endl;
	outFile << "显存: " << m_memory << std::endl;
	outFile << "存储: " << m_storage << std::endl;
}

// 获取AGX套件型号
std::string AGXKit::getModel() const {
	return m_model;
}

// 获取AI性能
std::string AGXKit::getAIPerformance() const {
	return m_aiPerformance;
}

// 获取CUDA核心数
std::string AGXKit::getCudaCores() const {
	return m_cudaCores;
}

// 获取Tensor CORE数
std::string AGXKit::getTensorCores() const {
	return m_tensorCores;
}

// 获取显存
std::string AGXKit::getMemory() const {
	return m_memory;
}

// 获取存储
std::string AGXKit::getStorage() const {
	return m_storage;
}
