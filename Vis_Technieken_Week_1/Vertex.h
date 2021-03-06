#pragma once
#include <gtc/type_ptr.hpp>

class Vertex
{
public:
	glm::vec3 position;
	glm::vec4 color;
	Vertex(const glm::vec3 &position, const glm::vec4 &color) : position(position), color(color) {}
};
