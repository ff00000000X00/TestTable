#include "ttablemodel.h"

int TableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
                return 0;
    return phoneBook.count();
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
                return 0;
        return 3;
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();
    if(index.row()<0||index.row()>phoneBook.size())
        return QVariant();



    if(role == user_id)
        return phoneBook.at(index.row()).user_id;
    else if(role == user_name)
        return phoneBook.at(index.row()).user_name;
    else if(role == phone_number)
        return phoneBook.at(index.row()).phone_number;
    else
        return QVariant();
}

QHash<int, QByteArray> TableModel::roleNames() const
{
    return {
        {user_id,"user_id"},
        {user_name,"user_name"},
        {phone_number,"phone_number"}
           };
}

void TableModel::setModel(const QStringList &data)
{
QStringList temp;
    for(int i = 0; i < data.count(); ++i)
    {
        phoneBook.push_back(*(new OneRowData));
        temp = data.at(i).split(";");

        phoneBook[i].user_id = temp.at(0);
        phoneBook[i].user_name = temp.at(1);
        phoneBook[i].phone_number = temp.at(2);

    }
}


TableModel::TableModel(QObject* parent)
    :QAbstractTableModel(parent)
{
}

