#include "planner.h"
#include <QDebug>

Planner::Planner(int startX, int startY, int endX, int endY, Grid *gridptr)
{
    // create map consists of nodes
    this->gridptr = gridptr;
    map.resize(this->gridptr->gridSize.width());
    for (int i = 0; i < int(map.size()); i++)
    {
        map[i].resize(this->gridptr->gridSize.height());
        for (int j = 0; j < int(map[i].size()); j++)
        {
            map[i][j].setX(i);
            map[i][j].setY(j);
            map[i][j].setStatus(NOT_WALKED);
        }
    }

    // assign start node
    map[startX][startY].setStatus(START);
    startNode = map[startX][startY];
    gridptr->updateGrid(startX, startY, COL_START);

    // assign end node
    map[endX][endY].setStatus(DESTINATION);
    endNode = map[endX][endY];
    gridptr->updateGrid(endX, endY, COL_DESTINATION);

    // assign current node
    currentNode = startNode;

    // start planning
    plannerStatus = PLANNING;
    nodeQueue.push(startNode);
    path.reserve(30);

    // create a timer
    timer = new QTimer(this);

    // setup signal and slot
    connect(timer, &QTimer::timeout, this, &Planner::step);
    timer->start(100);
}

Planner::~Planner()
{

}

void Planner::step()
{
    int x, y, nextX, nextY;
    Status status;

    if (plannerStatus == PLANNING)
    {
        if (nodeQueue.empty())
        {
            plannerStatus = STOPPED;
            return;
        }

        // pop first node from queue
        currentNode = nodeQueue.front();
        nodeQueue.pop();
        x = currentNode.getX();
        y = currentNode.getY();
        qInfo() << "Forward:" << x << y;

        // update node status
        if (currentNode.getStatus() != START) gridptr->updateGrid(x, y, COL_WALKED);

        for (int i = 0; i < int(directions.size()); i++)
        {
            nextX = x + directions[i][0];
            nextY = y + directions[i][1];

            status = map[nextX][nextY].getStatus();
            if (status == WALKED || status == OBSTACLE || status == START) continue;
            if (nextX < 0 || nextX >= int(map.size())) continue;
            if (nextY < 0 || nextY >= int(map[0].size())) continue;

            map[nextX][nextY].setParent(&map[x][y]);

            if (status == DESTINATION)
            {
                plannerStatus = STOPPED;
                showPath(map[nextX][nextY]);
                return;
            }
            map[nextX][nextY].setStatus(WALKED);
            gridptr->updateGrid(nextX, nextY, COL_WALKED);
            nodeQueue.push(map[nextX][nextY]);
        }
    }

}

void Planner::setGridptr(Grid *value)
{
    gridptr = value;
}

void Planner::setStartPos(int x, int y)
{
    gridptr->updateGrid(x, y, COL_START);

}

void Planner::setEndPos(int x, int y)
{
    gridptr->updateGrid(x, y, COL_DESTINATION);
}

void Planner::showPath(Node &endNode)
{
    int count = 0;
    Node node = endNode;
    while (node.getParent() != nullptr)
    {
        if (count > 1000) return;

        node = *node.getParent();
        if (node.getStatus() == START) return;
        node.setStatus(PATH);
        gridptr->updateGrid(node.getX(), node.getY(), COL_PATH);
        qInfo() << "Reverse:" << node.getX() << node.getY();
        count++;
    }
}
