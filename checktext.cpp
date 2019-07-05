#include "checktext.h"

checkText::checkText(QObject *parent, QObject * _qmlObject): QObject(parent)
{
    qmlObject = _qmlObject;
}

void checkText::cppSlot(QString msg)
{

    QStringList list = msg.split(QRegExp("\\s+"), QString::SkipEmptyParts);

    QMap<QString,int> count;

    for (int x = 0 ; x < list.count(); x++) {
        count[list[x]]++;
    }

    QStringList listDuplicates;
    QMapIterator<QString, int> counter(count);
    while (counter.hasNext()) {
        counter.next();
        if(counter.value() > 1){
        listDuplicates.append(counter.key());
        }
    }
    QMetaObject::invokeMethod(qmlObject, "showResults",Q_ARG(QVariant, listDuplicates.count()));
}
