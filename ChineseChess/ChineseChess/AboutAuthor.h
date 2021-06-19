#ifndef ABOUTAUTHOR_H
#define ABOUTAUTHOR_H

#include <QDialog>
#include <QFont>

namespace Ui {
class AboutAuthor;
}

class AboutAuthor : public QDialog
{
    Q_OBJECT

public:
    explicit AboutAuthor(QWidget *parent = 0);
    ~AboutAuthor();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AboutAuthor *ui;
};

#endif // ABOUTAUTHOR_H
