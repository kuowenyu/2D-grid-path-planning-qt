#ifndef NODE_H
#define NODE_H

enum Status
{
    START,
    DESTINATION,
    NOT_WALKED,
    WALKED,
    PATH,
    OBSTACLE,
};

class Node
{
public:
    Node();

    Status getStatus() const;
    void setStatus(const Status &value);

    Node *getParent() const;
    void setParent(Node *value);

    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);

private:
    int x;
    int y;
    Status status;
    Node *parent = nullptr;
};

#endif // NODE_H
