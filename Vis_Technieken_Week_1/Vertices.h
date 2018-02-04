#pragma once
#include <detail/type_vec4.hpp>
#include "Vertex.h"

Vertex vertices[] = {
	//face 1
	Vertex(glm::vec3(-1.0f,-1.0f,-1.0f), glm::vec4(0.5, 1, 1,1)),
	Vertex(glm::vec3(-1.0f,-1.0f, 1.0f), glm::vec4(0.5, 1, 1,1)),
	Vertex(glm::vec3(-1.0f, 1.0f, 1.0f), glm::vec4(0.5, 1, 1,1)),

	Vertex(glm::vec3(-1.0f,-1.0f,-1.0f), glm::vec4(0.5, 1, 1,1)),
	Vertex(glm::vec3(-1.0f, 1.0f, 1.0f), glm::vec4(0.5, 1, 1,1)),
	Vertex(glm::vec3(-1.0f, 1.0f,-1.0f), glm::vec4(0.5, 1, 1,1)),

	//face 2
	Vertex(glm::vec3(1.0f, 1.0f,-1.0f), glm::vec4(1, 0.5, 1,1)),
	Vertex(glm::vec3(-1.0f,-1.0f,-1.0f), glm::vec4(1, 0.5, 1,1)),
	Vertex(glm::vec3(-1.0f, 1.0f,-1.0f), glm::vec4(1, 0.5, 1,1)),

	Vertex(glm::vec3(1.0f, 1.0f,-1.0f), glm::vec4(1, 0.5, 1,1)),
	Vertex(glm::vec3(1.0f,-1.0f,-1.0f), glm::vec4(1, 0.5, 1,1)),
	Vertex(glm::vec3(-1.0f,-1.0f,-1.0f), glm::vec4(1, 0.5, 1,1)),

	//face 3
	Vertex(glm::vec3(1.0f,-1.0f, 1.0f), glm::vec4(1, 1, 0.5,1)),
	Vertex(glm::vec3(-1.0f,-1.0f,-1.0f), glm::vec4(1, 1, 0.5,1)),
	Vertex(glm::vec3(1.0f,-1.0f,-1.0f), glm::vec4(1, 1, 0.5,1)),

	Vertex(glm::vec3(1.0f,-1.0f, 1.0f), glm::vec4(1, 1, 0.5,1)),
	Vertex(glm::vec3(-1.0f,-1.0f, 1.0f), glm::vec4(1, 1, 0.5,1)),
	Vertex(glm::vec3(-1.0f,-1.0f,-1.0f), glm::vec4(1, 1, 0.5,1)),

	//face 4

	Vertex(glm::vec3(-1.0f, 1.0f, 1.0f), glm::vec4(0.5, 0.5, 1,1)),
	Vertex(glm::vec3(-1.0f,-1.0f, 1.0f), glm::vec4(0.5, 0.5, 1,1)),
	Vertex(glm::vec3(1.0f,-1.0f, 1.0f), glm::vec4(0.5, 0.5, 1,1)),

	Vertex(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec4(0.5, 0.5, 1,1)),
	Vertex(glm::vec3(-1.0f, 1.0f, 1.0f), glm::vec4(0.5, 0.5, 1,1)),
	Vertex(glm::vec3(1.0f,-1.0f, 1.0f), glm::vec4(0.5, 0.5, 1,1)),

	//face 5

	Vertex(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec4(1, 0.5, 0.5,1)),
	Vertex(glm::vec3(1.0f,-1.0f,-1.0f), glm::vec4(1, 0.5, 0.5,1)),
	Vertex(glm::vec3(1.0f, 1.0f,-1.0f), glm::vec4(1, 0.5, 0.5,1)),

	Vertex(glm::vec3(1.0f,-1.0f,-1.0f), glm::vec4(1, 0.5, 0.5,1)),
	Vertex(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec4(1, 0.5, 0.5,1)),
	Vertex(glm::vec3(1.0f,-1.0f, 1.0f), glm::vec4(1, 0.5, 0.5,1)),

	//face 6
	Vertex(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec4(0.5, 0.5, 0.5,1)),
	Vertex(glm::vec3(1.0f, 1.0f,-1.0f), glm::vec4(0.5, 0.5, 0.5,1)),
	Vertex(glm::vec3(-1.0f, 1.0f,-1.0f), glm::vec4(0.5, 0.5, 0.5,1)),

	Vertex(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec4(0.5, 0.5, 0.5,1)),
	Vertex(glm::vec3(-1.0f, 1.0f,-1.0f), glm::vec4(0.5, 0.5, 0.5,1)),
	Vertex(glm::vec3(-1.0f, 1.0f, 1.0f), glm::vec4(0.5, 0.5, 0.5,1))
};
