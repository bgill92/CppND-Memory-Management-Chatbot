#include "graphnode.h"
#include "graphedge.h"

// For debugging
#include <iostream>

GraphEdge::GraphEdge(int id)
{
	std::cout << "In GraphEdge Constructor" << std::endl;
    _id = id;
}

void GraphEdge::SetChildNode(GraphNode *childNode)
{
    _childNode = childNode;
}

void GraphEdge::SetParentNode(GraphNode *parentNode)
{
    _parentNode = parentNode;
}

void GraphEdge::AddToken(std::string token)
{
    _keywords.push_back(token);
}