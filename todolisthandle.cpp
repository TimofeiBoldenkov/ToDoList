#include <QJsonDocument>
#include "todolisthandle.h"

ToDoListHandle::ToDoListHandle() { }

ToDoListHandle::ToDoListHandle(const QString& fileName)
    : file(fileName)
{
    getListFromFile();
}

void ToDoListHandle::save()
{
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
        QJsonDocument document(list.toJson());
        if (file.write(document.toJson(QJsonDocument::Indented)) == -1)
            throw std::runtime_error("Failed to write to file");
        file.close();
    } else {
        throw std::runtime_error("Failed to open file for writing");
    }
}

ToDoListHandle::~ToDoListHandle()
{
    try {
        save();
    } catch (const std::runtime_error& e) {
        qWarning("Save failed in destructor: %s", e.what());
    }
}

void ToDoListHandle::changeFile(const QString& fileName)
{
    if (file.exists()) {
        if (!file.remove())
            throw std::runtime_error("Failed to remove existing file");
    }
    file.setFileName(fileName);
    getListFromFile();
}

void ToDoListHandle::getListFromFile()
{
    if (!file.exists()) {
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            throw std::runtime_error("Failed to create file");
        file.close();
    }
    if (file.open(QIODevice::ReadOnly | QIODeviceBase::Text)) {
        auto document = QJsonDocument::fromJson(file.readAll());
        if (document.isNull())
            throw std::runtime_error("Failed to parse json");
        if (!document.isArray())
            throw std::runtime_error("Invalid json: should be array");
        list = ToDoList::fromJson(document.array());
        file.close();
    } else {
        throw std::runtime_error("Failed to read file");
    }
}

QString ToDoListHandle::fileName() const
{
    return file.fileName();
}
