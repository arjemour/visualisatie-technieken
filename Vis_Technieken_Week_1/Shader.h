#pragma once
#include <GL/glew.h>
#include <string>

class Shader
{
private:
	GLuint programId;
	const char* cfragShaderData;
	const char* cvertexShaderData;

	void checkShaderErrors(GLuint shaderId);

public:
	Shader(std::string vsFile, std::string fsFile);
	void Use();
	GLuint getProgramId() const { return programId; }
};
