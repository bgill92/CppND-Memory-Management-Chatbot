#include "graphedge.h"
#include "graphnode.h"

// For debugging
#include <iostream>

GraphNode::GraphNode(int id)
{
    std::cout << "In GraphNode Constructor" << std::endl;
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    std::cout << "In GraphNode Destructor" << std::endl;

    // delete _chatBot; 

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

// void GraphNode::AddEdgeToChildNode(GraphEdge *edge)
void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> &&edge)
{
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot &&chatbot)
{
    _chatBot = ChatBot(std::move(chatbot));
    _chatBot.GetChatLogicHandle()->SetChatbotHandle(&_chatBot);
    _chatBot.SetImageHandle(_chatBot.GetImageHandle());
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    ChatBot chat_bot = ChatBot();
    chat_bot.SetRootNode(_chatBot.GetRootNode());
    chat_bot.SetChatLogicHandle(_chatBot.GetChatLogicHandle());
    chat_bot.SetImageHandle(_chatBot.GetImageHandle());
    newNode->MoveChatbotHere(std::move(chat_bot));    
    _chatBot.SetImageHandle(nullptr); // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    // return _childEdges[index];
    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}