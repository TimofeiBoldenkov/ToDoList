#ifndef TASK_H
#define TASK_H

#include <QString>
#include <QDateTime>
#include <QJsonObject>

class Task
{
public:
    Task(QString header, QDateTime deadline, QString description = "");


    QString getHeader() const {
        return header;
    }
    void setHeader(QString header) {
        this->header = header;
    }

    QDateTime getDeadline() const {
        return deadline;
    }
    void setDeadline(QDateTime deadline) {
        this->deadline = deadline;
    }

    QString getDescription() const {
        return description;
    }
    void setDescription(QString description) {
        this->description = description;
    }


    bool hasDeadlinePassed() const;

    QJsonObject toJson() const;
    static Task fromJson(const QJsonObject& json);

private:
    QString header;
    QDateTime deadline;
    QString description;
};

#endif // TASK_H
