#ifndef TODOLISTHANDLE_H
#define TODOLISTHANDLE_H

#include <QFile>
#include <QString>
#include "todolist.h"

class ToDoListHandle
{
public:
    ToDoListHandle(const QString& fileName);
    ToDoListHandle();
    ~ToDoListHandle();

    void save();

    void changeFile(const QString& fileName);

    ToDoList& operator*() {
        return list;
    }
    const ToDoList& operator*() const {
        return list;
    }

    ToDoList* operator->() {
        return &list;
    }
    const ToDoList* operator->() const {
        return &list;
    }

    QString fileName() const;

private:
    QFile file;
    ToDoList list;

    void getListFromFile();
};

#endif // TODOLISTHANDLE_H
