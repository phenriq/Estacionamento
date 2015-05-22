#ifndef CADASTRARNOVOUSER_H
#define CADASTRARNOVOUSER_H

#include <QDialog>

namespace Ui {
class CadastrarNovoUser;
}

class CadastrarNovoUser : public QDialog
{
    Q_OBJECT

public:
    explicit CadastrarNovoUser(QWidget *parent = 0);
    ~CadastrarNovoUser();

private slots:
    void on_pushButton_clicked();

private:
    Ui::CadastrarNovoUser *ui;
};

#endif // CADASTRARNOVOUSER_H
