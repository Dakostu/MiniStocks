#ifndef SIGNALMACHINE_H
#define SIGNALMACHINE_H

#include <QObject>

class SignalMachine : public QObject
{
    Q_OBJECT
public:
    SignalMachine();


signals:
    void requestRefresh();

public slots:
    void launch();
};

#endif // SIGNALMACHINE_H
