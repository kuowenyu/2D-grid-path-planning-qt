#include "grid.h"

Grid::Grid(QObject* parent, QGraphicsScene* scene,
           int startX, int startY,
           int gap, int size,
           int width, int height) : QObject(parent)
{
    this->startX = startX;
    this->startY = startY;
    this->gap = gap;
    this->size = size;
    this->scene = scene;

    gridSize = QSize(width, height);
    grid.resize(gridSize.width());
    gridptr.resize(gridSize.width());
    for (int i = 0; i < gridSize.width(); i++)
    {
        grid[i].resize(gridSize.height());
        gridptr[i].resize(gridSize.height());
    }


    for (int i = 0; i < gridSize.width(); i ++)
    {
        for (int j = 0; j < gridSize.height(); j++)
        {
            grid[i][j].setX(startX + gap * i);
            grid[i][j].setY(startY + gap * j);
            grid[i][j].setHeight(size);
            grid[i][j].setWidth(size);

            gridptr[i][j] = this->scene->addRect(grid[i][j], QPen(COL_NOT_WALKED), QBrush(COL_NOT_WALKED));
        }
    }
}

void Grid::updateGrid(int x, int y, Qt::GlobalColor color)
{
    QPen pen(color);
    QBrush brush(color);

    gridptr[x][y]->setPen(pen);
    gridptr[x][y]->setBrush(brush);
}
