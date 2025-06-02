#ifndef TODOAPP_H
#define TODOAPP_H

#include <QMainWindow>
#include "todolisthandle.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ToDoApp; }
QT_END_NAMESPACE

class ToDoApp : public QMainWindow
{
    Q_OBJECT

public:
    ToDoApp(QWidget *parent = nullptr);
    ~ToDoApp();

private:
    Ui::ToDoApp *ui;

    ToDoListHandle list;
};
#endif // TODOLIST_H
