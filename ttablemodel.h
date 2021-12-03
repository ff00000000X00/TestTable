#ifndef TABLEMODEL_H
#define TABLEMODEL_H
#include <QAbstractTableModel>

class TableModel:public QAbstractTableModel
{
    Q_OBJECT
private:
    enum Roles
    {
        user_id = Qt::UserRole + 1,
        user_name,
        phone_number,
    };

    struct OneRowData
    {
        QString user_id;
        QString user_name;
        QString phone_number;
    };

    QVector<OneRowData> phoneBook;
public:
    TableModel(QObject* parent = nullptr);
    void setModel(const QStringList &data);
protected:
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;
};

#endif // TABLEMODEL_H
