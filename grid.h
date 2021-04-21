#ifndef GRID_H
#define GRID_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <vector>

using namespace std;

#define COL_NOT_WALKED Qt::lightGray
#define COL_WALKED Qt::black
#define COL_PATH Qt::red
#define COL_START Qt::blue
#define COL_DESTINATION Qt::yellow

class Grid : public QObject
{
    Q_OBJECT
public:
    explicit Grid(QObject* parent = nullptr, QGraphicsScene *scene = nullptr,
                  int startX = 0, int startY = 0,
                  int gap = 0, int size = 0, int width = 0, int height = 0);

    void updateGrid(int x, int y, Qt::GlobalColor color);

    QSize gridSize;
    vector<vector<QRect>> grid;
    vector<vector<QGraphicsRectItem*>> gridptr;

private:
    int size;
    int gap;
    int startX;
    int startY;
    QGraphicsScene *scene;

signals:

};

#endif // GRID_H
