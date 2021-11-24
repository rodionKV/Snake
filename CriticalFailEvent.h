//
// Created by rodion on 24.11.2021.
//

#ifndef SNAKE_CRITICALFAILEVENT_H
#define SNAKE_CRITICALFAILEVENT_H
#include <QEvent>
class CriticalFailEvent : public QEvent {
public:
    static const int CodeFailEvent = QEvent::User + 200;

    CriticalFailEvent() : QEvent((Type)(CodeFailEvent)) {
    }

    static QString info() {
        return "FailStep!";
    }

};
#endif //SNAKE_CRITICALFAILEVENT_H
