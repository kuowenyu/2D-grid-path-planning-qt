#include "widget.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QDebug>
#include <QTimer>

#include "grid.h"
#include "planner.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene scene;
    scene.setSceneRect(0, 0, 800, 600);
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);

    Grid canvas(nullptr, &scene, 10, 10, 12, 10, 60, 45);

    QGraphicsView view(&scene);
    view.setWindowTitle("2D Grid Path Planner");
    // Fit the view in the scene's bounding rect
    view.show();

    Planner planner(2, 2, 5, 5, &canvas);

    return a.exec();
}
