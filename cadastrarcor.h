#ifndef CADASTRARCOR_H
#define CADASTRARCOR_H

#include <QDialog>

namespace Ui {
class CadastrarCor;
}

class CadastrarCor : public QDialog
{
    Q_OBJECT

public:
    explicit CadastrarCor(QWidget *parent = 0);
    ~CadastrarCor();

private slots:
    void on_btnNovaCor_clicked();

private:
    Ui::CadastrarCor *ui;
};

#endif // CADASTRARCOR_H
