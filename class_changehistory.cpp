#include <algorithm>
#include <QDataStream>
#include <QDebug>
#include "class_changehistory.h"



void class_ChangeHistory::Copy(const class_ChangeHistory &ch)
{
    {      //Copy:
        std::copy(ch.listHistory->begin(),ch.listHistory->end(),
                     listHistory->begin());
      //qDebug() <<"run method Copy";
    }
}

void class_ChangeHistory::Move(class_ChangeHistory &ch)
{
    { //Moving:
        listHistory = ch.listHistory;
        ch.listHistory = nullptr;
      //qDebug() <<"run method Move";
    }
}

class_ChangeHistory::class_ChangeHistory()
{
    listHistory = new QVector<Record>;
}

class_ChangeHistory::class_ChangeHistory(const class_ChangeHistory &ch)
{
    listHistory = new QVector<Record>(ch.count());
    Copy(ch);
}

class_ChangeHistory::class_ChangeHistory(class_ChangeHistory &&ch)
{
    Move(ch);
}

class_ChangeHistory &class_ChangeHistory::operator=(const class_ChangeHistory &ch)
{//operator assignment
    listHistory->clear();
      listHistory->resize(ch.count());
      Copy(ch);
       //qDebug() <<"run operator = &";
       return *this;
}

class_ChangeHistory &class_ChangeHistory::operator=(class_ChangeHistory &&ch)
{//moving assignment
    delete listHistory; Move(ch);
      //qDebug() <<"run operator = &&";
      return *this;
}

int class_ChangeHistory::count() const
{
    return listHistory->size();
}

QDataStream &operator<<(QDataStream &out, const class_ChangeHistory &ch)
{
    out<<ch.count();
    for (auto var: ch.access_listHistory())
           out << var.first << var.second;
     return out;
}

QDataStream &operator>>(QDataStream &in, class_ChangeHistory &ch)
{
    int count;  Record rec;
        in >> count;
        ch.clear();     //clear object class_ChangeHistory
        for(int i = 0; i < count; ++i)
          { in >> rec.first >> rec.second;
            ch << rec;  //fill object class_ChangeHistory
          }
      return in;
}


