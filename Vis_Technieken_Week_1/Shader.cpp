#include "Shader.h"
#include <string>
#include <iostream>
#include <fstream>

Shader::Shader(std::string vsFile, std::string fsFile)
{
	std::ifstream vertexShaderFile(vsFile);
	std::string vertexShaderData((std::istreambuf_iterator<char>(vertexShaderFile)), std::istreambuf_iterator<char>());
	cvertexShaderData = vertexShaderData.c_str();

	std::ifstream fragShaderFile(fsFile);
	std::string fragShaderData((std::istreambuf_iterator<char>(fragShaderFile)), std::istreambuf_iterator<char>());
	cfragShaderData = fragShaderData.c_str();

	programId = glCreateProgram();							// maak een shaderprogramma aan

	GLuint vertexId = glCreateShader(GL_VERTEX_SHADER);		// maak vertex shader aan
	glShaderSource(vertexId, 1, &cvertexShaderData, NULL);		// laat opengl de shader uit de variabele 'vertexShader' halen
	glCompileShader(vertexId);								// compileer de shader
	checkShaderErrors(vertexId);							// controleer of er fouten zijn opgetreden bij het compileren
	glAttachShader(programId, vertexId);					// hang de shader aan het shaderprogramma

	GLuint fragmentId = glCreateShader(GL_FRAGMENT_SHADER);	// maak fragment shader aan
	glShaderSource(fragmentId, 1, &cfragShaderData, NULL);	// laat opengl de shader uit de variabele 'fragmentShader' halen
	glCompileShader(fragmentId);							// compileer de shader
	checkShaderErrors(fragmentId);							// controleer of er fouten zijn opgetreden bij het compileren
	glAttachShader(programId, fragmentId);					// hang de shader aan het shaderprogramma
	glLinkProgram(programId);								// link het programma, zorg dat alle attributes en varying gelinked zijn
}

void Shader::Use()
{
	glUseProgram(programId);								// Zet dit als actieve programma
}

void Shader::checkShaderErrors(GLuint shaderId)
{
	GLint status;
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &status);					//kijk of het compileren is gelukt
	if (status == GL_FALSE)
	{
		int length, charsWritten;
		glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &length);				//haal de lengte van de foutmelding op
		char* infolog = new char[length + 1];
		memset(infolog, 0, length + 1);
		glGetShaderInfoLog(shaderId, length, &charsWritten, infolog);		//en haal de foutmelding zelf op
		std::cout << "Error compiling shader:\n" << infolog << std::endl;
		delete[] infolog;
	}
}

