#ifndef DENGLU_H
#define DENGLU_H

#include <QWidget>

namespace Ui {
class denglu;
}

class denglu : public QWidget
{
    Q_OBJECT

public:
    explicit denglu(QWidget *parent = nullptr);
    ~denglu();

private:
    Ui::denglu *ui;
    QVector<bool> Isshow;
};

#endif // DENGLU_H
