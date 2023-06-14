#pragma once

#include <iostream>
#include <fstream>
#include <streambuf>

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

namespace Warreign
{
	class Shader
	{
	protected:
		GLuint m_programID;

		struct AttributeLocations
		{
			GLint position;
			GLint color;
		} m_attributes;

		struct UniformLocations
		{
		} m_uniforms;

		static const std::string readShaderFromFile(const std::string& filename);

	public:
		Shader(const std::string& vertexShaderFilename, const std::string& fragmentShaderFilename);

		~Shader();

	public:
		void bind() const;
		void unbind() const;

	public:
		GLint attributeLocation(const std::string& name);
		GLint uniformLocation(const std::string& name);

	public:
		void setInteger1(GLint uniform, int value);

		void setFloat1(GLint uniform, float value);
		void setFloat2(GLint uniform, const glm::vec2& value);
		void setFloat3(GLint uniform, const glm::vec3& value);
		void setFloat4(GLint uniform, const glm::vec4& value);

		void setMatrix3(GLint uniform, const glm::mat3& value);
		void setMatrix4(GLint uniform, const glm::mat4 value);
	};

}