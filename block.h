#ifndef BLOCK_H
#define BLOCK_H

#include <QRect>

enum Status
{
    START,
    DESTINATION,
    NOT_WALKED,
    WALKED,
    PATH,
    OBSTACLE,
};

class Block : public QRect
{
public:
    explicit Block();
    Status status() const;
    void setStatus(const Status &status);
    void setParent(Block *parent);
    Block *getParent();


private:
    Status m_status;
    Block *parent = nullptr;

signals:

};

#endif // BLOCK_H
