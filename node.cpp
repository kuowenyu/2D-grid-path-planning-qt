#include "node.h"

Node::Node()
{

}

Status Node::getStatus() const
{
    return status;
}

void Node::setStatus(const Status &value)
{
    status = value;
}

Node *Node::getParent() const
{
    return parent;
}

void Node::setParent(Node *value)
{
    parent = value;
}

int Node::getX() const
{
    return x;
}

void Node::setX(int value)
{
    x = value;
}

int Node::getY() const
{
    return y;
}

void Node::setY(int value)
{
    y = value;
}
