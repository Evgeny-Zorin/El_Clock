#ifndef CLASS_CHANGEHISTORY_H
#define CLASS_CHANGEHISTORY_H
#include <QVector>
#include <QPair>
#include <QMetaType>
#include <QDebug>

using Record = QPair<QString, qint64>; //pair <date, delta value>, and "This type is guaranteed to be 64-bit on all platforms supported by Qt."

class class_ChangeHistory
{
    QVector<Record> *listHistory {nullptr}; //pointer to a data list
  private:
      void Copy (const class_ChangeHistory & ch);
      void Move(class_ChangeHistory & ch);
  public:
      class_ChangeHistory();        //standard constructor
      class_ChangeHistory(const class_ChangeHistory & ch);  //copy constructor
      class_ChangeHistory(class_ChangeHistory && ch);       //moving copy
      ~class_ChangeHistory(){if (listHistory) delete listHistory;}
   class_ChangeHistory& operator=(const class_ChangeHistory & ch); //operator assignment
   class_ChangeHistory& operator=(class_ChangeHistory && ch);      //moving assignment
   const QVector<Record>& access_listHistory() const{ return (*listHistory);}
   Record& operator[](const int& i)const        //overloading the random access operator
   {
    int k = i < 0 ? 0 : i;
    k = k > (listHistory->size() - 1) ? (listHistory->size() - 1) : k;
    return (*listHistory)[k];
   }
   void operator<<(Record rec){listHistory->push_back(rec);}    //add  pair to list

   int count() const;
   void clear(){listHistory->clear();}

};

//overload <<  >> for class_ChangeHistory

//This macro makes the type Type known to QMetaType as long as it provides a public default constructor,
//a public copy constructor and a public destructor.
//It is needed to use the type Type as a custom type in QVariant.
Q_DECLARE_METATYPE(class_ChangeHistory)
//qRegisterMetaType ()  //After a type has been registered, you can create and destroy objects of that type dynamically at run-time.

QDataStream & operator<<(QDataStream & out, class_ChangeHistory const & ch);
QDataStream & operator>>(QDataStream & in,  class_ChangeHistory & ch);



#endif // CLASS_CHANGEHISTORY_H
