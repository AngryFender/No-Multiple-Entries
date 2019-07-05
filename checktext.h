#ifndef CHECKTEXT_H
#define CHECKTEXT_H

#include <QObject>
#include <QDebug>
#include <QMetaObject>

class checkText : public QObject
{
    Q_OBJECT
public:
    explicit checkText(QObject *parent = nullptr, QObject * _qmlObject = nullptr);

private:
    QObject *qmlObject;

signals:
    void cppSignal( int count);
public slots:
    void cppSlot(QString msg);
};

#endif // CHECKTEXT_H
