#ifndef SHADER_HPP
#define SHADER_HPP

#include "glessential.hpp"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader {
private:
	// the program ID
	unsigned int ID;

public:
	// constructor reads and builds the shader
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath) {
		// 1. retrieve the vertex/fragment source code from filePath
		std::string vertexCode;
		std::string fragmentCode;
		std::ifstream vShaderFile;
		std::ifstream fShaderFile;

		vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

		try {
			vShaderFile.open(vertexPath);
			fShaderFile.open(fragmentPath);

			std::stringstream vShaderStream, fShaderStream;

			vShaderStream << vShaderFile.rdbuf();
			fShaderStream << fShaderFile.rdbuf();

			vShaderFile.close();
			fShaderFile.close();

			vertexCode = vShaderStream.str();
			fragmentCode = fShaderStream.str();
		}
		catch (std::ifstream::failure e) {
			std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
		}
		const char* vShaderCode = vertexCode.c_str();
		const char* fShaderCode = fragmentCode.c_str();

		// 2. compile shaders
		unsigned int vertex, fragment;
		int success;
		char infoLog[512];

		GLCall(vertex = glCreateShader(GL_VERTEX_SHADER));
		GLCall(glShaderSource(vertex, 1, &vShaderCode, NULL));
		GLCall(glCompileShader(vertex));

		GLCall(glGetShaderiv(vertex, GL_COMPILE_STATUS, &success));
		if (!success) {
			GLCall(glGetShaderInfoLog(vertex, 512, NULL, infoLog));
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
			std::cout << "code starts" << std::endl;
			std::cout << vShaderCode << std::endl;
			std::cout << "code ends" << std::endl;
		}

		GLCall(fragment = glCreateShader(GL_FRAGMENT_SHADER));
		GLCall(glShaderSource(fragment, 1, &fShaderCode, NULL));
		GLCall(glCompileShader(fragment));

		GLCall(glGetShaderiv(fragment, GL_COMPILE_STATUS, &success));
		if (!success) {
			GLCall(glGetShaderInfoLog(fragment, 512, NULL, infoLog));
			std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
			std::cout << "code starts" << std::endl;
			std::cout << fShaderCode;
			std::cout << "code ends" << std::endl;
		}

		GLCall(ID = glCreateProgram());
		GLCall(glAttachShader(ID, vertex));
		GLCall(glAttachShader(ID, fragment));
		GLCall(glLinkProgram(ID));

		GLCall(glGetProgramiv(ID, GL_LINK_STATUS, &success));
		if (!success) {
			GLCall(glGetProgramInfoLog(ID, 512, NULL, infoLog));
			std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		}

		GLCall(glDeleteShader(vertex));
		GLCall(glDeleteShader(fragment));
	}
	// use/activate the shader
	void use() {
		GLCall(glUseProgram(ID));
	}
	// returns ID of the shader
	unsigned int getID() {
		return ID;
	}
	// utility uniform functions
	void setMat3(const std::string& name, float* value) const {
		GLCall(glUniformMatrix3fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, value));
	}
	void setMat4(const std::string& name, float* value) const {
		GLCall(glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, value));
	}
	void setInt(const std::string& name, int value) const {
		GLCall(glUniform1i(glGetUniformLocation(ID, name.c_str()), value));
	}
	void setFloat(const std::string& name, float value) const {
		GLCall(glUniform1f(glGetUniformLocation(ID, name.c_str()), value));
	}
};

#endif //!SHADER_HPP