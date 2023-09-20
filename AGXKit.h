#pragma once
#include <string>
#include <fstream>

class AGXKit {
public:
	AGXKit();

	// 获取AGX套件型号
	std::string getModel() const;

	// 获取AI性能
	std::string getAIPerformance() const;

	// 获取CUDA核心数
	std::string getCudaCores() const;

	// 获取Tensor CORE数
	std::string getTensorCores() const;

	// 获取显存
	std::string getMemory() const;

	// 获取存储
	std::string getStorage() const;

	void setModel(const std::string& m);
	void setAIPerformance(const std::string& a);
	void setCudaCores(const std::string& cc);
	void setTensorCores(const std::string& tc);
	void setMemory(const std::string& m);
	void setStorage(const std::string& s);

	void print() const;
	void save(std::ofstream& outFile) const;

private:
	std::string m_model;
	std::string m_aiPerformance;
	std::string m_cudaCores;
	std::string m_tensorCores;
	std::string m_memory;
	std::string m_storage;
};
