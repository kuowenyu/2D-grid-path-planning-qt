#include "block.h"

Block::Block()
{
    m_status = NOT_WALKED;
}

Status Block::status() const
{
    return m_status;
}

void Block::setStatus(const Status &status)
{
    m_status = status;
}

void Block::setParent(Block *parent)
{
    this->parent = parent;
}

Block* Block::getParent()
{
    return parent;
}
