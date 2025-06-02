#ifndef TODOLIST_H
#define TODOLIST_H

#include <QFile>
#include <QJsonArray>
#include "task.h"

class ToDoList
{
public:
    ToDoList();
    ToDoList(const std::vector<Task>& tasks);

    const std::vector<Task>& getTasks() const {
        return tasks;
    }
    void setTasks(const std::vector<Task>& tasks) {
        this->tasks = tasks;
    }

    void append(const Task& task);

    QJsonArray toJson() const;
    static ToDoList fromJson(const QJsonArray& json);

private:
    std::vector<Task> tasks;
};

#endif // TODOLIST_H
