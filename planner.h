#ifndef PLANNER_H
#define PLANNER_H

#include <QTimer>
#include <QObject>
#include "grid.h"
#include "node.h"
#include <queue>

enum PlannerStatus
{
    PLANNING,
    STOPPED
};

class Planner : public QObject
{
public:
    Planner(int startX = 0, int startY = 0,
            int endX = 0, int endY = 0,
            Grid *gridptr = nullptr);

    ~Planner();

    void setGridptr(Grid *value);
    void setStartPos(int x, int y);
    void setEndPos(int x, int y);

    QTimer *timer;

private slots:
    void step();

private:
    void showPath(Node &endNode);

    Grid *gridptr;

    PlannerStatus plannerStatus;

    vector<vector<Node>> map;
    Node startNode;
    Node endNode;
    Node currentNode;
    queue<Node> nodeQueue;
    vector<Node> path;

    vector<vector<int>> directions = {{1, 0}, {0, 1}, {0, -1}};

    int count = 5;
};

#endif // PLANNER_H
