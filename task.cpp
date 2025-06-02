#include <stdexcept>
#include "task.h"

Task::Task(QString header_, QDateTime deadline_, QString description_)
    : header(header_), deadline(deadline_), description(description_)
{
    if (header_.isEmpty())
        throw std::invalid_argument("Header must not be empty");
}

bool Task::hasDeadlinePassed() const
{
    return QDateTime::currentDateTime() > deadline;
}

QJsonObject Task::toJson() const
{
    return QJsonObject{{"header", header},
        {"deadline", deadline.toString()},
        {"description", description}
    };
}

Task Task::fromJson(const QJsonObject& json)
{
    return Task(json["header"].toString(),
                QDateTime::fromString(json["deadline"].toString()),
                json["description"].toString()
           );
}
