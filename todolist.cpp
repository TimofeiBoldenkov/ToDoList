#include "todolist.h"

ToDoList::ToDoList() { }

ToDoList::ToDoList(const std::vector<Task>& tasks_)
    : tasks(tasks_)
{

}


void ToDoList::append(const Task& task)
{
    tasks.push_back(task);
}

QJsonArray ToDoList::toJson() const
{
    QJsonArray json;

    for (const Task& task : tasks) {
        json.append(task.toJson());
    }

    return json;
}

ToDoList ToDoList::fromJson(const QJsonArray& json)
{
    ToDoList list;

    for (const QJsonValue& value : json) {
        list.append(Task::fromJson(value.toObject()));
    }

    return list;
}
